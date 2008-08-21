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

#include "COLLADAMayaVisualSceneExporter.h"
#include "assert.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaConversion.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaControllerExporter.h"
#include "COLLADAMayaRotateHelper.h"

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
#include "COLLADAInstanceController.h"
#include "COLLADAMathUtils.h"
#include "COLLADALibraryControllers.h"
#include "COLLADAInstanceLight.h"
#include "COLLADAInstanceCamera.h"
#include "COLLADAURI.h"


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    VisualSceneExporter::VisualSceneExporter ( 
        COLLADA::StreamWriter* _streamWriter,
        DocumentExporter* _documentExporter,
        const String& _sceneId )
    : COLLADA::LibraryVisualScenes ( _streamWriter )
    , mDocumentExporter ( _documentExporter )
    , mSceneId ( _sceneId )
    , mIsJoint ( false )
    , mIsFirstRotation ( true )
    , mVisualSceneAdded ( false )
    , mVisualSceneNode ( NULL )
    {
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
        // Get the path of the current scene element.
        const MDagPath dagPath = sceneElement->getPath();

        // Check if the element isn't already exported
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElement* instantiatedSceneElement = sceneGraph->findExportedElement ( dagPath );
        bool hasPreviousInstance =  ( instantiatedSceneElement != NULL );
        if ( hasPreviousInstance )
        {
            sceneElement->setInstantiatedSceneElement ( instantiatedSceneElement );
        }

        // The unique ID
        String meshId = mDocumentExporter->dagPathToColladaId ( dagPath ); 
//         // Attach a function set
//         MFnDependencyNode fn ( dagPath.node() );
//         String nodeNameCollada = mDocumentExporter->mayaNameToColladaName ( fn.name(), true );
//         String meshId = /*GEOMETRY_ID_PRAEFIX +*/ nodeNameCollada;

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
        bool isSceneRoot = dagPath.length() == 0;
        if ( !isSceneRoot )
        {
//    if (!exportNode || !enterDagNode(sceneNode, dagPath))
//    {
//     animationExport = false;
//    }
        }

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
                sceneElement->setHasJoint(true);
                if ( ExportOptions::exportJointsAndSkin() )
                {
                    if ( animationExport )
                    {
                        colladaSceneNode = new COLLADA::Node ( mDocumentExporter->getStreamWriter(), hasPreviousInstance );
                        nodeExported = exportJointVisualSceneNode ( colladaSceneNode, sceneElement );

                        // Push it into the list of the exported elements
                        sceneGraph->addExportedElement ( sceneElement );
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
                    colladaSceneNode = new COLLADA::Node ( mDocumentExporter->getStreamWriter(), hasPreviousInstance );
                    nodeExported = exportNodeVisualSceneNode ( colladaSceneNode, sceneElement );

                    // push it into the list of the exported elements
                    sceneGraph->addExportedElement ( sceneElement );
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
            // Recursive call for all the child elements
            for ( uint i=0; i<sceneElement->getChildCount(); ++i )
            {
                SceneElement* childElement = sceneElement->getChild ( i );
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

    //------------------------------------------------------
    bool VisualSceneExporter::exportJointVisualSceneNode (
        COLLADA::Node *sceneNode,
        const SceneElement* sceneElement )
    {
        // Set the type of the node to a joint
        sceneNode->setType ( COLLADA::Node::JOINT );

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Get the node joint sid
        String nodeSid = mDocumentExporter->dagPathToColladaId ( dagPath );
        sceneNode->setNodeSid( nodeSid );

        // Export the segment-scale-compensate flag.
        bool segmentScaleCompensate;
        DagHelper::getPlugValue ( dagPath.transform(),
                                  ATTR_SEGMENT_SCALE_COMPENSATE,
                                  segmentScaleCompensate );

        // Not animateable
        sceneNode->addExtraTechniqueParameter ( MAYA_PROFILE,
                                                MAYA_SEGMENTSCALECOMP_PARAMETER,
                                                segmentScaleCompensate );

        // Export the node
        return exportVisualSceneNode ( sceneNode, sceneElement );
    }

    //------------------------------------------------------
    bool VisualSceneExporter::exportNodeVisualSceneNode (
        COLLADA::Node *sceneNode,
        const SceneElement* sceneElement )
    {
        // Set the type of the node
        sceneNode->setType ( COLLADA::Node::NODE );

        // Export the node
        return exportVisualSceneNode ( sceneNode, sceneElement );
    }

    //---------------------------------------------------------------
    bool VisualSceneExporter::exportVisualSceneNode (
        COLLADA::Node* sceneNode,
        const SceneElement* sceneElement )
    {
        // Set the visual scene node
        mVisualSceneNode = sceneNode;

        // Get the dagPath from the scene element
        MDagPath dagPath = sceneElement->getPath();

        // Flag, if the node is already instantiated
        bool isInstanceNode = mVisualSceneNode->getIsInstanceNode();
        if ( isInstanceNode )
        {
            // Prepares the visual scene node. 
            openVisualSceneNode ( sceneElement );
        }
        else
        {
            // Initialize the member variables
            if ( !initializeTransform ( dagPath ) )
            {
                MString pathName = dagPath.fullPathName();
                MString message = "Could not initialize the transform object of the path " + pathName;
                MGlobal::displayError( message );
                assert ( initializeTransform ( dagPath ) );
                return false;
            }

            // Prepares the visual scene node. 
            openVisualSceneNode ( sceneElement );

            // ------------------------------------------------------
            // Export the transformation information
        
            if ( ExportOptions::bakeTransforms() )
            {
                exportMatrixTransform ();
            }
            else if ( ExportOptions::exportCameraAsLookat() && dagPath.hasFn ( MFn::kCamera ) )
            {
                exportLookatTransform ();
            }
            else
            {   
                exportDecomposedTransform ();
            }

            // Exports the visibility technique tag and the visibility animation.
            exportVisibility ( sceneNode );


            // ------------------------------------------------------
            // Write the instance urls of the geometries, controllers 
            // and lights into the collada document.

            // Check the geometry instances, which use this visual scene
            uint childCount = sceneElement->getChildCount();
            for ( uint i=0; i<childCount; ++i )
            {
                SceneElement* childElement = sceneElement->getChild ( i );

                // Check if the child element is a mesh object and an export node
                if ( childElement->getType() == SceneElement::MESH &&
                     childElement->getIsExportNode() )
                {
                    // Get the controller library
                    ControllerExporter* controller = mDocumentExporter->getControllerExporter();
                    MObject childNode = childElement->getPath().node();

                    bool hasSkinController = controller->hasSkinController ( childNode );
                    bool hasMorphController = controller->hasMorphController ( childNode );

                    // Check for controllers, otherwise instantiate the geometry. 
                    // Add the controller and/or geometry to our libraries
                    if ( ( ExportOptions::exportJointsAndSkin() && hasSkinController ) || hasMorphController )
                    {
                        exportControllerInstance ( childElement, hasSkinController, hasMorphController );
                    }
                    else
                    {
                        exportGeometryInstance ( childElement );
                    }
                }
                else if ( childElement->getType() == SceneElement::LIGHT &&
                          childElement->getIsExportNode() )
                {
                    exportLightInstance ( childElement );
                }
                else if ( childElement->getType() == SceneElement::CAMERA &&
                          childElement->getIsExportNode() )
                {
                    exportCameraInstance ( childElement );
                }
            }
        }

        return true;
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportMaterialList( 
        COLLADA::InstanceMaterialList &instanceMaterialList, 
        MDagPath &dagPath,
        const uint instanceNumber )
    {
        // Find how many shaders are used by this instance of the mesh
        MFnMesh fnMesh ( dagPath.node() );

        // Get the connected shaders of the main mesh instance (we will take always the zero).
        // This is a COLLADA workaround to get the symbolic material name. 
        // This is used to share a pointer in the geometry, but to use different materials in the node.
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
                String shadingEngineName = shadingEngineFn.name().asChar();
                String materialName = mDocumentExporter->mayaNameToColladaName ( shadingEngineFn.name() );

                // To get the right shader name, we have to take the correct mesh instance.
                if ( instanceNumber > 0 )
                {
                    MObjectArray instanceShaders;
                    MIntArray instanceShaderIndices;
                    fnMesh.getConnectedShaders ( instanceNumber, instanceShaders, instanceShaderIndices );
                    shadingEngine = instanceShaders[shaderPosition];
                }

                // This object contains a reference to a shader, or material, so we might call
                // our own function to write that material to our own data structure for later export.
                MObject shader = DagHelper::getSourceNodeConnectedTo ( shadingEngine, ATTR_SURFACE_SHADER );
                MFnDependencyNode shaderFn ( shader );
                String shaderName = shaderFn.name().asChar();

                instanceMaterialList.push_back ( COLLADA::InstanceMaterial ( materialName, COLLADA::URI ( "", shaderName ) ) );
            }
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::openVisualSceneNode ( const SceneElement* sceneElement )
    {
        // Get the dagPath from the scene element
        const MDagPath dagPath = sceneElement->getPath();

        // Add the visual scene, if not done before
        if ( !mVisualSceneAdded )
        {
            // There is always just one visual scene. Give it a valid unique id.
            String visualSceneName = mDocumentExporter->checkNCName( mSceneId );
            openVisualScene ( VISUAL_SCENE_NODE_ID, visualSceneName );
            mVisualSceneAdded = true;
        }

        if ( mVisualSceneNode->getIsInstanceNode() )
        {
            // Get the URL of the instantiated visual scene node
            SceneElement* instantiatedSceneElement = sceneElement->getInstantiatedSceneElement();
            MDagPath instantiatedDagPath = instantiatedSceneElement->getPath();

            // Set the node URL
            String instanceNodeURL = mDocumentExporter->dagPathToColladaId ( instantiatedDagPath );
            mVisualSceneNode->setNodeURL ( COLLADA::URI ( "", instanceNodeURL ) );
        }
        else
        {
            // Get the node ID and name
            String nodeID = mDocumentExporter->dagPathToColladaId ( dagPath );
            String nodeName = mDocumentExporter->dagPathToColladaName ( dagPath );

            // Create the scene node
            mVisualSceneNode->setNodeId ( nodeID );
            mVisualSceneNode->setNodeName ( nodeName );
        }

        // open the scene node
        mVisualSceneNode->start();
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
        if ( mTransformObject != MObject::kNullObj )
        {
            mIsJoint = DagHelper::getPlugValue ( mTransformObject, ATTR_JOINT_ORIENT, jointOrientation );

            if ( !DagHelper::getPlugValue ( mTransformObject, ATTR_ROTATE, rotation ) ) rotation.setValue ( 0, 0, 0 );
            if ( !DagHelper::getPlugValue ( mTransformObject, ATTR_ROTATE_AXIS, rotationAxis ) ) rotationAxis.setValue ( 0, 0, 0 );

            rotation.order = ( MEulerRotation::RotationOrder ) ( ( int ) mTransformMatrix.rotationOrder() - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ );
            rotationAxis.order = jointOrientation.order = MEulerRotation::kXYZ;
        }
        else
        {
            rotation = mTransformMatrix.eulerRotation();
            rotation.order = ( MEulerRotation::RotationOrder ) ( ( int ) mTransformMatrix.rotationOrder() - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ );
            mIsJoint = false;
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

        if ( mIsJoint ) exportRotation ( ATTR_JOINT_ORIENT, jointOrientation );
        exportRotation ( ATTR_ROTATE, rotation );

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

        if ( !COLLADA::MathUtils::equals( shear[0], 0.0 ) )
        {
            double angle = COLLADA::MathUtils::radToDeg ( atan ( shear[0] ) );
            angle = COLLADA::MathUtils::equalsZero( angle ) ? 0 : angle;
            float* rotateAxis ( xAxis );
            float* aroundAxis ( yAxis );

            mVisualSceneNode->addSkew ( SKEW_XY_SID, (float) angle, rotateAxis, aroundAxis );
        }

        if ( !COLLADA::MathUtils::equals( shear[1], 0.0 ) )
        {
            double angle = COLLADA::MathUtils::radToDeg ( atan ( shear[1] ) );
            angle = COLLADA::MathUtils::equalsZero( angle ) ? 0 : angle;
            float* rotateAxis ( xAxis );
            float* aroundAxis ( zAxis );

            mVisualSceneNode->addSkew ( SKEW_XZ_SID, (float) angle, rotateAxis, aroundAxis );
        }

        if ( !COLLADA::MathUtils::equals( shear[2], 0.0 ) )
        {
//            double angle = COLLADA::MathUtils::radToDeg ( atan ( shear[2] ) );
            double angle = MAngle::internalToUI ( atan ( shear[2] ) );
            angle = COLLADA::MathUtils::equalsZero( angle ) ? 0 : angle;
            float* rotateAxis ( yAxis );
            float* aroundAxis ( zAxis );

            mVisualSceneNode->addSkew ( SKEW_YZ_SID, (float) angle, rotateAxis, aroundAxis );
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportTranslation ( const String name,
            const MPoint& translation,
            bool animation )
    {
        exportTranslation ( name, MVector ( translation ), animation );
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportTranslation ( 
        const String name,
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
            // Convert the  maya internal unit type from centimeters 
            // into the working units of the current scene!
            mVisualSceneNode->addTranslate ( 
                name, 
                COLLADA::MathUtils::equalsZero( translation.x ) ? 0 : MDistance::internalToUI ( translation.x ), 
                COLLADA::MathUtils::equalsZero( translation.y ) ? 0 : MDistance::internalToUI ( translation.y ), 
                COLLADA::MathUtils::equalsZero( translation.z ) ? 0 : MDistance::internalToUI ( translation.z ) );

            if ( animation )
            {
                AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
                animationExporter->addNodeAnimation ( 
                    mDagPath.node(), ATTR_TRANSLATE, name, kVector | kLength, XYZ_PARAMETERS );
            }
        }
    }

    //---------------------------------------------------------------
    // If you wish to get the rotation data in euler angles (why?) then change the
    // JointOrient and Rotation variables to be MEulerRotation types. The writing
    // code can then ignore the 'w' parameter, and just output x,y,z rotation values.
    void VisualSceneExporter::exportRotation ( const String name, const MEulerRotation& rotation )
    {
        RotateHelper rotateHelper ( rotation );
        std::vector<std::vector<double>>& matrixRotate = rotateHelper.getRotationMatrix ();
        std::vector<String>& rotateParams = rotateHelper.getRotationParameters ();
        
        // Set zero flags, where the rotation is zero. The order of rotation is ZYX.
        bool isZero[3] = {  COLLADA::MathUtils::equals( matrixRotate[0][3], 0.0 ), 
                            COLLADA::MathUtils::equals( matrixRotate[1][3], 0.0 ), 
                            COLLADA::MathUtils::equals( matrixRotate[2][3], 0.0 ) };

        // Get a pointer to the animation exporter.
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();

        // The array for the animations.
        bool isAnimated[3] = { false, false, false };

        // Go through the axes for the animations.
        for ( uint i=0; i<3; ++i )
        {
            // Add the animation in the order XYZ
            isAnimated[i] = animationExporter->addNodeAnimation (
                mTransformObject,
                name + rotateParams[i],
                kSingle | kQualifiedAngle,
                ANGLE_PARAMETER );
        }

        // Go through the axes for the rotations.
        for ( uint i=0; i<3; ++i )
        {
            bool rotationIsNecessary;
            // A joint must always have a rotation.
            if ( mIsJoint ) rotationIsNecessary = true;
            // You have to write the rotation, if the element is animated.
            else rotationIsNecessary = ( isAnimated[i] || !( !mIsFirstRotation && isZero[i] ));

            if ( mTransformObject != MObject::kNullObj && rotationIsNecessary )
            {
                // Add the rotation in the order ZYX
                mVisualSceneNode->addRotate (
                    name + rotateParams[i],
                    COLLADA::MathUtils::equalsZero( matrixRotate[i][0] ) ? 0 : matrixRotate[i][0],
                    COLLADA::MathUtils::equalsZero( matrixRotate[i][1] ) ? 0 : matrixRotate[i][1],
                    COLLADA::MathUtils::equalsZero( matrixRotate[i][2] ) ? 0 : matrixRotate[i][2],
                    COLLADA::MathUtils::equalsZero( matrixRotate[i][3] ) ? 0 : matrixRotate[i][3] );
            }
        }

        mIsFirstRotation = false;
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportMatrixTransform()
    {
        MMatrix mayaSceneMatrix = mTransformMatrix.asMatrix();
        double sceneMatrix[4][4] ;
        convertMMatrixToDouble4x4 ( sceneMatrix, mayaSceneMatrix );

        // Convert the  maya internal unit type of the transform part of the 
        // matrix from centimeters into the working units of the current scene!
        for ( uint i=0; i<3; ++i)
            sceneMatrix [i][3] = MDistance::internalToUI ( sceneMatrix [i][3] );

        mVisualSceneNode->addMatrix ( ATTR_TRANSFORM, sceneMatrix );

        // For animations, sampling is always enforced for baked transforms.
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
        MVector translation = mTransformMatrix.translation ( MSpace::kTransform );

        MPlug plug = MFnDagNode ( mTransformObject ).findPlug ( ATTR_MATRIX );
        mDocumentExporter->getAnimationCache()->cachePlug ( plug, true );
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
            // Positioning and orienting a camera or object in the scene is often 
            // complicated when using a matrix. A lookat transform is an intuitive 
            // way to specify an eye position, interest point, and orientation.

            // Get the camera matrix from which the other parameters are computed.
            MFnCamera camera ( cameraObject );
            MMatrix matrix = transformFunctionSet.transformationMatrix();
            matrix.homogenize();

            // Get the position of the camera in local space.
            MVector eye(matrix[3][0], matrix[3][1], matrix[3][2]);
            float eyePosition[3] = {
                COLLADA::MathUtils::equalsZero( matrix[3][0] ) ? 0.0f : (float) matrix[3][0], 
                COLLADA::MathUtils::equalsZero( matrix[3][1] ) ? 0.0f : (float) matrix[3][2], 
                COLLADA::MathUtils::equalsZero( matrix[3][2] ) ? 0.0f : (float) matrix[3][2] };

            // Compute center of interest.
            double centerOfInterestDistance = camera.centerOfInterestPoint ( MSpace::kObject ).z;
            MVector front ( matrix[2][0], matrix[2][2], matrix[2][2] );
            MVector centerOfInterest = eye + ( front * centerOfInterestDistance );
            float interestPosition[3] = {
                COLLADA::MathUtils::equalsZero( centerOfInterest.x ) ? 0.0f : (float) centerOfInterest.x, 
                COLLADA::MathUtils::equalsZero( centerOfInterest.y ) ? 0.0f : (float) centerOfInterest.y, 
                COLLADA::MathUtils::equalsZero( centerOfInterest.z ) ? 0.0f : (float) centerOfInterest.z };

            // Extract the up direction, which corresponds to the second row.
            float upPosition[3] = { 
                COLLADA::MathUtils::equalsZero( matrix[1][0] ) ? 0.0f : (float) matrix[1][0], 
                COLLADA::MathUtils::equalsZero( matrix[1][1] ) ? 0.0f : (float) matrix[1][2], 
                COLLADA::MathUtils::equalsZero( matrix[1][2] ) ? 0.0f : (float) matrix[1][2] };

            // Add the camera lookat
            mVisualSceneNode->addLookat ( eyePosition, interestPosition, upPosition );
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
            if ( !COLLADA::MathUtils::equals( scale[i], 1.0 ) ) isOneVector = false;
        }

        if ( mTransformObject != MObject::kNullObj && !isOneVector )
        {
            mVisualSceneNode->addScale ( 
                ATTR_SCALE, 
                COLLADA::MathUtils::equalsZero(scale[0]) ? 0 : scale[0], 
                COLLADA::MathUtils::equalsZero(scale[1]) ? 0 : scale[1], 
                COLLADA::MathUtils::equalsZero(scale[2]) ? 0 : scale[2] );

            AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
            animationExporter->addNodeAnimation ( mTransformObject, ATTR_SCALE, kVector, XYZ_PARAMETERS );
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportVisibility ( COLLADA::Node* sceneNode )
    {
        bool isVisible;

        if ( mTransformObject != MObject::kNullObj )
        {
            // Get the visibility value, if it exist
            if ( DagHelper::getPlugValue ( mTransformObject, ATTR_VISIBILITY, isVisible ) )
            {
                AnimationSampleCache* animationCache = mDocumentExporter->getAnimationCache();
                AnimationResult animationResult;
                animationResult = AnimationHelper::isAnimated( animationCache, mTransformObject, ATTR_VISIBILITY );

                // Write out the visibility of this node, if it is not visible or if it is animated.
                if ( !isVisible || animationResult != kISANIM_None )
                {
                    // Add an <extra> node with a visibility parameters that the animation can target
                    sceneNode->addExtraTechniqueParameter ( COLLADA_PROFILE, ATTR_VISIBILITY, isVisible );

                    AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
                    animationExporter->addNodeAnimation ( mTransformObject, ATTR_VISIBILITY, kBoolean );
                }
            }
        }
    }
    
    //---------------------------------------------------------------
    void VisualSceneExporter::exportControllerInstance( 
        SceneElement* childElement, 
        bool hasSkinController, 
        bool hasMorphController )
    {
        // Get the streamWriter from the export document
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the path and the id of the child element
        MDagPath childDagPath = childElement->getPath();

        // Create the unique controller ID
//         String controllerId = mDocumentExporter->dagPathToColladaId( childDagPath ) + 
//                                 COLLADA::LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;

        String controllerId;
        if ( !childElement->getNodeId().empty() ) controllerId = childElement->getNodeId();
        else controllerId = childElement->getNodeName();
        if ( hasMorphController )
            controllerId += COLLADA::LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX;
        if ( hasSkinController )
            controllerId += COLLADA::LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;

        COLLADA::InstanceController instanceController ( streamWriter );
        instanceController.setUrl ( COLLADA::URI ( "", controllerId ) );

        // Set the skeletonId. It indicates where a skin 
        // controller is to start to search for the joint nodes 
        // it needs. This element is meaningless for morph controllers.

        // Get the skeleton id from the element
        String skeletonId = childElement->getSkeletonId();
        if ( !skeletonId.empty() )
        {
            instanceController.addSkeleton( COLLADA::URI ( "", skeletonId ) );
        }

        // Write all materials
        COLLADA::InstanceMaterialList& instanceMaterialList =
            instanceController.getBindMaterial().getInstanceMaterialList();

        // Export the materials
        uint instanceNumber = childDagPath.instanceNumber();
        exportMaterialList( instanceMaterialList, childDagPath, instanceNumber );

        instanceController.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportGeometryInstance( SceneElement* childElement )
    {
        // Get the streamWriter from the export document
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the path and the id of the child element
        MDagPath childDagPath = childElement->getPath();
//        String geometryId = mDocumentExporter->dagPathToColladaId ( childDagPath );
        String geometryId = childElement->getNodeId();
        if ( geometryId.empty() ) geometryId = childElement->getNodeName();
        
        // Write the geometry instance
        COLLADA::InstanceGeometry instanceGeometry ( streamWriter );
        instanceGeometry.setUrl ( COLLADA::URI ( "", geometryId ) );

        // Write all materials
        COLLADA::InstanceMaterialList& instanceMaterialList =
            instanceGeometry.getBindMaterial().getInstanceMaterialList();

        // Export the materials
        uint instanceNumber = childDagPath.instanceNumber();
        exportMaterialList( instanceMaterialList, childDagPath, instanceNumber );

        instanceGeometry.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportLightInstance( SceneElement* childElement )
    {
        // Get the streamWriter from the export document
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the path and the id of the child element
        MDagPath childDagPath = childElement->getPath();
        String lightId = mDocumentExporter->dagPathToColladaId ( childDagPath );

        // Create and write the light instance
        COLLADA::InstanceLight instanceLight ( streamWriter, COLLADA::URI ( "", lightId ) );
        instanceLight.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportCameraInstance( SceneElement* childElement )
    {
        // Get the streamWriter from the export document
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the path and the id of the child element
        MDagPath childDagPath = childElement->getPath();
        String lightId = mDocumentExporter->dagPathToColladaId ( childDagPath );

        // Create and write the camera instance
        COLLADA::InstanceCamera instanceCamera ( streamWriter, COLLADA::URI ( "", lightId ) );
        instanceCamera.add();
    }

}