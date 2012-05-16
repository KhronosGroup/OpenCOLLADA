/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_DOCUMENTPROCESSOR_H__
#define __COLLADASAXFWL_DOCUMENTPROCESSOR_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADASaxFWLTypes.h"
#include "COLLADASaxFWLIFilePartLoader.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADASaxFWLSidTreeNode.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLExtraDataElementHandler.h"


#include "COLLADAFWUniqueId.h"
#include "COLLADAFWSkinController.h"

#include "COLLADABUURI.h"

#include <set>


namespace COLLADABU
{
	class URI;
}

namespace COLLADAFW
{
	class IWriter;
	class Object;
}


namespace COLLADASaxFWL
{
	class SaxParserErrorHandler;

    /** TODO Documentation */
	class DocumentProcessor  : public IFilePartLoader	
	{
	protected:

		/** The version of the collada document.*/
		COLLADAVersion mCOLLADAVersion;

		/** The COLLADA loader */
		Loader* mColladaLoader;

		/** The current node within the sid tree.*/
		SidTreeNode *mCurrentSidTreeNode;

		/** Maps the id of a collada element to the corresponding sit tree node.*/
		Loader::IdStringSidTreeNodeMap& mIdStringSidTreeNodeMap;

		/** List of all visual scenes in the file. They are send to the writer and deleted, when the file has 
		completely been parsed.*/
		Loader::VisualSceneList& mVisualScenes;

		/** List of all library nodes in the file. They are send to the writer and deleted, when the file has 
		completely been parsed.*/
		Loader::LibraryNodesList& mLibraryNodes;

		/** List of all effects in the file. They are send to the writer and deleted, when the file has 
		completely been parsed.*/
		Loader::EffectList& mEffects;

		/** List of all lights in the file. They are send to the writer and deleted, when the file has 
		completely been parsed.*/
		Loader::LightList& mLights;

		/** List of all cameras in the file. They are send to the writer and deleted, when the file has 
		completely been parsed.*/
		Loader::CameraList& mCameras;

		/** List of all joints already created. They will be written as part of kinematics.*/
		KinematicsIntermediateData& mKinematicsIntermediateData;

		/** Maps ids of all formulas in the file to the formula itself. They are send to the writer and deleted, when the file has 
		completely been parsed. This is required to resolve referenced elements like parameters and other formulas.*/
		Loader::UniqueIdFormulaMap& mFormulasMap;

		/** List all the connections of animations and sid addresses of the targets.*/
		Loader::AnimationSidAddressBindingList& mAnimationSidAddressBindings;

		/** Maps unique ids of animation list to the corresponding animation list. All animation list in this map 
		will be deleted by the FileLoader.*/
		Loader::UniqueIdAnimationListMap& mUniqueIdAnimationListMap;

        /** The handler to handle the extra data elements. */
        ExtraDataElementHandler mExtraDataElementHandler;

		/** A combination of ObjectFlags, indicating which objects should be parsed during the 
		parse process.*/
		int mObjectFlags;

		/** A combination of ObjectFlags, indicating which objects have be parsed already.*/
		int& mParsedObjectFlags;

		/** Maps unique ids of skin data to the sids of the joints of this skin controller.*/
		Loader::SkinDataJointSidsMap& mSkinDataJointSidsMap;

		/** Maps the Unique generated from the id of the COLLADA controller element to the 
		InstanceControllerDataList containing all instance controllers that reference the same controller.*/
		Loader::InstanceControllerDataListMap& mInstanceControllerDataListMap;

		/** Maps unique ids of skin data to the source uri string.*/
		Loader::SkinDataSkinSourceMap& mSkinDataSkinSourceMap;

		/** Set of all SkinController already created and written.*/
		Loader::SkinControllerSet& mSkinControllerSet;

		/** Error handler to be used. */
		SaxParserErrorHandler* mSaxParserErrorHandler;

	public:
		/** Constructor.
		@param colladaLoader The collada loader this file loader is being used by. Used to retrieve document 
		global properties.
		@param saxParserErrorHandler The error handler all sax parser errors should be passed to.
		@param objectFlags Flags (Loader::ObjectFlags) of objects that should be parsed. Set these 
		if you don't want to parse the entire file, but only those parts required to create the objects in 
		objectFlags.
		@param parsedObjectFlags Flags (Loader::ObjectFlags) of objects already parsed by @a colladaLoader. 
		Will be set to all objects parsed after a call of load().*/
		DocumentProcessor ( Loader* colladaLoader, 
			                SaxParserErrorHandler* saxParserErrorHandler, 
			                int objectFlags,
			                int& /*[in,out]*/ parsedObjectFlags );

        /** Destructor. */
		virtual ~DocumentProcessor();

		/** The version of the collada document.*/
		COLLADAVersion getCOLLADAVersion() const { return mCOLLADAVersion; }

		/** Returns error handler for xml parser. */
		SaxParserErrorHandler* getErrorHandler() {return mSaxParserErrorHandler;}

        /** The handler to handle the extra data elements. */
        ExtraDataElementHandler& getExtraDataElementHandler () { return mExtraDataElementHandler; }

		/** A combination of ObjectFlags, indicating which objects should be parsed during the 
		parse process.*/
		int getObjectFlags() const { return mObjectFlags; }

		/** Adds @a visualScene to the list of visual scenes. It will be sent to the writer and delete by the
		file loader.*/
		void addVisualScene( COLLADAFW::VisualScene* visualScene ) { mVisualScenes.push_back(visualScene); }

		/** Adds @a libraryNodes to the list of library nodes. It will be sent to the writer and delete by the
		file loader.*/
		void addLibraryNodes( COLLADAFW::LibraryNodes* libraryNodes ) { mLibraryNodes.push_back(libraryNodes); }

		/** Adds @a effect to the list of effects. It will be sent to the writer and delete by the
		file loader.*/
		void addEffect( COLLADAFW::Effect* effect ) { mEffects.push_back(effect); }

		/** Adds @a light to the list of lights. It will be sent to the writer and delete by the
		file loader.*/
		void addLight( COLLADAFW::Light* light ) { mLights.push_back(light); }

		/** Adds @a camera to the list of cameras. It will be sent to the writer and delete by the
		file loader.*/
		void addCamera( COLLADAFW::Camera* camera ) { mCameras.push_back(camera); }

		/** Adds @a formula to the list of formulas. It will be sent to the writer and delete by the
		file loader.*/
		void addFormula( COLLADAFW::Formula* formula );

		/** Returns the formula with unique id @a uniqueId.*/
		COLLADAFW::Formula* getFormulaByUniqueId(const COLLADAFW::UniqueId& uniqueId)const;

		/** Adds @a joint to the list of joints. It will be written as part of kinematics, if used.*/
		void addJoint( COLLADAFW::Joint* joint ) { mKinematicsIntermediateData.getJoints().push_back(joint); }

		/** Adds @a joint to the list of InstanceJoints. It will be written as part of kinematics, if used.*/
		void addInstanceJoint( KinematicInstance* instanceJoint ) { mKinematicsIntermediateData.getInstanceJoints().push_back(instanceJoint); }

		/** Adds @a kinematicsModel to the list of joints. It will be written as part of kinematics, if used.*/
		void addKinematicsModel( KinematicsModel* kinematicsModel );

		/** Returns the kinematics model with URi @a uri or null if no kinematics model with this URI has been
		added using addKinematicsModel.*/
		KinematicsModel* getKinematicsModelByUri( const COLLADABU::URI& uri);

		/** Adds @a kinematicsController to the list of joints. It will be written as part of kinematics, if used.*/
		void addKinematicsController( KinematicsController* kinematicsController );

		/** Returns the kinematics controller with URi @a uri or null if no kinematics controller with this URI has been
		added using addKinematicsController.*/
		KinematicsController* getKinematicsControllerByUri( const COLLADABU::URI& uri);

		/** Adds @a kinematicsScene to the list of joints. It will be written as part of kinematics, if used.*/
		void addKinematicsScene( KinematicsScene* kinematicsScene );

		/** Returns the kinematics scene with URi @a uri or null if no kinematics scene with this URI has been
		added using addKinematicsScene.*/
		KinematicsScene* getKinematicsSceneByUri( const COLLADABU::URI& uri);

		/** Adds @a instanceKinematicsScene to the list of joints. It will be written as part of kinematics, if used.*/
		void addInstanceKinematicsScene( KinematicsInstanceKinematicsScene* instanceKinematicsScene ) { mKinematicsIntermediateData.getInstanceKinematicsScenes().push_back(instanceKinematicsScene); }

		/** Creates a new node in the sid tree. Call this method for every collada element that has an sid or that has an id 
		and can have children with sids. For every call of this method you have to call moveUpInSidTree() when the element
		is closed.
		@param id The id of the element. Might be 0;
		@param sid The sid of the element. Might be 0;
		*/
		SidTreeNode* addToSidTree( const char* colladaId, const char* colladaSid  );

		/** Creates a new node in the sid tree. Call this method for every collada element that has an sid or that has an id 
		and can have children with sids. For every call of this method you have to call moveUpInSidTree() when the element
		is closed.
		@tparam TargetType The type of the target assigned to the sid tree node.
		@param id The id of the element. Might be 0;
		@param sid The sid of the element. Might be 0;
		@param target The target assigned to the sid tree node
		*/
		template<class TargetType>
		SidTreeNode* addToSidTree( const char* colladaId, const char* colladaSid, TargetType* target )
		{
			SidTreeNode* newNode = addToSidTree( colladaId, colladaSid );
			newNode->setTarget( target );
			return newNode;
		}

		/** Moves one node up in the sid tree. Call this method whenever an element, for which addToSidTree() was
		called, is closed.*/
		void moveUpInSidTree();

		/** Tries to resolve the an ID. If resolving failed, null is returned.*/
		const SidTreeNode* resolveId( const String& id );

		/** Tries to resolve the a sidaddress. If resolving failed, null is returned.*/
		const SidTreeNode* resolveSid( const SidAddress& sidAddress);

		/** Tries to resolve the a sidaddress. If resolving failed, null is returned.*/
		const SidTreeNode* resolveSid( const COLLADABU::URI& id, const String& sid);

		/** Resolves an sid in the element referenced by @a instancingElement. It uses the sids ins @a sidAddress, 
		starting with sid with index @a firstSidIndex. */
		const SidTreeNode* resolveSidInInstance( const SidTreeNode* instancingElement, const SidAddress& sidAddress,  size_t firstSidIndex);

		/** Tries to find element in sid tree with @a id. If not found, null is returned.*/ 
		SidTreeNode* findSidTreeNodeByStringId( const String& id); 

		/** The pair @a animationUniqueId, @a targetSidAddress to mUniqueIdSidAddressPairs.*/
		void addToAnimationSidAddressBindings( const AnimationInfo& animationInfo, const SidAddress& targetSidAddress );

		/** Returns the animation list with Unique id @a animationListUniqueId. If it could not be found, a new map 
		entry is created.*/
		COLLADAFW::AnimationList*& getAnimationListByUniqueId( const COLLADAFW::UniqueId& animationListUniqueId);

		/** Adds the pair @a skinDataUniqueId, @a jointSids to mSkinDataJointSidsMap.*/
		void addSkinDataJointSidsPair( const COLLADAFW::UniqueId& skinDataUniqueId, const StringList& sidsOrIds, bool areIds );

		/** Returns the sids of the nodes used by a skin controller using skin data with unique id 
		@a skinDataUniqueId*/
		const Loader::JointSidsOrIds& getJointSidsOrIdsBySkinDataUniqueId(const COLLADAFW::UniqueId& skinDataUniqueId) const;

		/** Adds the pair @a skinDataUniqueId, @a skinSource to mSkinDataSkinSourceMap.*/
		void addSkinDataSkinSourcePair( const COLLADAFW::UniqueId& skinDataUniqueId, const COLLADABU::URI& skinSource );

		/** Returns the skin source string of the skin controller, @a skinDataUniqueId was created from.*/
		const COLLADABU::URI* getSkinSourceBySkinDataUniqueId(const COLLADAFW::UniqueId& skinDataUniqueId) const;

		/** Returns the mapping of the Unique generated from the id of the COLLADA controller element to the 
		InstanceControllerDataList containing all instance controllers that reference the same controller.*/
		const Loader::InstanceControllerDataListMap& getInstanceControllerDataListMap() const { return mInstanceControllerDataListMap;}

		/** Returns the InstanceControllerDataList of the controller with Unique @a controllerUniqueId.*/
		const Loader::InstanceControllerDataList& getInstanceControllerDataListByControllerUniqueId(const COLLADAFW::UniqueId& controllerUniqueId)const;

		/** Returns the InstanceControllerDataList of the controller with Unique @a controllerUniqueId.*/
		Loader::InstanceControllerDataList& getInstanceControllerDataListByControllerUniqueId(const COLLADAFW::UniqueId& controllerUniqueId);

		/** Returns the intermediate data to build up the kinematics after the COLLADA file has been parsed.*/
		const KinematicsIntermediateData& getKinematicsIntermediateData() const { return mKinematicsIntermediateData; }

		/** Creates a controller which instantiation is described by @a InstanceControllerData and that uses 
		the controller with id @a controllerDataUniqueId.*/
		bool createAndWriteSkinController( const Loader::InstanceControllerData& instanceControllerData, 
			const COLLADAFW::UniqueId& controllerDataUniqueId,
			const COLLADAFW::UniqueId& sourceUniqueId);

		/** Creates a controller which instantiation is described by @a InstanceControllerData and that uses 
		the controller with id @a controllerDataUniqueId.
		@param sidsOrIds The sids or ids used to resolve joints.
		@param resolveIds If true, the strings in @a sidsOrIds are resolved as Ids, otherwise as Sids
		*/
		bool createAndWriteSkinController( const Loader::InstanceControllerData& instanceControllerData, 
			const COLLADAFW::UniqueId& controllerDataUniqueId,
			const COLLADAFW::UniqueId& sourceUniqueId,
			const StringList& sidsOrIds,
			bool resolveIds);


		/** Creates all skin controllers instantiated in the visual scene.*/
		bool createAndWriteSkinControllers();



	protected:
		/** Returns a pointer to the COLLADA loader. */
		Loader* getColladaLoader() { return mColladaLoader; }

		/** Returns a const pointer to the COLLADA document. */
		const Loader* getColladaLoader() const { return mColladaLoader; }

	private:
		friend class VersionParser;

        /** Disable default copy ctor. */
		DocumentProcessor( const DocumentProcessor& pre );

        /** Disable default assignment operator. */
		const DocumentProcessor& operator= ( const DocumentProcessor& pre );


		/** The version of the collada document.*/
		void setCOLLADAVersion(COLLADAVersion cOLLADAVersion);
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_DOCUMENTPROCESSOR_H__
