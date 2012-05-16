/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_FORMULAS_H__
#define __COLLADAFW_FORMULAS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWFormula.h"


namespace COLLADAFW
{

    /** Set of all formulas of the entire COLLADA file. */
	class Formulas 
	{
	private:
		FormulaArray mFormulas;
	
	public:

        /** Constructor. */
		Formulas();

		Formulas( const Formulas& rhs );

        /** Destructor. */
		virtual ~Formulas();

		const FormulaArray& getFormulas() const { return mFormulas; }

		FormulaArray& getFormulas() { return mFormulas; }

	private:
		/** disable assignment op. */
		const Formulas& operator=( const Formulas& rhs );
	};

} // namespace COLLADAFW

#endif // __COLLADAFW_FORMULAS_H__
