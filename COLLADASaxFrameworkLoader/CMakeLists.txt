set(name OpenCOLLADASaxFrameworkLoader)
project(${name})

set(libSaxFrameworkLoader_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/generated14
	${CMAKE_CURRENT_SOURCE_DIR}/include/generated15
)

set(libSaxFrameworkLoader_include_dirs ${libSaxFrameworkLoader_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(INST_SRC
	include/COLLADASaxFWLAccessor.h
	include/COLLADASaxFWLArrayElement.h
	include/COLLADASaxFWLAssetLoader.h
	include/COLLADASaxFWLCOLLADACsymbol.h
	include/COLLADASaxFWLDocumentProcessor.h
	include/COLLADASaxFWLException.h
	include/COLLADASaxFWLExtraDataElementHandler.h
	include/COLLADASaxFWLExtraDataLoader.h
	include/COLLADASaxFWLFileLoader.h
	include/COLLADASaxFWLFilePartLoader.h
	include/COLLADASaxFWLFormulasLinker.h
	include/COLLADASaxFWLFormulasLoader.h
	include/COLLADASaxFWLGeometryLoader.h
	include/COLLADASaxFWLGeometryMaterialIdInfo.h
	include/COLLADASaxFWLHelperLoaderBase.h
	include/COLLADASaxFWLIError.h
	include/COLLADASaxFWLIErrorHandler.h
	include/COLLADASaxFWLIExtraDataCallbackHandler.h
	include/COLLADASaxFWLIFilePartLoader.h
	include/COLLADASaxFWLIParserImpl.h
	include/COLLADASaxFWLIParserImpl14.h
	include/COLLADASaxFWLIParserImpl15.h
	include/COLLADASaxFWLInputShared.h
	include/COLLADASaxFWLInputUnshared.h
	include/COLLADASaxFWLInstanceArticulatedSystemLoader.h
	include/COLLADASaxFWLInstanceKinematicsModelLoader.h
	include/COLLADASaxFWLIntermediateTargetable.h
	include/COLLADASaxFWLInterpolationTypeSource.h
	include/COLLADASaxFWLJointsLoader.h
	include/COLLADASaxFWLKinematicsIntermediateData.h
	include/COLLADASaxFWLKinematicsSceneCreator.h
	include/COLLADASaxFWLLibraryAnimationClipsLoader.h
	include/COLLADASaxFWLLibraryAnimationsLoader.h
	include/COLLADASaxFWLLibraryArticulatedSystemsLoader.h
	include/COLLADASaxFWLLibraryCamerasLoader.h
	include/COLLADASaxFWLLibraryControllersLoader.h
	include/COLLADASaxFWLLibraryEffectsLoader.h
	include/COLLADASaxFWLLibraryFormulasLoader.h
	include/COLLADASaxFWLLibraryImagesLoader.h
	include/COLLADASaxFWLLibraryJointsLoader.h
	include/COLLADASaxFWLLibraryKinematicsModelsLoader.h
	include/COLLADASaxFWLLibraryKinematicsScenesLoader.h
	include/COLLADASaxFWLLibraryLightsLoader.h
	include/COLLADASaxFWLLibraryMaterialsLoader.h
	include/COLLADASaxFWLLibraryNodesLoader.h
	include/COLLADASaxFWLLoader.h
	include/COLLADASaxFWLMeshLoader.h
	include/COLLADASaxFWLMeshPrimitiveInputList.h
	include/COLLADASaxFWLNodeLoader.h
	include/COLLADASaxFWLPHElement.h
	include/COLLADASaxFWLPolygons.h
	include/COLLADASaxFWLPostProcessor.h
	include/COLLADASaxFWLPrerequisites.h
	include/COLLADASaxFWLPrimitiveBase.h
	include/COLLADASaxFWLRootParser14.h
	include/COLLADASaxFWLRootParser15.h
	include/COLLADASaxFWLSaxFWLError.h
	include/COLLADASaxFWLSaxParserError.h
	include/COLLADASaxFWLSaxParserErrorHandler.h
	include/COLLADASaxFWLSceneLoader.h
	include/COLLADASaxFWLSidAddress.h
	include/COLLADASaxFWLSidTreeNode.h
	include/COLLADASaxFWLSource.h
	include/COLLADASaxFWLSourceArrayLoader.h
	include/COLLADASaxFWLSplineLoader.h
	include/COLLADASaxFWLStableHeaders.h
	include/COLLADASaxFWLTechniqueCommon.h
	include/COLLADASaxFWLTransformationLoader.h
	include/COLLADASaxFWLTypes.h
	include/COLLADASaxFWLUtils.h
	include/COLLADASaxFWLVersionParser.h
	include/COLLADASaxFWLVertices.h
	include/COLLADASaxFWLVisualSceneLoader.h
	include/COLLADASaxFWLXmlTypes.h
)

set(INST_GEN14_SRC
	include/generated14/COLLADASaxFWLAssetLoader14.h
	include/generated14/COLLADASaxFWLColladaParserAutoGen14.h
	include/generated14/COLLADASaxFWLColladaParserAutoGen14Attributes.h
	include/generated14/COLLADASaxFWLColladaParserAutoGen14Enums.h
	include/generated14/COLLADASaxFWLColladaParserAutoGen14FunctionMapFactory.h
	include/generated14/COLLADASaxFWLColladaParserAutoGen14Private.h
	include/generated14/COLLADASaxFWLColladaParserAutoGen14ValidationData.h
	include/generated14/COLLADASaxFWLGeometryLoader14.h
	include/generated14/COLLADASaxFWLLibraryAnimationClipsLoader14.h
	include/generated14/COLLADASaxFWLLibraryAnimationsLoader14.h
	include/generated14/COLLADASaxFWLLibraryCamerasLoader14.h
	include/generated14/COLLADASaxFWLLibraryControllersLoader14.h
	include/generated14/COLLADASaxFWLLibraryEffectsLoader14.h
	include/generated14/COLLADASaxFWLLibraryImagesLoader14.h
	include/generated14/COLLADASaxFWLLibraryLightsLoader14.h
	include/generated14/COLLADASaxFWLLibraryMaterialsLoader14.h
	include/generated14/COLLADASaxFWLLibraryNodesLoader14.h
	include/generated14/COLLADASaxFWLMeshLoader14.h
	include/generated14/COLLADASaxFWLNodeLoader14.h
	include/generated14/COLLADASaxFWLSceneLoader14.h
	include/generated14/COLLADASaxFWLSourceArrayLoader14.h
	include/generated14/COLLADASaxFWLSplineLoader14.h
	include/generated14/COLLADASaxFWLVisualSceneLoader14.h
)

set(INST_GEN15_SRC
	include/generated15/COLLADASaxFWLAssetLoader15.h
	include/generated15/COLLADASaxFWLColladaParserAutoGen15.h
	include/generated15/COLLADASaxFWLColladaParserAutoGen15Attributes.h
	include/generated15/COLLADASaxFWLColladaParserAutoGen15Enums.h
	include/generated15/COLLADASaxFWLColladaParserAutoGen15FunctionMapFactory.h
	include/generated15/COLLADASaxFWLColladaParserAutoGen15Private.h
	include/generated15/COLLADASaxFWLColladaParserAutoGen15ValidationData.h
	include/generated15/COLLADASaxFWLFormulasLoader15.h
	include/generated15/COLLADASaxFWLGeometryLoader15.h
	include/generated15/COLLADASaxFWLLibraryAnimationClipsLoader15.h
	include/generated15/COLLADASaxFWLLibraryAnimationsLoader15.h
	include/generated15/COLLADASaxFWLLibraryArticulatedSystemsLoader15.h
	include/generated15/COLLADASaxFWLLibraryCamerasLoader15.h
	include/generated15/COLLADASaxFWLLibraryControllersLoader15.h
	include/generated15/COLLADASaxFWLLibraryEffectsLoader15.h
	include/generated15/COLLADASaxFWLLibraryFormulasLoader15.h
	include/generated15/COLLADASaxFWLLibraryImagesLoader15.h
	include/generated15/COLLADASaxFWLLibraryJointsLoader15.h
	include/generated15/COLLADASaxFWLLibraryKinematicsModelsLoader15.h
	include/generated15/COLLADASaxFWLLibraryKinematicsScenesLoader15.h
	include/generated15/COLLADASaxFWLLibraryLightsLoader15.h
	include/generated15/COLLADASaxFWLLibraryMaterialsLoader15.h
	include/generated15/COLLADASaxFWLLibraryNodesLoader15.h
	include/generated15/COLLADASaxFWLMeshLoader15.h
	include/generated15/COLLADASaxFWLNodeLoader15.h
	include/generated15/COLLADASaxFWLSceneLoader15.h
	include/generated15/COLLADASaxFWLSourceArrayLoader15.h
	include/generated15/COLLADASaxFWLVisualSceneLoader15.h
)

set(SRC
	src/COLLADASaxFWLLibraryArticulatedSystemsLoader.cpp
	src/COLLADASaxFWLCOLLADACsymbol.cpp
	src/COLLADASaxFWLLibraryAnimationClipsLoader.cpp
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
	src/COLLADASaxFWLSplineLoader.cpp

	src/generated14/COLLADASaxFWLSplineLoader14.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateNameMap.cpp
	src/generated14/COLLADASaxFWLLibraryNodesLoader14.cpp
	src/generated14/COLLADASaxFWLGeometryLoader14.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateFunctionMapFactory.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateValidation.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateEnums.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateFunctionMap.cpp
	src/generated14/COLLADASaxFWLLibraryMaterialsLoader14.cpp
	src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateFindElementHash.cpp
	src/generated14/COLLADASaxFWLLibraryAnimationClipsLoader14.cpp
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
	src/generated14/COLLADASaxFWLSplineLoader14.cpp

	src/generated15/COLLADASaxFWLNodeLoader15.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateNameMap.cpp
	src/generated15/COLLADASaxFWLMeshLoader15.cpp
	src/generated15/COLLADASaxFWLSceneLoader15.cpp
	src/generated15/COLLADASaxFWLLibraryArticulatedSystemsLoader15.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateFindElementHash.cpp
	src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateFunctionMapFactory.cpp
	src/generated15/COLLADASaxFWLLibraryAnimationClipsLoader15.cpp	
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

	${INST_SRC}
	${INST_GEN14_SRC}
	${INST_GEN15_SRC}
)

set(TARGET_LIBS
	OpenCOLLADABaseUtils
	GeneratedSaxParser
	OpenCOLLADAFramework
	MathMLSolver
	${PCRE_LIBRARIES}
)

# For parallel building.
if(USE_SHARED)
    add_dependencies(GeneratedSaxParser_shared OpenCOLLADABaseUtils_shared)
endif()
if(USE_STATIC)
    add_dependencies(GeneratedSaxParser_static OpenCOLLADABaseUtils_static)
endif()

if (USE_LIBXML)
	list(APPEND libGeneratedSaxParser_include_dirs ${LIBXML2_INCLUDE_DIR})
	list(APPEND TARGET_LIBS ${LIBXML2_LIBRARIES})
endif ()

if (USE_EXPAT)
	list(APPEND libGeneratedSaxParser_include_dirs ${LIBEXPAT_INCLUDE_DIR})
	list(APPEND TARGET_LIBS ${LIBEXPAT_LIBRARIES})
endif ()

include_directories(
	${libSaxFrameworkLoader_include_dirs}
	${libMathMLSolver_include_dirs}
	${libBaseUtils_include_dirs}
	${libFramework_include_dirs}
	${libGeneratedSaxParser_include_dirs}
	${PCRE_INCLUDE_DIR}
)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}")

install(
	FILES ${INST_SRC}
	DESTINATION ${OPENCOLLADA_INST_INCLUDE}/COLLADASaxFrameworkLoader
)
install(
	FILES ${INST_GEN14_SRC}
	DESTINATION ${OPENCOLLADA_INST_INCLUDE}/COLLADASaxFrameworkLoader/generated14
)
install(
	FILES ${INST_GEN15_SRC}
	DESTINATION ${OPENCOLLADA_INST_INCLUDE}/COLLADASaxFrameworkLoader/generated15
)
