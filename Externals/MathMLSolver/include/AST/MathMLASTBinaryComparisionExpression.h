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

#ifndef __MATHML_AST_BINARY_COMPARISION_EXPRESSION_H___
#define __MATHML_AST_BINARY_COMPARISION_EXPRESSION_H___

#include "MathMLSolverPrerequisites.h"
#include "MathMLASTNode.h"

namespace MathML
{

    namespace AST
    {
        /** String representation for enum Operator::EQ. */
        static const String OPERATOR_COMPARE_EQ = "==";
        /** String representation for enum Operator::NEQ. */
        static const String OPERATOR_COMPARE_NEQ = "!=";
        /** String representation for enum Operator::LTE. */
        static const String OPERATOR_COMPARE_LTE = "<=";
        /** String representation for enum Operator::GTE. */
        static const String OPERATOR_COMPARE_GTE = ">=";
        /** String representation for enum Operator::LT. */
        static const String OPERATOR_COMPARE_LT = "<";
        /** String representation for enum Operator::GT. */
        static const String OPERATOR_COMPARE_GT = ">";
        /** String representation for invalid operator. */
        static const String OPERATOR_COMPARE_ILLEGAL = "ILLEGAL";

        /** Specialized binary comparison node implementing INode. */

        class _MATHML_SOLVER_EXPORT BinaryComparisonExpression : public INode
        {

        public:
            /** Supported Comparison Operators.
            */
            enum Operator
            {
                EQ,
                NEQ,
                LTE,
                GTE,
                LT,
                GT
            };

        private:
            /** Left operand of this expression. */
            INode* mLeftOperand;
            /** Right operand of this expression. */
            INode* mRightOperand;
            /** Operator of this expression. */
            Operator mOperator;

            /** Disable copy construction to avoid expensive deep copies of big trees.
            */
            BinaryComparisonExpression( const BinaryComparisonExpression& );
            BinaryComparisonExpression& operator=( const BinaryComparisonExpression& );

        public:
            /** C-tor. */
            BinaryComparisonExpression();

            /** D-tor. */
            virtual ~BinaryComparisonExpression();

            // see INode::accept(IVisitor* )
            virtual void accept( IVisitor* visitor ) const;
			
			// see INode::getType()
			virtual NodeType getNodeType() const { return COMPARISON; }

            /** @return a copy of this node. */
            virtual INode* clone(CloneFlags cloneFlags) const;

            /** Returns operator of this expression. */
            virtual Operator getOperator() const;

            /** Sets operator of this expression. */
            virtual void setOperator( Operator op );

            /** Getter for the operator of the expression.
            @return The operator of the expression as string.
            */
            virtual const String& getOperatorString() const;

            /** Setter for the operator of the expression.
            @param op The operator to set as string.
            */
            virtual void setOperator( const String& op );

            /** Returns left operand of this expression. */
            virtual INode* getLeftOperand() const;

            /** Sets left operand of this expression. */
            virtual void setLeftOperand( INode* operand );

            /** Returns right operand of this expression. */
            virtual INode* getRightOperand() const;

            /** Sets right operand of this expression. */
            virtual void setRightOperand( INode* operand );

            /** Returns a string representation of passed operator. */
            static const String& operatorString( Operator op );
        };

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_BINARY_COMPARISION_EXPRESSION_H___
