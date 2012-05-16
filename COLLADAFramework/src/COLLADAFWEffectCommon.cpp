/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWEffectCommon.h"


namespace COLLADAFW
{

    //------------------------------
	EffectCommon::EffectCommon()
		: mShaderType(SHADER_UNKNOWN)
		, mShininess(-1)
		, mReflectivity(-1)
		, mIndexOfRefraction(-1)
	{
	}
	
    //------------------------------
	EffectCommon::~EffectCommon()
	{
	}

} // namespace COLLADAFW
