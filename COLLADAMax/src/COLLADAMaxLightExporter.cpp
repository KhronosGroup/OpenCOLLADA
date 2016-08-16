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

#include "COLLADAMaxLightExporter.h"

#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxDocumentExporter.h"
#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxEffectExporter.h"
#include "COLLADAMaxVisualSceneExporter.h"
#include "COLLADAMaxExtra.h"
#include "COLLADASWLight.h"

#include <max.h>
#include <shadgen.h>

namespace COLLADAMax
{

	const String LightExporter::LIGHT_ID_SUFFIX = "-light";


	const String LightExporter::LIGHT_ELEMENT = "max_light";
	const String LightExporter::LIGHT_MAP_ELEMENT = "light_map";
	const int LightExporter::LIGHT_PARAMETER_COUNT = 18;
	const Extra::ExtraParameter LightExporter::LIGHT_PARAMETERS[] =
	{
		{TYPE_FLOAT, 1, "multiplier"},
		{TYPE_FLOAT, 2, "contrast"},
		{TYPE_FLOAT, 3, "diffuse_soften"},
		{TYPE_FLOAT, 4, "hotspot_beam"},
		{TYPE_FLOAT, 5, "falloff"},
		{TYPE_FLOAT, 6, "aspect_ratio"},
		{TYPE_FLOAT, 7, "attenuation_near_start"},
		{TYPE_FLOAT, 8, "attenuation_near_end"},
		{TYPE_FLOAT, 9, "attenuation_far_start"},
		{TYPE_FLOAT, 10, "attenuation_far_end"},
		{TYPE_FLOAT, 11, "decay_falloff"},
		{TYPE_RGBA, 12, "shadow_color"},
		{TYPE_INT, 13, "atmosphere_on"},
		{TYPE_FLOAT, 14, "atmosphere_opacity"},
		{TYPE_FLOAT, 15, "atmosphere_color_amount"},
		{TYPE_FLOAT, 16, "shadow_density"},
		{TYPE_INT, 17, "shadow_map"},
		{TYPE_FLOAT, 18, "target_distance"}	
	};



	const String LightExporter::SKYLIGHT_ELEMENT = "skylight";
	const String LightExporter::SKYLIGHT_COLORMAP_ELEMENT = "color_map";
	const int LightExporter::SKYLIGHT_PARAMETER_COUNT = 10;
	const Extra::ExtraParameter LightExporter::SKYLIGHT_PARAMETERS[] =
	{
		//{TYPE_RGBA, 0, "color"},				 already exported in the color element of <light>
		{TYPE_FLOAT, 1, "color_map_amount"},
		//{TYPE_TEXMAP, 2, "color_map"},		 need special handling
		{TYPE_BOOL, 3, "color_map_on"},
		{TYPE_INT, 4, "rays_per_sample"},
		{TYPE_FLOAT, 7, "mode"},
		{TYPE_FLOAT, 10, "multiplier"},
		{TYPE_FLOAT, 11, "ray_bias"},
		{TYPE_BOOL, 12, "cast_shadows"},
		{TYPE_BOOL, 13, "intensity_on"}
	};



	const String LightExporter::OVERSHOOT_PARAMETER = "overshoot";
	const String LightExporter::MULTIPLIER_PARAMETER = "multiplier";
	const String LightExporter::DECAY_TYPE_PARAMETER = "decay_type";
	const String LightExporter::DECAY_RADIUS_PARAMETER = "decay_radius";
	const String LightExporter::USE_FAR_ATTENUATION_PARAMETER = "use_far_attenuation";
	const String LightExporter::USE_NEAR_ATTENUATION_PARAMETER = "use_near_attenuation";
	const String LightExporter::NEAR_START_ATTENUATION_PARAMETER = "attenuation_near_start";
	const String LightExporter::NEAR_END_ATTENUATION_PARAMETER = "attenuation_near_end";
	const String LightExporter::FAR_START_ATTENUATION_PARAMETER = "attenuation_far_start";
	const String LightExporter::FAR_END_ATTENUATION_PARAMETER = "attenuation_far_end";

	const String LightExporter::FALLSIZE_PARAMETER = "decay_falloff";
	const String LightExporter::HOTSPOT_PARAMETER = "hotspot_beam";

	const String LightExporter::AFFECT_SPECULAR_PARAMETER = "affect_specular";
	const String LightExporter::AFFECT_DIFFUSE_PARAMETER = "affect_diffuse";

	const String LightExporter::SHADOW_ATTRIBS = "shadow_attributes";
	const String LightExporter::SHADOW_TYPE = "type";
	const String LightExporter::SHADOW_SIZE = "size";
	const String LightExporter::SHADOW_TYPE_MAP = "type_map";
	const String LightExporter::SHADOW_TYPE_RAYTRACE = "type_raytrace";
	const String LightExporter::SHADOW_AFFECTS_LIST_NODES = "affect_list_nodes";
	const String LightExporter::SHADOW_AFFECTS_LIST_EXCLUDES = "affect_list_is_exclusive";
	const String LightExporter::SHADOW_AFFECTS_LIST_ILLUMINATES = "affect_is_illuminated";
	const String LightExporter::SHADOW_AFFECTS_LIST_CASTS = "affect_casts_shadows";


	const String LightExporter::SHADOW_MAP = "shadow_map";
	const String LightExporter::SHADOW_PROJ_IMAGE = "proj_image";
	const String LightExporter::SHADOW_PROJ_COLOR = "shadow_color";
	const String LightExporter::SHADOW_PROJ_COLOR_MULT = "shadow_color_mult";
	const String LightExporter::LIGHT_AFFECTS_SHADOW = "light_affects_shadow";

	const String LightExporter::ENVIRONMENT_AMBIENT_LIGHT_NAME = "EnvironmentAmbientLight";
	const String LightExporter::ENVIRONMENT_AMBIENT_LIGHT_ID = "EnvironmentAmbientLight";


    //---------------------------------------------------------------
    LightExporter::LightExporter ( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADASW::LibraryLights ( streamWriter ),
			Extra(streamWriter, documentExporter),
			mExportSceneGraph(exportSceneGraph),
			mDocumentExporter(documentExporter),
			mAnimationExporter(documentExporter->getAnimationExporter())
    {}


	//---------------------------------------------------------------
	String LightExporter::getLightId( const ExportNode& exportNode )
	{
		return exportNode.getId() + LIGHT_ID_SUFFIX;
	}


	//---------------------------------------------------------------
	void LightExporter::doExport()
	{
		exportEnvironmentAmbientLight();
		doExport( mExportSceneGraph->getRootExportNode() );
		closeLibrary();
	}

	//---------------------------------------------------------------
	void LightExporter::exportEnvironmentAmbientLight()
	{
		// Add the ambient lighting from the environment settings
		Point3 ambientColor = mDocumentExporter->getMaxInterface()->GetAmbient(0, FOREVER);

		COLLADASW::Color ambientLightColor = EffectExporter::maxColor2Color( ambientColor );

		COLLADASW::AmbientLight ambientLight(COLLADASW::LibraryLights::mSW, ENVIRONMENT_AMBIENT_LIGHT_ID, ENVIRONMENT_AMBIENT_LIGHT_NAME);

		ambientLight.setColor( ambientLightColor );
		addLight( ambientLight );
	}

	//---------------------------------------------------------------
	void LightExporter::doExport( ExportNode* exportNode )
	{
		if ( exportNode->getType() == ExportNode::LIGHT )
			exportLight(exportNode);

		size_t numberOfChildren = exportNode->getNumberOfChildren();
		for ( size_t i = 0; i < numberOfChildren; ++i )
			doExport( exportNode->getChild ( i ) );
	}


	//---------------------------------------------------------------
	void LightExporter::exportLight( ExportNode* exportNode )
	{
		if ( !exportNode->getIsInVisualScene() )
			return;
		
		String lightId = getLightId(*exportNode);

		INode * iNode = exportNode->getINode();

		LightObject* lightObject = (LightObject*) (iNode->GetObjectRef());

		if ( !lightObject )
			return;

		if (  mDocumentExporter->isExportedObject(ObjectIdentifier(lightObject)) )
			return;

		mDocumentExporter->insertExportedObject(ObjectIdentifier(lightObject), exportNode);

		// Retrieve the target node, if we are not baking matrices.
		// Baked matrices must always sample the transform!
		ULONG ClassId = lightObject->ClassID().PartA();
		bool isTargeted = !mDocumentExporter->getOptions().getBakeMatrices() && (ClassId == SPOT_LIGHT_CLASS_ID || ClassId == TDIR_LIGHT_CLASS_ID);
		
		INode* targetNode = isTargeted ? iNode->GetTarget() : 0;

		// some lights are not supported at all
		switch (ClassId)
		{
		case FSPOT_LIGHT_CLASS_ID:
		case SPOT_LIGHT_CLASS_ID:
		case DIR_LIGHT_CLASS_ID: 
		case TDIR_LIGHT_CLASS_ID:
		case SKY_LIGHT_CLASS_ID_PART_A:
		case OMNI_LIGHT_CLASS_ID:
			break;
		default:
			return;
		}


		// Determine the light's type
		bool isSpot = false;
		bool isDirectional = false;
		bool isPoint = false;
		bool isSky = false;

		COLLADASW::Light::LightType lightType;

		switch (ClassId)
		{
		case FSPOT_LIGHT_CLASS_ID:
		case SPOT_LIGHT_CLASS_ID: 
			lightType = COLLADASW::Light::SPOT; 
			isSpot = true; 
			break;
		case DIR_LIGHT_CLASS_ID: 
		case TDIR_LIGHT_CLASS_ID: 
			lightType = COLLADASW::Light::DIRECTIONAL; 
			isDirectional = true; 
			break;
		case SKY_LIGHT_CLASS_ID_PART_A:
			lightType = COLLADASW::Light::POINT; 
			isSky = true;
			break;
		case OMNI_LIGHT_CLASS_ID:
			lightType = COLLADASW::Light::POINT; 
			isPoint = true;
			break;
		}

		COLLADASW::Light * colladaLight = 0;

		switch ( lightType )
		{
		case COLLADASW::Light::DIRECTIONAL:
			colladaLight = new COLLADASW::DirectionalLight(COLLADASW::LibraryLights::mSW, lightId, COLLADASW::Utils::checkNCName(NativeString(exportNode->getINode()->GetName())));
			break;
		case COLLADASW::Light::POINT:
			colladaLight = new COLLADASW::PointLight(COLLADASW::LibraryLights::mSW, lightId, COLLADASW::Utils::checkNCName(NativeString(exportNode->getINode()->GetName())));
			break;
		case COLLADASW::Light::SPOT:
			colladaLight = new COLLADASW::SpotLight(COLLADASW::LibraryLights::mSW, lightId, COLLADASW::Utils::checkNCName(NativeString(exportNode->getINode()->GetName())));
			break;
		}

		// Retrieve the parameter block
		IParamBlock* parameters = 0;
		IParamBlock2* parametersSky = 0;

		if (isSky)
			parametersSky = (IParamBlock2*) lightObject->GetReference(MaxLight::PBLOCK_REF_SKY);
		else
			parameters = (IParamBlock*) lightObject->GetReference(MaxLight::PBLOCK_REF);

		if (!parameters && !parametersSky)
		{
			delete colladaLight;
			return;
		}


		if (parameters)
		{
			GenLight* light = (GenLight*)(lightObject);
			float intensity = light->GetIntensity( 0 );
			bool hasAnimatedColor = mAnimationExporter->addAnimatedParameter(parameters, MaxLight::PB_COLOR, lightId, colladaLight->getColorDefaultSid(), 0 );
			colladaLight->setColor(EffectExporter::maxColor2Color(parameters->GetColor(MaxLight::PB_COLOR) * intensity), hasAnimatedColor);
		}
		else if (parametersSky )
		{
			bool hasAnimatedColor = mAnimationExporter->addAnimatedParameter(parametersSky, MaxLight::PB_SKY_COLOR, lightId, colladaLight->getColorDefaultSid(), 0 );
			colladaLight->setColor(EffectExporter::maxColor2Color(parametersSky->GetColor(MaxLight::PB_SKY_COLOR)), hasAnimatedColor);
		}


		if (isSpot || isPoint)
		{
			GenLight* light = (GenLight*)(lightObject);
			int decayFunction = (int)light->GetDecayType();
			switch (decayFunction)
			{
			case 1:
				colladaLight->setConstantAttenuation(0.0f);
				colladaLight->setLinearAttenuation(1.0f);
				break;
			case 2:
				colladaLight->setConstantAttenuation(0.0f);
				colladaLight->setQuadraticAttenuation(1.0f);
				break;
			case 0:
			default:
				colladaLight->setConstantAttenuation(1.0f);
				break;
			}
		}
		else if (isSky)
		{
			colladaLight->setConstantAttenuation(1.0f);
		}

		setExtraTechnique(colladaLight);


		if ( parameters )
		{
			//addParamBlockAnimatedExtraParameters(LIGHT_ELEMENT, LIGHT_PARAMETERS, LIGHT_PARAMETER_COUNT, parameters, lightId);
		}
		else
			addParamBlockAnimatedExtraParameters(SKYLIGHT_ELEMENT, SKYLIGHT_PARAMETERS, SKYLIGHT_PARAMETER_COUNT, parametersSky, lightId);

		// add all the information to extra tag, that are not contained in IParamBlock
		if (isSpot || isDirectional || isPoint)
		{
			GenLight* light = (GenLight*)(lightObject);

			if (!light)
			{
				delete colladaLight;
				return;
			}

			// do not export turned off lights
			if (light->GetUseLight() != TRUE) {
				delete colladaLight;
				return;
			}


			// Export the overshoot flag for directional lights
			if (isDirectional || isSpot)
			{
				addExtraChildParameter(LIGHT_ELEMENT, OVERSHOOT_PARAMETER, light->GetOvershoot() != false);
			}

			addExtraChildParameter(LIGHT_ELEMENT, AFFECT_SPECULAR_PARAMETER, (int)light->GetAffectSpecular());
			addExtraChildParameter(LIGHT_ELEMENT, AFFECT_DIFFUSE_PARAMETER, (int)light->GetAffectDiffuse());

			addExtraChildParameter(LIGHT_ELEMENT, DECAY_TYPE_PARAMETER, (int)light->GetDecayType());
			addExtraChildParameter(LIGHT_ELEMENT, MULTIPLIER_PARAMETER, light->GetIntensity( 0 ));
			addExtraChildParameter(LIGHT_ELEMENT, DECAY_RADIUS_PARAMETER, light->GetDecayRadius( 0 ));
			addExtraChildParameter(LIGHT_ELEMENT, USE_NEAR_ATTENUATION_PARAMETER, (light->GetUseAttenNear() != false));
			addExtraChildParameter(LIGHT_ELEMENT, USE_FAR_ATTENUATION_PARAMETER, (light->GetUseAtten() != false));
			addExtraChildParameter(LIGHT_ELEMENT, NEAR_START_ATTENUATION_PARAMETER, light->GetAtten( 0, ATTEN1_START ) );
			addExtraChildParameter(LIGHT_ELEMENT, NEAR_END_ATTENUATION_PARAMETER, light->GetAtten( 0, ATTEN1_END ) );
			addExtraChildParameter(LIGHT_ELEMENT, FAR_START_ATTENUATION_PARAMETER, light->GetAtten( 0, ATTEN_START ) );
			addExtraChildParameter(LIGHT_ELEMENT, FAR_END_ATTENUATION_PARAMETER, light->GetAtten( 0, ATTEN_END ) );

			if (isSpot) {
				addExtraChildParameter(LIGHT_ELEMENT, FALLSIZE_PARAMETER, light->GetFallsize( 0 ) );
				addExtraChildParameter(LIGHT_ELEMENT, HOTSPOT_PARAMETER, light->GetHotspot( 0 ) );
			}

			exportShadowParameters(light);

			if (light->GetProjector())
			{
				Texmap* projectorMap = light->GetProjMap();
				if (projectorMap)
				{
					String imageId = exportTexMap(projectorMap);
					if ( !imageId.empty() )
					{
						addExtraChildParameter(LIGHT_ELEMENT, LIGHT_MAP_ELEMENT, "#" + imageId);
					}
				}
			}


		}
		else // isSky
		{
			Texmap *colorMap = parametersSky->GetTexmap(MaxLight::PB_SKY_COLOR_MAP, mDocumentExporter->getOptions().getAnimationStart());
			
			String imageId = exportTexMap(colorMap);
			if ( !imageId.empty())
			{
				addExtraChildParameter(SKYLIGHT_ELEMENT, SKYLIGHT_COLORMAP_ELEMENT, "#" + imageId);
			}
		}

		addLight(*colladaLight);

		delete colladaLight;

	}


	void LightExporter::exportShadowParameters(GenLight* light)
	{
		// Export light shadow attributes
		if (light->GetShadow())
		{
			// Light casts shadows
			int shadowType = light->GetShadowType();
			if (shadowType == 0) {
				addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_TYPE, SHADOW_TYPE_MAP);
				int size = light->GetShadowGenerator()->GetMapSize(0);
				addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_SIZE, size);				
			}
			else if (shadowType == 1) 
				addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_TYPE, SHADOW_TYPE_RAYTRACE);

			// GetExclusion list
			ExclList& exclusions = light->GetExclusionList();
			int exclusionsCount = exclusions.Count();
			if (exclusionsCount > 0)
			{
				String nodeURIs;
				for (int i = 0; i < exclusionsCount; i++)
				{
					INode* affectedNode = exclusions[i];
					if ( !affectedNode ) 
						continue;

					if ( !nodeURIs.empty() ) 
						nodeURIs += " ";

					ExportNode* affectedExportNode = mExportSceneGraph->getExportNode(affectedNode);
					String nodeURI = '#' + VisualSceneExporter::getNodeId(*affectedExportNode);
					nodeURIs += nodeURI;
				}
				addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_AFFECTS_LIST_NODES, nodeURIs);

				if (!exclusions.TestFlag(NT_INCLUDE))
				{
					addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_AFFECTS_LIST_EXCLUDES, 1);
				}
				if (exclusions.TestFlag(NT_AFFECT_ILLUM))
				{
					addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_AFFECTS_LIST_ILLUMINATES, 1);
				}
				if (exclusions.TestFlag(NT_AFFECT_SHADOWCAST))
				{
					addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_AFFECTS_LIST_CASTS, 1);
				}
			}

			// Export our shadow projection map
			Texmap* shadowProj = light->GetShadowProjMap();
			if (shadowProj)
			{
				IParamBlock* pblock = (IParamBlock*)light->GetReference(MaxLight::PBLOCK_REF);
				int shadowProjectionOn;
				pblock->GetValue(MaxLight::PB_OMNISHAD_COLMAP, 0, shadowProjectionOn, Interval::FOREVER);
				if (shadowProjectionOn)
				{
					String imageId = exportTexMap(shadowProj);
					if ( !imageId.empty() )
						addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_PROJ_IMAGE, "#" + imageId);
				}
				else
				{
					// Non-animatable is all they get
					Point3 shadowColor = light->GetShadColor(mDocumentExporter->getOptions().getAnimationStart());
					String shadowColorString = COLLADASW::Utils::toString(shadowColor.x) + COLLADASW::Utils::toString(shadowColor.y) + COLLADASW::Utils::toString(shadowColor.z);
					addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_PROJ_COLOR, shadowColorString);
					addExtraChildParameter(SHADOW_ATTRIBS, SHADOW_PROJ_COLOR_MULT, light->GetShadMult(0));
				}
				addExtraChildParameter(SHADOW_ATTRIBS, LIGHT_AFFECTS_SHADOW, light->GetLightAffectsShadow());
			}
		}
	}



	String LightExporter::exportTexMap(Texmap *map)
	{
		if ( map )
		{
			String fullFileName;
			return mDocumentExporter->getEffectExporter()->exportImage(map, fullFileName);
		}
		return EMPTY_STRING;
	}


}
