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
#include "xalanc/XPath/FunctionContains.hpp"



#include <xalanc/PlatformSupport/XalanMessageLoader.hpp>



#include "xalanc/XPath/XObjectFactory.hpp"



XALAN_CPP_NAMESPACE_BEGIN



FunctionContains::FunctionContains()
{
}



FunctionContains::~FunctionContains()
{
}



XObjectPtr
FunctionContains::execute(
            XPathExecutionContext&  executionContext,
            XalanNode*              /* context */,          
            const XObjectPtr        arg1,
            const XObjectPtr        arg2,
            const LocatorType*      /* locator */) const
{
    assert(arg1.null() == false && arg2.null() == false);   

    const XalanDOMString&   str1 = arg1->str();
    const XalanDOMString&   str2 = arg2->str();

    bool                    fResult = true;

    // If str2 is empty, then don't bother to check anything.
    if (isEmpty(str2) == false)
    {
        // Is str1 empty?
        if (isEmpty(str1) == true)
        {
            fResult = false;
        }
        else
        {
            // OK, both strings have some data, so look for
            // the index...
            const XalanDOMString::size_type     theIndex = indexOf(str1, str2);

            fResult = theIndex < length(str1) ? true : false;
        }
    }

    return executionContext.getXObjectFactory().createBoolean(fResult);
}



#if defined(XALAN_NO_COVARIANT_RETURN_TYPE)
Function*
#else
FunctionContains*
#endif
FunctionContains::clone(MemoryManagerType& theManager) const
{
    return XalanCopyConstruct(theManager, *this);
}



const XalanDOMString&
FunctionContains::getError(XalanDOMString& theResult) const
{
    return XalanMessageLoader::getMessage(
                theResult,
                XalanMessages::FunctionTakesTwoArguments_1Param,
                "contains()");
}



XALAN_CPP_NAMESPACE_END
