SET(name MathMLSolver)
PROJECT(${name})

SET(libMathMLSolver_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/AST
)

SET(libMathMLSolver_include_dirs ${libMathMLSolver_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libMathMLSolver_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

set(libMathMLSolver_src_files
	${CMAKE_CURRENT_SOURCE_DIR}/src/MathMLEvaluatorVisitor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/MathMLSolverPrecompiled.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/MathMLSymbolTable.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AST/MathMLASTStringVisitor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AST/MathMLASTUnaryArithmeticExpression.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AST/MathMLASTBinaryComparisionExpression.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AST/MathMLASTLogicExpression.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AST/MathMLASTFragmentExpression.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AST/MathMLASTFunctionExpression.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AST/MathMLASTVariableExpression.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AST/MathMLASTConstantExpression.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/AST/MathMLASTArithmeticExpression.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/MathMLSolverFunctionExtensions.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/MathMLSerializationVisitor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/MathMLSerializationUtil.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/MathMLString.cpp
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
