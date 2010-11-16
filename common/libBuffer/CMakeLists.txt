SET(name buffer)
PROJECT(${name})

SET(libBuffer_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libBuffer_include_dirs ${libBuffer_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libBuffer_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

set(libBuffer_src_files 
	${libBuffer_src_dirs}/CommonBuffer.cpp
	${libBuffer_src_dirs}/CommonCharacterBuffer.cpp
	${libBuffer_src_dirs}/CommonFWriteBufferFlusher.cpp
	${libBuffer_src_dirs}/CommonStreamBufferFlusher.cpp
)

SET(libBuffer_libs ftoa)

INCLUDE_DIRECTORIES(${libBuffer_include_dirs} ${libftoa_include_dirs})
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

IF (USE_STATIC)
	ADD_LIBRARY(${name}_static STATIC ${libBuffer_src_files})
	SET_TARGET_PROPERTIES(${name}_static PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_static ${libBuffer_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_STATIC)

IF (USE_SHARED)
	IF (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	ENDIF (NOT UNIX)
	ADD_LIBRARY(${name}_shared SHARED ${libBuffer_src_files})
	SET_TARGET_PROPERTIES(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_shared ${libBuffer_libs}) 
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_SHARED)
