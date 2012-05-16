#include "MathMLSolverStableHeaders.h"
#include "MathMLASTUnaryArithmeticExpression.h"

namespace MathML
{

    namespace AST
    {
        //---------------------------------------------------------------------------------
        UnaryExpression::UnaryExpression()
            : mOperator( ADD )
            , mOperand( 0 )
        {}

        //---------------------------------------------------------------------------------
        UnaryExpression::~UnaryExpression()
        {
            delete mOperand;
            mOperand = 0;
        }

        //---------------------------------------------------------------------------------
        void UnaryExpression::accept( IVisitor* visitor ) const
        {
            visitor->visit( this );
        }

        //---------------------------------------------------------------------------------
        UnaryExpression::Operator UnaryExpression::getOperator() const
        {
            return mOperator;
        }

        //---------------------------------------------------------------------------------
        void UnaryExpression::setOperator( Operator op )
        {
            mOperator = op;
        }

        //---------------------------------------------------------------------------------
        const String& UnaryExpression::getOperatorString() const
        {
            return operatorString( mOperator );
        }

        //---------------------------------------------------------------------------------
        const String& UnaryExpression::operatorString( Operator op )
        {
            switch ( op )
            {

            case ADD:
                return OPERATOR_UNARY_ADD;

            case SUB:
                return OPERATOR_UNARY_SUB;

            case NOT:
                return OPERATOR_UNARY_NOT;
            }

            return OPERATOR_UNARY_ILLEGAL;
        }

        //---------------------------------------------------------------------------------
        void UnaryExpression::setOperator( const String& op )
        {
            if ( op == OPERATOR_UNARY_ADD )
            {
                mOperator = ADD;
            }

            else if ( op == OPERATOR_UNARY_SUB )
            {
                mOperator = SUB;
            }

            else if ( op == OPERATOR_UNARY_NOT )
            {
                mOperator = NOT;
            }
        }

        //---------------------------------------------------------------------------------
        INode* UnaryExpression::getOperand() const
        {
            return mOperand;
        }

        //---------------------------------------------------------------------------------
        void UnaryExpression::setOperand( INode* operand )
        {
            mOperand = operand;
        }

        //-----------------------------------------------------------------
        INode* UnaryExpression::clone(CloneFlags cloneFlags) const
        {
            UnaryExpression* copy = new UnaryExpression();
            copy->mOperator = mOperator;

            if ( mOperand )
                copy->mOperand = mOperand->clone(cloneFlags);
            else
                copy->mOperand = 0;

            return copy;
        }

    } //namespace AST

} //namespace MathML
