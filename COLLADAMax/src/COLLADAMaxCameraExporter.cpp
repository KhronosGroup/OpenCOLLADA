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

#include "COLLADAMaxCameraExporter.h"
#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxDocumentExporter.h"
#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxExtra.h"
#include "COLLADAMaxConversionFunctor.h"

#include <max.h>

namespace COLLADAMax
{

	const String CameraExporter::CAMERA_ID_SUFFIX = "-camera";

	const String CameraExporter::XFOV_SID = "xfov";
	const String CameraExporter::XMAG_SID = "xmag";
	const String CameraExporter::ZNEAR_SID = "znear";
	const String CameraExporter::ZFAR_SID = "zfar";

	const String CameraExporter::EXTRA_PARAMETER_TARGET = "target";



	const String CameraExporter::MOTION_BLUR_ELEMENT = "motion_blur";
	const int CameraExporter::MOTION_BLUR_PARAMETER_COUNT = 9;
	const Extra::ExtraParameter CameraExporter::MOTION_BLUR_PARAMETERS[] =
	{
		{TYPE_FLOAT, 0, "display_passes"},
		{TYPE_FLOAT, 1, "total_passes"},
		{TYPE_INT, 2, "duration"},
		{TYPE_INT, 3, "bias"},
		{TYPE_INT, 4, "normalized_weights"},
		{TYPE_INT, 5, "dither_strength"},
		{TYPE_INT, 6, "tile_size"},
		{TYPE_INT, 7, "disable_filtering"},
		{TYPE_INT, 8, "disable_antialiasing"}
	};


	const String CameraExporter::DEPTH_OF_FIELD_ELEMENT = "depth_of_field";
	const int CameraExporter::DEPTH_OF_FIELD_PARAMETER_COUNT = 12;
	const Extra::ExtraParameter CameraExporter::DEPTH_OF_FIELD_PARAMETERS[] =
	{
		{TYPE_FLOAT, 0, "use_target_dist"},
		{TYPE_FLOAT, 1, "focal_depth"},
		{TYPE_INT, 2, "display_passes"},
		{TYPE_INT, 3, "total_passes"},
		{TYPE_INT, 4, "sample_radius"},
		{TYPE_INT, 5, "sample_bias"},
		{TYPE_INT, 6, "normalized_weights"},
		{TYPE_INT, 7, "dither_strength"},
		{TYPE_INT, 8, "tile_size"},
		{TYPE_INT, 9, "disable_filtering"},
		{TYPE_INT, 10, "disable_antialiasing"},
		{TYPE_INT, 11, "use_original_location"}
	};

	const String CameraExporter::TARGETDISTANCE_PARAMETER = "target_distance";




    //---------------------------------------------------------------
    CameraExporter::CameraExporter ( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADASW::LibraryCameras ( streamWriter ),
			Extra(streamWriter, documentExporter),
			mExportSceneGraph(exportSceneGraph),
			mDocumentExporter(documentExporter),
			mAnimationExporter(documentExporter->getAnimationExporter())
    {}


	//---------------------------------------------------------------
	String CameraExporter::getCameraId( const ExportNode& exportNode )
	{
		return exportNode.getId() + CAMERA_ID_SUFFIX;
	}


	//---------------------------------------------------------------
	void CameraExporter::doExport()
	{
		doExport ( mExportSceneGraph->getRootExportNode() );
		closeLibrary();
	}



	//---------------------------------------------------------------
	void CameraExporter::doExport( ExportNode* exportNode )
	{
		if ( exportNode->getType() == ExportNode::CAMERA )
			exportCamera(exportNode);

		size_t numberOfChildren = exportNode->getNumberOfChildren();
		for ( size_t i = 0; i < numberOfChildren; ++i )
			doExport ( exportNode->getChild ( i ) );
	}


	//---------------------------------------------------------------
	void CameraExporter::exportCamera( ExportNode* exportNode )
	{
		if ( !exportNode->getIsInVisualScene() )
			return;
		
		String cameraId = getCameraId(*exportNode);

		INode* iNode = exportNode->getINode();

		CameraObject* camera = (CameraObject*)iNode->GetObjectRef();

		INode* targetNode =  ( camera->ClassID().PartA() == LOOKAT_CAM_CLASS_ID) ? iNode->GetTarget() : 0;

		if ( camera )
		{
			if (  mDocumentExporter->isExportedObject(ObjectIdentifier(camera)) )
				return;

			mDocumentExporter->insertExportedObject(ObjectIdentifier(camera), exportNode);


			// Retrieve the camera parameters block
			IParamBlock* parameters = (IParamBlock*) camera->GetReference(MaxCamera::PBLOCK_REF);

			COLLADASW::BaseOptic * optics = 0; 
			if ( camera->IsOrtho() )
			{
				optics = new COLLADASW::OrthographicOptic(COLLADASW::LibraryCameras::mSW);

				// Calculate the target distance for FOV calculations
				float targetDistance;
				if ( targetNode )
				{
					Point3 targetTrans = targetNode->GetNodeTM(mDocumentExporter->getOptions().getAnimationStart()).GetTrans();
					Point3 cameraTrans = iNode->GetNodeTM(mDocumentExporter->getOptions().getAnimationStart()).GetTrans();
					targetDistance = (targetTrans - cameraTrans).Length();
				}
				else
				{
					targetDistance = camera->GetTDist(mDocumentExporter->getOptions().getAnimationStart());
				}
				ConversionInverseOrthoFOVFunctor conversionInverseOrthoFOVFunctor(targetDistance);

				if ( AnimationExporter::isAnimated(parameters, MaxCamera::FOV) )
				{
					optics->setXMag(conversionInverseOrthoFOVFunctor(parameters->GetFloat(MaxCamera::FOV)), XMAG_SID);
					mAnimationExporter->addAnimatedParameter(parameters, MaxCamera::FOV, cameraId, XMAG_SID, 0, true, &conversionInverseOrthoFOVFunctor);
				}
				else
				{
					optics->setXMag(conversionInverseOrthoFOVFunctor(parameters->GetFloat(MaxCamera::FOV)));	
				}
			}
			else
			{
				optics = new COLLADASW::PerspectiveOptic(COLLADASW::LibraryCameras::mSW);
				if ( AnimationExporter::isAnimated(parameters, MaxCamera::FOV) )
				{
					optics->setXFov(COLLADASW::MathUtils::radToDegF(parameters->GetFloat(MaxCamera::FOV)), XFOV_SID);
					mAnimationExporter->addAnimatedParameter(parameters, MaxCamera::FOV, cameraId, XFOV_SID, 0, true, &ConversionFunctors::radToDeg);
				}
				else
				{
					optics->setXFov(COLLADASW::MathUtils::radToDegF(parameters->GetFloat(MaxCamera::FOV)));	
				}
			}

			bool hasAnimatedZNear = mAnimationExporter->addAnimatedParameter(parameters, MaxCamera::NEAR_CLIP, cameraId, optics->getZNearDefaultSid(), 0);
			optics->setZNear(parameters->GetFloat(MaxCamera::NEAR_CLIP), hasAnimatedZNear);

			bool hasAnimatedZFar = mAnimationExporter->addAnimatedParameter(parameters, MaxCamera::FAR_CLIP, cameraId, optics->getZFarDefaultSid(), 0);
			optics->setZFar(parameters->GetFloat(MaxCamera::FAR_CLIP), hasAnimatedZFar);


			COLLADASW::Camera colladaCamera(COLLADASW::LibraryCameras::mSW, optics, cameraId, COLLADASW::Utils::checkNCName(exportNode->getINode()->GetName()));
			setExtraTechnique(&colladaCamera);


			// Retrieve the camera target
			if ( targetNode )
			{
				ExportNode* targetExportNode = mExportSceneGraph->getExportNode(targetNode);
				addExtraParameter(EXTRA_PARAMETER_TARGET, "#" + targetExportNode->getId());
			}

			if (camera->GetMultiPassEffectEnabled(0, FOREVER))
			{
				IMultiPassCameraEffect *multiPassCameraEffect = camera->GetIMultiPassCameraEffect();
				if (multiPassCameraEffect)
				{
					Class_ID id = multiPassCameraEffect->ClassID();

					// the camera could have both effects, but not in Max
					if (id == FMULTI_PASS_MOTION_BLUR_CLASS_ID)
					{
						IParamBlock2 *parameters = multiPassCameraEffect->GetParamBlock(0);
						if (parameters )
						{
							addParamBlockAnimatedExtraParameters(MOTION_BLUR_ELEMENT, MOTION_BLUR_PARAMETERS, MOTION_BLUR_PARAMETER_COUNT, parameters, cameraId);
						}
					}
					else if (id == FMULTI_PASS_DOF_CLASS_ID)
					{
						IParamBlock2 *parameters = multiPassCameraEffect->GetParamBlock(0);
						if (parameters )
						{
							addParamBlockAnimatedExtraParameters(DEPTH_OF_FIELD_ELEMENT, DEPTH_OF_FIELD_PARAMETERS, DEPTH_OF_FIELD_PARAMETER_COUNT, parameters, cameraId);
							addExtraParameter(TARGETDISTANCE_PARAMETER, camera->GetTDist(0));
						}
					}
				}
			}
			addCamera(colladaCamera);
		
			delete optics;
		}

	}

}
