/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_FORMULASLINKER_H__
#define __COLLADASAXFWL_FORMULASLINKER_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADAFWFormula.h"


namespace COLLADASaxFWL
{

	class DocumentProcessor;
	class COLLADACsymbol;

    /** Links all the formulas, i.e. it replaces COLLADACsymbol AST INodes by either FragmentExpression or */
	class FormulasLinker 	
	{
	private:
		/** The file loader.*/
		DocumentProcessor* mDocumentProcessor;
		
		/** All the formulas that should be linked.*/
		COLLADAFW::FormulaArray& mFormulas;

	public:

        /** Constructor. */
		FormulasLinker( DocumentProcessor* documentProcessor, COLLADAFW::FormulaArray& formulas);

        /** Destructor. */
		virtual ~FormulasLinker();

		/** Performs the linkage.*/
		bool link();
	private:

        /** Disable default copy ctor. */
		FormulasLinker( const FormulasLinker& pre );

        /** Disable default assignment operator. */
		const FormulasLinker& operator= ( const FormulasLinker& pre );

		/** @param formula The formula that contains csymbol somewhere in its ast.*/
		MathML::AST::INode* link( COLLADAFW::Formula* formula, MathML::AST::INode* astNode, bool& success);

		/** Links the element referenced in @a csymbol and returns either a MathML::AST::FragmentExpression or
		a MathML::AST::VariableExpression. 
		@param formula The formula that contains csymbol somewhere in its ast.*/
		MathML::AST::INode* link(COLLADAFW::Formula* formula, COLLADACsymbol* csymbol, bool& success);
	
		size_t getNewParamIndex(const COLLADAFW::Formula* formula, const String& parameterName, bool &found);
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_FORMULASLINKER_H__
