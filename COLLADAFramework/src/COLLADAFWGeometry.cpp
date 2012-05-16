/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWGeometry.h"


namespace COLLADAFW
{

    //------------------------------
	Geometry::Geometry ( const UniqueId& uniqueId, GeometryType geometryType )
		: ObjectTemplate < COLLADA_TYPE::GEOMETRY > ( uniqueId ),
		  mType(geometryType)
	{
	}
	
    //------------------------------
	Geometry::~Geometry()
	{
	}


} // namespace COLLADAFW
