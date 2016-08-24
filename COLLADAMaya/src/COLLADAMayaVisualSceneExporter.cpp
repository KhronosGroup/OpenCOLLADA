/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADAMayaMaterialExporter.h"
#include "COLLADAMayaLightExporter.h"
#include "COLLADAMayaLightProbeExporter.h"
#include "COLLADAMayaCameraExporter.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaPhysicsExporter.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaAttributeParser.h"

#include <maya/MFnIkHandle.h>
#include <maya/MFnSkinCluster.h>
#include <maya/MItDag.h>
#include <maya/MFnIkJoint.h>
#include <maya/MQuaternion.h>
#include <maya/MEulerRotation.h>
#include <maya/MDagPath.h>
#include <maya/MFnCamera.h>
#include <maya/MFileIO.h>
#include <maya/MFnAttribute.h>

#include "COLLADASWNode.h"
#include "COLLADASWInstanceGeometry.h"
#include "COLLADASWInstanceController.h"
#include "COLLADASWLibraryControllers.h"
#include "COLLADASWInstanceLight.h"
#include "COLLADASWInstanceCamera.h"
#include "COLLADASWInstanceNode.h"
#include "COLLADASWConstants.h"
#include "COLLADASWExtraTechnique.h"

#include "Math/COLLADABUMathUtils.h"

#include "assert.h"


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    VisualSceneExporter::VisualSceneExporter (
        COLLADASW::StreamWriter* streamWriter,
        DocumentExporter* documentExporter,
        const String& sceneId )
    : COLLADASW::LibraryVisualScenes ( streamWriter )
    , mDocumentExporter ( documentExporter )
    , mSceneId ( sceneId )
    , mIsJoint ( false )
    , mIsFirstRotation ( true )
    , mVisualSceneAdded ( false )
    , mVisualSceneNode ( NULL )
	, mLODIndexCounter1(0)
	, mLODIndexCounter2(0)
    {
    }

	VisualSceneExporter::~VisualSceneExporter()
	{
		lodCounterMap.clear();
	}


    // ------------------------------------------------------------
    bool VisualSceneExporter::exportVisualScenes()
    {
        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // The flag, if a node was exported and the visual scene tags must to be closed
        bool nodeExported = false;

        // Export all/selected DAG nodes
        size_t length = exportNodesTree->size();
        for ( size_t i = 0; i < length; ++i )
        {
            // No instance node under the visual scene!
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

        // If the element is a root element and it is instanced, we have to try to set 
        bool isInstance = dagPath.isInstanced ();
        bool hasPreviousInstance =  ( instantiatedSceneElement != NULL );
        if ( hasPreviousInstance )
        {
            sceneElement->setInstantiatedSceneElement ( instantiatedSceneElement );
        }

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
		bool isPhysicsNode = sceneElement->getIsPhysicsNode();

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
		SceneElement::Type sceneElementType = sceneElement->getType();
		bool isTransform = dagPath.hasFn ( MFn::kTransform );
	
		bool doExport = true;

		// Do export LOD Group Node only during "NO_PASS" (in library_visual_scenes)
		if ((mDocumentExporter->mExportPass != VISUAL_SCENE_PASS && sceneElementType == SceneElement::LOD))
			doExport = false;
		
		mLODIndexCounter1 = 1;

		if (sceneElement->getParentCount())
		{
			SceneElement::Type sceneParentElementType = sceneElement->getParent()->getType();
			if ((mDocumentExporter->mExportPass == VISUAL_SCENE_PASS && sceneParentElementType == SceneElement::LOD))
			{
				
				std::map<SceneElement*, int>::iterator iterator = lodCounterMap.find(sceneElement->getParent());
				if (iterator != lodCounterMap.end())
					mLODIndexCounter1 = ++iterator->second;
				else
					lodCounterMap.insert(std::make_pair(sceneElement->getParent(), mLODIndexCounter1));
			}
				

			if (mDocumentExporter->mExportPass == SECOND_LOD_PASS && sceneParentElementType == SceneElement::LOD)
				mLODIndexCounter2++;
		}

		bool ContinueExport = false;

		// DO export only from second LOD Node during "LOD second Pass" (in library_nodes)
		if (mDocumentExporter->mExportPass == SECOND_LOD_PASS && mLODIndexCounter2 > 1)
			ContinueExport = true;

		// Do export only first LOD Node during "NO_PASS" (in library_visual_scenes)
		if ((ExportOptions::exportLOD() && (mDocumentExporter->mExportPass != SECOND_LOD_PASS && isTransform && doExport && mLODIndexCounter1 < 2)) || (!ExportOptions::exportLOD() && isTransform))
			ContinueExport = true;

		if (ContinueExport)
	    {
            // Taken out of unvisible transforms. 
			if ((!ExportOptions::exportInvisibleNodes() && !isVisible && !isExportNode) || (ExportOptions::exportPhysics() && isPhysicsNode)) return false;

            // Export the scene graph node for all transform-derivatives
            if ( dagPath.hasFn ( MFn::kJoint ) )
            {
                sceneElement->setHasJoint(true);
				if (ExportOptions::exportJoints())
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
                // Just local export
				if (!isForced && !isLocal && !ExportOptions::exportXRefs()) return false;

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
			if (ExportOptions::exportJoints())
            {
                MGlobal::displayError ( "Export of ik handles not supported: " 
                    + MString ( sceneElement->getNodeName ().c_str () ) );
            }
            break;

        case MFn::kCamera:
            break;

        case MFn::kRigid:
            //if ( ExportOptions::exportPhysics() )
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

        // Check if the element is a local element and isn't already exported.
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
        SceneElement* sceneElement )
    {
        // Set the type of the node to a joint
        sceneNode->setType ( COLLADASW::Node::JOINT );

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();
        MObject node = dagPath.node();

        // Generate a COLLADA sid for the new object
        String nodeSid = mDocumentExporter->dagPathToColladaSid(dagPath);
        sceneNode->setNodeSid( nodeSid );

//         // Export the segment-scale-compensate flag.
//         bool segmentScaleCompensate;
//         DagHelper::getPlugValue ( dagPath.transform(),
//                                   ATTR_SEGMENT_SCALE_COMPENSATE,
//                                   segmentScaleCompensate );
// 
//         // Not animateable
//         sceneNode->addExtraTechniqueParameter ( PROFILE_MAYA,
//                                                 MAYA_SEGMENTSCALECOMP_PARAMETER,
//                                                 segmentScaleCompensate );

        // Export the node
        return exportVisualSceneNode ( sceneNode, sceneElement );
    }

    //------------------------------------------------------
    bool VisualSceneExporter::exportNodeVisualSceneNode (
        COLLADASW::Node *sceneNode,
        SceneElement* sceneElement )
    {
        // Set the type of the node
        sceneNode->setType ( COLLADASW::Node::NODE );

        // Export the node
        return exportVisualSceneNode ( sceneNode, sceneElement );
    }

    //---------------------------------------------------------------
    bool VisualSceneExporter::exportVisualSceneNode (
        COLLADASW::Node* sceneNode,
        SceneElement* sceneElement )
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
		if (!isInstanceNode || mDocumentExporter->mExportPass == SECOND_LOD_PASS)
        {
            // Initialize the member variables
            if ( !initializeTransform ( sceneElement ) )
            {
                MString pathName = dagPath.fullPathName();
                MString message = "Could not initialize the transform object of the path " + pathName;
                MGlobal::displayError( message );
                return false;
            }
        }

        // Prepares the visual scene node
        // (open the visual scene node o a node instance, if we need this).
		if (!openVisualSceneNode(sceneElement))
			return false;


		bool exportTransformation = false;
		if (mDocumentExporter->mExportPass == VISUAL_SCENE_PASS)
		{
			if (!isLocal || !isInstanceNode)
				exportTransformation = true;
		}
		else
		{
			if (sceneElement->getType() != SceneElement::LOD)
			{
				// Do export Transformation for LOD node only during 2nd Pass Library node 
				SceneElement::Type sceneParentElementType = sceneElement->getParent()->getType();
				if ((mDocumentExporter->mExportPass == SECOND_LOD_PASS && sceneParentElementType == SceneElement::LOD))
					exportTransformation = false;
				else
					exportTransformation = true;
			}
		}
			
		if (exportTransformation)
		{
			// Export the transformation information
			if (ExportOptions::bakeTransforms())
			{
				exportMatrixTransform();
			}
			else if (ExportOptions::exportCameraAsLookat() && dagPath.hasFn(MFn::kCamera))
			{
				exportLookatTransform();
			}
			else
			{
				exportDecomposedTransform();
			}
			
			// Exports the visibility technique tag and the visibility animation.
			exportVisibility(sceneNode);
		}


		if (!isLocal || mDocumentExporter->mExportPass == SECOND_LOD_PASS ||
			(mDocumentExporter->mExportPass == VISUAL_SCENE_PASS && (ExportOptions::exportLOD() && (sceneElement->getParentCount() > 0 && sceneElement->getParent()->getType() == SceneElement::LOD))))
        {
            // Export the node external reference
            exportInstanceNode ( sceneElement );
        }
        else if ( !isInstanceNode )
        {
            // Write the instance urls of the geometries, controllers
            // and lights into the collada document.
            exportInstanceChildNodes ( sceneElement );
        }

        return true;
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportInstanceMaterial (
        COLLADASW::InstanceMaterialList &instanceMaterialList,
        const MDagPath &dagPath )
    {
        MaterialExporter* materialExporter = mDocumentExporter->getMaterialExporter ();
        EffectExporter* effectExporter = mDocumentExporter->getEffectExporter ();

        // Find how many shaders are used by this instance of the mesh
        const MObject& meshNode = dagPath.node();
        MFnMesh fnMesh ( meshNode );

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
                String shadingEngineName = DocumentExporter::mayaNameToColladaName ( shadingEngineFn.name() );

                // Check if the current mesh has some polygons for the connected shader.
                // If not, we don't need to write the current material instance.
                if ( !meshContainsShaderPolygons ( meshNode, shaders, shaderIndices, shaderPosition ) ) continue;

                // To get the right shader name, we have to take the correct mesh instance.
                MStatus status;
                uint instanceNumber = dagPath.instanceNumber( &status ); CHECK_STAT( status );
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
                String mayaMaterialId = DocumentExporter::mayaNameToColladaName ( shaderNode.name(), true );
                const String& colladaMaterialId = materialExporter->findColladaMaterialId ( mayaMaterialId );
                
                // Create the material instance object.
				COLLADASW::InstanceMaterial materialInstance(shadingEngineName, COLLADASW::URI(EMPTY_STRING, colladaMaterialId));

                // Retrieve all the file textures with the blend modes, if exist.
                MObjectArray fileTextures;
                MIntArray blendModes;
                effectExporter->getShaderTextures ( shader, ATTR_OUT_COLOR, fileTextures, blendModes );
                effectExporter->getShaderTextures ( shader, ATTR_INCANDESCENCE, fileTextures, blendModes );
                effectExporter->getShaderTextures ( shader, ATTR_AMBIENT_COLOR, fileTextures, blendModes );
                effectExporter->getShaderTextures ( shader, ATTR_COLOR, fileTextures, blendModes );
                effectExporter->getShaderTextures ( shader, ATTR_NORMAL_CAMERA, fileTextures, blendModes );
                effectExporter->getShaderTextures ( shader, ATTR_SPECULAR_COLOR, fileTextures, blendModes );
                effectExporter->getShaderTextures ( shader, ATTR_REFLECTED_COLOR, fileTextures, blendModes );
                effectExporter->getShaderTextures ( shader, ATTR_OUT_TRANSPARENCY, fileTextures, blendModes );
                effectExporter->getShaderTextures ( shader, ATTR_TRANSPARENCY, fileTextures, blendModes );
                uint fileTextureCount = fileTextures.length();

                // Check if the current material instance uses a texcoord binding.
                MPlug uvSetMainPlug = MFnDependencyNode ( meshNode ).findPlug ( ATTR_UV_SET );
                for (uint i = 0; i < fileTextureCount; ++i)
                {
                    // Get the current file texture.
                    const MObject& fileTexture = fileTextures[i];

                    // Retrieve the UV set index for this texture
                    uint uvSetIndex = ShaderHelper::getAssociatedUVSet ( meshNode, fileTexture );

                    // Retrieve the name for this UV set and match it with a DAE source.
                    MPlug uvSetPlug = uvSetMainPlug.elementByPhysicalIndex ( uvSetIndex, &status );
                    if (status != MStatus::kSuccess) continue;
                    MPlug uvSetNamePlug = DagHelper::getChildPlug ( uvSetPlug, ATTR_UV_SET_NAME ); // "uvSetName"
                    MString uvSetName; uvSetNamePlug.getValue(uvSetName);
                    if (uvSetName.length() == 0) continue;

                    // Generate the name of the texture coordinates.
                    String texCoordName = EffectExporter::TEXCOORD_BASE + COLLADASW::Utils::toString ( i );
                    COLLADASW::BindVertexInput bindVertexInput ( texCoordName, COLLADASW::CSWC::CSW_SEMANTIC_TEXCOORD, uvSetIndex );
                    materialInstance.push_back ( bindVertexInput );
                }

                instanceMaterialList.push_back ( materialInstance );
            }
        }
    }

    //---------------------------------------------------------------
    const bool VisualSceneExporter::meshContainsShaderPolygons ( 
        const MObject& mesh, 
        const MObjectArray& shaders, 
        const MIntArray& shaderIndices, 
        const uint shaderPosition )
    {
        // Iterate through all polygons of the current mesh.
        MItMeshPolygon meshPolygonsIter ( mesh );
        for ( meshPolygonsIter.reset(); !meshPolygonsIter.isDone(); meshPolygonsIter.next() )
        {
            // Is this polygon shaded by this shader?
            int polyIndex = meshPolygonsIter.index();
            uint realShaderCount = ( uint ) shaders.length();
            if ( shaderPosition < realShaderCount &&
                ( uint ) shaderIndices[polyIndex] != shaderPosition ) continue;
            if ( shaderPosition >= realShaderCount &&
                ( shaderIndices[polyIndex] >= 0 &&
                shaderIndices[polyIndex] < ( int ) realShaderCount ) ) continue;

            // Polygons for the current shader found.
            return true;
        }

        // No polygons for the current shader.
        return false;
    }

	static float GetThresholdPlugValue(const SceneElement* sceneElement, int indexLOD)
	{

		// Add Threshold value To switch to Next LOD Node
		double threshold = -1;
		MDagPath dagPath;

		SceneElement::Type sceneElementType = sceneElement->getType();
		if (sceneElementType == SceneElement::LOD)
			dagPath = sceneElement->getPath();
		else
			dagPath = sceneElement->getParent()->getPath();

		MStatus status;
		MObject transformNode = dagPath.transform(&status);

		MPlug plugThreshold = MFnDependencyNode(transformNode).findPlug(ATTR_THRESHOLD, &status);
		if (status == MStatus::kSuccess)
		{

			char indexLODString[50];
			sprintf(indexLODString, "%d", indexLOD);

			MPlug plug = plugThreshold.elementByPhysicalIndex(indexLOD, &status);

			String thresholdLOD = String(ATTR_THRESHOLD) + String("[") + String(indexLODString) + String("]");
			plug.getValue(threshold);
			threshold = MDistance::internalToUI(threshold);
		}
			
		return (float)threshold;
	}

    //---------------------------------------------------------------
    bool VisualSceneExporter::openVisualSceneNode ( const SceneElement* sceneElement )
    {
        // Get the dagPath from the scene element
        const MDagPath dagPath = sceneElement->getPath();

        // Add the visual scene, if not done before
		if (mDocumentExporter->mExportPass == VISUAL_SCENE_PASS)
		{
			if (!mVisualSceneAdded)
			{
				MString sceneName;
				MGlobal::executeCommand(MString("file -q -ns"), sceneName);
				if (sceneName.length() != 0) mSceneId = sceneName.asChar();

				// There is always just one visual scene. Give it a valid unique id.
				String visualSceneName = COLLADABU::Utils::checkNCName(mSceneId);
				openVisualScene(VISUAL_SCENE_NODE_ID, visualSceneName);
				mVisualSceneAdded = true;
			}
		}
        
        bool isInstanceNode = mVisualSceneNode->getIsInstanceNode();
        if ( isInstanceNode )
        {
            String mayaNodeId;

            // Get the URL of the instantiated visual scene node
            SceneElement* instantiatedSceneElement = sceneElement->getInstantiatedSceneElement();
            if ( instantiatedSceneElement != 0 )
            {
                MDagPath instantiatedDagPath = instantiatedSceneElement->getPath();
                mayaNodeId = mDocumentExporter->dagPathToColladaId ( instantiatedDagPath );
            }
            else
            {
                // The maya node id.
                mayaNodeId = mDocumentExporter->dagPathToColladaId ( dagPath );
            }

            String colladaNodeId = findColladaNodeId ( mayaNodeId );
            if ( colladaNodeId.empty () )
            {
                colladaNodeId = getColladaNodeId ( dagPath );
            }

            mVisualSceneNode->setNodeURL ( COLLADASW::URI ( EMPTY_STRING, colladaNodeId ) );

			if (mDocumentExporter->mExportPass == SECOND_LOD_PASS)
			{
				// Get the dag node.
				MFnDagNode node(dagPath.node());

				// The maya node id.
				String mayaNodeId = mDocumentExporter->dagPathToColladaId(dagPath);
				
				// Export the original maya name.
				mVisualSceneNode->setNodeId(String("LOD__") + mayaNodeId);
				mVisualSceneNode->setNodeName(mayaNodeId);

				//mVisualSceneNode->addExtraTechniqueParameter(PROFILE_MAYA, PARAMETER_MAYA_ID, mayaNodeId);
			}
        }
        else
        {
			// Get the dag node.
			MFnDagNode node(dagPath.node());

			// The maya node id.
			String mayaNodeId = mDocumentExporter->dagPathToColladaId(dagPath);

			// Generate a COLLADA id for the new object.
			String colladaNodeId = getColladaNodeId(dagPath);

			// Make the id unique and store it in a map.
			colladaNodeId = mNodeIdList.addId(colladaNodeId, mDocumentExporter->mExportPass == VISUAL_SCENE_PASS ? false : true);

			mMayaIdColladaNodeId[mayaNodeId] = colladaNodeId;

			// Set the node id and the name.
			mVisualSceneNode->setNodeId(colladaNodeId);
			String nodeName = mDocumentExporter->dagPathToColladaName(dagPath);

			mVisualSceneNode->setNodeName(nodeName);
			
			mVisualSceneNode->addExtraTechniqueParameter(PROFILE_MAYA, PARAMETER_MAYA_ID, nodeName);   
        }

		exportExtraAttributes(sceneElement);

        // TODO Export the imported extra tags, if there exist some.
        

        // open the scene node

		bool lodPass = false;
		if (mDocumentExporter->mExportPass == SECOND_LOD_PASS || mDocumentExporter->mExportPass == FIRST_LOD_PASS)
			lodPass = true;

		if (mDocumentExporter->mExportPass == SECOND_LOD_PASS)
		{
			int indexLOD;
			String proxy = findNextColladaNodeId(sceneElement, indexLOD);
			if (proxy.compare(EMPTY_STRING) == 0)
				return false;

		}

		mVisualSceneNode->start(lodPass);
		return true;
    }

    //---------------------------------------------------------------
    bool VisualSceneExporter::initializeTransform ( SceneElement* sceneElement )
    {
        // Get the dagPath from the scene element
        MDagPath dagPath = sceneElement->getPath();
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

        // Get the transforms local translation
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

        // Skins being exported from maya need to have the bindpose matrix 
        // subtracted from the instance matrix.
        bool oneSkinAlready = false;

        // Check the child instances, which use this visual scene node.
        size_t childCount = sceneElement->getChildCount();
        for ( size_t i=0; i<childCount && !oneSkinAlready; ++i )
        {
            // Check if the child element is a mesh object and an export node
            SceneElement* childElement = sceneElement->getChild ( i );
            if ( childElement->getType() == SceneElement::MESH &&
                childElement->getIsExportNode() )
            {
                // Get the controller library
                ControllerExporter* controller = mDocumentExporter->getControllerExporter();
                MObject childNode = childElement->getPath().node();
                bool hasSkinController = controller->hasSkinController ( childNode );
                if ( hasSkinController )
                {
                    // Skins being exported from maya need to have the bindpose matrix 
                    // subtracted from the instance matrix.
                    MMatrix bindShapeMatrix = childElement->getBindShapeMatrix ();
                    MMatrix transformMatrix = mTransformMatrix.asMatrix ();

                    // Calculate the world transform of the node.
                    MMatrix transformMx = bindShapeMatrix.inverse () * transformMatrix;

                    // Set the new calculated transform matrix 
                    mTransformMatrix = transformMx;
                    mTransformObject = MObject::kNullObj;

                    // Do it just once.
                    oneSkinAlready = true;
                }
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
        if ( mIsJoint ) exportRotation ( ATTR_ROTATE_AXIS, rotationAxis );

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

        if ( !COLLADABU::Math::Utils::equalsZero ( shear[0], getTolerance () ) )
        {
            double angle = COLLADABU::Math::Utils::radToDeg ( atan ( shear[0] ) );
            angle = COLLADABU::Math::Utils::equalsZero ( angle, getTolerance () ) ? 0 : angle;
            float* rotateAxis ( xAxis );
            float* aroundAxis ( yAxis );

            mVisualSceneNode->addSkew ( SKEW_XY_SID, (float) angle, rotateAxis, aroundAxis );

//             // Set the animation, if the skew is animated.
//             AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
//             animationExporter->addNodeAnimation ( mTransformObject, ATTR_SKEW, ( SampleType ) ( kSingle | kQualifiedAngle ), XY_PARAMETER );
        }

        if ( !COLLADABU::Math::Utils::equalsZero ( shear[1], getTolerance () ) )
        {
            double angle = COLLADABU::Math::Utils::radToDeg ( atan ( shear[1] ) );
            angle = COLLADABU::Math::Utils::equalsZero( angle, getTolerance () ) ? 0 : angle;
            float* rotateAxis ( xAxis );
            float* aroundAxis ( zAxis );

            mVisualSceneNode->addSkew ( SKEW_XZ_SID, (float) angle, rotateAxis, aroundAxis );

//             // Set the animation, if the skew is animated.
//             AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
//             animationExporter->addNodeAnimation ( mTransformObject, ATTR_SKEW, ( SampleType ) ( kSingle | kQualifiedAngle ), XZ_PARAMETER );
        }

        if ( !COLLADABU::Math::Utils::equalsZero ( shear[2], getTolerance () ) )
        {
            double angle = MAngle::internalToUI ( atan ( shear[2] ) );
            angle = COLLADABU::Math::Utils::equalsZero( angle, getTolerance () ) ? 0 : angle;
            float* rotateAxis ( yAxis );
            float* aroundAxis ( zAxis );

            mVisualSceneNode->addSkew ( SKEW_YZ_SID, (float) angle, rotateAxis, aroundAxis );

//             // Set the animation, if the skew is animated.
//             AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
//             animationExporter->addNodeAnimation ( mTransformObject, ATTR_SKEW, ( SampleType ) ( kSingle | kQualifiedAngle ), YZ_PARAMETER );
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportScale()
    {
        // Get the scale.
        double scale[3] = {1, 1, 1};
        mTransformMatrix.getScale ( scale, MSpace::kTransform );

        // Check if all fields in the std::vector are ones
        bool isOneVector = true;
        for ( int i=0; i<3 && isOneVector; ++i )
        {
            if ( !COLLADABU::Math::Utils::equals( scale[i], 1.0, getTolerance () ) ) isOneVector = false;
        }

        // Check if the scale is animated.
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
        bool isAnimated = animationExporter->addNodeAnimation ( mTransformObject, ATTR_SCALE, kVector, XYZ_PARAMETERS );

        if ( mTransformObject != MObject::kNullObj || ( !isOneVector || isAnimated ) )
        {
            mVisualSceneNode->addScale (
                ATTR_SCALE,
                COLLADABU::Math::Utils::equalsZero ( scale[0], getTolerance () ) ? 0 : scale[0],
                COLLADABU::Math::Utils::equalsZero ( scale[1], getTolerance () ) ? 0 : scale[1],
                COLLADABU::Math::Utils::equalsZero ( scale[2], getTolerance () ) ? 0 : scale[2] );
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportTranslation ( 
        const String name,
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
                COLLADABU::Math::Utils::equalsZero( translation.x, getTolerance () ) ? 0 : MDistance::internalToUI ( translation.x ),
                COLLADABU::Math::Utils::equalsZero( translation.y, getTolerance () ) ? 0 : MDistance::internalToUI ( translation.y ),
                COLLADABU::Math::Utils::equalsZero( translation.z, getTolerance () ) ? 0 : MDistance::internalToUI ( translation.z ) );

            if ( animation )
            {
                AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
                animationExporter->addNodeAnimation ( mDagPath.node(), ATTR_TRANSLATE, name, ( SampleType ) ( kVector | kLength ), XYZ_PARAMETERS, true );
            }
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportRotation ( 
        const String name, 
        const MEulerRotation& rotation )
    {
        RotateHelper rotateHelper ( rotation );
        std::vector<std::vector<double> >& matrixRotate = rotateHelper.getRotationMatrix ();
        std::vector<String>& rotateParams = rotateHelper.getRotationParameters ();

        // Set zero flags, where the rotation is zero. The order of rotation is ZYX.
        bool isZero[3] = {  COLLADABU::Math::Utils::equalsZero ( matrixRotate[0][3], getTolerance () ),
                            COLLADABU::Math::Utils::equalsZero ( matrixRotate[1][3], getTolerance () ),
                            COLLADABU::Math::Utils::equalsZero ( matrixRotate[2][3], getTolerance () ) };

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
            bool rotationIsNecessary = false;

            // Check, if we have to write the rotation.
            if ( mIsJoint && COLLADABU::Utils::equalsIgnoreCase ( name, ATTR_JOINT_ORIENT )) 
            {
                // A joint must always have a rotation.
                rotationIsNecessary = true;
            }
            else 
            {
                // You have to write the rotation, if the element is animated.
                rotationIsNecessary = ( isAnimated[i] || !( !mIsFirstRotation && isZero[i] ));
            }

            if ( mTransformObject != MObject::kNullObj && rotationIsNecessary )
            {
                // Add the rotation in the order ZYX
                mVisualSceneNode->addRotate (
                    name + rotateParams[i],
                    COLLADABU::Math::Utils::equalsZero( matrixRotate[i][0], getTolerance () ) ? 0 : matrixRotate[i][0],
                    COLLADABU::Math::Utils::equalsZero( matrixRotate[i][1], getTolerance () ) ? 0 : matrixRotate[i][1],
                    COLLADABU::Math::Utils::equalsZero( matrixRotate[i][2], getTolerance () ) ? 0 : matrixRotate[i][2],
                    COLLADABU::Math::Utils::equalsZero( matrixRotate[i][3], getTolerance () ) ? 0 : matrixRotate[i][3] );
            }
        }

        mIsFirstRotation = false;
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportMatrixTransform()
    {
        MMatrix mayaSceneMatrix = mTransformMatrix.asMatrix();
        double sceneMatrix[4][4] ;
        convertMayaMatrixToTransposedDouble4x4 ( sceneMatrix, mayaSceneMatrix, getTolerance () );

        // Convert the  maya internal unit type of the transform part of the
        // matrix from centimeters into the working units of the current scene!
        for ( uint i=0; i<3; ++i)
            sceneMatrix [i][3] = MDistance::internalToUI ( sceneMatrix [i][3] );

        mVisualSceneNode->addMatrix ( ATTR_TRANSFORM, sceneMatrix );

        // For animations, sampling is always enforced for baked transforms.
        MPlug plug = MFnDagNode ( mTransformObject ).findPlug ( ATTR_MATRIX );
        mDocumentExporter->getAnimationCache()->cachePlug ( plug, true );

		MEulerRotation rotation;
		rotation.order = (MEulerRotation::RotationOrder) ((int)mTransformMatrix.rotationOrder() - MTransformationMatrix::kXYZ + MEulerRotation::kXYZ);

        // Export the animations
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
		animationExporter->addPlugAnimation(plug, ATTR_TRANSFORM, kMatrix, rotation.order, TRANSFORM_PARAMETER, true );
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
                COLLADABU::Math::Utils::equalsZero( matrix[3][0], getTolerance () ) ? 0.0f : (float) matrix[3][0],
                COLLADABU::Math::Utils::equalsZero( matrix[3][1], getTolerance () ) ? 0.0f : (float) matrix[3][1],
                COLLADABU::Math::Utils::equalsZero( matrix[3][2], getTolerance () ) ? 0.0f : (float) matrix[3][2] };

            // Compute center of interest.
            double centerOfInterestDistance = camera.centerOfInterestPoint ( MSpace::kObject ).z;
            MVector front ( matrix[2][0], matrix[2][1], matrix[2][2] );
            MVector centerOfInterest = eye + ( front * centerOfInterestDistance );
            float interestPosition[3] = {
                COLLADABU::Math::Utils::equalsZero( centerOfInterest.x, getTolerance () ) ? 0.0f : (float) centerOfInterest.x,
                COLLADABU::Math::Utils::equalsZero( centerOfInterest.y, getTolerance () ) ? 0.0f : (float) centerOfInterest.y,
                COLLADABU::Math::Utils::equalsZero( centerOfInterest.z, getTolerance () ) ? 0.0f : (float) centerOfInterest.z };

            // Extract the up direction, which corresponds to the second row.
            float upPosition[3] = {
                COLLADABU::Math::Utils::equalsZero( matrix[1][0], getTolerance () ) ? 0.0f : (float) matrix[1][0],
                COLLADABU::Math::Utils::equalsZero( matrix[1][1], getTolerance () ) ? 0.0f : (float) matrix[1][1],
                COLLADABU::Math::Utils::equalsZero( matrix[1][2], getTolerance () ) ? 0.0f : (float) matrix[1][2] };

            // Add the camera lookat
            mVisualSceneNode->addLookat ( eyePosition, interestPosition, upPosition );
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
                    sceneNode->addExtraTechniqueParameter ( PROFILE_MAYA, ATTR_VISIBILITY, isVisible );

                    AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
                    animationExporter->addNodeAnimation ( mTransformObject, ATTR_VISIBILITY, kBoolean );
                }
            }
        }
    }

	//---------------------------------------------------------------
	void VisualSceneExporter::exportExtraAttributes(const SceneElement* sceneElement)
	{
		class ExtraAttributeExporter : public AttributeParser
		{
		public:
            ExtraAttributeExporter(COLLADASW::Node & visualSceneNode)
                : mVisualSceneNode(visualSceneNode)
			{}

		private:
			COLLADASW::Node & mVisualSceneNode;

		protected:
			virtual bool onBeforePlug(MPlug & plug) override
			{
				MStatus status;

				MObject attr = plug.attribute(&status);
				if (!status) return false;

				MFnAttribute fnAttr(attr, &status);
				if (!status) return false;

				MString attrName = fnAttr.name(&status);
				if (!status) return false;

				bool isDynamic = fnAttr.isDynamic(&status);
				if (!status) return false;

				if (!isDynamic)
					return false;

				bool isHidden = fnAttr.isHidden(&status);
				if (!status) return false;

				if (isHidden)
					return false;

				return true;
			}

            virtual void onBoolean(MPlug & plug, const MString & name, bool value) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value, "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onInteger(MPlug & plug, const MString & name, int value) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value, "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onInteger2(MPlug & plug, const MString & name, int value[2]) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onInteger3(MPlug & plug, const MString & name, int value[3]) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], value[2], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onFloat(MPlug & plug, const MString & name, float value) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value, "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onFloat2(MPlug & plug, const MString & name, float value[2]) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onFloat3(MPlug & plug, const MString & name, float value[3]) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], value[2], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onDouble(MPlug & plug, const MString & name, double value) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value, "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onDouble2(MPlug & plug, const MString & name, double value[2]) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onDouble3(MPlug & plug, const MString & name, double value[3]) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], value[2], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onDouble4(MPlug & plug, const MString & name, double value[4]) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), value[0], value[1], value[2], value[3], "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onString(MPlug & plug, const MString & name, const MString & value) override
			{
				mVisualSceneNode.addExtraTechniqueParameter(PROFILE_MAYA, name.asChar(), COLLADABU::StringUtils::translateToXML(String(value.asChar())), "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
			}

            virtual void onEnum(MPlug & plug, const MString & name, int enumValue, const MString & enumName) override
            {
                // TODO export all possible enum values to be able to re-import them?
				mVisualSceneNode.addExtraTechniqueEnumParameter(PROFILE_MAYA, name.asChar(), COLLADABU::StringUtils::translateToXML(String(enumName.asChar())), "", COLLADASW::CSWC::CSW_ELEMENT_PARAM);
            }
		};

		MObject nodeObject = sceneElement->getNode();
		
		MStatus status;
		MFnDependencyNode fnNode(nodeObject, &status);
		if (!status) return;

        ExtraAttributeExporter extraAttributeExporter(*mVisualSceneNode);
		AttributeParser::parseAttributes(fnNode, extraAttributeExporter);
	}

    //---------------------------------------------------------------
    void VisualSceneExporter::exportInstanceController(
        SceneElement* sceneElement,
        const bool hasSkinController,
        const bool hasMorphController )
    {
        MObject childNode = sceneElement->getPath().node();

        // Get the streamWriter from the export document
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        ControllerExporter* controllerExporter = mDocumentExporter->getControllerExporter ();

        // Get the collada id.
//         MDagPath dagPath = sceneElement->getPath();
//         String mayaControllerId = mDocumentExporter->dagPathToColladaId ( dagPath );
        String mayaControllerId = sceneElement->getNodeName();
        if ( hasMorphController )
            mayaControllerId += COLLADASW::LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX;
        if ( hasSkinController )
            mayaControllerId += COLLADASW::LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;

        String colladaId = controllerExporter->findColladaControllerId ( mayaControllerId );

        // TODO id preservation
        // Create the unique controller ID
//         String colladaId;
//         if ( !sceneElement->getNodeId().empty() )
//             colladaId = sceneElement->getNodeId();
//         else
//           colladaId = sceneElement->getNodeName();
//         if ( hasMorphController )
//             colladaId += COLLADASW::LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX;
//         if ( hasSkinController )
//             colladaId += COLLADASW::LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;
		
        // Get the uri of the current scene
		COLLADASW::URI uri;
		if (!ExportOptions::exportSeparateFile() || (ExportOptions::exportSeparateFile() && !ExportOptions::exportAnimationsOnly()))
			uri = getSceneElementURI(sceneElement, colladaId);
		else
		{
			String daeName = ExportOptions::getDAEmodelName().asChar();
			
			MString exportedFile = mDocumentExporter->getFilename().c_str();

			// Make referenced file path relative to exported file directory
			COLLADASW::URI exportedFileURI = exportedFile.asChar();
			COLLADASW::URI exportedFileDirURI = exportedFileURI.getPathDir();
			exportedFileDirURI.setScheme(exportedFileURI.getScheme());
			
			COLLADASW::URI referencedFileURI = MString(daeName.c_str()).asChar();
			referencedFileURI.makeRelativeTo(exportedFileDirURI);
		 
			if (ExportOptions::exportAnimationsOnly() && daeName.compare("") != 0)
			{
				uri = URI(referencedFileURI.getURIString() + String("#") + colladaId);
			}
			else
			{
				MGlobal::displayWarning(MString("Please provide Model DAE path to not lose association between animation and a specific model "));
				return;
			}	
		}

        // Create the collada controller instance
        COLLADASW::InstanceController instanceController ( streamWriter );
        instanceController.setUrl ( uri );

        // Set the skeletonId. It indicates where a skin controller is to start to search for the 
        // joint nodes it needs. This element is meaningless for morph controllers.
        const std::set<URI>& skeletonURIs = sceneElement->getSkeletonURIs ();
        if ( skeletonURIs.size () > 0 )
        {
            std::set<URI>::const_iterator it = skeletonURIs.begin ();
            while ( it != skeletonURIs.end () )
            {
                instanceController.addSkeleton ( *it );
                ++it;
            }
        }

        // Write all materials
        COLLADASW::InstanceMaterialList& instanceMaterialList =
            instanceController.getBindMaterial().getInstanceMaterialList();

        // Export the materials
        exportInstanceMaterial ( instanceMaterialList, sceneElement->getPath() );

        instanceController.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportInstanceGeometry ( SceneElement* sceneElement )
    {
        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Get the collada mesh id.
        GeometryExporter* geometryExporter = mDocumentExporter->getGeometryExporter ();
        const String& colladaMeshId = geometryExporter->getColladaGeometryId ( dagPath );
        if ( colladaMeshId.empty () ) return;

        // Get the uri of the current scene
		COLLADASW::URI uri(getSceneElementURI(sceneElement, colladaMeshId));

        // Get the streamWriter from the export document
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Write the geometry instance
        COLLADASW::InstanceGeometry instanceGeometry ( streamWriter );
        instanceGeometry.setUrl ( uri );

        // Write all materials
        COLLADASW::InstanceMaterialList& instanceMaterialList =
            instanceGeometry.getBindMaterial().getInstanceMaterialList();

        // Export the materials
        exportInstanceMaterial ( instanceMaterialList, sceneElement->getPath() );

        instanceGeometry.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportInstanceLightProbe(const SceneElement* sceneElement)
    {
        // Get the collada light probe id.
        MDagPath dagPath = sceneElement->getPath();
        String mayaLightProbeId = mDocumentExporter->dagPathToColladaId ( dagPath );
        LightProbeExporter* lightProbeExporter = mDocumentExporter->getLightProbeExporter ();
        String colladaLightProbeId = lightProbeExporter->findColladaLightProbeId ( mayaLightProbeId );

        // Get the uri of the current scene
		COLLADASW::URI uri(getSceneElementURI(sceneElement, colladaLightProbeId));

        // Create and write the light probe instance
        //COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        //COLLADASW::InstanceLightProbe instanceLightProbe ( streamWriter, uri );
        //instanceLightProbe.add();

		mVisualSceneNode->addExtraTechniqueElement(COLLADAMaya::PROFILE_MAYA, COLLADAMaya::CSW_ELEMENT_INSTANCE_LIGHT_PROBE, COLLADASW::CSWC::CSW_ATTRIBUTE_URL, uri.getURIString());
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportInstanceLight( const SceneElement* sceneElement )
    {
        // Get the collada light id.
        MDagPath dagPath = sceneElement->getPath();
        String mayaLightId = mDocumentExporter->dagPathToColladaId ( dagPath );
        LightExporter* lightExporter = mDocumentExporter->getLightExporter ();
        String colladaLightId = lightExporter->findColladaLightId ( mayaLightId );

        // Get the uri of the current scene
		COLLADASW::URI uri(getSceneElementURI(sceneElement, colladaLightId));

        // Create and write the light instance
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        COLLADASW::InstanceLight instanceLight ( streamWriter, uri );
        instanceLight.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportInstanceCamera( const SceneElement* sceneElement )
    {
        // Get the collada id.
        MDagPath dagPath = sceneElement->getPath();
        String mayaId = mDocumentExporter->dagPathToColladaId ( dagPath );
        CameraExporter* cameraExporter = mDocumentExporter->getCameraExporter ();
        String colladaId = cameraExporter->findColladaCameraId ( mayaId );

        // Get the uri of the current scene
		COLLADASW::URI uri(getSceneElementURI(sceneElement, colladaId));

        // Create and write the camera instance
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        COLLADASW::InstanceCamera instanceCamera ( streamWriter, uri );
        instanceCamera.add();
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportInstanceNode ( SceneElement* sceneElement )
    {
        // Get the collada id.
        String mayaNodeId = sceneElement->getNodeId();
		if (mayaNodeId.empty())
		{
			mayaNodeId = mVisualSceneNode->getNodeId();
		}
        if ( mayaNodeId.empty() )
            mayaNodeId = sceneElement->getNodeName();
        String colladaNodeId = findColladaNodeId ( mayaNodeId );

        // Get the uri of the current scene
        COLLADASW::URI uri ( getSceneElementURI ( sceneElement, colladaNodeId ) );

        // Create and write the camera instance
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        COLLADASW::InstanceNode instanceNode ( streamWriter, uri );

		// Add Proxy to Next LOD Node (during Library Node second Pass)
		// Or during Visual Scene Pass only for element inside LOD Group
		if ((mDocumentExporter->mExportPass == SECOND_LOD_PASS) || 
			(ExportOptions::exportLOD() && mDocumentExporter->mExportPass == VISUAL_SCENE_PASS && (sceneElement->getParentCount()>0 && sceneElement->getParent()->getType() == SceneElement::LOD)))
		{
			int indexLOD;

			SceneElement* element;

			if (mDocumentExporter->mExportPass == VISUAL_SCENE_PASS)
				element = sceneElement->getParent();
			else
				element = sceneElement;

			String proxy = findNextColladaNodeId(element, indexLOD);
			if (proxy.compare(EMPTY_STRING) != 0)
			{
				String prefix = "LOD__";
				SceneElement* parent = sceneElement->getParent();
				
				if (indexLOD == parent->getChildCount() - 2)
					prefix = "";
				

				const String url = "#" + prefix + proxy;
				instanceNode.addExtraTechniqueParentElement(PROFILE_MAYA, PARAMETER_PROXY, "url", url);

				const String threshold = String(ATTR_THRESHOLD);
				instanceNode.addExtraTechniqueChildElement(PROFILE_MAYA, PARAMETER_PROXY, threshold, GetThresholdPlugValue(element, indexLOD));
			}			

			if (mDocumentExporter->mExportPass == VISUAL_SCENE_PASS)
				instanceNode.addExtraTechnique();		// Only Add Extra, Instance node has been added before
			else 
				instanceNode.add();	// Add Instance Node with proxy if != EMPTY_STRING, Add extra too
		}
		else
			instanceNode.add();
    }

    //---------------------------------------------------------------
    COLLADASW::URI VisualSceneExporter::getSceneElementURI (
        const SceneElement* sceneElement,
        const String& elementId /** = EMPTY_STRING */)
    {
		return getSceneElementURI(sceneElement->getPath(), elementId);
    }

    //---------------------------------------------------------------
	COLLADASW::URI VisualSceneExporter::getSceneElementURI(const MDagPath& dagPath, const String& id /*= EMPTY_STRING*/)
    {
        MFnDagNode dagFn(dagPath);
        bool isLocal = !dagFn.isFromReferencedFile();
		if (ExportOptions::exportXRefs() && ExportOptions::dereferenceXRefs()) {
            isLocal = true;
        }

        // Get the Uri of the element.
        if (!isLocal)
        {
            MObject referenceNode;
            MStatus status = ReferenceManager::getTopLevelReferenceNode(dagPath, referenceNode);
            if (status == MS::kFailure) {
                return COLLADASW::URI();
            }

            MString mayaReferenceFilename;
            status = ReferenceManager::getReferenceFilename(referenceNode, mayaReferenceFilename);

            String referenceFilename = mayaReferenceFilename.asChar();

            // Replace .mb by .dae
            String::size_type dotPos = referenceFilename.rfind('.');
            if (dotPos != String::npos) {
                referenceFilename.resize(dotPos);
                referenceFilename.append(".dae");
            }
            MString exportedFile = MFileIO::currentFile();

            // Make referenced file path relative to exported file directory
            COLLADASW::URI exportedFileURI = exportedFile.asChar();
            COLLADASW::URI exportedFileDirURI = exportedFileURI.getPathDir();
            exportedFileDirURI.setScheme(exportedFileURI.getScheme());
            COLLADASW::URI referencedFileURI = referenceFilename;
            if (ExportOptions::relativePaths())
            {
                referencedFileURI.makeRelativeTo(exportedFileDirURI);
            }

            COLLADASW::URI sceneElementURI(referencedFileURI);
            const bool removeFirstNamespace = true;
            String refNodeId = getColladaNodeId(dagPath, removeFirstNamespace);
            sceneElementURI.setFragment(refNodeId);
            return sceneElementURI;
        }
        else
        {
            // Get the id of the element
            if (!id.empty()) {
                return COLLADASW::URI(EMPTY_STRING, id);
            }
            else {
                return COLLADASW::URI(EMPTY_STRING, mDocumentExporter->dagPathToColladaId(dagPath));
            }
        }
    }

    //---------------------------------------------------------------
    void VisualSceneExporter::exportInstanceChildNodes( const SceneElement* sceneElement )
    {
        // Check the geometry instances, which use this visual scene
        size_t childCount = sceneElement->getChildCount();
        for ( size_t i=0; i<childCount; ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );

            // Just export visible export nodes.
            if ( !childElement->getIsExportNode() ) continue;
            if ( !ExportOptions::exportInvisibleNodes () && !childElement->getIsVisible () ) continue;

            bool exportGeometry = true;
            bool physicsExportNode = false;

            const MObject& transformNode = sceneElement->getPath().transform();
            DagHelper::getPlugValue(transformNode, ATTR_COLLISION_EXPORT_NODE, physicsExportNode);
            
            int shape;
            if (DagHelper::getPlugValue(transformNode, ATTR_COLLISION_SHAPE, shape) && !physicsExportNode)
            {
                if (shape == PhysicsExporter::Box ||
                    shape == PhysicsExporter::Capsule)
                    exportGeometry = false;
            }

            // Check if the child element is a mesh object and an export node
            if ( childElement->getType() == SceneElement::MESH && exportGeometry)
            {
                // Get the controller library
                ControllerExporter* controller = mDocumentExporter->getControllerExporter();
                MObject childNode = childElement->getPath().node();

                bool hasSkinController = controller->hasSkinController ( childNode );
                bool hasMorphController = controller->hasMorphController ( childNode );

                // Check for controllers, otherwise instantiate the geometry.
                // Add the controller and/or geometry to our libraries
				if ((ExportOptions::exportJoints() && hasSkinController) || hasMorphController)
                {
					if (ExportOptions::exportSkin() || ExportOptions::exportSeparateFile())
	                    exportInstanceController ( childElement, hasSkinController, hasMorphController );
                }
                else
                {
                    exportInstanceGeometry ( childElement );
                }
            }
            else if (childElement->getType() == SceneElement::LIGHT_PROBE &&
                childElement->getIsExportNode())
            {
                exportInstanceLightProbe(childElement);
            }
            else if ( childElement->getType() == SceneElement::LIGHT &&
                childElement->getIsExportNode() &&
                ExportOptions::exportLights())
            {
                exportInstanceLight ( childElement );
            }
            else if ( childElement->getType() == SceneElement::CAMERA &&
                childElement->getIsExportNode() &&
                ExportOptions::exportCameras())
            {
                exportInstanceCamera ( childElement );
            }
        }
    }

    // ------------------------------------
    const String VisualSceneExporter::findColladaNodeId ( const String& mayaNodeId )
    {
        const StringToStringMap::const_iterator it = mMayaIdColladaNodeId.find ( mayaNodeId );
        if ( it != mMayaIdColladaNodeId.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }

	const String VisualSceneExporter::findNextColladaNodeId(const SceneElement* sceneElement, int& indexLOD)
	{
		MDagPath dag;
		int index = 0;
		indexLOD = index;

		if (mDocumentExporter->mExportPass == VISUAL_SCENE_PASS)
			dag = sceneElement->getChild(1)->getPath();
		else
		{
			SceneElement* parent = sceneElement->getParent();
			
			bool found = false;
			for (index = 0; index < parent->getChildCount(); index++)
			{
				if (parent->getChild(index)->getPath() == sceneElement->getPath())
				{
					found = true;
					break;
				}
			}
			
			if (!found)
				return EMPTY_STRING;

			if (index + 1 >= parent->getChildCount())
				return EMPTY_STRING;
			else
				dag = parent->getChild(index + 1)->getPath();
		}

		indexLOD = index;

		String mayaNodeId = mDocumentExporter->dagPathToColladaId(dag);

		const StringToStringMap::iterator it = mMayaIdColladaNodeId.find(mayaNodeId);
		
		if (it != mMayaIdColladaNodeId.end())
		{
			return it->second;
		}
		return EMPTY_STRING;
	}

    // ------------------------------------
    COLLADAMaya::String VisualSceneExporter::getColladaNodeId ( 
        const MDagPath &dagPath,
		bool removeFirstNamespace)
    {
        String colladaNodeId;

        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( dagPath.node (), COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            colladaNodeId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false, removeFirstNamespace );
        }
        else
        {
            // Generate a COLLADA id for the new object
            //colladaNodeId = mDocumentExporter->mayaNameToColladaName ( node.name ().asChar () );
            colladaNodeId = mDocumentExporter->dagPathToColladaId ( dagPath, removeFirstNamespace );
        }	
        
        return colladaNodeId;
    }

	void VisualSceneExporter::ResetLODCounter()
	{
		mLODIndexCounter2 = 0;
	}
}
