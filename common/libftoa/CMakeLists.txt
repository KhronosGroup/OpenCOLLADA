PROJECT(ftoa)

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

ADD_LIBRARY(ftoa ${libftoa_src_files})
TARGET_LINK_LIBRARIES( 
	ftoa ${libftoa_libs} 
)
