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
#include "COLLADAMayaConversion.h"

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


    //------------------------------
	ControllerImporter::ControllerImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
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
            std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::iterator it = mSkinControllersMap.begin ();
            while ( it != mSkinControllersMap.end () )
            {
                std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
                for ( size_t i=0; i<skinControllers.size (); ++i )
                {
                    COLLADAFW::SkinController* skinController = skinControllers[i];
                    delete skinController;
                }
                skinControllers.clear ();
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
        if ( skinControllerDataIdExported ( skinControllerDataId ) ) return;

        // Get the current maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // TODO Get all controller objects, which use the current skinControllerData.
        // We have to create the skinController data for every skinController object.
        const std::vector<COLLADAFW::SkinController*>& skinControllers = findSkinControllersByDataId ( skinControllerDataId );
        for ( size_t i=0; i<skinControllers.size (); ++i )
        {
            // Get the current controller.
            const COLLADAFW::SkinController* skinController = skinControllers[i];
            const COLLADAFW::UniqueId& controllerId = skinController->getUniqueId ();

            // Add the original id attribute.
            String colladaId = skinControllerData->getOriginalId ();
            if ( !COLLADABU::Utils::equals ( colladaId, "" ) )
            {
                MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string" );
                MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string", colladaId );
            }

            // Every controller has two groupIds, which have to be connected to the geometry object 
            // groups. About this, the initial index position for connections to the geometry's 
            // object groups have to be on a later index position.
            addControllerToObjectGroupsInitialIndex ( controllerId );

            // Create a data store object to hold all the MayaDM objects of the current controller.
            // The objects will be needed, to make all the connections.
            MayaSkinClusterData controllerData;

            // SkinCluster nodes are created during a smooth bindSkin. The purpose of the skinCluster 
            // is to store a weight per influence object for each component of each geometry that is 
            // deformed. Influence objects can be joints or any transform.
            createSkinCluster ( skinControllerData, controllerData );

            // Create the groupId and the groupParts for the skinCluster.
            String groupIdName = GROUP_ID_NAME;
            groupIdName = DocumentImporter::frameworkNameToMayaName ( groupIdName );

            String groupIdName1 = getDocumentImporter ()->getGroupIdIdList ().addId ( groupIdName, true, true );
            MayaDM::GroupId groupId1 ( file, groupIdName1 );
            groupId1.setIsHistoricallyInteresting (0);
            controllerData.setGroupId1 ( groupId1 );

            String groupPartsName = GROUP_PARTS_NAME;
            groupPartsName = DocumentImporter::frameworkNameToMayaName ( groupPartsName );
            MayaDM::componentList compList;
            compList.push_back ( "vtx[*]" );

            String groupPartsName1 = getDocumentImporter ()->getGroupPartsIdList ().addId ( groupPartsName, true, true );
            MayaDM::GroupParts groupParts1 ( file, groupPartsName1 );
            groupParts1.setIsHistoricallyInteresting (0);
            groupParts1.setInputComponents ( compList );
            controllerData.setGroupParts1 ( groupParts1 );

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

            // Create the groupId and the groupParts for the tweak.
            String groupIdName2 = getDocumentImporter ()->getGroupIdIdList ().addId ( groupIdName, true, true );
            MayaDM::GroupId groupId2 ( file, groupIdName2 );
            groupId2.setIsHistoricallyInteresting (0);
            controllerData.setGroupId2 ( groupId2 );

            String groupPartsName2 = getDocumentImporter ()->getGroupPartsIdList ().addId ( groupPartsName, true, true );
            MayaDM::GroupParts groupParts2 ( file, groupPartsName2 );
            groupParts2.setIsHistoricallyInteresting (0);
            groupParts2.setInputComponents ( compList );
            controllerData.setGroupParts2 ( groupParts2 );

            // Hold the controller data in a map.
            mMayaSkinClustersDataMap [ controllerId ] = controllerData;
        }
    }

    // --------------------------------------------
    void ControllerImporter::createSkinCluster ( 
        const COLLADAFW::SkinControllerData* skinControllerData, 
        MayaSkinClusterData& controllerData )
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

        // Weights for each target.
        {
            // The number of influences is the number of vertices in the mesh.
            size_t vertexCount = skinControllerData->getVertexCount ();
            // The list with the numbers of influences per vertex.
            const COLLADAFW::UIntValuesArray& jointsPerVertex = skinControllerData->getJointsPerVertex ();
            // The joint indices
            const COLLADAFW::UIntValuesArray& jointIndices = skinControllerData->getJointIndices ();
            // The list of indices to the weight list.
            const COLLADAFW::UIntValuesArray& weightIndices = skinControllerData->getWeightIndices ();
            // The weight list.
            const COLLADAFW::FloatOrDoubleArray& weights = skinControllerData->getWeights ();

            size_t weightIndicesIndex = 0;
            for ( size_t influenceIndex=0; influenceIndex<vertexCount; ++influenceIndex )
            {
                // Number of influences
                unsigned int numVertexInfluences = jointsPerVertex [influenceIndex];

                // The list of the current weights array.
                std::vector<double> currentWeights;

                // Flag, if the weight list should be written.
                bool doWriteWeights = false;
                bool weightInserted = false;
                unsigned int jointStartIndex = 0;
                unsigned int jointEndIndex = 0;
                unsigned int previousJointIndex = 0;

                // Go through the weights and write them.
                // If the previous weight is from the joint before the current weight,
                // they can be written as an array. Otherwise, they have to be written separately.
                for ( size_t j=0; j<numVertexInfluences; ++j, ++weightIndicesIndex )
                {
                    // Get the current weight. 
                    unsigned int weightIndex = weightIndices [ weightIndicesIndex ];
                    double weight = getDoubleValue ( weights, weightIndex );
                    doWriteWeights = false;
                    weightInserted = false;

                    // Handle the indices.
                    unsigned int jointIndex = jointIndices [ weightIndicesIndex ];
                    if ( j == 0 ) 
                    {
                        // The begin is the end of the current array.
                        jointStartIndex = jointEndIndex = jointIndex;

                        // Push the current weight in the list of current weights.
                        currentWeights.push_back ( weight );
                        weightInserted = true;
                    }
                    else if ( jointIndex == jointEndIndex+1 )
                    {
                        // The next joint is the next neighbour. We can write an array.
                        jointEndIndex = jointIndex;

                        // Push the current weight in the list of current weights.
                        currentWeights.push_back ( weight );
                        weightInserted = true;
                    }
                    else 
                    {
                        // A hole in the index list, we have to write the current weight list.
                        doWriteWeights = true;
                    }

                    // At the last influence, the data will be written.
                    if ( j+1 == numVertexInfluences )
                    {
                        doWriteWeights = true;
                    }

                    // Write the weights, if necessary.
                    if ( doWriteWeights )
                    {
                        writeWeights ( skinCluster, currentWeights, influenceIndex, jointStartIndex, jointEndIndex );
                        jointStartIndex = jointEndIndex = jointIndex;
                    }

                    // Push the current weight in the list of current weights, if not already done.
                    if ( !weightInserted )
                    {
                        currentWeights.push_back ( weight );
                    }
                }

                // Write the last weights, if necessary.
                if ( currentWeights.size () > 0 )
                {
                    writeWeights ( skinCluster, currentWeights, influenceIndex, jointStartIndex, jointEndIndex );
                }
            }
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

            // Do the unit conversion of the transform values, if necessary.
            mayaPm[3][0] = toLinearUnit ( mayaPm[3][0] );
            mayaPm[3][1] = toLinearUnit ( mayaPm[3][1] );
            mayaPm[3][2] = toLinearUnit ( mayaPm[3][2] );

            // Set the maya inclusive matrix inverse of the driving transform at the time of bind.
            skinCluster.setBindPreMatrix ( i, mayaPm );
        }

        // Set the bind shape matrix
        {
            // Get the bind shape matrix.
            const COLLADABU::Math::Matrix4& bindShapeMatrix = skinControllerData->getBindShapeMatrix ();

            // Convert the matrix to a double[4][4]
            double gm[4][4];
            convertMatrix4ToTransposedDouble4x4 ( bindShapeMatrix, gm, getTolerance () );

            // Do the unit conversion of the transform values, if necessary.
            gm[3][0] = toLinearUnit ( gm[3][0] );
            gm[3][1] = toLinearUnit ( gm[3][1] );
            gm[3][2] = toLinearUnit ( gm[3][2] );

            // Set the maya inclusive matrix of the geometry path at the time of the bound.
            skinCluster.setGeomMatrix ( gm );
        }

        // Create skin cluster object set.
        String skinClusterSetName = skinClusterName + SET_NAME;
        MayaDM::ObjectSet skinClusterSet ( file, skinClusterSetName );
        skinClusterSet.setIsHistoricallyInteresting (0);
        skinClusterSet.setVerticesOnlySet (true);
        controllerData.setSkinClusterSet ( skinClusterSet );
    }

    //------------------------------
    void ControllerImporter::writeWeights ( 
        MayaDM::SkinCluster& skinCluster, 
        std::vector<double>& currentWeightList, 
        const size_t influenceIndex, 
        const unsigned int jointStartIndex, 
        const unsigned int jointEndIndex )
    {
        // We have to write the weights.
        size_t currentWeightListSize = currentWeightList.size ();
        if ( currentWeightListSize == 1 )
        {
            skinCluster.setWeights ( influenceIndex, jointStartIndex, currentWeightList[0] );
        }
        else if ( currentWeightListSize > 1 )
        {
            if ( jointEndIndex-jointStartIndex+1 != currentWeightList.size () )
            {
                std::cerr << "No valid weight list!" << endl;
                return;
            }
            skinCluster.startWeights ( influenceIndex, jointStartIndex, jointEndIndex );
            for ( size_t n=0; n<currentWeightList.size (); ++n )
                skinCluster.appendWeights ( currentWeightList[n] );
            skinCluster.endWeights ();
        }
        // Clear the list again and reset the variables.
        currentWeightList.clear ();
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
                const COLLADAFW::UniqueId& sourceId = skinController->getSource ();

                // Make a copy of the controller element.
                mSkinControllersMap[sourceId].push_back ( new COLLADAFW::SkinController (*skinController) );
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
    bool ControllerImporter::skinControllerDataIdExported ( const COLLADAFW::UniqueId& skinControllerDataId ) 
    {
        for ( size_t i=0; i<mSkinControllerDataIds.size (); ++i )
        {
            if ( mSkinControllerDataIds[i] == skinControllerDataId ) 
                return true;
        }
        return false;
    }

    // --------------------------------------------
    const std::vector<COLLADAFW::SkinController*> ControllerImporter::findSkinControllersByDataId ( const COLLADAFW::UniqueId& skinControllerDataId )
    {
        std::vector<COLLADAFW::SkinController*> skinControllersNewList (0);

        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*>>::iterator it = mSkinControllersMap.begin ();
        while ( it != mSkinControllersMap.end () )
        {
            std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
            for ( size_t i=0; i<skinControllers.size (); ++i )
            {
                COLLADAFW::SkinController* skinController = skinControllers[i];
                if ( skinController->getSkinControllerData () == skinControllerDataId )
                {
                    skinControllersNewList.push_back ( skinController );
                }
            }
            ++it;
        }
        return skinControllersNewList;
    }

    // --------------------------------------------
    const COLLADAFW::SkinController* ControllerImporter::findSkinController ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::iterator it = mSkinControllersMap.begin ();
        while ( it != mSkinControllersMap.end () )
        {
            std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
            for ( size_t i=0; i<skinControllers.size (); ++i )
            {
                COLLADAFW::SkinController* skinController = skinControllers[i];
                if ( skinController->getUniqueId () == controllerId )
                    return skinController;
            }
            ++it;
        }
        return 0;
    }

    // --------------------------------------------
    const std::vector<COLLADAFW::SkinController*>* ControllerImporter::findSkinControllersBySourceId ( const COLLADAFW::UniqueId& sourceId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::const_iterator it;
        it = mSkinControllersMap.find ( sourceId );
        if ( it != mSkinControllersMap.end () )
        {
            const std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
            return &skinControllers;
        }
        return 0;
    }
    
    // --------------------------------------------
    const COLLADAFW::UniqueId* ControllerImporter::getControllersGeometryId ( const COLLADAFW::UniqueId& controllerId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> >::const_iterator it = mSkinControllersMap.begin ();
        while ( it != mSkinControllersMap.end () )
        {
            const std::vector<COLLADAFW::SkinController*>& skinControllers = it->second;
            for ( size_t i=0; i<skinControllers.size (); ++i )
            {
                const COLLADAFW::SkinController* skinController = skinControllers[i];
                if ( skinController->getUniqueId () == controllerId )
                    return &(skinController->getSource ());
            }
            ++it;
        }
        return 0;
    }

    // --------------------------------------------
    const ControllerImporter::MayaSkinClusterData* ControllerImporter::findMayaSkinClusterData ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        std::map<COLLADAFW::UniqueId, MayaSkinClusterData>::const_iterator it = mMayaSkinClustersDataMap.find ( controllerId );
        if ( it != mMayaSkinClustersDataMap.end () )
            return &(it->second);
        return 0;
    }

    // --------------------------------------------
    const size_t ControllerImporter::findObjectGroupsInitialIndex ( 
        const COLLADAFW::UniqueId& controllerId ) const
    {
        std::map<COLLADAFW::UniqueId, size_t>::const_iterator it = mObjectGroupsInitialIndexMap.find ( controllerId ); 
        if ( it != mObjectGroupsInitialIndexMap.end () )
        {
            return it->second;
        }
        return 0;
    }

    // --------------------------------------------
    void ControllerImporter::addControllerToObjectGroupsInitialIndex ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        size_t objectGroupsInitialIndex = findObjectGroupsInitialIndex ( controllerId );
        objectGroupsInitialIndex += 2; 
        mObjectGroupsInitialIndexMap [ controllerId ] = objectGroupsInitialIndex;
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
        std::map<COLLADAFW::UniqueId, MayaSkinClusterData>::const_iterator it2 = mMayaSkinClustersDataMap.begin ();
        while ( it2 != mMayaSkinClustersDataMap.end () )
        {
            // Get the current controller.
            const COLLADAFW::UniqueId& controllerId = it2->first;
            const COLLADAFW::SkinController* skinController = findSkinController ( controllerId );
            if ( skinController == 0 ) 
            {
                std::cerr << "No skin controller element found!" << endl;
                ++it2;
                continue;
            }

            // Get the maya controller data object.
            const MayaSkinClusterData& controllerData = it2->second;
            const MayaDM::SkinCluster& skinCluster = controllerData.getSkinCluster ();

            // Iterate over the joints of the current controller and make the connections.
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

        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        GeometryImporter* geometryImporter = getDocumentImporter ()->getGeometryImporter ();

        // Get the geometry objects of the controllers and make the required connections.
        std::map<COLLADAFW::UniqueId, MayaSkinClusterData>::const_iterator it = mMayaSkinClustersDataMap.begin ();
        while ( it != mMayaSkinClustersDataMap.end () )
        {
            // Get the current controller.
            const COLLADAFW::UniqueId& controllerId = it->first;
            const COLLADAFW::SkinController* skinController = findSkinController ( controllerId );
            if ( skinController == 0 ) 
            {
                std::cerr << "No skin controller element found!" << endl;
                ++it;
                continue;
            }

            // Get the maya controller data objects.
            const MayaSkinClusterData& controllerData = it->second;
            const MayaDM::SkinCluster& skinCluster = controllerData.getSkinCluster ();

            // Get the source object (can be either a mesh geometry or a morph controller element).
            const COLLADAFW::UniqueId& sourceId = skinController->getSource ();

            // TODO Check for multiple mesh instances. If there are multiple instances, 
            // we have to use the full path to the mesh object.
            const UniqueIdVec* transformIds = visualSceneImporter->findControllerTransformIds ( controllerId );
            const COLLADAFW::UniqueId& transformId = (*transformIds) [0];

            // Get the meshControllerData
            GeometryImporter::MeshControllerData* meshControllerData = geometryImporter->findMeshControllerDataByControllerAndTransformId ( controllerId, transformId );
            const COLLADAFW::UniqueId& geometryId = meshControllerData->getGeometryId ();
            if ( geometryId != sourceId )
            {
                std::cerr << "Wrong sourceId!" << endl;
                ++it;
                continue;
            }
            // Get the second mesh object of the controller.
            MayaDM::Mesh* mesh = meshControllerData->getControllerMeshNode ();
            const MayaDM::Mesh* meshOrig = meshControllerData->getOriginalMeshNode ();
            //const MayaDM::Mesh* meshOrig = geometryImporter->findMayaDMControllerMeshNode ( sourceId );
            if ( meshOrig == 0 )
            {
                std::cerr << "No original mesh object for the current mesh controller!" << endl;
                return;
            }
            // Get all pathes of the current transformation to know the number of transform node instances.
            std::vector<String> transformPathes;
            visualSceneImporter->getTransformPathes ( transformPathes, transformId );
            size_t numTransformInstances = transformPathes.size ();

            // TODO Can't we always use the full path?
            String meshName = mesh->getName ();
            if ( numTransformInstances >= 1 )
            {
                // Set the current transformation path for the meshName (unique identifier).
                String meshPath = transformPathes [0] + "|" + meshName;
                mesh->setName ( meshPath );
            }

            // TODO Are this always the right ids? 
            // Just one controller per geometry, always at the beginning, the primitve element 
            // indices come always after the controller indices.

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

            // Just do this connection, if we don't use groupParts 
            // (no multiple mesh primitive elements in the current geometry)
            const size_t numPrimitiveElements = geometryImporter->findPrimitivesCount ( sourceId );
            if ( numPrimitiveElements == 1 )
            {
                // connectAttr "skinCluster1.outputGeometry[0]" "pCubeShape1.inMesh";
                const MayaDM::SkinCluster& skinCluster = controllerData.getSkinCluster ();
                connectAttr ( file, skinCluster.getOutputGeometry (0), mesh->getInMesh () );
            }

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

            // Reset the name of the mesh object.
            if ( numTransformInstances >= 1 )
            {
                mesh->setName ( meshName );
            }

            ++it;
        }
    }

    // --------------------------------------------
    void ControllerImporter::writeControllerConnections ()
    {
        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        std::map<COLLADAFW::UniqueId, MayaSkinClusterData>::const_iterator it = mMayaSkinClustersDataMap.begin ();
        while ( it != mMayaSkinClustersDataMap.end () )
        {
            const MayaSkinClusterData& controllerData = it->second;

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
