/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxCameraImporter.h"

#include "COLLADAFWCamera.h"

#include <max.h>

namespace COLLADAMax
{

    //------------------------------
	CameraImporter::CameraImporter( DocumentImporter* documentImporter, const COLLADAFW::Camera* camera )
		: ImporterBase(documentImporter)
		, mCamera(camera)
	{
	}

    //------------------------------
	CameraImporter::~CameraImporter()
	{
	}

	//------------------------------
	bool CameraImporter::import()
	{
		GenCamera* maxCamera = createCamera(mCamera);

		handleObjectReferences(mCamera, maxCamera);

		return true;
	}

	//------------------------------
	GenCamera* CameraImporter::createCamera( const COLLADAFW::Camera* camera )
	{
		// TODO TARGETED_CAMERA 
		GenCamera* maxCamera = getMaxImportInterface()->CreateCameraObject( FREE_CAMERA );

		float targetDistance = 100; // we don't have a target, therefore we need to set anything
		maxCamera->SetTDist(0, targetDistance);

		if (camera->getCameraType() == COLLADAFW::Camera::PERSPECTIVE)
		{
			// Perspective camera
			maxCamera->SetOrtho(FALSE);
			switch ( camera->getDescriptionType() )
			{
			case COLLADAFW::Camera::SINGLE_X:
			case COLLADAFW::Camera::X_AND_Y:
			case COLLADAFW::Camera::ASPECTRATIO_AND_X:
				maxCamera->SetFOVType(0);
				maxCamera->SetFOV(0, COLLADABU::Math::Utils::degToRadF( (float)camera->getXFov()));
				break;
			case COLLADAFW::Camera::SINGLE_Y:
			case COLLADAFW::Camera::ASPECTRATIO_AND_Y:
				{
					float aspectRatio = getMaxInterface()->GetRendImageAspect();
					maxCamera->SetFOVType(1);
					float yfov = COLLADABU::Math::Utils::degToRadF( (float)camera->getYFov());
					float xfov = 2 * atan( aspectRatio * tan(yfov/2));
					maxCamera->SetFOV(0, xfov);
					break;
				}
			}
		}
		else
		{
			// Orthographic camera
			maxCamera->SetOrtho(TRUE);

			// Consider only the correct magnification and the target distance,
			// which is kept constant, to calculate the FOV.
			switch ( camera->getDescriptionType() )
			{
			case COLLADAFW::Camera::SINGLE_X:
			case COLLADAFW::Camera::X_AND_Y:
			case COLLADAFW::Camera::ASPECTRATIO_AND_X:
				{
					maxCamera->SetFOVType(0);
					float fov = 2 * (float)atan( camera->getXMag()/targetDistance );
					maxCamera->SetFOV(0, fov);
					break;
				}
			case COLLADAFW::Camera::SINGLE_Y:
			case COLLADAFW::Camera::ASPECTRATIO_AND_Y:
				{
					float aspectRatio = getMaxInterface()->GetRendImageAspect();
					maxCamera->SetFOVType(1);
					float yfov = 2 * (float)atan( camera->getYMag()/targetDistance );
					float xfov = 2 * atan( aspectRatio * tan(yfov/2));
					maxCamera->SetFOV(0, xfov );
					break;
				}
			}
		}

		// Common camera parameters: nearZ, farZ
		// The "Far Clip " animatable parameter intentionally has an extra space in the definition.
		maxCamera->SetClipDist(0, CAM_HITHER_CLIP, (float)camera->getNearClippingPlane());
		maxCamera->SetClipDist(0, CAM_YON_CLIP, (float)camera->getFarClippingPlane());
		maxCamera->SetManualClip(TRUE);
		maxCamera->Enable(TRUE);
		
		return maxCamera;
	}


} // namespace COLLADAMax
