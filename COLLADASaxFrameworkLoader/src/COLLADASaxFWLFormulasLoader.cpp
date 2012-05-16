/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLFormulasLoader.h"

#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLCOLLADACsymbol.h"

#include "COLLADAFWFormula.h"
#include "COLLADAFWFormulaNewParam.h"

#include "GeneratedSaxParserUtils.h"

#include "MathMLASTUnaryArithmeticExpression.h"
#include "MathMLASTArithmeticExpression.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLASTVariableExpression.h"
#include "MathMLASTLogicExpression.h"
#include "MathMLASTBinaryComparisionExpression.h"
#include "MathMLASTFunctionExpression.h"
#include "MathMLParserConstants.h"


namespace COLLADASaxFWL
{

	//-----------------------------------------------------------------
	FormulasLoader::FormulasLoader( )
		: mCurrentFormula( 0 )
		, mSepOccurred( false )
		, mCurrentCSymbolFunctionUniqueId(COLLADAFW::UniqueId::INVALID)
		, mCurrentCSymbolIsFunction(false)
		, mCurrentApplyHasChild(false)
		, mWithinNewParam(false)
		, mCurrentFormulaNewParam(0)
	{
	}

	//-----------------------------------------------------------------
	FormulasLoader::~FormulasLoader()
	{
	}

    //-----------------------------------------------------------------
    const COLLADAFW::UniqueId& FormulasLoader::getUniqueId ()
    {
        if ( mCurrentFormula )
            return mCurrentFormula->getUniqueId ();
        return COLLADAFW::UniqueId::INVALID;
    }

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__formula( const formula__AttributeData& attributeData )
	{
		mCurrentFormula = FW_NEW COLLADAFW::Formula( getHandlingFilePartLoader()->createUniqueIdFromId( attributeData.id, COLLADAFW::Formula::ID()) );
		if ( attributeData.name )
			mCurrentFormula->setName( attributeData.name );
		else if ( attributeData.id )
			mCurrentFormula->setName( attributeData.id );
		else if ( attributeData.sid )
			mCurrentFormula->setName( attributeData.sid );

		if ( attributeData.id )
			mCurrentFormula->setOriginalId ( attributeData.id );

		getHandlingFilePartLoader()->addToSidTree( attributeData.id, attributeData.sid, mCurrentFormula );

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__formula()
	{
		getHandlingFilePartLoader()->getFileLoader()->addFormula( mCurrentFormula );
		mCurrentFormula = 0;
		getHandlingFilePartLoader()->moveUpInSidTree();

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__newparam( const formula_newparam_type__AttributeData& attributeData )
	{
		mWithinNewParam = true;
		if ( attributeData.sid )
		{
			mCurrentFormulaNewParamSid = attributeData.sid;
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__newparam()
	{
		COLLADAFW::FormulaNewParamPointerArray& newParams = mCurrentFormula->getNewParams();
		newParams.append(mCurrentFormulaNewParam);
		mWithinNewParam = false;
		mCurrentFormulaNewParamSid.clear();
		mCurrentFormulaNewParam = 0;
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__float()
	{
		if ( mWithinNewParam )
		{
			mCurrentFormulaNewParam = FW_NEW COLLADAFW::FormulaNewParam(COLLADAFW::FormulaNewParam::VALUETYPE_FLOAT);
			mCurrentFormulaNewParam->setName(mCurrentFormulaNewParamSid);
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__float()
	{
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::data__float( float value )
	{
		if ( mWithinNewParam )
		{
			mCurrentFormulaNewParam->setDoubleValue( value );
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__int()
	{
		if ( mWithinNewParam )
		{
			mCurrentFormulaNewParam = FW_NEW COLLADAFW::FormulaNewParam(COLLADAFW::FormulaNewParam::VALUETYPE_INT);
			mCurrentFormulaNewParam->setName(mCurrentFormulaNewParamSid);
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__int()
	{
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::data__int( int value )
	{
		if ( mWithinNewParam )
		{
			mCurrentFormulaNewParam->setIntValue( value );
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__bool()
	{
		if ( mWithinNewParam )
		{
			mCurrentFormulaNewParam = FW_NEW COLLADAFW::FormulaNewParam(COLLADAFW::FormulaNewParam::VALUETYPE_BOOL);
			mCurrentFormulaNewParam->setName(mCurrentFormulaNewParamSid);
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__bool()
	{
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::data__bool( bool value )
	{
		if ( mWithinNewParam )
		{
			mCurrentFormulaNewParam->setBoolValue( value );
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__math( const math__AttributeData& attributeData )
	{
		NodeVector newArray;
		mNodeListStack.push( newArray );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__math()
	{
		return end__apply();
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__apply( const apply__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = false;
		NodeVector newArray;
		mNodeListStack.push( newArray );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__apply()
	{
		mCurrentApplyHasChild = true;

		if ( mNodeListStack.empty() )
		{
			// TODO error handling
			return false;
		}

		NodeVector nodes = mNodeListStack.top();
		mNodeListStack.pop();
		size_t numOfNodes = nodes.size();

		if ( numOfNodes == 0 )
		{
			// TODO error handling
			return false;
		}

		if ( mOperatorStack.empty() )
		{
			mCurrentFormula->getMathmlAsts().allocMemory( nodes.size() );
			for (size_t i=0; i<nodes.size(); ++i)
			{
				mCurrentFormula->getMathmlAsts().append( nodes[ i ] );
			}
		}
		else
		{
			Operator op = mOperatorStack.top();
			mOperatorStack.pop();

			if ( isFunction( op ) )
			{
				MathML::AST::INode* node = createFunctionOperation( nodes, op );
				appendNewNode( node );
			}
			else if ( op == USER_DEFINED_FUNCTION )
			{
				MathML::AST::INode* node = createUserDefinedFunctionOperation( nodes );
				appendNewNode( node );
			}
			else
			{
				switch ( numOfNodes )
				{

				case 1:
					{
						MathML::AST::INode* node = createUnaryOperation( nodes, op );
						appendNewNode( node );
						break;
					}
				default:
					{
						MathML::AST::INode* node = createMultiOperandOperation( nodes, op );
						appendNewNode( node );
						break;
					}
				}
			}
		}

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::appendNewNode( MathML::AST::INode* node )
	{
		if ( node )
		{
			if ( mNodeListStack.empty() )
				mCurrentFormula->getMathmlAsts().append( node );
			else
				mNodeListStack.top().push_back( node );
		}
		else
		{
			// TODO error handling
		}
		return true;
	}

	//-----------------------------------------------------------------
	MathML::AST::INode* FormulasLoader::createUnaryOperation( const NodeVector& nodes, Operator op )
	{
		MathML::AST::UnaryExpression::Operator mmlOp;
		switch ( op )
		{
		case ADD:
			mmlOp = MathML::AST::UnaryExpression::ADD;
			break;
		case SUB:
			mmlOp = MathML::AST::UnaryExpression::SUB;
			break;
		case NOT:
			mmlOp = MathML::AST::UnaryExpression::NOT;
			break;
		default:
			// invalid operator
			return 0;
		}

		MathML::AST::UnaryExpression* expression = new MathML::AST::UnaryExpression();
		expression->setOperator( mmlOp );
		expression->setOperand( nodes[ 0 ] );

		return expression;
	}

	//-----------------------------------------------------------------
	MathML::AST::INode* FormulasLoader::createMultiOperandOperation( const NodeVector& nodes, Operator op )
	{
		MathML::AST::INode* node;
		switch ( op )
		{
		case ADD:
		case SUB:
		case MUL:
		case DIV:
			node = createArithmeticOperation( nodes, op );
			break;
		case AND:
		case OR:
		case XOR:
			node = createLogicOperation( nodes, op );
			break;
		case EQ:
		case NEQ:
		case LT:
		case LTE:
		case GT:
		case GTE:
			node = createBinaryComparisonOperation( nodes, op );
			break;
		default:
			// invalid operator
			node = 0;
		}

		return node;
	}

	//-----------------------------------------------------------------
	MathML::AST::INode* FormulasLoader::createArithmeticOperation( const NodeVector& nodes, Operator op )
	{
		MathML::AST::ArithmeticExpression::Operator mmlOp;
		switch ( op )
		{
		case ADD:
			mmlOp = MathML::AST::ArithmeticExpression::ADD;
			break;
		case SUB:
			mmlOp = MathML::AST::ArithmeticExpression::SUB;
			break;
		case MUL:
			mmlOp = MathML::AST::ArithmeticExpression::MUL;
			break;
		case DIV:
			mmlOp = MathML::AST::ArithmeticExpression::DIV;
			break;
		default:
			// invalid operator
			return 0;
		}

		MathML::AST::ArithmeticExpression* expression = new MathML::AST::ArithmeticExpression();
		expression->setOperator( mmlOp );
		for (size_t i=0; i<nodes.size(); ++i)
		{
			expression->addOperand( nodes[ i ] );
		}

		return expression;
	}

	//-----------------------------------------------------------------
	MathML::AST::INode* FormulasLoader::createLogicOperation( const NodeVector& nodes, Operator op )
	{
		MathML::AST::LogicExpression::Operator mmlOp;
		switch ( op )
		{
		case AND:
			mmlOp = MathML::AST::LogicExpression::AND;
			break;
		case OR:
			mmlOp = MathML::AST::LogicExpression::OR;
			break;
		case XOR:
			mmlOp = MathML::AST::LogicExpression::XOR;
			break;
		default:
			// invalid operator
			return 0;
		}

		MathML::AST::LogicExpression* expression = new MathML::AST::LogicExpression();
		expression->setOperator( mmlOp );
		for (size_t i=0; i<nodes.size(); ++i)
		{
			expression->addOperand( nodes[ i ] );
		}

		return expression;
	}

	//-----------------------------------------------------------------
	MathML::AST::INode* FormulasLoader::createBinaryComparisonOperation( const NodeVector& nodes, Operator op )
	{
		if ( nodes.size() != 2 )
		{
			// TODO error handling
			return 0;
		}

		MathML::AST::BinaryComparisonExpression::Operator mmlOp;
		switch ( op )
		{
		case EQ:
			mmlOp = MathML::AST::BinaryComparisonExpression::EQ;
			break;
		case NEQ:
			mmlOp = MathML::AST::BinaryComparisonExpression::NEQ;
			break;
		case LT:
			mmlOp = MathML::AST::BinaryComparisonExpression::LT;
			break;
		case LTE:
			mmlOp = MathML::AST::BinaryComparisonExpression::LTE;
			break;
		case GT:
			mmlOp = MathML::AST::BinaryComparisonExpression::GT;
			break;
		case GTE:
			mmlOp = MathML::AST::BinaryComparisonExpression::GTE;
			break;
		default:
			// invalid operator
			return 0;
		}

		MathML::AST::BinaryComparisonExpression* expression = new MathML::AST::BinaryComparisonExpression();
		expression->setOperator( mmlOp );
		expression->setLeftOperand( nodes[ 0 ] );
		expression->setRightOperand( nodes[ 1 ] );

		return expression;
	}

	//-----------------------------------------------------------------
	MathML::AST::INode* FormulasLoader::createFunctionOperation( const NodeVector& nodes, Operator op )
	{
		const MathML::String* functionName;
		switch ( op )
		{
		case POW:
			functionName = &MathML::FUNCTION_POW;
			break;
		case FACTORIAL:
			functionName = &MathML::FUNCTION_FACTORIAL;
			break;
		case ABS:
			functionName = &MathML::FUNCTION_ABS;
			break;
		case EXP:
			functionName = &MathML::FUNCTION_EXP;
			break;
		case LN:
			functionName = &MathML::FUNCTION_LOGN;
			break;
		case MIN:
			functionName = &MathML::FUNCTION_MIN;
			break;
		case MAX:
			functionName = &MathML::FUNCTION_MAX;
			break;
		case CEIL:
			functionName = &MathML::FUNCTION_CEILING;
			break;
		case FLOOR:
			functionName = &MathML::FUNCTION_FLOOR;
			break;
		case GCD:
			functionName = &MathML::FUNCTION_GCD;
			break;
		case LCM:
			functionName = &MathML::FUNCTION_LCM;
			break;
		case REM:
			functionName = &MathML::FUNCTION_REM;
			break;
		case ROOT:
			functionName = &MathML::FUNCTION_ROOT;
			break;
		case LOG:
			functionName = &MathML::FUNCTION_LOG;
			break;
		case SIN:
			functionName = &MathML::FUNCTION_SIN;
			break;
		case COS:
			functionName = &MathML::FUNCTION_COS;
			break;
		case TAN:
			functionName = &MathML::FUNCTION_TAN;
			break;
		case SEC:
			functionName = &MathML::FUNCTION_SEC;
			break;
		case CSC:
			functionName = &MathML::FUNCTION_CSC;
			break;
		case COT:
			functionName = &MathML::FUNCTION_COT;
			break;
		case ARCSIN:
			functionName = &MathML::FUNCTION_ARCSIN;
			break;
		case ARCCOS:
			functionName = &MathML::FUNCTION_ARCCOS;
			break;
		case ARCTAN:
			functionName = &MathML::FUNCTION_ARCTAN;
			break;
		case ARCSEC:
			functionName = &MathML::FUNCTION_ARCSEC;
			break;
		case ARCCSC:
			functionName = &MathML::FUNCTION_ARCCSC;
			break;
		case ARCCOT:
			functionName = &MathML::FUNCTION_ARCCOT;
			break;
		case SINH:
			functionName = &MathML::FUNCTION_SINH;
			break;
		case COSH:
			functionName = &MathML::FUNCTION_COSH;
			break;
		case TANH:
			functionName = &MathML::FUNCTION_TANH;
			break;
		case SECH:
			functionName = &MathML::FUNCTION_SECH;
			break;
		case CSCH:
			functionName = &MathML::FUNCTION_CSCH;
			break;
		case COTH:
			functionName = &MathML::FUNCTION_COTH;
			break;
		case ARCSINH:
			functionName = &MathML::FUNCTION_ARCSINH;
			break;
		case ARCCOSH:
			functionName = &MathML::FUNCTION_ARCCOSH;
			break;
		case ARCTANH:
			functionName = &MathML::FUNCTION_ARCTANH;
			break;
		case ARCCOTH:
			functionName = &MathML::FUNCTION_ARCCOTH;
			break;
		case ARCSECH:
			functionName = &MathML::FUNCTION_ARCSECH;
			break;
		case ARCCSCH:
			functionName = &MathML::FUNCTION_ARCCSCH;
			break;
		default:
			// invalid operator
			return 0;
		}

		MathML::AST::FunctionExpression* expression = new MathML::AST::FunctionExpression( *functionName );
		expression->setParameterList( nodes );

		return expression;
	}


	//-----------------------------------------------------------------
	MathML::AST::INode* FormulasLoader::createUserDefinedFunctionOperation( const NodeVector& nodes )
	{
		COLLADABU_ASSERT(!nodes.empty());
		MathML::AST::INode* firstNode = nodes.front();

		COLLADABU_ASSERT( firstNode->getNodeType() == MathML::AST::INode::USERDEFINED);
		COLLADACsymbol* csymbol = (COLLADACsymbol*)firstNode;
		size_t nodesCount = nodes.size();
		if ( nodesCount > 1)
		{
			//we have parameters. copy them into csymbol
			COLLADACsymbol::ParameterList& parameterList = csymbol->getParameterList();
			parameterList.reserve( nodesCount - 1 );
			NodeVector::const_iterator it = nodes.begin() + 1;
			for ( ; it != nodes.end(); ++it)
			{
				parameterList.push_back(*it);
			}
		}

		return csymbol;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::isFunction( Operator op )
	{
		switch ( op )
		{
		case POW:
		case FACTORIAL:
		case ABS:
		case EXP:
		case LN:
		case MIN:
		case MAX:
		case CEIL:
		case FLOOR:
		case GCD:
		case LCM:
		case REM:
		case ROOT:
		case LOG:
		case SIN:
		case COS:
		case TAN:
		case SEC:
		case CSC:
		case COT:
		case ARCSIN:
		case ARCCOS:
		case ARCTAN:
		case ARCSEC:
		case ARCCSC:
		case ARCCOT:
		case SINH:
		case COSH:
		case TANH:
		case SECH:
		case CSCH:
		case COTH:
		case ARCSINH:
		case ARCCOSH:
		case ARCTANH:
		case ARCCOTH:
		case ARCSECH:
		case ARCCSCH:
			return true;
		default:
			return false;
		}
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__quotient( const quotient__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( DIV );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__divide( const divide__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( DIV );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__minus( const minus__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( SUB );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__plus( const plus__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ADD );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__times( const times__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( MUL );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__sum( const sum__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ADD );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__product( const product__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( MUL );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__cn( const cn__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__cn()
	{
		MathML::AST::INode* node;

		if ( mSepOccurred )
		{
			// TODO support for other types than rational
			MathML::AST::ConstantExpression* constant1 = createConstant( mCurrentTextData );
			MathML::AST::ConstantExpression* constant2 = createConstant( mCurrentTextDataAfterSep );
			MathML::AST::ArithmeticExpression* expression = new MathML::AST::ArithmeticExpression();
			expression->setOperator( MathML::AST::ArithmeticExpression::DIV );
			expression->addOperand( constant1 );
			expression->addOperand( constant2 );
			node = expression;
		}
		else
		{
			MathML::AST::ConstantExpression* constant = createConstant( mCurrentTextData );
			node = constant;
		}

		mNodeListStack.top().push_back( node );
		mSepOccurred = false;
		mCurrentTextDataAfterSep.clear();
		mCurrentTextData.clear();

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::data__cn( const ParserChar* value, size_t length )
	{
		if ( mSepOccurred )
		{
			mCurrentTextDataAfterSep.append( value, length );
		}
		else
		{
			mCurrentTextData.append( value, length );
		}
		return true;
	}

	//-----------------------------------------------------------------
	MathML::AST::ConstantExpression* FormulasLoader::createConstant( const String& value )
	{
		MathML::AST::ConstantExpression* constant = FW_NEW MathML::AST::ConstantExpression( value );

		bool failed = false;
		double doubleValue = GeneratedSaxParser::Utils::toDouble( value.c_str(), failed );
		if ( !failed )
		{
			constant->setValue( doubleValue );
		}
		else
		{
			bool boolValue = GeneratedSaxParser::Utils::toBool( value.c_str(), failed );
			if ( !failed )
			{
				constant->setValue( boolValue );
			}
		}

		return constant;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__ci( const ci__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__ci()
	{
		MathML::AST::VariableExpression* variable = FW_NEW MathML::AST::VariableExpression( mCurrentTextData );
		mCurrentTextData.clear();
		mNodeListStack.top().push_back( variable );

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::data__ci( const ParserChar* value, size_t length )
	{
		mCurrentTextData.append( value, length );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__csymbol( const csymbol__AttributeData& attributeData )
	{
		if ( !mCurrentApplyHasChild )
		{
			// The csymbol appears as first child of apply. I must be a user defined function.
			mOperatorStack.push(USER_DEFINED_FUNCTION);
			mCurrentCSymbolIsFunction = true;
			if (attributeData.definitionURL)
			{
				mCurrentCSymbolFunctionUniqueId = getHandlingFilePartLoader()->createUniqueIdFromUrl(attributeData.definitionURL, COLLADAFW::Formula::ID());
			}
		}
		mCurrentApplyHasChild = true;
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__csymbol()
	{
		COLLADACsymbol* csymbol = 0;
		if ( mCurrentCSymbolIsFunction )
		{
			csymbol = FW_NEW COLLADACsymbol( mCurrentTextData, mCurrentCSymbolFunctionUniqueId );
		}
		else
		{
			csymbol = FW_NEW COLLADACsymbol( mCurrentTextData);
		}
		mCurrentTextData.clear(); 
		mNodeListStack.top().push_back( csymbol );
		mCurrentCSymbolIsFunction = false;
		mCurrentCSymbolFunctionUniqueId = COLLADAFW::UniqueId::INVALID;
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::data__csymbol( const ParserChar* value, size_t length )
	{
		mCurrentTextData.append( value, length );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__exponentiale( const exponentiale__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		MathML::AST::ConstantExpression* constant = FW_NEW MathML::AST::ConstantExpression( MathML::EULERS_NUMBER );
		mNodeListStack.top().push_back( constant );

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__pi( const pi__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		MathML::AST::ConstantExpression* constant = FW_NEW MathML::AST::ConstantExpression( MathML::PI_NUMBER );
		mNodeListStack.top().push_back( constant );

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__true( const true__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		MathML::AST::ConstantExpression* constant = FW_NEW MathML::AST::ConstantExpression( true );
		mNodeListStack.top().push_back( constant );

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__false( const false__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		MathML::AST::ConstantExpression* constant = FW_NEW MathML::AST::ConstantExpression( false );
		mNodeListStack.top().push_back( constant );

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__and( const and__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( AND);
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__or( const or__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( OR );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__xor( const xor__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( XOR );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__not( const not__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( NOT );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__eq( const eq__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( EQ );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__neq( const neq__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( NEQ );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__leq( const leq__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( LTE );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__lt( const lt__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( LT );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__geq( const geq__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( GTE );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__gt( const gt__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( GT );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__equivalent( const equivalent__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( EQ );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__abs( const abs__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ABS );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__factorial( const factorial__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( FACTORIAL );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__floor( const floor__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( FLOOR );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__ceiling( const ceiling__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( CEIL );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__rem( const rem__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( REM );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__power( const power__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( POW );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__root( const root__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ROOT );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__max( const max__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( MAX );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__min( const min__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( MIN );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__gcd( const gcd__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( GCD );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__lcm( const lcm__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( LCM );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__exp( const exp__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( EXP );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__ln( const ln__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( LN );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__log( const log__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( LOG );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__logbase( const logbase__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		NodeVector newArray;
		mNodeListStack.push( newArray );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::end__logbase()
	{
		if ( mNodeListStack.empty() )
		{
			// TODO error handling
			return false;
		}

		NodeVector nodes = mNodeListStack.top();
		mNodeListStack.pop();
		size_t numOfNodes = nodes.size();

		if ( numOfNodes == 0 )
		{
			// TODO error handling
			return false;
		}

		appendNewNode( nodes[ 0 ] );

		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__sin( const sin__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( SIN );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__cos( const cos__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( COS );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__tan( const tan__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( TAN );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__sec( const sec__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( SEC );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__csc( const csc__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( CSC );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__cot( const cot__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( COT );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arcsin( const arcsin__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCSIN );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arccos( const arccos__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCCOS );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arctan( const arctan__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCTAN );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arcsec( const arcsec__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCSEC );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arccsc( const arccsc__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCCSC );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arccot( const arccot__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCCOT );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__sinh( const sinh__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( SINH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__cosh( const cosh__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( COSH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__tanh( const tanh__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( TANH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__sech( const sech__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( SECH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__csch( const csch__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( CSCH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__coth( const coth__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( COTH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arccosh( const arccosh__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCCOSH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arccoth( const arccoth__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCCOTH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arccsch( const arccsch__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCCSCH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arcsech( const arcsech__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCSECH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arcsinh( const arcsinh__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCSINH );
		return true;
	}

	//-----------------------------------------------------------------
	bool FormulasLoader::begin__arctanh( const arctanh__AttributeData& attributeData )
	{
		mCurrentApplyHasChild = true;
		mOperatorStack.push( ARCTANH );
		return true;
	}

} // namespace COLLADASaxFWL
