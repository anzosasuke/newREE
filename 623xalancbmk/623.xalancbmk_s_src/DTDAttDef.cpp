/*
 * Copyright 1999-2000,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: DTDAttDef.cpp 191054 2005-06-17 02:56:35Z jberry $
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/framework/XMLElementDecl.hpp>
#include <xercesc/validators/DTD/DTDAttDef.hpp>

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  DTDAttDef: Constructors and Destructor
// ---------------------------------------------------------------------------
DTDAttDef::DTDAttDef(MemoryManager* const manager) :

    XMLAttDef(XMLAttDef::CData, XMLAttDef::Implied, manager)
   , fElemId(XMLElementDecl::fgInvalidElemId)
    , fName(0)
{
}

DTDAttDef::DTDAttDef(const  XMLCh* const           attName
                    , const XMLAttDef::AttTypes    type
                    , const XMLAttDef::DefAttTypes defType
                    , MemoryManager* const         manager) :
    XMLAttDef(type, defType, manager)
    , fElemId(XMLElementDecl::fgInvalidElemId)
    , fName(0)
{
    fName = XMLString::replicate(attName, getMemoryManager());
}

DTDAttDef::DTDAttDef( const   XMLCh* const         attName
                    , const XMLCh* const           attValue
                    , const XMLAttDef::AttTypes    type
                    , const XMLAttDef::DefAttTypes defType
                    , const XMLCh* const           enumValues
                    , MemoryManager* const         manager) :

    XMLAttDef(attValue, type, defType, enumValues, manager)
    , fElemId(XMLElementDecl::fgInvalidElemId)
    , fName(0)
{
    fName = XMLString::replicate(attName, getMemoryManager());
}

DTDAttDef::~DTDAttDef()
{
    getMemoryManager()->deallocate(fName); //delete [] fName;
}


// ---------------------------------------------------------------------------
//  DTDAttDef: Setter methods
// ---------------------------------------------------------------------------
void DTDAttDef::setName(const XMLCh* const newName)
{
    getMemoryManager()->deallocate(fName); //delete [] fName;
    fName = XMLString::replicate(newName, getMemoryManager());
}

/***
 * Support for Serialization/De-serialization
 ***/

IMPL_XSERIALIZABLE_TOCREATE(DTDAttDef)

void DTDAttDef::serialize(XSerializeEngine& serEng)
{

    XMLAttDef::serialize(serEng);

    if (serEng.isStoring())
    {
        serEng<<fElemId;
        serEng.writeString(fName);
    }
    else
    {
        serEng>>fElemId;
        serEng.readString(fName);
    }
}


XERCES_CPP_NAMESPACE_END
