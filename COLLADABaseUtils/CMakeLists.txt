PROJECT(OpenCOLLADABaseUtils)

SET(libBaseUtils_include_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/include/
	${CMAKE_CURRENT_SOURCE_DIR}/include/Math/
	${PCRE_INCLUDE_DIR}
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

INCLUDE_DIRECTORIES(${libBaseUtils_include_dirs} ${libUTF_include_dirs}
)
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(OpenCOLLADABaseUtils ${libBaseUtils_src_files})
TARGET_LINK_LIBRARIES( 
	OpenCOLLADABaseUtils ${libBaseUtils_libs}
)
