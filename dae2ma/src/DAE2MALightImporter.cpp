/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MALightImporter.h"
#include "DAE2MAVisualSceneImporter.h"
#include "DAE2MAMaterialImporter.h"

#include "Math/COLLADABUMathUtils.h"

#include "COLLADAFWLight.h"

#include <MayaDMCommands.h>
#include <MayaDMLight.h>
#include <MayaDMAmbientLight.h>
#include <MayaDMDirectionalLight.h>


namespace DAE2MA
{

    const String LightImporter::LIGHT_NAME = "light";
    const String LightImporter::DEFAULT_LIGHT_LIST_NAME = "lightList1";
    const String LightImporter::DEFAULT_LIGHT_SET_NAME = "defaultLightSet";
    const String LightImporter::DEFAULT_LIGHT_LINKER_NAME = "lightLinker1";


    //------------------------------
	LightImporter::LightImporter ( DocumentImporter* documentImporter ) 
        : BaseImporter ( documentImporter )
        , mDefaultLightLinker ( NULL, DEFAULT_LIGHT_LINKER_NAME, EMPTY_STRING, false, false )
        , mDefaultLightList ( NULL, ":" + DEFAULT_LIGHT_LIST_NAME, EMPTY_STRING, false, false )
        , mDefaultLightSet ( NULL, ":" + DEFAULT_LIGHT_SET_NAME, EMPTY_STRING, false, false )
	{}
	
    //------------------------------
	LightImporter::~LightImporter()
	{
        UniqueIdLightNodeMap::iterator it = mMayaLightMap.begin ();
        while ( it != mMayaLightMap.end () )
        {
            MayaDM::Light* light = it->second;
            delete light;
            ++it;
        }
        mMayaLightMap.clear ();

        UniqueIdMayaNodeMap::iterator it2 = mMayaLightNodesMap.begin ();
        while ( it2 != mMayaLightNodesMap.end () )
        {
            MayaNode* mayaNode = it2->second;
            delete mayaNode;
            ++it2;
        }
        mMayaLightNodesMap.clear ();

	}

    //------------------------------
    void LightImporter::initialiseDefaultLightObjects ()
    {
        // Get a reference to the current maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Create the default light linker
        mDefaultLightLinker.setFile ( file );
        mDefaultLightLinker.setName ( DEFAULT_LIGHT_LINKER_NAME );

        // Create a object for the default light list.
        mDefaultLightList.setFile ( file );
        mDefaultLightList.setName ( ":" + DEFAULT_LIGHT_LIST_NAME );
        
        // Create a object for the default light set.
        mDefaultLightSet.setFile ( file );
        mDefaultLightSet.setName ( ":" + DEFAULT_LIGHT_SET_NAME );

    }

    //------------------------------
    void LightImporter::importLight ( const COLLADAFW::Light* light )
    {
        // Check if the light is already imported.
        const COLLADAFW::UniqueId& lightId = light->getUniqueId ();
        if ( findMayaLightNode ( lightId ) != 0 ) return;

        // Get the transform nodes, which work with this light instance.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const UniqueIdVec* transformNodes = visualSceneImporter->findLightTransformIds ( lightId );
        if ( transformNodes == 0 )
        {
            std::cerr << "No transform node which implements this light!" << std::endl;
            return;
        }

        UniqueIdVec::const_iterator nodesIter = transformNodes->begin ();
        while ( nodesIter != transformNodes->end () )
        {
            // Get the maya node of the current transform node.
            const COLLADAFW::UniqueId& transformNodeId = *nodesIter;
            MayaNodesList* mayaNodesList = visualSceneImporter->findMayaTransformNodes ( transformNodeId );
            if ( mayaNodesList == 0 ) 
            {
                std::cerr << "Cant find transform node!" << std::endl;
                return;
            }
            MayaNode* mayaTransformNode = (*mayaNodesList) [0];
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

        // Make the maya name unique and manage it in all necessary lists.
        String lightName = light->getName ();
        if ( lightName.empty () ) lightName = LIGHT_NAME;
        lightName = DocumentImporter::frameworkNameToMayaName ( lightName );
        const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
        String originalMayaId = getOriginalMayaId ( callbackHandler, lightId, COLLADASaxFWL15::HASH_ELEMENT_LIGHT );
        if ( !originalMayaId.empty () ) lightName = originalMayaId;
        lightName = generateUniqueDagNodeName ( lightName, mayaTransformNode );

        // Create a maya node object of the current node and push it into the map.
        MayaNode* mayaLightNode = new MayaNode ( lightId, lightName, mayaTransformNode );
        mMayaLightNodesMap [ lightId ] = mayaLightNode;

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
            std::cerr << "Unknown light type!" << std::endl;
            return;
        }

        // Add the original id attribute.
        String colladaId = light->getOriginalId ();
        if ( !colladaId.empty () )
        {
            MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
            MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
        }
//         // TODO Add the attributes for all the extra tags.
//         setExtraData ( light->getExtraDataArray () );

        // Set the standard light color.
        COLLADAFW::Color color = light->getColor ();
        mayaLight->setColor ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue () ) );
        
        // Store the light in a map.
        appendLight ( lightId, mayaLight );
    }

    // --------------------------------------------
    MayaNode* LightImporter::findMayaLightNode ( const COLLADAFW::UniqueId& lightId ) 
    {
        UniqueIdMayaNodeMap::iterator it = mMayaLightNodesMap.find ( lightId );
        if ( it != mMayaLightNodesMap.end () )
            return it->second;

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
        if ( COLLADABU::Math::Utils::equalsZero ( light->getFallOffExponent (), getTolerance () ) ) dropOff = 0.0;
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
        // The maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        size_t lightLinkerLinkIndex = 0;

        // Get the default light set.
        MayaDM::ObjectSet defaultLightSet ( file, DEFAULT_LIGHT_SET_NAME, EMPTY_STRING, false, false );

        // Connect the existing shader engines with the first light linker link's object.
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
        const MaterialImporter::ShadingDataMap& shadingDataMap = materialImporter->getShadingEnginesMap ();
        MaterialImporter::ShadingDataMap::const_iterator it = shadingDataMap.begin ();
        while ( it != shadingDataMap.end () )
        {
            MaterialImporter::ShadingData* shadingData = it->second;
            const MayaDM::ShadingEngine& shadingEngine = shadingData->getShadingEngine ();

            // Connect the the default light set message with the next light linker link's light
            // connectAttr ":defaultLightSet.message" "lightLinker1.link[0].light";
            connectAttr ( file, defaultLightSet.getMessage (), mDefaultLightLinker.getLight ( lightLinkerLinkIndex ) );

            // Connect the current shading engine's message with the next light linker link's object.
            // connectAttr "lambert2SG.message" "lightLinker1.link[0].object";
            connectAttr ( file, shadingEngine.getMessage (), mDefaultLightLinker.getObject ( lightLinkerLinkIndex ) );

            // Connect the the default light set message with the next light linker shadow link's shadow light
            // connectAttr ":defaultLightSet.message" "lightLinker1.shadowLink[0].shadowLight";
            connectAttr ( file, defaultLightSet.getMessage (), mDefaultLightLinker.getShadowLight ( lightLinkerLinkIndex ) );

            // Connect the current shading engine's message with the next light linker shadow link's shadow object.
            // connectAttr "lambert2SG.message" "lightLinker1.shadowLink[0].shadowObject";
            connectAttr ( file, shadingEngine.getMessage (), mDefaultLightLinker.getShadowObject ( lightLinkerLinkIndex ) );

            // Increment the light linker index
            ++lightLinkerLinkIndex;

            ++it;
        }

        // Create the dummy object of the initial shading group.
        MayaDM::ShadingEngine initialShadingEngine ( file, ":" + MaterialImporter::INITIAL_SHADING_ENGINE_NAME, EMPTY_STRING, false, false );

        // Connect the default light set message with the next light linker link's light
        // connectAttr ":defaultLightSet.message" "lightLinker1.link[1].light";
        connectAttr ( file, defaultLightSet.getMessage (), mDefaultLightLinker.getLight ( lightLinkerLinkIndex ) );
        // Connect the initial shading group message with the next light linker link's object
        // connectAttr ":initialShadingGroup.message" "lightLinker1.link[1].object";
        connectAttr ( file, initialShadingEngine.getMessage (), mDefaultLightLinker.getObject ( lightLinkerLinkIndex ) );

        // Connect the default light set message with the light linker shadow link's shadow light
        // connectAttr ":defaultLightSet.message" "lightLinker1.shadowLink[1].shadowLight";
        connectAttr ( file, defaultLightSet.getMessage (), mDefaultLightLinker.getShadowLight ( lightLinkerLinkIndex ) );
        // Connect the initial shading group message with the next light linker shadow link's shadow object
        // connectAttr ":initialShadingGroup.message" "lightLinker1.shadowLink[1].shadowObject";
        connectAttr ( file, initialShadingEngine.getMessage (), mDefaultLightLinker.getShadowObject ( lightLinkerLinkIndex ) );

        // Connect the light linker the initial light list link Nodes
        // connectAttr "lightLinker1.message" ":lightList1.linkNodes" -nextAvailable;
        connectAttr ( file, mDefaultLightLinker.getMessage (), mDefaultLightList.getLinkNodes (0) );

    }

    // --------------------------
    void LightImporter::connectLightObjects ()
    {
        // The maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        size_t lightIndex = 0;
        size_t lightSetIndex = 0;
        UniqueIdMayaNodeMap::iterator it = mMayaLightNodesMap.begin ();
        while ( it != mMayaLightNodesMap.end () )
        {
            const COLLADAFW::UniqueId& lightId = it->first;
            MayaNode* mayaNode = it->second;

            MayaDM::DependNode* dependNode = findMayaLight ( lightId );
            MayaDM::Light* lightNode = ( MayaDM::Light* ) dependNode;
            dependNode->setName ( mayaNode->getNodePath () );

            // Connect the light data of the lights (just real ones, no instances), with the light list.
            //connectAttr "|spotLight1|spotLightShape1.lightData" ":lightList1.lights" -nextAvailable;
            //connectAttr "spotLightShape2.lightData" ":lightList1.lights" -nextAvailable;
            connectAttr ( file, lightNode->getLightData (), mDefaultLightList.getLights ( lightIndex ) );
            ++lightIndex;

            // Get the transform nodes, which work with this light instance.
            VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
            const UniqueIdVec* transformNodes = visualSceneImporter->findLightTransformIds ( lightId );
            if ( transformNodes == 0 )
            {
                std::cerr << "No transform node which implements this light!" << std::endl;
                return;
            }

            size_t nodeIndex = 0;
            UniqueIdVec::const_iterator nodesIter = transformNodes->begin ();
            while ( nodesIter != transformNodes->end () )
            {
                // Get the maya transform nodes and read the path.
                const COLLADAFW::UniqueId& transformNodeId = *nodesIter;
                MayaNodesList* transformNodes = visualSceneImporter->findMayaTransformNodes ( transformNodeId );
                if ( transformNodes->size () == 0 )
                {
                    std::cerr << "The referenced transform node doesn't exist!" << std::endl;
                    return;
                }
                MayaNode* mayaTransformNode = (*transformNodes) [0];
                String transformNodeName = mayaTransformNode->getName ();
                String transformNodePath = mayaTransformNode->getNodePath ();
                MayaDM::Transform transformNode ( file, transformNodePath, EMPTY_STRING, false, false );

                // Connect the light transforms instance object groups with the default light set.
                //connectAttr "spotLight1.instObjGroups" ":defaultLightSet.dagSetMembers" -nextAvailable;
                //connectAttr "|spotLight2.instObjGroups" ":defaultLightSet.dagSetMembers" -nextAvailable;
                //connectAttr "spotLight3.instObjGroups" ":defaultLightSet.dagSetMembers" -nextAvailable;
                connectNextAttr ( file, transformNode.getInstObjGroups (), mDefaultLightSet.getDagSetMembers () );
                //connectAttr ( file, transformNode.getInstObjGroups (0), mDefaultLightSet.getDagSetMembers (lightSetIndex) );
                ++lightSetIndex;

                ++nodesIter;
            }
            
            ++it;
        }
    }

} // namespace DAE2MA
