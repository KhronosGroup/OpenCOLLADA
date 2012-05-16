#include "MathMLSolverStableHeaders.h"
#include "MathMLASTLogicExpression.h"

namespace MathML
{

    namespace AST
    {
        //---------------------------------------------------------------------------------
        LogicExpression::LogicExpression()
            : mOperator( AND )
        {}

        //---------------------------------------------------------------------------------
        LogicExpression::~LogicExpression()
        {
            for (size_t i=0; i<mOperands.size(); ++i)
            {
                delete mOperands.at( i );
            }
        }

        //---------------------------------------------------------------------------------
        void LogicExpression::accept( IVisitor* visitor ) const
        {
            visitor->visit( this );
        }

        //---------------------------------------------------------------------------------
        LogicExpression::Operator LogicExpression::getOperator() const
        {
            return mOperator;
        }

        //---------------------------------------------------------------------------------
        void LogicExpression::setOperator( Operator op )
        {
            mOperator = op;
        }

        //---------------------------------------------------------------------------------
        String LogicExpression::getOperatorString() const
        {
            return operatorString( mOperator );
        }

        //---------------------------------------------------------------------------------
        String LogicExpression::operatorString( Operator op )
        {
            switch ( op )
            {

            case AND:
                return OPERATOR_LOGIC_AND;

            case OR:
                return OPERATOR_LOGIC_OR;

            case XOR:
                return OPERATOR_LOGIC_XOR;
            }

            return OPERATOR_LOGIC_ILLEGAL;
        }

        //---------------------------------------------------------------------------------
        void LogicExpression::setOperator( const String& op )
        {
            if ( op == OPERATOR_LOGIC_AND )
            {
                mOperator = AND;
            }

            else if ( op == OPERATOR_LOGIC_OR )
            {
                mOperator = OR;
            }

            else if ( op == OPERATOR_LOGIC_XOR )
            {
                mOperator = XOR;
            }
        }

		//---------------------------------------------------------------------------------
		const NodeList& LogicExpression::getOperands() const
		{
			return mOperands;
		}

		//---------------------------------------------------------------------------------
		NodeList& LogicExpression::getOperands()
		{
			return mOperands;
		}

        //---------------------------------------------------------------------------------
        void LogicExpression::addOperand( INode* operand )
        {
            mOperands.push_back( operand );
        }

        //-----------------------------------------------------------------
        INode* LogicExpression::clone(CloneFlags cloneFlags) const
        {
            LogicExpression* copy = new LogicExpression();
            copy->mOperator = mOperator;
            for (size_t i=0; i<mOperands.size(); ++i)
            {
                copy->mOperands.push_back( mOperands.at( i )->clone(cloneFlags) );
            }
            return copy;
        }

    } //namespace AST

} //namespace MathML
