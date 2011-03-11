/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWSpline.h"
#include "COLLADAFWTristrips.h"
#include "COLLADAFWLinestrips.h"

namespace COLLADAFW
{

    //----------------------------------
    Spline::Spline( const UniqueId& uniqueId )
        : Geometry ( uniqueId, Geometry::GEO_TYPE_SPLINE )
    {

    }

    //----------------------------------
	Spline::~Spline()
	{
    }

} // namespace COLLADAFW
