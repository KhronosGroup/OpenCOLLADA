SET(name pcre)
PROJECT(${name})

SET(libpcre_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libpcre_include_dirs ${libpcre_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libpcre_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

file(GLOB libpcre_src_files 
	${libpcre_src_dirs}/*.c
)

SET(libpcre_libs)

INCLUDE_DIRECTORIES(${libpcre_include_dirs})
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(${name} ${libpcre_src_files})
TARGET_LINK_LIBRARIES(${name} ${libpcre_libs})
SET(CMAKE_REQUIRED_LIBRARIES "${name};${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)