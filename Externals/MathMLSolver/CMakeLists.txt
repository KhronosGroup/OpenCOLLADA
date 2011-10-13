set(name MathMLSolver)
project(${name})

set(libMathMLSolver_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/AST
)

set(libMathMLSolver_include_dirs ${libMathMLSolver_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/MathMLEvaluatorVisitor.cpp
	src/MathMLSolverPrecompiled.cpp
	src/MathMLSymbolTable.cpp
	src/AST/MathMLASTStringVisitor.cpp
	src/AST/MathMLASTUnaryArithmeticExpression.cpp
	src/AST/MathMLASTBinaryComparisionExpression.cpp
	src/AST/MathMLASTLogicExpression.cpp
	src/AST/MathMLASTFragmentExpression.cpp
	src/AST/MathMLASTFunctionExpression.cpp
	src/AST/MathMLASTVariableExpression.cpp
	src/AST/MathMLASTConstantExpression.cpp
	src/AST/MathMLASTArithmeticExpression.cpp
	src/MathMLSolverFunctionExtensions.cpp
	src/MathMLSerializationVisitor.cpp
	src/MathMLSerializationUtil.cpp
	src/MathMLString.cpp
)

set(TARGET_LIBS)

include_directories(
	${libMathMLSolver_include_dirs}
)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}")
