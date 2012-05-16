/******************************************************************************
Copyright (c) 2007 netAllied GmbH, Tettnang

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

#ifndef __MATHML_EVALUATOR_VISITOR_H__
#define __MATHML_EVALUATOR_VISITOR_H__

#include "MathMLSolverPrerequisites.h"

#include "MathMLASTNode.h"
#include "MathMLASTArithmeticExpression.h"
#include "MathMLASTLogicExpression.h"
#include "MathMLASTBinaryComparisionExpression.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLASTUnaryArithmeticExpression.h"
#include "MathMLASTFragmentExpression.h"
#include "MathMLASTVariableExpression.h"
#include "MathMLASTFunctionExpression.h"
#include "MathMLASTVisitor.h"
#include "MathMLSymbolTable.h"


namespace MathML
{
    /** Forward Declaration. */
    class ErrorHandler;

    /** Expression node visitor for evaluating.
    */

    class _MATHML_SOLVER_EXPORT EvaluatorVisitor : public AST::IVisitor
    {

    private:
        /** Temporary value of branch evaluating. */
        AST::ConstantExpression mBranchValue;

        /** Symbol table holding given variables and functions. */
        SymbolTable& mSymbolTable;

        /** Error handler. */
        ErrorHandler* mErrorHandler;

    public:
        /** Creates a new evaluator that uses the given SymbolTable by reference to evaluate expressions.
		*/
        EvaluatorVisitor( SymbolTable& symbolTable, ErrorHandler* errorHandler );

        /** D-tor. */
        virtual ~EvaluatorVisitor();

        // see IVisitor::visit(const ArithmeticExpression&)
        virtual void visit( const AST::ArithmeticExpression* const node );

        // see IVisitor::visit(const BinaryComparisionExpression&)
        virtual void visit( const AST::BinaryComparisonExpression* const node );

        // see IVisitor::visit(const FragmentExpression&)
        virtual void visit( const AST::FragmentExpression* const node );

        // see IVisitor::visit(const LogicExpression&)
        virtual void visit( const AST::LogicExpression* const node );

        // see IVisitor::visit(const ConstantExpression&)
        virtual void visit( const AST::ConstantExpression* const node );

        // see IVisitor::visit(const FunctionExpression&)
        virtual void visit( const AST::FunctionExpression* const node );

        // see IVisitor::visit(const UnaryArithmeticExpression&)
        virtual void visit( const AST::UnaryExpression* const node );

        // see IVisitor::visit(const VariableExpression&)
        virtual void visit( const AST::VariableExpression* const node );

        /** Getter for last calculated branch value. */
        virtual const AST::ConstantExpression& getValue();

    };

} //namespace MathML

#endif //__MATHML_EVALUATOR_VISITOR_H__
