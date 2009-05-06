/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_CONTROLLERIMPORTER_H__
#define __COLLADAMAYA_CONTROLLERIMPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADABUIDList.h"


namespace COLLADAMaya
{

    /** 
     * Handles the import of controllers. 
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
    class ControllerImporter : public BaseImporter
    {
    private:

        /** The standard name for controller without name. */
        static const String SKIN_CLUSTER_NAME;
        static const String TWEAK_NAME;
        static const String SET_NAME;
        static const String GROUP_ID_NAME;
        static const String GROUP_PARTS_NAME;

    private:

        /**
        * The list of the unique maya controller names.
        */
        COLLADABU::IDList mSkinClusterIdList;
        COLLADABU::IDList mTweakIdList;
        COLLADABU::IDList mGroupIdList;
        COLLADABU::IDList mGroupPartsIdList;

        /** 
        * The map holds the unique ids of the controller nodes to the maya specific nodes. 
        */
        UniqueIdMayaNodeMap mMayaControllerNodesMap;

	
	public:

        /** Constructor. */
		ControllerImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~ControllerImporter();

        /**
        * Imports the data of the current controller.
        */
        void importController ( /*const COLLADAFW::Controller* controller*/ );

        /**
         * Make the connections for the controller.
         */
        void writeConnections ();

    private:

        MayaNode* findMayaControllerNode ( const COLLADAFW::UniqueId& controllerId );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_CONTROLLERIMPORTER_H__
