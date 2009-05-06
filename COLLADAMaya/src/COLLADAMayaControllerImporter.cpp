/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaControllerImporter.h"

//#include "COLLADAFWController.h"

#include "MayaDMSkinCluster.h"
#include "MayaDMTweak.h"
#include "MayaDMObjectSet.h"
#include "MayaDMGroupParts.h"
#include "MayaDMCommands.h"
#include "MayaDMGroupId.h"


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
    const String ControllerImporter::SKIN_CLUSTER_NAME = "skinCluster";
    const String ControllerImporter::TWEAK_NAME = "tweak";
    const String ControllerImporter::SET_NAME = "set";
    const String ControllerImporter::GROUP_ID_NAME = "groupId";
    const String ControllerImporter::GROUP_PARTS_NAME = "groupParts";


    //------------------------------
	ControllerImporter::ControllerImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	ControllerImporter::~ControllerImporter()
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

    //------------------------------
    void ControllerImporter::importController ( /*const COLLADAFW::Controller* controller*/ )
    {
//        if ( controller == 0 ) return;
// 
//         // Check if the current controller is already imported.
//         const COLLADAFW::UniqueId& controllerId = controller->getUniqueId ();
//         if ( findMayaControllerNode ( controllerId ) != 0 ) return;

        // Create a unique skin cluster name.
        String skinClusterName; // = controller->getName ();
        if ( COLLADABU::Utils::equals ( skinClusterName, "" ) ) 
            skinClusterName = SKIN_CLUSTER_NAME;
        skinClusterName = DocumentImporter::frameworkNameToMayaName ( skinClusterName );
        skinClusterName = mSkinClusterIdList.addId ( skinClusterName, true, true );

        // Get the current maya file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Add the original id attribute.
        String colladaId;// = controller->getOriginalId ();
        if ( !COLLADABU::Utils::equals ( colladaId, "" ) )
        {
            MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string" );
            MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string", colladaId );
        }

        // Create the skin cluster
        MayaDM::SkinCluster skinCluster ( file, skinClusterName );

        // Create skin cluster object set.
        String skinClusterSetName = skinClusterName + SET_NAME;
        MayaDM::ObjectSet skinClusterSet ( file, skinClusterSetName );
        skinClusterSet.setIsHistoricallyInteresting (0);
        skinClusterSet.setVerticesOnlySet (true);

        // Create the tweak object and the set.
        String tweakName = TWEAK_NAME;
        tweakName = DocumentImporter::frameworkNameToMayaName ( tweakName );
        tweakName = mTweakIdList.addId ( tweakName, true, true );
        MayaDM::Tweak tweak ( file, tweakName );

        String tweakSetName = tweakName + SET_NAME;
        MayaDM::ObjectSet tweakSet ( file, tweakSetName );
        tweakSet.setIsHistoricallyInteresting (0);
        tweakSet.setVerticesOnlySet (true);

        // Create the groupIds and the groupParts.
        String groupIdName = GROUP_ID_NAME;
        groupIdName = DocumentImporter::frameworkNameToMayaName ( groupIdName );
        
        String groupIdName1 = mGroupIdList.addId ( groupIdName, true, true );
        MayaDM::GroupId groupId1 ( file, groupIdName1 );
        groupId1.setIsHistoricallyInteresting (0);

        String groupIdName2 = mGroupIdList.addId ( groupIdName, true, true );
        MayaDM::GroupId groupId2 ( file, groupIdName2 );
        groupId2.setIsHistoricallyInteresting (0);

        String groupPartsName = GROUP_PARTS_NAME;
        groupPartsName = DocumentImporter::frameworkNameToMayaName ( groupPartsName );
        MayaDM::componentList compList;
        compList.push_back ( "vtx[*]" );

        String groupPartsName1 = mGroupPartsIdList.addId ( groupPartsName, true, true );
        MayaDM::GroupParts groupParts1 ( file, groupPartsName1 );
        groupParts1.setIsHistoricallyInteresting (0);
        groupParts1.setInputRemoveComponent ( compList );

        String groupPartsName2 = mGroupPartsIdList.addId ( groupPartsName, true, true );
        MayaDM::GroupParts groupParts2 ( file, groupPartsName2 );
        groupParts2.setIsHistoricallyInteresting (0);
        groupParts2.setInputRemoveComponent ( compList );

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
    void ControllerImporter::writeConnections ()
    {
//         writeJointConnections ();
//         writeGeometryConnections ();

    }

} // namespace COLLADAMaya
