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

#include "xalanc/XSLT/StylesheetConstructionContextDefault.hpp"



#include <algorithm>



#include <xalanc/Include/STLHelper.hpp>



#include <xalanc/PlatformSupport/StringTokenizer.hpp>
#include <xalanc/PlatformSupport/URISupport.hpp>
#include <xalanc/PlatformSupport/XalanMessageLoader.hpp>



#include <xalanc/DOMSupport/DOMServices.hpp>



#include <xalanc/XPath/XObjectFactory.hpp>
#include <xalanc/XPath/XPathEnvSupport.hpp>
#include <xalanc/XPath/XPathFactory.hpp>
#include <xalanc/XPath/XPathProcessorImpl.hpp>



#include "xalanc/XSLT/Constants.hpp"
#include "xalanc/XSLT/ElemApplyImport.hpp"
#include "xalanc/XSLT/ElemChoose.hpp"
#include "xalanc/XSLT/ElemComment.hpp"
#include "xalanc/XSLT/ElemCopy.hpp"
#include "xalanc/XSLT/ElemCopyOf.hpp"
#include "xalanc/XSLT/ElemDecimalFormat.hpp"
#include "xalanc/XSLT/ElemExtensionCall.hpp"
#include "xalanc/XSLT/ElemFallback.hpp"
#include "xalanc/XSLT/ElemForwardCompatible.hpp"
#include "xalanc/XSLT/ElemForEach.hpp"
#include "xalanc/XSLT/ElemIf.hpp"
#include "xalanc/XSLT/ElemMessage.hpp"
#include "xalanc/XSLT/ElemNumber.hpp"
#include "xalanc/XSLT/ElemOtherwise.hpp"
#include "xalanc/XSLT/ElemParam.hpp"
#include "xalanc/XSLT/ElemPI.hpp"
#include "xalanc/XSLT/ElemSort.hpp"
#include "xalanc/XSLT/ElemWhen.hpp"
#include "xalanc/XSLT/ElemWithParam.hpp"
#include "xalanc/XSLT/StylesheetRoot.hpp"
#include "xalanc/XSLT/XSLTEngineImpl.hpp"
#include "xalanc/XSLT/XSLTInputSource.hpp"



XALAN_CPP_NAMESPACE_BEGIN



StylesheetConstructionContextDefault::StylesheetConstructionContextDefault(
            MemoryManagerType&                      theManager,
            XSLTEngineImpl&                         processor,
            XPathFactory&                           xpathFactory,
            VectorAllocatorSizeType                 theXalanDOMCharVectorAllocatorBlockSize,
            XalanAVTAllocator::size_type            theAVTAllocatorBlockSize,
            XalanAVTPartSimpleAllocator::size_type  theAVTPartSimpleAllocatorBlockSize,
            XalanAVTPartXPathAllocator::size_type   theAVTPartXPathAllocatorBlockSize,
            XalanQNameByValueAllocator::size_type   theXalanQNameByValueAllocatorBlockSize,
            VectorAllocatorSizeType                 thePointerVectorAllocatorBlockSize) :
    StylesheetConstructionContext(theManager),
    m_processor(processor),
    m_xpathFactory(xpathFactory),
    m_xpathProcessor(theManager, XPathProcessorImpl::create(theManager)),
    m_stylesheets(theManager),
    m_stringPool(theManager),
    m_xalanDOMCharVectorAllocator(theManager, theXalanDOMCharVectorAllocatorBlockSize),
    m_tempBuffer(theManager),
    m_scratchQName(theManager),
    m_stringCache(theManager),
    m_avtAllocator(theManager, theAVTAllocatorBlockSize),
    m_avtPartSimpleAllocator(theManager, theAVTPartSimpleAllocatorBlockSize),
    m_avtPartXPathAllocator(theManager, theAVTPartXPathAllocatorBlockSize),
    m_xalanQNameByValueAllocator(theManager, theXalanQNameByValueAllocatorBlockSize),
    m_useAttributeSetsQName(XSLTEngineImpl::getXSLNameSpaceURL(), Constants::ATTRNAME_USEATTRIBUTESETS),
    m_pointerVectorAllocator(theManager, thePointerVectorAllocatorBlockSize),
    m_allocatedElements(theManager),
    m_elemApplyTemplatesAllocator(theManager, eDefaultElemApplyTemplatesBlockSize),
    m_elemAttributeAllocator(theManager, eDefaultElemAttributeBlockSize),
    m_elemAttributeSetAllocator(theManager, eDefaultElemAttributeSetBlockSize),
    m_elemCallTemplateAllocator(theManager, eDefaultElemCallTemplateBlockSize),
    m_elemElementAllocator(theManager, eDefaultElemElementBlockSize),
    m_elemLiteralResultAllocator(theManager, eDefaultElemLiteralResultBlockSize),
    m_elemTemplateAllocator(theManager, eDefaultElemTemplateBlockSize),
    m_elemTextLiteralAllocator(theManager, eDefaultElemTextLiteralBlockSize),
    m_elemValueOfAllocator(theManager, eDefaultElemValueOfBlockSize),
    m_elemVariableAllocator(theManager, eDefaultElemVariableBlockSize),
    m_matchPatternDataAllocator(theManager,eDefaultMatchPatternDataBlockSize),
    m_spaceAttrQName(DOMServices::s_XMLNamespaceURI, Constants::ATTRNAME_SPACE)
{
}



StylesheetConstructionContextDefault::~StylesheetConstructionContextDefault()
{
    reset();
}



void
StylesheetConstructionContextDefault::error(
            const XalanDOMString&       msg,
            const XalanNode*            sourceNode,
            const ElemTemplateElement*  styleNode) const
{
    m_processor.error(msg, sourceNode, styleNode);
}



void
StylesheetConstructionContextDefault::error(
            const XalanDOMString&   msg,
            const XalanNode*        sourceNode,
            const LocatorType*      locator) const
{
    if (locator != 0)
    {
        m_processor.error(msg, *locator, sourceNode);
    }
    else
    {
        m_processor.error(msg, sourceNode);
    }
}




void
StylesheetConstructionContextDefault::warn(
            const XalanDOMString&       msg,
            const XalanNode*            sourceNode,
            const ElemTemplateElement*  styleNode) const
{
    m_processor.warn(msg, sourceNode, styleNode);
}



void
StylesheetConstructionContextDefault::warn(
            const XalanDOMString&   msg,
            const XalanNode*        sourceNode,
            const LocatorType*      locator) const
{
    if (locator != 0)
    {
        m_processor.warn(msg, *locator, sourceNode);
    }
    else
    {
        m_processor.warn(msg, sourceNode);
    }
}


void
StylesheetConstructionContextDefault::message(
            const XalanDOMString&       msg,
            const XalanNode*            sourceNode,
            const ElemTemplateElement*  styleNode) const
{
    m_processor.message(msg, sourceNode, styleNode);
}



void
StylesheetConstructionContextDefault::message(
            const XalanDOMString&   msg,
            const XalanNode*        sourceNode,
            const LocatorType*      locator) const
{
    if (locator != 0)
    {
        m_processor.message(msg, *locator, sourceNode);
    }
    else
    {
        m_processor.message(msg, sourceNode);
    }
}


void
StylesheetConstructionContextDefault::reset()
{
    XALAN_USING_STD(for_each)

    for_each(
            m_stylesheets.begin(),
            m_stylesheets.end(),
            DeleteFunctor<StylesheetRoot>( getMemoryManager()));

    m_stylesheets.clear();

    for_each(
            m_allocatedElements.begin(),
            m_allocatedElements.end(),
            DeleteFunctor<ElemTemplateElement>( getMemoryManager()));

    m_allocatedElements.clear();

    m_xpathFactory.reset();

    m_stringPool.clear();

    m_stringCache.reset();

    m_avtAllocator.reset();

    m_avtPartSimpleAllocator.reset();

    m_avtPartXPathAllocator.reset();

    m_xalanQNameByValueAllocator.reset();

    m_pointerVectorAllocator.reset();

    m_elemApplyTemplatesAllocator.reset();

    m_elemAttributeAllocator.reset();

    m_elemAttributeSetAllocator.reset();

    m_elemCallTemplateAllocator.reset();

    m_elemElementAllocator.reset();

    m_elemLiteralResultAllocator.reset();

    m_elemTemplateAllocator.reset();

    m_elemTextLiteralAllocator.reset();

    m_elemValueOfAllocator.reset();

    m_elemVariableAllocator.reset();

    m_matchPatternDataAllocator.reset();
}



StylesheetRoot*
StylesheetConstructionContextDefault::create(const XalanDOMString&  theBaseIdentifier)
{
    m_stylesheets.reserve(m_stylesheets.size() + 1);

    StylesheetRoot* const   theStylesheetRoot =
        StylesheetRoot::create( getMemoryManager(), theBaseIdentifier, *this);

    m_stylesheets.push_back(theStylesheetRoot);

    return theStylesheetRoot;
}



StylesheetRoot*
StylesheetConstructionContextDefault::create(const XSLTInputSource&     theInputSource)
{
    const XMLCh* const  theSystemID =
                theInputSource.getSystemId();

    GetAndReleaseCachedString theGuard(*this);

    XalanDOMString& theBaseIdentifier = theGuard.get();

    if (theSystemID != 0)
    {
        theBaseIdentifier.assign(theSystemID); 
    }


    return create(theBaseIdentifier);
}



Stylesheet*
StylesheetConstructionContextDefault::create(
            StylesheetRoot&         theStylesheetRoot,
            const XalanDOMString&   theBaseIdentifier)
{
    Stylesheet* const   theStylesheet =
        Stylesheet::create(
            getMemoryManager(),
            theStylesheetRoot,
            theBaseIdentifier,
            *this);

    return theStylesheet;
}



void
StylesheetConstructionContextDefault::destroy(StylesheetRoot*   theStylesheetRoot)
{
    XALAN_USING_STD(find)

    const StylesheetVectorType::iterator    i =
        find(
            m_stylesheets.begin(),
            m_stylesheets.end(),
            theStylesheetRoot);

    if (i != m_stylesheets.end())
    {
        m_stylesheets.erase(i);

        delete theStylesheetRoot;
    }

    if (m_stylesheets.empty() == true)
    {
        reset();
    }
}



StylesheetConstructionContextDefault::URLAutoPtrType
StylesheetConstructionContextDefault::getURLFromString(const XalanDOMString&    urlString)
{
    return URISupport::getURLFromString(urlString,  getMemoryManager());
}



XalanDOMString&
StylesheetConstructionContextDefault::getURLStringFromString(const XalanDOMString&  urlString,
                                                             XalanDOMString&        theResult)
{
    URISupport::getURLStringFromString(urlString, theResult);

    return theResult;
}



StylesheetConstructionContextDefault::URLAutoPtrType
StylesheetConstructionContextDefault::getURLFromString(
            const XalanDOMString&   urlString,
            const XalanDOMString&   base)
{
    return URISupport::getURLFromString(urlString, base,  getMemoryManager());
}



XalanDOMString&
StylesheetConstructionContextDefault::getURLStringFromString(
            const XalanDOMString&   urlString,
            const XalanDOMString&   base,
            XalanDOMString&         theResult)
{
    URISupport::getURLStringFromString(urlString, base, theResult);

    return theResult;
}



const XalanDOMString&
StylesheetConstructionContextDefault::getXSLTNamespaceURI() const
{
    return XSLTEngineImpl::getXSLNameSpaceURL();
}



XPath*
StylesheetConstructionContextDefault::createMatchPattern(
            const LocatorType*      locator,
            const XalanDOMString&   str,
            const PrefixResolver&   resolver,
            bool                    allowVariableReferences,
            bool                    allowKeyFunction)
{
    XPath* const    xpath = m_xpathFactory.create();

    // Note that we use the current locator from the
    // processing stack, and not the locator passed in.
    // This is because the locator on the stack is active,
    // during construction, while the locator passed in
    // will be used at run-time.
    m_xpathProcessor->initMatchPattern(
            *xpath,
            *this,
            str,
            resolver,
            getLocatorFromStack(),
            allowVariableReferences,
            allowKeyFunction);

    xpath->setInStylesheet(true);

    xpath->setLocator(locator);

    return xpath;
}



XPath*
StylesheetConstructionContextDefault::createMatchPattern(
            const LocatorType*      locator,
            const XalanDOMChar*     str,
            const PrefixResolver&   resolver,
            bool                    allowVariableReferences,
            bool                    allowKeyFunction)
{
    assert(str != 0);

    assign(m_tempBuffer, str);

    return createMatchPattern(
                locator,
                m_tempBuffer,
                resolver,
                allowVariableReferences,
                allowKeyFunction);
}



XPath*
StylesheetConstructionContextDefault::createXPath(
            const LocatorType*      locator,
            const XalanDOMString&   str,
            const PrefixResolver&   resolver,
            bool                    allowVariableReferences,
            bool                    allowKeyFunction)
{
    XPath* const    xpath = m_xpathFactory.create();

    // Note that we use the current locator from the
    // processing stack, and not the locator passed in.
    // This is because the locator on the stack is active,
    // during construction, while the locator passed in
    // will be used at run-time.
    m_xpathProcessor->initXPath(
            *xpath,
            *this,
            str,
            resolver,
            getLocatorFromStack(),
            allowVariableReferences,
            allowKeyFunction);

    xpath->setInStylesheet(true);

    xpath->setLocator(locator);

    return xpath;
}



XPath*
StylesheetConstructionContextDefault::createXPath(
            const LocatorType*      locator,
            const XalanDOMChar*     str,
            const PrefixResolver&   resolver,
            bool                    allowVariableReferences,
            bool                    allowKeyFunction)
{
    assert(str != 0);

    assign(m_tempBuffer, str);

    return createXPath(
                locator,
                m_tempBuffer,
                resolver,
                allowVariableReferences,
                allowKeyFunction);
}



XPath*
StylesheetConstructionContextDefault::createXPath(
            const LocatorType*          locator,
            const XalanDOMChar*         str,
            XalanDOMString::size_type   len,
            const PrefixResolver&       resolver,
            bool                        allowVariableReferences,
            bool                        allowKeyFunction)
{
    assert(str != 0);

    assign(m_tempBuffer, str, len);

    return createXPath(
                locator,
                m_tempBuffer,
                resolver,
                allowVariableReferences,
                allowKeyFunction);
}



const LocatorType*
StylesheetConstructionContextDefault::getLocatorFromStack() const
{
    return m_processor.getLocatorFromStack();
}



void
StylesheetConstructionContextDefault::pushLocatorOnStack(const LocatorType*     locator)
{
    m_processor.pushLocatorOnStack(locator);
}



void
StylesheetConstructionContextDefault::popLocatorStack()
{
    m_processor.popLocatorStack();
}



const XalanDOMString&
StylesheetConstructionContextDefault::getXalanXSLNameSpaceURL() const
{
    return XSLTEngineImpl::getXalanXSLNameSpaceURL();
}



XalanDocument*
StylesheetConstructionContextDefault::parseXML(
            const XalanDOMString&   urlString,
            DocumentHandlerType*    docHandler,
            XalanDocument*          docToRegister)
{
    return m_processor.parseXML(urlString, docHandler, docToRegister);
}



bool
StylesheetConstructionContextDefault::isXMLSpaceAttribute(
            const XalanDOMChar*     theAttributeName,
            const Stylesheet&       theStylesheet,
            const LocatorType*      theLocator)
{
    assert(theAttributeName != 0);

    m_scratchQName.set(theAttributeName, theStylesheet.getNamespaces(), theLocator, true);

    return m_spaceAttrQName == m_scratchQName;
}



bool
StylesheetConstructionContextDefault::isXSLUseAttributeSetsAttribute(
            const XalanDOMChar*     theAttributeName,
            const Stylesheet&       theStylesheet,
            const LocatorType*      theLocator)
{
    assert(theAttributeName != 0);

    m_scratchQName.set(theAttributeName, theStylesheet.getNamespaces(), theLocator, true);

    return m_useAttributeSetsQName == m_scratchQName;
}



bool
StylesheetConstructionContextDefault::isValidQName(
            const XalanDOMChar*     theName,
            const Stylesheet&       theStylesheet,
            const LocatorType*      theLocator)
{
    assert(theName != 0);

    m_scratchQName.set(theName, theStylesheet.getNamespaces(), theLocator, false);

    return m_scratchQName.isValid();
}



template <class Type>
class CreateElementFunctor
{
public:

    Type*
    operator()(         
        MemoryManagerType&              theManager,
        StylesheetConstructionContext&  constructionContext,
        Stylesheet&                     stylesheetTree,
        const AttributeListType&        atts,
        int                             lineNumber,
        int                             columnNumber)
    {
        Type*   theResult;

        return XalanConstruct(
                    theManager,
                    theResult,
                    constructionContext,
                    stylesheetTree,
                    atts,
                    lineNumber,
                    columnNumber);
    }
};



ElemTemplateElement*
StylesheetConstructionContextDefault::createElement(
            int                         token,
            Stylesheet&                 stylesheetTree,
            const AttributeListType&    atts,
            const LocatorType*          locator)
{
    const XalanLocator::size_type   lineNumber = XalanLocator::getLineNumber(locator);
    const XalanLocator::size_type   columnNumber = XalanLocator::getColumnNumber(locator);

    ElemTemplateElement*    theElement = 0;

    switch(token)
    {
    case ELEMNAME_APPLY_IMPORTS:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemApplyImport>() (
            getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_APPLY_TEMPLATES:
        return m_elemApplyTemplatesAllocator.create(
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_ATTRIBUTE:
        return m_elemAttributeAllocator.create(
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_ATTRIBUTE_SET:
        return m_elemAttributeSetAllocator.create(
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_CALL_TEMPLATE:
        return m_elemCallTemplateAllocator.create(
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_CHOOSE:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemChoose>()(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_COMMENT:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemComment>()(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
      break;

    case ELEMNAME_COPY:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemCopy>()(
            getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_COPY_OF:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemCopyOf>()(
            getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_DECIMAL_FORMAT:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemDecimalFormat>()(
            getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_ELEMENT:
        return m_elemElementAllocator.create(
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
      break;

    case ELEMNAME_FALLBACK:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemFallback>()(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_FOR_EACH:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemForEach>()(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_IF:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemIf>()(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_MESSAGE:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemMessage>()(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_NUMBER:
        m_allocatedElements.push_back(0);

        theElement = ElemNumber::create(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber,
            stylesheetTree.getStylesheetRoot().getNextElemNumberID());
        break;

    case ELEMNAME_OTHERWISE:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemOtherwise>()(
            getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_PARAM:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemParam>()(
            getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_PI:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemPI>()(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
      break;

    case ELEMNAME_SORT:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemSort>()(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_TEMPLATE:
        return m_elemTemplateAllocator.create(
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_VALUE_OF:
        return m_elemValueOfAllocator.create(
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_VARIABLE:
        return m_elemVariableAllocator.create(
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_WITH_PARAM:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemWithParam>()(
             getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    case ELEMNAME_WHEN:
        m_allocatedElements.push_back(0);

        theElement = CreateElementFunctor<ElemWhen>()(
            getMemoryManager(),
            *this,
            stylesheetTree,
            atts,
            lineNumber,
            columnNumber);
        break;

    default:
        {
            const GetAndReleaseCachedString     theGuard1(*this);
            const GetAndReleaseCachedString     theGuard2(*this);

            error(
                XalanMessageLoader::getMessage(
                    theGuard1.get(),
                    XalanMessages::UnknownXSLTToken_1Param,
                    LongToDOMString(
                        token,
                        theGuard2.get())),
                0,
                locator);
        }
        break;
    };

    assert(theElement != 0 && m_allocatedElements.back() == 0);

    m_allocatedElements.back() = theElement;

    return theElement;
}



ElemTemplateElement*
StylesheetConstructionContextDefault::createElement(
            int                         token,
            Stylesheet&                 stylesheetTree,
            const XalanDOMChar*         name,
            const AttributeListType&    atts,
            const LocatorType*          locator)
{
    const XalanLocator::size_type   lineNumber = XalanLocator::getLineNumber(locator);
    const XalanLocator::size_type   columnNumber = XalanLocator::getColumnNumber(locator);

    ElemTemplateElement*    theElement = 0;

    if (token == ELEMNAME_LITERAL_RESULT)
    {
        theElement = m_elemLiteralResultAllocator.create(
            *this,
            stylesheetTree,
            name,
            atts,
            lineNumber,
            columnNumber);
    }
    else if (token == ELEMNAME_FORWARD_COMPATIBLE)
    {
        m_allocatedElements.push_back(0);

        theElement = ElemForwardCompatible::create(
             getMemoryManager(),
            *this,
            stylesheetTree,
            name,
            atts,
            lineNumber,
            columnNumber);

        m_allocatedElements.back() = theElement;
    }
    else
    {
        GetAndReleaseCachedString theGuard(*this);
        GetAndReleaseCachedString theGuard1(*this);

        error(
            XalanMessageLoader::getMessage(
                theGuard.get(),
                XalanMessages::UnknownXSLTToken_1Param,
                LongToDOMString(token, theGuard1.get())),
            0,
            locator);
    }

    return theElement;
}



ElemTemplateElement*
StylesheetConstructionContextDefault::createElement(
            Stylesheet&                 stylesheetTree,
            const XalanDOMChar*         name,
            const AttributeListType&    atts,
            ExtensionNSHandler&         handler,
            const LocatorType*          locator)
{
    const XalanLocator::size_type   lineNumber = XalanLocator::getLineNumber(locator);
    const XalanLocator::size_type   columnNumber = XalanLocator::getColumnNumber(locator);

    m_allocatedElements.push_back(0);

    m_allocatedElements.back() = ElemExtensionCall::create(
            getMemoryManager(),
            *this,
            stylesheetTree,
            name,
            atts,
            lineNumber,
            columnNumber,
            handler);

    return m_allocatedElements.back();
}



ElemTemplateElement*
StylesheetConstructionContextDefault::createElement(
            Stylesheet&                 stylesheetTree,
            const XalanDOMChar*         chars,
            XalanDOMString::size_type   length,
            bool                        preserveSpace,
            bool                        disableOutputEscaping,
            const LocatorType*          locator)
{
    const XalanLocator::size_type   lineNumber = XalanLocator::getLineNumber(locator);
    const XalanLocator::size_type   columnNumber = XalanLocator::getColumnNumber(locator);

    return m_elemTextLiteralAllocator.create(
            *this,
            stylesheetTree,
            lineNumber,
            columnNumber,
            chars,
            0,
            length,
            preserveSpace, 
            disableOutputEscaping);
}



const XalanMatchPatternData*
StylesheetConstructionContextDefault::createXalanMatchPatternData(
            const ElemTemplate&     theTemplate,
            size_type               thePosition,
            const XalanDOMString&   theTargetString,
            const XPath&            theMatchPattern,
            const XalanDOMString&   thePatternString,
            XPath::eMatchScore      thePriority)
{
    return m_matchPatternDataAllocator.create(
            theTemplate,
            thePosition,
            theTargetString,
            theMatchPattern,
            thePatternString,
            thePriority);
}



StylesheetConstructionContextDefault::eElementToken
StylesheetConstructionContextDefault::getElementToken(const XalanDOMString&     name) const
{
    return getElementNameToken(name);
}



StylesheetConstructionContextDefault::eElementToken
StylesheetConstructionContextDefault::getElementNameToken(const XalanDOMString&     name)
{
    // Find the entity, if any...
    const ElementTokenTableEntry*   theFirst = s_elementTokenTable;
    const ElementTokenTableEntry*   theLast = &s_elementTokenTableLast;

    while(theFirst <= theLast)
    {
        const ElementTokenTableEntry* const 
            theCurrent = theFirst + (theLast - theFirst) / 2;

        const int   theResult = compareIgnoreCaseASCII(name, theCurrent->m_name);

        if (theResult < 0)
        {
            theLast = theCurrent - 1;
        }
        else if (theResult > 0)
        {
            theFirst = theCurrent + 1;
        }
        else
        {
            return theCurrent->m_token;
        }
    }

    return s_elementTokenTableDummy.m_token;
}



double
StylesheetConstructionContextDefault::getXSLTVersionSupported() const
{
    return 1.0L;
}



const XalanDOMString&
StylesheetConstructionContextDefault::getPooledString(const XalanDOMString&     theString)
{
    return m_stringPool.get(theString);
}



const XalanDOMString&
StylesheetConstructionContextDefault::getPooledString(
            const XalanDOMChar*         theString,
            XalanDOMString::size_type   theLength)
{
    return m_stringPool.get(theString, theLength);
}



XalanDOMString&
StylesheetConstructionContextDefault::getCachedString()
{
    return m_stringCache.get();
}



bool
StylesheetConstructionContextDefault::releaseCachedString(XalanDOMString&   theString)
{
    return m_stringCache.release(theString);
}



XalanDOMChar*
StylesheetConstructionContextDefault::allocateXalanDOMCharVector(XalanDOMString::size_type  theLength)
{
    return m_xalanDOMCharVectorAllocator.allocate(theLength);
}



XalanDOMChar*
StylesheetConstructionContextDefault::allocateXalanDOMCharVector(
            const XalanDOMChar*         theString,
            XalanDOMString::size_type   theLength,
            bool                        fTerminate)
{
    assert(theString != 0);

    const XalanDOMString::size_type     theActualLength =
        theLength == XalanDOMString::npos ? XalanDOMString::length(theString) : theLength;

    XalanDOMChar*   theVector =
        m_xalanDOMCharVectorAllocator.allocate(fTerminate == true ? theActualLength + 1 : theActualLength);

    XalanDOMChar* const     theEnd =
        XalanCopy(theString, theString + theActualLength, theVector);

    if (fTerminate == true)
    {
        *theEnd = XalanDOMChar(0);
    }

    return theVector;
}



const AVT*
StylesheetConstructionContextDefault::createAVT(
            const LocatorType*              locator,
            const XalanDOMChar*             name,
            const XalanDOMChar*             stringedValue,
            const PrefixResolver&           resolver)
{
    return m_avtAllocator.create(*this, locator, name, stringedValue, resolver);
}



const AVTPart*
StylesheetConstructionContextDefault::createAVTPart(
            const XalanDOMChar*         theString,
            XalanDOMString::size_type   theLength)
{
    return m_avtPartSimpleAllocator.create(*this, theString, theLength);
}



const AVTPart*
StylesheetConstructionContextDefault::createAVTPart(
            const LocatorType*          locator,
            const XalanDOMChar*         str,
            XalanDOMString::size_type   len,
            const PrefixResolver&       resolver)
{
    const XPath* const  xpath =
        createXPath(
            locator,
            str,
            len,
            resolver);

    assert(xpath != 0);

    return m_avtPartXPathAllocator.create(xpath);
}



const AVT**
StylesheetConstructionContextDefault::allocateAVTPointerVector(size_type    theLength)
{
    return doAllocateAVTPointerVector(theLength);
}



const AVTPart**
StylesheetConstructionContextDefault::allocateAVTPartPointerVector(size_type    theLength)
{
    return doAllocateAVTPartPointerVector(theLength);
}



const XalanQName*
StylesheetConstructionContextDefault::createXalanQName(
            const XalanDOMString&       qname,
            const NamespacesStackType&  namespaces,
            const LocatorType*          locator,
            bool                        fUseDefault)
{
    return  m_xalanQNameByValueAllocator.create(qname, namespaces, locator, fUseDefault);

}



const XalanQName*
StylesheetConstructionContextDefault::createXalanQName(
            const XalanDOMChar*         qname,
            const NamespacesStackType&  namespaces,
            const LocatorType*          locator,
            bool                        fUseDefault)
{
    return  m_xalanQNameByValueAllocator.create(qname, namespaces, locator, fUseDefault);

}



const XalanQName**
StylesheetConstructionContextDefault::tokenizeQNames(
            size_type&                  count,
            const XalanDOMChar*         qnameTokens,
            const NamespacesStackType&  namespaces,
            const LocatorType*          locator,
            bool                        fUseDefault)
{
    assert(qnameTokens != 0);

    StringTokenizer     tokenizer(qnameTokens);

    count = tokenizer.countTokens();

    if (count == 0)
    {
        return 0;
    }
    else
    {
        const XalanQName**  theResult = doAllocateXalanQNamePointerVector(count);
        assert(theResult != 0);

        const GetAndReleaseCachedString     theGuard(*this);

        XalanDOMString&     qname = theGuard.get();

        size_type   theCurrentIndex = 0;

        while(tokenizer.hasMoreTokens())
        {
            tokenizer.nextToken(qname);
            assert(length(qname) != 0);

            theResult[theCurrentIndex++] =
                    m_xalanQNameByValueAllocator.create(
                        qname,
                        namespaces,
                        locator,
                        fUseDefault);
        }

        assert(theCurrentIndex == count);

        return theResult;
    }
}



const XalanDOMChar  StylesheetConstructionContextDefault::s_if[] =
{
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_f,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_key[] =
{
    XalanUnicode::charLetter_k,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_y,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_copy[] =
{
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_y,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_sort[] =
{
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_t,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_text[] =
{
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_x,
    XalanUnicode::charLetter_t,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_when[] =
{
    XalanUnicode::charLetter_w,
    XalanUnicode::charLetter_h,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_n,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_empty[] =
{
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_y,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_param[] =
{
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_m,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_choose[] =
{
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_h,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_import[] =
{
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_t,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_number[] =
{
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_b,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_r,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_output[] =
{
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_t,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_comment[] =
{
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_t,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_copyOf[] =
{
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_y,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_f,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_element[] =
{
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_t,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_include[] =
{
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_d,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_message[] =
{
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_g,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_fallback[] =
{
    XalanUnicode::charLetter_f,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_b,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_k,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_forEach[] =
{
    XalanUnicode::charLetter_f,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_r,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_h,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_template[] =
{
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_valueOf[] =
{
    XalanUnicode::charLetter_v,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_e,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_f,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_variable[] =
{
    XalanUnicode::charLetter_v,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_b,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_attribute[] =
{
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_b,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_otherwise[] =
{
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_h,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_w,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_transform[] =
{
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_f,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_m,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_stylesheet[] =
{
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_y,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_h,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_t,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_withParam[] =
{
    XalanUnicode::charLetter_w,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_h,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_m,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_stripSpace[] =
{
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_p,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_applyImports[] =
{
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_y,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_s,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_attributeSet[] =
{
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_b,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_t,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_callTemplate[] =
{
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_l,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_decimalFormat[] =
{
    XalanUnicode::charLetter_d,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_l,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_f,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_t,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_preserveSpace[] =
{
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_v,
    XalanUnicode::charLetter_e,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_e,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_applyTemplates[] =
{
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_y,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_s,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_namespaceAlias[] =
{
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_m,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_e,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_l,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_a,
    XalanUnicode::charLetter_s,
    0
};

const XalanDOMChar  StylesheetConstructionContextDefault::s_processingInstruction[] =
{
    XalanUnicode::charLetter_p,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_e,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_g,
    XalanUnicode::charHyphenMinus,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_n,
    XalanUnicode::charLetter_s,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_r,
    XalanUnicode::charLetter_u,
    XalanUnicode::charLetter_c,
    XalanUnicode::charLetter_t,
    XalanUnicode::charLetter_i,
    XalanUnicode::charLetter_o,
    XalanUnicode::charLetter_n,
    0
};


const StylesheetConstructionContextDefault::ElementTokenTableEntry  StylesheetConstructionContextDefault::s_elementTokenTable[] =
{
    {
        s_if,
        ELEMNAME_IF
    },
    {
        s_key,
        ELEMNAME_KEY
    },
    {
        s_copy,
        ELEMNAME_COPY
    },
    {
        s_sort,
        ELEMNAME_SORT
    },
    {
        s_text,
        ELEMNAME_TEXT
    },
    {
        s_when,
        ELEMNAME_WHEN
    },
    {
        s_empty,
        ELEMNAME_EMPTY
    },
    {
        s_param,
        ELEMNAME_PARAM
    },
    {
        s_choose,
        ELEMNAME_CHOOSE
    },
    {
        s_import,
        ELEMNAME_IMPORT
    },
    {
        s_number,
        ELEMNAME_NUMBER
    },
    {
        s_output,
        ELEMNAME_OUTPUT
    },
    {
        s_comment,
        ELEMNAME_COMMENT
    },
    {
        s_copyOf,
        ELEMNAME_COPY_OF
    },
    {
        s_element,
        ELEMNAME_ELEMENT
    },
    {
        s_include,
        ELEMNAME_INCLUDE
    },
    {
        s_message,
        ELEMNAME_MESSAGE
    },
    {
        s_fallback,
        ELEMNAME_FALLBACK
    },
    {
        s_forEach,
        ELEMNAME_FOR_EACH
    },
    {
        s_template,
        ELEMNAME_TEMPLATE
    },
    {
        s_valueOf,
        ELEMNAME_VALUE_OF
    },
    {
        s_variable,
        ELEMNAME_VARIABLE
    },
    {
        s_attribute,
        ELEMNAME_ATTRIBUTE
    },
    {
        s_otherwise,
        ELEMNAME_OTHERWISE
    },
    {
        s_transform,
        ELEMNAME_STYLESHEET
    },
    {
        s_stylesheet,
        ELEMNAME_STYLESHEET
    },
    {
        s_withParam,
        ELEMNAME_WITH_PARAM
    },
    {
        s_stripSpace,
        ELEMNAME_STRIP_SPACE
    },
    {
        s_applyImports,
        ELEMNAME_APPLY_IMPORTS
    },
    {
        s_attributeSet,
        ELEMNAME_ATTRIBUTE_SET
    },
    {
        s_callTemplate,
        ELEMNAME_CALL_TEMPLATE
    },
    {
        s_decimalFormat,
        ELEMNAME_DECIMAL_FORMAT
    },
    {
        s_preserveSpace,
        ELEMNAME_PRESERVE_SPACE
    },
    {
        s_applyTemplates,
        ELEMNAME_APPLY_TEMPLATES
    },
    {
        s_namespaceAlias,
        ELEMNAME_NAMESPACE_ALIAS
    },
    {
        s_processingInstruction,
        ELEMNAME_PI
    },
    // This must be the last one...
    {
        0,
        ELEMNAME_UNDEFINED
    }
};

const unsigned int  StylesheetConstructionContextDefault::s_elementTokenTableSize =
        sizeof(s_elementTokenTable) / sizeof(s_elementTokenTable[0]);

const StylesheetConstructionContextDefault::ElementTokenTableEntry&     StylesheetConstructionContextDefault::s_elementTokenTableLast =
    StylesheetConstructionContextDefault::s_elementTokenTable[s_elementTokenTableSize - 2];

const StylesheetConstructionContextDefault::ElementTokenTableEntry&     StylesheetConstructionContextDefault::s_elementTokenTableDummy =
    StylesheetConstructionContextDefault::s_elementTokenTable[s_elementTokenTableSize - 1];



XALAN_CPP_NAMESPACE_END
