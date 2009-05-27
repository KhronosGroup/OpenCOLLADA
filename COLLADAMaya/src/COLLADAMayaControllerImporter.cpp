/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaControllerImporter.h"
#include "COLLADAMayaVisualSceneImporter.h"
#include "COLLADAMayaGeometryImporter.h"

#include "COLLADAFWSkinController.h"
#include "COLLADAFWSkinControllerData.h"

#include "MayaDMCommands.h"


namespace COLLADAMaya
{

    /** 
    * For one controller, we need the following objects:
    *
    * createNode skinCluster -n "skinCluster1";
    * createNode objectSet -n "skinCluster1set";
    *
    * createNode tweak -n "tweak1";
    * createNode objectSet -n "tweak1set";
    *
    * createNode groupId -n "groupId1";
    * createNode groupParts -n "groupParts1";
    * createNode groupId -n "groupId2";
    * createNode groupParts -n "groupParts2";
    */
    const String ControllerImporter::SKIN_CLUSTER_NAME = "SkinCluster";
    const String ControllerImporter::TWEAK_NAME = "Tweak";
    const String ControllerImporter::SET_NAME = "Set";
    const String ControllerImporter::GROUP_PARTS_NAME = "GroupParts";


    //------------------------------
	ControllerImporter::ControllerImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
        , mObjectGroupsInitialIndex (0)
	{
	}
	
    //------------------------------
	ControllerImporter::~ControllerImporter()
	{
        {
            UniqueIdMayaNodeMap::iterator it = mMayaControllerNodesMap.begin ();
            while ( it != mMayaControllerNodesMap.end () )
            {
                MayaNode* mayaNode = it->second;
                delete mayaNode;
                ++it;
            }
            mMayaControllerNodesMap.clear ();
        }

        {
            std::map<COLLADAFW::UniqueId, COLLADAFW::SkinController*>::const_iterator it;
            it = mSkinControllersMap.begin ();
            while ( it != mSkinControllersMap.end () )
            {
                COLLADAFW::SkinController* skinController = it->second;
                delete skinController;
                ++it;
            }
            mSkinControllersMap.clear ();
        }

	}

    // --------------------------------------------
    void ControllerImporter::importSkinControllerData ( 
        const COLLADAFW::SkinControllerData* skinControllerData )
    {
        if ( skinControllerData == 0 ) return;

        // Check if the current controller is already imported.
        const COLLADAFW::UniqueId& skinControllerDataId = skinControllerData->getUniqueId ();
        if ( findMayaSkinControllerDataNode ( skinControllerDataId ) != 0 ) return;

        // Get the current maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Add the original id attribute.
        String colladaId = skinControllerData->getOriginalId ();
        if ( !COLLADABU::Utils::equals ( colladaId, "" ) )
        {
            MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string" );
            MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string", colladaId );
        }

        // Every controller has two groupIds, which have to be connected to the geometry object groups.
        // About this, the initial index position for connections to the geometry's object groups 
        // have to be on a later index position.
        addControllerToObjectGroupsInitialIndex ();

        // Create a data store object to hold all the MayaDM objects of the current controller.
        // The objects will be needed, to make all the connections.
        ControllerData controllerData;

        // SkinCluster nodes are created during a smooth bindSkin. The purpose of the skinCluster 
        // is to store a weight per influence object for each component of each geometry that is 
        // deformed. Influence objects can be joints or any transform.
        createSkinCluster ( skinControllerData, controllerData );

        // Create the tweak object and the set.
        String tweakName = TWEAK_NAME;
        tweakName = DocumentImporter::frameworkNameToMayaName ( tweakName );
        tweakName = mTweakIdList.addId ( tweakName, true, true );
        MayaDM::Tweak tweak ( file, tweakName );
        controllerData.setTweak ( tweak );

        String tweakSetName = tweakName + SET_NAME;
        MayaDM::ObjectSet tweakSet ( file, tweakSetName );
        tweakSet.setIsHistoricallyInteresting (0);
        tweakSet.setVerticesOnlySet (true);
        controllerData.setTweakSet ( tweakSet );

        // Create the groupIds and the groupParts.
        String groupIdName = GROUPID_NAME;
        groupIdName = DocumentImporter::frameworkNameToMayaName ( groupIdName );
        
        String groupIdName1 = getDocumentImporter ()->getGroupIdList ().addId ( groupIdName, true, true );
        MayaDM::GroupId groupId1 ( file, groupIdName1 );
        groupId1.setIsHistoricallyInteresting (0);
        controllerData.setGroupId1 ( groupId1 );
        
        String groupIdName2 = getDocumentImporter ()->getGroupIdList ().addId ( groupIdName, true, true );
        MayaDM::GroupId groupId2 ( file, groupIdName2 );
        groupId2.setIsHistoricallyInteresting (0);
        controllerData.setGroupId2 ( groupId2 );

        String groupPartsName = GROUP_PARTS_NAME;
        groupPartsName = DocumentImporter::frameworkNameToMayaName ( groupPartsName );
        MayaDM::componentList compList;
        compList.push_back ( "vtx[*]" );

        String groupPartsName1 = mGroupPartsIdList.addId ( groupPartsName, true, true );
        MayaDM::GroupParts groupParts1 ( file, groupPartsName1 );
        groupParts1.setIsHistoricallyInteresting (0);
        groupParts1.setInputComponents ( compList );
        controllerData.setGroupParts1 ( groupParts1 );

        String groupPartsName2 = mGroupPartsIdList.addId ( groupPartsName, true, true );
        MayaDM::GroupParts groupParts2 ( file, groupPartsName2 );
        groupParts2.setIsHistoricallyInteresting (0);
        groupParts2.setInputComponents ( compList );
        controllerData.setGroupParts2 ( groupParts2 );

        // Hold the controller data in a map.
        mControllers [ skinControllerDataId ] = controllerData;
    }

    // --------------------------------------------
    void ControllerImporter::createSkinCluster ( 
        const COLLADAFW::SkinControllerData* skinControllerData, 
        ControllerData& controllerData )
    {
        // Create a unique skin cluster name.
        String skinClusterName; // = controller->getName ();
        if ( COLLADABU::Utils::equals ( skinClusterName, "" ) ) 
            skinClusterName = SKIN_CLUSTER_NAME;
        skinClusterName = DocumentImporter::frameworkNameToMayaName ( skinClusterName );
        skinClusterName = mSkinClusterIdList.addId ( skinClusterName, true, true );

        // Create the skin cluster
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::SkinCluster skinCluster ( file, skinClusterName );
        controllerData.setSkinCluster ( skinCluster );

        // Set the bind shape matrix
        {
            // Get the bind shape matrix.
            const COLLADABU::Math::Matrix4& bindShapeMatrix = skinControllerData->getBindShapeMatrix ();

            // Convert the matrix to a double[4][4]
            double gm[4][4];
            convertMatrix4ToTransposedDouble4x4 ( bindShapeMatrix, gm, getTolerance () );

            // Set the maya inclusive matrix of the geometry path at the time of the bound.
            skinCluster.setGeomMatrix ( gm );
        }

        // Set the inverse bind matrices
        const COLLADAFW::Matrix4Array& inverseBindMatrices = skinControllerData->getInverseBindMatrices ();
        size_t numInverseBindMatrices = inverseBindMatrices.getCount ();
        for ( size_t i=0; i<numInverseBindMatrices; ++i )
        {
            // Get the inverse bind matrix.
            const COLLADABU::Math::Matrix4& inverseBindMatrix = inverseBindMatrices [i];

            // Convert the matrix to a double[4][4]
            double pm[4][4];
            convertMatrix4ToTransposedDouble4x4 ( inverseBindMatrix, pm, getTolerance () );
            MayaDM::matrix mayaPm ( pm );

            // Set the maya inclusive matrix inverse of the driving transform at the time of bind.
            skinCluster.setBindPreMatrix ( i, mayaPm );
        }

        // Weights for each target.
        {
            // The number of influences is the number of vertices in the mesh.
            size_t vertexCount = skinControllerData->getVertexCount ();
            // The list with the numbers of influences per vertex.
            const COLLADAFW::UIntValuesArray& jointsPerVertex = skinControllerData->getJointsPerVertex ();
            // The list of indices to the weight list.
            const COLLADAFW::UIntValuesArray& weightIndices = skinControllerData->getWeightIndices ();
            // The weight list.
            const COLLADAFW::FloatOrDoubleArray& weights = skinControllerData->getWeights ();

            size_t weightIndicesIndex = 0;
            for ( size_t influenceIndex=0; influenceIndex<vertexCount; ++influenceIndex )
            {
                // Number of influences
                unsigned int vertexInfluences = jointsPerVertex [influenceIndex];

                skinCluster.startWeights ( influenceIndex, 0, vertexInfluences-1 );
                for ( size_t j=0; j<vertexInfluences; ++j, ++weightIndicesIndex )
                {
                    unsigned int weightIndex = weightIndices [ weightIndicesIndex ];
                    double weight = getDoubleValue ( weights, weightIndex );
                    skinCluster.appendWeights ( weight );
                }
                skinCluster.endWeights ();
            }
        }

        // Store the joint indices, need it later.
        {
            ControllerJointInfo controllerJointInfo;
            const COLLADAFW::UniqueId& controllerId = skinControllerData->getUniqueId ();
            controllerJointInfo.setControllerId ( controllerId );
            size_t jointCount = skinControllerData->getJointsCount ();
            controllerJointInfo.setJointCount ( jointCount );
            const COLLADAFW::UIntValuesArray& jointIndices = skinControllerData->getJointIndices ();
            size_t numJointIndices = jointIndices.getCount ();
            std::vector<unsigned int>& controllerJointInfoJointIndices = controllerJointInfo.getJointIndices ();
            for ( size_t i=0; i<numJointIndices; ++i )
                controllerJointInfoJointIndices.push_back ( jointIndices[i] );
            mJointInfosMap [controllerId] = controllerJointInfo;
        }

        // Create skin cluster object set.
        String skinClusterSetName = skinClusterName + SET_NAME;
        MayaDM::ObjectSet skinClusterSet ( file, skinClusterSetName );
        skinClusterSet.setIsHistoricallyInteresting (0);
        skinClusterSet.setVerticesOnlySet (true);
        controllerData.setSkinClusterSet ( skinClusterSet );
    }

    //------------------------------
    void ControllerImporter::storeController ( const COLLADAFW::Controller* controller )
    {
       if ( controller == 0 ) return;

        // Check if the current controller is already imported.
        const COLLADAFW::UniqueId& controllerId = controller->getUniqueId ();
        if ( findMayaControllerNode ( controllerId ) != 0 ) return;

        COLLADAFW::Controller::ControllerType controllerType = controller->getControllerType ();
        switch ( controllerType )
        {
        case COLLADAFW::Controller::CONTROLLER_TYPE_SKIN:
            {
                // Get the skin controller object.
                COLLADAFW::SkinController* skinController = (COLLADAFW::SkinController*)controller;

                // Returns the unique id of the source that gets modified by this controller. 
                // Must be a mesh or a controller.
                const COLLADAFW::UniqueId& controllerSourceId = skinController->getSource ();

                // Get the skin controller data id.
                const COLLADAFW::UniqueId& skinControllerDataId = skinController->getSkinControllerData ();

                // Make a copy of the controller element.
                mSkinControllersMap [skinControllerDataId] = new COLLADAFW::SkinController ( *skinController );


            }
            break;
        case COLLADAFW::Controller::CONTROLLER_TYPE_MORPH:
            cerr << "Morph controller not implemented!" << endl;
            break;
        default:
            cerr << "Unknown controller type!" << endl;
        }

    }

    // --------------------------------------------
    MayaNode* ControllerImporter::findMayaControllerNode ( const COLLADAFW::UniqueId& controllerId ) 
    {
        UniqueIdMayaNodeMap::iterator it = mMayaControllerNodesMap.find ( controllerId );
        if ( it != mMayaControllerNodesMap.end () )
            return it->second;

        return 0;
    }

    // --------------------------------------------
    MayaNode* ControllerImporter::findMayaSkinControllerDataNode ( const COLLADAFW::UniqueId& skinControllerId ) 
    {
        UniqueIdMayaNodeMap::iterator it = mMayaSkinControllerNodesMap.find ( skinControllerId );
        if ( it != mMayaSkinControllerNodesMap.end () )
            return it->second;

        return 0;
    }

    // --------------------------------------------
    const COLLADAFW::SkinController* ControllerImporter::findSkinController ( const COLLADAFW::UniqueId& skinControllerDataId )
    {
        std::map<COLLADAFW::UniqueId, COLLADAFW::SkinController*>::const_iterator it;
        it = mSkinControllersMap.find ( skinControllerDataId );
        if ( it != mSkinControllersMap.end () )
            return it->second;
        return 0;
    }

    // --------------------------------------------
    const COLLADAFW::SkinController* ControllerImporter::findSkinControllerBySourceId ( const COLLADAFW::UniqueId& sourceId )
    {
        std::map<COLLADAFW::UniqueId, COLLADAFW::SkinController*>::const_iterator it;
        it = mSkinControllersMap.begin ();
        while ( it != mSkinControllersMap.end () )
        {
            if ( it->second->getSource () == sourceId )
                return it->second;
            ++it;
        }
        return 0;
    }
    
    // --------------------------------------------
    const COLLADAFW::UniqueId* ControllerImporter::getControllersGeometryId ( const COLLADAFW::UniqueId& controllerId )
    {
        std::map<COLLADAFW::UniqueId, COLLADAFW::SkinController*>::const_iterator it = mSkinControllersMap.begin ();
        while ( it != mSkinControllersMap.end () )
        {
            COLLADAFW::SkinController* skinController = it->second;
            if ( skinController->getUniqueId () == controllerId )
                return &(skinController->getSource ());
            ++it;
        }
        return 0;
    }

    // --------------------------------------------
    void ControllerImporter::writeConnections ()
    {
        writeJointConnections ();
        writeGeometryConnections ();
        writeControllerConnections ();
    }

    // --------------------------------------------
    void ControllerImporter::writeJointConnections ()
    {
        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Make the connections between the child and parent joints.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const UniqueIdMayaNodesMap& mayaTransformNodesMap = visualSceneImporter->getMayaTransformNodesMap ();

        UniqueIdMayaNodesMap::const_iterator it = mayaTransformNodesMap.begin ();
        while ( it != mayaTransformNodesMap.end () )
        {
            const MayaNodesList& mayaNodesList = it->second;
            if ( mayaNodesList.size () > 0 )
            {
                // Just make the connections for the first instance.
                MayaNode* mayaNode = mayaNodesList [0];
                if ( mayaNode->getType () == COLLADAFW::Node::JOINT )
                {
                    MayaNode* parentMayaNode = mayaNode->getParent ();
                    if ( parentMayaNode && parentMayaNode->getType () == COLLADAFW::Node::JOINT )
                    {
                        // Get the MayaDM objects.
                        const COLLADAFW::UniqueId& nodeId = mayaNode->getUniqueId ();
                        const MayaDM::Joint* jointNode = (MayaDM::Joint*)visualSceneImporter->findMayaDMTransform ( nodeId );

                        const COLLADAFW::UniqueId& parentNodeId = parentMayaNode->getUniqueId ();
                        const MayaDM::Joint* parentJointNode = (MayaDM::Joint*)visualSceneImporter->findMayaDMTransform ( parentNodeId );

                        // connectAttr "joint1.scale" "joint2.inverseScale";
                        connectAttr ( file, parentJointNode->getScale (), jointNode->getInverseScale () );
                    }
                }
            }
            ++it;
        }


        // Connect the skin cluster's joints world matrix with the skin cluster matrix.
        std::map<COLLADAFW::UniqueId, ControllerData>::const_iterator it2 = mControllers.begin ();
        while ( it2 != mControllers.end () )
        {
            // Get the maya controller data objects.
            const ControllerData& controllerData = it2->second;
            const MayaDM::SkinCluster& skinCluster = controllerData.getSkinCluster ();

            // Get the list of joints of the current controller.
            const COLLADAFW::UniqueId& skinControllerDataId = it2->first;
            const COLLADAFW::SkinController* skinController = findSkinController ( skinControllerDataId );
            if ( skinController == 0 )
            {
                std::cerr << "No skin controller element found!" << endl;
                ++it2;
                continue;
            }

            // Iterate over the joints and make the connections.
            const COLLADAFW::UniqueIdArray& joints = skinController->getJoints ();
            for ( size_t i=0; i<joints.getCount (); ++i )
            {
                // Get the maya joint node.
                const COLLADAFW::UniqueId& jointId = joints [i];
                MayaDM::Joint* jointNode = ( MayaDM::Joint* ) visualSceneImporter->findMayaDMTransform ( jointId );

                // connectAttr "joint1.worldMatrix" "skinCluster1.matrix[0]";
                connectAttr ( file, jointNode->getWorldMatrix (), skinCluster.getMatrix ( i ) );

                // - ".liw" stands for "Lock Influence Weight". By default, a joint doesn't have this 
                // attribute, but when it is smooth bound to geometry, each joint receives this new 
                // attribute. It is just a custom attribute. Its output connects to the respective 
                // skinCluster's ".lockWeights[]" (.lw) imput attribute. ".lockWeights[]" is an 
                // array attribute, that can receive inputs from multiple joint.liw attrs.
                // - There is no reference to this attribute (.liw) in the documentation, since it 
                // is a custom attr generated by the smoothBind process. You can find documentation 
                // for the ".lw" attr in the "joint" documentation.
                // connectAttr "joint1.lockInfluenceWeights" "skinCluster1.lockWeights[0]";
                //connectAttr ( file, jointNode->lockInfluenceWeights (), skinCluster.getLockWeights ( i ) );
            }

            ++it2;
        }
    }

    // --------------------------------------------
    void ControllerImporter::writeGeometryConnections ()
    {
        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the geometry objects of the controllers and make the required connections.
        std::map<COLLADAFW::UniqueId, ControllerData>::const_iterator it = mControllers.begin ();
        while ( it != mControllers.end () )
        {
            // Get the maya controller data objects.
            const ControllerData& controllerData = it->second;
            const MayaDM::SkinCluster& skinCluster = controllerData.getSkinCluster ();

            // Get the list of joints of the current controller.
            const COLLADAFW::UniqueId& skinControllerDataId = it->first;
            const COLLADAFW::SkinController* skinController = findSkinController ( skinControllerDataId );

            // Returns the unique id of the source that gets modified by this controller. 
            // Must be a mesh or a controller.
            // TODO Get the source object (can be either a mesh geometry or another controller element).
            const COLLADAFW::UniqueId& sourceId = skinController->getSource ();

            // Look for the source object in the geometries.
            GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();
            const MayaDM::Mesh* mesh = geometryImporter->findMayaDMMeshNode ( sourceId );
            if ( mesh )
            {
                // Get the second mesh object of the controller.
                const MayaDM::Mesh* meshOrig = geometryImporter->findMayaDMControllerMeshNode ( sourceId );

                // TODO Use the right ids!!!
                // connectAttr "skinCluster1GroupId.groupId" "pCubeShape1.instObjGroups.objectGroups[0].objectGroupId";
                const MayaDM::GroupId& skinClusterGroupId = controllerData.getGroupId1 ();
                connectAttr ( file, skinClusterGroupId.getGroupId (), mesh->getObjectGroupId (0) );

                // connectAttr "skinCluster1Set.memberWireframeColor" "pCubeShape1.instObjGroups.objectGroups[0].objectGrpColor";
                const MayaDM::ObjectSet& skinClusterSet = controllerData.getSkinClusterSet();
                connectAttr ( file, skinClusterSet.getMemberWireframeColor (), mesh->getObjectGrpColor (0) );

                // connectAttr "groupId2.groupId" "pCubeShape1.instObjGroups.objectGroups[1].objectGroupId";
                const MayaDM::GroupId& groupId2 = controllerData.getGroupId2 ();
                connectAttr ( file, groupId2.getGroupId (), mesh->getObjectGroupId (1) );

                // connectAttr "tweakSet1.memberWireframeColor" "pCubeShape1.instObjGroups.objectGroups[1].objectGrpColor";
                const MayaDM::ObjectSet& tweakSet = controllerData.getTweakSet ();
                connectAttr ( file, tweakSet.getMemberWireframeColor (), mesh->getObjectGrpColor (1) );

                // connectAttr "skinCluster1.outputGeometry[0]" "pCubeShape1.inMesh";
                const MayaDM::SkinCluster& skinCluster = controllerData.getSkinCluster ();
                connectAttr ( file, skinCluster.getOutputGeometry (0), mesh->getInMesh () );

                // connectAttr "tweak1.vlist[0].vertex[0]" "pCubeShape1.tweakLocation";
                const MayaDM::Tweak& tweak = controllerData.getTweak ();
                connectAttr ( file, tweak.getVertex (0,0), mesh->getTweakLocation () );

                // connectAttr "pCubeShape1.instObjGroups.objectGroups[0]" "skinCluster1Set.dagSetMembers" -nextAvailable;
                connectNextAttr ( file, mesh->getObjectGroups (0), skinClusterSet.getDagSetMembers () );

                // connectAttr "pCubeShape1.instObjGroups.objectGroups[1]" "tweakSet1.dagSetMembers" -nextAvailable;
                connectNextAttr ( file, mesh->getObjectGroups (1), tweakSet.getDagSetMembers () );

                // connectAttr "pCubeShape1Orig.worldMesh" "groupParts2.inputGeometry";
                const MayaDM::GroupParts& groupParts2 = controllerData.getGroupParts2 ();
                connectAttr ( file, meshOrig->getWorldMesh (), groupParts2.getInputGeometry () );
            }

            ++it;
        }
    }

    // --------------------------------------------
    void ControllerImporter::writeControllerConnections ()
    {
        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        std::map<COLLADAFW::UniqueId, ControllerData>::const_iterator it = mControllers.begin ();
        while ( it != mControllers.end () )
        {
            const ControllerData& controllerData = it->second;

            // connectAttr "skinCluster1GroupParts.outputGeometry" "skinCluster1.input[0].inputGeometry";
            const MayaDM::GroupParts& skinClusterGroupParts = controllerData.getGroupParts1 ();
            const MayaDM::SkinCluster& skinCluster = controllerData.getSkinCluster ();
            connectAttr ( file, skinClusterGroupParts.getOutputGeometry (), skinCluster.getInputGeometry (0) );

            // connectAttr "skinCluster1GroupId.groupId" "skinCluster1.input[0].groupId";
            const MayaDM::GroupId& skinClusterGroupId = controllerData.getGroupId1 ();
            connectAttr ( file, skinClusterGroupId.getGroupId (), skinCluster.getGroupId (0) );

            // connectAttr "groupParts2.outputGeometry" "tweak1.input[0].inputGeometry";
            const MayaDM::GroupParts& groupParts2 = controllerData.getGroupParts2 ();
            const MayaDM::Tweak& tweak = controllerData.getTweak ();
            connectAttr ( file, groupParts2.getOutputGeometry (), tweak.getInputGeometry (0) );

            // connectAttr "groupId2.groupId" "tweak1.input[0].groupId";
            const MayaDM::GroupId& groupId2 = controllerData.getGroupId2 ();
            connectAttr ( file, groupId2.getGroupId (), tweak.getGroupId (0) );

            // connectAttr "skinCluster1GroupId.message" "skinCluster1Set.groupNodes" -nextAvailable;
            const MayaDM::ObjectSet& skinClusterSet = controllerData.getSkinClusterSet ();
            connectNextAttr ( file, skinClusterGroupId.getMessage (), skinClusterSet.getGroupNodes () );

            // connectAttr "skinCluster1.message" "skinCluster1Set.usedBy[0]";
            connectAttr ( file, skinCluster.getMessage (), skinClusterSet.getUsedBy (0) );

            // connectAttr "tweak1.outputGeometry[0]" "skinCluster1GroupParts.inputGeometry";
            connectAttr ( file, tweak.getOutputGeometry (0), skinClusterGroupParts.getInputGeometry () );

            // connectAttr "skinCluster1GroupId.groupId" "skinCluster1GroupParts.groupId";
            connectAttr ( file, skinClusterGroupId.getGroupId (), skinClusterGroupParts.getGroupId () );

            // connectAttr "groupId2.message" "tweakSet1.groupNodes" -nextAvailable;
            const MayaDM::ObjectSet& tweakSet = controllerData.getTweakSet ();
            connectNextAttr ( file, groupId2.getMessage (), tweakSet.getGroupNodes () );

            // connectAttr "tweak1.message" "tweakSet1.usedBy[0]";
            connectAttr ( file, tweak.getMessage (), tweakSet.getUsedBy (0) );

            // connectAttr "groupId2.groupId" "groupParts2.groupId";
            connectAttr ( file, groupId2.getGroupId (), groupParts2.getGroupId () );

            ++it;
        }
    }

} // namespace COLLADAMaya
