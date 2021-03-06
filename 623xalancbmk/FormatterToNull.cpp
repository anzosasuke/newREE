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
// Class header file
#include "xalanc/XMLSupport/FormatterToNull.hpp"



XALAN_CPP_NAMESPACE_BEGIN



FormatterToNull::FormatterToNull() :
	FormatterListener(OUTPUT_METHOD_NONE)
{
}



FormatterToNull::~FormatterToNull()
{
}



void
FormatterToNull::setDocumentLocator(const LocatorType* const	/* locator */)
{
}



void
FormatterToNull::startDocument()
{
}



void
FormatterToNull::endDocument()
{
}



void
FormatterToNull::startElement(
			const XMLCh* const	/* name */,
			AttributeListType&	/* attrs */)
{
}



void
FormatterToNull::endElement(
			const	XMLCh* const	/* name */)
{
}



void
FormatterToNull::characters(
			const XMLCh* const	/* chars */,
			const unsigned int	/* length */)
{
}



void
FormatterToNull::charactersRaw(
		const XMLCh* const	/* chars */,
		const unsigned int	/*length */)
{
}


void
FormatterToNull::entityReference(const XMLCh* const	/* name */)
{
}



void
FormatterToNull::ignorableWhitespace(
			const XMLCh* const	/* chars */,
			const unsigned int	/* length */)
{
}



void
FormatterToNull::processingInstruction(
			const XMLCh* const	/* target */,
			const XMLCh* const	/* data */)
{
}



void
FormatterToNull::resetDocument()
{
}



void
FormatterToNull::comment(const XMLCh* const	/* data */)
{
}



void
FormatterToNull::cdata(
			const XMLCh* const	 /* ch */,
			const unsigned int 	/* length */)
{
}



XALAN_CPP_NAMESPACE_END
