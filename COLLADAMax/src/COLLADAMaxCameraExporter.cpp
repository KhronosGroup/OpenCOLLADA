/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

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
	const String CameraExporter::MOTION_BLUR_DISPLAYPASSES_PARAMETER = "display_passes";
	const String CameraExporter::MOTION_BLUR_TOTALPASSES_PARAMETER = "total_passes";
	const String CameraExporter::MOTION_BLUR_DURATION_PARAMETER = "duration";
	const String CameraExporter::MOTION_BLUR_BIAS_PARAMETER = "bias";
	const String CameraExporter::MOTION_BLUR_NORMWEIGHTS_PARAMETER = "normalized_weights";
	const String CameraExporter::MOTION_BLUR_DITHERSTRENGTH_PARAMETER = "dither_strength";
	const String CameraExporter::MOTION_BLUR_TILESIZE_PARAMETER = "tile_size";
	const String CameraExporter::MOTION_BLUR_DISABLEFILTER_PARAMETER = "disable_filtering";
	const String CameraExporter::MOTION_BLUR_DISABLEANTIALIAS_PARAMETER = "disable_antialiasing";


	const String CameraExporter::DEPTH_OF_FIELD_ELEMENT = "depth_of_field";
	const String CameraExporter::DEPTH_OF_FIELD_USETARGETDIST_PARAMETER = "use_target_dist";
	const String CameraExporter::DEPTH_OF_FIELD_FOCALDEPTH_PARAMETER = "focal_depth";
	const String CameraExporter::DEPTH_OF_FIELD_DISPLAYPASSES_PARAMETER = "display_passes";
	const String CameraExporter::DEPTH_OF_FIELD_USEORIGLOC_PARAMETER = "use_original_location";
	const String CameraExporter::DEPTH_OF_FIELD_TOTALPASSES_PARAMETER = "total_passes";
	const String CameraExporter::DEPTH_OF_FIELD_SAMPLERADIUS_PARAMETER = "sample_radius";
	const String CameraExporter::DEPTH_OF_FIELD_SAMPLEBIAS_PARAMETER = "sample_bias";
	const String CameraExporter::DEPTH_OF_FIELD_NORMWEIGHTS_PARAMETER = "normalized_weights";
	const String CameraExporter::DEPTH_OF_FIELD_DITHERSTR_PARAMETER = "dither_strength";
	const String CameraExporter::DEPTH_OF_FIELD_TILESIZE_PARAMETER = "tile_size";
	const String CameraExporter::DEPTH_OF_FIELD_DISFILTERING_PARAMETER = "disable_filtering";
	const String CameraExporter::DEPTH_OF_FIELD_DISANTIALIAS_PARAMETER = "disable_antialiasing";

	const String CameraExporter::TARGETDISTANCE_PARAMETER = "target_distance";




    //---------------------------------------------------------------
    CameraExporter::CameraExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADA::LibraryCameras ( streamWriter ),
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

			// Retrieve the camera parameters block
			IParamBlock* parameters = (IParamBlock*) camera->GetReference(MaxCamera::PBLOCK_REF);

			COLLADA::BaseOptic * optics = 0; 
			if ( camera->IsOrtho() )
			{
				optics = new COLLADA::OrthographicOptic(mSW);

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
					targetDistance = camera->GetTDist(TIME_EXPORT_START);
				}
				ConversionInverseOrthoFOVFunctor conversionInverseOrthoFOVFunctor(targetDistance);

				if ( AnimationExporter::isAnimated(parameters, MaxCamera::FOV) )
				{
					optics->setXMag(conversionInverseOrthoFOVFunctor(parameters->GetFloat(MaxCamera::FOV)), XMAG_SID);
					mAnimationExporter->addAnimatedParameter(parameters, MaxCamera::FOV, cameraId, XMAG_SID, 0, &conversionInverseOrthoFOVFunctor);
				}
				else
				{
					optics->setXMag(conversionInverseOrthoFOVFunctor(parameters->GetFloat(MaxCamera::FOV)));	
				}
			}
			else
			{
				optics = new COLLADA::PerspectiveOptic(mSW);
				if ( AnimationExporter::isAnimated(parameters, MaxCamera::FOV) )
				{
					optics->setXFov(COLLADA::MathUtils::radToDegF(parameters->GetFloat(MaxCamera::FOV)), XFOV_SID);
					mAnimationExporter->addAnimatedParameter(parameters, MaxCamera::FOV, cameraId, XFOV_SID, 0, &ConversionFunctors::radToDeg);
				}
				else
				{
					optics->setXFov(COLLADA::MathUtils::radToDegF(parameters->GetFloat(MaxCamera::FOV)));	
				}
			}

			if ( AnimationExporter::isAnimated(parameters, MaxCamera::NEAR_CLIP) )
			{
				optics->setZNear(parameters->GetFloat(MaxCamera::NEAR_CLIP), ZNEAR_SID);
				mAnimationExporter->addAnimatedParameter(parameters, MaxCamera::NEAR_CLIP, cameraId, ZNEAR_SID, 0);
			}
			else
			{
				optics->setZNear(parameters->GetFloat(MaxCamera::NEAR_CLIP));
			}

			if ( AnimationExporter::isAnimated(parameters, MaxCamera::FAR_CLIP) )
			{
				optics->setZFar(parameters->GetFloat(MaxCamera::FAR_CLIP), ZFAR_SID);
				mAnimationExporter->addAnimatedParameter(parameters, MaxCamera::FAR_CLIP, cameraId, ZFAR_SID, 0);
			}
			else
			{
				optics->setZFar(parameters->GetFloat(MaxCamera::FAR_CLIP));
			}


			COLLADA::Camera colladaCamera(mSW, optics, cameraId, COLLADA::Utils::checkNCName(exportNode->getINode()->GetName()));
			addCamera(colladaCamera);


			// Retrieve the camera target
			if ( targetNode )
			{
				ExportNode* targetExportNode = mExportSceneGraph->getExportNode(targetNode);
				addExtraTechniqueParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, EXTRA_PARAMETER_TARGET, "#" + targetExportNode->getId());
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
							exportExtraParameter( MOTION_BLUR_DISPLAYPASSES_PARAMETER, MOTION_BLUR_ELEMENT, parameters, MultiPassEffectMB::prm_displayPasses, cameraId);
							exportExtraParameter( MOTION_BLUR_TOTALPASSES_PARAMETER, MOTION_BLUR_ELEMENT, parameters, MultiPassEffectMB::prm_totalPasses, cameraId);
							exportExtraParameter( MOTION_BLUR_DURATION_PARAMETER, MOTION_BLUR_ELEMENT, parameters, MultiPassEffectMB::prm_duration, cameraId);
							exportExtraParameter( MOTION_BLUR_BIAS_PARAMETER, MOTION_BLUR_ELEMENT, parameters, MultiPassEffectMB::prm_bias, cameraId);
							exportExtraParameter( MOTION_BLUR_NORMWEIGHTS_PARAMETER, MOTION_BLUR_ELEMENT, parameters, MultiPassEffectMB::prm_normalizeWeights, cameraId);
							exportExtraParameter( MOTION_BLUR_DITHERSTRENGTH_PARAMETER, MOTION_BLUR_ELEMENT, parameters, MultiPassEffectMB::prm_ditherStrength, cameraId);
							exportExtraParameter( MOTION_BLUR_TILESIZE_PARAMETER, MOTION_BLUR_ELEMENT, parameters, MultiPassEffectMB::prm_tileSize, cameraId);
							exportExtraParameter( MOTION_BLUR_DISABLEFILTER_PARAMETER, MOTION_BLUR_ELEMENT, parameters, MultiPassEffectMB::prm_disableFiltering, cameraId);
							exportExtraParameter( MOTION_BLUR_DISABLEANTIALIAS_PARAMETER, MOTION_BLUR_ELEMENT, parameters, MultiPassEffectMB::prm_disableAntialiasing, cameraId);
						}
					}
					else if (id == FMULTI_PASS_DOF_CLASS_ID)
					{
						IParamBlock2 *parameters = multiPassCameraEffect->GetParamBlock(0);
						if (parameters )
						{
							exportExtraParameter( DEPTH_OF_FIELD_USETARGETDIST_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_useTargetDistance, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_FOCALDEPTH_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_focalDepth, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_DISPLAYPASSES_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_displayPasses, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_USEORIGLOC_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_useOriginalLocation, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_TOTALPASSES_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_totalPasses, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_SAMPLERADIUS_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_sampleRadius, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_NORMWEIGHTS_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_normalizeWeights, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_DITHERSTR_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_ditherStrength, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_TILESIZE_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_tileSize, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_DISFILTERING_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_disableFiltering, cameraId);
							exportExtraParameter( DEPTH_OF_FIELD_DISANTIALIAS_PARAMETER, DEPTH_OF_FIELD_ELEMENT, parameters, MultiPassEffectDOF::prm_disableAntialiasing, cameraId);

							addExtraTechniqueParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, TARGETDISTANCE_PARAMETER, camera->GetTDist(0));
						}
					}
				}

			}
			addTextureExtraTechniques(*mSW);
		
			delete optics;
		}

	}


	void CameraExporter::exportExtraParameter(const String & parameterName, const String& childName, IParamBlock2* parameters, int parameterIndex, const String& cameraId)
	{
		ParamType2 parametrType = parameters->GetParameterType(parameterIndex);

		// use the animation number with the GetController method
		// since the parameters enumeration doesn't reflect the param
		// block order.
		int animationNumber = parameters->GetAnimNum(parameterIndex);
		Control *controller = parameters->GetController(animationNumber);

		switch (parametrType)
		{
		case TYPE_BOOL:
			addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex)!= false);
			// NO ANIMATION ON BOOLEANS
			break;
		case TYPE_INT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex) , parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, cameraId, parameterName, 0);
			}
			else
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex));
			}
			break;
		case TYPE_FLOAT:
			if ( AnimationExporter::isAnimated(parameters, parameterIndex) )
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetFloat(parameterIndex), parameterName);
				mAnimationExporter->addAnimatedParameter(parameters, parameterIndex, cameraId, parameterName, 0);
			}
			else
			{
				addExtraTechniqueChildParameter(Extra::TECHNIQUE_PROFILE_3DSMAX, childName, parameterName, parameters->GetInt(parameterIndex));
			}
			break;
		default:
			break;
		}

	}

}
