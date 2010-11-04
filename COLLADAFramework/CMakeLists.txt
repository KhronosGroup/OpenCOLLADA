PROJECT(OpenCOLLADAFramework)


SET(libFramework_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libFramework_include_dirs ${libFramework_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libFramework_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

file(GLOB_RECURSE libFramework_src_files 
	${libFramework_src_dirs}/*.cpp
	${libFramework_src_dirs}/*.h
)

SET(libFramework_libs
	OpenCOLLADABaseUtils
	MathMLSolver
)

INCLUDE_DIRECTORIES(${libFramework_include_dirs} ${libBaseUtils_include_dirs} ${libMathMLSolver_include_dirs})
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(OpenCOLLADAFramework ${libFramework_src_files})
TARGET_LINK_LIBRARIES( 
	OpenCOLLADAFramework ${libFramework_libs}
)
