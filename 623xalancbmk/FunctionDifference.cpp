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
#include "xalanc/XalanExtensions/FunctionDifference.hpp"



#include <xalanc/PlatformSupport/XalanMessageLoader.hpp>



#include <xalanc/XPath/XPathExecutionContext.hpp>
#include <xalanc/XPath/XObjectFactory.hpp>



XALAN_CPP_NAMESPACE_BEGIN



FunctionDifference::FunctionDifference()
{
}



FunctionDifference::~FunctionDifference()
{
}



XObjectPtr
FunctionDifference::execute(
            XPathExecutionContext&          executionContext,
            XalanNode*                      context,
            const XObjectArgVectorType&     args,
            const LocatorType*              locator) const
{
    if (args.size() != 2)
    {
        XPathExecutionContext::GetAndReleaseCachedString theGuard(executionContext);
        XalanDOMString& theBuffer = theGuard.get();

        executionContext.error(getError(theBuffer), context, locator);
    }

    assert(args[0].null() == false && args[1].null() == false);

    const NodeRefListBase&  nodeset1 = args[0]->nodeset();
    const NodeRefListBase&  nodeset2 = args[1]->nodeset();

    typedef XPathExecutionContext::BorrowReturnMutableNodeRefList   BorrowReturnMutableNodeRefList;

    BorrowReturnMutableNodeRefList  theResult(executionContext);

    const NodeRefListBase::size_type    theLength = nodeset1.getLength();

    // Check the second node-set for nodes in the
    // first node-set.  If a node is not found,
    // add it to the result.
    for (NodeRefListBase::size_type i = 0; i < theLength; ++i)
    {
        XalanNode* const    theNode = nodeset1.item(i);
        assert(theNode != 0);

        if (nodeset2.indexOf(theNode) == NodeRefListBase::npos)
        {
            theResult->addNodeInDocOrder(theNode, executionContext);
        }
    }

    theResult->setDocumentOrder();

    return executionContext.getXObjectFactory().createNodeSet(theResult);
}



#if defined(XALAN_NO_COVARIANT_RETURN_TYPE)
Function*
#else
FunctionDifference*
#endif
FunctionDifference::clone(MemoryManagerType&    theManager) const
{
    return XalanCopyConstruct(theManager, *this);
}



const XalanDOMString&
FunctionDifference::getError(XalanDOMString&    theResult) const
{
    return XalanMessageLoader::getMessage(
                theResult,
                XalanMessages::FunctionAcceptsTwoArguments_1Param,
                "difference");
}



XALAN_CPP_NAMESPACE_END
