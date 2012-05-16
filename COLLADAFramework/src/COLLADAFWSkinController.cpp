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
	SkinController::SkinController( const UniqueId& uniqueId ) 
		: Controller( uniqueId, Controller::CONTROLLER_TYPE_SKIN )
	{

	}

    //------------------------------
	SkinController::SkinController( const SkinController& pre )
		: Controller( pre.getUniqueId(), Controller::CONTROLLER_TYPE_SKIN, pre.getSource () )
		, mSkinControllerData(pre.mSkinControllerData)
	{
		const UniqueIdArray& preJoints = pre.mJoints;
		size_t bonesCount = preJoints.getCount();
		mJoints.allocMemory(bonesCount);
		mJoints.setCount(bonesCount);
		for ( size_t i = 0; i < bonesCount; ++i )
		{
			mJoints[i] = preJoints[i];
		}
	}

} // namespace COLLADAFW
