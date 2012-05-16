#include "MathMLSolverStableHeaders.h"
#include "MathMLEvaluatorVisitor.h"

//#define DEFAULT_VARIABLE_VALUE_1

namespace MathML
{
    //----------------------------------------------------------------------------
    EvaluatorVisitor::EvaluatorVisitor( SymbolTable& symbolTable, ErrorHandler* errorHandler )
            : mBranchValue ( 0.0 )
			, mSymbolTable ( symbolTable )
            , mErrorHandler ( errorHandler )
    {}

    //----------------------------------------------------------------------------
    EvaluatorVisitor::~EvaluatorVisitor()
    {}

    //----------------------------------------------------------------------------
    const AST::ConstantExpression& EvaluatorVisitor::getValue()
    {
        return mBranchValue;
    }

    //----------------------------------------------------------------------------
    void EvaluatorVisitor::visit( const AST::ArithmeticExpression* const node )
    {
        AST::ArithmeticExpression::Operator op = node->getOperator();
        AST::NodeList operands = node->getOperands();
        AST::NodeList::iterator it;

        AST::ConstantExpression prevBranchValue;
        it = operands.begin();

        // evaluate first operand and set temporary branch value

        if ( it != operands.end() )
        {
            ( *it ) ->accept( this );
            ++it;
        }

        // evaluate other operands AND apply operation
        for ( ; it != operands.end(); ++it )
        {
            prevBranchValue = mBranchValue;
            ( *it ) ->accept( this );

            switch ( op )
            {

            case AST::ArithmeticExpression::ADD:
                mBranchValue = prevBranchValue + mBranchValue;
                break;

            case AST::ArithmeticExpression::SUB:
                mBranchValue = prevBranchValue - mBranchValue;
                break;

            case AST::ArithmeticExpression::MUL:
                mBranchValue = prevBranchValue * mBranchValue;
                break;

            case AST::ArithmeticExpression::DIV:
                mBranchValue = prevBranchValue / mBranchValue;
                break;

            default:
                //@todo: exception handling
                break;
            }
        }
    }

    //----------------------------------------------------------------------------
    void EvaluatorVisitor::visit( const AST::BinaryComparisonExpression* const node )
    {
        AST::BinaryComparisonExpression::Operator op = node->getOperator();

        AST::ConstantExpression prevBranchValue;

        // evaluate first operand and set temporary branch value
        ( node->getLeftOperand() ) ->accept( this );

        // evaluate second operand AND apply operation
        prevBranchValue = mBranchValue;
        ( node->getRightOperand() ) ->accept( this );

        switch ( op )
        {

        case AST::BinaryComparisonExpression::EQ:
            mBranchValue = prevBranchValue == mBranchValue;
            break;

        case AST::BinaryComparisonExpression::NEQ:
            mBranchValue = prevBranchValue != mBranchValue;
            break;

        case AST::BinaryComparisonExpression::LTE:
            mBranchValue = prevBranchValue <= mBranchValue;
            break;

        case AST::BinaryComparisonExpression::GTE:
            mBranchValue = prevBranchValue >= mBranchValue;
            break;

        case AST::BinaryComparisonExpression::LT:
            mBranchValue = prevBranchValue < mBranchValue;
            break;

        case AST::BinaryComparisonExpression::GT:
            mBranchValue = prevBranchValue > mBranchValue;
            break;

        default:
            //@todo: exception handling
            break;
        }

    }

    //----------------------------------------------------------------------------
    void EvaluatorVisitor::visit( const AST::FragmentExpression* const node )
    {
        AST::INode* fragment = node->getFragment();

        // save state of symbol table
        SymbolTable scopeTable = mSymbolTable;

        AST::FragmentExpression::ParameterMap params = node->getParameterMap();
        AST::FragmentExpression::ParameterMap::iterator it;

        // temporary store params in symbol table

        for ( it = params.begin(); it != params.end(); ++it )
        {
            const String& paramName = it->first;
            AST::INode* node = it->second;

            scopeTable.setVariable( paramName, node );
        }

        // evaluate fragment
		if( fragment != 0 )
		{
			EvaluatorVisitor evaluator( scopeTable, mErrorHandler );
			fragment->accept( &evaluator );
			mBranchValue = evaluator.getValue();
		}
		else
		{
			std::ostringstream desc;
			desc << "Symbol " << node->getName() << " not declared!";
            if ( mErrorHandler )
            {
                Error err( Error::ERR_ITEM_NOT_FOUND, desc.str() );
                mErrorHandler->handleError( &err );
            }
		}


        // restore state of symbol table
        // mSymbolTable = saveTable;
    }

    //----------------------------------------------------------------------------
    void EvaluatorVisitor::visit( const AST::LogicExpression* const node )
    {
        AST::LogicExpression::Operator op = node->getOperator();
        AST::NodeList operands = node->getOperands();
        AST::NodeList::iterator it;

        AST::ConstantExpression prevBranchValue;
        it = operands.begin();

        // evaluate first operand and set temporary branch value

        if ( it != operands.end() )
        {
            ( *it ) ->accept( this );
            ++it;
        }

        // evaluate other operands AND apply operation
        for ( ; it != operands.end(); ++it )
        {
            prevBranchValue = mBranchValue;
            ( *it ) ->accept( this );

            switch ( op )
            {

            case AST::LogicExpression::AND:
                mBranchValue = prevBranchValue && mBranchValue;
                break;

            case AST::LogicExpression::OR:
                mBranchValue = prevBranchValue || mBranchValue;
                break;

            case AST::LogicExpression::XOR:
                mBranchValue = prevBranchValue ^ mBranchValue;
                break;

            default:
                //@todo: exception handling
                break;
            }
        }

    }

    //----------------------------------------------------------------------------
    void EvaluatorVisitor::visit( const AST::ConstantExpression* const node )
    {
        // returning the value of the scalar
        mBranchValue = *( node );
    }

    //----------------------------------------------------------------------------
    void EvaluatorVisitor::visit( const AST::FunctionExpression* const node )
    {
        ScalarList evaluatedArgs;
        AST::NodeList params = node->getParameterList();

        for ( unsigned int i = 0; i < params.size(); ++i )
        {
            AST::INode* argNode = params[ i ];
            argNode->accept( this );
            evaluatedArgs.push_back( mBranchValue );
        }

        //process function
        mSymbolTable.evaluateFunction( mBranchValue, node->getName(), evaluatedArgs );
    }

    //----------------------------------------------------------------------------
    void EvaluatorVisitor::visit( const AST::UnaryExpression* const node )
    {
        AST::UnaryExpression::Operator op = node->getOperator();

        // evaluate only operand
        ( node->getOperand() ) ->accept( this );

        // apply operation

        switch ( op )
        {

        case AST::UnaryExpression::ADD:
            //do nothing
            break;

        case AST::UnaryExpression::SUB:
            mBranchValue = -mBranchValue;
            break;

        case AST::UnaryExpression::NOT:
            mBranchValue = !mBranchValue;
            break;

        default:
            //@todo: exception handling
            break;
        }

    }

    //----------------------------------------------------------------------------
    void EvaluatorVisitor::visit( const AST::VariableExpression* const node )
    {
        // check symbol table for variable
        AST::INode* variableNode = mSymbolTable.getVariable( node->getName() );

        if ( variableNode != 0 )
        {
            variableNode->accept( this );
            return ;
        }

        //variable not found
        std::stringstream oss;

        oss << "variable '" << node->getName() << "' could not be found!";

        if ( mErrorHandler )
        {
            Error err( Error::ERR_INVALIDPARAMS, oss.str() );
            mErrorHandler->handleError( &err );
        }
        mBranchValue.setValue( 0. );
    }

} //namespace MathML
