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


#ifndef __COLLADAMAX_LIGHTEXPORTER_H__
#define __COLLADAMAX_LIGHTEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAMaxExtra.h"

#include "COLLADASWLibraryLights.h"



namespace COLLADAMax
{

	class ExportSceneGraph;
	class ExportNode;
	class DocumentExporter;
	class AnimationExporter;


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
		static const String MULTIPLIER_PARAMETER;
		static const String DECAY_TYPE_PARAMETER;
		static const String DECAY_RADIUS_PARAMETER;
		static const String USE_FAR_ATTENUATION_PARAMETER;
		static const String USE_NEAR_ATTENUATION_PARAMETER;
		static const String NEAR_START_ATTENUATION_PARAMETER;
		static const String NEAR_END_ATTENUATION_PARAMETER;
		static const String FAR_START_ATTENUATION_PARAMETER;
		static const String FAR_END_ATTENUATION_PARAMETER;


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

		static const String ENVIRONMENT_AMBIENT_LIGHT_NAME;
		static const String ENVIRONMENT_AMBIENT_LIGHT_ID;


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
		/** Exports the environment ambient color.*/
		void exportEnvironmentAmbientLight();

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

