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

#include "MayaDMSkinCluster.h"
#include "MayaDMTweak.h"
#include "MayaDMObjectSet.h"
#include "MayaDMGroupId.h"
#include "MayaDMGroupParts.h"

#include "COLLADAFWSkinController.h"


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

    public:

        /**
        * The indices of joints assigned to a joint/vertex pair of a controller element. 
        * The number of pairs for the i'th vertex is given by the i'th value in mJointsPerVertex.
        */
        class ControllerJointInfo
        {
        private:
            COLLADAFW::UniqueId controllerId;
            std::vector<unsigned int> mJointIndices;
            size_t mJointCount;

        public:
            ControllerJointInfo () : mJointCount (0) {}
            virtual ~ControllerJointInfo () {};

            const COLLADAFW::UniqueId& getControllerId () const { return controllerId; }
            void setControllerId ( const COLLADAFW::UniqueId& val ) { controllerId = val; }

            std::vector<unsigned int>& getJointIndices () { return mJointIndices; }
            const std::vector<unsigned int>& getJointIndices () const { return mJointIndices; }

            const size_t& getJointCount () const { return mJointCount; }
            void setJointCount ( const size_t& val ) { mJointCount = val; }
        };

        /**
         * Create a data store object to hold all the MayaDM objects of the current controller.
         * The objects will be needed, to make all the connections.
         */
        class ControllerData
        {
        private:
            MayaDM::SkinCluster mSkinCluster;
            MayaDM::ObjectSet mSkinClusterSet;
            MayaDM::Tweak mTweak;
            MayaDM::ObjectSet mTweakSet;
            MayaDM::GroupId mGroupId1;
            MayaDM::GroupId mGroupId2;
            MayaDM::GroupParts mGroupParts1;
            MayaDM::GroupParts mGroupParts2;

        public:
            ControllerData () {}
            virtual ~ControllerData () {}

            const MayaDM::SkinCluster& getSkinCluster () const { return mSkinCluster; }
            void setSkinCluster ( const MayaDM::SkinCluster& val ) { mSkinCluster = val; }

            const MayaDM::ObjectSet& getSkinClusterSet () const { return mSkinClusterSet; }
            void setSkinClusterSet ( const MayaDM::ObjectSet& val ) { mSkinClusterSet = val; }

            const MayaDM::Tweak& getTweak () const { return mTweak; }
            void setTweak ( const MayaDM::Tweak& val ) { mTweak = val; }

            const MayaDM::ObjectSet& getTweakSet () const { return mTweakSet; }
            void setTweakSet ( const MayaDM::ObjectSet& val ) { mTweakSet = val; }

            const MayaDM::GroupId& getGroupId1 () const { return mGroupId1; }
            void setGroupId1 ( const MayaDM::GroupId& val ) { mGroupId1 = val; }

            const MayaDM::GroupId& getGroupId2 () const { return mGroupId2; }
            void setGroupId2 ( const MayaDM::GroupId& val ) { mGroupId2 = val; }

            const MayaDM::GroupParts& getGroupParts1 () const { return mGroupParts1; }
            void setGroupParts1 ( const MayaDM::GroupParts& val ) { mGroupParts1 = val; }

            const MayaDM::GroupParts& getGroupParts2 () const { return mGroupParts2; }
            void setGroupParts2 ( const MayaDM::GroupParts& val ) { mGroupParts2 = val; }
        };

    private:

        /**
        * The list of the unique maya controller names.
        */
        COLLADABU::IDList mSkinClusterIdList;
        COLLADABU::IDList mTweakIdList;

        /** 
        * The map holds the unique ids of the controller nodes to the maya specific nodes. 
        */
        UniqueIdMayaNodeMap mMayaControllerNodesMap;

        /** 
        * The map holds the unique ids of the skin controller nodes to the maya specific nodes. 
        */
        UniqueIdMayaNodeMap mMayaSkinControllerNodesMap;
	
        /**
        * The indices of joints assigned to a joint/vertex pair of a controller element. 
        * The number of pairs for the i'th vertex is given by the i'th value in mJointsPerVertex.
        */
        std::map<COLLADAFW::UniqueId, ControllerJointInfo> mJointInfosMap;

        /**
         * The map holds the skin controller objects for every source (mesh or morph controller).
         */
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*>> mSkinControllersMap;

        /**
         * The map holds a list of controller objects.
         */
        std::map<COLLADAFW::UniqueId, ControllerData> mControllers;

        /**
        * The initial index position in depend on the number of controllers.
        * If we have one or more controllers, the material groupIds have to 
        * connect to the geometry object groups on a later index position.
        */
        size_t mObjectGroupsInitialIndex;

	public:

        /** Constructor. */
		ControllerImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~ControllerImporter();

        /**
        * Stores the data of the current controller.
        * We need this informations before we import the geometries, to know if a geometry has
        * an controller.
        */
        void storeController ( const COLLADAFW::Controller* controller );

        /**
        * Imports the data of the current controller.
        */
        void importSkinControllerData ( const COLLADAFW::SkinControllerData* skinControllerData );

        /**
         * Create a maya skin cluster object and the skin cluster object set.
         * SkinCluster nodes are created during a smooth bindSkin. The purpose of the skinCluster 
         * is to store a weight per influence object for each component of each geometry that is 
         * deformed. Influence objects can be joints or any transform.
         * Note that unlike most deformers, a skinCluster node can deform only a single geometry. 
         * Therefore, if additional geometries are added to the skinCluster set, they will be ignored.
         */
        void createSkinCluster ( 
            const COLLADAFW::SkinControllerData* skinControllerData, 
            ControllerData& controllerData );

        /**
         * Make the connections for the controller.
         */
        void writeConnections ();

        /**
         * Returns the skin controller element, with the given skinControllerDataId. 
         * If no skin controller  uses the source, the method returns null.
         */
        const COLLADAFW::SkinController* findSkinControllerByDataId ( const COLLADAFW::UniqueId& skinControllerDataId );

        /**
        * Returns the skin controller element, which uses the given source. If no skin controller 
        * uses the source, the method returns null.
        */
        const std::vector<COLLADAFW::SkinController*>* findSkinControllersBySourceId ( const COLLADAFW::UniqueId& sourceId );

        /**
         * Returns the geometryId of the skinController's id.
         */
        const COLLADAFW::UniqueId* getControllersGeometryId ( const COLLADAFW::UniqueId& controllerId );

        /**
         * If we have one or more controllers, the material groupIds have to 
         * connect to the geometry object groups on a later index position.
         * The method returns the initial index position in depend on the number of controllers.
         */
        const size_t getObjectGroupsInitialIndex () const { return mObjectGroupsInitialIndex; }

        /**
        * The map holds a list of controller objects.
        */
        const ControllerData* findControllerData ( const COLLADAFW::UniqueId& skinControllerDataId );

    private:

        /**
        * The initial index position in depend on the number of controllers. 
        * Every controller has two groupIds, which have to be connected to the geometry object groups.
        * If we have one or more controllers, the material groupIds have to 
        * connect to the geometry object groups on a later index position.
        */
        void addControllerToObjectGroupsInitialIndex () { mObjectGroupsInitialIndex += 2; }

        /**
         * Make the controller connections to the joints.
         */
        void writeJointConnections ();

        /**
         * Make the controller connections to the geometry.
         */
        void writeGeometryConnections ();

        /**
         * Make all the other controller data connections.
         */
        void writeControllerConnections ();

        /**
         * Get the maya controller node with the given unique id.
         */
        MayaNode* findMayaControllerNode ( const COLLADAFW::UniqueId& controllerId );

        /**
        * Get the maya skin controller node with the given unique id.
        */
        MayaNode* findMayaSkinControllerDataNode ( const COLLADAFW::UniqueId& skinControllerId );

    };

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_CONTROLLERIMPORTER_H__
