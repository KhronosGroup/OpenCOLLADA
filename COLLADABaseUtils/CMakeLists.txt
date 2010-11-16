SET(name OpenCOLLADABaseUtils)
PROJECT(${name})

SET(libBaseUtils_include_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/include/
	${CMAKE_CURRENT_SOURCE_DIR}/include/Math/
)

SET(libBaseUtils_include_dirs ${libBaseUtils_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libBaseUtils_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

file(GLOB_RECURSE libBaseUtils_src_files 
	${libBaseUtils_src_dirs}/*.cpp
	${libBaseUtils_src_dirs}/*.h
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



