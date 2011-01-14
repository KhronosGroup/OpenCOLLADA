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
	COLLADACsymbol::COLLADACsymbol( const SidAddress& sidAddress, CSymbolType cSymbolType )
		: mSidAddress(sidAddress)
		, mCSymbolType(cSymbolType) 
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
		COLLADACsymbol* copy = new COLLADACsymbol( mSidAddress, mCSymbolType);
		return copy;
	}


} // namespace COLLADASaxFWL
