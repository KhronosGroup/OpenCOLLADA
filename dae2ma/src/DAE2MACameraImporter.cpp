/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MACameraImporter.h"
#include "DAE2MAVisualSceneImporter.h"
#include "DAE2MASyntax.h"

#include "COLLADAFWCamera.h"

#include <MayaDMCommands.h>


namespace DAE2MA
{

    const String CameraImporter::CAMERA_NAME = "camera";


    //------------------------------
	CameraImporter::CameraImporter ( DocumentImporter* documentImporter ) 
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	CameraImporter::~CameraImporter()
	{
        UniqueIdMayaNodeMap::iterator it = mMayaCameraNodesMap.begin ();
        while ( it != mMayaCameraNodesMap.end () )
        {
            MayaNode* mayaNode = it->second;
            delete mayaNode;
            ++it;
        }
        mMayaCameraNodesMap.clear ();
	}

    //------------------------------
    void CameraImporter::importCamera ( const COLLADAFW::Camera* camera )
    {
        // Check if the camera is already imported.
        const COLLADAFW::UniqueId& cameraId = camera->getUniqueId ();
        if ( findMayaCameraNode ( cameraId ) != 0 ) return;

        // Get the transform nodes, which work with this camera instance.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const UniqueIdVec* transformNodeIds = visualSceneImporter->findCameraTransformIds ( cameraId );
        if ( transformNodeIds == 0 )
        {
            std::cerr << "No camera node which implements this camera!" << std::endl;
            return;
        }

        UniqueIdVec::const_iterator nodesIter = transformNodeIds->begin ();
        while ( nodesIter != transformNodeIds->end () )
        {
            // Get the maya node of the current transform node.
            const COLLADAFW::UniqueId& transformNodeId = *nodesIter;
            MayaNodesList* mayaTransformNodes = visualSceneImporter->findMayaTransformNodes ( transformNodeId );
            if ( mayaTransformNodes->size () == 0 )
            {
                std::cerr << "The referenced transform node doesn't exist!" << std::endl;
                return;
            }
            MayaNode* mayaTransformNode = (*mayaTransformNodes) [0];
            String transformNodeName = mayaTransformNode->getName ();

            // Get the path to the parent transform node.
            String transformNodePath = mayaTransformNode->getNodePath ();

            // The first reference is a direct one, the others are instances.
            if ( nodesIter == transformNodeIds->begin() )
            {
                // Create the current mesh node.
                createCamera ( camera, mayaTransformNode );
            }
            else
            {
                // Get the path to the mesh.
                MayaNode* mayaCameraNode = findMayaCameraNode ( cameraId );
                String cameraNodePath = mayaCameraNode->getNodePath ();

                // parent -shape -noConnections -relative -addObject "|pCube1|pCubeShape1" "pCube2";
                FILE* file = getDocumentImporter ()->getFile ();
                MayaDM::parentShape ( file, cameraNodePath, transformNodePath, false, true, true, true );
            }

            ++nodesIter;
        }
    }

    //------------------------------
    void CameraImporter::createCamera ( 
        const COLLADAFW::Camera* camera,  
        MayaNode* mayaTransformNode )
    {
        // Get the unique id.
        const COLLADAFW::UniqueId& cameraId = camera->getUniqueId ();

        // Make the maya name unique and manage it in all necessary lists.
        String cameraName = camera->getName ();
        if ( cameraName.empty () ) cameraName = CAMERA_NAME;
        cameraName = DocumentImporter::frameworkNameToMayaName ( cameraName );
        const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
        String originalMayaId = getOriginalMayaId ( callbackHandler, cameraId, COLLADASaxFWL15::HASH_ELEMENT_CAMERA );
        if ( !originalMayaId.empty () ) cameraName = originalMayaId;
        cameraName = generateUniqueDagNodeName ( cameraName, mayaTransformNode );

        // Create a maya node object of the current node and push it into the map.
        MayaNode* mayaCameraNode = new MayaNode ( cameraId, cameraName, mayaTransformNode );
        mMayaCameraNodesMap [ cameraId ] = mayaCameraNode;

        // Check if we want to write a shared default camera.
        bool isSharedCamera = false;
        if (   COLLADABU::Utils::equals ( camera->getName (), CAMERA_PERSP_SHAPE ) 
            || COLLADABU::Utils::equals ( camera->getName (), CAMERA_TOP_SHAPE ) 
            || COLLADABU::Utils::equals ( camera->getName (), CAMERA_FRONT_SHAPE ) 
            || COLLADABU::Utils::equals ( camera->getName (), CAMERA_SIDE_SHAPE ) )
        {
            isSharedCamera = true;
        }

        // Create the maya camera object and write it into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Camera mayaCamera ( file, cameraName, mayaTransformNode->getNodePath (), isSharedCamera );

        // Add the original id attribute.
        String colladaId = camera->getOriginalId ();
        if ( !colladaId.empty () )
        {
            MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
            MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
        }
//         // TODO Add the attributes for all the extra tags.
//         setExtraData ( camera->getExtraDataArray () );

        // Have a look, if there is a center of interest set by the transform's lookat matrix.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        double centerOfInterestDistance;
        bool found = visualSceneImporter->findCenterOfInterestDistance ( mayaTransformNode->getUniqueId (), centerOfInterestDistance );
        if ( found )
        {
            mayaCamera.setCenterOfInterest ( centerOfInterestDistance );
        }

        // Write the data in depend on the camera type.
        const COLLADAFW::Camera::CameraType& cameraType = camera->getCameraType ();
        switch ( cameraType )
        {
        case COLLADAFW::Camera::ORTHOGRAPHIC:
            setOrthographicCameraAttributes ( camera, mayaCameraNode, mayaCamera );
            break;
        case COLLADAFW::Camera::PERSPECTIVE:
            setPerspectiveCameraAttributes ( camera, mayaCameraNode, mayaCamera );
            break;
        default:
            std::cerr << "Unknown camera type!" << std::endl;
            break;
        }

    }

    //------------------------------
    void CameraImporter::setPerspectiveCameraAttributes ( 
        const COLLADAFW::Camera* camera,
        MayaNode* mayaCameraNode, 
        MayaDM::Camera& mayaCamera )
    {
        mayaCamera.setOrthographic ( false );

        double nearClipPlane = camera->getNearClippingPlane ();
        nearClipPlane = toLinearUnit ( nearClipPlane );
        mayaCamera.setNearClipPlane ( nearClipPlane );

        double farClipPlane = camera->getFarClippingPlane ();
        farClipPlane = toLinearUnit ( farClipPlane );
        mayaCamera.setFarClipPlane ( farClipPlane );

        FILE* file = getDocumentImporter ()->getFile ();

        const COLLADAFW::Camera::DescriptionType& description = camera->getDescriptionType ();
        switch ( description )
        {
        case COLLADAFW::Camera::ASPECTRATIO_AND_X:
            {
                double aspectRatio = camera->getAspectRatio ();
                MayaDM::editCameraAspectRatio ( file, mayaCameraNode->getNodePath (), aspectRatio );

                double horizontalFieldOfView = camera->getXFov ();
                MayaDM::editCameraHorizontalFieldOfView ( file, mayaCameraNode->getNodePath (), horizontalFieldOfView );
            }
            break;
        case COLLADAFW::Camera::ASPECTRATIO_AND_Y:
            {
                double aspectRatio = camera->getAspectRatio ();
                MayaDM::editCameraAspectRatio ( file, mayaCameraNode->getNodePath (), aspectRatio );

                double verticalFieldOfView = camera->getYFov ();
                MayaDM::editCameraVerticalFieldOfView ( file, mayaCameraNode->getNodePath (), verticalFieldOfView );
            }
            break;
        case COLLADAFW::Camera::SINGLE_X:
            {
                double aspectRatio = 1.0;
                MayaDM::editCameraAspectRatio ( file, mayaCameraNode->getNodePath (), aspectRatio );
                
                double horizontalFieldOfView = camera->getXFov ();
                MayaDM::editCameraHorizontalFieldOfView ( file, mayaCameraNode->getNodePath (), horizontalFieldOfView );
            }
            break;
        case COLLADAFW::Camera::SINGLE_Y:
            {
                double aspectRatio = 1.0;
                MayaDM::editCameraAspectRatio ( file, mayaCameraNode->getNodePath (), aspectRatio );

                double verticalFieldOfView = camera->getYFov ();
                MayaDM::editCameraVerticalFieldOfView ( file, mayaCameraNode->getNodePath (), verticalFieldOfView );
            }
            break;
        case COLLADAFW::Camera::X_AND_Y:
            {
                double aspectRatio = camera->getXFov () / camera->getYFov ();
                MayaDM::editCameraAspectRatio ( file, mayaCameraNode->getNodePath (), aspectRatio );

                double horizontalFieldOfView = camera->getXFov ();
                MayaDM::editCameraHorizontalFieldOfView ( file, mayaCameraNode->getNodePath (), horizontalFieldOfView );

                double verticalFieldOfView = camera->getYFov ();
                MayaDM::editCameraVerticalFieldOfView ( file, mayaCameraNode->getNodePath (), verticalFieldOfView );
            }
            break;
        default:
            std::cerr << "Unknown description type!" << std::endl;
            break;
        }

    }

    //------------------------------
    void CameraImporter::setOrthographicCameraAttributes ( 
        const COLLADAFW::Camera* camera, 
        MayaNode* mayaCameraNode, 
        MayaDM::Camera& mayaCamera )
    {
        mayaCamera.setOrthographic ( true );

        double nearClipPlane = camera->getNearClippingPlane ();
        nearClipPlane = toLinearUnit ( nearClipPlane );
        mayaCamera.setNearClipPlane ( nearClipPlane );

        double farClipPlane = camera->getFarClippingPlane ();
        farClipPlane = toLinearUnit ( farClipPlane );
        mayaCamera.setFarClipPlane ( farClipPlane );
        
        FILE* file = getDocumentImporter ()->getFile ();

        COLLADAFW::Camera::DescriptionType description = camera->getDescriptionType ();
        switch ( description )
        {
        case COLLADAFW::Camera::ASPECTRATIO_AND_X:
            {
                double aspectRatio = camera->getAspectRatio ();
                MayaDM::editCameraAspectRatio ( file, mayaCameraNode->getNodePath (), aspectRatio );

                double orthographicWidth = camera->getXMag () * 2;
                MayaDM::editCameraOrthographicWidth ( file, mayaCameraNode->getNodePath (), orthographicWidth );
            }
            break;
        case COLLADAFW::Camera::ASPECTRATIO_AND_Y:
            {
                double aspectRatio = camera->getAspectRatio ();
                MayaDM::editCameraAspectRatio ( file, mayaCameraNode->getNodePath (), aspectRatio );

                double orthographicHeight = camera->getYMag () * 2;
                MayaDM::editCameraOrthographicWidth ( file, mayaCameraNode->getNodePath (), orthographicHeight );
            }
            break;
        case COLLADAFW::Camera::SINGLE_X:
            {
                double orthographicWidth = camera->getXMag () * 2;
                MayaDM::editCameraOrthographicWidth ( file, mayaCameraNode->getNodePath (), orthographicWidth );
            }
            break;
        case COLLADAFW::Camera::SINGLE_Y:
            {
                double orthographicHeight = camera->getYMag () * 2;
                MayaDM::editCameraOrthographicWidth ( file, mayaCameraNode->getNodePath (), orthographicHeight );
            }
            break;
        case COLLADAFW::Camera::X_AND_Y:
            {
                double orthographicWidth = camera->getXMag () * 2;
                MayaDM::editCameraOrthographicWidth ( file, mayaCameraNode->getNodePath (), orthographicWidth );

//                 double aspectRatio = camera->getXMag () / camera->getYMag ();
//                 MayaDM::editCameraAspectRatio ( file, mayaCameraNode->getNodePath (), aspectRatio );
            }
            break;
        default:
            std::cerr << "Unknown description type!" << std::endl;
            break;
        }

    }

    // --------------------------------------------
    MayaNode* CameraImporter::findMayaCameraNode ( const COLLADAFW::UniqueId& cameraId ) 
    {
        UniqueIdMayaNodeMap::iterator it = mMayaCameraNodesMap.find ( cameraId );
        if ( it != mMayaCameraNodesMap.end () )
            return it->second;

        return 0;
    }

} // namespace DAE2MA
