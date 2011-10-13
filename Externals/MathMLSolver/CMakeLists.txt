set(name MathMLSolver)
project(${name})

set(libMathMLSolver_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/AST
)

set(libMathMLSolver_include_dirs ${libMathMLSolver_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

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

set(libMathMLSolver_libs)

include_directories(
	${libMathMLSolver_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

if (USE_STATIC)
	add_library(${name}_static STATIC ${libMathMLSolver_src_files})
	set_target_properties(${name}_static PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_static ${libMathMLSolver_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()

if (USE_SHARED)
	if (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	endif ()
	add_library(${name}_shared SHARED ${libMathMLSolver_src_files})
	set_target_properties(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_shared ${libMathMLSolver_libs}) 
	set(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()
