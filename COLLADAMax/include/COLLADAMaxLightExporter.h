/*
    Copyright (c) 2008 NetAllied Systems GmbH

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


#ifndef __COLLADAMAX_LIGHTEXPORTER_H__
#define __COLLADAMAX_LIGHTEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAMaxExtra.h"

#include "COLLADASWLibraryLights.h"


// extra class ID from the samples (systems/sunlight/natLight.cpp)
#define SKY_LIGHT_CLASS_ID			Class_ID(0x7bf61478, 0x522e4705)
#define SKY_LIGHT_CLASS_ID_PART_A	0x7bf61478



namespace COLLADAMax
{

	class ExportSceneGraph;
	class ExportNode;
	class DocumentExporter;
	class AnimationExporter;



	// Information found in the 3dsMax SDK from the 'light' object sample.
	namespace MaxLight
	{
		// reference #s
		const unsigned int PBLOCK_REF = 0;		// This is a IParamBlock
		const unsigned int PBLOCK_REF_SKY = 0;	// This is a IParamBlock2
		const unsigned int PROJMAP_REF = 1;
		const unsigned int SHADPROJMAP_REF = 2;
		const unsigned int SHADTYPE_REF = 3;

		// Parameter block indices common to all lights (except SkyLight)
		const unsigned int PB_COLOR = 0;
		const unsigned int PB_INTENSITY = 1;
		const unsigned int PB_CONTRAST = 2;
		const unsigned int PB_DIFFSOFT = 3;

		// Parameter block indices for non-OMNI lights.
		const unsigned int PB_HOTSIZE = 4;
		const unsigned int PB_FALLSIZE = 5;
		const unsigned int PB_ASPECT = 6;
		const unsigned int PB_ATTENSTART1 = 7;
		const unsigned int PB_ATTENEND1 = 8;
		const unsigned int PB_ATTENSTART = 9;
		const unsigned int PB_ATTENEND = 10;
		const unsigned int PB_DECAY = 11;
		const unsigned int PB_SHADCOLOR = 12;
		const unsigned int PB_ATMOS_SHAD = 13;
		const unsigned int PB_ATMOS_OPACITY = 14;
		const unsigned int PB_ATMOS_COLAMT = 15;
		const unsigned int PB_SHADMULT = 16;
		const unsigned int PB_SHAD_COLMAP = 17;
		const unsigned int PB_TDIST = 18;

		// Parameter block indices for OMNI only
		const unsigned int PB_OMNIATSTART1 = 4;
		const unsigned int PB_OMNIATEND1 = 5;
		const unsigned int PB_OMNIATSTART = 6;
		const unsigned int PB_OMNIATEND = 7;
		const unsigned int PB_OMNIDECAY = 8;
		const unsigned int PB_OMNISHADCOLOR = 9;
		const unsigned int PB_OMNIATMOS_SHAD = 10;
		const unsigned int PB_OMNIATMOS_OPACITY = 11;
		const unsigned int PB_OMNIATMOS_COLAMT = 12;
		const unsigned int PB_OMNISHADMULT = 13;
		const unsigned int PB_OMNISHAD_COLMAP = 14;

		// Parameter block indices for SkyLights (by looking at the ParamBlockDesc)
		const unsigned int PB_SKY_COLOR = 0;
		const unsigned int PB_SKY_SKY_COLOR_MAP_AMOUNT = 1;
		const unsigned int PB_SKY_COLOR_MAP = 2; // TYPE_TEXMAP
		const unsigned int PB_SKY_SKY_COLOR_MAP_ON = 3;
		const unsigned int PB_SKY_RAYS_PER_SAMPLE = 4;
		// baad food
		const unsigned int PB_SKY_MODE = 7; // ??
		// baad food
		const unsigned int PB_SKY_INTENSITY = 0xa;
		const unsigned int PB_SKY_RAY_BIAS = 0xb;
		const unsigned int PB_SKY_CAST_SHADOWS = 0xc;
		const unsigned int PB_SKY_MULTIPLIER_ON = 0xd;
	};




    /** Class to export lights.*/
    class LightExporter : public COLLADASW::LibraryLights, public Extra
    {
	public:
		static const String LIGHT_ID_SUFFIX;

		/** Name of the light extra tag.*/
		static const String LIGHT_ELEMENT;
		static const String LIGHT_MAP_ELEMENT;
		/** Number of light extra parameters.*/
		static const int LIGHT_PARAMETER_COUNT;
		/** light parameters.*/
		static const ExtraParameter LIGHT_PARAMETERS[];

		/** Name of the skylight extra tag.*/
		static const String SKYLIGHT_ELEMENT;
		static const String SKYLIGHT_COLORMAP_ELEMENT;
		/** Number of skylight extra parameters.*/
		static const int SKYLIGHT_PARAMETER_COUNT;
		/** skylight parameters.*/
		static const ExtraParameter SKYLIGHT_PARAMETERS[];


		static const String OVERSHOOT_PARAMETER;
		static const String DECAY_TYPE_PARAMETER;
		static const String USE_FAR_ATTENUATION_PARAMETER;
		static const String USE_NEAR_ATTENUATION_PARAMETER;


		static const String SHADOW_ATTRIBS;
		static const String SHADOW_TYPE;
		static const String SHADOW_TYPE_MAP;
		static const String SHADOW_TYPE_RAYTRACE;
		static const String SHADOW_AFFECTS;
		static const String SHADOW_AFFECTS_LIST_NODES;
		static const String SHADOW_AFFECTS_LIST_EXCLUDES;
		static const String SHADOW_AFFECTS_LIST_ILLUMINATES;
		static const String SHADOW_AFFECTS_LIST_CASTS;


		static const String SHADOW_MAP;
		static const String SHADOW_PROJ_IMAGE;
		static const String SHADOW_PROJ_COLOR;
		static const String SHADOW_PROJ_COLOR_MULT;
		static const String LIGHT_AFFECTS_SHADOW;



	private:
		ExportSceneGraph* mExportSceneGraph;
		DocumentExporter* mDocumentExporter;
		AnimationExporter* mAnimationExporter;

    public:
        /** Constructor
         @param streamWriter the stream the extra tags should be written to.*/
        LightExporter ( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter  );

        /** Destructor*/
        virtual ~LightExporter()
        {}

		/** Exports all the lights in the export scene graph.*/
		void doExport();

		/** Creates an id for the light.*/
		static String getLightId( const ExportNode& exportNode );

    private:

		/** Exports all the lights in @a exportNode and all its child nodes.*/
		void doExport ( ExportNode* exportNode );

		/** Exports the camera represented by @a exportNode.*/
		void exportLight( ExportNode* exportNode );

		/** Exports the shadow parameters*/
		void exportShadowParameters(GenLight* light);


		/** Exports the Texmap @a map, i.e. adds it to \<library_images\>*/
		String exportTexMap(Texmap *map);


	};


}


#endif //__COLLADAMAX_LIGHTEXPORTER_H__

