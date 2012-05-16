/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWFormulas.h"

#include "MathMLASTNode.h"
#include "MathMLASTArithmeticExpression.h"
#include "MathMLASTBinaryComparisionExpression.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLASTFragmentExpression.h"
#include "MathMLASTFunctionExpression.h"
#include "MathMLASTLogicExpression.h"
#include "MathMLASTUnaryArithmeticExpression.h"
#include "MathMLASTVariableExpression.h"


namespace COLLADAFW
{

	//------------------------------
	void setFragments( MathML::AST::INode* astNode, const Formula::ASTNodeASTNodeMap& originalClonedASTNodeMap)
	{
		switch ( astNode->getNodeType() )
		{
		case MathML::AST::INode::ARITHMETIC:
			{
				MathML::AST::ArithmeticExpression* arithmetic = (MathML::AST::ArithmeticExpression*)astNode;
				MathML::AST::NodeList& operands = arithmetic->getOperands();
				for ( size_t i = 0, count = operands.size(); i < count; ++i )
				{
					setFragments(operands[i], originalClonedASTNodeMap);
				}
				break;
			}
		case MathML::AST::INode::COMPARISON:
			{
				MathML::AST::BinaryComparisonExpression* comparison = (MathML::AST::BinaryComparisonExpression*)astNode;
				setFragments(comparison->getLeftOperand(), originalClonedASTNodeMap);
				setFragments(comparison->getRightOperand(), originalClonedASTNodeMap);
				break;
			}
		case MathML::AST::INode::CONSTANT:
		case MathML::AST::INode::VARIABLE:
			break;
		case MathML::AST::INode::FRAGMENT:
			{
				MathML::AST::FragmentExpression* fragment = (MathML::AST::FragmentExpression*)astNode;
				MathML::AST::INode* fragmentNode = fragment->getFragment();
				Formula::ASTNodeASTNodeMap::const_iterator it = originalClonedASTNodeMap.find(fragmentNode);
				COLLADABU_ASSERT( it != originalClonedASTNodeMap.end() );
				fragment->setFragment( it->second );
				break;
			}
		case MathML::AST::INode::LOGICAL:
			{
				MathML::AST::LogicExpression* logical = (MathML::AST::LogicExpression*)astNode;
				MathML::AST::NodeList& operands = logical->getOperands();
				for ( size_t i = 0, count = operands.size(); i < count; ++i )
				{
					setFragments(operands[i], originalClonedASTNodeMap);
				}
				break;
			}
		case MathML::AST::INode::UNARY:
			{
				MathML::AST::UnaryExpression* unary = (MathML::AST::UnaryExpression*)astNode;
				setFragments(unary->getOperand(), originalClonedASTNodeMap);
				break;
			}
		case MathML::AST::INode::FUNCTION:
			{
				MathML::AST::FunctionExpression* func = (MathML::AST::FunctionExpression*)astNode;
				MathML::AST::NodeList& operands = func->getParameterList();
				for ( size_t i = 0, count = operands.size(); i < count; ++i )
				{
					setFragments(operands[i], originalClonedASTNodeMap);
				}
				break;
			}
		default:
			COLLADABU_ASSERT(false);
		}

	}

    //------------------------------
	Formulas::Formulas(  )
		: mFormulas( FormulaArray::OWNER )
	{
	}

	//------------------------------
	Formulas::Formulas( const Formulas& rhs )
		: mFormulas( FormulaArray::OWNER )
	{
		Formula::ASTNodeASTNodeMap originalClonedASTNodeMap;
		size_t count = rhs.mFormulas.getCount();
		mFormulas.reallocMemory(count);
		for ( size_t i = 0; i < count; ++i )
		{
			mFormulas[i] = rhs.mFormulas[i]->clone( originalClonedASTNodeMap );
		}
		mFormulas.setCount(count);

		for ( size_t i = 0; i < count; ++i )
		{
			const MathmlAstArray& asts = mFormulas[i]->getMathmlAsts();
			// second step: set fragments to corresponding formula ast
			for ( size_t j = 0, count = asts.getCount(); j < count; ++j )
			{
				setFragments(asts[j], originalClonedASTNodeMap);
			}
		}
	}
    //------------------------------
	Formulas::~Formulas()
	{
		for ( size_t i = 0, count = mFormulas.getCount(); i < count; ++i )
		{
			FW_DELETE mFormulas[i];
		}
	}

} // namespace COLLADAFW
