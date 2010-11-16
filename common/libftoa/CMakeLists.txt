SET(name ftoa)
PROJECT(${name})

SET(libftoa_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libftoa_include_dirs ${libftoa_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libftoa_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

SET(libftoa_src_files 
	${libftoa_src_dirs}/Commondtoa.cpp
	${libftoa_src_dirs}/Commonftoa.cpp
	${libftoa_src_dirs}/Commonitoa.cpp
)

SET(libftoa_libs)

INCLUDE_DIRECTORIES(${libftoa_include_dirs})
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

IF (USE_STATIC)
	ADD_LIBRARY(${name}_static STATIC ${libftoa_src_files})
	SET_TARGET_PROPERTIES(${name}_static PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_static ${libftoa_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_STATIC)

IF (USE_SHARED)
	IF (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	ENDIF (NOT UNIX)
	ADD_LIBRARY(${name}_shared SHARED ${libftoa_src_files})
	SET_TARGET_PROPERTIES(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_shared ${libftoa_libs}) 
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_SHARED)
