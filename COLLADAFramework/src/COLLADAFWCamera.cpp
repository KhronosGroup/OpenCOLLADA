/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
	Camera::Camera( const UniqueId& uniqueId)
		: ObjectTemplate< COLLADA_TYPE::CAMERA >(uniqueId)
		, mCameraType(UNDEFINED_CAMERATYPE)
		, mDescriptionType( UNDEFINED )
		, mXFovOrXMag(0)
		, mYFovOrYMag(0)
		, mAspectRatio(0)
		, mNearClippingPlane(0)
		, mFarClippingPlane(0)
	{
	}

    //------------------------------
	Camera::~Camera()
	{
	}

} // namespace COLLADAFW
