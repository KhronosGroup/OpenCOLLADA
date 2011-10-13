SET(name OpenCOLLADABaseUtils)
PROJECT(${name})

SET(libBaseUtils_include_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/Math
)

SET(libBaseUtils_include_dirs ${libBaseUtils_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libBaseUtils_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

set(libBaseUtils_src_files
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUUtils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUURI.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUPrecompiledHeaders.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUPcreCompiledPattern.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUIDList.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUStringUtils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUHashFunctions.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUNativeString.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathMatrix3.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathVector3.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathUtils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathQuaternion.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathMatrix4.cpp
)

SET(libBaseUtils_libs
	UTF
	${PCRE_LIBRARIES}
)

INCLUDE_DIRECTORIES(${libBaseUtils_include_dirs} 
	${libUTF_include_dirs}
	${PCRE_INCLUDE_DIR}
)

LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

IF (USE_STATIC)
	ADD_LIBRARY(${name}_static STATIC ${libBaseUtils_src_files})
	SET_TARGET_PROPERTIES(${name}_static PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_static ${libBaseUtils_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_STATIC)
IF (USE_SHARED)
	IF (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	ENDIF (NOT UNIX)
	ADD_LIBRARY(${name}_shared SHARED ${libBaseUtils_src_files})
	SET_TARGET_PROPERTIES(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_shared ${libBaseUtils_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}"  PARENT_SCOPE)
ENDIF (USE_SHARED)



