/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_TRIANGLE_H__
#define __DAE23DS_TRIANGLE_H__

#include "DAE23dsPrerequisites.h"


namespace DAE23ds
{

	template<class T>
	struct Triangle
	{
		Triangle( T i1, T i2, T i3, COLLADAFW::MaterialId _materialId)
			: materialId(_materialId)
		{
			indices[0] = i1;
			indices[1] = i2;
			indices[2] = i3;
		}

		COLLADAFW::MaterialId materialId;
		T indices[3];
	};


} // namespace DAE23ds

#endif // __DAE23DS_TRIANGLE_H__
