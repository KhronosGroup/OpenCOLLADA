/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWMorphController.h"


namespace COLLADAFW
{

    //------------------------------
	MorphController::MorphController( ObjectId objectId ) 
		: Controller( objectId, Controller::CONTROLLER_TYPE_MORPH)
	{

	}

	//------------------------------
	MorphController::MorphController( const MorphController& pre )
		: Controller( pre.getObjectId(), Controller::CONTROLLER_TYPE_MORPH, pre.getSource () )
		, mMorphWeights(pre.mMorphWeights)
        , mOriginalId(pre.mOriginalId)
        , mName(pre.mName)
	{
		const UniqueIdArray& preMorphTargets = pre.mMorphTargets;
		size_t bonesCount = preMorphTargets.getCount();
		mMorphTargets.allocMemory(bonesCount);
		mMorphTargets.setCount(bonesCount);
		for ( size_t i = 0; i < bonesCount; ++i )
		{
			mMorphTargets[i] = preMorphTargets[i];
		}
	}

} // namespace COLLADAFW
