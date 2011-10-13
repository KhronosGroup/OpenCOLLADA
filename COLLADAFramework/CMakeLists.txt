set(name OpenCOLLADAFramework)
project(${name})

set(libFramework_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libFramework_include_dirs ${libFramework_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libFramework_src_files
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWLight.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWEffectCommon.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWInstanceKinematicsScene.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWRoot.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWFormula.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWPrecompiledHeaders.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWCamera.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWTexture.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWRenderState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWNode.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWKinematicsScene.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWMorphController.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWRotate.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWImage.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWValidate.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWVisualScene.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWKinematicsModel.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWEffect.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWMeshPrimitive.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWConstants.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWColor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWUniqueId.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWFormulas.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWTransformation.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWSkinController.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWMaterial.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWSampler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWScale.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWFloatOrDoubleArray.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWGeometry.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWTranslate.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWAxisInfo.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWKinematicsController.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWMatrix.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWLoaderUtils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWFileInfo.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWSkinControllerData.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADAFWMesh.cpp
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
link_directories(${LIBRARY_OUTPUT_PATH})

if (USE_STATIC)
	add_library(${name}_static STATIC ${libFramework_src_files})
	set_target_properties(${name}_static PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_static ${libFramework_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()

if (USE_SHARED)
	if (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	endif ()
	add_library(${name}_shared SHARED ${libFramework_src_files})
	set_target_properties(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_shared ${libFramework_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE) 
endif ()
