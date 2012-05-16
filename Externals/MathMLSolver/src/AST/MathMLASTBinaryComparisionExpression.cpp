#include "MathMLSolverStableHeaders.h"
#include "MathMLASTBinaryComparisionExpression.h"

namespace MathML
{

    namespace AST
    {
        //---------------------------------------------------------------------------------
        BinaryComparisonExpression::BinaryComparisonExpression()
                : mOperator( EQ )
                , mLeftOperand( 0 )
                , mRightOperand( 0 )
        {}

        BinaryComparisonExpression::~BinaryComparisonExpression()
        {
            delete mLeftOperand;
            delete mRightOperand;
        }

        //---------------------------------------------------------------------------------
        void BinaryComparisonExpression::accept( IVisitor* visitor ) const
        {
            visitor->visit( this );
        }

        //---------------------------------------------------------------------------------
        BinaryComparisonExpression::Operator BinaryComparisonExpression::getOperator() const
        {
            return mOperator;
        }

        //---------------------------------------------------------------------------------
        void BinaryComparisonExpression::setOperator( Operator op )
        {
            mOperator = op;
        }

        //---------------------------------------------------------------------------------
        const String& BinaryComparisonExpression::getOperatorString() const
        {
            return operatorString( mOperator );
        }

        //---------------------------------------------------------------------------------
        const String& BinaryComparisonExpression::operatorString( Operator op )
        {
            switch ( op )
            {

            case EQ:
                return OPERATOR_COMPARE_EQ;

            case NEQ:
                return OPERATOR_COMPARE_NEQ;

            case LTE:
                return OPERATOR_COMPARE_LTE;

            case GTE:
                return OPERATOR_COMPARE_GTE;

            case LT:
                return OPERATOR_COMPARE_LT;

            case GT:
                return OPERATOR_COMPARE_GT;
            }

            return OPERATOR_COMPARE_ILLEGAL;
        }

        //---------------------------------------------------------------------------------
        void BinaryComparisonExpression::setOperator( const String& op )
        {
            if ( op == OPERATOR_COMPARE_EQ )
            {
                mOperator = EQ;
            }

            else if ( op == OPERATOR_COMPARE_NEQ )
            {
                mOperator = NEQ;
            }

            else if ( op == OPERATOR_COMPARE_LTE )
            {
                mOperator = LTE;
            }

            else if ( op == OPERATOR_COMPARE_GTE )
            {
                mOperator = GTE;
            }

            else if ( op == OPERATOR_COMPARE_LT )
            {
                mOperator = LT;
            }

            else if ( op == OPERATOR_COMPARE_GT )
            {
                mOperator = GT;
            }
        }

        //---------------------------------------------------------------------------------
        INode* BinaryComparisonExpression::getLeftOperand() const
        {
            return mLeftOperand;
        }

        //---------------------------------------------------------------------------------
        void BinaryComparisonExpression::setLeftOperand( INode* operand )
        {
            mLeftOperand = operand;
        }

        //---------------------------------------------------------------------------------
        INode* BinaryComparisonExpression::getRightOperand() const
        {
            return mRightOperand;
        }

        //---------------------------------------------------------------------------------
        void BinaryComparisonExpression::setRightOperand( INode* operand )
        {
            mRightOperand = operand;
        }

        //-----------------------------------------------------------------
        INode* BinaryComparisonExpression::clone(CloneFlags cloneFlags) const
        {
            BinaryComparisonExpression* copy = new BinaryComparisonExpression();
            copy->mOperator = mOperator;

            if ( mLeftOperand )
                copy->mLeftOperand = mLeftOperand->clone(cloneFlags);
            else
                copy->mLeftOperand = 0;

            if ( mRightOperand )
                copy->mRightOperand = mRightOperand->clone(cloneFlags);
            else
                copy->mRightOperand = 0;

            return copy;
        }

    } //namespace AST

} //namespace MathML

