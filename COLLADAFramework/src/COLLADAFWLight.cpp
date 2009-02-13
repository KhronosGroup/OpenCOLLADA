/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWLight.h"


namespace COLLADAFW
{

    //------------------------------
	Light::Light( ObjectId objectId )
		: ObjectTemplate< COLLADA_TYPE::LIGHT >(objectId)
		, mLightType(UNDEFINED)
		, mColor()
		, mConstantAttenuation(1)
		, mLinearAttenuation(0)
		, mQuadraticAttenuation(0)
		, mFallOffAngle(180)
		, mFallOffExponent(0)
	{
	}

    //------------------------------
	Light::~Light()
	{
	}

} // namespace COLLADAFW
