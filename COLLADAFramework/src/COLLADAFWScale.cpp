/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWScale.h"

namespace COLLADAFW
{
	//--------------------------------------------------------------------
	Scale::Scale()
		: Transformation(Transformation::SCALE),
		mScaleVector(COLLADABU::Math::Vector3::UNIT_SCALE)
	{
	}

	Scale::Scale( const COLLADABU::Math::Vector3& scaleVector )
		: Transformation(Transformation::SCALE),
		mScaleVector(scaleVector)
	{
	}

	Scale::Scale( double x, double y, double z )
		: Transformation(Transformation::SCALE),
		mScaleVector(COLLADABU::Math::Vector3(x, y, z))
	{
	}


	//--------------------------------------------------------------------
	Scale::~Scale()
	{
	}

} // namespace COLLADAFW
