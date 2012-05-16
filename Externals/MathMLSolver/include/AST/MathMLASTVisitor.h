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

#ifndef __MATHML_AST_VISITOR_H___
#define __MATHML_AST_VISITOR_H___

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

        /** Interface of AST node visitor. */

        class _MATHML_SOLVER_EXPORT IVisitor
        {

        public:

            /** Virtual D-tor to make sure sub class D-tors are called. */
            virtual ~IVisitor()
            {}

            /** Callback for visiting of (specialized) arithmetic node.
                     @param node The arithmetic expression node.
                     */
            virtual void visit( const ArithmeticExpression* const node ) = 0;

            /** Callback for visiting of (specialized) binary comparision node.
            @param node The binary comparision expression node.
            */
            virtual void visit( const BinaryComparisonExpression* const node ) = 0;

            /** Callback for visiting of (specialized) fragment node.
            @param node The fragment expression node.
            */
            virtual void visit( const FragmentExpression* const node ) = 0;

            /** Callback for visiting of (specialized) logic node.
            @param node The logic expression node.
            */
            virtual void visit( const LogicExpression* const node ) = 0;

            /** Callback for visiting of (specialized) constant node.
            @param node The constant expression node.
            */
            virtual void visit( const ConstantExpression* const node ) = 0;

            /** Callback for visiting of (specialized) function node.
            @param node The function expression node.
            */
            virtual void visit( const FunctionExpression* const node ) = 0;

            /** Callback for visiting of (specialized) unary arithmetic node.
            @param node The unary arithmetic expression node.
            */
            virtual void visit( const UnaryExpression* const node ) = 0;

            /** Callback for visiting of (specialized) variable node.
            @param node The variable expression node.
            */
            virtual void visit( const VariableExpression* const node ) = 0;

			virtual void visit( const INode* const node)
			{
				switch(node->getNodeType())
				{
				case INode::FRAGMENT:
					visit(static_cast<const FragmentExpression* const>(node));
					break;

				case INode::ARITHMETIC:
					visit(static_cast<const ArithmeticExpression* const>(node));
					break;

				case INode::COMPARISON:
					visit(static_cast<const BinaryComparisonExpression* const>(node));
					break;

				case INode::CONSTANT:
					visit(static_cast<const ConstantExpression* const>(node));
					break;

				case INode::FUNCTION:
					visit(static_cast<const FunctionExpression* const>(node));
					break;

				case INode::LOGICAL:
					visit(static_cast<const LogicExpression* const>(node));
					break;

				case INode::UNARY:
					visit(static_cast<const UnaryExpression* const>(node));
					break;

				case INode::VARIABLE:
					visit(static_cast<const VariableExpression* const>(node));
					break;
				}
			}

        };

        /** Default expression node visitor implementing AST-Node-Interface ('INode').
        @par Does nothing. Specialized Visitors have to implement/override the methods.
        */

        class _MATHML_SOLVER_EXPORT DefaultVisitor : public IVisitor
        {

        public:
            // see IVisitor::visit(const ArithmeticExpression&)
            virtual void visit( const ArithmeticExpression* const node )
            {}

            // see IVisitor::visit(const BinaryComparisionExpression&)
            virtual void visit( const BinaryComparisonExpression* const node )
            {}

            // see IVisitor::visit(const FragmentExpression&)
            virtual void visit( const FragmentExpression* const node )
            {}

            // see IVisitor::visit(const LogicExpression&)
            virtual void visit( const LogicExpression* const node )
            {}

            // see IVisitor::visit(const ConstantExpression&)
            virtual void visit( const ConstantExpression* const node )
            {}

            // see IVisitor::visit(const FunctionExpression&)
            virtual void visit( const FunctionExpression* const node )
            {}

            // see IVisitor::visit(const UnaryArithmeticExpression&)
            virtual void visit( const UnaryExpression* const node )
            {}

            // see IVisitor::visit(const VariableExpression&)
            virtual void visit( const VariableExpression* const node )
            {}

        }

        ;

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_VISITOR_H___
