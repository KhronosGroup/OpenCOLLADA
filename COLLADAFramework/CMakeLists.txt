set(name OpenCOLLADAFramework)
project(${name})

set(libFramework_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libFramework_include_dirs ${libFramework_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/COLLADAFWLight.cpp
	src/COLLADAFWEffectCommon.cpp
	src/COLLADAFWInstanceKinematicsScene.cpp
	src/COLLADAFWRoot.cpp
	src/COLLADAFWFormula.cpp
	src/COLLADAFWPrecompiledHeaders.cpp
	src/COLLADAFWCamera.cpp
	src/COLLADAFWTexture.cpp
	src/COLLADAFWRenderState.cpp
	src/COLLADAFWNode.cpp
	src/COLLADAFWKinematicsScene.cpp
	src/COLLADAFWMorphController.cpp
	src/COLLADAFWRotate.cpp
	src/COLLADAFWImage.cpp
	src/COLLADAFWValidate.cpp
	src/COLLADAFWVisualScene.cpp
	src/COLLADAFWKinematicsModel.cpp
	src/COLLADAFWEffect.cpp
	src/COLLADAFWMeshPrimitive.cpp
	src/COLLADAFWConstants.cpp
	src/COLLADAFWColor.cpp
	src/COLLADAFWUniqueId.cpp
	src/COLLADAFWFormulas.cpp
	src/COLLADAFWTransformation.cpp
	src/COLLADAFWSkinController.cpp
	src/COLLADAFWMaterial.cpp
	src/COLLADAFWSampler.cpp
	src/COLLADAFWScale.cpp
	src/COLLADAFWFloatOrDoubleArray.cpp
	src/COLLADAFWGeometry.cpp
	src/COLLADAFWTranslate.cpp
	src/COLLADAFWAxisInfo.cpp
	src/COLLADAFWKinematicsController.cpp
	src/COLLADAFWMatrix.cpp
	src/COLLADAFWLoaderUtils.cpp
	src/COLLADAFWFileInfo.cpp
	src/COLLADAFWSkinControllerData.cpp
	src/COLLADAFWMesh.cpp
)

set(libFramework_libs
	OpenCOLLADABaseUtils
	MathMLSolver
)

include_directories(
	${libFramework_include_dirs}
	${libBaseUtils_include_dirs}
	${libMathMLSolver_include_dirs}

)
opencollada_add_lib(${name} "${SRC}" "${libFramework_libs}")
