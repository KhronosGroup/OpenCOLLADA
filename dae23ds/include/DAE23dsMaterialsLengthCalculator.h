/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MATERIALSLENGTHCALCULATOR_H__
#define __DAE23DS_MATERIALSLENGTHCALCULATOR_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsMaterialsBase.h"


namespace DAE23ds
{

	class MaterialsLengthCalculator : public MaterialsBase 
	{
	public:

        /** Constructor. */
		MaterialsLengthCalculator(Writer* writer3ds);

        /** Destructor. */
		virtual ~MaterialsLengthCalculator();

		/** Calculates the length of the entire material block. */
		void calculate();

	private:

        /** Disable default copy ctor. */
		MaterialsLengthCalculator( const MaterialsLengthCalculator& pre );

        /** Disable default assignment operator. */
		const MaterialsLengthCalculator& operator= ( const MaterialsLengthCalculator& pre );

	};

} // namespace DAE23DS

#endif // __DAE23DS_MATERIALSLENGTHCALCULATOR_H__
