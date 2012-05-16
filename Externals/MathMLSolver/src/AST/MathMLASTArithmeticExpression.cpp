#include "MathMLSolverStableHeaders.h"
#include "MathMLASTArithmeticExpression.h"

namespace MathML
{

    namespace AST
    {
        //---------------------------------------------------------------------------------
        ArithmeticExpression::ArithmeticExpression()
            : mOperator( ADD )
        {}

        //---------------------------------------------------------------------------------
        ArithmeticExpression::~ArithmeticExpression()
        {
            for (size_t i=0; i<mOperands.size(); ++i)
            {
                delete mOperands.at( i );
            }
        }

        //---------------------------------------------------------------------------------
        void ArithmeticExpression::accept( IVisitor* visitor ) const
        {
            visitor->visit( this );
        }

        //---------------------------------------------------------------------------------
        ArithmeticExpression::Operator ArithmeticExpression::getOperator() const
        {
            return mOperator;
        }

        //---------------------------------------------------------------------------------
        void ArithmeticExpression::setOperator( Operator op )
        {
            mOperator = op;
        }

        //---------------------------------------------------------------------------------
        const String& ArithmeticExpression::getOperatorString() const
        {
            return operatorString( mOperator );
        }

        //---------------------------------------------------------------------------------
        const String& ArithmeticExpression::operatorString( Operator op )
        {
            switch ( op )
            {

            case ADD:
                return OPERATOR_ARITHMETIC_ADD;

            case SUB:
                return OPERATOR_ARITHMETIC_SUB;

            case MUL:
                return OPERATOR_ARITHMETIC_MUL;

            case DIV:
                return OPERATOR_ARITHMETIC_DIV;
            }

            return OPERATOR_ARITHMETIC_ILLEGAL;
        }

        //---------------------------------------------------------------------------------
        void ArithmeticExpression::setOperator( const String& op )
        {
            if ( op == OPERATOR_ARITHMETIC_ADD )
            {
                mOperator = ADD;
            }

            else if ( op == OPERATOR_ARITHMETIC_SUB )
            {
                mOperator = SUB;
            }

            else if ( op == OPERATOR_ARITHMETIC_MUL )
            {
                mOperator = MUL;
            }

            else if ( op == OPERATOR_ARITHMETIC_DIV )
            {
                mOperator = DIV;
            }
        }

		//---------------------------------------------------------------------------------
		const NodeList& ArithmeticExpression::getOperands() const
		{
			return mOperands;
		}

		//---------------------------------------------------------------------------------
		NodeList& ArithmeticExpression::getOperands()
		{
			return mOperands;
		}

        //---------------------------------------------------------------------------------
        void ArithmeticExpression::addOperand( INode* operand )
        {
            mOperands.push_back( operand );
        }

        //-----------------------------------------------------------------
        INode* ArithmeticExpression::clone(CloneFlags cloneFlags) const
        {
            ArithmeticExpression* copy = new ArithmeticExpression();
            copy->mOperator = mOperator;
            for (size_t i=0; i<mOperands.size(); ++i)
            {
                copy->mOperands.push_back( mOperands.at( i )->clone(cloneFlags) );
            }
            return copy;
        }

    } //namespace AST

} //namespace MathML
