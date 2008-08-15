/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaLightExporter.h"
#include "COLLADAMayaExportOptions.h"

#include <maya/MFnLight.h>
#include <maya/MFnNonAmbientLight.h>
#include <maya/MFnAmbientLight.h>
#include <maya/MFnSpotLight.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    LightExporter::LightExporter ( 
        COLLADA::StreamWriter* streamWriter,
        DocumentExporter* documentExporter )
    : COLLADA::LibraryLights ( streamWriter )
    , mDocumentExporter ( documentExporter )
    {}


    //---------------------------------------------------------------
    void LightExporter::exportLights ( )
    {
        if ( !ExportOptions::exportLights() ) return;

        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        uint length = exportNodesTree->size();
        for ( uint i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            exportLights ( sceneElement );
        }

        closeLibrary();
    }

    //---------------------------------------------------------------
    void LightExporter::exportLights ( SceneElement* sceneElement )
    {
        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Check if it is a mesh and an export node
        if ( sceneElement->getType() == SceneElement::LIGHT &&
             sceneElement->getIsExportNode() )
        {
            // Export the geometry 
            bool exported = exportLight ( dagPath );

            // Push it in the list of exported elements.
            if ( exported )
                mDocumentExporter->getSceneGraph()->addExportedElement( sceneElement );
        }


        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportLights ( childElement );
        }
    }

    // --------------------------------------------------------
    bool LightExporter::exportLight ( const MDagPath& dagPath )
    {
        if ( !ExportOptions::exportLights() ) return false;

        MObject lightNode = dagPath.node();

        // Retrieve the Maya light object
        MStatus status;
        MFnLight lightFn(lightNode, &status); CHECK_MSTATUS(status);
        if (status != MStatus::kSuccess) return false;

        // Generate a COLLADA id for the new light object
        String lightId = mDocumentExporter->dagPathToColladaId ( dagPath );
        String lightName = mDocumentExporter->dagPathToColladaName ( dagPath );

        // Color/Intensity are the common attributes of all lights
        MColor mayaColor = lightFn.color(&status); 
        CHECK_MSTATUS(status);
        COLLADA::Color lightColor ( mayaColor.r, mayaColor.g, mayaColor.b, mayaColor.a );
        // TODO
//        ANIM->AddPlugAnimation(lightNode, "color", colladaLight->GetColor(), kColour);

        float intensity = lightFn.intensity(&status); 
        CHECK_MSTATUS(status);
        // TODO
//        ANIM->AddPlugAnimation(lightNode, "intensity", colladaLight->GetIntensity(), kSingle);

        // Get a pointer to the stream writer.
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Figure out the type of light and create it
        COLLADA::Light* light = NULL;
        MFn::Type type = lightNode.apiType();
        switch (type)
        {
        case MFn::kAmbientLight: 
            light = new COLLADA::AmbientLight( streamWriter, lightId, lightColor, intensity, lightName); 
            break; 
        case MFn::kDirectionalLight: 
            light = new COLLADA::DirectionalLight( streamWriter, lightId, lightColor, intensity, lightName); 
            break;
        case MFn::kSpotLight: 
            light = new COLLADA::SpotLight( streamWriter, lightId, lightColor, intensity, lightName); 
            break;
        case MFn::kPointLight: // Intentional pass-through
        default: 
            light = new COLLADA::PointLight( streamWriter, lightId, lightColor, intensity, lightName); 
            break;
        }

        // Add the type specific attributes
        if (lightNode.hasFn(MFn::kNonAmbientLight))
        {
            // Needed Point and Spot light types parameters: Attenuation and Attenuation_Scale
            // Attenuation in COLLADA is equal to Decay in Maya.
            MFnNonAmbientLight naLightFn(lightNode);
            int decayRate = naLightFn.decayRate(&status); CHECK_MSTATUS(status);
            decayRate = min(decayRate, 2); decayRate = max(decayRate, 0);

            light->setConstantAttenuation((decayRate == 0) ? 1.0f : 0.0f);
            light->setLinearAttenuation((decayRate == 1) ? 1.0f : 0.0f);
            light->setQuadraticAttenuation((decayRate == 2) ? 1.0f : 0.0f);
        }
        else if (lightNode.hasFn(MFn::kAmbientLight))
        {
            MFnAmbientLight ambientLightFn ( lightNode );
//             FCDETechnique* mayaTechnique = light->GetExtra()->GetDefaultType()->AddTechnique(DAEMAYA_MAYA_PROFILE);
//             FCDENode* ambientShadeParameter = mayaTechnique->AddParameter(DAEMAYA_AMBIENTSHADE_LIGHT_PARAMETER, ambientLightFn.ambientShade());
//            ANIM->AddPlugAnimation(lightNode, "ambientShade", ambientShadeParameter->GetAnimated(), kSingle);
        }

        if (lightNode.hasFn(MFn::kSpotLight))
        {
            // Put in the needed spot light type attributes : Falloff, Falloff_Scale and Angle
            MFnSpotLight spotFn(lightNode);

            float fallOffAngle = COLLADA::MathUtils::radToDegF( (float)spotFn.coneAngle(&status) ); 
            CHECK_MSTATUS(status);
            light->setFallOffAngle( fallOffAngle );
//            ANIM->AddPlugAnimation(lightNode, "coneAngle", colladaLight->GetFallOffAngle(), kSingle | kAngle);
            light->setFallOffExponent(1.0f);

            float penumbraValue = COLLADA::MathUtils::radToDegF ( (float)spotFn.penumbraAngle(&status) ); 
            CHECK_MSTATUS(status);
//            ANIM->AddPlugAnimation(lightNode, "penumbraAngle", colladaLight->GetOuterAngle(), kSingle | kAngle);
//            FCDLightTools::LoadPenumbra(light, penumbraValue, colladaLight->GetOuterAngle().GetAnimated());

//            light->SetDropoff((float) spotFn.dropOff(&status)); CHECK_MSTATUS(status);
//            ANIM->AddPlugAnimation(lightNode, "dropoff", colladaLight->GetDropoff(), kSingle);
        }
        
        addLight ( *light );

        return true;
    }

}