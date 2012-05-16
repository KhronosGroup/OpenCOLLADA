/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
	Light::Light( const UniqueId& uniqueId )
		: ObjectTemplate< COLLADA_TYPE::LIGHT >(uniqueId)
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
