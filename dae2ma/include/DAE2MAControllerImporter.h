/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_CONTROLLERIMPORTER_H__
#define __DAE2MA_CONTROLLERIMPORTER_H__

#include "DAE2MAPrerequisites.h"
#include "DAE2MABaseImporter.h"
#include "DAE2MAMorphAnimation.h"

#include "MayaDMSkinCluster.h"
#include "MayaDMTweak.h"
#include "MayaDMObjectSet.h"
#include "MayaDMGroupId.h"
#include "MayaDMGroupParts.h"
#include "MayaDMBlendShape.h"

#include "COLLADAFWSkinController.h"


namespace DAE2MA
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
        static const String BLEND_SHAPE_NAME;
        static const String TWEAK_NAME;
        static const String SET_NAME;

    public:

        /**
        * Create a data store object to hold all the MayaDM objects of the current controller.
        * The objects will be needed, to make all the connections.
        */
        class GeometryFilterData
        {
        public:
            enum GeometryFilterType
            {
                GEOMETRY_FILTER_TYPE_SKIN_CLUSTER,
                GEOMETRY_FILTER_TYPE_BLEND_SHAPE, 
                GEOMETRY_FILTER_TYPE_UNKNOWN
            };
        private:
            GeometryFilterType mGeometryFilterType;
            MayaDM::GeometryFilter* mGeometryFilter;
            MayaDM::ObjectSet mGeometryFilterSet;
            MayaDM::Tweak mTweak;
            MayaDM::ObjectSet mTweakSet;
            MayaDM::GroupId mGeometryFilterGroupId;
            MayaDM::GroupId mTweakGroupId;
            MayaDM::GroupParts mGeometryFilterGroupParts;
            MayaDM::GroupParts mTweakGroupParts;

        public:
            GeometryFilterData ( GeometryFilterType geometryFilterType ) 
                : mGeometryFilterType ( geometryFilterType ) 
            {}

            virtual ~GeometryFilterData () 
            {
                delete mGeometryFilter;
            }

            const GeometryFilterData::GeometryFilterType& getGeometryFilterType () const { return mGeometryFilterType; }

            MayaDM::GeometryFilter* getGeometryFilter () { return mGeometryFilter; }
            const MayaDM::GeometryFilter* getGeometryFilter () const { return mGeometryFilter; }
            void setGeometryFilter ( MayaDM::GeometryFilter* val ) { mGeometryFilter = val; }

            const MayaDM::ObjectSet& getGeometryFilterSet () const { return mGeometryFilterSet; }
            void setGeometryFilterSet ( const MayaDM::ObjectSet& val ) { mGeometryFilterSet = val; }

            const MayaDM::Tweak& getTweak () const { return mTweak; }
            void setTweak ( const MayaDM::Tweak& val ) { mTweak = val; }

            const MayaDM::ObjectSet& getTweakSet () const { return mTweakSet; }
            void setTweakSet ( const MayaDM::ObjectSet& val ) { mTweakSet = val; }

            const MayaDM::GroupId& getGeometryFilterGroupId () const { return mGeometryFilterGroupId; }
            void setGeometryFilterGroupId ( const MayaDM::GroupId& val ) { mGeometryFilterGroupId = val; }

            const MayaDM::GroupId& getTweakGroupId () const { return mTweakGroupId; }
            void setTweakGroupId ( const MayaDM::GroupId& val ) { mTweakGroupId = val; }

            const MayaDM::GroupParts& getGeometryFilterGroupParts () const { return mGeometryFilterGroupParts; }
            void setGeometryFilterGroupParts ( const MayaDM::GroupParts& val ) { mGeometryFilterGroupParts = val; }

            const MayaDM::GroupParts& getTweakGroupParts () const { return mTweakGroupParts; }
            void setTweakGroupParts ( const MayaDM::GroupParts& val ) { mTweakGroupParts = val; }
        };

        /**
        * The MayaSkinClusterData class is a MayaGeometryFilterData class with a skinCluster object.
        */
        class SkinClusterData : public GeometryFilterData
        {
        public:
            SkinClusterData () 
                : GeometryFilterData ( GeometryFilterData::GEOMETRY_FILTER_TYPE_SKIN_CLUSTER ) 
            {}
            virtual ~SkinClusterData () {}

            MayaDM::SkinCluster* getSkinCluster () { return (MayaDM::SkinCluster*)getGeometryFilter (); }
            void setSkinCluster ( MayaDM::SkinCluster* val ) { setGeometryFilter ( val ); }

            const MayaDM::ObjectSet& getSkinClusterSet () const { return getGeometryFilterSet (); }
            void setSkinClusterSet ( const MayaDM::ObjectSet& val ) { setGeometryFilterSet ( val ); }
        };

        /**
        * The MayaBlendShapeData class is a MayaGeometryFilterData class with a blendShape object.
        */
        class BlendShapeData : public GeometryFilterData
        {
        public:
            BlendShapeData () 
                : GeometryFilterData ( GeometryFilterData::GEOMETRY_FILTER_TYPE_BLEND_SHAPE ) 
            {}
            virtual ~BlendShapeData () {}

            MayaDM::BlendShape* getBlendShape () { return (MayaDM::BlendShape*)getGeometryFilter (); }
            void setBlendShape ( MayaDM::BlendShape* val ) { setGeometryFilter ( val ); }

            const MayaDM::ObjectSet& getBlendShapeSet () const { return getGeometryFilterSet (); }
            void setBlendShapeSet ( const MayaDM::ObjectSet& val ) { setGeometryFilterSet ( val ); }
        };

    private:

        /** 
        * The map holds the unique ids of the controller nodes to the maya specific nodes. 
        */
        UniqueIdMayaNodeMap mMayaControllerNodesMap;

        /** 
        * The map holds the unique ids of the skin controller data ids. 
        */
        UniqueIdVec mSkinControllerDataIds;
	
        /** 
        * The map holds the unique ids of the morph controller ids. 
        */
        UniqueIdVec mMorphControllerIds;

        /**
         * The map holds the skin controller objects for every source (mesh or skin controller).
         */
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::SkinController*> > mSkinControllersMap;

        /**
        * The map holds the morph controller objects for every source (mesh).
        */
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> > mMorphControllersMap;

        /**
        * The map holds the morph controller objects for every morph target object (mesh).
        */
        std::map<COLLADAFW::UniqueId, std::vector<COLLADAFW::MorphController*> > mMorphTargetsMap;

        /**
         * The map holds a list of controller objects.
         */
        std::map<COLLADAFW::UniqueId, GeometryFilterData*> mGeometryFilterDataMap;

        /**
        * The initial index position in depend on the number of controllers.
        * If we have one or more controllers, the material groupIds have to 
        * connect to the geometry object groups on a later index position.
        */
        UniqueIdSizeTMap mObjectGroupsInitialIndexMap;

        /**
         * The map contains for every morph controller the morph targets (mesh or controller objects).
         */
        UniqueIdUniqueIdsMap mMorphTargetIds;

        /**
        * The map holds for every animationListId the unique id of corresponding node.
        */
        std::map <COLLADAFW::UniqueId, MorphAnimation> mMorphAnimationMap;

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
        * Returns true, if the import was successful.
        */
        bool importSkinControllerData ( const COLLADAFW::SkinControllerData* skinControllerData );

        /**
         * Imports the copied morph controllers.
         */
        void importMorphControllers ();

        /**
         * Make the connections for the controller.
         */
        void writeConnections ();

        /**
        * Returns the controller element, which uses the given source. If no controller 
        * uses the source, the method returns null. Can be a skin or morph controller.
        */
        const COLLADAFW::Controller* findController ( const COLLADAFW::UniqueId& controllerId );

        /**
        * Returns the morph controller element, which uses the given source. If no morph controller 
        * uses the source, the method returns null.
        */
        const COLLADAFW::MorphController* findMorphController ( const COLLADAFW::UniqueId& controllerId );

        /**
        * Returns the skin controller element, which uses the given source. If no skin controller 
        * uses the source, the method returns null.
        */
        const COLLADAFW::SkinController* findSkinController ( const COLLADAFW::UniqueId& controllerId );

        /**
         * Returns true, if there exist a controller element, which use this geometry.
         */
        bool isSourceControlled ( const COLLADAFW::UniqueId& sourceId );

        /**
        * Returns the skin controller element, which uses the given source. 
        */
        std::vector<COLLADAFW::Controller*> findControllersBySourceId ( const COLLADAFW::UniqueId& sourceId );

        /**
        * Returns the morph controller element, which uses the given source. If no morph controller 
        * uses the source, the method returns null.
        */
        std::vector<COLLADAFW::MorphController*>* findMorphControllersBySourceId ( const COLLADAFW::UniqueId& sourceId );

        /**
        * Returns the morph controller element, which uses the given source. If no morph controller 
        * uses the source, the method returns null.
        */
        const std::vector<COLLADAFW::MorphController*>* findMorphControllersBySourceId ( const COLLADAFW::UniqueId& sourceId ) const;

        /**
        * Returns the morph controller element, which uses the given geometry as a morph target. 
        * If no morph controller uses the source, the method returns null.
        */
        std::vector<COLLADAFW::MorphController*>* findMorphControllersByMorphTargetId ( const COLLADAFW::UniqueId& geometryId );

        /**
        * Returns the morph controller element, which uses the given geometry as a morph target. 
        * If no morph controller uses the source, the method returns null.
        */
        const std::vector<COLLADAFW::MorphController*>* findMorphControllersByMorphTargetId ( const COLLADAFW::UniqueId& geometryId ) const;

        /**
        * Returns the skin controller element, which uses the given source. If no skin controller 
        * uses the source, the method returns null.
        */
        std::vector<COLLADAFW::SkinController*>* findSkinControllersBySourceId ( const COLLADAFW::UniqueId& sourceId );

        /**
        * Returns the skin controller element, which uses the given source. If no skin controller 
        * uses the source, the method returns null.
        */
        const std::vector<COLLADAFW::SkinController*>* findSkinControllersBySourceId ( const COLLADAFW::UniqueId& sourceId ) const;

        /**
         * Returns the geometryId of the skinController's id.
         */
        const COLLADAFW::UniqueId* getControllerSourceId ( const COLLADAFW::UniqueId& controllerId ) const;

        /**
         * If we have one or more controllers, the material groupIds have to 
         * connect to the geometry object groups on a later index position.
         * The method returns the initial index position in depend on the number of controllers.
         */
        const size_t findObjectGroupsInitialIndex ( const COLLADAFW::UniqueId& controllerId ) const;

        /**
        * The map holds a list of maya geometry filter objects.
        */
        const GeometryFilterData* findGeometryFilterData ( const COLLADAFW::UniqueId& controllerId );

        /**
        * The map holds for every animationListId the unique id of corresponding node.
        */
        const MorphAnimation* findMorphAnimation ( const COLLADAFW::UniqueId& animationListId );

    private:

        /**
         * Imports the current morph controller.
         * Returns true, if the import was successful.
         */
        const bool importMorphController ( 
            COLLADAFW::MorphController* morphController );

        /**
        * Create a maya skin cluster object and the skin cluster object set with all needed maya
        * objects to create the connections of the skinCluster.
        * SkinCluster nodes are created during a smooth bindSkin. The purpose of the skinCluster 
        * is to store a weight per influence object for each component of each geometry that is 
        * deformed. Influence objects can be joints or any transform.
        * Note that unlike most deformers, a skinCluster node can deform only a single geometry. 
        * Therefore, if additional geometries are added to the skinCluster set, they will be ignored.
        */
        const String createSkinCluster ( 
            const COLLADAFW::SkinControllerData* skinControllerData, 
            SkinClusterData& skinClusterData );

        /**
        * Create a maya blend shape object and the skin cluster object set with all needed maya
        * objects to create the connections of the skinCluster.
        * BlendShape nodes takes geometry as input and deforms it based on pairs of target shapes 
        * and weight values, to produce a new shape that is the specified blending of the input shapes. 
        */
        const String createBlendShape ( 
            COLLADAFW::MorphController* morphController, 
            BlendShapeData& blendShapeData );

        /**
        * Create all maya objects, which are needed to connect a maya skinCluster or a blendShape 
        * to a geometry.
        */
        void createGeometryFilterBindingObjects ( 
            GeometryFilterData &controllerData, 
            const String& geometryFilterName );

        /**
        * Write the weights into the maya ascii file.
        */
        void writeWeights ( 
            MayaDM::SkinCluster* skinCluster, 
            std::vector<double>& currentWeightList, 
            const size_t influenceIndex, 
            const unsigned int jointStartIndex, 
            const unsigned int jointEndIndex );

        /**
        * The initial index position in depend on the number of controllers. 
        * Every controller has two groupIds, which have to be connected to the geometry object groups.
        * If we have one or more controllers, the material groupIds have to 
        * connect to the geometry object groups on a later index position.
        */
        void addControllerToObjectGroupsInitialIndex ( const COLLADAFW::UniqueId& controllerId );

        /**
        * Returns true, if the skin controller data with the given unique id is already exported.
        */
        const bool skinControllerDataExported ( const COLLADAFW::UniqueId& skinControllerDataId ) const;

        /**
        * Returns true, if the morph controller with the given unique id is already exported.
        */
        bool morphControllerExported ( const COLLADAFW::UniqueId& morphControllerId );

        /**
        * Returns the skin controller element, with the given skinControllerDataId. 
        * If no skin controller  uses the source, the method returns null.
        */
        const std::vector<COLLADAFW::SkinController*> findSkinControllersByDataId ( const COLLADAFW::UniqueId& skinControllerDataId );

        /**
        * Get the maya controller node with the given unique id.
        */
        MayaNode* findMayaControllerNode ( const COLLADAFW::UniqueId& controllerId );

        /**
         * Returns a vector with all morph targets of the current morph controller.
         * If no targets exist, 0 will be returned.
         */
        const UniqueIdVec* findMorphTargets ( const COLLADAFW::UniqueId& controllerId );

        /**
         * Make the controller connections to the joints.
         */
        void connectSkinControllerJoints ();

        /**
         * Make the connections to the morph controller targets.
         */
        void connectMorphControllerTargets ();

        /**
         * Make the controller connections to the geometry.
         */
        void connectGeometries ();

        const UniqueIdVec* getSkinControllerTransforms ( 
            const COLLADAFW::UniqueId& controllerId );

        /**
         * Make all the other controller data connections.
         */
        void connectControllers ();

    };

} // namespace DAE2MA

#endif // __DAE2MA_CONTROLLERIMPORTER_H__
