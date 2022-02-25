TUNE=peak
LABEL=collect-build-flags-m64
NUMBER=623
NAME=xalancbmk_s
SOURCES= AIXPlatformUtils.cpp CSetDefs.cpp Win32PlatformUtils.cpp \
	 Win32MsgLoader.cpp Win32TransService.cpp Win32TransService2.cpp \
	 SunCCDefs.cpp SolarisPlatformUtils.cpp GCCDefs.cpp \
	 LinuxPlatformUtils.cpp MIPSproDefs.cpp IRIXPlatformUtils.cpp \
	 HPCCDefs.cpp HPPlatformUtils.cpp ASCIIRangeFactory.cpp AVT.cpp \
	 AVTPart.cpp AVTPartSimple.cpp AVTPartXPath.cpp AbstractDOMParser.cpp \
	 AbstractNumericFacetValidator.cpp AbstractNumericValidator.cpp \
	 AbstractStringValidator.cpp AllContentModel.cpp \
	 AnySimpleTypeDatatypeValidator.cpp AnyURIDatatypeValidator.cpp \
	 AttrImpl.cpp AttrMapImpl.cpp AttrNSImpl.cpp AttributeListImpl.cpp \
	 AttributesImpl.cpp BMPattern.cpp Base64.cpp \
	 Base64BinaryDatatypeValidator.cpp BinFileInputStream.cpp \
	 BinFileOutputStream.cpp BinInputStream.cpp BinMemInputStream.cpp \
	 BinMemOutputStream.cpp BinOutputStream.cpp BitSet.cpp \
	 BlockRangeFactory.cpp BooleanDatatypeValidator.cpp CDATASectionImpl.cpp \
	 CMAny.cpp CMBinaryOp.cpp CMUnaryOp.cpp CharToken.cpp \
	 CharacterDataImpl.cpp ChildNode.cpp ClosureToken.cpp CommentImpl.cpp \
	 ComplexTypeInfo.cpp ConcatToken.cpp ConditionToken.cpp Constants.cpp \
	 ContentLeafNameTypeVector.cpp ContentSpecNode.cpp CountersTable.cpp \
	 DFAContentModel.cpp DGXMLScanner.cpp DOMAttrImpl.cpp DOMAttrMapImpl.cpp \
	 DOMAttrNSImpl.cpp DOMBuilderImpl.cpp DOMCDATASectionImpl.cpp \
	 DOMCharacterDataImpl.cpp DOMChildNode.cpp DOMCommentImpl.cpp \
	 DOMConfigurationImpl.cpp DOMDeepNodeListImpl.cpp \
	 DOMDocumentFragmentImpl.cpp DOMDocumentImpl.cpp DOMDocumentTypeImpl.cpp \
	 DOMElementImpl.cpp DOMElementNSImpl.cpp DOMEntityImpl.cpp \
	 DOMEntityReferenceImpl.cpp DOMErrorImpl.cpp DOMException.cpp \
	 DOMImplementationImpl.cpp DOMImplementationRegistry.cpp \
	 DOMLocatorImpl.cpp DOMNamedNodeMapImpl.cpp DOMNodeIDMap.cpp \
	 DOMNodeImpl.cpp DOMNodeIteratorImpl.cpp DOMNodeListImpl.cpp \
	 DOMNodeVector.cpp DOMNormalizer.cpp DOMNotationImpl.cpp \
	 DOMParentNode.cpp DOMParser.cpp DOMProcessingInstructionImpl.cpp \
	 DOMRangeException.cpp DOMRangeImpl.cpp DOMServices.cpp DOMString.cpp \
	 DOMStringHelper.cpp DOMStringPool.cpp DOMStringPrintWriter.cpp \
	 DOMSupport.cpp DOMSupportDefault.cpp DOMSupportException.cpp \
	 DOMSupportInit.cpp DOMTextImpl.cpp DOMTreeWalkerImpl.cpp \
	 DOMTypeInfoImpl.cpp DOMWriterImpl.cpp DOMXPathException.cpp DOM_Attr.cpp \
	 DOM_CDATASection.cpp DOM_CharacterData.cpp DOM_Comment.cpp \
	 DOM_DOMException.cpp DOM_DOMImplementation.cpp DOM_Document.cpp \
	 DOM_DocumentFragment.cpp DOM_DocumentType.cpp DOM_Element.cpp \
	 DOM_Entity.cpp DOM_EntityReference.cpp DOM_NamedNodeMap.cpp DOM_Node.cpp \
	 DOM_NodeFilter.cpp DOM_NodeIterator.cpp DOM_NodeList.cpp \
	 DOM_Notation.cpp DOM_ProcessingInstruction.cpp DOM_Range.cpp \
	 DOM_RangeException.cpp DOM_Text.cpp DOM_TreeWalker.cpp DOM_XMLDecl.cpp \
	 DStringPool.cpp DTDAttDef.cpp DTDAttDefList.cpp DTDElementDecl.cpp \
	 DTDEntityDecl.cpp DTDGrammar.cpp DTDScanner.cpp DTDValidator.cpp \
	 DatatypeValidator.cpp DatatypeValidatorFactory.cpp \
	 DateDatatypeValidator.cpp DateTimeDatatypeValidator.cpp \
	 DateTimeValidator.cpp DayDatatypeValidator.cpp \
	 DecimalDatatypeValidator.cpp DeepNodeListImpl.cpp \
	 DefaultPanicHandler.cpp DocumentFragmentImpl.cpp DocumentImpl.cpp \
	 DocumentTypeImpl.cpp DomMemDebug.cpp DoubleDatatypeValidator.cpp \
	 DoubleSupport.cpp Dummy.cpp DurationDatatypeValidator.cpp \
	 ENTITYDatatypeValidator.cpp ElemApplyImport.cpp ElemApplyTemplates.cpp \
	 ElemAttribute.cpp ElemAttributeSet.cpp ElemCallTemplate.cpp \
	 ElemChoose.cpp ElemComment.cpp ElemCopy.cpp ElemCopyOf.cpp \
	 ElemDecimalFormat.cpp ElemElement.cpp ElemEmpty.cpp \
	 ElemExtensionCall.cpp ElemFallback.cpp ElemForEach.cpp \
	 ElemForwardCompatible.cpp ElemIf.cpp ElemLiteralResult.cpp \
	 ElemMessage.cpp ElemNumber.cpp ElemOtherwise.cpp ElemPI.cpp \
	 ElemParam.cpp ElemSort.cpp ElemStack.cpp ElemTemplate.cpp \
	 ElemTemplateElement.cpp ElemText.cpp ElemTextLiteral.cpp ElemUse.cpp \
	 ElemValueOf.cpp ElemVariable.cpp ElemWhen.cpp ElemWithParam.cpp \
	 ElementDefinitionImpl.cpp ElementImpl.cpp ElementNSImpl.cpp \
	 ElementPrefixResolverProxy.cpp EncodingValidator.cpp EntityImpl.cpp \
	 EntityReferenceImpl.cpp ExecutionContext.cpp \
	 ExtensionFunctionHandler.cpp ExtensionNSHandler.cpp FieldActivator.cpp \
	 FieldValueMap.cpp FileHandleImpl.cpp FloatDatatypeValidator.cpp \
	 FormatterListener.cpp FormatterStringLengthCounter.cpp \
	 FormatterToDOM.cpp FormatterToDeprecatedXercesDOM.cpp \
	 FormatterToHTML.cpp FormatterToNull.cpp FormatterToSourceTree.cpp \
	 FormatterToText.cpp FormatterToXML.cpp FormatterToXercesDOM.cpp \
	 FormatterTreeWalker.cpp Function.cpp FunctionConcat.cpp \
	 FunctionContains.cpp FunctionCurrent.cpp FunctionDifference.cpp \
	 FunctionDistinct.cpp FunctionDocument.cpp FunctionElementAvailable.cpp \
	 FunctionEvaluate.cpp FunctionFormatNumber.cpp \
	 FunctionFunctionAvailable.cpp FunctionGenerateID.cpp \
	 FunctionHasSameNodes.cpp FunctionID.cpp FunctionIntersection.cpp \
	 FunctionKey.cpp FunctionLang.cpp FunctionNamespaceURI.cpp \
	 FunctionNodeSet.cpp FunctionNormalizeSpace.cpp FunctionStartsWith.cpp \
	 FunctionString.cpp FunctionSubstring.cpp FunctionSubstringAfter.cpp \
	 FunctionSubstringBefore.cpp FunctionSystemProperty.cpp \
	 FunctionTranslate.cpp FunctionUnparsedEntityURI.cpp \
	 GeneralAttributeCheck.cpp GenerateEvent.cpp Grammar.cpp \
	 GrammarResolver.cpp HashPtr.cpp HashXMLCh.cpp HeaderDummy.cpp HexBin.cpp \
	 HexBinaryDatatypeValidator.cpp ICUResHandler.cpp IC_Field.cpp IC_Key.cpp \
	 IC_KeyRef.cpp IC_Selector.cpp IC_Unique.cpp IDDatatypeValidator.cpp \
	 IDREFDatatypeValidator.cpp IGXMLScanner.cpp IGXMLScanner2.cpp \
	 IconvTransService.cpp IdentityConstraint.cpp \
	 IdentityConstraintHandler.cpp InMemHandler.cpp InMemMsgLoader.cpp \
	 InputSource.cpp KVStringPair.cpp KeyTable.cpp ListDatatypeValidator.cpp \
	 LocalFileFormatTarget.cpp LocalFileInputSource.cpp Match.cpp \
	 MemBufFormatTarget.cpp MemBufInputSource.cpp MemoryManagerArrayImpl.cpp \
	 MemoryManagerImpl.cpp MixedContentModel.cpp ModifierToken.cpp \
	 MonthDatatypeValidator.cpp MonthDayDatatypeValidator.cpp \
	 MsgFileOutputStream.cpp MutableNodeRefList.cpp Mutexes.cpp \
	 NCNameDatatypeValidator.cpp NLSHandler.cpp NOTATIONDatatypeValidator.cpp \
	 NameDatatypeValidator.cpp NamedNodeMapAttributeList.cpp \
	 NamedNodeMapImpl.cpp NamespaceScope.cpp NamespacesHandler.cpp \
	 NodeIDMap.cpp NodeImpl.cpp NodeIteratorImpl.cpp NodeListImpl.cpp \
	 NodeNameTreeWalker.cpp NodeRefList.cpp NodeRefListBase.cpp \
	 NodeSortKey.cpp NodeSorter.cpp NodeVector.cpp NotationImpl.cpp \
	 NullPrintWriter.cpp Op.cpp OpFactory.cpp OutputContextStack.cpp \
	 PSVIAttribute.cpp PSVIAttributeList.cpp PSVIElement.cpp PSVIItem.cpp \
	 PanicHandler.cpp ParenToken.cpp ParentNode.cpp ParserForXMLSchema.cpp \
	 PlatformSupportInit.cpp PlatformUtils.cpp PrefixResolver.cpp \
	 PrintWriter.cpp ProblemListener.cpp ProblemListenerDefault.cpp \
	 ProcessingInstructionImpl.cpp QName.cpp QNameDatatypeValidator.cpp \
	 RangeFactory.cpp RangeImpl.cpp RangeToken.cpp RangeTokenMap.cpp \
	 ReaderMgr.cpp RefCountedImpl.cpp RegularExpression.cpp RegxParser.cpp \
	 RegxUtil.cpp Resettable.cpp ResultNamespacesStack.cpp SAX2Handler.cpp \
	 SAX2XMLFilterImpl.cpp SAX2XMLReaderImpl.cpp SAXException.cpp \
	 SAXParseException.cpp SAXParser.cpp SGXMLScanner.cpp SchemaAttDef.cpp \
	 SchemaAttDefList.cpp SchemaElementDecl.cpp SchemaGrammar.cpp \
	 SchemaInfo.cpp SchemaSymbols.cpp SchemaValidator.cpp SelectionEvent.cpp \
	 SimpleContentModel.cpp StdBinInputStream.cpp StdInInputSource.cpp \
	 StdOutFormatTarget.cpp StringDatatypeValidator.cpp StringPool.cpp \
	 StringToken.cpp StringTokenizer.cpp Stylesheet.cpp \
	 StylesheetConstructionContext.cpp \
	 StylesheetConstructionContextDefault.cpp StylesheetExecutionContext.cpp \
	 StylesheetExecutionContextDefault.cpp StylesheetHandler.cpp \
	 StylesheetRoot.cpp SubstitutionGroupComparator.cpp \
	 SynchronizedStringPool.cpp TextImpl.cpp TimeDatatypeValidator.cpp \
	 Token.cpp TokenFactory.cpp TopLevelArg.cpp TraceListener.cpp \
	 TraceListenerDefault.cpp TracerEvent.cpp TransService.cpp \
	 TraverseSchema.cpp TreeWalker.cpp TreeWalkerImpl.cpp URISupport.cpp \
	 URLInputSource.cpp UnicodeRangeFactory.cpp UnionDatatypeValidator.cpp \
	 UnionToken.cpp ValidationContextImpl.cpp ValueStore.cpp \
	 ValueStoreCache.cpp VariablesStack.cpp VecAttrListImpl.cpp \
	 VecAttributesImpl.cpp WFXMLScanner.cpp Wrapper4DOMInputSource.cpp \
	 Wrapper4InputSource.cpp Writer.cpp XBoolean.cpp \
	 XML256TableTranscoder.cpp XML256TableTranscoder390.cpp \
	 XML88591Transcoder.cpp XML88591Transcoder390.cpp XMLASCIITranscoder.cpp \
	 XMLASCIITranscoder390.cpp XMLAbstractDoubleFloat.cpp XMLAttDef.cpp \
	 XMLAttDefList.cpp XMLAttr.cpp XMLBigDecimal.cpp XMLBigInteger.cpp \
	 XMLBuffer.cpp XMLBufferMgr.cpp XMLCanRepGroup.cpp XMLChTranscoder.cpp \
	 XMLChar.cpp XMLContentModel.cpp XMLDTDDescription.cpp \
	 XMLDTDDescriptionImpl.cpp XMLDateTime.cpp XMLDeclImpl.cpp XMLDouble.cpp \
	 XMLEBCDICTranscoder.cpp XMLEBCDICTranscoder390.cpp XMLElementDecl.cpp \
	 XMLEntityDecl.cpp XMLException.cpp XMLFloat.cpp XMLFormatter.cpp \
	 XMLGrammarDescription.cpp XMLGrammarPoolImpl.cpp \
	 XMLIBM1047Transcoder.cpp XMLIBM1047Transcoder390.cpp \
	 XMLIBM1140Transcoder.cpp XMLIBM1140Transcoder390.cpp XMLInitializer.cpp \
	 XMLMsgLoader.cpp XMLNotationDecl.cpp XMLNumber.cpp XMLParserLiaison.cpp \
	 XMLRangeFactory.cpp XMLReader.cpp XMLRecognizer.cpp XMLRefInfo.cpp \
	 XMLRegisterCleanup.cpp XMLScanner.cpp XMLScannerResolver.cpp \
	 XMLSchemaDescription.cpp XMLSchemaDescriptionImpl.cpp XMLString.cpp \
	 XMLStringTokenizer.cpp XMLSupportException.cpp XMLSupportInit.cpp \
	 XMLUCSTranscoder.cpp XMLURL.cpp XMLUTF16Transcoder.cpp \
	 XMLUTF8Transcoder.cpp XMLUTF8Transcoder390.cpp XMLUni.cpp \
	 XMLUniCharacter.cpp XMLUri.cpp XMLValidator.cpp XMLWin1252Transcoder.cpp \
	 XMLWin1252Transcoder390.cpp XMemory.cpp XNodeSet.cpp \
	 XNodeSetAllocator.cpp XNodeSetBase.cpp XNodeSetNodeProxy.cpp \
	 XNodeSetNodeProxyAllocator.cpp XNodeSetResultTreeFragProxy.cpp XNull.cpp \
	 XNumber.cpp XNumberAllocator.cpp XNumberBase.cpp XObject.cpp \
	 XObjectFactory.cpp XObjectFactoryDefault.cpp \
	 XObjectResultTreeFragProxy.cpp XObjectResultTreeFragProxyBase.cpp \
	 XObjectResultTreeFragProxyText.cpp XObjectTypeCallback.cpp XPath.cpp \
	 XPathAllocator.cpp XPathCAPI.cpp XPathConstructionContext.cpp \
	 XPathConstructionContextDefault.cpp XPathEnvSupport.cpp \
	 XPathEnvSupportDefault.cpp XPathEvaluator.cpp XPathExecutionContext.cpp \
	 XPathExecutionContextDefault.cpp XPathExpression.cpp XPathFactory.cpp \
	 XPathFactoryBlock.cpp XPathFactoryDefault.cpp XPathFunctionTable.cpp \
	 XPathInit.cpp XPathMatcher.cpp XPathMatcherStack.cpp \
	 XPathParserException.cpp XPathProcessor.cpp XPathProcessorImpl.cpp \
	 XPathSymbols.cpp XProtoType.cpp XResultTreeFrag.cpp \
	 XResultTreeFragAllocator.cpp XSAXMLScanner.cpp XSAnnotation.cpp \
	 XSAttributeDeclaration.cpp XSAttributeGroupDefinition.cpp \
	 XSAttributeUse.cpp XSComplexTypeDefinition.cpp XSDDOMParser.cpp \
	 XSDElementNSImpl.cpp XSDErrorReporter.cpp XSDLocator.cpp \
	 XSElementDeclaration.cpp XSFacet.cpp XSIDCDefinition.cpp \
	 XSLException.cpp XSLTEngineImpl.cpp XSLTInit.cpp XSLTInputSource.cpp \
	 XSLTProcessor.cpp XSLTProcessorEnvSupport.cpp \
	 XSLTProcessorEnvSupportDefault.cpp XSLTProcessorException.cpp \
	 XSLTResultTarget.cpp XSModel.cpp XSModelGroup.cpp \
	 XSModelGroupDefinition.cpp XSMultiValueFacet.cpp XSNamespaceItem.cpp \
	 XSNotationDeclaration.cpp XSObject.cpp XSObjectFactory.cpp \
	 XSParticle.cpp XSSimpleTypeDefinition.cpp XSTypeDefinition.cpp \
	 XSValue.cpp XSWildcard.cpp XSerializeEngine.cpp XSpan.cpp XString.cpp \
	 XStringAdapter.cpp XStringAdapterAllocator.cpp XStringAllocator.cpp \
	 XStringBase.cpp XStringCached.cpp XStringCachedAllocator.cpp \
	 XStringReference.cpp XStringReferenceAllocator.cpp \
	 XTemplateSerializer.cpp XToken.cpp XTokenNumberAdapter.cpp \
	 XTokenNumberAdapterAllocator.cpp XTokenStringAdapter.cpp \
	 XTokenStringAdapterAllocator.cpp XUnknown.cpp XUtil.cpp \
	 XalanAVTAllocator.cpp XalanAVTPartSimpleAllocator.cpp \
	 XalanAVTPartXPathAllocator.cpp XalanAttr.cpp XalanBitmap.cpp \
	 XalanCAPI.cpp XalanCDataSection.cpp XalanCharacterData.cpp \
	 XalanComment.cpp XalanCompiledStylesheetDefault.cpp \
	 XalanDOMException.cpp XalanDOMImplementation.cpp XalanDOMInit.cpp \
	 XalanDOMString.cpp XalanDOMStringAllocator.cpp XalanDOMStringCache.cpp \
	 XalanDOMStringHashTable.cpp XalanDOMStringPool.cpp \
	 XalanDOMStringReusableAllocator.cpp XalanDecimalFormatSymbols.cpp \
	 XalanDefaultDocumentBuilder.cpp XalanDefaultParsedSource.cpp \
	 XalanDiagnosticMemoryManager.cpp XalanDocument.cpp \
	 XalanDocumentFragment.cpp XalanDocumentFragmentNodeRefListBaseProxy.cpp \
	 XalanDocumentPrefixResolver.cpp XalanDocumentType.cpp \
	 XalanEXSLTCommon.cpp XalanEXSLTDateTime.cpp XalanEXSLTDynamic.cpp \
	 XalanEXSLTMath.cpp XalanEXSLTSet.cpp XalanEXSLTString.cpp \
	 XalanElemApplyTemplatesAllocator.cpp XalanElemAttributeAllocator.cpp \
	 XalanElemAttributeSetAllocator.cpp XalanElemCallTemplateAllocator.cpp \
	 XalanElemElementAllocator.cpp XalanElemEmptyAllocator.cpp \
	 XalanElemLiteralResultAllocator.cpp XalanElemTemplateAllocator.cpp \
	 XalanElemTextAllocator.cpp XalanElemTextLiteralAllocator.cpp \
	 XalanElemValueOfAllocator.cpp XalanElemVariableAllocator.cpp \
	 XalanElement.cpp XalanEmptyNamedNodeMap.cpp \
	 XalanEncodingPropertyCache.cpp XalanEntity.cpp XalanEntityReference.cpp \
	 XalanExe.cpp XalanExtensions.cpp XalanFStreamOutputStream.cpp \
	 XalanFileOutputStream.cpp XalanFileUtility.cpp \
	 XalanHTMLElementsProperties.cpp XalanICUMessageLoader.cpp \
	 XalanInMemoryMessageLoader.cpp XalanMatchPatternData.cpp \
	 XalanMatchPatternDataAllocator.cpp XalanMemoryManagement.cpp \
	 XalanMemoryManagerDefault.cpp XalanMessageLoader.cpp XalanMsgLib.cpp \
	 XalanNLSMessageLoader.cpp XalanNamedNodeMap.cpp XalanNamespacesStack.cpp \
	 XalanNode.cpp XalanNodeList.cpp XalanNodeListDummy.cpp \
	 XalanNodeListSurrogate.cpp XalanNotation.cpp XalanNullOutputStream.cpp \
	 XalanNumberFormat.cpp XalanNumberingResourceBundle.cpp \
	 XalanOutputStream.cpp XalanOutputStreamPrintWriter.cpp \
	 XalanParsedSource.cpp XalanParsedURI.cpp XalanProcessingInstruction.cpp \
	 XalanQName.cpp XalanQNameByReference.cpp XalanQNameByValue.cpp \
	 XalanQNameByValueAllocator.cpp XalanReferenceCountedObject.cpp \
	 XalanSimplePrefixResolver.cpp XalanSourceTreeAttr.cpp \
	 XalanSourceTreeAttrNS.cpp XalanSourceTreeAttributeAllocator.cpp \
	 XalanSourceTreeAttributeNSAllocator.cpp XalanSourceTreeComment.cpp \
	 XalanSourceTreeCommentAllocator.cpp XalanSourceTreeContentHandler.cpp \
	 XalanSourceTreeDOMSupport.cpp XalanSourceTreeDocument.cpp \
	 XalanSourceTreeDocumentAllocator.cpp XalanSourceTreeDocumentFragment.cpp \
	 XalanSourceTreeDocumentFragmentAllocator.cpp XalanSourceTreeElement.cpp \
	 XalanSourceTreeElementA.cpp XalanSourceTreeElementAAllocator.cpp \
	 XalanSourceTreeElementANS.cpp XalanSourceTreeElementANSAllocator.cpp \
	 XalanSourceTreeElementNA.cpp XalanSourceTreeElementNAAllocator.cpp \
	 XalanSourceTreeElementNANS.cpp XalanSourceTreeElementNANSAllocator.cpp \
	 XalanSourceTreeHelper.cpp XalanSourceTreeInit.cpp \
	 XalanSourceTreeParserLiaison.cpp \
	 XalanSourceTreeProcessingInstruction.cpp \
	 XalanSourceTreeProcessingInstructionAllocator.cpp \
	 XalanSourceTreeText.cpp XalanSourceTreeTextAllocator.cpp \
	 XalanSourceTreeTextIWS.cpp XalanSourceTreeTextIWSAllocator.cpp \
	 XalanSourceTreeWrapperParsedSource.cpp XalanSpaceNodeTester.cpp \
	 XalanStdOutputStream.cpp XalanText.cpp \
	 XalanToXercesTranscoderWrapper.cpp XalanTranscodingServices.cpp \
	 XalanTransformer.cpp XalanTransformerOutputStream.cpp \
	 XalanTransformerProblemListener.cpp XalanUTF16Transcoder.cpp \
	 XalanUTF16Writer.cpp XalanUTF8Writer.cpp XalanXMLChar.cpp \
	 XalanXMLFileReporter.cpp XalanXMLSerializerBase.cpp \
	 XalanXMLSerializerFactory.cpp XalanXPathException.cpp \
	 XercesAttGroupInfo.cpp XercesAttrBridge.cpp XercesAttrWrapper.cpp \
	 XercesAttrWrapperAllocator.cpp XercesAttributeBridgeAllocator.cpp \
	 XercesBridgeHelper.cpp XercesBridgeNavigator.cpp \
	 XercesCDATASectionBridge.cpp XercesCDATASectionWrapper.cpp \
	 XercesCommentBridge.cpp XercesCommentWrapper.cpp XercesDOMException.cpp \
	 XercesDOMFormatterWalker.cpp XercesDOMImplementationBridge.cpp \
	 XercesDOMImplementationWrapper.cpp XercesDOMParsedSource.cpp \
	 XercesDOMParser.cpp XercesDOMSupport.cpp XercesDOMWalker.cpp \
	 XercesDOMWrapperException.cpp XercesDOMWrapperParsedSource.cpp \
	 XercesDOM_NodeHack.cpp XercesDocumentBridge.cpp \
	 XercesDocumentFragmentBridge.cpp XercesDocumentTypeBridge.cpp \
	 XercesDocumentTypeWrapper.cpp XercesDocumentWrapper.cpp \
	 XercesElementBridge.cpp XercesElementBridgeAllocator.cpp \
	 XercesElementWildcard.cpp XercesElementWrapper.cpp \
	 XercesElementWrapperAllocator.cpp XercesEntityBridge.cpp \
	 XercesEntityReferenceBridge.cpp XercesEntityReferenceWrapper.cpp \
	 XercesEntityWrapper.cpp XercesGroupInfo.cpp \
	 XercesLiaisonXalanDOMStringPool.cpp XercesNamedNodeMapAttributeList.cpp \
	 XercesNamedNodeMapBridge.cpp XercesNamedNodeMapWrapper.cpp \
	 XercesNodeListBridge.cpp XercesNodeListWrapper.cpp \
	 XercesNotationBridge.cpp XercesNotationWrapper.cpp \
	 XercesParserLiaison.cpp XercesProcessingInstructionBridge.cpp \
	 XercesProcessingInstructionWrapper.cpp XercesTextBridge.cpp \
	 XercesTextBridgeAllocator.cpp XercesTextWrapper.cpp \
	 XercesTextWrapperAllocator.cpp XercesToXalanNodeMap.cpp \
	 XercesTreeWalker.cpp XercesWrapperHelper.cpp XercesWrapperNavigator.cpp \
	 XercesWrapperNavigatorAllocator.cpp XercesWrapperToXalanNodeMap.cpp \
	 XercesXPath.cpp YearDatatypeValidator.cpp YearMonthDatatypeValidator.cpp
EXEBASE=xalancbmk_s
NEED_MATH=
BENCHLANG=CXX

BENCH_CXXFLAGS   = -DAPP_NO_THREADS -DXALAN_INMEM_MSG_LOADER -I. -Ixercesc -Ixercesc/dom -Ixercesc/dom/impl -Ixercesc/sax -Ixercesc/util/MsgLoaders/InMemory -Ixercesc/util/Transcoders/Iconv -Ixalanc/include -DPROJ_XMLPARSER -DPROJ_XMLUTIL -DPROJ_PARSERS -DPROJ_SAX4C -DPROJ_SAX2 -DPROJ_DOM -DPROJ_VALIDATORS -DXML_USE_INMEM_MESSAGELOADER
CC               = $(SPECLANG)gcc-8     -std=c99   -m64
CC_VERSION_OPTION = -v
CXX              = $(SPECLANG)g++-8     -std=c++03 -m64
CXX_VERSION_OPTION = -v
EXTRA_OPTIMIZE   = -fopenmp -DSPEC_OPENMP
EXTRA_PORTABILITY = -DSPEC_LP64
FC               = $(SPECLANG)gfortran-8           -m64
FC_VERSION_OPTION = -v
OPTIMIZE         = -O3 -march=native -fno-unsafe-math-optimizations  -fno-tree-loop-vectorize
OS               = unix
PORTABILITY      = -DSPEC_LINUX
SPECLANG         = /volatile/zephyr/wayedt/linuxbrew_updated/opt/gcc@8/bin/
absolutely_no_locking = 0
abstol           = 
action           = validate
allow_label_override = 0
backup_config    = 1
baseexe          = xalancbmk_s
basepeak         = 0
benchdir         = benchspec
benchmark        = 623.xalancbmk_s
binary           = 
bindir           = exe
builddir         = build
bundleaction     = 
bundlename       = 
calctol          = 0
changedhash      = 0
check_version    = 0
clean_between_builds = no
command_add_redirect = 1
commanderrfile   = speccmds.err
commandexe       = xalancbmk_s_peak.collect-build-flags-m64
commandfile      = speccmds.cmd
commandoutfile   = speccmds.out
commandstdoutfile = speccmds.stdout
comparedir       = compare
compareerrfile   = compare.err
comparefile      = compare.cmd
compareoutfile   = compare.out
comparestdoutfile = compare.stdout
compile_error    = 0
compwhite        = 
configdir        = config
configfile       = collect-build-flags.cfg
configpath       = /scratch/wayedt/spec2017_root/config/collect-build-flags.cfg
copies           = 1
current_range    = 
datadir          = data
default_size     = ref
default_submit   = $command
delay            = 0
deletebinaries   = 0
deletework       = 0
dependent_workloads = 0
device           = 
difflines        = 10
dirprot          = 511
discard_power_samples = 0
enable_monitor   = 1
endian           = 12345678
env_vars         = 0
expand_notes     = 0
expid            = 
exthash_bits     = 256
failflags        = 0
fake             = 0
feedback         = 1
flag_url_base    = https://www.spec.org/auto/cpu2017/Docs/benchmarks/flags/
floatcompare     = 
force_monitor    = 0
from_runcpu      = 2
fw_bios          = 
hostname         = n235.local
http_proxy       = 
http_timeout     = 30
hw_avail         = 
hw_cpu_max_mhz   = 
hw_cpu_name      = could not determine
hw_cpu_nominal_mhz = 
hw_disk          = 50 TB  add more disk info here
hw_memory        = 'N GB (N x N GB nRxn PC4-nnnnX-X)'
hw_memory001     = format is 'n GB (n x n GB nRxn PCn-nnnnnR-n, ECC)' part 001
hw_memory002     = format is 'n GB (n x n GB nRxn PCn-nnnnnR-n, ECC)' part 002
hw_model         = 
hw_nchips        = could not determine
hw_ncores        = 
hw_ncpuorder     = 
hw_nthreadspercore = 
hw_ocache        = 
hw_other         = 
hw_pcache        = 
hw_scache        = 
hw_tcache        = 
hw_vendor        = My Corporation
idle_current_range = 
idledelay        = 10
idleduration     = 60
ignore_errors    = 1
ignore_sigint    = 0
ignorecase       = 
info_wrap_columns = 50
inputdir         = input
inputgenerrfile  = inputgen.err
inputgenfile     = inputgen.cmd
inputgenoutfile  = inputgen.out
inputgenstdoutfile = inputgen.stdout
iteration        = -1
iterations       = 1
keeptmp          = 0
label            = collect-build-flags-m64
license_num      = nnn (Your SPEC license number)
line_width       = 1020
link_input_files = 1
locking          = 1
log              = CPU2017
log_line_width   = 1020
log_timestamp    = 0
logfile          = /scratch/wayedt/spec2017_root/tmp/CPU2017.007/templogs/preenv.intspeed.007.1
logname          = /scratch/wayedt/spec2017_root/tmp/CPU2017.007/templogs/preenv.intspeed.007.1
lognum           = 007.1
mail_reports     = all
mailcompress     = 0
mailmethod       = smtp
mailport         = 25
mailserver       = 127.0.0.1
mailto           = 
make             = specmake
make_no_clobber  = 0
makefile_template = Makefile.YYYtArGeTYYYspec
makeflags        = --jobs=8
max_average_uncertainty = 1
max_hum_limit    = 0
max_report_runs  = 3
max_unknown_uncertainty = 1
mean_anyway      = 1
meter_connect_timeout = 30
meter_errors_default = 5
meter_errors_percentage = 5
min_report_runs  = 2
min_temp_limit   = 20
minimize_builddirs = 0
minimize_rundirs = 0
name             = xalancbmk_s
nansupport       = 
need_math        = 
no_input_handler = close
no_monitor       = 
noratios         = 0
note_preenv      = 1
notes_plat_sysinfo_000 =  Sysinfo program /scratch/wayedt/spec2017_root/bin/sysinfo
notes_plat_sysinfo_005 =  Rev: r5974 of 2018-05-19 9bcde8f2999c33d61f64985e45859ea9
notes_plat_sysinfo_010 =  running on n235.local Wed Jun 23 20:55:45 2021
notes_plat_sysinfo_015 = 
notes_plat_sysinfo_020 =  SUT (System Under Test) info as seen by some common utilities.
notes_plat_sysinfo_025 =  For more information on this section, see
notes_plat_sysinfo_030 =     https://www.spec.org/cpu2017/Docs/config.html\#sysinfo
notes_plat_sysinfo_035 = 
notes_plat_sysinfo_040 =  From /proc/cpuinfo
notes_plat_sysinfo_045 =  *
notes_plat_sysinfo_050 =  * Did not identify cpu model.  If you would
notes_plat_sysinfo_055 =  * like to write your own sysinfo program, see
notes_plat_sysinfo_060 =  * www.spec.org/cpu2017/config.html\#sysinfo
notes_plat_sysinfo_065 =  *
notes_plat_sysinfo_070 =  *
notes_plat_sysinfo_075 =  * 0 "physical id" tags found.  Perhaps this is an older system,
notes_plat_sysinfo_080 =  * or a virtualized system.  Not attempting to guess how to
notes_plat_sysinfo_085 =  * count chips/cores for this system.
notes_plat_sysinfo_090 =  *
notes_plat_sysinfo_095 =         "processors"
notes_plat_sysinfo_100 =     cores, siblings (Caution: counting these is hw and system dependent. The following
notes_plat_sysinfo_105 =     excerpts from /proc/cpuinfo might not be reliable.  Use with caution.)
notes_plat_sysinfo_110 = 
notes_plat_sysinfo_115 =  From lscpu:
notes_plat_sysinfo_120 =       Architecture:        x86_64
notes_plat_sysinfo_125 =       CPU op-mode(s):      32-bit, 64-bit
notes_plat_sysinfo_130 =       Byte Order:          Little Endian
notes_plat_sysinfo_135 =       CPU(s):              16
notes_plat_sysinfo_140 =       On-line CPU(s) list: 0-15
notes_plat_sysinfo_145 =       Thread(s) per core:  1
notes_plat_sysinfo_150 =       Core(s) per socket:  8
notes_plat_sysinfo_155 =       Socket(s):           2
notes_plat_sysinfo_160 =       NUMA node(s):        2
notes_plat_sysinfo_165 =       Vendor ID:           GenuineIntel
notes_plat_sysinfo_170 =       CPU family:          6
notes_plat_sysinfo_175 =       Model:               45
notes_plat_sysinfo_180 =       Model name:          Intel(R) Xeon(R) CPU E5-2660 0 @ 2.20GHz
notes_plat_sysinfo_185 =       Stepping:            7
notes_plat_sysinfo_190 =       CPU MHz:             2699.914
notes_plat_sysinfo_195 =       CPU max MHz:         3000.0000
notes_plat_sysinfo_200 =       CPU min MHz:         1200.0000
notes_plat_sysinfo_205 =       BogoMIPS:            4399.66
notes_plat_sysinfo_210 =       Virtualization:      VT-x
notes_plat_sysinfo_215 =       L1d cache:           32K
notes_plat_sysinfo_220 =       L1i cache:           32K
notes_plat_sysinfo_225 =       L2 cache:            256K
notes_plat_sysinfo_230 =       L3 cache:            20480K
notes_plat_sysinfo_235 =       NUMA node0 CPU(s):   0,2,4,6,8,10,12,14
notes_plat_sysinfo_240 =       NUMA node1 CPU(s):   1,3,5,7,9,11,13,15
notes_plat_sysinfo_245 =       Flags:               fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov
notes_plat_sysinfo_250 =       pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp
notes_plat_sysinfo_255 =       lm constant_tsc arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf
notes_plat_sysinfo_260 =       eagerfpu pni pclmulqdq dtes64 ds_cpl vmx smx est tm2 ssse3 cx16 xtpr pdcm pcid dca
notes_plat_sysinfo_265 =       sse4_1 sse4_2 x2apic popcnt tsc_deadline_timer aes xsave avx lahf_lm tpr_shadow vnmi
notes_plat_sysinfo_270 =       flexpriority ept vpid xsaveopt dtherm ida arat pln pts
notes_plat_sysinfo_275 =     WARNING: the 'lscpu' utility claims that 2 "Socket(s)" were seen, which does not match
notes_plat_sysinfo_280 =     the could not determine "physyical id"s seen in /proc/cpuinfo.  The tester should
notes_plat_sysinfo_285 =     verify the count independently.
notes_plat_sysinfo_290 = 
notes_plat_sysinfo_295 =  From numactl --hardware  WARNING: a numactl 'node' might or might not correspond to a
notes_plat_sysinfo_300 =  physical chip.
notes_plat_sysinfo_305 = 
notes_plat_sysinfo_310 =  From /proc/meminfo
notes_plat_sysinfo_315 =  Did not find total memory in /proc/meminfo
notes_plat_sysinfo_320 = 
notes_plat_sysinfo_325 =  /usr/bin/lsb_release -d
notes_plat_sysinfo_330 =     CentOS Linux release 7.2.1511 (Core)
notes_plat_sysinfo_335 = 
notes_plat_sysinfo_340 =  From /etc/*release* /etc/*version*
notes_plat_sysinfo_345 =     centos-release: CentOS Linux release 7.2.1511 (Core)
notes_plat_sysinfo_350 =     centos-release-upstream: Derived from Red Hat Enterprise Linux 7.2 (Source)
notes_plat_sysinfo_355 =     os-release:
notes_plat_sysinfo_360 =        NAME="CentOS Linux"
notes_plat_sysinfo_365 =        VERSION="7 (Core)"
notes_plat_sysinfo_370 =        ID="centos"
notes_plat_sysinfo_375 =        ID_LIKE="rhel fedora"
notes_plat_sysinfo_380 =        VERSION_ID="7"
notes_plat_sysinfo_385 =        PRETTY_NAME="CentOS Linux 7 (Core)"
notes_plat_sysinfo_390 =        ANSI_COLOR="0;31"
notes_plat_sysinfo_395 =        CPE_NAME="cpe:/o:centos:centos:7"
notes_plat_sysinfo_400 =     redhat-release: CentOS Linux release 7.2.1511 (Core)
notes_plat_sysinfo_405 =     system-release: CentOS Linux release 7.2.1511 (Core)
notes_plat_sysinfo_410 =     system-release-cpe: cpe:/o:centos:centos:7
notes_plat_sysinfo_415 = 
notes_plat_sysinfo_420 =  uname -a:
notes_plat_sysinfo_425 =     Linux n235.local 3.10.0-862.14.4.el7.x86_64 \#1 SMP Wed Sep 26 15:12:11 UTC 2018 x86_64
notes_plat_sysinfo_430 =     GNU/Linux
notes_plat_sysinfo_435 = 
notes_plat_sysinfo_440 =  Kernel self-reported vulnerability status:
notes_plat_sysinfo_445 = 
notes_plat_sysinfo_450 =  CVE-2017-5754 (Meltdown):          No status reported
notes_plat_sysinfo_455 =  CVE-2017-5753 (Spectre variant 1): No status reported
notes_plat_sysinfo_460 =  CVE-2017-5715 (Spectre variant 2): No status reported
notes_plat_sysinfo_465 = 
notes_plat_sysinfo_470 =  run-level 3 2021-06-22 12:56
notes_plat_sysinfo_475 = 
notes_plat_sysinfo_480 =  SPEC is set to: /scratch/wayedt/spec2017_root
notes_plat_sysinfo_485 =     Filesystem               Type   Size  Used Avail Use% Mounted on
notes_plat_sysinfo_490 =     panfs://pfs.local:global panfs   50T   17T   34T  33% /panfs
notes_plat_sysinfo_495 = 
notes_plat_sysinfo_500 =  Cannot run dmidecode; consider saying 'chmod +s /usr/sbin/dmidecode'
notes_plat_sysinfo_505 = 
notes_plat_sysinfo_510 =  (End of data from sysinfo program)
notes_wrap_columns = 0
notes_wrap_indent =   
num              = 623
obiwan           = 
oldhash          = 
os_exe_ext       = 
output_format    = txt,html,cfg,pdf,csv
output_root      = 
outputdir        = output
parallel_test    = 0
parallel_test_submit = 0
parallel_test_workloads = 
path             = /scratch/wayedt/spec2017_root/benchspec/CPU/623.xalancbmk_s
plain_train      = 1
platform         = 
power            = 0
preENV_LD_LIBRARY_PATH = %{gcc_dir}/lib64/:%{gcc_dir}/lib/:/lib64
preenv           = 0
prefix           = 
prepared_by      = wayedt  (is never output, only tags rawfile)
ranks            = 1
rawhash_bits     = 256
rebuild          = 0
reftime          = reftime
reltol           = 
reportable       = 0
resultdir        = result
review           = 0
run              = all
runcpu           = /scratch/wayedt/spec2017_root/bin/harness/runcpu --configfile collect-build-flags.cfg --action run --noreportable --nopower --runmode speed --tune peak --size refspeed intspeed --nopreenv --note-preenv --logfile /scratch/wayedt/spec2017_root/tmp/CPU2017.007/templogs/preenv.intspeed.007.1 --lognum 007.1 --from_runcpu 2
rundir           = run
runmode          = speed
safe_eval        = 1
save_build_files = 
section_specifier_fatal = 1
setprocgroup     = 1
setup_error      = 0
sigint           = 2
size             = refspeed
size_class       = ref
skipabstol       = 
skipobiwan       = 
skipreltol       = 
skiptol          = 
smarttune        = peak
specdiff         = specdiff
specrun          = specinvoke
srcalt           = 
srcdir           = src
srcsource        = /scratch/wayedt/spec2017_root/benchspec/CPU/523.xalancbmk_r/src
stagger          = 10
strict_rundir_verify = 1
sw_avail         = 
sw_base_ptrsize  = 64-bit
sw_compiler001   = C/C++/Fortran: Version 7.2.1 of GCC, the
sw_compiler002   = GNU Compiler Collection
sw_file          = panfs
sw_os001         = CentOS Linux release 7.2.1511 (Core)
sw_os002         = 3.10.0-862.14.4.el7.x86_64
sw_other         = 
sw_peak_ptrsize  = 64-bit
sw_state         = Run level 3 (add definition here)
sysinfo_hash_bits = 256
sysinfo_program  = specperl /scratch/wayedt/spec2017_root/bin/sysinfo
sysinfo_program_hash = sysinfo:SHA:32259ebd59f3e93740723202f27c44c82ee68e0f2e40cd2ca50cfd5519772397
table            = 1
teeout           = 0
test_date        = Jun-2021
test_sponsor     = My Corporation
tester           = My Corporation
threads          = 4
top              = /scratch/wayedt/spec2017_root
train_single_thread = 0
train_with       = train
tune             = peak
uid              = 100358403
unbuffer         = 1
uncertainty_exception = 5
update           = 0
update_url       = http://www.spec.org/auto/cpu2017/updates/
use_submit_for_compare = 0
use_submit_for_speed = 0
username         = wayedt
verbose          = 5
verify_binaries  = 1
version          = 0.905000
version_url      = http://www.spec.org/auto/cpu2017/current_version
voltage_range    = 
worklist         = list
OUTPUT_RMFILES   = train-allbooks.out
