/*
 * Copyright 1999-2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "xalanc/Harness/XalanDiagnosticMemoryManager.hpp"



#if !defined(XALAN_CLASSIC_IOSTREAMS)
#include <iostream>
#endif



#include <ctype.h>



#include "xercesc/util/PlatformUtils.hpp"



XALAN_CPP_NAMESPACE_BEGIN



XalanDiagnosticMemoryManager::XalanDiagnosticMemoryManager(
            MemoryManager&  theMemoryManager,
            bool            fAssertErrors,
            StreamType*     theStream) :
    m_memoryManager(theMemoryManager),
    m_assertErrors(fAssertErrors),
    m_locked(false),
    m_sequence(0),
    m_highWaterMark(0),
    m_currentAllocated(0),
    m_allocations(theMemoryManager),
    m_stream(theStream)
{
}



XalanDiagnosticMemoryManager::~XalanDiagnosticMemoryManager()
{
    if (m_allocations.size() > 0 && m_stream != 0)
    {
        *m_stream << "Detected memory leaks. "
                  << int_type(m_allocations.size())
                  << " blocks are still allocated.\n";
    }
}



void*
XalanDiagnosticMemoryManager::allocate(size_type  size)
{
    void*   theResult = 0;

    if (m_locked == true)
    {
        if (m_stream != 0)
        {
            *m_stream << "Attempt to allocate "
                      << int_type(size)
                      << " bytes from locked instance "
                      << this
                      << ".\n";
        }

        throw LockException();
    }
    else
    {
        theResult =
            m_memoryManager.allocate(size);
        assert(theResult != 0);

        assert(m_allocations.find(theResult) == m_allocations.end());

        m_currentAllocated += size;

        if (m_currentAllocated > m_highWaterMark)
        {
            m_highWaterMark = m_currentAllocated;
        }

        m_allocations.insert(MapType::value_type(theResult, Data(size, m_sequence++)));
    }

    return theResult;
}



void
XalanDiagnosticMemoryManager::deallocate(void*    pointer)
{
    if (m_locked == true)
    {
        if (m_stream != 0)
        {
            *m_stream << "Attempt to deallocate address "
                      << pointer
                      << " with locked instance "
                      << this
                      << ".\n";
        }

        throw LockException();
    }
    else
    {
        if (pointer != 0)
        {
            MapType::iterator   i =
                m_allocations.find(pointer);
            
            if (i != m_allocations.end())
            {
                m_memoryManager.deallocate(pointer);
                
                assert(m_currentAllocated >= i->second.m_size);
                
                m_currentAllocated -= i->second.m_size;
                
                m_allocations.erase(i);
            }
            else
            {
                if (m_stream != 0)
                {
                    *m_stream << "Attempt to free unallocated address "
                              << pointer
                              << " with instance "
                              << this
                              << ".\n";
                }

                assert(!m_assertErrors);
            }
        }
    }
}



void
XalanDiagnosticMemoryManager::dumpStatistics(
            StreamType*     theStream,
            size_type       theBytesToDump)
{
    StreamType* const   diagStream = theStream != 0 ? theStream : m_stream;

    if (diagStream != 0)
    {
        *diagStream << "Total number of allocations: "
                    << int_type(m_sequence)
                    << ".\n"
                    << "Total current allocations: "
                    << int_type(m_allocations.size())
                    << ".\n"
                    << "Total bytes currently allocated: "
                    << int_type(m_currentAllocated)
                    << ".\n"
                    << "Peak bytes allocated: "
                    << int_type(m_highWaterMark)
                    << ".\n";

        for(const_iterator i = m_allocations.begin();
                i != m_allocations.end();
                    ++i)
        {
            const void* const   thePointer = i->first;
            const Data&         theData = i->second;

            XALAN_USING_STD(dec);

            *diagStream << "Block at address "
                        << thePointer
                        << " with sequence "
                        << dec
                        << int_type(theData.m_sequence)
                        << " is "
                        << int_type(theData.m_size)
                        << " bytes long.\n";

            XALAN_USING_XERCES(XMLPlatformUtils);

            const size_type     theHeaderSize =
                XMLPlatformUtils::alignPointerForNewBlockAllocation(sizeof(MemoryManager*));

            const char* const   theChars =
                reinterpret_cast<const char*>(thePointer) + 
                    theHeaderSize;

            const unsigned char* const  theUChars =
                reinterpret_cast<const unsigned char*>(theChars);

            if (theBytesToDump != 0)
            {
                XALAN_USING_STD(hex);

                const size_type     theCount =
                    theBytesToDump > theData.m_size ?
                        theData.m_size :
                        theBytesToDump;

                {
                    *diagStream << "(";

                    for (size_t j = 0; j < theCount; ++j)
                    {
                        const char  ch = isprint(theChars[j]) ?
                                            theChars[j] :
                                            ' ';

                        *diagStream << ch;
                    }

                    *diagStream << ")  ";
                }

                if (theCount < theBytesToDump)
                {
                    for (size_t j = theCount; j < theBytesToDump; ++j)
                    {
                        *diagStream << ' ';
                    }
                }

                {
                    *diagStream << hex;

                    for (size_t j = 0; j < theCount; ++j)
                    {
                        *diagStream << unsigned(theUChars[j])
                                    << " ";
                    }
                }

                *diagStream << "\n";
            }
        }
    }
}



XALAN_CPP_NAMESPACE_END
