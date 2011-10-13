set(name OpenCOLLADASaxFrameworkLoader)
project(${name})

set(libSaxFrameworkLoader_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/generated14
	${CMAKE_CURRENT_SOURCE_DIR}/include/generated15
)

set(libSaxFrameworkLoader_include_dirs ${libSaxFrameworkLoader_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/COLLADASaxFWLLibraryArticulatedSystemsLoader.cpp
	src/COLLADASaxFWLCOLLADACsymbol.cpp
	src/COLLADASaxFWLLibraryAnimationsLoader.cpp
	src/COLLADASaxFWLIParserImpl14.cpp
	src/COLLADASaxFWLTransformationLoader.cpp
	src/COLLADASaxFWLInputUnshared.cpp
	src/COLLADASaxFWLIFilePartLoader.cpp
	src/COLLADASaxFWLFilePartLoader.cpp
	src/COLLADASaxFWLGeometryMaterialIdInfo.cpp
	src/COLLADASaxFWLLibraryControllersLoader.cpp
	src/COLLADASaxFWLSaxParserError.cpp
	src/COLLADASaxFWLSaxFWLError.cpp
	src/COLLADASaxFWLSourceArrayLoader.cpp
	src/COLLADASaxFWLLibraryKinematicsScenesLoader.cpp
	src/COLLADASaxFWLExtraDataLoader.cpp
	src/COLLADASaxFWLLoader.cpp
	src/COLLADASaxFWLLibraryLightsLoader.cpp
	src/COLLADASaxFWLLibraryImagesLoader.cpp
	src/COLLADASaxFWLIParserImpl15.cpp
	src/COLLADASaxFWLJointsLoader.cpp
	src/COLLADASaxFWLKinematicsIntermediateData.cpp
	src/COLLADASaxFWLTypes.cpp
	src/COLLADASaxFWLNodeLoader.cpp
	src/COLLADASaxFWLAssetLoader.cpp
	src/COLLADASaxFWLRootParser14.cpp
	src/COLLADASaxFWLKinematicsSceneCreator.cpp
	src/COLLADASaxFWLIExtraDataCallbackHandler.cpp
	src/COLLADASaxFWLMeshPrimitiveInputList.cpp
	src/COLLADASaxFWLPrecompiledHeaders.cpp
	src/COLLADASaxFWLInstanceKinematicsModelLoader.cpp
	src/COLLADASaxFWLSaxParserErrorHandler.cpp
	src/COLLADASaxFWLLibraryNodesLoader.cpp
	src/COLLADASaxFWLRootParser15.cpp
	src/COLLADASaxFWLLibraryCamerasLoader.cpp
	src/COLLADASaxFWLFormulasLinker.cpp
	src/COLLADASaxFWLLibraryKinematicsModelsLoader.cpp
	src/COLLADASaxFWLLibraryFormulasLoader.cpp
	src/COLLADASaxFWLPostProcessor.cpp
	src/COLLADASaxFWLDocumentProcessor.cpp
	src/COLLADASaxFWLSceneLoader.cpp
	src/COLLADASaxFWLInstanceArticulatedSystemLoader.cpp
	src/COLLADASaxFWLFormulasLoader.cpp
	src/COLLADASaxFWLLibraryMaterialsLoader.cpp
	src/COLLADASaxFWLFileLoader.cpp
	src/COLLADASaxFWLMeshLoader.cpp
	src/COLLADASaxFWLVersionParser.cpp
	src/COLLADASaxFWLIError.cpp
	src/COLLADASaxFWLIErrorHandler.cpp
	src/COLLADASaxFWLLibraryEffectsLoader.cpp
	src/COLLADASaxFWLLibraryJointsLoader.cpp
	src/COLLADASaxFWLSidTreeNode.cpp
	src/COLLADASaxFWLSidAddress.cpp
	src/COLLADASaxFWLVisualSceneLoader.cpp
	src/COLLADASaxFWLGeometryLoader.cpp
	src/COLLADASaxFWLExtraDataElementHandler.cpp

	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateNameMap.cpp
	src/generated14/COLLADASaxFWLLibraryNodesLoader14.cpp
	src/generated14/COLLADASaxFWLGeometryLoader14.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateFunctionMapFactory.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateValidation.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateEnums.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateFunctionMap.cpp
	src/generated14/COLLADASaxFWLLibraryMaterialsLoader14.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateFindElementHash.cpp
	src/generated14/COLLADASaxFWLLibraryAnimationsLoader14.cpp
	src/generated14/COLLADASaxFWLSceneLoader14.cpp
	src/generated14/COLLADASaxFWLAssetLoader14.cpp
	src/generated14/COLLADASaxFWLLibraryEffectsLoader14.cpp
	src/generated14/COLLADASaxFWLVisualSceneLoader14.cpp
	src/generated14/COLLADASaxFWLSourceArrayLoader14.cpp
	src/generated14/COLLADASaxFWLNodeLoader14.cpp
	src/generated14/COLLADASaxFWLLibraryControllersLoader14.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14Private.cpp
	src/generated14/COLLADASaxFWLLibraryCamerasLoader14.cpp
	src/generated14/COLLADASaxFWLMeshLoader14.cpp
	src/generated14/COLLADASaxFWLLibraryImagesLoader14.cpp
	src/generated14/COLLADASaxFWLLibraryLightsLoader14.cpp

	src/generated15/COLLADASaxFWLNodeLoader15.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateNameMap.cpp
	src/generated15/COLLADASaxFWLMeshLoader15.cpp
	src/generated15/COLLADASaxFWLSceneLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryArticulatedSystemsLoader15.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateFindElementHash.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateFunctionMapFactory.cpp
	src/generated15/COLLADASaxFWLLibraryAnimationsLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryJointsLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryNodesLoader15.cpp
	src/generated15/COLLADASaxFWLSourceArrayLoader15.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateValidation.cpp
	src/generated15/COLLADASaxFWLLibraryKinematicsModelsLoader15.cpp
	src/generated15/COLLADASaxFWLVisualSceneLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryImagesLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryFormulasLoader15.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15Private.cpp
	src/generated15/COLLADASaxFWLFormulasLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryKinematicsScenesLoader15.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateFunctionMap.cpp
	src/generated15/COLLADASaxFWLGeometryLoader15.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateEnums.cpp
	src/generated15/COLLADASaxFWLLibraryLightsLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryEffectsLoader15.cpp
	src/generated15/COLLADASaxFWLAssetLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryCamerasLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryMaterialsLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryControllersLoader15.cpp
)

set(libSaxFrameworkLoader_libs
	OpenCOLLADABaseUtils
	GeneratedSaxParser
	OpenCOLLADAFramework
	MathMLSolver
	${PCRE_LIBRARIES}
)

if (USE_LIBXML)
	list(APPEND libGeneratedSaxParser_include_dirs ${LIBXML2_INCLUDE_DIR})
	list(APPEND libGeneratedSaxParser_libs ${LIBXML2_LIBRARIES})
endif ()

if (USE_EXPAT)
	list(APPEND libGeneratedSaxParser_include_dirs ${LIBEXPAT_INCLUDE_DIR})
	list(APPEND libGeneratedSaxParser_libs ${LIBEXPAT_LIBRARIES})
endif ()

include_directories(
	${libSaxFrameworkLoader_include_dirs} 
	${libMathMLSolver_include_dirs} 
	${libBaseUtils_include_dirs} 
	${libFramework_include_dirs} 
	${libGeneratedSaxParser_include_dirs}
	${PCRE_INCLUDE_DIR}
)

opencollada_add_lib(${name} "${SRC}" "${libSaxFrameworkLoader_libs}")
