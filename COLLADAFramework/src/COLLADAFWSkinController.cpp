/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWSkinController.h"


namespace COLLADAFW
{

    //------------------------------
	SkinController::SkinController( ObjectId objectId ) 
		: Controller( objectId, Controller::CONTROLLER_TYPE_SKIN )
	{

	}

	SkinController::SkinController( const SkinController& pre )
		: Controller( pre.getObjectId(), Controller::CONTROLLER_TYPE_SKIN )
		, mSkinControllerData(pre.mSkinControllerData)
	{
		const UniqueIdArray& preBones = pre.mBones;
		size_t bonesCount = preBones.getCount();
		mBones.allocMemory(bonesCount);
		mBones.setCount(bonesCount);
		for ( size_t i = 0; i < bonesCount; ++i )
		{
			mBones[i] = preBones[i];
		}
	}

} // namespace COLLADAFW
