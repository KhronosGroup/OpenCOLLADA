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
#include "COLLADAMayaGeometryImporter.h"
#include "ColladaMayaException.h"

#include "MayaDMJoint.h"

#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWTranslate.h"

#include "Math/COLLADABUMathMatrix4.h"

#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MVector.h>


namespace COLLADAMaya
{
    
    // -----------------------------------
    VisualSceneImporter::VisualSceneImporter ( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
    {}

    // -----------------------------------
    bool VisualSceneImporter::importVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
        String visualSceneName = visualScene->getName ();

        // Iterate over the root nodes of the current visual scene
        const COLLADAFW::NodeArray& rootNodes = visualScene->getRootNodes ();
        size_t count = rootNodes.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            COLLADAFW::Node* rootNode = rootNodes [i];
            importNode ( rootNode );

//             // Set the node visible
//             DagHelper::setPlugValue( transformObject, ATTR_VISIBILITY, true );
        }

        return true;
    }

    // -----------------------------------
    bool VisualSceneImporter::readGeometryInstances (
        MayaDM::Transform* transformNode, 
        const COLLADAFW::Node* node )
    {
        bool singleGeometryInstance = node->getInstanceGeometries().getCount() == 1;

        // Get the unique id of the current node.
        const COLLADAFW::UniqueId& nodeId = node->getUniqueId ();

        // Go through the geometry instances and save the geometry ids to the current node.
        const COLLADAFW::InstanceGeometryArray& geometryInstances = node->getInstanceGeometries ();
        size_t numInstances = geometryInstances.getCount ();
        for ( size_t i=0; i<numInstances; ++i )
        {
            const COLLADAFW::InstanceGeometry* instanceGeometry = geometryInstances [i];
            const COLLADAFW::UniqueId& geometryId = instanceGeometry->getInstanciatedObjectId ();

            // Save for every geometry a list of transform nodes, which refer to it.
            mGeometryNodesMap [ geometryId ].insert ( nodeId );
        }

        return true;
    }

    // -----------------------------------
    bool VisualSceneImporter::importTransformations ( 
        MayaDM::Transform* transformNode, 
        const COLLADAFW::Node* rootNode )
    {
        // Get the current maya ascii file to write the data.
        FILE* file = getDocumentImporter ()->getFile ();

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
                break;
            case COLLADAFW::Transformation::MATRIX:
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

                    // Write the current rotation in a quaternion and 
                    // multiplicate with the existing rotation.
                    COLLADAFW::Scale* scale = ( COLLADAFW::Scale* )transform;
                    COLLADABU::Math::Vector3& scaleVec = scale->getScale ();
                    for ( size_t j=0; j<3; ++j )
                        mayaTransform.scale[j] *= scaleVec[j];
                }
                else validMayaTransform = false;
                break;
            case COLLADAFW::Transformation::SKEW:
                break;
            case COLLADAFW::Transformation::TRANSLATE:
                {
                    // Set the actual phase to a scale phase.
                    if ( ( mayaTransform.phase != MayaTransformation::PHASE_TRANS1 ) && 
                         ( mayaTransform.phase != MayaTransformation::PHASE_TRANS2 ) && 
                         ( mayaTransform.phase != MayaTransformation::PHASE_TRANS3 ) )
                    {
                        mayaTransform.phase += 1;
                    }

                    // Write the current rotation in a quaternion and 
                    // multiplicate with the existing rotation.
                    COLLADAFW::Translate* translate = ( COLLADAFW::Translate* )transform;
                    COLLADABU::Math::Vector3 translation = translate->getTranslation ();
                    if ( mayaTransform.phase == MayaTransformation::PHASE_TRANS1 )
                    {
                        for ( size_t j=0; j<3; ++j )
                            mayaTransform.translate1[j] += translation [j];
                    }
                    else if ( mayaTransform.phase == MayaTransformation::PHASE_TRANS2 )
                    {
                        for ( size_t j=0; j<3; ++j )
                            mayaTransform.translate2[j] += translation [j];
                    }
                    else if ( mayaTransform.phase == MayaTransformation::PHASE_TRANS3 )
                    {
                        for ( size_t j=0; j<3; ++j )
                            mayaTransform.translate3[j] += translation [j];
                    }
                }
                break;
            default:
                break;
            }
        }
        
        if ( validMayaTransform )
        {
            // Write the transformations directly into the maya file.
            std::vector<double> mayaTranslate3 = mayaTransform.translate3;
            MVector translate3 ( mayaTranslate3 [0], mayaTranslate3 [1], mayaTranslate3 [2] );
            MVector inverseScalePivot ( mayaTranslate3 [0], mayaTranslate3 [1], mayaTranslate3 [2] );
            MVector scalePivot = inverseScalePivot * (-1);

            std::vector<double> mayaTranslate2 = mayaTransform.translate2;
            MVector translate2 ( mayaTranslate2 [0], mayaTranslate2 [1], mayaTranslate2 [2] );
            MVector inverseRotatePivot = translate2 - translate3;
            MVector rotatePivot = inverseRotatePivot * (-1);

            std::vector<double> mayaTranslate1 = mayaTransform.translate1;
            MVector translate1 ( mayaTranslate1 [0], mayaTranslate1 [1], mayaTranslate1 [2] );
            MVector translate = translate1 - rotatePivot;
            MVector tester = translate1 + translate2 + translate3;

            MQuaternion mayaRotate = mayaTransform.rotation;
            MEulerRotation eulerRotation = mayaRotate.asEulerRotation ();
            MEulerRotation::RotationOrder order = eulerRotation.order;
            MVector rotation = eulerRotation.asVector ();

            std::vector<double> mayaScale = mayaTransform.scale;
            MVector scale ( mayaScale[0], mayaScale[1], mayaScale[2] );

            if ( translate != MVector (0, 0, 0) )
                transformNode->setTranslate ( MayaDM::double3 ( translate.x, translate.y, translate.z ) );
            if ( rotation != MVector (0, 0, 0) )
                transformNode->setRotate ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg(rotation.x), COLLADABU::Math::Utils::radToDeg(rotation.y), COLLADABU::Math::Utils::radToDeg(rotation.z) ) );
            if ( scale != MVector (1, 1, 1) )
                transformNode->setScale ( MayaDM::double3 ( mayaScale[0], mayaScale[1], mayaScale[2] ) );

            // TODO Maya only knows skews around the x, y or z axis as shears, no free axes.
            // So we only import skews around the standard axes, others will be ignored.
//             if (IsEquivalent(t->GetRotateAxis(), FMVector3::XAxis) && IsEquivalent(t->GetAroundAxis(), FMVector3::YAxis)) wantedBucket = SKEW_XY;
//             else if (IsEquivalent(t->GetRotateAxis(), FMVector3::XAxis) && IsEquivalent(t->GetAroundAxis(), FMVector3::ZAxis)) wantedBucket = SKEW_XZ;
//             else if (IsEquivalent(t->GetRotateAxis(), FMVector3::YAxis) && IsEquivalent(t->GetAroundAxis(), FMVector3::ZAxis)) wantedBucket = SKEW_YZ;
//            transformNode->setShear ( MayaDM::double3 ( translate.x, translate.y, translate.z ) );

            if ( rotatePivot != MVector (0, 0, 0) )
                transformNode->setRotatePivot ( MayaDM::double3 ( rotatePivot.x, rotatePivot.y, rotatePivot.z ) );
            if ( scalePivot != MVector (0, 0, 0) )
                transformNode->setScalePivot ( MayaDM::double3 ( scalePivot.x, scalePivot.y, scalePivot.z ) );

            if ( order != MEulerRotation::kXYZ )
                transformNode->setRotateOrder ( order );
        }
        else
        {
            // Set the transform matrix to the transform object
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
            transformNode->setRotate ( MayaDM::double3 ( rotation[0], rotation[1], rotation[2] ) );

            double scale[3];
            tm.getScale ( scale, MSpace::kTransform );
            transformNode->setScale ( MayaDM::double3 ( scale[0], scale[1], scale[2] ) );

            double shear[3];
            tm.getShear ( shear, MSpace::kTransform );
            transformNode->setShear ( MayaDM::double3 ( shear[0], shear[1], shear[2] ) );

        }
        return true;
    }

    // -----------------------------------
    void VisualSceneImporter::convertMatrix4ToTransposedDouble4x4( const COLLADABU::Math::Matrix4& inputMatrix, double outputMatrix[][4] )
    {
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][0])) outputMatrix[0][0] = 0.0;
        else outputMatrix[0][0] = inputMatrix[0][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][1])) outputMatrix[1][0] = 0.0;
        else outputMatrix[1][0] = inputMatrix[0][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][2])) outputMatrix[2][0] = 0.0;
        else outputMatrix[2][0] = inputMatrix[0][2];
        outputMatrix[3][0] = 0;

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][0])) outputMatrix[0][1] = 0.0;
        else outputMatrix[0][1] = inputMatrix[1][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][1])) outputMatrix[1][1] = 0.0;
        else outputMatrix[1][1] = inputMatrix[1][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][2])) outputMatrix[2][1] = 0.0;
        else outputMatrix[2][1] = inputMatrix[1][2];
        outputMatrix[3][1] = 0;

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][0])) outputMatrix[0][2] = 0.0;
        else outputMatrix[0][2] = inputMatrix[2][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][1])) outputMatrix[1][2] = 0.0;
        else outputMatrix[1][2] = inputMatrix[2][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][2])) outputMatrix[2][2] = 0.0;
        else outputMatrix[2][2] = inputMatrix[2][2];
        outputMatrix[3][2] = 0;

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][0])) outputMatrix[0][3] = 0.0;
        else outputMatrix[0][3] = inputMatrix[3][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][1])) outputMatrix[1][3] = 0.0;
        else outputMatrix[1][3] = inputMatrix[3][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][2])) outputMatrix[2][3] = 0.0;
        else outputMatrix[2][3] = inputMatrix[3][2];
        outputMatrix[3][3] = 1;
    }

    // -----------------------------------
    void VisualSceneImporter::importNode ( 
        const COLLADAFW::Node* node, 
        const COLLADAFW::UniqueId* parentNodeId )
    {
        String nodeName = node->getName ();
        String nodeSid = node->getSid ();
        
        mNodeNamesMap [ node->getUniqueId () ] = nodeName;

        // Get the current maya ascii file to write the data.
        FILE* file = getDocumentImporter ()->getFile ();

        // Create a transform node of the specific type.
        MayaDM::Transform* transformNode;

        // Check for a parent node name
        String parentNodeName = "";
        if ( parentNodeId != 0 )
        {
            parentNodeName = mNodeNamesMap [ *parentNodeId ];
        }

        COLLADAFW::Node::NodeType nodeType = node->getType ();
        switch ( nodeType )
        {
        case COLLADAFW::Node::JOINT:
            {
                transformNode = new MayaDM::Joint ( file, nodeName.c_str (), parentNodeName );
                String message = "VisualSceneImporter::importVisualScene :: Transform type JOINT not implemented!";
                std::cerr << message << std::endl;
                throw new ColladaMayaException ( message );
                break;
            }
        case COLLADAFW::Node::NODE:
            {
                // Create the transform node of the current root node.
                transformNode = new MayaDM::Transform ( file, nodeName.c_str (), parentNodeName );
                break;
            }
        default:
            String message = "Not a valid node type!";
            MGlobal::displayError ( message.c_str () );
            std::cerr << message << std::endl;
            throw new ColladaMayaException ( message );
        }

        // Import the tranformations
        importTransformations ( transformNode, node );

        // Import instance geometry
        readGeometryInstances ( transformNode, node );

        // Recursive call for all child elements.
        const COLLADAFW::NodeArray& childNodes = node->getChildNodes ();
        size_t numChildNodes = childNodes.getCount ();
        for ( size_t i=0; i<numChildNodes; ++i )
        {
            COLLADAFW::Node* childNode = childNodes [i];
            importNode ( childNode, &node->getUniqueId () );
        }
    }
}