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
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaConversion.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaControllerExporter.h"
#include "COLLADAMayaRotateHelper.h"
#include "COLLADAMayaReferenceManager.h"

#include <maya/MFnIkHandle.h>
#include <maya/MFnMesh.h>
#include <maya/MFnSkinCluster.h>
#include <maya/MItDag.h>
#include <maya/MFnIkJoint.h>
#include <maya/MQuaternion.h>
#include <maya/MEulerRotation.h>
#include <maya/MDagPath.h>
#include <maya/MFnCamera.h>

#include "COLLADASWNode.h"
#include "COLLADASWInstanceGeometry.h"
#include "COLLADASWInstanceController.h"
#include "COLLADASWLibraryControllers.h"
#include "COLLADASWInstanceLight.h"
#include "COLLADASWInstanceCamera.h"
#include "COLLADASWInstanceNode.h"
#include "COLLADASWConstants.h"

#include "Math/COLLADABUMathUtils.h"

#include "assert.h"


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    VisualSceneExporter::VisualSceneExporter (
        COLLADASW::StreamWriter* _streamWriter,
        DocumentExporter* _documentExporter,
        const String& _sceneId )
    : COLLADASW::LibraryVisualScenes ( _streamWriter )
    , mDocumentExporter ( _documentExporter )
    , mSceneId ( _sceneId )
    , mIsJoint ( false )
    , mIsFirstRotation ( true )
    , mVisualSceneAdded ( false )
    , mVisualSceneNode ( NULL )
    {
    }


    // ------------------------------------------------------------
    bool VisualSceneExporter::exportVisualScenes()
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

        // Export all/selected DAG nodes
        size_t length = exportNodesTree->size();
        for ( size_t i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];

            // Exports all the nodes in a node and all its child nodes recursive
            if ( exportVisualSceneNodes ( sceneElement ) ) nodeExported = true;
        }

        // Just if a node was exported, the visual scene tag
        // in the collada document is open and should be closed.
        if ( nodeExported ) closeVisualScene();

        closeLibrary();

        // TODO
        // Setup the reference information
        // GetReferenceManager()->Synchronize();

        return nodeExported;
    }

    // ---------------------------------------------------------------
    // Exports all the nodes in a node and all its child nodes recursive
    bool VisualSceneExporter::exportVisualSceneNodes ( SceneElement* sceneElement )
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

        bool isForced = sceneElement->getIsForced();
        bool isVisible = sceneElement->getIsVisible();
        bool isExportNode = sceneElement->getIsExportNode();

        // Check for a file reference
        bool isLocal = sceneElement->getIsLocal();

        // If this is a DAG node (not a DAG shape) check to see whether we should enter
        bool animationExport = true;
        bool isSceneRoot = dagPath.length() == 0;
        if ( !isSceneRoot )
        {
            if ( !isExportNode )
            {
                animationExport = false;
            }
        }

        // The COLLADA Node
        COLLADASW::Node* colladaSceneNode = NULL;

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
                        colladaSceneNode = new COLLADASW::Node ( mDocumentExporter->getStreamWriter(), hasPreviousInstance );
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
                    COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
                    colladaSceneNode = new COLLADASW::Node ( streamWriter, hasPreviousInstance );
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

        // Export type-specific information
        MFn::Type type = dagPath.apiType();
        switch (type)
        {
        case MFn::kLookAt:
        case MFn::kParentConstraint:
        case MFn::kOrientConstraint:
        case MFn::kConstraint:
        case MFn::kAimConstraint:
        case MFn::kPoleVectorConstraint:
        case MFn::kPointConstraint:
        case MFn::kNormalConstraint:
            MGlobal::displayError ( "Export of constraints not supported: " 
                + MString ( sceneElement->getNodeName ().c_str () ) );
            break;

        case MFn::kAmbientLight:
        case MFn::kSpotLight:
        case MFn::kPointLight:
        case MFn::kDirectionalLight:
            break;

        case MFn::kMesh:
            break;

        case MFn::kIkHandle:
            if ( ExportOptions::exportJointsAndSkin() )
            {
                MGlobal::displayError ( "Export of ik handles not supported: " 
                    + MString ( sceneElement->getNodeName ().c_str () ) );
            }
            break;

        case MFn::kCamera:
            break;

        case MFn::kRigid:
            if ( ExportOptions::exportPhysics() )
            {
                MGlobal::displayError ( "Export of physics not supported: "
                    + MString ( sceneElement->getNodeName ().c_str () ) );
            }
            break;

        case MFn::kNurbsCurve:
            {
                MGlobal::displayError ( "Export of spline not supported: " 
                    + MString ( sceneElement->getNodeName ().c_str () ) );
            }
            break;
        case MFn::kNurbsSurface:
            {
                MGlobal::displayError ( "Export of nurbs not supported: "
                    + MString ( sceneElement->getNodeName ().c_str () ) );
            }
            break;
        case MFn::kEmitter:
            {
                MGlobal::displayError ( "Export of emitters not supported: "
                    + MString ( sceneElement->getNodeName ().c_str () ) );
            }
            break;
        case MFn::kAir:
        case MFn::kDrag:
        case MFn::kField:
        case MFn::kGravity:
        case MFn::kNewton:
        case MFn::kRadial:
        case MFn::kTurbulence:
        case MFn::kUniform:
        case MFn::kVortex:
        case MFn::kVolumeAxis:
            {
                MGlobal::displayError ( "Could not export. Unknown node type: " 
                    + MString ( sceneElement->getNodeName ().c_str () ) );
            }
            break;
        default: break;
        }

        // Check if the element isn't already exported
        if ( isLocal && !hasPreviousInstance )
        {
            // Recursive call for all the child elements
            for ( uint i=0; i<sceneElement->getChildCount(); ++i )
            {
                SceneElement* childElement = sceneElement->getChild ( i );
                exportVisualSceneNodes ( childElement );
            }
        }

        // Close the visual scene tag in the collada document
        if ( colladaSceneNode != NULL )
        {
            if ( nodeExported )
            {
                // Write the extra technique tags in the collada document
                colladaSceneNode->addExtraTechniques ( mSW );

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
        COLLADASW::Node *sceneNode,
        const SceneElement* sceneElement )
    {
        // Set the type of the node to a joint
        sceneNode->setType ( COLLADASW::Node::JOINT );

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
        sceneNode->addExtraTechniqueParameter ( COLLADASW::CSWC::CSW_PROFILE_MAYA,
                                                MAYA_SEGMENTSCALECOMP_PARAMETER,
                                                segmentScaleCompensate );

        // Export the node
        return exportVisualSceneNode ( sceneNode, sceneElement );
    }

    //------------------------------------------------------
    bool VisualSceneExporter::exportNodeVisualSceneNode (
        COLLADASW::Node *sceneNode,
        const SceneElement* sceneElement )
    {
        // Set the type of the node
        sceneNode->setType ( COLLADASW::Node::NODE );

        // Export the node
        return exportVisualSceneNode ( sceneNode, sceneElement );
    }

    //---------------------------------------------------------------
    bool VisualSceneExporter::exportVisualSceneNode (
        COLLADASW::Node* sceneNode,
        const SceneElement* sceneElement )
    {
        // Set the visual scene node
        mVisualSceneNode = sceneNode;

        // Get the dagPath from the scene element
        MDagPath dagPath = sceneElement->getPath();

        // Flag, if the node is already instantiated
        bool isInstanceNode = mVisualSceneNode->getIsInstanceNode();

        // False, if the node has a external reference.
        bool isLocal = sceneElement->getIsLocal();

        // Do all the stuff if we export a full node.
        if ( !isInstanceNode && isLocal )
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
        }

        // Prepares the visual scene node
        // (open the visual scene node o a node instance, if we need this).
        openVisualSceneNode ( sceneElement );

        if ( !isLocal )
        {
            // Export the node external reference
            exportNodeInstance ( sceneElement );
        }
        else if ( !isInstanceNode )
        {
            // Do all the stuff if we export a full node.

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

            // Write the instance urls of the geometries, controllers
            // and lights into the collada document.
            exportChildNodeInstances(sceneElement);
        }

        return true;
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportMaterialList(
        COLLADASW::InstanceMaterialList &instanceMaterialList,
        const MDagPath &dagPath )
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
        uint numShaders = ( uint ) std::max ( ( size_t ) 1, ( size_t ) shaders.length() );
        for ( uint shaderPosition = 0; shaderPosition < numShaders; ++shaderPosition )
        {
            if ( shaderPosition < realShaderCount )
            {
                // Add shader-specific parameters (TexCoords sets).
                // Add symbolic name for the material used on this polygon set.
                MObject shadingEngine = shaders[shaderPosition];
                MFnDependencyNode shadingEngineFn ( shadingEngine );
                String shadingEngineName = shadingEngineFn.name().asChar();
                String materialName = DocumentExporter::mayaNameToColladaName ( shadingEngineFn.name() );

                MStatus status;
                uint instanceNumber = dagPath.instanceNumber( &status ); CHECK_STAT( status );

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
                MFnDependencyNode shaderNode ( shader );
                String materialId = DocumentExporter::mayaNameToColladaName ( shaderNode.name(), true );

                COLLADASW::InstanceMaterial materialInstance ( materialName, COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, materialId ) );
                instanceMaterialList.push_back ( materialInstance );
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
            String visualSceneName = COLLADABU::Utils::checkNCName( mSceneId );
            openVisualScene ( VISUAL_SCENE_NODE_ID, visualSceneName );
            mVisualSceneAdded = true;
        }

        bool isInstanceNode = mVisualSceneNode->getIsInstanceNode();
        if ( isInstanceNode )
        {
            // Get the URL of the instantiated visual scene node
            SceneElement* instantiatedSceneElement = sceneElement->getInstantiatedSceneElement();
            MDagPath instantiatedDagPath = instantiatedSceneElement->getPath();

            // Set the node URL
            String instanceNodeURL = mDocumentExporter->dagPathToColladaId ( instantiatedDagPath );
            mVisualSceneNode->setNodeURL ( COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, instanceNodeURL ) );
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

        if ( !COLLADABU::Math::Utils::equals( shear[0], 0.0 ) )
        {
            double angle = COLLADABU::Math::Utils::radToDeg ( atan ( shear[0] ) );
            angle = COLLADABU::Math::Utils::equalsZero( angle ) ? 0 : angle;
            float* rotateAxis ( xAxis );
            float* aroundAxis ( yAxis );

            mVisualSceneNode->addSkew ( SKEW_XY_SID, (float) angle, rotateAxis, aroundAxis );
        }

        if ( !COLLADABU::Math::Utils::equals( shear[1], 0.0 ) )
        {
            double angle = COLLADABU::Math::Utils::radToDeg ( atan ( shear[1] ) );
            angle = COLLADABU::Math::Utils::equalsZero( angle ) ? 0 : angle;
            float* rotateAxis ( xAxis );
            float* aroundAxis ( zAxis );

            mVisualSceneNode->addSkew ( SKEW_XZ_SID, (float) angle, rotateAxis, aroundAxis );
        }

        if ( !COLLADABU::Math::Utils::equals( shear[2], 0.0 ) )
        {
//            double angle = COLLADABU::Math::Utils::radToDeg ( atan ( shear[2] ) );
            double angle = MAngle::internalToUI ( atan ( shear[2] ) );
            angle = COLLADABU::Math::Utils::equalsZero( angle ) ? 0 : angle;
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
                COLLADABU::Math::Utils::equalsZero( translation.x ) ? 0 : MDistance::internalToUI ( translation.x ),
                COLLADABU::Math::Utils::equalsZero( translation.y ) ? 0 : MDistance::internalToUI ( translation.y ),
                COLLADABU::Math::Utils::equalsZero( translation.z ) ? 0 : MDistance::internalToUI ( translation.z ) );

            if ( animation )
            {
                AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
                animationExporter->addNodeAnimation ( mDagPath.node(), ATTR_TRANSLATE, name, ( SampleType ) ( kVector | kLength ), XYZ_PARAMETERS, true );
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
        std::vector < std::vector < double > >& matrixRotate = rotateHelper.getRotationMatrix ();
        std::vector < String >& rotateParams = rotateHelper.getRotationParameters ();

        // Set zero flags, where the rotation is zero. The order of rotation is ZYX.
        bool isZero[3] = {  COLLADABU::Math::Utils::equals( matrixRotate[0][3], 0.0 ),
                            COLLADABU::Math::Utils::equals( matrixRotate[1][3], 0.0 ),
                            COLLADABU::Math::Utils::equals( matrixRotate[2][3], 0.0 ) };

        // Get a pointer to the animation exporter.
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();

        // The array for the animations.
        bool isAnimated[3] = { false, false, false };

        // Go through the axes for the animations.
        for ( uint i=0; i<3; ++i )
        {
            // Add the animation in the order XYZ
            isAnimated[i] = animationExporter->addNodeAnimation ( mTransformObject, name + rotateParams[i], ( SampleType ) ( kSingle | kQualifiedAngle ), ANGLE_PARAMETER );
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
                    COLLADABU::Math::Utils::equalsZero( matrixRotate[i][0] ) ? 0 : matrixRotate[i][0],
                    COLLADABU::Math::Utils::equalsZero( matrixRotate[i][1] ) ? 0 : matrixRotate[i][1],
                    COLLADABU::Math::Utils::equalsZero( matrixRotate[i][2] ) ? 0 : matrixRotate[i][2],
                    COLLADABU::Math::Utils::equalsZero( matrixRotate[i][3] ) ? 0 : matrixRotate[i][3] );
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
        MPlug plug = MFnDagNode ( mTransformObject ).findPlug ( ATTR_MATRIX );
        mDocumentExporter->getAnimationCache()->cachePlug ( plug, true );

        // Export the animations
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
        animationExporter->addPlugAnimation ( plug, ATTR_TRANSFORM, kMatrix, TRANSFORM_PARAMETER );
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
                COLLADABU::Math::Utils::equalsZero( matrix[3][0] ) ? 0.0f : (float) matrix[3][0],
                COLLADABU::Math::Utils::equalsZero( matrix[3][1] ) ? 0.0f : (float) matrix[3][1],
                COLLADABU::Math::Utils::equalsZero( matrix[3][2] ) ? 0.0f : (float) matrix[3][2] };

            // Compute center of interest.
            double centerOfInterestDistance = camera.centerOfInterestPoint ( MSpace::kObject ).z;
            MVector front ( matrix[2][0], matrix[2][1], matrix[2][2] );
            MVector centerOfInterest = eye + ( front * centerOfInterestDistance );
            float interestPosition[3] = {
                COLLADABU::Math::Utils::equalsZero( centerOfInterest.x ) ? 0.0f : (float) centerOfInterest.x,
                COLLADABU::Math::Utils::equalsZero( centerOfInterest.y ) ? 0.0f : (float) centerOfInterest.y,
                COLLADABU::Math::Utils::equalsZero( centerOfInterest.z ) ? 0.0f : (float) centerOfInterest.z };

            // Extract the up direction, which corresponds to the second row.
            float upPosition[3] = {
                COLLADABU::Math::Utils::equalsZero( matrix[1][0] ) ? 0.0f : (float) matrix[1][0],
                COLLADABU::Math::Utils::equalsZero( matrix[1][1] ) ? 0.0f : (float) matrix[1][1],
                COLLADABU::Math::Utils::equalsZero( matrix[1][2] ) ? 0.0f : (float) matrix[1][2] };

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
            if ( !COLLADABU::Math::Utils::equals( scale[i], 1.0 ) ) isOneVector = false;
        }

        // Check if the scale is animated.
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
        bool isAnimated = animationExporter->addNodeAnimation ( mTransformObject, ATTR_SCALE, kVector, XYZ_PARAMETERS );

        if ( mTransformObject != MObject::kNullObj && ( !isOneVector || isAnimated ) )
        {
            mVisualSceneNode->addScale (
                ATTR_SCALE,
                COLLADABU::Math::Utils::equalsZero(scale[0]) ? 0 : scale[0],
                COLLADABU::Math::Utils::equalsZero(scale[1]) ? 0 : scale[1],
                COLLADABU::Math::Utils::equalsZero(scale[2]) ? 0 : scale[2] );
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportVisibility ( COLLADASW::Node* sceneNode )
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
                    sceneNode->addExtraTechniqueParameter ( COLLADASW::CSWC::CSW_PROFILE_COLLADA, ATTR_VISIBILITY, isVisible );

                    AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
                    animationExporter->addNodeAnimation ( mTransformObject, ATTR_VISIBILITY, kBoolean );
                }
            }
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportControllerInstance(
        SceneElement* sceneElement,
        const bool hasSkinController,
        const bool hasMorphController )
    {
        // Get the streamWriter from the export document
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the path and the id of the child element
        MDagPath dagPath = sceneElement->getPath();

        // Create the unique controller ID
        String controllerId;
        if ( !sceneElement->getNodeId().empty() )
            controllerId = sceneElement->getNodeId();
        else
          controllerId = sceneElement->getNodeName();

        if ( hasMorphController )
            controllerId += COLLADASW::LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX;
        if ( hasSkinController )
            controllerId += COLLADASW::LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;

        // Get the uri of the current scene
        COLLADASW::URI uri ( getSceneElementURI ( sceneElement, controllerId  ) );

        // Create the collada controller instance
        COLLADASW::InstanceController instanceController ( streamWriter );
        instanceController.setUrl ( uri );

        // Set the skeletonId. It indicates where a skin
        // controller is to start to search for the joint nodes
        // it needs. This element is meaningless for morph controllers.

        // Get the skeleton id from the element
        const std::set<String>& skeletonIds = sceneElement->getSkeletonIds ();
        if ( skeletonIds.size () > 0 )
        {
            std::set<String>::const_iterator it = skeletonIds.begin ();
            while ( it != skeletonIds.end () )
            {
                instanceController.addSkeleton ( COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, *it ) );
                ++it;
            }
        }

        // Write all materials
        COLLADASW::InstanceMaterialList& instanceMaterialList =
            instanceController.getBindMaterial().getInstanceMaterialList();

        // Export the materials
        exportMaterialList ( instanceMaterialList, dagPath );

        instanceController.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportGeometryInstance( SceneElement* sceneElement )
    {
        // Get the streamWriter from the export document
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the path and the id of the element
        MDagPath dagPath = sceneElement->getPath();
        String geometryId = sceneElement->getNodeId();
        if ( geometryId.empty() )
            geometryId = sceneElement->getNodeName();

        // Get the uri of the current scene
        COLLADASW::URI uri ( getSceneElementURI ( sceneElement, geometryId  ) );

        // Write the geometry instance
        COLLADASW::InstanceGeometry instanceGeometry ( streamWriter );
        instanceGeometry.setUrl ( uri );
//        instanceGeometry.setUrl ( COLLADASW::URI ( "", geometryId ) );

        // Write all materials
        COLLADASW::InstanceMaterialList& instanceMaterialList =
            instanceGeometry.getBindMaterial().getInstanceMaterialList();

        // Export the materials
        exportMaterialList ( instanceMaterialList, sceneElement->getPath() );

        instanceGeometry.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportLightInstance( const SceneElement* sceneElement )
    {
        // Get the streamWriter from the export document
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the uri of the current scene
        COLLADASW::URI uri ( getSceneElementURI ( sceneElement ) );

        // Create and write the light instance
        COLLADASW::InstanceLight instanceLight ( streamWriter, uri );
        instanceLight.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportCameraInstance( const SceneElement* sceneElement )
    {
        // Get the streamWriter from the export document
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the uri of the current scene
        COLLADASW::URI uri ( getSceneElementURI ( sceneElement ) );

        // Create and write the camera instance
        COLLADASW::InstanceCamera instanceCamera ( streamWriter, uri );
        instanceCamera.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportNodeInstance ( const SceneElement* sceneElement )
    {
        // Get the streamWriter from the export document
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the uri of the current scene
        COLLADASW::URI uri ( getSceneElementURI ( sceneElement ) );

        // Create and write the camera instance
        COLLADASW::InstanceNode instanceNode ( streamWriter, uri );
        instanceNode.add();
    }

    //---------------------------------------------------------------
    COLLADASW::URI VisualSceneExporter::getSceneElementURI (
        const SceneElement* sceneElement,
        const String& elementId /** = "" */ )
    {
        // Get the path of the element
        MDagPath dagPath = sceneElement->getPath();

        // Check if the element is instanced.
        uint instanceNumber = 0;
        if ( dagPath.isInstanced() )
        {
            SceneElement* exportedElement =
                mDocumentExporter->getSceneGraph()->findExportedElement( dagPath );
            dagPath = exportedElement->getPath();
        }

        // Get the Uri of the element.
        if ( !sceneElement->getIsLocal() )
        {
            // Load the external reference through the reference manager.
            String referenceFilename = ReferenceManager::getReferenceFilename( dagPath ).asChar();
            return COLLADASW::URI ( COLLADASW::URI::nativePathToUri ( referenceFilename ) );
        }
        else
        {
            // Get the id of the element
            if ( !elementId.empty() )
                return COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, elementId );
            else return COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, mDocumentExporter->dagPathToColladaId ( dagPath ) );
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportChildNodeInstances( const SceneElement* sceneElement )
    {
        // Check the geometry instances, which use this visual scene
        size_t childCount = sceneElement->getChildCount();
        for ( size_t i=0; i<childCount; ++i )
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

}
