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

	include/AST/MathMLASTArithmeticExpression.h
	include/AST/MathMLASTBinaryComparisionExpression.h
	include/AST/MathMLASTConstantExpression.h
	include/AST/MathMLASTFragmentExpression.h
	include/AST/MathMLASTFunctionExpression.h
	include/AST/MathMLASTLogicExpression.h
	include/AST/MathMLASTNode.h
	include/AST/MathMLASTStringVisitor.h
	include/AST/MathMLASTUnaryArithmeticExpression.h
	include/AST/MathMLASTVariableExpression.h
	include/AST/MathMLASTVisitor.h
	include/MathMLError.h
	include/MathMLEvaluatorVisitor.h
	include/MathMLParser.h
	include/MathMLParserConstants.h
	include/MathMLPlatform.h
	include/MathMLSerializationUtil.h
	include/MathMLSerializationVisitor.h
	include/MathMLSingleton.h
	include/MathMLSolverFunctionExtensions.h
	include/MathMLSolverPrerequisites.h
	include/MathMLSolverStableHeaders.h
	include/MathMLStreamParser.h
	include/MathMLStreamParserHandler.h
	include/MathMLString.h
	include/MathMLSymbolTable.h
)

set(TARGET_LIBS)

include_directories(
	${libMathMLSolver_include_dirs}
)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}")
