/*
 * Copyright 1999-2004 The Apache Software Foundation.
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
// Class header file...
#include "xalanc/PlatformSupport/XalanOutputStream.hpp"



#include <xercesc/util/TransService.hpp>



#include "xalanc/Include/STLHelper.hpp"



#include "xalanc/PlatformSupport/XalanMessageLoader.hpp"
#include "xalanc/PlatformSupport/XalanTranscodingServices.hpp"



XALAN_CPP_NAMESPACE_BEGIN



const XalanDOMChar  XalanOutputStream::s_nlString[] =
{
    XalanUnicode::charLF,
    0
};



const XalanDOMChar  XalanOutputStream::s_nlCRString[] =
{
    XalanUnicode::charCR,
    XalanUnicode::charLF,
    0
};



const XalanDOMString::size_type     XalanOutputStream::s_nlStringLength =
    sizeof(s_nlString) / sizeof(s_nlString[0]) - 1;

const XalanDOMString::size_type     XalanOutputStream::s_nlCRStringLength =
    sizeof(s_nlCRString) / sizeof(s_nlCRString[0]) - 1;





XalanOutputStream::XalanOutputStream(
            MemoryManagerType&      theManager,
            size_type               theBufferSize,
            size_type               theTranscoderBlockSize,
            bool                    fThrowTranscodeException) :
    m_transcoderBlockSize(theTranscoderBlockSize),
    m_transcoder(0),
    m_bufferSize(theBufferSize),
    m_buffer(theManager),
    m_encoding(theManager),
    m_writeAsUTF16(false),
    m_throwTranscodeException(fThrowTranscodeException),
    m_transcodingBuffer(theManager)
{
    if (m_bufferSize == 0)
    {
        m_bufferSize = 1;
    }

    m_buffer.reserve(theBufferSize + 1);
}



XalanOutputStream::~XalanOutputStream()
{
    XalanTranscodingServices::destroyTranscoder(m_transcoder);
}



void
XalanOutputStream::write(
            const XalanDOMChar*     theBuffer,
            size_type               theBufferLength)
{
    assert(theBuffer != 0);

    if (theBufferLength + m_buffer.size() > m_bufferSize)
    {
        flushBuffer();
    }

    if (theBufferLength > m_bufferSize)
    {
        assert(m_buffer.empty() == true);

        doWrite(theBuffer, theBufferLength);
    }
    else
    {
        m_buffer.insert(m_buffer.end(),
                        theBuffer,
                        theBuffer + theBufferLength);
    }
}



void
XalanOutputStream::transcode(
            const XalanDOMChar*     theBuffer,
            size_type               theBufferLength,
            TranscodeVectorType&    theDestination)
{
    if (m_transcoder == 0)
    {
        if (TranscodeToLocalCodePage(
                theBuffer,
                theBufferLength,
                theDestination) == false)
        {
            if (m_throwTranscodeException == true)
            {
                XalanDOMString theBuffer(theDestination.getMemoryManager());

                throw TranscodingException(theBuffer);
            }
            else
            {
            }
        }
    }
    else
    {
        bool                    fDone = false;

        // Keep track of the total bytes we've added to the
        // destination vector, and the total bytes we've
        // eaten from theBuffer.
        size_type   theTotalBytesFilled = 0;
        size_type   theTotalBytesEaten = 0;

        // Keep track of the current position in the input buffer,
        // and amount remaining in the buffer, since we may not be
        // able to transcode it all at once.
        const XalanDOMChar*     theBufferPosition = theBuffer;
        size_type               theRemainingBufferLength = theBufferLength;

        // Keep track of the destination size, and the target size, which is
        // the size of the destination that has not yet been filled with
        // transcoded characters.  Double the buffer size, in case we're
        // transcoding to a 16-bit encoding.
        // $$$ ToDo: We need to know the size of an encoding, so we can
        // do the right thing with the destination size.
        size_type   theDestinationSize = theBufferLength * 2;
        size_type   theTargetSize = theDestinationSize;

        do
        {
            // Resize the buffer...
            theDestination.resize(theDestinationSize + 1);

            size_type   theSourceBytesEaten = 0;
            size_type   theTargetBytesEaten = 0;

            XalanTranscodingServices::eCode     theResult =
                m_transcoder->transcode(
                        theBufferPosition,
                        theRemainingBufferLength,
#if defined(XALAN_OLD_STYLE_CASTS)
                        (XMLByte*)&theDestination[0] + theTotalBytesFilled,
#else
                        reinterpret_cast<XMLByte*>(&theDestination[0]) + theTotalBytesFilled,
#endif
                        theTargetSize,
                        theSourceBytesEaten,
                        theTargetBytesEaten);

            if(theResult != XalanTranscodingServices::OK)
            {
                if (m_throwTranscodeException == true)
                {
                    XalanDOMString theBuffer(theDestination.getMemoryManager());

                    throw TranscodingException(theBuffer);
                }
            }

            theTotalBytesFilled += theTargetBytesEaten;
            theTotalBytesEaten += theSourceBytesEaten;

            if (theTotalBytesEaten == theBufferLength)
            {
                fDone = true;
            }
            else
            {
                assert(theTotalBytesEaten < theBufferLength);

                // Update everything...
                theBufferPosition += theSourceBytesEaten;
                theRemainingBufferLength -= theSourceBytesEaten;

                // The new target size will always be the
                // current destination size, since we
                // grow by a factor of 2.  This will
                // need to change if the factor is
                // every changed.
                theTargetSize = theDestinationSize;

                // Grow the destination by a factor of
                // two 2.  See the previous comment if
                // you want to change this.
                theDestinationSize = theDestinationSize * 2;
            }
        } while(fDone == false);

        // Resize things, if there are any extra bytes...
        if (theDestination.size() != theTotalBytesFilled)
        {
            theDestination.resize(theTotalBytesFilled);
        }
    }
}



void
XalanOutputStream::setOutputEncoding(const XalanDOMString&  theEncoding)
{
    // Flush, just in case.  This should probably be an error...
    flushBuffer();

    XalanTranscodingServices::destroyTranscoder(m_transcoder);

    XalanTranscodingServices::eCode     theCode = XalanTranscodingServices::OK;

    // This turns on an optimization that we can only do if
    // XalanDOMChar == sizeof(ushort).  See doWrite().
#if !defined(XALAN_XALANDOMCHAR_USHORT_MISMATCH)
    if (XalanTranscodingServices::encodingIsUTF16(theEncoding) == true)
    {
        m_writeAsUTF16 = true;
    }
    else
#endif
    {
        m_transcoder = XalanTranscodingServices::makeNewTranscoder(
                    getMemoryManager(),
                    theEncoding,
                    theCode,
                    m_transcoderBlockSize);

        if (theCode == XalanTranscodingServices::UnsupportedEncoding)
        {
            XalanDOMString theBuffer(getMemoryManager());

            throw UnsupportedEncodingException(theEncoding, theBuffer);
        }
        else if (theCode != XalanTranscodingServices::OK)
        {
            XalanDOMString theBuffer(getMemoryManager());

            throw TranscoderInternalFailureException(theEncoding, theBuffer);
        }

        assert(m_transcoder != 0);
    }

    m_encoding = theEncoding;

    const XalanTranscodingServices::XalanXMLByte*   theProlog =
        XalanTranscodingServices::getStreamProlog(theEncoding);
    assert(theProlog != 0);

    const size_type     theLength = XalanTranscodingServices::length(theProlog);

    if (theLength > 0)
    {
#if defined(XALAN_OLD_STYLE_CASTS)
        write((const char*)theProlog, theLength);
#else
        write(reinterpret_cast<const char*>(theProlog), theLength);
#endif
    }
}



bool
XalanOutputStream::canTranscodeTo(unsigned int      theChar) const
{
    if (m_transcoder != 0)
    {
        return m_transcoder->canTranscodeTo(theChar);
    }
    else
    {
        // We'll always return true here, since an exception will be
        // thrown when we try to transcode.  We'ed like to enable the
        // commented out line, if we can ever figure out how to see
        // if a character can be encoded.
        return true;
//      return XalanTranscodingServices::canTranscodeToLocalCodePage(theChar);
    }
}



void
XalanOutputStream::flushBuffer()
{
    if (m_buffer.empty() == false)
    {
        CollectionClearGuard<BufferType>    theGuard(m_buffer);

        assert(size_type(m_buffer.size()) == m_buffer.size());

        doWrite(&*m_buffer.begin(), size_type(m_buffer.size()));
    }

    assert(m_buffer.empty() == true);
}



void
XalanOutputStream::doWrite(
            const XalanDOMChar*     theBuffer,
            size_type               theBufferLength)
{
    assert(theBuffer != 0);

    if (m_writeAsUTF16 == true)
    {
        assert(sizeof(XalanDOMChar) == sizeof(char) * 2);

        // This is a hack to write UTF-16 through as if it
        // were just chars.  Saves lots of time "transcoding."
#if defined(XALAN_OLD_STYLE_CASTS)
        writeData((const char*)theBuffer, theBufferLength * 2);
#else
        writeData(reinterpret_cast<const char*>(theBuffer), theBufferLength * 2);
#endif
    }
    else
    {
        transcode(theBuffer, theBufferLength, m_transcodingBuffer);

        assert(&m_transcodingBuffer[0] != 0);

        assert(size_type(m_transcodingBuffer.size()) == m_transcodingBuffer.size());

        writeData(
            &m_transcodingBuffer[0],
            size_type(m_transcodingBuffer.size()));
    }
}



void
XalanOutputStream::setBufferSize(size_type  theBufferSize)
{
    flushBuffer();

    if (theBufferSize == 0)
    {
        m_bufferSize = 1;
    }
    else
    {
        m_bufferSize = theBufferSize;
    }

    if (m_buffer.size() < m_bufferSize)
    {
        // Enlarge the buffer...
        m_buffer.reserve(theBufferSize + 1);
    }
    else if (m_buffer.size() > m_bufferSize)
    {
        // Shrink the buffer.

        // Create a temp buffer and make it
        // the correct size.
        BufferType  temp(getMemoryManager());
        
        temp.reserve(theBufferSize + 1);
        
        // Swap temp with m_buffer so that
        // m_buffer is now the correct size.
        temp.swap(m_buffer);
    }
}



void
XalanOutputStream::newline()
{
    // We've had requests to make this a run-time switch, but for now,
    // it's compile time only...
#if defined(XALAN_NEWLINE_IS_CRLF)
    write(s_nlCRString, s_nlCRStringLength);
#else
    write(s_nlString, s_nlStringLength);
#endif
}



const XalanDOMChar*
XalanOutputStream::getNewlineString() const
{
    // We've had requests to make this a run-time switch, but for now,
    // it's compile time only...
#if defined(XALAN_NEWLINE_IS_CRLF)
    return s_nlCRString;
#else
    return s_nlString;
#endif
}

const XalanDOMChar  XalanOutputStream::XalanOutputStreamException::m_type[] = 
{   
    XalanUnicode::charLetter_X,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_F,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_O,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_S,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_E,
    XalanUnicode::charLetter_x,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_n,
    0
};


XalanOutputStream::XalanOutputStreamException::XalanOutputStreamException(
            const XalanDOMString&   theMessage,
            MemoryManagerType&      theManager) :
    XSLException(theMessage, theManager)
{
}



XalanOutputStream::XalanOutputStreamException::~XalanOutputStreamException()
{
}

const XalanDOMChar  XalanOutputStream::UnknownEncodingException::m_type[] = 
{   
    XalanUnicode::charLetter_U,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_k,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_w,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_E,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_d,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_g,
    XalanUnicode::charLetter_E,
    XalanUnicode::charLetter_x,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_n,
    0
};



XalanOutputStream::UnknownEncodingException::UnknownEncodingException(XalanDOMString& theBuffer) :
    XalanOutputStreamException(
        XalanMessageLoader::getMessage(
            theBuffer,
            XalanMessages::AnErrorOccurredWhileTranscoding),
     theBuffer.getMemoryManager())
{
}



XalanOutputStream::UnknownEncodingException::~UnknownEncodingException()
{
}



const XalanDOMChar  XalanOutputStream::UnsupportedEncodingException::m_type[] = 
{   
    XalanUnicode::charLetter_U,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_d,
    XalanUnicode::charLetter_E,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_d,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_g,
    XalanUnicode::charLetter_E,
    XalanUnicode::charLetter_x,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_n,
    0
};



XalanOutputStream::UnsupportedEncodingException::UnsupportedEncodingException(
            const XalanDOMString&   theEncoding,
            XalanDOMString&         theBuffer) :
    XalanOutputStreamException(
        XalanMessageLoader::getMessage(
            theBuffer,
            XalanMessages::UnsupportedEncoding_1Param,
            theEncoding),
        theBuffer.getMemoryManager()),
   m_encoding(
       theEncoding, 
       theBuffer.getMemoryManager())
{
}



XalanOutputStream::UnsupportedEncodingException::~UnsupportedEncodingException()
{
}



XalanOutputStream::TranscoderInternalFailureException::TranscoderInternalFailureException(
            const XalanDOMString&   theEncoding,
            XalanDOMString&         theBuffer) :
    XalanOutputStreamException(
        XalanMessageLoader::getMessage(
            theBuffer, 
            XalanMessages::UnknownErrorOccurredWhileTranscodingToEncoding_1Param,
            theEncoding),
        theBuffer.getMemoryManager()),
    m_encoding(
        theEncoding,
        theBuffer.getMemoryManager())
{
}



XalanOutputStream::TranscoderInternalFailureException::~TranscoderInternalFailureException()
{
}



XalanOutputStream::TranscodingException::TranscodingException(XalanDOMString&   theBuffer) :
    XalanOutputStreamException(
        XalanMessageLoader::getMessage(
            theBuffer,
            XalanMessages::AnErrorOccurredWhileTranscoding),
        theBuffer.getMemoryManager())
{
}



XalanOutputStream::TranscodingException::~TranscodingException()
{
}



XALAN_CPP_NAMESPACE_END
