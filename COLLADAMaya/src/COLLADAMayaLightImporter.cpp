/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaLightImporter.h"
#include "COLLADAMayaVisualSceneImporter.h"
#include "COLLADAMayaMaterialImporter.h"

#include "math\COLLADABUMathUtils.h"

#include "COLLADAFWLight.h"

#include <MayaDMCommands.h>
#include <MayaDMLight.h>
#include <MayaDMAmbientLight.h>
#include <MayaDMDirectionalLight.h>
#include <MayaDMLightList.h>
#include <MayaDMObjectSet.h>


namespace COLLADAMaya
{

    const String LightImporter::LIGHT_NAME = "Light";
    const String LightImporter::INITIAL_LIGHT_LIST = ":lightList1";
    const String LightImporter::DEFAULT_LIGHT_SET = ":defaultLightSet";
    const String LightImporter::LIGHT_LINKER_NAME = "lightLinker1";


    //------------------------------
	LightImporter::LightImporter ( DocumentImporter* documentImporter ) 
        : BaseImporter ( documentImporter )
        , mLightLinker (0)
	{
	}
	
    //------------------------------
	LightImporter::~LightImporter()
	{
        delete mLightLinker;

        UniqueIdLightNodeMap::const_iterator it = mMayaLightMap.begin ();
        if ( it != mMayaLightMap.end () )
        {
            MayaDM::Light* light = it->second;
            delete light;
        }
	}

    //------------------------------
    void LightImporter::createLightLinker ()
    {
        if ( mLightLinker == 0 )
        {
            FILE* file = getDocumentImporter ()->getFile ();
            mLightLinker = new MayaDM::LightLinker ( file, LIGHT_LINKER_NAME );
        }
    }

    //------------------------------
    void LightImporter::importLight ( const COLLADAFW::Light* light )
    {
        // If we have one or more lights, we need a light linker
        if ( mLightLinker == 0 ) createLightLinker ();

        // Check if the light is already imported.
        const COLLADAFW::UniqueId& lightId = light->getUniqueId ();
        if ( findMayaLightNode ( lightId ) != 0 ) return;

        // Get the transform nodes, which work with this light instance.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const UniqueIdVec* transformNodes = visualSceneImporter->findLightTransformIds ( lightId );
        if ( transformNodes == 0 )
        {
            MGlobal::displayError ( "No transform node which implements this light!" );
            std::cerr << "No transform node which implements this light!" << endl;
            return;
        }

        UniqueIdVec::const_iterator nodesIter = transformNodes->begin ();
        while ( nodesIter != transformNodes->end () )
        {
            // Get the maya node of the current transform node.
            const COLLADAFW::UniqueId& transformNodeId = *nodesIter;
            MayaNode* mayaTransformNode = visualSceneImporter->findMayaTransformNode ( transformNodeId );
            String transformNodeName = mayaTransformNode->getName ();

            // Get the path to the parent transform node.
            String transformNodePath = mayaTransformNode->getNodePath ();

            // The first reference is a direct one, the others are instances.
            if ( nodesIter == transformNodes->begin() )
            {
                // Create the current mesh node.
                createLight ( light, mayaTransformNode );
            }
            else
            {
                // Get the path to the node.
                MayaNode* mayaLightNode = findMayaLightNode ( lightId );
                String lightNodePath = mayaLightNode->getNodePath ();

                // parent -shape -noConnections -relative -addObject "|pCube1|pCubeShape1" "pCube2";
                FILE* file = getDocumentImporter ()->getFile ();
                MayaDM::parentShape ( file, lightNodePath, transformNodePath, false, true, true, true );
            }

            ++nodesIter;
        }
    }

    // --------------------------------------------
    void LightImporter::createLight ( 
        const COLLADAFW::Light* light,  
        MayaNode* mayaTransformNode )
    {
        // Check if the camera is already imported.
        const COLLADAFW::UniqueId& lightId = light->getUniqueId ();

        // Create a unique name.
        String lightName = light->getName ();
        if ( COLLADABU::Utils::equals ( lightName, "" ) ) 
            lightName = LIGHT_NAME;
        lightName = mLightIdList.addId ( lightName );

        // Create a maya node object of the current node and push it into the map.
        MayaNode mayaMeshNode ( lightId, lightName, mayaTransformNode );
        mMayaLightNodesMap [ lightId ] = mayaMeshNode;

        FILE* file = getDocumentImporter ()->getFile ();

        MayaDM::Light* mayaLight = 0;
        COLLADAFW::Light::LightType lightType = light->getLightType ();
        switch ( lightType )
        {
        case COLLADAFW::Light::AMBIENT_LIGHT:
            {
                mayaLight = new MayaDM::AmbientLight ( file, lightName, mayaTransformNode->getNodePath () );
            }
            break;
        case COLLADAFW::Light::DIRECTIONAL_LIGHT:
            {
                mayaLight = new MayaDM::DirectionalLight ( file, lightName, mayaTransformNode->getNodePath () );
            }
            break;
        case COLLADAFW::Light::POINT_LIGHT:
            {
                mayaLight = new MayaDM::PointLight ( file, lightName, mayaTransformNode->getNodePath () );
                setPointLightAttributes ( light, mayaLight );
            }
            break;
        case COLLADAFW::Light::SPOT_LIGHT:
            {
                mayaLight = new MayaDM::SpotLight ( file, lightName, mayaTransformNode->getNodePath () );
                setSpotLightAttributes ( light, mayaLight );
            }
            break;
        default:
            MGlobal::displayError ( "Unknown light type!" );
            std::cerr << "Unknown light type!" << endl;
            return;
            break;
        }

        COLLADAFW::Color color = light->getColor ();
        mayaLight->setColor ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue () ) );
        
        appendLight ( lightId, mayaLight );
    }

    // --------------------------------------------
    MayaNode* LightImporter::findMayaLightNode ( const COLLADAFW::UniqueId& lightId ) 
    {
        UniqueIdMayaNodesMap::iterator it = mMayaLightNodesMap.find ( lightId );
        if ( it != mMayaLightNodesMap.end () )
            return &(*it).second;

        return 0;
    }

    // --------------------------------------------
    void LightImporter::setPointLightAttributes ( 
        const COLLADAFW::Light* light, 
        MayaDM::Light* mayaLight )
    {
        MayaDM::PointLight* pointLight = (MayaDM::PointLight*)mayaLight;

        // Attenuation in COLLADA is equal to Decay in Maya.
        double constant = light->getConstantAttenuation ();
        double linear = light->getLinearAttenuation ();
        double quadratic = light->getQuadraticAttenuation ();

        // TODO If light is animated, the values have to change!
        if ( quadratic > linear && quadratic > constant )
            pointLight->setDecayRate ( 2 );
        else if ( linear > constant )
            pointLight->setDecayRate ( 1 );
        else pointLight->setDecayRate ( 0 );
    }

    // --------------------------------------------
    void LightImporter::setSpotLightAttributes ( 
        const COLLADAFW::Light* light, 
        MayaDM::Light* mayaLight )
    {
        MayaDM::SpotLight* spotLight = (MayaDM::SpotLight*)mayaLight;

        // Attenuation in COLLADA is equal to Decay in Maya.
        double constant = light->getConstantAttenuation ();
        double linear = light->getLinearAttenuation ();
        double quadratic = light->getQuadraticAttenuation ();

        // TODO If light is animated, the values have to change!
        if ( quadratic > linear && quadratic > constant )
            spotLight->setDecayRate ( 2 );
        else if ( linear > constant )
            spotLight->setDecayRate ( 1 );
        else spotLight->setDecayRate ( 0 );

        // Drop-off
        double dropOff;
        if ( COLLADABU::Math::Utils::equals ( light->getFallOffExponent (), 0.0 ) ) dropOff = 0.0;
        else dropOff = 1.0; // COLLADA 1.4 took out the fallOffScale, for some reason.
        spotLight->setDropoff ( dropOff );

        // Cone and Penumbra Angles
        double fallOffAngle = light->getFallOffAngle ();
        spotLight->setConeAngle ( fallOffAngle );

//         double penumbraAngle = ( light->getOuterAngle() - light->getFallOffAngle() ) / 2.0f;
//         spotLight->setPenumbraAngle ( COLLADABU::Math::Utils::degToRad ( penumbraAngle ));

    }

    // --------------------------
    MayaDM::Light* LightImporter::findMayaLight ( const COLLADAFW::UniqueId& val ) const
    {
        UniqueIdLightNodeMap::const_iterator it = mMayaLightMap.find ( val );
        if ( it != mMayaLightMap.end () )
        {
            return it->second;
        }
        return 0;
    }

    // --------------------------
    void LightImporter::appendLight ( const COLLADAFW::UniqueId& id, MayaDM::Light* lightNode )
    {
        mMayaLightMap [id] = lightNode;
    }

    // --------------------------
    void LightImporter::writeConnections ()
    {
        connectLightObjects();
        connectLightLinkers ();
    }

    // --------------------------
    void LightImporter::connectLightLinkers ()
    {
        if ( !mLightLinker ) return;

        // The maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        size_t lightLinkerLinkIndex = 0;

        // Get the default light set.
        MayaDM::ObjectSet defaultLightSet ( file, DEFAULT_LIGHT_SET, "", false );

        // Connect the existing shader engines with the first light linker link's object.
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
        const MaterialImporter::ShadingDataMap& shadingDataMap = materialImporter->getShadingEnginesMap ();
        MaterialImporter::ShadingDataMap::const_iterator it = shadingDataMap.begin ();
        while ( it != shadingDataMap.end () )
        {
            MaterialImporter::ShadingData* shadingData = it->second;
            MayaDM::ShadingEngine* shadingEngine = shadingData->getShadingEngine ();

            // Connect the the default light set message with the next light linker link's light
            // connectAttr ":defaultLightSet.message" "lightLinker1.link[0].light";
            connectAttr ( file, defaultLightSet.getMessage (), mLightLinker->getLight ( lightLinkerLinkIndex ) );

            // Connect the current shading engine's message with the next light linker link's object.
            // connectAttr "lambert2SG.message" "lightLinker1.link[0].object";
            connectAttr ( file, shadingEngine->getMessage (), mLightLinker->getObject ( lightLinkerLinkIndex ) );

            // Connect the the default light set message with the next light linker shadow link's shadow light
            // connectAttr ":defaultLightSet.message" "lightLinker1.shadowLink[0].shadowLight";
            connectAttr ( file, defaultLightSet.getMessage (), mLightLinker->getShadowLight ( lightLinkerLinkIndex ) );

            // Connect the current shading engine's message with the next light linker shadow link's shadow object.
            // connectAttr "lambert2SG.message" "lightLinker1.shadowLink[0].shadowObject";
            connectAttr ( file, shadingEngine->getMessage (), mLightLinker->getShadowObject ( lightLinkerLinkIndex ) );

            // Increment the light linker index
            ++lightLinkerLinkIndex;

            ++it;
        }

        // Create the dummy object of the initial shading group.
        MayaDM::ShadingEngine initialShadingEngine ( file, MaterialImporter::INITIAL_SHADING_ENGINE, "", false );

        // Connect the default light set message with the next light linker link's light
        // connectAttr ":defaultLightSet.message" "lightLinker1.link[1].light";
        connectAttr ( file, defaultLightSet.getMessage (), mLightLinker->getLight ( lightLinkerLinkIndex ) );
        // Connect the initial shading group message with the next light linker link's object
        // connectAttr ":initialShadingGroup.message" "lightLinker1.link[1].object";
        connectAttr ( file, initialShadingEngine.getMessage (), mLightLinker->getObject ( lightLinkerLinkIndex ) );

        // Connect the default light set message with the light linker shadow link's shadow light
        // connectAttr ":defaultLightSet.message" "lightLinker1.shadowLink[1].shadowLight";
        connectAttr ( file, defaultLightSet.getMessage (), mLightLinker->getShadowLight ( lightLinkerLinkIndex ) );
        // Connect the initial shading group message with the next light linker shadow link's shadow object
        // connectAttr ":initialShadingGroup.message" "lightLinker1.shadowLink[1].shadowObject";
        connectAttr ( file, initialShadingEngine.getMessage (), mLightLinker->getShadowObject ( lightLinkerLinkIndex ) );


        // Create a dummy object for the light list.
        MayaDM::LightList lightList ( file, INITIAL_LIGHT_LIST, "", false );

        // Connect the light linker the initial light list link Nodes
        // connectAttr "lightLinker1.message" ":lightList1.linkNodes" -nextAvailable;
        connectAttr ( file, mLightLinker->getMessage (), lightList.getLinkNodes (0) );

    }

    // --------------------------
    void LightImporter::connectLightObjects ()
    {
        // The maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Create a dummy object for the light list.
        MayaDM::LightList lightList ( file, INITIAL_LIGHT_LIST, "", false );

        // Create the default light set dummy object, if we need it for the connections. 
        MayaDM::ObjectSet* defaultLightSet = 0;

        size_t lightIndex = 0;
        size_t lightSetIndex = 0;
        UniqueIdMayaNodesMap::iterator it = mMayaLightNodesMap.begin ();
        while ( it != mMayaLightNodesMap.end () )
        {
            const COLLADAFW::UniqueId& lightId = it->first;
            MayaNode& mayaNode = it->second;

            MayaDM::DependNode* dependNode = findMayaLight ( lightId );
            MayaDM::Light* lightNode = ( MayaDM::Light* ) dependNode;
            dependNode->setName ( mayaNode.getNodePath () );

            // Connect the light data of the lights (just real ones, no instances), with the light list.
            //connectAttr "|spotLight1|spotLightShape1.lightData" ":lightList1.lights" -nextAvailable;
            //connectAttr "spotLightShape2.lightData" ":lightList1.lights" -nextAvailable;
            connectAttr ( file, lightNode->getLightData (), lightList.getLights ( lightIndex ) );
            ++lightIndex;

            // Get the transform nodes, which work with this light instance.
            VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
            const UniqueIdVec* transformNodes = visualSceneImporter->findLightTransformIds ( lightId );
            if ( transformNodes == 0 )
            {
                MGlobal::displayError ( "No transform node which implements this light!" );
                std::cerr << "No transform node which implements this light!" << endl;
                return;
            }

            size_t nodeIndex = 0;
            UniqueIdVec::const_iterator nodesIter = transformNodes->begin ();
            while ( nodesIter != transformNodes->end () )
            {
                // Get the transform node.
                const COLLADAFW::UniqueId& transformNodeId = *nodesIter;
                MayaNode* mayaTransformNode = visualSceneImporter->findMayaTransformNode ( transformNodeId );
                String transformNodeName = mayaTransformNode->getName ();
                String transformNodePath = mayaTransformNode->getNodePath ();
                MayaDM::Transform transformNode ( file, transformNodePath, "", false );

                // Create the dummy object of the default light set, if we need it.
                if ( defaultLightSet == 0 )
                    defaultLightSet = new MayaDM::ObjectSet ( file, DEFAULT_LIGHT_SET, "", false );

                // Connect the light transforms instance object groups with the default light set.
                //connectAttr "spotLight1.instObjGroups" ":defaultLightSet.dagSetMembers" -nextAvailable;
                //connectAttr "|spotLight2.instObjGroups" ":defaultLightSet.dagSetMembers" -nextAvailable;
                //connectAttr "spotLight3.instObjGroups" ":defaultLightSet.dagSetMembers" -nextAvailable;
                connectAttr ( file, transformNode.getInstObjGroups (0), defaultLightSet->getDagSetMembers (lightSetIndex) );
                ++lightSetIndex;

                ++nodesIter;
            }

            ++it;
        }

        if ( defaultLightSet != 0 )
            delete defaultLightSet;
    }

} // namespace COLLADAMaya
