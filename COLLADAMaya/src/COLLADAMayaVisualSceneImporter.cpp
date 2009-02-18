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
#include "COLLADAMayaVisualSceneImporter.h"
#include "COLLADAMayaDocumentImporter.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaMaterialImporter.h"

#include "MayaDMJoint.h"
#include "MayaDMDependNode.h"
#include "MayaDMCommands.h"

#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWTranslate.h"
#include "COLLADAFWLookat.h"

#include "Math/COLLADABUMathMatrix4.h"

#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MVector.h>

#include <vector>


namespace COLLADAMaya
{
    
    const String VisualSceneImporter::TRANSFORM_NODE_NAME = "Transform";


    // -----------------------------------
    VisualSceneImporter::VisualSceneImporter ( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
    {}

    // -----------------------------------
    bool VisualSceneImporter::importVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
        // Iterate over the root nodes of the current visual scene
        const COLLADAFW::NodeArray& rootNodes = visualScene->getRootNodes ();
        size_t count = rootNodes.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            COLLADAFW::Node* rootNode = rootNodes [i];
            importNode ( rootNode );
        }

        // Write all the node instances
        writeNodeInstances ();

        return true;
    }

    // -----------------------------------
    void VisualSceneImporter::importNode ( 
        const COLLADAFW::Node* node, 
        const COLLADAFW::UniqueId* parentTransformNodeId )
    {

        // Check for a parent node name
        MayaNode* parentMayaNode = NULL;
        String parentNodeName = ""; 
        if ( parentTransformNodeId != NULL ) 
        {
            parentMayaNode = findMayaTransformNode ( *parentTransformNodeId );
            assert ( parentMayaNode != NULL );
            parentNodeName = parentMayaNode->getName ();
        }

        // Get the unique node name
        String nodeName = node->getName ();
        if ( COLLADABU::Utils::equals ( nodeName, "" ) )
            nodeName = TRANSFORM_NODE_NAME;
        nodeName = DocumentImporter::frameworkNameToMayaName ( nodeName );
        nodeName = mTransformNodeIdList.addId ( nodeName );

        // Create the node object (joint or node)
        MayaDM::Transform* transformNode = createNode ( node, nodeName, parentNodeName );

        // Create a maya node object of the current node and push it into the map.
        const COLLADAFW::UniqueId& transformNodeId = node->getUniqueId ();
        MayaNode mayaNode ( transformNodeId, nodeName, parentMayaNode );
        mMayaTransformNodesMap [ transformNodeId ] = mayaNode;

        // Import the tranformations.
        importTransformations ( node, transformNode );

        // Import the instances.
        readNodeInstances ( node );
        readGeometryInstances ( node );
        readCameraInstances ( node );
        readLightInstances ( node );

        // Recursive call for all child elements.
        const COLLADAFW::NodeArray& childNodes = node->getChildNodes ();
        size_t numChildNodes = childNodes.getCount ();
        for ( size_t i=0; i<numChildNodes; ++i )
        {
            COLLADAFW::Node* childNode = childNodes [i];
            importNode ( childNode, &transformNodeId );
        }

        delete transformNode;
    }

    // -----------------------------------
    bool VisualSceneImporter::importTransformations ( 
        const COLLADAFW::Node* rootNode, 
        MayaDM::Transform* transformNode )
    {
        // This is the order of the transforms:
        //
        // matrix = [SP-1 * S * SH * SP * ST] * [RP-1 * RA * R * JO * RP * RT] * T
        //          [        scale          ] * [          rotation          ] * translation
        //
        // Where SP is scale pivot translation, S is scale, SH is shear, ST is scale pivot translation
        // RP is rotation pivot, RA is rotation axis, R is rotation, RP is rotation pivot,
        // RT is rotation pivot translation, T is translation, JO is joint orientation
        //
        // references: Maya documentation - transform node, Maya documentation - joint node
        // NOTE: Left multiplying, column-order matrices
        //

        // Go through the transforms and try to fill the maya transformation. 
        // This just works, if the framework has the transformations in any order of the style
        // T* R* T* S* T*, if the order differs from, we have to transform with a matrix (but 
        // with matrix transformation is no animation possible).
        MayaTransformation mayaTransform;

        bool hasRotatePivot = false;
        bool hasScalePivot = false;

        bool validMayaTransform = 
            isValidMayaTransform ( rootNode, mayaTransform, hasRotatePivot, hasScalePivot );
        if ( validMayaTransform )
        {
            // Set the transform values.
            importDecomposedTransform ( mayaTransform, transformNode, hasRotatePivot, hasScalePivot );
        }
        else
        {
            // Set the transform matrix to the transform object
            importMatrixTransform ( rootNode, transformNode );
        }
        return true;
    }

    // -----------------------------------
    void VisualSceneImporter::convertMatrix4ToTransposedDouble4x4 ( 
        const COLLADABU::Math::Matrix4& inputMatrix, 
        double outputMatrix[][4] )
    {
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][0])) outputMatrix[0][0] = 0.0;
        else outputMatrix[0][0] = inputMatrix[0][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][1])) outputMatrix[1][0] = 0.0;
        else outputMatrix[1][0] = inputMatrix[0][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][2])) outputMatrix[2][0] = 0.0;
        else outputMatrix[2][0] = inputMatrix[0][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][3])) outputMatrix[3][0] = 0.0;
        else outputMatrix[3][0] = inputMatrix[0][3];
//        outputMatrix[3][0] = 0;

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][0])) outputMatrix[0][1] = 0.0;
        else outputMatrix[0][1] = inputMatrix[1][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][1])) outputMatrix[1][1] = 0.0;
        else outputMatrix[1][1] = inputMatrix[1][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][2])) outputMatrix[2][1] = 0.0;
        else outputMatrix[2][1] = inputMatrix[1][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][3])) outputMatrix[3][1] = 0.0;
        else outputMatrix[3][1] = inputMatrix[1][3];
//        outputMatrix[3][1] = 0;

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][0])) outputMatrix[0][2] = 0.0;
        else outputMatrix[0][2] = inputMatrix[2][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][1])) outputMatrix[1][2] = 0.0;
        else outputMatrix[1][2] = inputMatrix[2][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][2])) outputMatrix[2][2] = 0.0;
        else outputMatrix[2][2] = inputMatrix[2][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][3])) outputMatrix[3][2] = 0.0;
        else outputMatrix[3][2] = inputMatrix[2][3];
//        outputMatrix[3][2] = 0;

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][0])) outputMatrix[0][3] = 0.0;
        else outputMatrix[0][3] = inputMatrix[3][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][1])) outputMatrix[1][3] = 0.0;
        else outputMatrix[1][3] = inputMatrix[3][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][2])) outputMatrix[2][3] = 0.0;
        else outputMatrix[2][3] = inputMatrix[3][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][3])) outputMatrix[3][3] = 0.0;
        else outputMatrix[3][3] = inputMatrix[3][3];
//        outputMatrix[3][3] = 1;
    }

    // -----------------------------------
    void VisualSceneImporter::importMatrixTransform ( 
        const COLLADAFW::Node* rootNode, 
        MayaDM::Transform* transformNode )
    {
        COLLADABU::Math::Matrix4 transformMatrix;
        rootNode->getTransformationMatrix ( transformMatrix );
        double mtx[4][4];
        convertMatrix4ToTransposedDouble4x4 ( transformMatrix, mtx );
        MMatrix matrix ( mtx );
        MTransformationMatrix tm ( matrix );

        MStatus status;
        MVector transVec = tm.getTranslation ( MSpace::kTransform, &status );
        transformNode->setTranslate ( MayaDM::double3 ( transVec.x, transVec.y, transVec.z ));

        double rotation[3];
        MTransformationMatrix::RotationOrder order;
        tm.getRotation ( rotation, order, MSpace::kTransform );
        if ( ! ( MVector (0,0,0) == MVector ( rotation ) ) )
            transformNode->setRotate ( MayaDM::double3 ( rotation[0], rotation[1], rotation[2] ) );

        double scale[3];
        tm.getScale ( scale, MSpace::kTransform );
        if ( ! ( MVector (1,1,1) == MVector ( scale ) ) )
            transformNode->setScale ( MayaDM::double3 ( scale[0], scale[1], scale[2] ) );

        double shear[3];
        tm.getShear ( shear, MSpace::kTransform );
        if ( ! ( MVector (0,0,0) == MVector ( shear ) ) )
            transformNode->setShear ( MayaDM::double3 ( shear[0], shear[1], shear[2] ) );
    }

    // -----------------------------------
    MayaDM::Transform* VisualSceneImporter::createNode ( 
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
                String message = "VisualSceneImporter::importVisualScene :: Transform type JOINT not implemented!";
                std::cerr << message << std::endl;
                MGlobal::displayError ( message.c_str () );
                assert ( "Transform type JOINT not implemented!" );
                break;
            }
        case COLLADAFW::Node::NODE:
            {
                // Create the transform node of the current root node.
                transformNode = new MayaDM::Transform ( file, nodeName.c_str (), parentNodeName );
                break;
            }
        default:
            std::cerr << "Not a valid node type!" << std::endl;
            MGlobal::displayError ("Not a valid node type!" );
            assert ( "Not a valid node type!" );
        }

        return transformNode;
    }

    // -----------------------------------
    bool VisualSceneImporter::isValidMayaTransform ( 
        const COLLADAFW::Node* rootNode, 
        MayaTransformation& mayaTransform, 
        bool& hasRotatePivot,
        bool& hasScalePivot )
    {
        bool validMayaTransform = true;

        const COLLADAFW::TransformationArray& transforms = rootNode->getTransformations ();
        size_t numTransforms = transforms.getCount ();
        for ( size_t i=0; i<numTransforms && validMayaTransform; ++i )
        {
            const COLLADAFW::Transformation* transform = transforms [i];
            COLLADAFW::Transformation::TransformationType transformType; 
            transformType = transform->getTransformationType ();

            switch ( transformType )
            {
            case COLLADAFW::Transformation::LOOKAT:
                // TODO
                {
                    /**
                    * Positioning and orienting a camera or object in the scene is often 
                    * complicated when using a matrix. A lookat transform is an intuitive 
                    * way to specify an eye position, interest point, and orientation.
                    */
                    COLLADAFW::Lookat* lookat = ( COLLADAFW::Lookat* )transform;

                    /** The position of the object. */
                    COLLADABU::Math::Vector3& eyePosition = lookat->getEyePosition (); 
                    /** The position of the interest point. */
                    COLLADABU::Math::Vector3& interestPosition = lookat->getInterestPointPosition(); 
                    /** The direction that points up. */
                    COLLADABU::Math::Vector3& upPosition = lookat->getUpAxisDirection();

                    // TODO Do anything with this values!

                    assert ("Lookat not implemented!");

                    validMayaTransform = false;
                    break;
                }
            case COLLADAFW::Transformation::MATRIX:
                // Nothing to do, the matrix will be read automatically.
                validMayaTransform = false;
                break;
            case COLLADAFW::Transformation::ROTATE:
                {
                    if ( mayaTransform.phase <= MayaTransformation::PHASE_ROTATE )
                    {
                        // Set the actual phase to a rotate phase.
                        mayaTransform.phase = MayaTransformation::PHASE_ROTATE;

                        // Write the current rotation in a quaternion and 
                        // multiplicate with the existing rotation.
                        COLLADAFW::Rotate* rotation = ( COLLADAFW::Rotate* )transform;
                        double angle = rotation->getRotationAngle ();
                        COLLADABU::Math::Vector3& axis = rotation->getRotationAxis ();
                        MVector mayaAxis ( axis.x, axis.y, axis.z );
                        MQuaternion quaternion ( COLLADABU::Math::Utils::degToRad(angle), mayaAxis );

                        // The order of the multiplication is deciding!
                        mayaTransform.rotation = quaternion * mayaTransform.rotation;
                    }
                    else validMayaTransform = false;
                }
                break;
            case COLLADAFW::Transformation::SCALE:
                if ( mayaTransform.phase <= MayaTransformation::PHASE_SCALE )
                {
                    // Set the actual phase to a scale phase.
                    mayaTransform.phase = MayaTransformation::PHASE_SCALE;

                    COLLADAFW::Scale* scale = ( COLLADAFW::Scale* )transform;
                    COLLADABU::Math::Vector3& scaleVec = scale->getScale ();
                    for ( unsigned int k=0; k<3; ++k )
                        mayaTransform.scale [k] = scaleVec [k];
                }
                else validMayaTransform = false;
                break;
            case COLLADAFW::Transformation::SKEW:
                {
                    COLLADAFW::Skew* skew = ( COLLADAFW::Skew* )transform;

                    MMatrix matrix;
                    skewValuesToMayaMatrix ( skew, matrix );
                    MTransformationMatrix tm ( matrix );

                    double shear[3];
                    tm.getShear ( shear, MSpace::kTransform );

                    for ( unsigned int k=0; k<3; ++k )
                        mayaTransform.skew [k] = shear [k];
                    break;
                }
            case COLLADAFW::Transformation::TRANSLATE:
                {
                    // Set the actual phase to a scale phase.
                    if ( ( mayaTransform.phase != MayaTransformation::PHASE_TRANS1 ) && 
                        ( mayaTransform.phase != MayaTransformation::PHASE_TRANS2 ) && 
                        ( mayaTransform.phase != MayaTransformation::PHASE_TRANS3 ) )
                    {
                        mayaTransform.phase += 1;
                    }

                    COLLADAFW::Translate* translate = ( COLLADAFW::Translate* )transform;
                    COLLADABU::Math::Vector3 translation = translate->getTranslation ();
                    if ( mayaTransform.phase == MayaTransformation::PHASE_TRANS1 )
                    {
                        mayaTransform.translate1Vec.push_back ( MVector (translation[0],translation[1],translation[2] ) );
                        ++mayaTransform.numTranslate1;
                        for ( unsigned int j=0; j<3; ++j )
                            mayaTransform.translate1[j] += translation [j];
                    }
                    else if ( mayaTransform.phase == MayaTransformation::PHASE_TRANS2 )
                    {
                        mayaTransform.translate2Vec.push_back ( MVector (translation[0],translation[1],translation[2] ) );
                        ++mayaTransform.numTranslate2;
                        for ( unsigned int j=0; j<3; ++j )
                            mayaTransform.translate2[j] += translation [j];
                    }
                    else if ( mayaTransform.phase == MayaTransformation::PHASE_TRANS3 )
                    {
                        mayaTransform.translate3Vec.push_back ( MVector (translation[0],translation[1],translation[2] ) );
                        ++mayaTransform.numTranslate3;
                        for ( unsigned int j=0; j<3; ++j )
                            mayaTransform.translate3[j] += translation [j];
                    }
                }
                break;
            default:
                std::cerr << "Unknown transformation type!" << endl;
                MGlobal::displayError ( "Unknown transformation type!" );
                assert ( "Unknown transformation type!" );
                break;
            }
        }

        if ( validMayaTransform )
        {
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
                MVector scalePivotInverse = mayaTransform.translate3Vec[0];

                // If we have a scalePivotInverse, we need minimum one translate2 vector. 
                // The last translate2 vector has to be the scalePivot. 
                MVector scalePivot (0,0,0);
                if ( numTranslate2Vec > 0 )
                {
                    // The last translate2 vector has to be the scalePivot. 
                    scalePivot = mayaTransform.translate2Vec[numTranslate2Vec-1];
                }
                else
                {
                    // Except we don't have a rotation... 
                    // Then the scalePivot is the last translate1 vector.
                    // The last translate2 vector has to be the scalePivot. 
                    scalePivot = mayaTransform.translate1Vec[numTranslate1Vec-1];
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
                    MVector rotatePivotInverse = mayaTransform.translate2Vec[0];

                    // The last translate1 vector has to be the rotatePivot. 
                    MVector rotatePivot = mayaTransform.translate1Vec[numTranslate1Vec-1];

                    // Check, if the vectors are inverse.
                    if ( ( rotatePivot * (-1) ) != rotatePivotInverse )
                    {
                        validMayaTransform = false;
                        return validMayaTransform;
                    }
                    hasRotatePivot = true;
                }
            }
        }

        return validMayaTransform;
    }

    // -----------------------------------
    void VisualSceneImporter::importDecomposedTransform ( 
        const MayaTransformation &mayaTransform, 
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

        MVector scalePivot (0,0,0);
        MVector scalePivotTranslate (0,0,0);

        MVector rotatePivot (0,0,0);
        MVector rotatePivotTranslate (0,0,0);

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
        MVector translate1 = mayaTransform.translate1;
        MVector translate2 = mayaTransform.translate2;
        MVector translate3 = mayaTransform.translate3;
        MVector translate = translate1 + translate2 + translate3 - scalePivotTranslate - rotatePivotTranslate;

        MQuaternion mayaRotate = mayaTransform.rotation;
        MEulerRotation eulerRotation = mayaRotate.asEulerRotation ();
        MEulerRotation::RotationOrder order = eulerRotation.order;
        MVector rotation = eulerRotation.asVector ();

        MVector scale = mayaTransform.scale;
        MVector skew = mayaTransform.skew;

        // Write the transformations directly into the maya file.
        if ( translate != MVector (0, 0, 0) )
            transformNode->setTranslate ( toLinearUnit ( MayaDM::double3 ( translate.x , translate.y, translate.z ) ) );
        if ( rotation != MVector (0, 0, 0) )
            transformNode->setRotate ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg(rotation.x), COLLADABU::Math::Utils::radToDeg(rotation.y), COLLADABU::Math::Utils::radToDeg(rotation.z) ) );
        if ( scale != MVector (1, 1, 1) )
            transformNode->setScale ( MayaDM::double3 ( scale[0], scale[1], scale[2] ) );

        if ( skew != MVector (0, 0, 0))
            transformNode->setShear ( MayaDM::double3 ( skew.x, skew.y, skew.z ) );

        if ( rotatePivot != MVector (0, 0, 0) )
            transformNode->setRotatePivot ( toLinearUnit ( MayaDM::double3 ( rotatePivot.x, rotatePivot.y, rotatePivot.z ) ) );
        if ( rotatePivotTranslate != MVector (0, 0, 0) )
            transformNode->setRotatePivotTranslate ( toLinearUnit ( MayaDM::double3 ( rotatePivotTranslate.x, rotatePivotTranslate.y, rotatePivotTranslate.z ) ) );

        if ( scalePivot != MVector (0, 0, 0) )
            transformNode->setScalePivot ( toLinearUnit ( MayaDM::double3 ( scalePivot.x, scalePivot.y, scalePivot.z ) ) );
        if ( scalePivotTranslate != MVector (0, 0, 0) )
            transformNode->setScalePivotTranslate ( toLinearUnit ( MayaDM::double3 ( scalePivotTranslate.x, scalePivotTranslate.y, scalePivotTranslate.z ) ) );
        
        if ( order != MEulerRotation::kXYZ )
            transformNode->setRotateOrder ( order );
    }

    // -----------------------------------
    void VisualSceneImporter::skewValuesToMayaMatrix ( 
        const COLLADAFW::Skew* skew, MMatrix& matrix ) const
    {
        float s = tanf ( COLLADABU::Math::Utils::degToRadF ( skew->getAngle () ) );

        const COLLADABU::Math::Vector3& rotateAxis = skew->getRotateAxis();
        const COLLADABU::Math::Vector3& translateAxis = skew->getRotateAxis();

        for ( int row = 0; row < 3; ++row )
        {
            for ( int col = 0; col < 3; ++col )
            {
                matrix[col][row] = ((row == col) ? 1.0f : 0.0f) + s * (float)rotateAxis [col] * (float)translateAxis [row];
            }
        }

        matrix[0][3] = matrix[1][3] = matrix[2][3] = 0.0f;
        matrix[3][0] = matrix[3][1] = matrix[3][2] = 0.0f;
        matrix[3][3] = 1.0f;
    }

    // -----------------------------------
    const MayaNode* VisualSceneImporter::findMayaTransformNode ( 
        const COLLADAFW::UniqueId& uniqueId ) const
    {
        UniqueIdMayaNodesMap::const_iterator it = mMayaTransformNodesMap.find ( uniqueId );
        if ( it != mMayaTransformNodesMap.end () )
            return &(*it).second;

        return 0;
    }

    // -----------------------------------
    MayaNode* VisualSceneImporter::findMayaTransformNode ( const COLLADAFW::UniqueId& uniqueId )
    {
        UniqueIdMayaNodesMap::iterator it = mMayaTransformNodesMap.find ( uniqueId );
        if ( it != mMayaTransformNodesMap.end () )
            return &(*it).second;

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
    void VisualSceneImporter::writeNodeInstances ()
    {
        UniqueIdUniqueIdsMap::iterator it = mTransformInstancesMap.begin ();
        while ( it != mTransformInstancesMap.end() )
        {
            const COLLADAFW::UniqueId& instanceNodeId = it->first;

            BaseImporter::UniqueIdVec& parentNodes = it->second;
            size_t numInstances = parentNodes.size ();
            for ( size_t i=0; i<numInstances; ++i )
            {
                const COLLADAFW::UniqueId& parentNodeId = parentNodes [i];

                // TODO Check if the original node is already generated!
                MayaNode* mayaChildNode = findMayaTransformNode ( instanceNodeId );
                if ( mayaChildNode == 0 )
                {
                    MGlobal::displayError ( "The referenced transform node doesn't exist!" );
                    std::cerr << "The referenced transform node doesn't exist!" << endl;
                }
                String childNodeName = mayaChildNode->getName ();
                String childNodePath = mayaChildNode->getNodePath ();

                // Get the pathes.
                MayaNode* mayaParentNode = findMayaTransformNode ( parentNodeId );
                String parentNodePath = mayaParentNode->getNodePath ();

                // parent -shape -noConnections -relative -addObject "|node1|node2" "|rootNode";
                FILE* file = getDocumentImporter ()->getFile ();
                MayaDM::parentShape ( file, childNodePath, parentNodePath, false, true, true, true  );
            }

            ++it;
        }
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
    void VisualSceneImporter::readMaterialInstances ( 
        const COLLADAFW::UniqueId& transformNodeId, 
        const COLLADAFW::InstanceGeometry* instanceGeometry )
    {
        // Get the material importer
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();

        // Go through the bound materials
        const COLLADAFW::InstanceGeometry::MaterialBindingArray& materialBindingsArray = instanceGeometry->getMaterialBindings ();
        size_t numOfBindings = materialBindingsArray.getCount ();
        for ( size_t i=0; i<numOfBindings; ++i )
        {
            const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding = materialBindingsArray [i];

            // Write the shader data into the maya file.
            materialImporter->writeShaderData ( materialBinding, transformNodeId, instanceGeometry );
        }
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
}