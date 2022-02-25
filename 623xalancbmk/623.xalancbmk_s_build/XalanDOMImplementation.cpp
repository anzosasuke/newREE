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
#include "xalanc/XalanDOM/XalanDOMImplementation.hpp"



XALAN_CPP_NAMESPACE_BEGIN



XalanDOMImplementation::XalanDOMImplementation()
{
}



XalanDOMImplementation::~XalanDOMImplementation()
{
}



XalanDOMImplementation::XalanDOMImplementation(const XalanDOMImplementation&	/* theSource */)
{
}



XalanDOMImplementation&
XalanDOMImplementation::operator=(const XalanDOMImplementation&	/* theSource */)
{
	return *this;
}



bool
XalanDOMImplementation::operator==(const XalanDOMImplementation&	/* theRHS */) const
{
	return false;
}



XALAN_CPP_NAMESPACE_END
