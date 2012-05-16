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

#ifndef __MATHML_AST_UNARY_ARITHMETIC_EXPRESSION_H___
#define __MATHML_AST_UNARY_ARITHMETIC_EXPRESSION_H___

#include "MathMLSolverPrerequisites.h"
#include "MathMLASTNode.h"

namespace MathML
{

    namespace AST
    {
        /** String representation for enum Operator::ADD. */
        static const String OPERATOR_UNARY_ADD = "+";
        /** String representation for enum Operator::SUB. */
        static const String OPERATOR_UNARY_SUB = "-";
        /** String representation for enum Operator::NOT. */
        static const String OPERATOR_UNARY_NOT = "!";
        /** String representation for invalid operator. */
        static const String OPERATOR_UNARY_ILLEGAL = "ILLEGAL";

        /** Specialized unary arithmetic node implementing INode. */

        class _MATHML_SOLVER_EXPORT UnaryExpression : public INode
        {

        public:
            /** Enumeration of the unary arithmetic operators. */
            enum Operator
            {
                ADD,
                SUB,
                NOT
            };

        private:
            /** The operand for the unary expression. */
            INode* mOperand;

            /** The operator of the unary expression. */
            Operator mOperator;

            /** Disable copy construction to avoid expensive deep copies of big trees.
            */
            UnaryExpression( const UnaryExpression& );
            UnaryExpression& operator=( const UnaryExpression& );

        public:
            /** C-tor. */
            UnaryExpression();

            /** D-tor. */
            virtual ~UnaryExpression();

            // see INode::accept(IVisitor* )
            virtual void accept( IVisitor* visitor ) const;

			// see INode::getType()
			virtual NodeType getNodeType() const { return UNARY; }

            /** @return a copy of this node. */
            virtual INode* clone(CloneFlags cloneFlags) const;

            /** Getter for the operator of the unary expression.
            @return The operator of the expression.
            */
            virtual Operator getOperator() const;

            /** Setter for the operator of the unary expression.
            @param op The operator to set.
            */
            virtual void setOperator( Operator op );

            /** Getter for the operator of the unary expression.
            @return The operator of the expression as string.
            */
            virtual const String& getOperatorString() const;

            /** Setter for the operator of the unary expression.
            @param op The operator to set as string.
            */
            virtual void setOperator( const String& op );

            /** Getter for the operand of the unary expression.
            @return The operand of the expression.
            */
            virtual INode* getOperand() const;

            /** Setter for the operand of the unary expression.
            @param operand The operand to set.
            */
            virtual void setOperand( INode* operand );

            /** Returns a string representation of passed operator. */
            static const String& operatorString( Operator op );
        };

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_UNARY_ARITHMETIC_EXPRESSION_H___
