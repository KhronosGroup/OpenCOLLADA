/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"

#include "COLLADAMayaVisualSceneExporter.h"
#include "assert.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaConvert.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaSyntax.h"

#include <maya/MFnIkHandle.h>
#include <maya/MFnMesh.h>
#include <maya/MFnSkinCluster.h>
#include <maya/MItDag.h>
#include <maya/MFnIkJoint.h>
#include <maya/MQuaternion.h>
#include <maya/MEulerRotation.h>
#include <maya/MDagPath.h>
#include <maya/MFnCamera.h>

#include "COLLADANode.h"
#include "COLLADAInstanceGeometry.h"
#include "COLLADAMathUtils.h"


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    VisualSceneExporter::VisualSceneExporter ( COLLADA::StreamWriter* _streamWriter,
            DocumentExporter* _documentExporter,
            const String& _sceneId )
            : COLLADA::LibraryVisualScenes ( _streamWriter ),
            mDocumentExporter ( _documentExporter ),
            mSceneId ( _sceneId )
    {
        visualSceneAdded = false;
        isJoint = false;
        isFirstRotation = true;
        mVisualSceneNode = NULL;
    }


    //---------------------------------------------------------------
    void VisualSceneExporter::openVisualSceneNode ( const MDagPath &dagPath )
    {
        // get the node ID and name
        String nodeID = mDocumentExporter->dagPathToColladaId ( dagPath ).asChar();
        String nodeName = mDocumentExporter->dagPathToColladaName ( dagPath ).asChar();

        // Create the scene node
        mVisualSceneNode->setId ( nodeID );
        mVisualSceneNode->setNodeName ( nodeName );
        mVisualSceneNode->setType ( COLLADA::Node::NODE );

        // open the scene node
        mVisualSceneNode->start();
    }

    // ------------------------------------------------------------
    void VisualSceneExporter::exportVisualScenes()
    {
        // Get the sceneID
        String sceneID = SceneGraph::SCENE_ID;

        // Assign a name to the scene
        MString sceneName;
        MGlobal::executeCommand ( MString ( "file -q -ns" ), sceneName );

        if ( sceneName.length() != 0 ) sceneID = sceneName.asChar();

        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();

        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // The flag, if a node was exported and the visual scene tags must to be closed
        bool nodeExported = false;

        bool isLocal = true;

        // Export all/selected DAG nodes
        uint length = exportNodesTree->size();

        for ( uint i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            const MDagPath dagPath = sceneElement->getPath();
            MFnDependencyNode fn ( dagPath.node() );
            String theNodeName = fn.name().asChar();

            // Exports all the nodes in a node and all its child nodes recursive

            if ( exportVisualSceneNodes ( sceneElement, isLocal ) ) nodeExported = true;
        }

        // Just if a node was exported, the visual scene tag
        // in the collada document is open and should be closed.

        if ( nodeExported ) closeVisualScene();

        closeLibrary();

        // TODO
        // Setup the reference information
        // GetReferenceManager()->Synchronize();

    }

    // ---------------------------------------------------------------
    // Exports all the nodes in a node and all its child nodes recursive
    bool VisualSceneExporter::exportVisualSceneNodes ( SceneElement* sceneElement, bool &isLocal )
    {
        const MDagPath dagPath = sceneElement->getPath();
        MFn::Type type = dagPath.apiType();

        // Check if the element isn't already exported
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        bool hasPreviousInstance = sceneGraph->findElement ( dagPath ) != NULL;

        // Attach a function set
        MFnDependencyNode fn ( dagPath.node() );
        String nodeNameCollada = mDocumentExporter->mayaNameToColladaName ( fn.name(), true ).asChar();

        // The unique ID
        String meshId = /*GEOMETRY_ID_PRAEFIX +*/ nodeNameCollada;

        // The transform node
        MStatus status;
        MObject transformNode = dagPath.transform ( &status );

        if ( ( status != MS::kSuccess ) && status.statusCode () == MStatus::kInvalidParameter ) return false;

        MFnDagNode transform ( transformNode, &status );

        if ( !status )
        {
            status.perror ( "MFnDagNode constructor" );
            return false;
        }

        bool isForced = false;

        bool isVisible = false;

        if ( !sceneGraph->isExportNode ( dagPath, isForced, isVisible ) ) return false;

        // TODO
        // If this is a DAG node (not a DAG shape) check to see whether we should enter
        bool animationExport = true;

        /*
        bool isSceneRoot = dagPath.length() == 0;
        if (!isSceneRoot)
        {
         if (!exportNode || !enterDagNode(sceneNode, dagPath))
         {
          animationExport = false;
         }
        }*/

        // The COLLADA Node
        COLLADA::Node* colladaSceneNode = NULL;

        // Flag if the node was exported
        bool nodeExported = false;

        // Export the transform
        bool isTransform = dagPath.hasFn ( MFn::kTransform );

        if ( isTransform )
        {
            sceneElement->setType ( SceneElement::TRANSFORM );

            // Export the scene graph node for all transform-derivatives

            if ( dagPath.hasFn ( MFn::kJoint ) )
            {
                if ( ExportOptions::exportJointsAndSkin() )
                {
                    if ( animationExport )
                    {
                        colladaSceneNode = new COLLADA::Node ( mDocumentExporter->getStreamWriter() );
                        nodeExported = exportVisualSceneNode ( colladaSceneNode, sceneElement );

                        // push it into the list of the exported elements
                        sceneGraph->addElement ( sceneElement );

                        // TODO
                        //     doc->GetControllerLibrary()->ExportJoint(sceneNode, dagPath, isLocal);
                    }

                    else
                    {
                        isLocal = true;
                    }
                }

                else
                {
                    isTransform = false; // we didn't do anything to this node
                }
            }

            else
            {
                // Taken out of VisitTransform.  If VisitTransform
                // returns without creating a child, then we -will- fail.
                if ( !isForced && !isVisible && !isLocal ) return false;

                if ( animationExport )
                {
                    colladaSceneNode = new COLLADA::Node ( mDocumentExporter->getStreamWriter() );
                    nodeExported = exportVisualSceneNode ( colladaSceneNode, sceneElement );

                    // push it into the list of the exported elements
                    sceneGraph->addElement ( sceneElement );
                }

                else
                {
                    isLocal = true;
                }
            }
        }

        // Check if the element isn't already exported

        if ( isLocal && !hasPreviousInstance )
        {
            for ( uint i=0; i<sceneElement->getChildCount(); ++i )
            {
                SceneElement* childElement = sceneElement->getChild ( i );

                // recursive call for all the child elements
                exportVisualSceneNodes ( childElement, isLocal );
            }
        }

        // Close the visual scene tag in the collada document

        if ( colladaSceneNode != NULL )
        {
            if ( nodeExported )
            {
                // Write the extra technique tags in the collada document
                colladaSceneNode->addTextureExtraTechniques ( *mSW );

                // Close the current scene node
                colladaSceneNode->end();
            }

            delete ( colladaSceneNode );

            colladaSceneNode = NULL;
        }

        return nodeExported;
    }

    //---------------------------------------------------------------
    /**
     * Creates and opens a visual scene node
     * and writes the references to the geometries and materials.
     */
    bool VisualSceneExporter::exportVisualSceneNode ( COLLADA::Node* sceneNode,
            SceneElement* sceneElement )
    {
        // Set the visual scene node
        mVisualSceneNode = sceneNode;

        // Get the dagPath from the scene element
        const MDagPath dagPath = sceneElement->getPath();

        // Initialize the member varibles

        if ( !initializeTransform ( dagPath ) )
        {
            String pathName = dagPath.fullPathName().asChar();
            String message = "Could not initialize the transform object of the path " + pathName;
            assert ( message.c_str() );
            return false;
        }

        // Add the visual scene, if not done before

        if ( !visualSceneAdded )
        {
            openVisualScene ( mSceneId );
            visualSceneAdded = true;
        }

        // Prepares the visual scene node
        openVisualSceneNode ( dagPath );

        // ------------------------------------------------------
        // Export the transformation information

        if ( ExportOptions::bakeTransforms() )
        {
            exportMatrixTransform();
        }

        else if ( ExportOptions::exportCameraAsLookat() && dagPath.hasFn ( MFn::kCamera ) )
        {
            exportLookatTransform();
        }

        else
        {
            exportDecomposedTransform();
        }

        // Exports the visibility technique tag and the visibility animation.
        exportVisibility ( sceneNode );


        // ------------------------------------------------------
        // Write the geometries in the collada document

        // Get the streamWriter from the export document
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Check the geometry instances, which use this visual scene
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );

            if ( childElement->getType() == SceneElement::MESH && childElement->getIsExportNode() )
            {
                MDagPath childDagPath = childElement->getPath();
                String childNodeID = childElement->getNodeName().asChar();

                // Write the geometry instance
                COLLADA::InstanceGeometry instanceGeometry ( streamWriter );
                instanceGeometry.setUrl ( "#" + COLLADA::LibraryGeometries::GEOMETRY_ID_PRAEFIX + childNodeID );

                // Write all materials
                COLLADA::InstanceMaterialList& instanceMaterialList =
                    instanceGeometry.getBindMaterial().getInstanceMaterialList();

                // Find how many shaders are used by this instance of the mesh
                MFnMesh fnMesh ( childDagPath.node() );

                String nodeName = fnMesh.name().asChar();
                String pathName = childDagPath.fullPathName().asChar();

                MObjectArray shaders;
                MIntArray shaderIndices;
                fnMesh.getConnectedShaders ( 0, shaders, shaderIndices );

                uint realShaderCount = ( uint ) shaders.length();
                uint numShaders = ( uint ) max ( ( size_t ) 1, ( size_t ) shaders.length() );

                for ( uint shaderPosition = 0; shaderPosition < numShaders; ++shaderPosition )
                {
                    if ( shaderPosition < realShaderCount )
                    {
                        // Add shader-specific parameters (TexCoords sets).
                        // Add symbolic name for the material used on this polygon set.
                        MObject shadingEngine = shaders[shaderPosition];
                        MFnDependencyNode shadingEngineFn ( shadingEngine );
                        String colladaName = mDocumentExporter->mayaNameToColladaName ( shadingEngineFn.name(), true ).asChar();

                        String shadingEngineName = shadingEngineFn.name().asChar();
                        String materialName = mDocumentExporter->mayaNameToColladaName ( shadingEngineFn.name() ).asChar();

                        // This object contains a reference to a shader, or material, so we might call
                        // our own function to write that material to our own data structure for later export.
                        MObject shader = DagHelper::getSourceNodeConnectedTo ( shadingEngine, "surfaceShader" );
                        MFnDependencyNode shaderFn ( shader );
                        String shaderName = shaderFn.name().asChar();

                        instanceMaterialList.push_back ( COLLADA::InstanceMaterial ( materialName, "#" + shaderName ) );
                    }
                }

                instanceGeometry.add();
            }
        }

        return true;
    }

    //---------------------------------------------------------------
    bool VisualSceneExporter::initializeTransform ( const MDagPath &dagPath )
    {
        mDagPath = dagPath;

        MStatus status;
        MObject transformNode = dagPath.transform ( &status );

        if ( ( status != MS::kSuccess ) && status.statusCode () == MStatus::kInvalidParameter ) return false;

        mTransformObject = transformNode;

        MFnDagNode transform ( transformNode, &status );

        if ( !status )
        {
            status.perror ( "MFnDagNode constructor" );
            return false;
        }

        // get the transforms local translation
        MFnTransform fn ( transformNode );

        mTransformMatrix = fn.transformation();

        if ( fn.parentCount() > 0 )
        {
            MFnTransform t ( fn.parent ( 0 ) );

            if ( t.hasObj ( MFn::kClusterFilter ) || t.hasObj ( MFn::kSkinClusterFilter ) )
            {
                mTransformMatrix = MTransformationMatrix ( mTransformMatrix.asMatrix() * t.transformationMatrix() );
            }
        }

        return true;
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportDecomposedTransform()
    {
        MVector translation = mTransformMatrix.translation ( MSpace::kTransform );
        MPoint rotatePivotTranslation = mTransformMatrix.rotatePivotTranslation ( MSpace::kTransform );
        MPoint rotatePivot = mTransformMatrix.rotatePivot ( MSpace::kTransform, NULL );
        MVector scalePivotTranslation = mTransformMatrix.scalePivotTranslation ( MSpace::kTransform );
        MVector scalePivot = mTransformMatrix.scalePivot ( MSpace::kTransform );
        double shear[3] = {0, 0, 0};
        mTransformMatrix.getShear ( shear, MSpace::kTransform );

        MEulerRotation jointOrientation, rotation, rotationAxis;
        bool isJoint;

        if ( mTransformObject != MObject::kNullObj )
        {
            isJoint = DagHelper::getPlugValue ( mTransformObject, ATTR_JOINT_ORIENT, jointOrientation );

            if ( !DagHelper::getPlugValue ( mTransformObject, ATTR_ROTATE, rotation ) ) rotation.setValue ( 0, 0, 0 );

            if ( !DagHelper::getPlugValue ( mTransformObject, ATTR_ROTATE_AXIS, rotationAxis ) ) rotationAxis.setValue ( 0, 0, 0 );

            rotation.order = ( MEulerRotation::RotationOrder ) ( ( int ) mTransformMatrix.rotationOrder() - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ );

            rotationAxis.order = jointOrientation.order = MEulerRotation::kXYZ;
        }

        else
        {
            rotation = mTransformMatrix.eulerRotation();
            rotation.order = ( MEulerRotation::RotationOrder ) ( ( int ) mTransformMatrix.rotationOrder() - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ );
            isJoint = false;
        }

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
        exportTranslation ( ATTR_TRANSLATE, translation, true );

        exportTranslation ( ATTR_ROTATE_PIVOT_TRANSLATION, rotatePivotTranslation, false );

        exportTranslation ( ATTR_ROTATE_PIVOT, rotatePivot, false );

        if ( isJoint ) exportRotation ( ATTR_JOINT_ORIENT, jointOrientation );

        exportRotation ( ATTR_ROTATE, rotation );

        // exportRotation(ROTATE_AXIS_SID, rotationAxis); // Also called rotate orient in documentation

        exportTranslation ( ATTR_ROTATE_PIVOT_INVERSE, rotatePivot * -1, false );

        exportTranslation ( ATTR_SCALE_PIVOT_TRANSLATION, scalePivotTranslation, false );

        exportTranslation ( ATTR_SCALE_PIVOT, scalePivot, false );

        exportSkew ( shear );

        // get the transforms scale
        exportScale();

        exportTranslation ( ATTR_SCALE_PIVOT_INVERSE, scalePivot * -1, false );
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportSkew ( double* shear )
    {
        // From my derivation, it is easier to split the shear into three.
        // This forces the hard coded axises and the angle becomes simply:
        // skewAngle = arctan(shearValue);
        //

        float xAxis[] = {1.0f, 0.0f, 0.0f};
        float yAxis[] = {0.0f, 1.0f, 0.0f};
        float zAxis[] = {0.0f, 0.0f, 1.0f};

        if ( shear[0] != 0.0 )
        {
            float angle = COLLADA::MathUtils::radToDegF ( ( float ) atan ( shear[0] ) );
            float* rotateAxis ( xAxis );
            float* aroundAxis ( yAxis );

            mVisualSceneNode->addSkew ( SKEW_XY_SID, angle, rotateAxis, aroundAxis );
        }

        if ( shear[1] != 0.0 )
        {
            float angle = COLLADA::MathUtils::radToDegF ( ( float ) atan ( shear[1] ) );
            float* rotateAxis ( xAxis );
            float* aroundAxis ( zAxis );

            mVisualSceneNode->addSkew ( SKEW_XZ_SID, angle, rotateAxis, aroundAxis );
        }

        if ( shear[2] != 0.0 )
        {
            float angle = COLLADA::MathUtils::radToDegF ( ( float ) atan ( shear[2] ) );
            float* rotateAxis ( yAxis );
            float* aroundAxis ( zAxis );

            mVisualSceneNode->addSkew ( SKEW_YZ_SID, angle, rotateAxis, aroundAxis );
        }
    }

    //---------------------------------------------------------------
    //
    // Element export
    //
    //---------------------------------------------------------------

    //---------------------------------------------------------------
    void VisualSceneExporter::exportTranslation ( const String name,
            const MPoint& translation,
            bool animation )
    {
        exportTranslation ( name, MVector ( translation ), animation );
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportTranslation ( const String name,
            const MVector& translation,
            bool animation )
    {
        bool isZero = true;

        for ( int i=0; i<3 && isZero; ++i )
        {
            if ( translation[i] != 0 ) isZero = false;
        }

        if ( animation || !isZero )
        {
            mVisualSceneNode->addTranslate ( name, translation.x, translation.y, translation.z );

            // TODO

            if ( animation )
            {
                AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
                animationExporter->addPlugAnimation ( mDagPath.node(), ATTR_TRANSLATE, name, TRANSLATION_PARAMETERS, kVector | kLength );
                //   animationExporter->addPlugAnimation(mDagPath.node(), name, translation, kVector | kLength);
                /*
                ANIM->AddPlugAnimation(transform, name, colladaTranslate->GetTranslation(), kVector | kLength);
                presence.trans = isZero ? DaeTransformPresence::kPresent : DaeTransformPresence::kNecessary;
                presence.transNode = colladaTranslate;

                if (transform == MObject::kNullObj && presence.trans == DaeTransformPresence::kPresent)
                {
                 SAFE_RELEASE(presence.transNode);
                 presence.trans = DaeTransformPresence::kUnused;
                }
                */
            }
        }
    }

    //---------------------------------------------------------------
    // If you wish to get the rotation data in euler angles (why?) then change the
    // JointOrient and Rotation variables to be MEulerRotation types. The writing
    // code can then ignore the 'w' parameter, and just output x,y,z rotation values.
    void VisualSceneExporter::exportRotation ( const String name, const MEulerRotation& rotation )
    {
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();

        // Export XYZ euler rotation in Z Y X order in the file
        // The rotation order is set to XYZ, Collada reads the parameter from behind
        // MEulerRotation eulerRotation = rotation.asEulerRotation();

        mVisualSceneNode->addRotateZ ( ATTR_ROTATE_Z, COLLADA::MathUtils::radToDeg ( rotation.z ) );
        mVisualSceneNode->addRotateY ( ATTR_ROTATE_Y, COLLADA::MathUtils::radToDeg ( rotation.y ) );
        mVisualSceneNode->addRotateX ( ATTR_ROTATE_X, COLLADA::MathUtils::radToDeg ( rotation.x ) );

        bool isZero[3] = { ( rotation.x == 0.0 ), ( rotation.y == 0.0 ), ( rotation.z == 0.0 ) };

        for ( uint i=0; i<3; ++i )
        {
            animationExporter->addPlugAnimation ( mTransformObject,
                                                  name + XYZ_PARAMETERS[i],
                                                  ANGLE_PARAMETER,
                                                  kSingle | kQualifiedAngle );

            /*
            // TODO
            FCDAnimated* animated = rotateHelper.colladaRotations[i]->GetAngleAxis().GetAnimated();
            ANIM->AddPlugAnimation(transform, str + components[i], animated, kSingle | kQualifiedAngle);
            p[i] = (!isFirstRotation && isZero[i]) ? DaeTransformPresence::kPresent : DaeTransformPresence::kNecessary;
            rotationTransforms[i] = rotateHelper.colladaRotations[i];

            if (transform == MObject::kNullObj && !isFirstRotation && isZero[i])
            {
             SAFE_RELEASE(rotationTransforms[i]);
             p[i] = DaeTransformPresence::kUnused;
            }
            */
        }

        isFirstRotation = false;
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportMatrixTransform()
    {
        MMatrix mayaSceneMatrix = mTransformMatrix.asMatrix();
        double sceneMatrix[4][4] ;
        MConvert::convertMMatrixToDouble4x4 ( sceneMatrix, mayaSceneMatrix );
        mVisualSceneNode->addMatrix ( ATTR_TRANSFORM, sceneMatrix );

        // For animations, sampling is always enforced for baked transforms.
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
        MVector translation = mTransformMatrix.translation ( MSpace::kTransform );

        MPlug plug = MFnDagNode ( mTransformObject ).findPlug ( ATTR_MATRIX );
        mDocumentExporter->getAnimationCache()->cachePlug ( plug, true );
        animationExporter->addPlugAnimation ( plug, ATTR_TRANSFORM, MATRIX_PARAMETER, kMatrix );
        // animationExporter->addPlugAnimation(plug, translation, kMatrix);

        /*
        // For animations, sampling is always enforced for baked transforms.
        MPlug p = MFnDagNode(transform).findPlug("matrix");
        doc->GetAnimationCache()->CachePlug(p, true);

        FCDAnimated* animated = colladaTransform->GetTransform().GetAnimated();
        ANIM->AddPlugAnimation(p, animated, kMatrix);
        */
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportLookatTransform()
    {
        // Compute local space parameters and export them. These parameters are:
        // - Eye position
        // - Interest point
        // - Up-axis direction
        //
        // TODO: camera animations for look-at transform are not implemented yet.
        //

        // attach the function set to the object
        MFnTransform transformFunctionSet ( mTransformObject );

        // Locate the camera in the dagPath
        MObject cameraObject ( MObject::kNullObj );
        uint pathChildCount = transformFunctionSet.childCount();

        for ( uint i = 0; i < pathChildCount; ++i )
        {
            MObject child = transformFunctionSet.child ( i );

            if ( child.hasFn ( MFn::kCamera ) )
            {
                cameraObject = child;
                break;
            }
        }

        if ( cameraObject == MObject::kNullObj )
        {
            // Revert to using decomposed transforms.
            exportDecomposedTransform();
        }

        else
        {
            // Get the camera matrix from which the other parameters
            // are computed.
            MFnCamera camera ( cameraObject );
            MMatrix matrix = transformFunctionSet.transformationMatrix();
            matrix.homogenize();

            // Get the position of the camera in local space.
            MVector eye ( matrix[3][0], matrix[3][1], matrix[3][2] );

            // Compute center of interest.
            double centerOfInterestDistance = camera.centerOfInterestPoint ( MSpace::kObject ).z;
            MVector front ( matrix[2][0], matrix[2][1], matrix[2][2] );
            MVector centerOfInterest = eye + ( front * centerOfInterestDistance );

            // TODO
            /*
            FCDTLookAt* lookAtTransform = (FCDTLookAt*) colladaNode->AddTransform(FCDTransform::LOOKAT);
            lookAtTransform->SetPosition(MConvert::ToFMVector(eye));
            lookAtTransform->SetTarget(MConvert::ToFMVector(centerOfInterest));

            // Extract the up direction, which corresponds to the second row.
            lookAtTransform->SetUp((float) matrix[1][0], (float) matrix[1][1], (float) matrix[1][2]);
            */
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportScale()
    {
        // attach the function set to the object
        MFnTransform transformFunctionSet ( mTransformObject );

        double scale[3] = {1, 1, 1};
        transformFunctionSet.getScale ( scale );

        // Check if all fields in the std::vector are ones
        bool isOneVector = true;

        for ( int i=0; i<3 && isOneVector; ++i )
        {
            if ( scale[i] != 1 ) isOneVector = false;
        }

        if ( mTransformObject != MObject::kNullObj || !isOneVector )
        {
            mVisualSceneNode->addScale ( ATTR_SCALE, scale[0], scale[1], scale[2] );

            AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
            animationExporter->addPlugAnimation ( mTransformObject, ATTR_SCALE, SCALE_PARAMETERS, kVector );
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportVisibility ( COLLADA::Node* sceneNode )
    {
        bool isVisible;

        if ( mTransformObject != MObject::kNullObj &&
                DagHelper::getPlugValue ( mTransformObject, ATTR_VISIBILITY, isVisible ) )
        {
            // Add an <extra> node with a visibility parameters that the animation can target
            sceneNode->addExtraTechniqueParameter ( COLLADA_PROFILE, ATTR_VISIBILITY, isVisible );

            AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
            animationExporter->addPlugAnimation ( mTransformObject, ATTR_VISIBILITY, EMPTY_PARAMETER, kBoolean );
        }
    }

}