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
#include "COLLADAMaxLightImporter.h"

#include "COLLADAFWLight.h"


namespace COLLADAMax
{


	/** Converts @a color to a max Point3. @a color must be valid.*/
	Point3 toMaxPoint3( const COLLADAFW::Color& color )
	{
		assert(color.isValid());
		return Point3(color.getRed(), color.getGreen(), color.getBlue());
	}

	
	//------------------------------
	LightImporter::LightImporter( DocumentImporter* documentImporter, const COLLADAFW::Light* light )
		: ImporterBase(documentImporter)
		, mLight(light)
	{
	}

    //------------------------------
	LightImporter::~LightImporter()
	{
	}

	//------------------------------
	bool LightImporter::import()
	{

		addLight( *mLight );
		LightObject* maxLight = createLight(mLight);

		handleObjectReferences(mLight, maxLight);

		return true;
	}

	//------------------------------
	LightObject* LightImporter::createLight( const COLLADAFW::Light* light )
	{
		LightObject* maxLight = 0;
		const SkyLightParameters* skyLightParameters = getSkyLightParametersByUniqueId(light->getUniqueId());
		if ( skyLightParameters )
		{
			maxLight = createSkyLight(light, skyLightParameters);
		}
		else
		{
			maxLight = createGenericLight(light);
		}
		return maxLight;
	}

	//------------------------------
	GenLight* LightImporter::createGenericLight( const COLLADAFW::Light* light )
	{
		// ambient, spot, directional, point

		// Create the correctly-typed 3dsMax light object
		int maxLightType;
		COLLADAFW::Light::LightType lightType = light->getLightType();
		switch (lightType)
		{
		case COLLADAFW::Light::AMBIENT_LIGHT:
			// Ambient lighting is global and additive, in 3dsMax,
			// let the DocumentImporter object handle them
			createAndAddAmbientLight( light );
			return 0;
		case COLLADAFW::Light::POINT_LIGHT: 
			maxLightType = OMNI_LIGHT; 
			break;
		case COLLADAFW::Light::DIRECTIONAL_LIGHT: 
			maxLightType = /*(isTargeted) ? TDIR_LIGHT : */DIR_LIGHT; 
			break;
		case COLLADAFW::Light::SPOT_LIGHT: 
			maxLightType = /*(isTargeted) ? TSPOT_LIGHT :*/ FSPOT_LIGHT; 
			break;
		default: 
			return 0;
		}
		GenLight* maxLight = getMaxImportInterface()->CreateLightObject(maxLightType);

		float targetDistance = 0.0f;
		targetDistance = 120.0f; // may change later on if the MAX profile value was found.

		maxLight->SetTDist(0, targetDistance);

		if (lightType == COLLADAFW::Light::DIRECTIONAL_LIGHT)
		{
			maxLight->SetOvershoot(TRUE); // may change later on if the MAX profile value was found.
		}

		// Decay rates are available, in Max, on all light types
		// Figure out the decay type, since Max only allows for one attenuation factor
		// forget about the decay being animated, COLLADA doesn't support that.
		int decayType = 0;
		if (lightType == COLLADAFW::Light::POINT_LIGHT || lightType == COLLADAFW::Light::SPOT_LIGHT)
		{
			if ( light->getConstantAttenuation() > 0 ) 
				decayType = 0;
			else if ( light->getLinearAttenuation() > 0 ) 
				decayType = 1;
			else 
				decayType = 2;
		}

		maxLight->SetDecayType(decayType);

		if (lightType == COLLADAFW::Light::SPOT_LIGHT || lightType == COLLADAFW::Light::DIRECTIONAL_LIGHT)
		{
			// Force the spot to be a circle. Some of the light values seem to be
			// missing default assignation on construction and instead inherit
			// unknown values from previous, deleted scenes.
			maxLight->SetSpotShape(CIRCLE_LIGHT);

			// Angles are shared between spot and directional lights.
			double fallOffAngle = light->getFallOffAngle();
			maxLight->SetHotspot(0, (float)fallOffAngle);

			// Max crashes when the fallsize is less or equal to the hotspot
			maxLight->SetFallsize(0, (float)(fallOffAngle * 1.001));
		}

		// Common light parameters
		Point3 color = toMaxPoint3(light->getColor());
		maxLight->SetRGBColor(0, color);
	//	maxLight->SetIntensity(0, colladaLight->GetIntensity());

		// Enable  light
		maxLight->Enable(TRUE);
		maxLight->SetUseLight(TRUE);


		return maxLight;
	}


	//------------------------------
	LightObject* LightImporter::createSkyLight( const COLLADAFW::Light* light, const SkyLightParameters* skyLightParameters )
	{
		void* lightMaxObject = createMaxObject(LIGHT_CLASS_ID, SKY_LIGHT_CLASS_ID);
		LightObject* skyLight = (LightObject*)lightMaxObject;

		IParamBlock2* skyLightParams = (IParamBlock2*) skyLight->GetReference(MaxLight::PBLOCK_REF_SKY);

		Point3 color = toMaxPoint3(light->getColor());

		// param id documented in const Extra::ExtraParameter LightExporter::SKYLIGHT_PARAMETERS
		skyLightParams->SetValue(0, 0, color);
		skyLightParams->SetValue(1, 0, skyLightParameters->colorMapAmount);
		skyLightParams->SetValue(3, 0, skyLightParameters->colorMapOn);
		skyLightParams->SetValue(4, 0, skyLightParameters->raysPerSample);
		skyLightParams->SetValue(7, 0, skyLightParameters->mode);
		skyLightParams->SetValue(10, 0, skyLightParameters->multiplier);
		skyLightParams->SetValue(11, 0, skyLightParameters->rayBias);
		skyLightParams->SetValue(12, 0, skyLightParameters->castShadows);
		skyLightParams->SetValue(13, 0, skyLightParameters->intensityOn);

		return skyLight;
	}

	//------------------------------
	void LightImporter::createAndAddAmbientLight( const COLLADAFW::Light* light )
	{
		if ( light->getLightType() == COLLADAFW::Light::AMBIENT_LIGHT )
		{
			getDocumentImporter()->addAmbientColor(light->getColor());
		}
	}
} // namespace COLLADAMax
