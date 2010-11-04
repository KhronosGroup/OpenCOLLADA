PROJECT(OpenCOLLADAStreamWriter)

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
	ftoa
	buffer
	OpenCOLLADABaseUtils
)

INCLUDE_DIRECTORIES(${libStreamWriter_include_dirs} ${libBaseUtils_include_dirs} ${libftoa_include_dirs} ${libBuffer_include_dirs})
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(OpenCOLLADAStreamWriter ${libStreamWriterLoader_src_files})
TARGET_LINK_LIBRARIES( 
	OpenCOLLADAStreamWriter ${libStreamWriter_libs} 
)
