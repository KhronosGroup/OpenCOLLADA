/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLCOLLADACsymbol.h"

#include "MathMLASTVisitor.h"


namespace COLLADASaxFWL
{

	//------------------------------
	COLLADACsymbol::COLLADACsymbol( const SidAddress& sidAddress)
		: mSidAddress(sidAddress)
		, mFunctionName()
		, mFormulaUniqueId(COLLADAFW::UniqueId::INVALID)
		, mCSymbolType(PARAMETER)
		, mParameterList()
	{

	}

	//------------------------------
	COLLADACsymbol::COLLADACsymbol( const String& functionName, const COLLADAFW::UniqueId& formulaUniqueId )
		: mSidAddress()
		, mFunctionName(functionName)
		, mFormulaUniqueId(formulaUniqueId)
		, mCSymbolType(FUNCTION)
		, mParameterList()
	{

	}

    //------------------------------
	COLLADACsymbol::~COLLADACsymbol()
	{
	}

	//------------------------------
	void COLLADACsymbol::accept( MathML::AST::IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	//-----------------------------------------------------------------
	MathML::AST::INode* COLLADACsymbol::clone(CloneFlags cloneFlags) const
	{
		COLLADACsymbol* copy = 0;
		if ( mCSymbolType == PARAMETER)
		{
			copy = new COLLADACsymbol( mSidAddress );
		}
		else
		{
			copy = new COLLADACsymbol( mFunctionName, mFormulaUniqueId );
		}
		return copy;
	}

	//------------------------------
	const COLLADAFW::UniqueId& COLLADACsymbol::getFormulaUniqueId() const
	{
		return mFormulaUniqueId;
	}

	//------------------------------
	const String& COLLADACsymbol::getFunctionName() const
	{
		return mFunctionName;
	}


} // namespace COLLADASaxFWL
