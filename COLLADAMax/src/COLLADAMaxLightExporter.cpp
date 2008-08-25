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

#include "COLLADAMaxLightExporter.h"

#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxDocumentExporter.h"
#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxExtra.h"
#include "COLLADALight.h"
//#include "COLLADAMaxConversionFunctor.h"

#include <max.h>

namespace COLLADAMax
{

	const String LightExporter::LIGHT_ID_SUFFIX = "-light";


    //---------------------------------------------------------------
    LightExporter::LightExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADA::LibraryLights ( streamWriter ),
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
		doExport ( mExportSceneGraph->getRootExportNode() );
		closeLibrary();
	}



	//---------------------------------------------------------------
	void LightExporter::doExport( ExportNode* exportNode )
	{
		if ( exportNode->getType() == ExportNode::LIGHT )
			exportLight(exportNode);

		size_t numberOfChildren = exportNode->getNumberOfChildren();
		for ( size_t i = 0; i < numberOfChildren; ++i )
			doExport ( exportNode->getChild ( i ) );
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

		COLLADA::Light::LightType lightType;

		switch (ClassId)
		{
		case FSPOT_LIGHT_CLASS_ID:
		case SPOT_LIGHT_CLASS_ID: 
			lightType = COLLADA::Light::SPOT; 
			isSpot = true; 
			break;
		case DIR_LIGHT_CLASS_ID: 
		case TDIR_LIGHT_CLASS_ID: 
			lightType = COLLADA::Light::DIRECTIONAL; 
			isDirectional = true; 
			break;
		case SKY_LIGHT_CLASS_ID_PART_A:
			lightType = COLLADA::Light::POINT; 
			isSky = true;
			break;
		case OMNI_LIGHT_CLASS_ID:
			lightType = COLLADA::Light::POINT; 
			isPoint = true;
			break;
		}

		COLLADA::Light * colladaLight = 0;

		switch ( lightType )
		{
		case COLLADA::Light::DIRECTIONAL:
			colladaLight = new COLLADA::DirectionalLight(mSW, lightId, 1.0, COLLADA::Utils::checkNCName(exportNode->getINode()->GetName()));
			break;
		case COLLADA::Light::POINT:
			colladaLight = new COLLADA::PointLight(mSW, lightId, 1.0, COLLADA::Utils::checkNCName(exportNode->getINode()->GetName()));
			break;
		case COLLADA::Light::SPOT:
			colladaLight = new COLLADA::SpotLight(mSW, lightId, 1.0, COLLADA::Utils::checkNCName(exportNode->getINode()->GetName()));
			break;
		}

		// Retrieve the parameter block
		IParamBlock* parameters = 0;
		IParamBlock2* parametersSky = 0;

		if (isSky)
		{
			parametersSky = (IParamBlock2*) lightObject->GetReference(MaxLight::PBLOCK_REF_SKY);
		}
		else
		{
			parameters = (IParamBlock*) lightObject->GetReference(MaxLight::PBLOCK_REF);
		}

		if (!parameters && !parametersSky)
			return;


		delete colladaLight;

	}


	void LightExporter::exportExtraParameter(const String & parameterName, const String& childName, IParamBlock2* parameters, int parameterIndex, const String& cameraId)
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
