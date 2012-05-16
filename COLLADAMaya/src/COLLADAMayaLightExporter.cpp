/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADAMayaAnimationExporter.h"

#include <maya/MFnLight.h>
#include <maya/MFnNonAmbientLight.h>
#include <maya/MFnAmbientLight.h>
#include <maya/MFnSpotLight.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    LightExporter::LightExporter ( 
        COLLADASW::StreamWriter* streamWriter,
        DocumentExporter* documentExporter )
    : COLLADASW::LibraryLights ( streamWriter )
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
        size_t length = exportNodesTree->size();
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
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;
        if ( !sceneElement->getIsExportNode () ) return;

        // Check if it is a light.
        SceneElement::Type sceneElementType = sceneElement->getType();
        if ( sceneElementType == SceneElement::LIGHT )
        {
            // Get the current dag path
            MDagPath dagPath = sceneElement->getPath();

            // Check if the current scene element isn't already exported.
            SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
            if ( sceneGraph->findExportedElement ( dagPath ) ) return;

            // Check if the current element is an instance. 
            // We don't need to export instances, because we export the original instanced element.
            bool isInstance = ( dagPath.isInstanced() && dagPath.instanceNumber() > 0 );

            // If the original instanced element isn't already exported, we have to export it now.
            if ( isInstance )
            {
                // Get the original instanced element.
                MDagPath instancedPath;
                dagPath.getPath ( instancedPath, 0 );

                // Check if the original instanced element is already exported.
                SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
                SceneElement* exportedElement = sceneGraph->findExportedElement ( instancedPath );
                if ( exportedElement == 0 )
                {
                    // Export the original instanced element and push it in the exported scene graph. 
                    if ( exportLight ( instancedPath ) )
                    {
                        SceneElement* instancedSceneElement = sceneGraph->findElement ( instancedPath );
                        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
                        sceneGraph->addExportedElement( instancedSceneElement );
                    }
                }
            }
            else
            {
                // Export the element and push it in the exported scene graph. 
                if ( exportLight ( dagPath ) )
                {
                    SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
                    sceneGraph->addExportedElement( sceneElement );
                }
            }
        }


        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportLights ( childElement );
        }
    }

    // ------------------------------------
    bool LightExporter::exportLight ( const MDagPath& dagPath )
    {
        if ( !ExportOptions::exportLights() ) return false;

        MObject lightNode = dagPath.node();

        // Retrieve the Maya light object
        MStatus status;
        MFnLight lightFn(lightNode, &status); CHECK_STAT(status);
        if (status != MStatus::kSuccess) return false;

        // Get the maya light id.
        String mayaLightId = mDocumentExporter->dagPathToColladaId ( dagPath );

        // Generate a COLLADA id for the new object
        String colladaLightId;
        
        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( lightNode, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            colladaLightId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
        }
        else
        {
            // Generate a COLLADA id for the new object
            colladaLightId = mDocumentExporter->dagPathToColladaId ( dagPath );
        }
        // Make the id unique and store it in a map.
        colladaLightId = mLightIdList.addId ( colladaLightId );
        mMayaIdColladaIdMap [ mayaLightId ] = colladaLightId;

        // Get a pointer to the stream writer.
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // The light name
        String lightName = mDocumentExporter->dagPathToColladaName ( dagPath );

        // Figure out the type of light and create it
        COLLADASW::Light* light = NULL;
        MFn::Type type = lightNode.apiType();
        switch (type)
        {
        case MFn::kAmbientLight: 
            light = new COLLADASW::AmbientLight( streamWriter, colladaLightId, lightName ); 
            break; 
        case MFn::kDirectionalLight: 
            light = new COLLADASW::DirectionalLight( streamWriter, colladaLightId, lightName ); 
            break;
        case MFn::kSpotLight: 
            light = new COLLADASW::SpotLight( streamWriter, colladaLightId, lightName ); 
            break;
        case MFn::kPointLight: // Intentional pass-through
        default: 
            light = new COLLADASW::PointLight( streamWriter, colladaLightId, lightName ); 
            break;
        }

        // Export the original maya name.
        light->addExtraTechniqueParameter ( PROFILE_MAYA, PARAMETER_MAYA_ID, mayaLightId );

        // Get a pointer to the animation exporter.
        AnimationExporter* anim = mDocumentExporter->getAnimationExporter();
        bool animated = false;
        
        // Color/Intensity are the common attributes of all lights
        MColor mayaColor = lightFn.color ( &status ); CHECK_STAT(status);
        COLLADASW::Color lightColor ( mayaColor.r, mayaColor.g, mayaColor.b, mayaColor.a );
        animated = anim->addNodeAnimation ( lightNode, ATTR_COLOR, kColour, RGBA_PARAMETERS );
        light->setColor( lightColor, animated );

        float intensity = lightFn.intensity ( &status ); CHECK_STAT(status);
        animated = anim->addNodeAnimation ( lightNode, ATTR_INTENSITY, kSingle );
        light->setIntensity( intensity, animated );

        // Add the type specific attributes
        if (lightNode.hasFn(MFn::kNonAmbientLight))
        {
            // Needed Point and Spot light types parameters: Attenuation and Attenuation_Scale
            // Attenuation in COLLADA is equal to Decay in Maya.
            MFnNonAmbientLight naLightFn(lightNode);
            int decayRate = naLightFn.decayRate(&status); CHECK_STAT(status);
            decayRate = std::min ( decayRate, 2 ); 
            decayRate = std::max ( decayRate, 0 );

            light->setConstantAttenuation ( ( decayRate == 0 ) ? 1.0f : 0.0f);
            light->setLinearAttenuation ( ( decayRate == 1 ) ? 1.0f : 0.0f);
            light->setQuadraticAttenuation ( ( decayRate == 2 ) ? 1.0f : 0.0f);
        }
        else if (lightNode.hasFn(MFn::kAmbientLight))
        {
            MFnAmbientLight ambientLightFn ( lightNode );
            float ambientShade = ambientLightFn.ambientShade();
            String paramSid = EMPTY_STRING;
            animated = anim->addNodeAnimation ( lightNode, ATTR_AMBIENT_SHADE, kSingle );
            if ( animated ) paramSid = ATTR_AMBIENT_SHADE;
            light->addExtraTechniqueParameter ( PROFILE_MAYA, MAYA_AMBIENTSHADE_LIGHT_PARAMETER, ambientShade, paramSid );
        }

        if (lightNode.hasFn(MFn::kSpotLight))
        {
            // Put in the needed spot light type attributes : Falloff, Falloff_Scale and Angle
            MFnSpotLight spotFn(lightNode);

            float fallOffAngle = COLLADABU::Math::Utils::radToDegF ( (float)spotFn.coneAngle( &status ) ); CHECK_STAT(status);
            animated = anim->addNodeAnimation ( lightNode, ATTR_CONE_ANGLE, ( SampleType ) ( kSingle | kAngle ) );
            light->setFallOffAngle ( fallOffAngle, animated );

            light->setFallOffExponent ( 1.0f );

            float penumbraValue = COLLADABU::Math::Utils::radToDegF ( (float)spotFn.penumbraAngle( &status ) ); CHECK_STAT(status);
            animated = anim->addNodeAnimation ( lightNode, ATTR_PENUMBRA_ANGLE, ( SampleType ) ( kSingle | kAngle ) );
            // TODO
//            FCDLightTools::LoadPenumbra(light, penumbraValue, colladaLight->GetOuterAngle().GetAnimated());

            // TODO
//             animated = anim->addNodeAnimation ( lightNode, ATTR_DROP_OFF, kSingle );
//             light->setDropOff ( (float) spotFn.dropOff ( &status ), animated ); CHECK_MSTATUS(status);
        }
        
        addLight ( *light );
        delete light;

        return true;
    }

    // ------------------------------------
    const String LightExporter::findColladaLightId ( const String& mayaLightId )
    {
        const StringToStringMap::const_iterator it = mMayaIdColladaIdMap.find ( mayaLightId );
        if ( it != mMayaIdColladaIdMap.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }

}