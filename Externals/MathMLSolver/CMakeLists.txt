SET(name MathMLSolver)
PROJECT(${name})

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

IF (USE_STATIC)
	ADD_LIBRARY(${name}_static STATIC ${libMathMLSolver_src_files})
	SET_TARGET_PROPERTIES(${name}_static PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_static ${libMathMLSolver_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_STATIC)

IF (USE_SHARED)
	IF (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	ENDIF (NOT UNIX)
	ADD_LIBRARY(${name}_shared SHARED ${libMathMLSolver_src_files})
	SET_TARGET_PROPERTIES(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_shared ${libMathMLSolver_libs}) 
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_SHARED)
