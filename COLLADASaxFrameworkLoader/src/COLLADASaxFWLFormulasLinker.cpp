/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLFormulasLinker.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADASaxFWLSidTreeNode.h"
#include "COLLADASaxFWLCOLLADACsymbol.h"
#include "COLLADASaxFWLFileLoader.h"

#include "MathMLASTNode.h"
#include "MathMLASTArithmeticExpression.h"
#include "MathMLASTBinaryComparisionExpression.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLASTFragmentExpression.h"
#include "MathMLASTFunctionExpression.h"
#include "MathMLASTLogicExpression.h"
#include "MathMLASTUnaryArithmeticExpression.h"
#include "MathMLASTVariableExpression.h"

namespace COLLADASaxFWL
{

    //------------------------------
	FormulasLinker::FormulasLinker( DocumentProcessor* documentProcessor, COLLADAFW::FormulaArray& formulas )
		: mDocumentProcessor(documentProcessor)
		, mFormulas(formulas)
	{
	}

    //------------------------------
	FormulasLinker::~FormulasLinker()
	{
	}

	//------------------------------
	bool FormulasLinker::link()
	{
		size_t formulasCount = mFormulas.getCount();
		for ( size_t i = 0; i < formulasCount; ++i)
		{
			COLLADAFW::Formula* formula = mFormulas[i];
			COLLADAFW::MathmlAstArray& asts = formula->getMathmlAsts();
			size_t astsCount = asts.getCount();
			for ( size_t j = 0; j < astsCount; ++j)
			{
				MathML::AST::INode*& astNode =  asts[j];
				bool success = true;
				astNode = link( formula, astNode, success);
				if ( !success )
					return false;
			}
		}
		return true;
	}

	//------------------------------
	MathML::AST::INode* FormulasLinker::link( COLLADAFW::Formula* formula, MathML::AST::INode* astNode, bool& success)
	{
		switch ( astNode->getNodeType() )
		{
		case MathML::AST::INode::ARITHMETIC:
			{
				MathML::AST::ArithmeticExpression* arithmetic = (MathML::AST::ArithmeticExpression*)astNode;
				MathML::AST::NodeList& operands = arithmetic->getOperands();
				for ( size_t i = 0, count = operands.size(); i < count; ++i )
				{
					operands[i] = link(formula, operands[i], success);
				}
			}
			return astNode;
		case MathML::AST::INode::COMPARISON:
			{
				MathML::AST::BinaryComparisonExpression* comparison = (MathML::AST::BinaryComparisonExpression*)astNode;
				comparison->setLeftOperand(link(formula, comparison->getLeftOperand(), success));
				comparison->setRightOperand(link(formula, comparison->getRightOperand(), success));
			}
			return astNode;
		case MathML::AST::INode::CONSTANT:
		case MathML::AST::INode::VARIABLE:
			success = true;
			return astNode;
		case MathML::AST::INode::FRAGMENT:
			{
				MathML::AST::FragmentExpression* fragment = (MathML::AST::FragmentExpression*)astNode;
				fragment->setFragment( link( formula, fragment->getFragment(), success) );
			}
			return astNode;
		case MathML::AST::INode::LOGICAL:
			{
				MathML::AST::LogicExpression* logical = (MathML::AST::LogicExpression*)astNode;
				MathML::AST::NodeList& operands = logical->getOperands();
				for ( size_t i = 0, count = operands.size(); i < count; ++i )
				{
					operands[i] = link(formula, operands[i], success);
				}
			}
			return astNode;
		case MathML::AST::INode::UNARY:
			{
				MathML::AST::UnaryExpression* unary = (MathML::AST::UnaryExpression*)astNode;
				unary->setOperand(link(formula, unary->getOperand(), success));
			}
			return astNode;
		case MathML::AST::INode::FUNCTION:
			{
				MathML::AST::FunctionExpression* func = (MathML::AST::FunctionExpression*)astNode;
				MathML::AST::NodeList& operands = func->getParameterList();
				for ( size_t i = 0, count = operands.size(); i < count; ++i )
				{
					operands[i] = link(formula, operands[i], success);
				}
			}
			return astNode;
		case MathML::AST::INode::USERDEFINED:
			{
				COLLADACsymbol* csymbol = (COLLADACsymbol*) astNode;
				MathML::AST::INode* linkedNode = link( formula, csymbol, success );
				delete csymbol;
				return linkedNode;
			}
		default:
			COLLADABU_ASSERT(false);
		}
		return 0;
	}

	//------------------------------
	MathML::AST::INode* FormulasLinker::link( COLLADAFW::Formula* formula, COLLADACsymbol* csymbol, bool& success)
	{
		const SidAddress& targetAddress = csymbol->getSidAddress();

		const String* csymbolName = 0;
		// if the address consist of a single word, this is considered to be the csymbol name.
		if ( !targetAddress.getId().empty() && 
			targetAddress.getSids().empty() && 
			targetAddress.getMemberSelection() == SidAddress::MEMBER_SELECTION_NONE )
		{
			csymbolName = &targetAddress.getId();
		}

		if ( csymbol->getCSymbolType() == COLLADACsymbol::FUNCTION )
		{
			const COLLADAFW::UniqueId& formulaUniqueId = csymbol->getFormulaUniqueId();

			COLLADAFW::Formula* targetFormula = mDocumentProcessor->getFormulaByUniqueId(formulaUniqueId);
		
			MathML::AST::FragmentExpression* fragmentExpression = 0;

			if ( targetFormula )
			{
				// find a suitable name for the fragment expression
				// if possible use the string in the csymbol element, otherwise the name of the referenced fromula
				const String* fragmentExpressionName = 0;
				fragmentExpressionName = csymbolName ? csymbolName : &targetFormula->getName();

				fragmentExpression = new MathML::AST::FragmentExpression(*fragmentExpressionName, MathML::AST::INode::CLONEFLAG_DEEPCOPY_FRAGMENT_PARAMS);
				COLLADAFW::MathmlAstArray& asts = targetFormula->getMathmlAsts();
				if ( asts.getCount() == 1)
				{
					// we have to ensure, that the fragment won't change anymore. Therefore we need to link immediately
					bool fragmentSuccess = true;
					asts[0] = link( targetFormula, asts[0], fragmentSuccess);
					fragmentExpression->setFragment( asts[0] );
					if ( !fragmentSuccess )
					{
						return false;
					}
				}
				const COLLADACsymbol::ParameterList& parameters =  csymbol->getParameterList();
				const COLLADAFW::FormulaNewParamPointerArray& targetFormulaParameters = targetFormula->getNewParams();
				if ( parameters.size() != targetFormulaParameters.getCount() )
				{
					String msg = "Number of newparams in formula \"" + *fragmentExpressionName;
					const String& formulaName = formula->getName();
					if ( !formulaName.empty() )
					{
						msg.append( "referenced in \"" + formulaName + "\" ");
					}
					msg.append( "does not match parameters count." );

					success = mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_PARAMETER_COUNT_DOESNOT_MATCH, msg);
				}
				else
				{
					COLLADACsymbol::ParameterList::const_iterator it = parameters.begin();
					for ( size_t i = 0; it!=parameters.end(); ++it, ++i )
					{
						const COLLADAFW::FormulaNewParam* parameter = targetFormulaParameters[i];
						fragmentExpression->addParameter(parameter->getName(), link( formula, *it, success));
						if ( !success )
						{
							break;
						}
					}
				}
			}
			else
			{
				// formula not found
				fragmentExpression = new MathML::AST::FragmentExpression(targetAddress.getSidAddressString(), MathML::AST::INode::CLONEFLAG_DEEPCOPY_FRAGMENT_PARAMS);

				String msg = "Formula with unique id\"" + formulaUniqueId.toAscii() + "\" ";
				msg.append( "could not be found." );

				success = mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_FORMULA, msg);
			}
			return fragmentExpression;
		}
		else
		{
			MathML::AST::VariableExpression* variableExpression = 0;

			// the csymbol is a parameter. 
			// if the address consist of a single word, it might be a parameter of the formula itself.
			if ( csymbolName )
			{
				//search for the parameter name in the formulas new params
				bool found = false;
				getNewParamIndex(formula, *csymbolName, found);
				if ( found )
				{
					// we are done. create new VariableExpression and return
					variableExpression = FW_NEW MathML::AST::VariableExpression(*csymbolName);
					success = true;
					return variableExpression;
				}
			}

			// Try to find the referenced parameter in the entire COLLADA file, using ordinary sid address
			// syntax
			const SidTreeNode* targetSidTreeNode = mDocumentProcessor->resolveSid( targetAddress );

			if ( !targetSidTreeNode )
			{
				// parameter not found
				String msg = "Parameter with sid address \"" + targetAddress.getSidAddressString() + "\" ";
				const String& formulaName = formula->getName();
				if ( !formulaName.empty() )
				{
					msg.append( "referenced in \"" + formulaName + "\" ");
				}
				msg.append( "could not be resolved." );

				success = mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_PARAMETER, msg);
			}
			else
			{
				// parameter found
				if (targetSidTreeNode->getTargetType() == SidTreeNode::TARGETTYPECLASS_OBJECT)
				{
					// the parameter is an object, e.g. a joint
					const COLLADAFW::Object* object = targetSidTreeNode->getObjectTarget();
					COLLADABU_ASSERT(object);
					variableExpression = new MathML::AST::VariableExpression(object->getUniqueId().toAscii());
				}
				else if (targetSidTreeNode->getTargetType() == SidTreeNode::TARGETTYPECLASS_INTERMEDIATETARGETABLE)
				{
					// the parameter is an object, e.g. a joint
					const IntermediateTargetable* intermediateTargetable = targetSidTreeNode->getIntermediateTargetableTarget();
					COLLADABU_ASSERT(intermediateTargetable);
					const KinematicInstance* kinematicInstance = intermediateTargetableSafeCast<KinematicInstance>(intermediateTargetable);
					// for now we only support kinematic instances here
					COLLADABU_ASSERT(kinematicInstance);
					variableExpression = new MathML::AST::VariableExpression(kinematicInstance->getReplacingObjectUniqueId().toAscii());
				}
				else
				{
					// TODO: animatabel not supported yet
					success = false;
					return 0;
				}

			}
			success = true;
			return variableExpression;
		}

		success = false;
		return 0;
	}

	//------------------------------
	size_t FormulasLinker::getNewParamIndex(const COLLADAFW::Formula* formula, const String& parameterName, bool &found)
	{
		const COLLADAFW::FormulaNewParamPointerArray& newParams = formula->getNewParams();
		for ( size_t i = 0, count = newParams.getCount(); i < count; ++i)
		{
			const COLLADAFW::FormulaNewParam* newParam = newParams[i];
			if ( newParam->getName() == parameterName )
			{
				found = true;
				return i;
			}
		}
		found = false;
		return 0;
	}

} // namespace COLLADASaxFWL
