/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MAVisualSceneImporter.h"
#include "DAE2MADocumentImporter.h"
#include "DAE2MASyntax.h"
#include "DAE2MAMaterialImporter.h"
#include "DAE2MAConversion.h"
#include "DAE2MAControllerImporter.h"
#include "DAE2MANodeImporter.h"

#include "MayaDMJoint.h"
#include "MayaDMDependNode.h"
#include "MayaDMCommands.h"

#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWTranslate.h"
#include "COLLADAFWLookat.h"

#include "Math/COLLADABUMathMatrix4.h"

#include <vector>


namespace DAE2MA
{
    
    const String VisualSceneImporter::TRANSFORM_NODE_NAME = "Transform";


    // -----------------------------------
    VisualSceneImporter::VisualSceneImporter ( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
    {}
    
    // -----------------------------------
    VisualSceneImporter::~VisualSceneImporter ()
    {
        UniqueIdMayaNodesMap::iterator it = mMayaTransformNodesMap.begin ();
        while ( it != mMayaTransformNodesMap.end () )
        {
            MayaNodesList mayaNodes = it->second;
            for ( size_t i=0; i<mayaNodes.size (); ++i )
            {
                MayaNode* mayaNode = mayaNodes[i];
                delete mayaNode;
            }
            mayaNodes.clear ();
            ++it;
        }
        mMayaTransformNodesMap.clear ();
    }

    // -----------------------------------
    void VisualSceneImporter::importVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
        // Iterate over the root nodes of the current visual scene.
        const COLLADAFW::NodePointerArray& rootNodes = visualScene->getRootNodes ();

        // Iterate over the root nodes.
        size_t count = rootNodes.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            // Get the root node.
            COLLADAFW::Node* rootNode = rootNodes [i];

            // Import the root node and all child nodes.
            importNode ( rootNode, 0, &mDummyRootMayaNode );
        }

        // Import the node instances, when all nodes of the visual scene 
        // and the library nodes are already imported.
        writeNodeInstances ();
    }

//     // -----------------------------------
//     void VisualSceneImporter::importLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes )
//     {
//         // A library node is always instanciated from the visual scene.
//         // So we can't create the nodes on root.
//         const COLLADAFW::NodePointerArray& nodes = libraryNodes->getNodes ();
//         size_t numNodes = nodes.getCount ();
//         for ( size_t i=0; i<numNodes; ++i )
//         {
//             COLLADAFW::Node* node = nodes [i];
//             importNode ( node, 0, 0, false );
//         }
//     }

    // -----------------------------------
    MayaNode* VisualSceneImporter::importNode ( 
        const COLLADAFW::Node* node, 
        const COLLADAFW::Node* parentNode /*= NULL*/, 
        MayaNode* parentMayaNode /*= NULL*/ )
    {
        // Check if the current node is already imported.
        const COLLADAFW::UniqueId& nodeId = node->getUniqueId ();
        if ( findMayaTransformNodes ( nodeId ) != 0 ) return 0;

        // Make the maya name unique and manage it in all necessary lists.
        String nodeName = node->getName ();
        if ( nodeName.empty () ) nodeName = TRANSFORM_NODE_NAME;
        nodeName = DocumentImporter::frameworkNameToMayaName ( nodeName );
        const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
        String originalMayaId = getOriginalMayaId ( callbackHandler, nodeId, COLLADASaxFWL15::HASH_ELEMENT_NODE );
        if ( !originalMayaId.empty () ) nodeName = originalMayaId;
        nodeName = generateUniqueDagNodeName ( nodeName, parentMayaNode );

        // Check for a parent node name
        String parentNodePath = EMPTY_STRING; 
        if ( parentMayaNode != 0 ) parentNodePath = parentMayaNode->getNodePath ();

        // Create a maya node object of the current node and push it into the map.
        COLLADAFW::Node::NodeType nodeType = node->getType ();
        MayaNode* mayaNode = new MayaNode ( nodeId, nodeName, parentMayaNode, nodeType );
        mMayaTransformNodesMap [ nodeId ].push_back ( mayaNode );

        // Create the node object (joint or node)
        MayaDM::Transform* transformNode = createMayaDMNode ( node, nodeName, parentNodePath );

        // Get the current maya ascii file to write the data.
        FILE* file = getDocumentImporter ()->getFile ();

        // Add the original id attribute.
        String colladaId = node->getOriginalId ();
        if ( !colladaId.empty () )
        {
            MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
            MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
        }
//         // TODO Add the attributes for all the extra tags.
//         setExtraData ( node->getExtraDataArray () );

        // Import the transformations.
        importTransformations ( node, transformNode, parentNode );

        // We need the maya transform node for connect it with the animations.
        mMayaDMTransformMap [ nodeId ] = *transformNode;

        // Destroy the node object.
        delete transformNode;
        
        // Import node instances
        importNodeInstances ( node, mayaNode );

        // Import the instances.
        readGeometryInstances ( node );
        readCameraInstances ( node );
        readLightInstances ( node );
        readControllerInstances ( node );

        // Recursive call for all child elements.
        const COLLADAFW::NodeArray& childNodes = node->getChildNodes ();
        size_t numChildNodes = childNodes.getCount ();
        for ( size_t i=0; i<numChildNodes; ++i )
        {
            COLLADAFW::Node* childNode = childNodes [i];
            importNode ( childNode, node, mayaNode );
        }

        return mayaNode;
    }

//     // -----------------------------------
//     const String VisualSceneImporter::makeUniqueTransformMaterialName ( String transformName )
//     {
//         String dummyMaterialName = getDocumentImporter ()->getMaterialImporter ()->addMaterialId ( transformName );
//         if ( !COLLADABU::Utils::equalsIgnoreCase ( dummyMaterialName, transformName ) )
//         {
//             transformName = dummyMaterialName;
// 
//             String dummyTransformName = mTransformIdList.addId ( transformName );
//             if ( !COLLADABU::Utils::equalsIgnoreCase ( dummyTransformName, transformName ) )
//             {
//                 transformName = dummyTransformName;
// 
//                 // Recursive call
//                 makeUniqueTransformMaterialName ( transformName );
//             }
//             else return transformName;
//         }
//         
//         return transformName;
//     }

    // -----------------------------------
    bool VisualSceneImporter::importTransformations ( 
        const COLLADAFW::Node* node, 
        MayaDM::Transform* transformNode, 
        const COLLADAFW::Node* parentNode /*= NULL*/ )
    {
        // This is the order of the transforms:
        //
        // matrix = [SP-1 * S * SH * SP * ST] * [RP-1 * RA * R * JO * RP * RT] * T
        //          [        scale          ] * [          rotation          ] * translation
        //
        // [SP] scale pivot translation
        // [S] scale
        // [SH] shear
        // [ST] scale pivot translation
        // [RP] rotation pivot
        // [RA] rotation axis
        // [R] rotation
        // [RP] rotation pivot
        // [RT] rotation pivot translation
        // [T] translation
        // [JO] joint orientation
        //
        // references: Maya documentation - transform node, Maya documentation - joint node
        // NOTE: Left multiplying, column-order matrices
        //

        // Go through the transforms and try to fill the maya transformation. 
        // This just works, if the framework has the transformations in any order of the style
        // T* R* T* S* T*, if the order differs from, we have to transform with a matrix (but 
        // with matrix transformation is no animation possible).

        MayaTransform mayaTransform;
        std::vector<TransformAnimation> transformAnimations;

        bool hasRotatePivot = false;
        bool hasScalePivot = false;
        bool isLookatTransform = false;
        bool validMayaTransform = false;

        validMayaTransform = 
            readMayaTransformations ( node, mayaTransform, transformNode, transformAnimations, 
                                        hasRotatePivot, hasScalePivot, isLookatTransform );
        if ( !isLookatTransform )
        {
            if ( validMayaTransform )
            {
                // Set the transform animation information.
                size_t numTransformAnimations = transformAnimations.size ();
                for ( size_t i=0; i<numTransformAnimations; ++i )
                {
                    const TransformAnimation& transformAnim = transformAnimations [i];
                    const COLLADAFW::UniqueId& animationListId = transformAnim.getAnimationListId ();
                    mTransformAnimationMap [animationListId] = transformAnim;
                }

                // Set the transform values.
                if ( node->getType () == COLLADAFW::Node::NODE )
                    importDecomposedNodeTransform ( mayaTransform, transformNode, hasRotatePivot, hasScalePivot );
                else if ( node->getType () == COLLADAFW::Node::JOINT )
                    importDecomposedJointTransform ( mayaTransform, (MayaDM::Joint*) transformNode );
            }
            else
            {
                // Set the transform matrix to the transform object
                if ( node->getType () == COLLADAFW::Node::NODE )
                    importMatrixNodeTransform ( node, transformNode );
                else if ( node->getType () == COLLADAFW::Node::JOINT )
                    importMatrixJointTransform ( node, transformNode, parentNode );
            }
        }
        return true;
    }

    // -----------------------------------
    void VisualSceneImporter::importMatrixJointTransform ( 
        const COLLADAFW::Node* node, 
        MayaDM::Transform* transformNode,
        const COLLADAFW::Node* parentNode /*= NULL*/ )
    {
        importMatrixNodeTransform ( node, transformNode );
    }

    // -----------------------------------
    void VisualSceneImporter::importMatrixNodeTransform ( 
        const COLLADAFW::Node* node, 
        MayaDM::Transform* transformNode )
    {
        COLLADABU::Math::Matrix4 transformMatrix = node->getTransformationMatrix ();
        importMatrixTransform ( transformMatrix, transformNode );
    }

    // -----------------------------------
    bool VisualSceneImporter::importMatrixTransform ( 
        const COLLADABU::Math::Matrix4& transformMatrix,
        MayaDM::Transform* transformNode )
    {
        // To get the rotation, we have to remove the scale from the matrix. After this, we have to 
        // check if there is also a shear on the matrix. If not, we can get the rotation.
		COLLADABU::Math::Matrix3 m3x3 = extract3x3MatrixWithNormalizedColumns(transformMatrix).transpose();

        // Get the scale.
        COLLADABU::Math::Vector3 scale = transformMatrix.getScale ();

        // Get the determinant of the matrix. If it is smaller or equal zero, we have to change 
        // the matrix to get the correct rotation and we have to change the scale x value.
        double determinant = m3x3.determinant ();
        if ( determinant <= 0 )
        {
            scale.x *= -1;
            COLLADABU::Math::Matrix3 m3x3Det ( -1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 );
            m3x3 = m3x3 * m3x3Det;
        }

        // Write the translation.
        COLLADABU::Math::Vector3 trans = transformMatrix.getTrans ();
        transformNode->setTranslate ( toLinearUnit ( MayaDM::double3 ( trans.x, trans.y, trans.z ) ) );

        // Now we can get the rotation and set it into the document.
        double x=0.0, y=0.0, z=0.0;
		m3x3.toEulerAnglesXYZ ( x, y, z );
        if ( !COLLADABU::Math::Utils::equals ( x, 1.0, getTolerance () ) || !COLLADABU::Math::Utils::equals ( y, 1.0, getTolerance () ) || !COLLADABU::Math::Utils::equals ( z, 1.0, getTolerance () ) )
            transformNode->setRotate ( toAngularUnit ( MayaDM::double3 ( x, y, z ) ) );

        // Write the scale.
        if ( !COLLADABU::Math::Utils::equals ( scale.x, 1.0, getTolerance () ) || !COLLADABU::Math::Utils::equals ( scale.y, 1.0, getTolerance () ) || !COLLADABU::Math::Utils::equals ( scale.z, 1.0, getTolerance () ) )
            transformNode->setScale ( ( MayaDM::double3 ( scale.x, scale.y, scale.z ) ) );

        // TODO Shear
//         double shear[3];
//         tm.getShear ( shear, MSpace::kTransform );
//         if ( ! ( MVector (0,0,0) == MVector ( shear ) ) )
//             transformNode->setShear ( ( MayaDM::double3 ( shear[0], shear[1], shear[2] ) ) );
//         //transformNode->setShear ( toUpAxisTypeAxis ( MayaDM::double3 ( shear[0], shear[1], shear[2] ) ) );

        return true;
    }

    // -----------------------------------
    MayaDM::Transform* VisualSceneImporter::createMayaDMNode ( 
        const COLLADAFW::Node* node, 
        const String& nodeName, 
        const String& parentNodeName )
    {
        // Get the current maya ascii file to write the data.
        FILE* file = getDocumentImporter ()->getFile ();

        // Create a transform node of the specific type.
        MayaDM::Transform* transformNode;

        COLLADAFW::Node::NodeType nodeType = node->getType ();
        switch ( nodeType )
        {
        case COLLADAFW::Node::JOINT:
            {
                transformNode = new MayaDM::Joint ( file, nodeName.c_str (), parentNodeName );
                break;
            }
        case COLLADAFW::Node::NODE:
            {
                // Create the transform node object of the current node.
                transformNode = new MayaDM::Transform ( file, nodeName.c_str (), parentNodeName );
                break;
            }
        default:
            std::cerr << "Not a valid node type!" << std::endl;
        }

        // Now set the node path in front of the name.
        transformNode->setName ( parentNodeName + "|" + nodeName );

        return transformNode;
    }

    // -----------------------------------
    bool VisualSceneImporter::readMayaTransformations ( 
        const COLLADAFW::Node* node, 
        MayaTransform& mayaTransform, 
        MayaDM::Transform* transformNode, 
        std::vector<TransformAnimation>& transformAnimations,
        bool& hasRotatePivot,
        bool& hasScalePivot,
        bool& isLookatTransform )
    {
        bool validMayaTransform = true;

        const COLLADAFW::UniqueId& transformId = node->getUniqueId ();

        // Not every animation can be imported. So if we have more then one translation in the 
        // current node, we can't import the animation. 
        size_t numTranslations = 0;
        TransformAnimation translateAnim;

        const COLLADAFW::TransformationArray& transforms = node->getTransformations ();
        size_t numTransforms = transforms.getCount ();
        for ( size_t i=0; i<numTransforms && validMayaTransform; ++i )
        {
            const COLLADAFW::Transformation* transformation = transforms [i];

            COLLADAFW::Transformation::TransformationType transformType; 
            transformType = transformation->getTransformationType ();

            // Check if we handle a joint node.
            bool isJoint = ( node->getType () == COLLADAFW::Node::JOINT );

            // Not every animation can be imported. So if we have more then one translation in the 
            // current node, we can't import the animation. 
            bool storeAnimationDirectly = true;

            // Set the transformation information in depend of the transform type.
            switch ( transformType )
            {
            case COLLADAFW::Transformation::LOOKAT:
                {
                    // Import the camera's lookat transform matrix.
                    importLookatTransform ( node, transformation, transformNode );

                    isLookatTransform = true; 
                    validMayaTransform = false;
                    return validMayaTransform;
                }
                break;
            case COLLADAFW::Transformation::MATRIX:
                {
                    // Nothing to do, the matrix will be read automatically.
                    validMayaTransform = false;
                    return validMayaTransform;
                }
                break;
            case COLLADAFW::Transformation::ROTATE:
                {
                    if ( !isJoint )
                        validMayaTransform = handleTransformRotateValues ( mayaTransform, transformation );
                    else 
                        validMayaTransform = handleJointRotateValues ( mayaTransform, transformation );

                    if ( !validMayaTransform ) return validMayaTransform;
                }
                break;
            case COLLADAFW::Transformation::SCALE:
                if ( mayaTransform.phase <= MayaTransform::PHASE_SCALE )
                {
                    // Set the actual phase to a scale phase.
                    mayaTransform.phase = MayaTransform::PHASE_SCALE;

                    COLLADAFW::Scale* scale = ( COLLADAFW::Scale* )transformation;
                    COLLADABU::Math::Vector3& scaleVec = scale->getScale ();
                    for ( unsigned int k=0; k<3; ++k )
                        mayaTransform.scale [k] = scaleVec [k];
                }
                else 
                {
                    validMayaTransform = false;
                    return validMayaTransform;
                }
                break;
            case COLLADAFW::Transformation::SKEW:
                {
                    // TODO Skew
                    COLLADAFW::Skew* skew = ( COLLADAFW::Skew* )transformation;
//                     MMatrix matrix;
//                     skewValuesToMayaMatrix ( skew, matrix );
//                     MTransformationMatrix tm ( matrix );
//                     double shear[3];
//                     tm.getShear ( shear, MSpace::kTransform );
//                     for ( unsigned int k=0; k<3; ++k )
//                         mayaTransform.skew [k] = shear [k];

                    float angle = skew->getAngle ();
                    COLLADABU::Math::Vector3& rotateAxis = skew->getRotateAxis ();
                    COLLADABU::Math::Vector3& translateAxis = skew->getTranslateAxis ();
                    // TODO
//                     for ( unsigned int k=0; k<3; ++k )
//                         mayaTransform.skew [k] = ???;
                }
                break;
            case COLLADAFW::Transformation::TRANSLATE:
                {
                    storeAnimationDirectly = false;
                    ++numTranslations;

                    // Create the animation of the translation.
                    const COLLADAFW::UniqueId& animationListId = transformation->getAnimationList ();
                    if ( animationListId.isValid () )
                    {
                        translateAnim.setAnimationListId ( animationListId );
                        translateAnim.setAnimationSourceId ( transformId );
                        translateAnim.setTransformation ( transformation );
                        translateAnim.setTransformPhase ( mayaTransform.phase );
                        translateAnim.setIsJointTransform ( isJoint );
                    }

                    handleTranslateValues ( mayaTransform, transformation );
                }
                break;
            default:
                std::cerr << "Unknown transformation type!" << std::endl;
                continue;
                break;
            }

            // Store the animation of the current transformation.
            if ( storeAnimationDirectly )
                createTransformAnimation ( transformId, transformation, mayaTransform.phase, isJoint, transformAnimations );
        }

        // Just if we have only one translation, we can import the animation of it.
        if ( translateAnim.getAnimationListId ().isValid () )
        {
            if ( numTranslations > 1 )
            {
                std::cerr << "Can't import animation of translation, about multiple translates under node " << node->getName () << std::endl;
            }
            else 
                transformAnimations.push_back ( translateAnim );
        }

        // Check the pivot values.
        if ( validMayaTransform )
            validMayaTransform = checkPivotValues ( mayaTransform, hasScalePivot, hasRotatePivot );

        return validMayaTransform;
    }

    // -----------------------------------
    bool VisualSceneImporter::handleJointRotateValues ( 
        MayaTransform &mayaTransform, 
        const COLLADAFW::Transformation* transformation )
    {
        bool validMayaTransform = true; 

        COLLADAFW::Rotate* rotation = ( COLLADAFW::Rotate* )transformation;
        double angle = rotation->getRotationAngle ();
        COLLADABU::Math::Vector3& axis = rotation->getRotationAxis ();

        // If the rotation axis is zero, we don't need to handle the rotation. 
        if ( COLLADABU::Math::Vector3::ZERO == axis )
        {
            return validMayaTransform;
        }

        // If the rotation is not aroung one axis, 
        // we have to iterpret the data with the transformation matrix.
        if ( axis != COLLADABU::Math::Vector3::UNIT_X && 
             axis != COLLADABU::Math::Vector3::UNIT_Y && 
             axis != COLLADABU::Math::Vector3::UNIT_Z )
        {
            validMayaTransform = false;
            return validMayaTransform;
        }

        // Rotation is maya conform, if there is not more than one rotation per axis
        // (except the axis rotations are direct successive).

        // On the first rotation set the actual phase to the joint orient phase 1.
        if ( mayaTransform.phase < MayaTransform::PHASE_JOINT_ORIENT1 )
        {
            mayaTransform.phase = MayaTransform::PHASE_JOINT_ORIENT1;
            mayaTransform.axisPhaseJointOrient1 = axis;
        }
        else if ( mayaTransform.phase > MayaTransform::PHASE_ROTATE_ORIENT3 )
        {
            validMayaTransform = false;
            return validMayaTransform;
        }


        // Check if the axis has changed.
        switch ( mayaTransform.phase )
        {
        case MayaTransform::PHASE_JOINT_ORIENT1:
            {
                // Change the phase set the axis if necessary.
                if ( mayaTransform.axisPhaseJointOrient1 != axis )
                {
                    mayaTransform.phase = MayaTransform::PHASE_JOINT_ORIENT2;
                    mayaTransform.axisPhaseJointOrient2 = axis;
                }
            }
            break;

        case MayaTransform::PHASE_JOINT_ORIENT2:
            {
                // Check, if the axis is not already used.
                if ( axis == mayaTransform.axisPhaseJointOrient1 )
                {
                    // Set the phase to the next orientation.
                    mayaTransform.phase = MayaTransform::PHASE_ROTATE1;
                    mayaTransform.axisPhaseRotate1 = axis;
                }
                else if ( mayaTransform.axisPhaseJointOrient2 != axis )
                {
                    // Change the phase and set the axis if necessary.
                    mayaTransform.phase = MayaTransform::PHASE_JOINT_ORIENT3;
                    mayaTransform.axisPhaseJointOrient3 = axis;
                }
            }
            break;

        case MayaTransform::PHASE_JOINT_ORIENT3:
            {
                // Set the phase to the next orientation.
                mayaTransform.phase = MayaTransform::PHASE_ROTATE1;
                mayaTransform.axisPhaseRotate1 = axis;
            }
            break;

        case MayaTransform::PHASE_ROTATE1:
            {
                // Change the phase set the axis if necessary.
                if ( mayaTransform.axisPhaseRotate1 != axis )
                {
                    mayaTransform.phase = MayaTransform::PHASE_ROTATE2;
                    mayaTransform.axisPhaseRotate2 = axis;
                }
            }
            break;

        case MayaTransform::PHASE_ROTATE2:
            {
                // Check, if the axis is not already used.
                if ( axis == mayaTransform.axisPhaseRotate1 )
                {
                    // Set the phase to the next orientation.
                    mayaTransform.phase = MayaTransform::PHASE_ROTATE_ORIENT1;
                    mayaTransform.axisPhaseRotateOrient1 = axis;
                }
                else if ( mayaTransform.axisPhaseRotate2 != axis )
                {
                    // Change the phase and set the axis if necessary.
                    mayaTransform.phase = MayaTransform::PHASE_ROTATE3;
                    mayaTransform.axisPhaseRotate3 = axis;
                }
            }
            break;

        case MayaTransform::PHASE_ROTATE3:
            {
                // Set the phase to the next orientation.
                mayaTransform.phase = MayaTransform::PHASE_ROTATE_ORIENT1;
                mayaTransform.axisPhaseRotateOrient1 = axis;
            }
            break;

        case MayaTransform::PHASE_ROTATE_ORIENT1:
            {
                // Change the phase set the axis if necessary.
                if ( mayaTransform.axisPhaseRotateOrient1 != axis )
                {
                    mayaTransform.phase = MayaTransform::PHASE_ROTATE_ORIENT2;
                    mayaTransform.axisPhaseRotateOrient2 = axis;
                }
            }
            break;

        case MayaTransform::PHASE_ROTATE_ORIENT2:
            {
                // Check, if the axis is not already used.
                if ( axis == mayaTransform.axisPhaseRotate1 )
                {
                    validMayaTransform = false;
                    return validMayaTransform;
                }
                else if ( mayaTransform.axisPhaseRotate2 != axis )
                {
                    // Change the phase and set the axis if necessary.
                    mayaTransform.phase = MayaTransform::PHASE_ROTATE_ORIENT3;
                    mayaTransform.axisPhaseRotateOrient3 = axis;
                }
            }
            break;

        case MayaTransform::PHASE_ROTATE_ORIENT3:
            {
                validMayaTransform = false;
                return validMayaTransform;
            }
            break;

        default:
            std::cerr << "No valid transformation phase!" << std::endl;
            break;
        }

        // Add the rotation angle.
        if ( mayaTransform.phase <= MayaTransform::PHASE_JOINT_ORIENT3 )
        {
            if ( axis == COLLADABU::Math::Vector3::UNIT_X )
            {
                mayaTransform.jointOrient.x += angle;
            }
            else if ( axis == COLLADABU::Math::Vector3::UNIT_Y )
            {
                mayaTransform.jointOrient.y += angle;
            }
            else if ( axis == COLLADABU::Math::Vector3::UNIT_Z )
            {
                mayaTransform.jointOrient.z += angle;
            }
        }
        else if ( mayaTransform.phase <= MayaTransform::PHASE_ROTATE3 )
        {
            if ( axis == COLLADABU::Math::Vector3::UNIT_X )
            {
                mayaTransform.rotation.x += angle;
            }
            else if ( axis == COLLADABU::Math::Vector3::UNIT_Y )
            {
                mayaTransform.rotation.y += angle;
            }
            else if ( axis == COLLADABU::Math::Vector3::UNIT_Z )
            {
                mayaTransform.rotation.z += angle;
            }
        }
        else if ( mayaTransform.phase <= MayaTransform::PHASE_ROTATE_ORIENT3 )
        {
            if ( axis == COLLADABU::Math::Vector3::UNIT_X )
            {
                mayaTransform.rotateOrient.x += angle;
            }
            else if ( axis == COLLADABU::Math::Vector3::UNIT_Y )
            {
                mayaTransform.rotateOrient.y += angle;
            }
            else if ( axis == COLLADABU::Math::Vector3::UNIT_Z )
            {
                mayaTransform.rotateOrient.z += angle;
            }
        }

        return validMayaTransform;
    }

    // -----------------------------------
    bool VisualSceneImporter::handleTransformRotateValues ( 
        MayaTransform &mayaTransform, 
        const COLLADAFW::Transformation* transformation )
    {
        bool validMayaTransform = true; 

        COLLADAFW::Rotate* rotation = ( COLLADAFW::Rotate* )transformation;
        double angle = rotation->getRotationAngle ();
        COLLADABU::Math::Vector3& axis = rotation->getRotationAxis ();

        // If the rotation axis is zero, we don't need to handle the rotation. 
        if ( COLLADABU::Math::Vector3::ZERO == axis )
        {
            return validMayaTransform;
        }

        // If the rotation is not aroung one axis, 
        // we have to iterpret the data with the transformation matrix.
        if ( axis != COLLADABU::Math::Vector3::UNIT_X && 
             axis != COLLADABU::Math::Vector3::UNIT_Y && 
             axis != COLLADABU::Math::Vector3::UNIT_Z )
        {
            validMayaTransform = false;
            return validMayaTransform;
        }

        // Rotation is maya conform, if there is not more than one rotation per axis
        // (except the axis rotations are direct successive).

        // On the first rotation set the actual phase to the rotate phase 1.
        if ( mayaTransform.phase < MayaTransform::PHASE_ROTATE1 )
        {
            mayaTransform.phase = MayaTransform::PHASE_ROTATE1;
            mayaTransform.axisPhaseRotate1 = axis;
        }
        else if ( mayaTransform.phase > MayaTransform::PHASE_ROTATE3 )
        {
            validMayaTransform = false;
            return validMayaTransform;
        }

        // Check if the axis has changed.
        switch ( mayaTransform.phase )
        {
        case MayaTransform::PHASE_ROTATE1:
            {
                // Change the phase set the axis if necessary.
                if ( mayaTransform.axisPhaseRotate1 != axis )
                {
                    mayaTransform.phase = MayaTransform::PHASE_ROTATE2;
                    mayaTransform.axisPhaseRotate2 = axis;
                }
            }
            break;

        case MayaTransform::PHASE_ROTATE2:
            {
                // Check, if the axis is not already used.
                if ( axis == mayaTransform.axisPhaseRotate1 )
                {
                    validMayaTransform = false;
                    return validMayaTransform;
                }

                // Change the phase and set the axis if necessary.
                if ( mayaTransform.axisPhaseRotate2 != axis )
                {
                    mayaTransform.phase = MayaTransform::PHASE_ROTATE3;
                    mayaTransform.axisPhaseRotate3 = axis;
                }
            }
            break;

        case MayaTransform::PHASE_ROTATE3:
            {
                // Check, if the axis is not already used.
                if ( axis == mayaTransform.axisPhaseRotate1 || 
                    axis == mayaTransform.axisPhaseRotate2 )
                {
                    validMayaTransform = false;
                    return validMayaTransform;
                }
            }
            break;

        default:
            std::cerr << "No valid transformation phase!" << std::endl;
            break;
        }

        if ( mayaTransform.phase <= MayaTransform::PHASE_ROTATE3 )
        {
            if ( axis == COLLADABU::Math::Vector3::UNIT_X )
            {
                mayaTransform.rotation.x += angle;
            }
            else if ( axis == COLLADABU::Math::Vector3::UNIT_Y )
            {
                mayaTransform.rotation.y += angle;
            }
            else if ( axis == COLLADABU::Math::Vector3::UNIT_Z )
            {
                mayaTransform.rotation.z += angle;
            }
            else
            {
                validMayaTransform = false;
                return validMayaTransform;
            }
        }

        return validMayaTransform;
    }

    // -----------------------------------
    void VisualSceneImporter::handleTranslateValues ( 
        MayaTransform &mayaTransform, 
        const COLLADAFW::Transformation* transformation )
    {
        // Get the translation.
        COLLADAFW::Translate* translate = ( COLLADAFW::Translate* )transformation;
        COLLADABU::Math::Vector3 translation = translate->getTranslation ();

        // We don't need to handle a zero translation.
        if ( COLLADABU::Math::Vector3::ZERO == translation ) return;

        // Set the actual phase to a transform phase.
        if ( mayaTransform.phase <= MayaTransform::PHASE_TRANS1 ) 
            mayaTransform.phase = MayaTransform::PHASE_TRANS1;
        else if ( mayaTransform.phase <= MayaTransform::PHASE_TRANS2 )
            mayaTransform.phase = MayaTransform::PHASE_TRANS2;
        else if ( mayaTransform.phase <= MayaTransform::PHASE_TRANS3 )
            mayaTransform.phase = MayaTransform::PHASE_TRANS3;

        if ( mayaTransform.phase == MayaTransform::PHASE_TRANS1 )
        {
            mayaTransform.translate1Vec.push_back ( COLLADABU::Math::Vector3 (translation[0],translation[1],translation[2] ) );
            ++mayaTransform.numTranslate1;
            for ( unsigned int j=0; j<3; ++j )
                mayaTransform.translate1[j] += translation [j];
        }
        else if ( mayaTransform.phase == MayaTransform::PHASE_TRANS2 )
        {
            mayaTransform.translate2Vec.push_back ( COLLADABU::Math::Vector3 (translation[0],translation[1],translation[2] ) );
            ++mayaTransform.numTranslate2;
            for ( unsigned int j=0; j<3; ++j )
                mayaTransform.translate2[j] += translation [j];
        }
        else if ( mayaTransform.phase == MayaTransform::PHASE_TRANS3 )
        {
            mayaTransform.translate3Vec.push_back ( COLLADABU::Math::Vector3 (translation[0],translation[1],translation[2] ) );
            ++mayaTransform.numTranslate3;
            for ( unsigned int j=0; j<3; ++j )
                mayaTransform.translate3[j] += translation [j];
        }
    }

    // -----------------------------------
    bool VisualSceneImporter::checkPivotValues ( 
        MayaTransform &mayaTransform, 
        bool &hasScalePivot, 
        bool &hasRotatePivot )
    {
        bool validMayaTransform = true; 

        // Get the number of vectors
        size_t numTranslate1Vec = mayaTransform.translate1Vec.size ();
        size_t numTranslate2Vec = mayaTransform.translate2Vec.size ();
        size_t numTranslate3Vec = mayaTransform.translate3Vec.size ();

        // Just one translate3Vec is allowed.
        if (  numTranslate3Vec > 1 )
        {
            validMayaTransform = false;
            return validMayaTransform;
        }

        // If we have one translate3, which is the scalePivotInverse, 
        // the last Vector of the translate2 has to be the scalePivot.
        if ( numTranslate3Vec == 1 )
        {
            // The first translate3 vector has to be the scalePivotInverse.
            COLLADABU::Math::Vector3& scalePivotInverse = mayaTransform.translate3Vec[0];

            // If we have a scalePivotInverse, we need minimum one translate2 vector. 
            // The last translate2 vector has to be the scalePivot. 
            COLLADABU::Math::Vector3 scalePivot (0,0,0);
            if ( numTranslate2Vec > 0 )
            {
                // The last translate2 vector has to be the scalePivot. 
                scalePivot = mayaTransform.translate2Vec[numTranslate2Vec-1];
            }
            else
            {
                // Except we don't have a rotation... 
                // Then the scalePivot is the last translate1 vector.
                if ( numTranslate1Vec > 0 )
                    scalePivot = mayaTransform.translate1Vec[numTranslate1Vec-1];
                else 
                {
                    validMayaTransform = false;
                    return validMayaTransform;
                }
            }

            // Check, if the vectors are inverse.
            if ( ( scalePivot * (-1) ) != scalePivotInverse )
            {
                validMayaTransform = false;
                return validMayaTransform;
            }

            // We have a valid scalePivot.
            hasScalePivot = true;
        }

        // Without a translate1 vector, we can't have a rotatePivot
        if ( numTranslate1Vec > 0 )
        {
            // We also need minimum one translate2 vector, 
            // respectively minimum two translate2 vectors, if we have a scalePivot.
            if ( numTranslate2Vec > 0 || ( hasScalePivot && numTranslate2Vec > 1 ) )
            {
                // Check if we have a rotatePivotInverse at the beginning of the translate2 vectors
                // and the rotatePivot at the end of the translate1 vectors.

                // The first translate2 vector has to be the rotatePivotInverse.
                COLLADABU::Math::Vector3& rotatePivotInverse = mayaTransform.translate2Vec[0];

                // The last translate1 vector has to be the rotatePivot. 
                COLLADABU::Math::Vector3& rotatePivot = mayaTransform.translate1Vec[numTranslate1Vec-1];

                // Check, if the vectors are inverse.
                if ( ( rotatePivot * (-1) ) != rotatePivotInverse )
                {
                    validMayaTransform = false;
                    return validMayaTransform;
                }
                hasRotatePivot = true;
            }
        }

        return validMayaTransform;
    }

    // -----------------------------------
    void VisualSceneImporter::importDecomposedJointTransform ( 
        const MayaTransform &mayaTransform, 
        MayaDM::Joint* jointNode )
    {
        // This is the order of the transforms:
        //
        // matrix = [S] * [RO] * [R] * [JO] * [IS] * [T]
        //
        // Where S is scale, RO is rotate orient (attribute name is rotateAxis), R is rotation, 
        // JO is joint orientation, IS is parentScaleInverse, T is translation

        // Get the euler rotation and detect the rotation order.
        MayaTransform::RotationOrder rotateOrientOrder = getRotationOrder ( mayaTransform.axisPhaseRotateOrient1, mayaTransform.axisPhaseRotateOrient2, mayaTransform.axisPhaseRotateOrient3 );
        COLLADABU::Math::Vector3 rotateOrient = mayaTransform.rotateOrient;

        // Get the euler rotation and detect the rotation order.
        MayaTransform::RotationOrder rotateOrder = getRotationOrder ( mayaTransform.axisPhaseRotate1, mayaTransform.axisPhaseRotate2, mayaTransform.axisPhaseRotate3 );
        COLLADABU::Math::Vector3 rotation = mayaTransform.rotation;

        // Get the euler rotation and detect the rotation order.
        MayaTransform::RotationOrder jointOrientOrder = getRotationOrder ( mayaTransform.axisPhaseJointOrient1, mayaTransform.axisPhaseJointOrient2, mayaTransform.axisPhaseJointOrient3 );
        COLLADABU::Math::Vector3 jointOrient = mayaTransform.jointOrient;

        // Get the scale.
        COLLADABU::Math::Vector3 scale = mayaTransform.scale;

        // TODO If the current node is a joint, we have to look for the parent scale.
//        MVector parentScaleInverse = mayaTransform.parentScaleInverse;

        // Get the number of vectors
        size_t numTranslate1Vec = mayaTransform.translate1Vec.size ();
        size_t numTranslate2Vec = mayaTransform.translate2Vec.size ();
        size_t numTranslate3Vec = mayaTransform.translate3Vec.size ();

        // T = T1 + T2 + T3 - SPT - RPT
        COLLADABU::Math::Vector3 translate1 = mayaTransform.translate1;
        COLLADABU::Math::Vector3 translate2 = mayaTransform.translate2;
        COLLADABU::Math::Vector3 translate3 = mayaTransform.translate3;
        COLLADABU::Math::Vector3 translate = translate1 + translate2 + translate3;

        // Write the transformations directly into the maya file.
        if ( translate != COLLADABU::Math::Vector3 (0, 0, 0) )
            jointNode->setTranslate ( toLinearUnit ( MayaDM::double3 ( translate.x , translate.y, translate.z ) ) );

        // Rotate Orient (attribute name is rotateAxis)
        if ( rotateOrient != COLLADABU::Math::Vector3 (0, 0, 0) )
        {
            jointNode->setRotateAxis ( MayaDM::double3 ( rotateOrient.x, rotateOrient.y, rotateOrient.z ) );
        }

        if ( rotation != COLLADABU::Math::Vector3 (0, 0, 0) )
        {
            if ( rotateOrder != MayaTransform::kXYZ )
                jointNode->setRotateOrder ( rotateOrder );
            jointNode->setRotate ( MayaDM::double3 ( rotation.x, rotation.y, rotation.z ) );
        }

        if ( jointOrient != COLLADABU::Math::Vector3 (0, 0, 0) )
        {
            // TODO
//             if ( rotateOrder != MEulerRotation::kXYZ )
//                 jointNode->setJointOrientType ( rotateOrder );
            jointNode->setJointOrient ( MayaDM::double3 ( jointOrient.x, jointOrient.y, jointOrient.z ) );
        }

        if ( scale != COLLADABU::Math::Vector3 (1, 1, 1) )
            jointNode->setScale ( MayaDM::double3 ( scale[0], scale[1], scale[2] ) );
    }

    // -----------------------------------
    void VisualSceneImporter::importDecomposedNodeTransform ( 
        const MayaTransform &mayaTransform, 
        MayaDM::Transform* transformNode,
        const bool hasRotatePivot,
        const bool hasScalePivot )
    {
        // This is the order of the transforms:
        //
        // matrix = [SP-1 * S * SH * SP * ST] * [RP-1 * RA * R * JO * RP * RT] * T
        //          [        scale          ] * [          rotation          ] * translation
        //
        // Where SP is scale pivot translation, S is scale, SH is shear, ST is scale pivot translation
        // RP is rotation pivot, RA is rotation axis, R is rotation, RP is rotation pivot,
        // RT is rotation pivot translation, T is translation, JO is joint orientation

        // T1 = T + RP + RPT
        // R  = R
        // T2 = RP-1 + SPT + SP
        // S  = S
        // T3 = SP-1
        // ==> T = T1 + T2 + T3 - SPT - RPT

        // In the following calculation the RPT and SPT values are absent, 
        // so the calculation is wrong!
        {
//             MVector translate3 = mayaTransform.translate3;
//             MVector inverseScalePivot ( translate3 [0], translate3 [1], translate3 [2] );
//             MVector scalePivot = inverseScalePivot * (-1);
// 
//             MVector translate2 = mayaTransform.translate2;
//             MVector inverseRotatePivot = scalePivot - translate2;
//             MVector rotatePivot = inverseRotatePivot * (-1);
// 
//             MVector translate1 = mayaTransform.translate1;
//             MVector translate = translate1 - rotatePivot;
//             MVector tester = translate1 + translate2 + translate3;
// 
//             MQuaternion mayaRotate = mayaTransform.rotation;
//             MEulerRotation eulerRotation = mayaRotate.asEulerRotation ();
//             MEulerRotation::RotationOrder order = eulerRotation.order;
//             MVector rotation = eulerRotation.asVector ();
        }

        // Get the number of vectors
        size_t numTranslate1Vec = mayaTransform.translate1Vec.size ();
        size_t numTranslate2Vec = mayaTransform.translate2Vec.size ();
        size_t numTranslate3Vec = mayaTransform.translate3Vec.size ();

        COLLADABU::Math::Vector3 scalePivot (0,0,0);
        COLLADABU::Math::Vector3 scalePivotTranslate (0,0,0);

        COLLADABU::Math::Vector3 rotatePivot (0,0,0);
        COLLADABU::Math::Vector3 rotatePivotTranslate (0,0,0);

        bool hasScalePivotTranslate = false;

        if ( hasScalePivot )
        {
            // Get the scalePivot
            scalePivot = mayaTransform.translate3Vec[0] * (-1);

            // Check for a scalePivotTranslate
            if ( hasRotatePivot )
            {
                if ( numTranslate2Vec == 3 )
                {
                    scalePivotTranslate = mayaTransform.translate2Vec[numTranslate2Vec-2];
                    hasScalePivotTranslate = true;
                }
            }
            else
            {
                if ( numTranslate2Vec == 2 )
                {
                    scalePivotTranslate = mayaTransform.translate2Vec[0];
                    hasScalePivotTranslate = true;
                }
            }
        }

        if ( hasRotatePivot )
        {
            // The last translate1 vector has to be the rotatePivot. 
            rotatePivot = mayaTransform.translate1Vec[numTranslate1Vec-1];

            if ( hasScalePivot )
            {
                if ( numTranslate2Vec == 3 )
                    rotatePivotTranslate = mayaTransform.translate1Vec[1];
            }
        }

        // T = T1 + T2 + T3 - SPT - RPT
        COLLADABU::Math::Vector3 translate1 = mayaTransform.translate1;
        COLLADABU::Math::Vector3 translate2 = mayaTransform.translate2;
        COLLADABU::Math::Vector3 translate3 = mayaTransform.translate3;
        COLLADABU::Math::Vector3 translate = translate1 + translate2 + translate3 - scalePivotTranslate - rotatePivotTranslate;

        // Get the euler rotation and detect the rotation order.
        MayaTransform::RotationOrder order = getRotationOrder ( mayaTransform.axisPhaseRotate1, mayaTransform.axisPhaseRotate2, mayaTransform.axisPhaseRotate3 );
        COLLADABU::Math::Vector3 rotation = mayaTransform.rotation;

        COLLADABU::Math::Vector3 scale = mayaTransform.scale;
        COLLADABU::Math::Vector3 skew = mayaTransform.skew;

        // Write the transformations directly into the maya file.
        if ( translate != COLLADABU::Math::Vector3 (0, 0, 0) )
            transformNode->setTranslate ( toLinearUnit ( MayaDM::double3 ( translate.x , translate.y, translate.z ) ) );
        if ( rotation != COLLADABU::Math::Vector3 (0, 0, 0) )
            transformNode->setRotate ( MayaDM::double3 ( rotation.x, rotation.y, rotation.z ) );
        if ( scale != COLLADABU::Math::Vector3 (1, 1, 1) )
            transformNode->setScale ( MayaDM::double3 ( scale[0], scale[1], scale[2] ) );
            //transformNode->setScale ( toUpAxisTypeFactor ( MayaDM::double3 ( scale[0], scale[1], scale[2] ) ) );

        if ( skew != COLLADABU::Math::Vector3 (0, 0, 0))
            transformNode->setShear ( MayaDM::double3 ( skew.x, skew.y, skew.z ) );
            //transformNode->setShear ( toUpAxisTypeAxis ( MayaDM::double3 ( skew.x, skew.y, skew.z ) ) );

        if ( rotatePivot != COLLADABU::Math::Vector3 (0, 0, 0) )
            transformNode->setRotatePivot ( toLinearUnit ( MayaDM::double3 ( rotatePivot.x, rotatePivot.y, rotatePivot.z ) ) );
        if ( rotatePivotTranslate != COLLADABU::Math::Vector3 (0, 0, 0) )
            transformNode->setRotatePivotTranslate ( toLinearUnit ( MayaDM::double3 ( rotatePivotTranslate.x, rotatePivotTranslate.y, rotatePivotTranslate.z ) ) );

        if ( scalePivot != COLLADABU::Math::Vector3 (0, 0, 0) )
            transformNode->setScalePivot ( toLinearUnit ( MayaDM::double3 ( scalePivot.x, scalePivot.y, scalePivot.z ) ) );
        if ( scalePivotTranslate != COLLADABU::Math::Vector3 (0, 0, 0) )
            transformNode->setScalePivotTranslate ( toLinearUnit ( MayaDM::double3 ( scalePivotTranslate.x, scalePivotTranslate.y, scalePivotTranslate.z ) ) );
        
        if ( order != MayaTransform::kXYZ )
            transformNode->setRotateOrder ( order );
    }

//     // -----------------------------------
//     void VisualSceneImporter::skewValuesToMayaMatrix ( 
//         const COLLADAFW::Skew* skew, MMatrix& matrix ) 
//     {
//         // Shearing in xy, xz, yx [Sh] 
//         float s = tanf ( COLLADABU::Math::Utils::degToRadF ( skew->getAngle () ) );
// 
//         // Unit conversion.
//         const COLLADABU::Math::Vector3& rotateAxis = skew->getRotateAxis();
//         //MayaDM::double3 rotate ( toUpAxisTypeAxis ( MayaDM::double3 ( rotateAxis.x, rotateAxis.y, rotateAxis.z ) ) );
// 
//         const COLLADABU::Math::Vector3& translateAxis = skew->getTranslateAxis();
//         //MayaDM::double3 translate ( toUpAxisTypeAxis ( MayaDM::double3 ( translateAxis.x, translateAxis.y, translateAxis.z ) ) );
// 
//         /*
//         Sh =    |  1    0    0    0 |
//                 | shxy  1    0    0 |
//                 | shxz shyz  1    0 | 
//                 |  0    0    0    1 |
//         */
//         for ( int row = 0; row < 3; ++row )
//         {
//             for ( int col = 0; col < 3; ++col )
//             {
//                 matrix[col][row] = ((row == col) ? 1.0f : 0.0f) + s * (float)rotateAxis [col] * (float)translateAxis [row];
//             }
//         }
// 
//         matrix[0][3] = matrix[1][3] = matrix[2][3] = 0.0f;
//         matrix[3][0] = matrix[3][1] = matrix[3][2] = 0.0f;
//         matrix[3][3] = 1.0f;
//     }

    // -----------------------------------
    void VisualSceneImporter::createTransformAnimation ( 
        const COLLADAFW::UniqueId& transformId, 
        const COLLADAFW::Transformation* transformation, 
        const MayaTransform::TransformPhase& transformPhase,
        const bool isJointTransform, 
        std::vector<TransformAnimation>& transformAnimations )
    {
        // Get the id of animation list of the current transformation and store 
        // the transform node id, the mayaTransform node and the transformation type.
        const COLLADAFW::UniqueId& animationListId = transformation->getAnimationList ();
        if ( animationListId.isValid () )
        {
            // Create a TransformAnimation objekt and push it in the list.
            TransformAnimation transformAnim;
            transformAnim.setAnimationListId ( animationListId );
            transformAnim.setAnimationSourceId ( transformId );
            transformAnim.setTransformation ( transformation );
            transformAnim.setTransformPhase ( transformPhase );
            transformAnim.setIsJointTransform ( isJointTransform );
            transformAnimations.push_back ( transformAnim );
        }
    }

    // -----------------------------------
    const BaseImporter::MayaNodesList* VisualSceneImporter::findMayaTransformNodes ( 
        const COLLADAFW::UniqueId& transformId ) const
    {
        UniqueIdMayaNodesMap::const_iterator it = mMayaTransformNodesMap.find ( transformId );
        if ( it != mMayaTransformNodesMap.end () )
            return &(it->second);

        return 0;
    }

    // -----------------------------------
    BaseImporter::MayaNodesList* VisualSceneImporter::findMayaTransformNodes ( 
        const COLLADAFW::UniqueId& transformId )
    {
        UniqueIdMayaNodesMap::iterator it = mMayaTransformNodesMap.find ( transformId );
        if ( it != mMayaTransformNodesMap.end () )
            return &(it->second);

        return 0;
    }

    // -----------------------------------
    const BaseImporter::UniqueIdVec* VisualSceneImporter::findTransformInstances ( 
        const COLLADAFW::UniqueId& transformId ) const
    {
        UniqueIdUniqueIdsMap::const_iterator it = mTransformInstancesMap.find ( transformId );

        if ( it != mTransformInstancesMap.end () )
            return &(*it).second;

        return 0;
    }

    // -----------------------------------
    const BaseImporter::UniqueIdVec* VisualSceneImporter::findGeometryTransformIds ( 
        const COLLADAFW::UniqueId& geometryId ) const
    {
        UniqueIdUniqueIdsMap::const_iterator it = mGeometryTransformIdsMap.find ( geometryId );

        if ( it != mGeometryTransformIdsMap.end () )
            return &(*it).second;

        return 0;
    }

    // -----------------------------------
    const BaseImporter::UniqueIdVec* VisualSceneImporter::findCameraTransformIds ( 
        const COLLADAFW::UniqueId& cameraId ) const
    {
        UniqueIdUniqueIdsMap::const_iterator it = mCameraTransformIdsMap.find ( cameraId );

        if ( it != mCameraTransformIdsMap.end () )
            return &(*it).second;

        return 0;
    }

    // -----------------------------------
    const BaseImporter::UniqueIdVec* VisualSceneImporter::findLightTransformIds ( 
        const COLLADAFW::UniqueId& lightId ) const
    {
        UniqueIdUniqueIdsMap::const_iterator it = mLightTransformIdsMap.find ( lightId );

        if ( it != mLightTransformIdsMap.end () )
            return &(*it).second;

        return 0;
    }

    // -----------------------------------
    const BaseImporter::UniqueIdVec* VisualSceneImporter::findControllerTransformIds ( 
        const COLLADAFW::UniqueId& controllerId ) const
    {
        UniqueIdUniqueIdsMap::const_iterator it = mControllerTransformIdsMap.find ( controllerId );

        if ( it != mControllerTransformIdsMap.end () )
            return &(*it).second;

        return 0;
    }

    // -----------------------------------
    bool VisualSceneImporter::importNodeInstances ( 
        const COLLADAFW::Node* parentNode, 
        MayaNode* parentMayaNode )
    {
        const COLLADAFW::InstanceNodeArray& nodeInstances = parentNode->getInstanceNodes ();
        size_t numInstances = nodeInstances.getCount ();
        for ( size_t i=0; i<numInstances; ++i )
        {
            // Get the unique node id and the framework node.
            const COLLADAFW::InstanceNode* instanceNode = nodeInstances [i];
            const COLLADAFW::UniqueId& instanceNodeId = instanceNode->getInstanciatedObjectId ();

            const NodeImporter* nodeImporter = getDocumentImporter ()->getNodeImporter ();
            const COLLADAFW::Node* node = nodeImporter->findNode ( instanceNodeId );
            if ( node == 0 )
            {
                std::cerr << "No node object for the current node id! Can't import!" << std::endl;
                continue;
            }
            
            // TODO Check if the node is already imported. If not, import the node, 
            // otherwise push it in the list of node instances.
            if ( !findMayaTransformNodes ( instanceNodeId ) ) 
            {
                // Import the instance node.
                importNode ( node, parentNode, parentMayaNode );
            }
            else
            {
                // Push the parent node of the instanciated node in the list of instance node parents.
                // The map holds for every transform node a list of all existing parent transform nodes
                // (this are the nodes, which hold an instance of the current transform node).
                const COLLADAFW::UniqueId& parentNodeId = parentNode->getUniqueId ();
                mTransformInstancesMap [ instanceNodeId ].push_back ( parentNodeId );
            }
        }

        return true;
    }

    // -----------------------------------
    bool VisualSceneImporter::readNodeInstances ( const COLLADAFW::Node* parentNode )
    {
        const COLLADAFW::UniqueId& parentNodeId = parentNode->getUniqueId ();

        const COLLADAFW::InstanceNodeArray& nodeInstances = parentNode->getInstanceNodes ();
        size_t numInstances = nodeInstances.getCount ();
        for ( size_t i=0; i<numInstances; ++i )
        {
            // Hold the information to create this instance.
            const COLLADAFW::InstanceNode* instanceNode = nodeInstances [i];
            const COLLADAFW::UniqueId& instanceNodeId = instanceNode->getInstanciatedObjectId ();

            // Push the parent node of the instanciated node in the list of instance node parents.
            // The map holds for every transform node a list of all existing parent transform nodes
            // (this are the nodes, which hold an instance of the current transform node).
            mTransformInstancesMap [ instanceNodeId ].push_back ( parentNodeId );
        }

        return true;
    }

    // -----------------------------------
    bool VisualSceneImporter::readGeometryInstances ( const COLLADAFW::Node* node )
    {
        // Get the unique id of the current node.
        const COLLADAFW::UniqueId& transformNodeId = node->getUniqueId ();

        // Go through the geometry instances and save the geometry ids to the current node.
        const COLLADAFW::InstanceGeometryArray& geometryInstances = node->getInstanceGeometries ();
        size_t numInstances = geometryInstances.getCount ();
        for ( size_t i=0; i<numInstances; ++i )
        {
            const COLLADAFW::InstanceGeometry* instanceGeometry = geometryInstances [i];
            const COLLADAFW::UniqueId& geometryId = instanceGeometry->getInstanciatedObjectId ();

            // Save for every geometry a list of transform nodes, which refer to it.
            mGeometryTransformIdsMap [ geometryId ].push_back ( transformNodeId );

            // Read the shading engines.
            readMaterialInstances ( transformNodeId, instanceGeometry );
        }

        return true;
    }

    // -----------------------------------
    bool VisualSceneImporter::readControllerInstances ( const COLLADAFW::Node* node )
    {
        // Get the unique id of the current node.
        const COLLADAFW::UniqueId& transformId = node->getUniqueId ();

        // Get the maya transform node and set the transform matrix. 
        // We will need it again, if we import a skin controller.
        MayaNodesList* mayaNodesList = findMayaTransformNodes ( transformId );
        if ( mayaNodesList != 0 ) 
        {
            COLLADABU::Math::Matrix4 transformMatrix = node->getTransformationMatrix ();
            for ( size_t j=0; j<mayaNodesList->size (); ++j )
            {
                MayaNode* mayaNode = (*mayaNodesList) [j];
                mayaNode->setTransformationMatrix ( transformMatrix );
            }
        }

        // Go through the instances and save the ids to the current node.
        const COLLADAFW::InstanceControllerArray& controllerInstances = node->getInstanceControllers ();
        size_t numInstances = controllerInstances.getCount ();
        for ( size_t i=0; i<numInstances; ++i )
        {
            const COLLADAFW::InstanceController* instanceController = controllerInstances [i];
            const COLLADAFW::UniqueId& controllerId = instanceController->getInstanciatedObjectId ();

            // Save for every controller a list of transform nodes, which refer to it.
            mControllerTransformIdsMap[controllerId].push_back ( transformId );

            // Get the geometryId of the geometry, which is controlled from the current controller object.
            ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
            const COLLADAFW::UniqueId* sourceId = controllerImporter->getControllerSourceId ( controllerId );
            if ( sourceId == NULL )
            {
                std::cerr << "No geometry for the current controller!" << std::endl;
                return false;
            }

            // Read the shading engines. Store the information, that the material instance is  
            // referenced from a controller object. We need this information if we do the 
            // connections between the geometries and the shadingEngines.
            readMaterialInstances ( transformId, instanceController, &controllerId );
        }

        return true;
    }

    // -----------------------------------
    template<COLLADAFW::ClassId classId>
    void VisualSceneImporter::readMaterialInstances ( 
        const COLLADAFW::UniqueId& transformId, 
        const COLLADAFW::InstanceBindingBase<classId>* instanceBinding,
        const COLLADAFW::UniqueId* controllerId /*= 0*/ )
    {
        // Store the shader data.
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
        materialImporter->writeShaderData ( transformId, instanceBinding, controllerId );

        // Create the necessary uv chooser objects for texture uv set binding.
        materialImporter->createBindingInputSets ( transformId, instanceBinding, controllerId );
    }

    // -----------------------------------
    bool VisualSceneImporter::readCameraInstances ( const COLLADAFW::Node* node )
    {
        // Get the unique id of the current node.
        const COLLADAFW::UniqueId& transformNodeId = node->getUniqueId ();

        // Go through the camera instances and save the geometry ids to the current node.
        const COLLADAFW::InstanceCameraArray& cameraInstances = node->getInstanceCameras ();
        size_t numInstances = cameraInstances.getCount ();
        for ( size_t i=0; i<numInstances; ++i )
        {
            const COLLADAFW::InstanceCamera* instanceCamera = cameraInstances [i];
            const COLLADAFW::UniqueId& cameraId = instanceCamera->getInstanciatedObjectId ();

            // Save for every geometry a list of transform nodes, which refer to it.
            mCameraTransformIdsMap [ cameraId ].push_back ( transformNodeId );
        }

        return true;
    }

    // -----------------------------------
    bool VisualSceneImporter::readLightInstances ( const COLLADAFW::Node* node )
    {
        // Get the unique id of the current node.
        const COLLADAFW::UniqueId& transformNodeId = node->getUniqueId ();

        // Go through the camera instances and save the geometry ids to the current node.
        const COLLADAFW::InstanceLightArray& lightInstances = node->getInstanceLights ();
        size_t numInstances = lightInstances.getCount ();
        for ( size_t i=0; i<numInstances; ++i )
        {
            const COLLADAFW::InstanceLight* instanceLight = lightInstances [i];
            const COLLADAFW::UniqueId& lightId = instanceLight->getInstanciatedObjectId ();

            // Save for every geometry a list of transform nodes, which refer to it.
            mLightTransformIdsMap [ lightId ].push_back ( transformNodeId );
        }

        return true;
    }

    // -----------------------------------
    void VisualSceneImporter::writeNodeInstances ()
    {
        // A pointer to the current maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Go through the transform instances and copy / move the instantiated nodes.
        UniqueIdUniqueIdsMap::iterator it = mTransformInstancesMap.begin ();
        while ( it != mTransformInstancesMap.end() )
        {
            const COLLADAFW::UniqueId& instanceNodeId = it->first;
            BaseImporter::UniqueIdVec& parentNodes = it->second;
            if ( parentNodes.size () == 0 )
            {
                std::cerr << "There has to be a parent node for the current transform node! Can't import!" << std::endl;
                continue;
            }

            // Get the maya child node and read the path.
            MayaNodesList* childTransformNodes = findMayaTransformNodes ( instanceNodeId );
            if ( childTransformNodes == 0 || childTransformNodes->size () == 0 )
            {
                std::cerr << "The referenced transform node doesn't exist!" << std::endl;
                return;
            }
            // The first node is always the reference node for the other instances.
            MayaNode* mayaChildNode = (*childTransformNodes) [0];
            const COLLADAFW::UniqueId& childTransformId = mayaChildNode->getUniqueId ();
            String childNodeName = mayaChildNode->getName ();
            String childNodePath = mayaChildNode->getNodePath ();

            // Go through the instances.
            size_t numInstances = parentNodes.size ();
            for ( size_t i=0; i<numInstances; ++i )
            {
                const COLLADAFW::UniqueId& parentTransformId = parentNodes [i];
                
                // Get the maya parent nodes and read the path.
                MayaNodesList* parentTransformNodes = findMayaTransformNodes ( parentTransformId );
                if ( parentTransformNodes == 0 )
                {
                    std::cerr << "The referenced transform node doesn't exist!" << std::endl;
                    return;
                }
                // Multiple parent instances...
                MayaNode* mayaParentNode = (*parentTransformNodes) [0];
                String parentNodeName = mayaParentNode->getName ();
                String parentNodePath = mayaParentNode->getNodePath ();

                // This flag is set, if the node is not from the visual scene, 
                // but from the library nodes. We don't have to create a new instance, 
                // instead of this we have to move the node!
//                 bool isCorrectPositioned = mayaChildNode->getIsCorrectPositioned ();
//                 if ( !isCorrectPositioned )
//                 {
//                     // parent -shape -noConnections -relative "|node1|node2" "|rootNode";
//                     MayaDM::parent ( file, childNodePath, parentNodePath, false, false, true, true  );
//                     mayaChildNode->setIsCorrectPositioned ( true );
//                     mayaChildNode->setParent ( mayaParentNode );
//                     childNodePath = mayaChildNode->getNodePath ();
//                 }
//                 else
                {
                    // parent -shape -noConnections -relative -addObject "|node1|node2" "|rootNode";
                    MayaDM::parent ( file, childNodePath, parentNodePath, false, true, true, true  );

                    // Create the maya transform nodes for the internal transform graph of this
                    // node instance and all child nodes.
                    MayaNode* mayaInstanceNode = new MayaNode ( instanceNodeId, childNodeName, mayaParentNode, mayaChildNode->getType () );
                    mMayaTransformNodesMap [ instanceNodeId ].push_back ( mayaInstanceNode );
                }
            }

            ++it;
        }
    }

    // --------------------------------------------
    size_t VisualSceneImporter::getNumTransformInstances ( 
        const COLLADAFW::UniqueId& transformId, 
        const bool recursive /*= false*/ )
    {
        // There is always one instance!
        size_t numNodeInstances = 0;
        if ( !recursive ) ++numNodeInstances;

        MayaNodesList* nodeInstances = findMayaTransformNodes ( transformId );
        if ( nodeInstances != 0 )
        {
            size_t nodeCounter = nodeInstances->size ();
            numNodeInstances += nodeCounter - 1;
            for ( size_t i=0; i<nodeCounter; ++i )
            {
                MayaNode* mayaNodeInstance = (*nodeInstances) [i];
                String name = mayaNodeInstance->getName ();
                String path = mayaNodeInstance->getNodePath ();

                MayaNode* parentMayaNode = mayaNodeInstance->getParent ();
                if ( parentMayaNode != 0 )
                {
                    const COLLADAFW::UniqueId& parentTransformNodeId = parentMayaNode->getUniqueId ();
                    numNodeInstances += getNumTransformInstances ( parentTransformNodeId, true );
                }
            }
        }

        return numNodeInstances;
    }

    // --------------------------------------------
    void VisualSceneImporter::getTransformPathes ( 
        std::vector<String>& transformPathes, 
        const COLLADAFW::UniqueId& transformId, 
        const String childSubPath /*= EMPTY_STRING*/ )
    {
        MayaNodesList* transformInstances = findMayaTransformNodes ( transformId );
        if ( transformInstances != 0 )
        {
            size_t nodeCounter = transformInstances->size ();
            for ( size_t i=0; i<nodeCounter; ++i )
            {
                MayaNode* mayaTransformInstanceNode = (*transformInstances) [i];
                String transformInstancePath = mayaTransformInstanceNode->getNodePath ();

                // The first instance in the list is always the original. 
                // The path of the first instance has to be stored only once!
                if ( i > 0 || childSubPath.empty () )
                {
                    // Push the path of the instance in the list of node pathes.
                    String transformPath = transformInstancePath + childSubPath;
                    transformPathes.push_back ( transformPath );
                }

                // Get the child path, to append on the parent instance path.
                MayaNode* parentMayaNode = mayaTransformInstanceNode->getParent ();
                if ( parentMayaNode != 0 )
                {
                    String parentChildSubPath =  "|" + mayaTransformInstanceNode->getName () + childSubPath;
                    const COLLADAFW::UniqueId& parentTransformId = parentMayaNode->getUniqueId ();
                    getTransformPathes ( transformPathes, parentTransformId, parentChildSubPath );
                }
            }
        }
    }

    // --------------------------------------------
    bool VisualSceneImporter::importLookatTransform ( 
        const COLLADAFW::Node* node,
        const COLLADAFW::Transformation* transformation,
        MayaDM::Transform* transformNode )
    {
        // Positioning and orienting a camera or object in the scene is often complicated when 
        // using a matrix. A lookat transform is an intuitive way to specify an eye position, 
        // interest point, and orientation.
        COLLADAFW::Lookat* lookat = ( COLLADAFW::Lookat* ) transformation;

        // The position of the object. 
        COLLADABU::Math::Vector3& eyePosition = lookat->getEyePosition (); 

        // The position of the interest point.
        COLLADABU::Math::Vector3& interestPosition = lookat->getInterestPointPosition(); 

        // The direction that points up. 
        COLLADABU::Math::Vector3& upPosition = lookat->getUpAxisDirection();

        // Create a transform matrix from the lookat elements.
        COLLADABU::Math::Vector3 forward = interestPosition - eyePosition;
        forward.normalise ();
        COLLADABU::Math::Vector3 sideways, upward;
        if ( forward != upPosition && forward != -upPosition)
        {
            sideways = forward.crossProduct ( upPosition );
            sideways.normalise ();
        }
        else if ( upPosition != COLLADABU::Math::Vector3::UNIT_X )
        {
            sideways = COLLADABU::Math::Vector3::UNIT_X;
        }
        else
        {
            sideways = COLLADABU::Math::Vector3::UNIT_Z;
        }
        upward = sideways.crossProduct ( forward );

        // Create the maya transform matrix.
        COLLADABU::Math::Matrix4 mx;
        mx.setElement ( 0, 0, sideways.x );    mx.setElement ( 0, 1, sideways.y );    mx.setElement ( 0, 2, sideways.z );
        mx.setElement ( 1, 0, upward.x );      mx.setElement ( 1, 1, upward.y );      mx.setElement ( 1, 2, upward.z );
        mx.setElement ( 2, 0, -forward.x );    mx.setElement ( 2, 1, -forward.y );    mx.setElement ( 2, 2, -forward.z );
        mx.setElement ( 3, 0, eyePosition.x ); mx.setElement ( 3, 1, eyePosition.y ); mx.setElement ( 3, 2, eyePosition.z );

        mx.setElement ( 0, 3, 0.0f ); mx.setElement ( 1, 3, 0.0f ); mx.setElement ( 2, 3, 0.0f );
        mx.setElement ( 3, 3, 1.0f );

        // Get the translation and write it directly into the maya file.
        COLLADABU::Math::Vector3 trans = mx.getTrans ();
        transformNode->setTranslate ( toLinearUnit ( MayaDM::double3 ( trans.x, trans.y, trans.z ) ) );

        // To get the rotation, we have to remove the scale from the matrix. After this, we have to 
        // check if there is also a shear on the matrix. If not, we can get the rotation.
        COLLADABU::Math::Matrix3 m3x3 = extract3x3MatrixWithNormalizedColumns ( mx );

        // Get the determinant of the matrix. If it is smaller or equal zero, we have to change 
        // the matrix to get the correct rotation.
        double determinant = m3x3.determinant ();
        if ( determinant <= 0 )
        {
            COLLADABU::Math::Matrix3 m3x3Det ( -1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 );
            m3x3 = m3x3 * m3x3Det;
        }

        // Now we can get the rotation and set it into the document.
        double x=0.0, y=0.0, z=0.0;
        m3x3.toEulerAnglesZYX ( z, y, x );
        transformNode->setRotate ( toAngularUnit ( MayaDM::double3 ( x, y, z ) ) );

        // Compute the center of interest distance. We want store it for creating the camera.
        double centerOfInterestDistance = ( interestPosition - eyePosition ).length ();
        const COLLADAFW::UniqueId& transformNodeId = node->getUniqueId ();

        // Set the center of interest distance value in a map to the current transform node.
        mCenterOfInterestDistances [ transformNodeId ] = centerOfInterestDistance;

        return true;
    }

    // --------------------------------------------
    bool VisualSceneImporter::findCenterOfInterestDistance ( 
        const COLLADAFW::UniqueId& transformId, 
        double& centerOfInterestDistance )
    {
        std::map<COLLADAFW::UniqueId, double>::const_iterator it = mCenterOfInterestDistances.find ( transformId );
        if ( it != mCenterOfInterestDistances.end () )
        {
            centerOfInterestDistance = it->second;
            return true;
        }
        return false;
    }

    // --------------------------------------------
    const TransformAnimation* VisualSceneImporter::findTransformAnimation ( 
        const COLLADAFW::UniqueId& animationListId )
    {
        std::map <COLLADAFW::UniqueId, TransformAnimation>::const_iterator it = mTransformAnimationMap.find ( animationListId );
        if ( it != mTransformAnimationMap.end () )
        {
            return &(it->second);
        }
        return 0;
    }

    // --------------------------------------------
    MayaDM::Transform* VisualSceneImporter::findMayaDMTransform ( const COLLADAFW::UniqueId& transformId )
    {
        std::map<COLLADAFW::UniqueId, MayaDM::Transform>::iterator it = mMayaDMTransformMap.find ( transformId );
        if ( it != mMayaDMTransformMap.end () )
        {
            return &(it->second);
        }
        return 0;
    }

    // --------------------------------------------
    const MayaDM::Transform* VisualSceneImporter::findMayaDMTransform ( const COLLADAFW::UniqueId& transformId ) const
    {
        std::map<COLLADAFW::UniqueId, MayaDM::Transform>::const_iterator it = mMayaDMTransformMap.find ( transformId );
        if ( it != mMayaDMTransformMap.end () )
        {
            return &(it->second);
        }
        return 0;
    }

    // --------------------------------------------
    MayaTransform::RotationOrder VisualSceneImporter::getRotationOrder ( 
        const COLLADABU::Math::Vector3 axis1, 
        const COLLADABU::Math::Vector3 axis2, 
        const COLLADABU::Math::Vector3 axis3 )
    {
        // Attention: the order is from behind!
        MayaTransform::RotationOrder order = MayaTransform::kXYZ;

        // X..
        if ( axis1 == COLLADABU::Math::Vector3::UNIT_X ) 
        {
            if ( axis2 == COLLADABU::Math::Vector3::UNIT_Y ) 
            {
                if ( axis3 == COLLADABU::Math::Vector3::UNIT_Z ) 
                {
                    order = MayaTransform::kZYX; // xyz
                }
                else if ( axis3 == COLLADABU::Math::Vector3 (0,0,0) )
                {
                    order = MayaTransform::kZYX; // xy
                }
                else std::cerr << "No valid euler rotation order!" << std::endl;
            }
            else if ( axis2 == COLLADABU::Math::Vector3::UNIT_Z ) 
            {
                if ( axis3 == COLLADABU::Math::Vector3::UNIT_Y )
                {
                    order = MayaTransform::kYZX; // xzy
                }
                else if ( axis3 == COLLADABU::Math::Vector3 (0,0,0) )
                {
                    order = MayaTransform::kZYX; // xz
                }
                else std::cerr << "No valid euler rotation order!" << std::endl;
            }
            else if ( axis2 == COLLADABU::Math::Vector3 (0,0,0) )
            {
                order = MayaTransform::kXYZ; // x
            }
            else std::cerr << "No valid euler rotation order!" << std::endl;
        }

        // Y..
        else if ( axis1 == COLLADABU::Math::Vector3::UNIT_Y ) 
        {
            if ( axis2 == COLLADABU::Math::Vector3::UNIT_X ) 
            {
                if ( axis3 == COLLADABU::Math::Vector3::UNIT_Z ) 
                {
                    order = MayaTransform::kZXY; // yxz
                }
                else if ( axis3 == COLLADABU::Math::Vector3 (0,0,0) )
                {
                    order = MayaTransform::kXYZ; // yx
                }
                else std::cerr << "No valid euler rotation order!" << std::endl;
            }
            else if ( axis2 == COLLADABU::Math::Vector3::UNIT_Z ) 
            {
                if ( axis3 == COLLADABU::Math::Vector3::UNIT_X ) 
                {
                    order = MayaTransform::kXZY; // yzx
                }
                else if ( axis3 == COLLADABU::Math::Vector3 (0,0,0) )
                {
                    order = MayaTransform::kZYX; // yz
                }
                else std::cerr << "No valid euler rotation order!" << std::endl;
            }
            else if ( axis2 == COLLADABU::Math::Vector3 (0,0,0) )
            {
                order = MayaTransform::kXYZ; // y
            }
            else std::cerr << "No valid euler rotation order!" << std::endl;
        }

        // Z..
        else if ( axis1 == COLLADABU::Math::Vector3::UNIT_Z ) 
        {
            if ( axis2 == COLLADABU::Math::Vector3::UNIT_X ) 
            {
                if ( axis3 == COLLADABU::Math::Vector3::UNIT_Y ) 
                {
                    order = MayaTransform::kYXZ; // zxy
                }
                else if ( axis3 == COLLADABU::Math::Vector3 (0,0,0) )
                {
                    order = MayaTransform::kXYZ; // zx
                }
                else std::cerr << "No valid euler rotation order!" << std::endl;
            }
            else if ( axis2 == COLLADABU::Math::Vector3::UNIT_Y ) 
            {
                if ( axis3 == COLLADABU::Math::Vector3::UNIT_X ) 
                {
                    order = MayaTransform::kXYZ; // zyx
                }
                else if ( axis3 == COLLADABU::Math::Vector3 (0,0,0) )
                {
                    order = MayaTransform::kXYZ; // zy
                }
                else std::cerr << "No valid euler rotation order!" << std::endl;
            }
            else if ( axis2 == COLLADABU::Math::Vector3 (0,0,0) )
            {
                order = MayaTransform::kXYZ; // z
            }
            else std::cerr << "No valid euler rotation order!" << std::endl;
        }	
    
        return order;
    }

}
