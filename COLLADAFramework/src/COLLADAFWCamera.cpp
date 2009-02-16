/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWCamera.h"


namespace COLLADAFW
{

    //------------------------------
	Camera::Camera( ObjectId objectId)
		: ObjectTemplate< COLLADA_TYPE::CAMERA >(objectId)
		, mCameraType(UNDEFINED_CAMERATYPE)
		, mDescriptionType( UNDEFINED )
		, mXFovOrXMag(0)
        , mHasXFovOrXMag (false)
		, mYFovOrYMag(0)
        , mHasYFovOrYMag (false)
		, mAspectRatio(0)
        , mHasAspectRatio (false)
		, mNearClippingPlane(0)
		, mFarClippingPlane(0)
	{
	}

    //------------------------------
	Camera::~Camera()
	{
	}

} // namespace COLLADAFW
