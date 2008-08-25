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


#ifndef __COLLADAMAX_CAMERAEXPORTER_H__
#define __COLLADAMAX_CAMERAEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADALibraryCameras.h"
#include "COLLADAMaxConversionFunctor.h"

#define FMULTI_PASS_MOTION_BLUR_CLASS_ID Class_ID(0xd481518, 0x687d7c99)
#define FMULTI_PASS_DOF_CLASS_ID Class_ID(0xd481815, 0x687d799c)


namespace COLLADAMax
{

	class ExportSceneGraph;
	class ExportNode;
	class DocumentExporter;
	class AnimationExporter;


	namespace MaxCamera
	{
		// reference #s
		const unsigned int PBLOCK_REF = 0;   // This is a IParamBlock, not a IParamBlock2.
		const unsigned int DOF_REF = 1;
		const unsigned int MP_EFFECT_REF = 2;

		// Parameter block indices
		const unsigned int FOV = 0; //float
		const unsigned int TARGET_DISTANCE = 1; //float
		const unsigned int NEAR_CLIP = 2; //float
		const unsigned int FAR_CLIP = 3; //float
		const unsigned int NEAR_RANGE = 4; //float
		const unsigned int FAR_RANGE = 5; //float
		const unsigned int MULTI_PASS_EFFECT_ENABLE = 6;  //bool
		const unsigned int MULTI_PASS_EFFECT_RENDER_EFFECTS_PER_PASS = 7; //bool
		const unsigned int FOV_TYPE = 8;  //int
	};


	namespace MultiPassEffectMB
	{
		// parameter blocks IDs
		enum
		{
			multiPassMotionBlur_params,
		};

		// parameters for multiPassMotionBlur_params
		enum
		{
			prm_displayPasses,
			prm_totalPasses,
			prm_duration,
			prm_bias,
			prm_normalizeWeights,
			prm_ditherStrength,
			prm_tileSize,
			prm_disableFiltering,
			prm_disableAntialiasing,
		};
	}

	// Again from the samples...

	namespace MultiPassEffectDOF
	{
		// parameter blocks IDs
		enum
		{
			multiPassDOF_params,
		};

		// parameters for multiPassDOF_params
		enum
		{
			prm_useTargetDistance,
			prm_focalDepth,
			prm_displayPasses,
			prm_totalPasses,
			prm_sampleRadius,
			prm_sampleBias,
			prm_normalizeWeights,
			prm_ditherStrength,
			prm_tileSize,
			prm_disableFiltering,
			prm_disableAntialiasing,
			prm_useOriginalLocation,
		};
	}

    /** Class to export cameras.*/
    class CameraExporter : public COLLADA::LibraryCameras
    {
	public:
		/** Conversion functor to calculate the orthographic left for a camera's FOV.*/
		class ConversionInverseOrthoFOVFunctor : public ConversionFunctor
		{
		private:
			float mTargetDistance;
		public:
			/** Constructor. */
			ConversionInverseOrthoFOVFunctor(float targetDistance) { mTargetDistance = targetDistance; }

			/** Destructor. */
			virtual ~ConversionInverseOrthoFOVFunctor() {} 

			/** This member must create a new instance of the class and return a pointer to it.*/
			virtual ConversionFunctor* clone()const { return new ConversionInverseOrthoFOVFunctor(*this); }

			/** Main functor to override. 
			@param v The value to convert. @return The converted value. */
			virtual float operator()(float fov)const {return mTargetDistance * tanf(fov / 2.0f);}
		};

	public:
		static const String CAMERA_ID_SUFFIX;

		static const String XFOV_SID;
		static const String XMAG_SID;
		static const String ZNEAR_SID;
		static const String ZFAR_SID;

		static const String EXTRA_PARAMETER_TARGET;


		static const String MOTION_BLUR_ELEMENT;
		static const String MOTION_BLUR_DISPLAYPASSES_PARAMETER;
		static const String MOTION_BLUR_TOTALPASSES_PARAMETER;
		static const String MOTION_BLUR_DURATION_PARAMETER;
		static const String MOTION_BLUR_BIAS_PARAMETER;
		static const String MOTION_BLUR_NORMWEIGHTS_PARAMETER;
		static const String MOTION_BLUR_DITHERSTRENGTH_PARAMETER;
		static const String MOTION_BLUR_TILESIZE_PARAMETER;
		static const String MOTION_BLUR_DISABLEFILTER_PARAMETER;
		static const String MOTION_BLUR_DISABLEANTIALIAS_PARAMETER;


		static const String DEPTH_OF_FIELD_ELEMENT;
		static const String DEPTH_OF_FIELD_USETARGETDIST_PARAMETER;
		static const String DEPTH_OF_FIELD_FOCALDEPTH_PARAMETER;
		static const String DEPTH_OF_FIELD_DISPLAYPASSES_PARAMETER;
		static const String DEPTH_OF_FIELD_USEORIGLOC_PARAMETER;
		static const String DEPTH_OF_FIELD_TOTALPASSES_PARAMETER;
		static const String DEPTH_OF_FIELD_SAMPLERADIUS_PARAMETER;
		static const String DEPTH_OF_FIELD_SAMPLEBIAS_PARAMETER;
		static const String DEPTH_OF_FIELD_NORMWEIGHTS_PARAMETER;
		static const String DEPTH_OF_FIELD_DITHERSTR_PARAMETER;
		static const String DEPTH_OF_FIELD_TILESIZE_PARAMETER;
		static const String DEPTH_OF_FIELD_DISFILTERING_PARAMETER;
		static const String DEPTH_OF_FIELD_DISANTIALIAS_PARAMETER;

		static const String TARGETDISTANCE_PARAMETER;



    private:
		ExportSceneGraph* mExportSceneGraph;
		DocumentExporter* mDocumentExporter;
		AnimationExporter* mAnimationExporter;

    public:
        /** Constructor
         @param streamWriter the stream the extra tags should be written to.*/
        CameraExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter  );

        /** Destructor*/
        virtual ~CameraExporter()
        {}

		/** Exports all the cameras in the export scene graph.*/
		void doExport();

		/** Creates an id for the camera.*/
		static String getCameraId( const ExportNode& exportNode );

    private:

		/** Exports all the cameras in @a exportNode and all its child nodes.*/
		void doExport ( ExportNode* exportNode );

		/** Exports the camera represented by @a exportNode.*/
		void CameraExporter::exportCamera( ExportNode* exportNode );

		void exportExtraParameter(const String & parameterName, const String& childName, IParamBlock2* parameters, int parameterIndex, const String& cameraId);


	};


}


#endif //__COLLADAMAX_CAMERAEXPORTER_H__

