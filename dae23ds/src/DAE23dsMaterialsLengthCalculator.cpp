/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "dae23dsStableHeaders.h"
#include "DAE23dsMaterialsLengthCalculator.h"


namespace DAE23ds
{

    //------------------------------
	MaterialsLengthCalculator::MaterialsLengthCalculator( Writer* writer3ds )
		: MaterialsBase(writer3ds)
	{

	}

    //------------------------------
	MaterialsLengthCalculator::~MaterialsLengthCalculator()
	{
	}

	//------------------------------
	void MaterialsLengthCalculator::calculate()
	{
		Writer::UniqueIdFWMaterialMap::const_iterator it = mUniqueIdFWMaterialMap.begin();
		for ( ; it != mUniqueIdFWMaterialMap.end(); ++it )
		{
			const COLLADAFW::Material* material = &it->second;
			addToObjectAndMaterialBlockLength(calculateMaterialBlockLength( material ));
		}
	}
} // namespace DAE23ds
