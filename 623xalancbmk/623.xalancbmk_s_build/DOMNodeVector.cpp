/*
 * Copyright 2001-2002,2004 The Apache Software Foundation.
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
 * $Id: DOMNodeVector.cpp 176317 2005-02-21 18:19:45Z cargilld $
 */

//
//	file:   DOMNodeVector.cpp
//			Implementation of class DOMNodeVector.
//			(Use of STL vector, or equivalent, would have been nice,
//			but is not available.  'DOMNode *' is the only type
//			kept in Vectors in this DOM implementation, so this is
//			a hardwired implementation for that type.
//

#include "xercesc/dom/impl/DOMNodeVector.hpp"
#include "xercesc/dom/impl/DOMDocumentImpl.hpp"
#include <assert.h>

XERCES_CPP_NAMESPACE_BEGIN


DOMNodeVector::DOMNodeVector(DOMDocument *doc)
{
	init(doc, 10);
}

DOMNodeVector::DOMNodeVector(DOMDocument *doc, XMLSize_t size) {
	init(doc, size);
}


void DOMNodeVector::init(DOMDocument *doc, XMLSize_t size) {
    assert(size > 0);
    //data = new (doc) DOMNode *[size];
    data = (DOMNode**) ((DOMDocumentImpl *)doc)->allocate(sizeof(DOMNode*) * size);
    assert(data != 0);
    XMLSize_t i;
    for (i=0; i<size; i++)
        data[i] = 0;
    allocatedSize = size;
    nextFreeSlot = 0;
}


DOMNodeVector::~DOMNodeVector() {
}


void DOMNodeVector::addElement(DOMNode *elem) {
	checkSpace();
	data[nextFreeSlot] = elem;
	++nextFreeSlot;
}


void DOMNodeVector::checkSpace() {
    if (nextFreeSlot == allocatedSize) {
        XMLSize_t grow = allocatedSize/2;
        if (grow < 10) grow = 10;
        XMLSize_t newAllocatedSize = allocatedSize + grow;
        DOMDocument *doc = data[0]->getOwnerDocument();

        //DOMNode **newData = new (doc) DOMNode *[newAllocatedSize];
        DOMNode **newData = (DOMNode**) ((DOMDocumentImpl *)doc)->allocate(sizeof(DOMNode*) * newAllocatedSize);

        assert(newData != 0);
        for (XMLSize_t i=0; i<allocatedSize; i++) {
            newData[i] = data[i];
        }
        // delete [] data;  // revisit.  Can't delete!  Recycle?
        allocatedSize = newAllocatedSize;
        data = newData;
    }
}


void DOMNodeVector::insertElementAt(DOMNode *elem, XMLSize_t index) {
	XMLSize_t i;

	assert(index <= nextFreeSlot);

	checkSpace();
	for (i=nextFreeSlot; i>index; --i) {
		data[i] = data[i-1];
	}
	data[index] = elem;
	++nextFreeSlot;

}


void DOMNodeVector::removeElementAt(XMLSize_t index) {
	assert(index < nextFreeSlot);
	for (XMLSize_t i=index; i<nextFreeSlot-1; ++i) {
		data[i] = data[i+1];
	}
	--nextFreeSlot;
}

void DOMNodeVector::reset() {
	nextFreeSlot = 0;
}

void DOMNodeVector::setElementAt(DOMNode *elem, XMLSize_t index) {
	assert(index < nextFreeSlot);
	data[index] = elem;
}


XERCES_CPP_NAMESPACE_END

