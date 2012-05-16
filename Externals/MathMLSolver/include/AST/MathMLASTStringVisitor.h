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

#ifndef __MATHML_AST_STRING_VISITOR_H___
#define __MATHML_AST_STRING_VISITOR_H___

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

namespace MathML
{

    namespace AST
    {

        /** Expression node visitor for string dump.
        */

        class _MATHML_SOLVER_EXPORT StringVisitor : public IVisitor
        {

        private:
            /** The output stream pointer. */
            std::ostream* mOut;

        public:
            /** Initializing constructor.
            @param out The output stream to stream to.
            */
            StringVisitor( std::ostream* out );

            /** D-tor. */
            ~StringVisitor();

            // see IVisitor::visit(const ArithmeticExpression&)
            virtual void visit( const ArithmeticExpression* const node );

            // see IVisitor::visit(const BinaryComparisionExpression&)
            virtual void visit( const BinaryComparisonExpression* const node );

            // see IVisitor::visit(const FragmentExpression&)
            virtual void visit( const FragmentExpression* const node );

            // see IVisitor::visit(const LogicExpression&)
            virtual void visit( const LogicExpression* const node );

            // see IVisitor::visit(const ConstantExpression&)
            virtual void visit( const ConstantExpression* const node );

            // see IVisitor::visit(const FunctionExpression&)
            virtual void visit( const FunctionExpression* const node );

            // see IVisitor::visit(const UnaryArithmeticExpression&)
            virtual void visit( const UnaryExpression* const node );

            // see IVisitor::visit(const VariableExpression&)
            virtual void visit( const VariableExpression* const node );
        };

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_STRING_VISITOR_H___
