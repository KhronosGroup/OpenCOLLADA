set(name OpenCOLLADAStreamWriter)
project(${name})

set(libStreamWriter_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libStreamWriter_include_dirs ${libStreamWriter_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libStreamWriter_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

set(libStreamWriterLoader_src_files
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWTechniqueFX.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWStreamWriter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWImage.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryImages.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWControlVertices.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWInstanceEffect.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWException.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWBindMaterial.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWSource.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWSurfaceInitOption.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWColor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWInstanceNode.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWInstanceCamera.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWPass.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWPrimitves.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWShader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryLights.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryGeometries.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWScene.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryAnimationClips.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWExtra.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryMaterials.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWBaseElement.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryEffects.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWExtraTechnique.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWEffectProfile.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWFormatHint.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryControllers.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWBaseInputElement.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWInstanceMaterial.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLight.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWCameraOptic.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWVertices.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWInstanceController.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWTechnique.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryAnimations.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWParamBase.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryVisualScenes.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWCamera.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWAsset.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibraryCameras.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWNode.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWInstanceGeometry.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWSampler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWInstanceLight.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWTexture.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWRenderState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWInputList.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWElementWriter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWLibrary.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADASWConstants.cpp
)

set(libStreamWriter_libs
	OpenCOLLADABaseUtils	
	buffer
	ftoa
)

include_directories(
	${libStreamWriter_include_dirs} 
	${libBaseUtils_include_dirs} 
	${libftoa_include_dirs} 
	${libBuffer_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

if (USE_STATIC)
	add_library(${name}_static STATIC ${libStreamWriterLoader_src_files})
	set_target_properties(${name}_static PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_static ${libStreamWriter_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()

if (USE_SHARED)
	if (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	endif ()
	add_library(${name}_shared SHARED ${libStreamWriterLoader_src_files})
	set_target_properties(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_shared ${libStreamWriter_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()
