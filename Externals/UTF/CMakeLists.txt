SET(name UTF)
PROJECT(${name})

SET(libUTF_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libUTF_include_dirs ${libUTF_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libUTF_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

file(GLOB_RECURSE libUTF_src_files 
	${libUTF_src_dirs}/*.c
)

SET(libUTF_libs)

INCLUDE_DIRECTORIES(
	${libUTF_include_dirs} 
)
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

IF (USE_STATIC)
	ADD_LIBRARY(${name}_static STATIC ${libUTF_src_files})
	SET_TARGET_PROPERTIES(${name}_static PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_static ${libUTF_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_STATIC)

IF (USE_SHARED)
	IF (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	ENDIF (NOT UNIX)
	ADD_LIBRARY(${name}_shared SHARED ${libUTF_src_files})
	SET_TARGET_PROPERTIES(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_shared ${libUTF_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_SHARED)
