set(name OpenCOLLADASaxFrameworkLoader)
project(${name})

set(libSaxFrameworkLoader_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/generated14
	${CMAKE_CURRENT_SOURCE_DIR}/include/generated15
)

set(libSaxFrameworkLoader_include_dirs ${libSaxFrameworkLoader_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libSaxFrameworkLoader_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

set(libSaxFrameworkLoader_src_files
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryArticulatedSystemsLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLCOLLADACsymbol.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryAnimationsLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLIParserImpl14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLTransformationLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLInputUnshared.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLIFilePartLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLFilePartLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLGeometryMaterialIdInfo.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryControllersLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLSaxParserError.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLSaxFWLError.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLSourceArrayLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryKinematicsScenesLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLExtraDataLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryLightsLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryImagesLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLIParserImpl15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLNodeLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateNameMap.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLMeshLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLSceneLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryArticulatedSystemsLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateFindElementHash.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateFunctionMapFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryAnimationsLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryJointsLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryNodesLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLSourceArrayLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateValidation.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryKinematicsModelsLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLVisualSceneLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryImagesLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryFormulasLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLColladaParserAutoGen15Private.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLFormulasLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryKinematicsScenesLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateFunctionMap.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLGeometryLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLColladaParserAutoGen15PrivateEnums.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryLightsLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryEffectsLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLAssetLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryCamerasLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryMaterialsLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated15/COLLADASaxFWLLibraryControllersLoader15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLJointsLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLKinematicsIntermediateData.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLTypes.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLNodeLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLAssetLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLRootParser14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLKinematicsSceneCreator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLIExtraDataCallbackHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLMeshPrimitiveInputList.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLPrecompiledHeaders.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLInstanceKinematicsModelLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLSaxParserErrorHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryNodesLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLRootParser15.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryCamerasLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLFormulasLinker.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryKinematicsModelsLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryFormulasLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLPostProcessor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLDocumentProcessor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLSceneLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLInstanceArticulatedSystemLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLFormulasLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryMaterialsLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLFileLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLMeshLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLVersionParser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLIError.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLIErrorHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryEffectsLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLLibraryJointsLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateNameMap.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLLibraryNodesLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLGeometryLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateFunctionMapFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateValidation.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateEnums.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateFunctionMap.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLLibraryMaterialsLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLColladaParserAutoGen14PrivateFindElementHash.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLLibraryAnimationsLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLSceneLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLAssetLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLLibraryEffectsLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLVisualSceneLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLSourceArrayLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLNodeLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLLibraryControllersLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLColladaParserAutoGen14Private.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLLibraryCamerasLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLMeshLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLLibraryImagesLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/generated14/COLLADASaxFWLLibraryLightsLoader14.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLSidTreeNode.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLSidAddress.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLVisualSceneLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLGeometryLoader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASaxFWLExtraDataElementHandler.cpp
)

set(libSaxFrameworkLoader_libs
	OpenCOLLADABaseUtils
	GeneratedSaxParser
	OpenCOLLADAFramework
	MathMLSolver
      ${PCRE_LIBRARIES}
)

if (USE_LIBXML)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBXML2_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBXML2_LIBRARIES})
endif ()

if (USE_EXPAT)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBEXPAT_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBEXPAT_LIBRARIES})
endif ()

include_directories(
	${libSaxFrameworkLoader_include_dirs} 
	${libMathMLSolver_include_dirs} 
	${libBaseUtils_include_dirs} 
	${libFramework_include_dirs} 
	${libGeneratedSaxParser_include_dirs}
	${PCRE_INCLUDE_DIR}
)
link_directories(${LIBRARY_OUTPUT_PATH})

if (USE_STATIC)
	add_library(${name}_static STATIC ${libSaxFrameworkLoader_src_files})
	set_target_properties(${name}_static PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_static ${libSaxFrameworkLoader_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()

if (USE_SHARED)
	if (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	endif ()
	add_library(${name}_shared SHARED ${libSaxFrameworkLoader_src_files})
	set_target_properties(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_shared ${libSaxFrameworkLoader_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()