/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_COLLADACSYMBOL_H__
#define __COLLADASAXFWL_COLLADACSYMBOL_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSidAddress.h"

#include "MathMLSolverPrerequisites.h"
#include "MathMLASTNode.h"
#include "MathMLASTFragmentExpression.h"


namespace COLLADASaxFWL
{

	/** Specialized variable node implementing INode. Used to store <MathML:csymbol> date intemediately. */

	class  COLLADACsymbol : public MathML::AST::INode
	{
	public:
		enum CSymbolType { PARAMETER, FUNCTION };

		typedef MathML::AST::FragmentExpression::ParameterList ParameterList;

	private:
		/** Sid address of the referenced parameter or formula. */
		SidAddress mSidAddress;

		/** Type of the csymbol.*/
		CSymbolType mCSymbolType;

		/** The parameters of the function, if the csymbol is a function.*/
		ParameterList mParameterList;

	public:
		/** Initializing constructor.
		@param name The name of the variable
		*/
		COLLADACsymbol( const SidAddress& sidAddress, CSymbolType cSymbolType );

		/** D-tor. */
		virtual ~COLLADACsymbol();

		// see INode::accept(IVisitor* )
		virtual void accept( MathML::AST::IVisitor* visitor ) const;

		// see INode::getType()
		virtual MathML::AST::INode::NodeType getNodeType() const { return USERDEFINED; }

		/** @return a copy of this node. */
		virtual MathML::AST::INode* clone(CloneFlags cloneFlags = CLONEFLAG_DEFAULT) const;

		/** Sid address of the referenced parameter or formula. */
		const SidAddress& getSidAddress() const { return mSidAddress; }

		/** The parameters of the function, if the csymbol is a function.*/
		const ParameterList& getParameterList() const { return mParameterList; }

		/** The parameters of the function, if the csymbol is a function.*/
		ParameterList& getParameterList() { return mParameterList; }

		/** Type of the csymbol.*/
		CSymbolType getCSymbolType() const { return mCSymbolType; }
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_COLLADACSYMBOL_H__
