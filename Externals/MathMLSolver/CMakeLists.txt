PROJECT(MathMLSolver)

SET(libMathMLSolver_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
	${CMAKE_CURRENT_SOURCE_DIR}/include/AST/
)

SET(libMathMLSolver_include_dirs ${libMathMLSolver_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libMathMLSolver_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

file(GLOB_RECURSE libMathMLSolver_src_files 
	${libMathMLSolver_src_dirs}/*.cpp
	${libMathMLSolver_src_dirs}/*.h
)

SET(libMathMLSolver_libs)

INCLUDE_DIRECTORIES(${libMathMLSolver_include_dirs})
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(MathMLSolver ${libMathMLSolver_src_files})
TARGET_LINK_LIBRARIES( 
	MathMLSolver ${libMathMLSolver_libs} 
)
