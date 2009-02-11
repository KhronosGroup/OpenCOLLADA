/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryCamerasLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWCamera.h"

namespace COLLADASaxFWL
{

    //------------------------------
	LibraryCamerasLoader::LibraryCamerasLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentCamera(0)
		, mCurrentCameraHasX(false)
		, mCurrentCameraHasY(false)
		, mCurrentCameraHasAspectRatio(false)
	{
	}

    //------------------------------
	LibraryCamerasLoader::~LibraryCamerasLoader()
	{
	}

	//------------------------------
	void LibraryCamerasLoader::resetCurrentValues()
	{
		mCurrentCamera = 0;
		mCurrentCameraHasX = false;
		mCurrentCameraHasY = false;
		mCurrentCameraHasAspectRatio = false;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__library_cameras()
	{
		finish();
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__camera( const camera__AttributeData& attributeData )
	{
		mCurrentCamera = FW_NEW COLLADAFW::Camera( getUniqueIdFromId( attributeData.id, COLLADAFW::Camera::ID()).getObjectId() );

		if ( attributeData.name )
			mCurrentCamera->setName( (const char*) attributeData.name );
		else if ( attributeData.id )
			mCurrentCamera->setName( (const char*) attributeData.id );

		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__camera()
	{
		bool success = writer()->writeCamera(mCurrentCamera);
		FW_DELETE mCurrentCamera;
		resetCurrentValues();
		return success;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__perspective()
	{
		mCurrentCamera->setCameraType(COLLADAFW::Camera::PERSPECTIVE);
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__xfov( double value )
	{
		mCurrentCamera->setXFovOrXMag( value );
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__yfov( double value )
	{
		mCurrentCamera->setYFovOrYMag( value );
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__perspective__aspect_ratio( double value )
	{
		mCurrentCamera->setAspectRatio(value);
		return true;
	}

	bool LibraryCamerasLoader::data__perspective__znear( double value )
	{
		mCurrentCamera->setNearClippingPlane(value);
		return true;
	}

	bool LibraryCamerasLoader::data__perspective__zfar( double value )
	{
		mCurrentCamera->setFarClippingPlane(value);
		return true;
	}


} // namespace COLLADASaxFWL
