/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWSampler.h"


namespace COLLADAFW
{

    //------------------------------
	Sampler::Sampler ( const UniqueId& uniqueId )
        : ObjectTemplate<COLLADA_TYPE::SAMPLER>(uniqueId)
        , mSamplerType(SAMPLER_TYPE_UNSPECIFIED)
		, mSourceImageUniqueId()
		, mMinFilter( SAMPLER_FILTER_LINEAR )
		, mMagFilter( SAMPLER_FILTER_LINEAR )
		, mMipFilter( SAMPLER_FILTER_LINEAR )
		, mWrapS(WRAP_MODE_WRAP)
		, mWrapT(WRAP_MODE_WRAP)
		, mWrapP(WRAP_MODE_WRAP)
		, mMipmapMaxlevel(255)
		, mMipmapBias(0)

	{
	}
	
    //------------------------------
	Sampler::~Sampler()
	{
	}

} // namespace COLLADAFW
