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

#ifndef __MATHML_AST_LOGIC_EXPRESSION_H___
#define __MATHML_AST_LOGIC_EXPRESSION_H___

#include "MathMLSolverPrerequisites.h"
#include "MathMLASTNode.h"

namespace MathML
{

    namespace AST
    {
        /** String representation for enum Operator::AND. */
        static const String OPERATOR_LOGIC_AND = "&&";
        /** String representation for enum Operator::OR. */
        static const String OPERATOR_LOGIC_OR = "||";
        /** String representation for enum Operator::XOR. */
        static const String OPERATOR_LOGIC_XOR = "^";
        /** String representation for invalid operator. */
        static const String OPERATOR_LOGIC_ILLEGAL = "ILLEGAL";

        /** Specialized logic node implementing INode. */

        class _MATHML_SOLVER_EXPORT LogicExpression : public INode
        {

        public:
            /** Enumeration of the logic operators. */
            enum Operator
            {
                AND,
                OR,
                XOR

                //NOT is represented in unary expression.
            };

        private:
            /** The operand list for the same type of logic operation. */
            NodeList mOperands;

            /** The operator of the logic expression. */
            Operator mOperator;

            /** Disable copy construction to avoid expensive deep copies of big trees.
            */
            LogicExpression( const LogicExpression& );
            LogicExpression& operator=( const LogicExpression& );

        public:
            /** C-tor. */
            LogicExpression();

            /** D-tor. */
            ~LogicExpression();

            // see INode::accept(IVisitor* )
            virtual void accept( IVisitor* visitor ) const;

			// see INode::getType()
			virtual NodeType getNodeType() const { return LOGICAL; }

            /** @return a copy of this node. */
            virtual INode* clone(CloneFlags cloneFlags) const;

            /** Getter for the operator of the logic expression.
            @return The operator of the expression.
            */
            virtual Operator getOperator() const;

            /** Setter for the operator of the logic expression.
            @param op The operator to set.
            */
            virtual void setOperator( Operator op );

            /** Getter for the operator of the expression.
            @return The operator of the expression as string.
            */
            virtual String getOperatorString() const;

            /** Setter for the operator of the expression.
            @param op The operator to set as string.
            */
            virtual void setOperator( const String& op );

			/** Getter for the operands of the logic expression.
			@return The list of operands.
			*/
			virtual const NodeList& getOperands() const;

			/** Getter for the operands of the logic expression.
			@return The list of operands.
			*/
			virtual NodeList& getOperands();

            /** Adds an operand to the logic expression.
            @param operand The operand to add to the list of operands.
            */
            virtual void addOperand( INode* operand );

            /** Returns a string representation of passed operator. */
            static String operatorString( Operator op );
        };

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_LOGIC_EXPRESSION_H___
