SET(name OpenCOLLADAStreamWriter)
PROJECT(${name})

SET(libStreamWriter_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libStreamWriter_include_dirs ${libStreamWriter_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libStreamWriter_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

file(GLOB_RECURSE libStreamWriterLoader_src_files 
	${libStreamWriter_src_dirs}/*.cpp
	${libStreamWriter_src_dirs}/*.h
)

SET(libStreamWriter_libs
	OpenCOLLADABaseUtils	
	buffer
	ftoa
)

INCLUDE_DIRECTORIES(${libStreamWriter_include_dirs} 
	${libBaseUtils_include_dirs} 
	${libftoa_include_dirs} 
	${libBuffer_include_dirs}
)

LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

IF (USE_STATIC)
	ADD_LIBRARY(${name}_static STATIC ${libStreamWriterLoader_src_files})
	SET_TARGET_PROPERTIES(${name}_static PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_static ${libStreamWriter_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_STATIC)

IF (USE_SHARED)
	IF (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	ENDIF (NOT UNIX)
	ADD_LIBRARY(${name}_shared SHARED ${libStreamWriterLoader_src_files})
	SET_TARGET_PROPERTIES(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_shared ${libStreamWriter_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_SHARED)
