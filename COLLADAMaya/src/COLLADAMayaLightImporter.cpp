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

#include "math\COLLADABUMathUtils.h"

#include "COLLADAFWLight.h"

#include <MayaDMCommands.h>
#include <MayaDMLight.h>
#include <MayaDMAmbientLight.h>
#include <MayaDMDirectionalLight.h>


namespace COLLADAMaya
{

    const String LightImporter::LIGHT_NAME = "Light";


    //------------------------------
	LightImporter::LightImporter ( DocumentImporter* documentImporter ) 
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	LightImporter::~LightImporter()
	{
	}

    //------------------------------
    void LightImporter::importLight ( const COLLADAFW::Light* light )
    {
        // Check if the camera is already imported.
        const COLLADAFW::UniqueId& lightId = light->getUniqueId ();
        if ( findMayaLightNode ( lightId ) != 0 ) return;

        // Get the transform nodes, which work with this camera instance.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const UniqueIdVec* transformNodes = visualSceneImporter->findCameraTransformIds ( lightId );
        if ( transformNodes == 0 )
        {
            MGlobal::displayError ( "No camera node which implements this camera!" );
            std::cerr << "No camera node which implements this camera!" << endl;
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
                // Get the path to the mesh.
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
        
        delete mayaLight;
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
        spotLight->setConeAngle ( COLLADABU::Math::Utils::degToRad ( fallOffAngle ) );

//         double penumbraAngle = ( light->getOuterAngle() - light->getFallOffAngle() ) / 2.0f;
//         spotLight->setPenumbraAngle ( COLLADABU::Math::Utils::degToRad ( penumbraAngle ));

    }

} // namespace COLLADAMaya
