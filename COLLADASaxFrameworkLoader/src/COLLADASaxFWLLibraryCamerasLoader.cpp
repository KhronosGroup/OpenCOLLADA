/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryCamerasLoader.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLFileLoader.h"

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
		, mInOptics(false)
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
    const COLLADAFW::UniqueId& LibraryCamerasLoader::getUniqueId ()
    {
        if ( mCurrentCamera )
            return mCurrentCamera->getUniqueId ();
        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	bool LibraryCamerasLoader::end__library_cameras()
	{
		getFileLoader()->moveUpInSidTree();
		finish();
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__camera( const camera__AttributeData& attributeData )
	{
		mCurrentCamera = FW_NEW COLLADAFW::Camera( createUniqueIdFromId( attributeData.id, COLLADAFW::Camera::ID()) );

		if ( attributeData.name )
			mCurrentCamera->setName( (const char*) attributeData.name );
		else if ( attributeData.id )
			mCurrentCamera->setName( (const char*) attributeData.id );

        if ( attributeData.id )
            mCurrentCamera->setOriginalId ( (const char*)attributeData.id );

		getFileLoader()->addToSidTree( attributeData.id, 0);
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__camera()
	{
		// we need to determine the description type
		// X = 1, Y = 2, aspect ratio = 4
		int descriptionType = (mCurrentCameraHasX ? 1 : 0) +
							  (mCurrentCameraHasY ? 2 : 0) +
							  (mCurrentCameraHasAspectRatio ? 4 : 0);
		switch ( descriptionType )
		{
		case 1:
			mCurrentCamera->setDescriptionType(COLLADAFW::Camera::SINGLE_X);
			break;
		case 2:
			mCurrentCamera->setDescriptionType(COLLADAFW::Camera::SINGLE_Y);
			break;
		case 3:
			mCurrentCamera->setDescriptionType(COLLADAFW::Camera::X_AND_Y);
			break;
		case 5:
			mCurrentCamera->setDescriptionType(COLLADAFW::Camera::ASPECTRATIO_AND_X);
			break;
		case 6:
			mCurrentCamera->setDescriptionType(COLLADAFW::Camera::ASPECTRATIO_AND_Y);
			break;
		default:
			mCurrentCamera->setDescriptionType(COLLADAFW::Camera::UNDEFINED);
		}

		bool success = true;
		if ( (getObjectFlags() & Loader::CAMERA_FLAG) != 0 )
		{
			getFileLoader()->addCamera( mCurrentCamera );
		}
		resetCurrentValues();
		getFileLoader()->moveUpInSidTree();
		return success;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__perspective()
	{
		mCurrentCamera->setCameraType(COLLADAFW::Camera::PERSPECTIVE);
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__orthographic()
	{
		mCurrentCamera->setCameraType(COLLADAFW::Camera::ORTHOGRAPHIC);
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__xfov( const xfov__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentCamera->getXFov());
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__xfov( float value )
	{
		mCurrentCamera->setXFov( value );
		mCurrentCameraHasX = true;
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__xfov()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__yfov( const yfov__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentCamera->getYFov());
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__yfov( float value )
	{
		mCurrentCamera->setYFov( value );
		mCurrentCameraHasY = true;
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__yfov()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__xmag( const xmag__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentCamera->getXMag());
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__xmag( float value )
	{
		mCurrentCamera->setXMag( value );
		mCurrentCameraHasX = true;
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__xmag()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__ymag( const ymag__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentCamera->getYMag());
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__ymag( float value )
	{
		mCurrentCamera->setYMag( value );
		mCurrentCameraHasY = true;
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__ymag()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__aspect_ratio( const aspect_ratio__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentCamera->getAspectRatio());
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__aspect_ratio( float value )
	{
		mCurrentCamera->setAspectRatio(value);
		mCurrentCameraHasAspectRatio = true;
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__aspect_ratio()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__znear( const znear__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentCamera->getNearClippingPlane());
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__znear( float value )
	{
		mCurrentCamera->setNearClippingPlane(value);
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__znear()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::begin__zfar( const zfar__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentCamera->getFarClippingPlane());
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::data__zfar( float value )
	{
		mCurrentCamera->setFarClippingPlane(value);
		return true;
	}

	//------------------------------
	bool LibraryCamerasLoader::end__zfar()
	{
		moveUpInSidTree();
		return true;
	}

} // namespace COLLADASaxFWL
