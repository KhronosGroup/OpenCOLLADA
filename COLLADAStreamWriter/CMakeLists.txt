set(name OpenCOLLADAStreamWriter)
project(${name})

set(libStreamWriter_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libStreamWriter_include_dirs ${libStreamWriter_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/COLLADASWTechniqueFX.cpp
	src/COLLADASWStreamWriter.cpp
	src/COLLADASWImage.cpp
	src/COLLADASWLibraryImages.cpp
	src/COLLADASWControlVertices.cpp
	src/COLLADASWInstanceEffect.cpp
	src/COLLADASWException.cpp
	src/COLLADASWBindMaterial.cpp
	src/COLLADASWSource.cpp
	src/COLLADASWSurfaceInitOption.cpp
	src/COLLADASWColor.cpp
	src/COLLADASWInstanceNode.cpp
	src/COLLADASWInstanceCamera.cpp
	src/COLLADASWPass.cpp
	src/COLLADASWPrimitves.cpp
	src/COLLADASWShader.cpp
	src/COLLADASWLibraryLights.cpp
	src/COLLADASWLibraryGeometries.cpp
	src/COLLADASWScene.cpp
	src/COLLADASWLibraryAnimationClips.cpp
	src/COLLADASWExtra.cpp
	src/COLLADASWLibraryMaterials.cpp
	src/COLLADASWBaseElement.cpp
	src/COLLADASWLibraryEffects.cpp
	src/COLLADASWExtraTechnique.cpp
	src/COLLADASWEffectProfile.cpp
	src/COLLADASWFormatHint.cpp
	src/COLLADASWLibraryControllers.cpp
	src/COLLADASWBaseInputElement.cpp
	src/COLLADASWInstanceMaterial.cpp
	src/COLLADASWLight.cpp
	src/COLLADASWCameraOptic.cpp
	src/COLLADASWVertices.cpp
	src/COLLADASWInstanceController.cpp
	src/COLLADASWTechnique.cpp
	src/COLLADASWLibraryAnimations.cpp
	src/COLLADASWParamBase.cpp
	src/COLLADASWLibraryVisualScenes.cpp
	src/COLLADASWCamera.cpp
	src/COLLADASWAsset.cpp
	src/COLLADASWLibraryCameras.cpp
	src/COLLADASWNode.cpp
	src/COLLADASWInstanceGeometry.cpp
	src/COLLADASWSampler.cpp
	src/COLLADASWInstanceLight.cpp
	src/COLLADASWTexture.cpp
	src/COLLADASWRenderState.cpp
	src/COLLADASWInputList.cpp
	src/COLLADASWElementWriter.cpp
	src/COLLADASWLibrary.cpp
	src/COLLADASWConstants.cpp
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

opencollada_add_lib(${name} "${SRC}" "${libStreamWriter_libs}")
