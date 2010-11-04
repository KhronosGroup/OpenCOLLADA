PROJECT(Buffer)

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

SET(libBuffer_libs)

INCLUDE_DIRECTORIES(${libBuffer_include_dirs} ${libftoa_include_dirs})
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(buffer ${libBuffer_src_files})
TARGET_LINK_LIBRARIES( 
	buffer ${libBuffer_libs} 
)
