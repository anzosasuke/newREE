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
// Base class header file.
#include "xalanc/XPath/XPathParserException.hpp"



XALAN_CPP_NAMESPACE_BEGIN


const XalanDOMChar	XPathParserException::m_type[] = 
{	
	XalanUnicode::charLetter_X,
	XalanUnicode::charLetter_P,
	XalanUnicode::charLetter_a,
	XalanUnicode::charLetter_t,
	XalanUnicode::charLetter_h,
	XalanUnicode::charLetter_P,
	XalanUnicode::charLetter_a,
	XalanUnicode::charLetter_r,
	XalanUnicode::charLetter_s,
	XalanUnicode::charLetter_e,
	XalanUnicode::charLetter_r,
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



XPathParserException::XPathParserException(
			const XalanDOMString&	message,
			const XalanDOMString&	theURI,
			int						theLineNumber,
			int						theColumnNumber,
            MemoryManagerType&      theManager) :
	XalanXPathException(message, theURI, theLineNumber, theColumnNumber, theManager)
{
}



XPathParserException::XPathParserException(
			const LocatorType&		theLocator,
			const XalanDOMString&	theMessage,
            MemoryManagerType&      theManager) :
	XalanXPathException(theLocator, theMessage, theManager)
{
}



XPathParserException::XPathParserException(
			const XalanDOMString&	message,
            MemoryManagerType&      theManager) :
	XalanXPathException(message, theManager)
{
}



XPathParserException::~XPathParserException()
{
}



XALAN_CPP_NAMESPACE_END
