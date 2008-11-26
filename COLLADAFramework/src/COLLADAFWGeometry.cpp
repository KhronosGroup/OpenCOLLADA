/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Geometry::Geometry(ObjectId objectId)
		: Object<COLLADA_TYPE::GEOMETRY>(objectId)
	{
	}
	
    //------------------------------
	Geometry::~Geometry()
	{
	}

    //------------------------------
    void Geometry::setGeometricElement ( GeometricElement* geometricElement )
    {
        mGeometricElement = geometricElement;
    }

    //------------------------------
    GeometricElement* Geometry::getGeometricElement ()
    {
        return mGeometricElement;
    }

} // namespace COLLADAFW
