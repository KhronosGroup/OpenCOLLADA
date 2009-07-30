/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_FILELOADER_H__
#define __COLLADASAXFWL_FILELOADER_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADASaxFWLTypes.h"
#include "COLLADASaxFWLIFilePartLoader.h"
#include "COLLADASaxFWLColladaParserAutoGen14Private.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADASaxFWLSidTreeNode.h"
#include "COLLADASaxFWLLoader.h"

#include "COLLADASaxFWLColladaParserAutoGen14Private.h"
#include "COLLADASaxFWLColladaParserAutoGen15Private.h"

#include "GeneratedSaxParserRawUnknownElementHandler.h"

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
	class SidTreeNode;
	class SidAddress;
	class FilePartLoader;
	class SaxParserErrorHandler;

	/** Loader to a COLLADA document. Referenced documents are not loaded.*/
	class FileLoader : public IFilePartLoader
    {
	public:
		enum ParsingStatus
		{
			PARSING_NOT_STARTED,        //!< Parsing of the .dae fiel has not been started
			PARSING_PARSING,            //!< The .dae file is beeing parsed
			PARSING_FINISHED            //!< Parsing of the .dae file has been finished
		};

	private:
        friend class VersionParser;

        /** Contains the binding of an animation to the referenced object. Required to create animation lists*/
		struct AnimationSidAddressBinding
		{
			AnimationSidAddressBinding( const AnimationInfo& _animationInfo, const SidAddress& _sidAddress)
				: animationInfo(_animationInfo), sidAddress(_sidAddress) {}
			AnimationInfo animationInfo;

			SidAddress sidAddress;
		};

		/** List of UniqueIdSidAddressPairs.*/
		typedef std::vector< AnimationSidAddressBinding > AnimationSidAddressBindingList;

		/** Maps unique ids of skin data to the sids of the joints of this skin controller.*/
		typedef std::map< COLLADAFW::UniqueId, StringList> SkinDataJointSidsMap;

		/** Maps unique ids of skin data to the source uri string.*/
		typedef std::map< COLLADAFW::UniqueId/*skin controller data*/, COLLADABU::URI/*source uri string*/> SkinDataSkinSourceMap;

		/** Set of SkinControllers.*/
		typedef std::set< COLLADAFW::SkinController, bool(*)(const COLLADAFW::SkinController& lhs, const COLLADAFW::SkinController& rhs)> SkinControllerSet;

	private:
		/** The version of the collada document.*/
		COLLADAVersion mCOLLADAVersion;

		/** The COLLADA loader */
		Loader* mColladaLoader;

		/** The uri of the file that should be imported.*/
		COLLADABU::URI mFileURI;

		/** Parsing status of the FileLoader.*/
		ParsingStatus mParsingStatus;

		/** The parent (in the notion of the framework  data model) of the currently parsed element.*/
		COLLADAFW::Object* mObject;

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

		/** List of all formulas in the file. They are send to the writer and deleted, when the file has 
		completely been parsed. This is required to resolve referenced elements like parameters and other formulas.*/
		Loader::FormulaList& mFormulas;

		/** List all the connections of animations and sid addresses of the targets.*/
		AnimationSidAddressBindingList mAnimationSidAddressBindings;

		/** Maps unique ids of animation list to the corresponding animation list. All animation list in this map 
		will be deleted by the FileLoader.*/
		Loader::UniqueIdAnimationListMap& mUniqueIdAnimationListMap;

		/** An unknown element handler that stores the unknown elements as raw xml data.*/
		GeneratedSaxParser::RawUnknownElementHandler mRawUnknownElementHandler;

		/** A combination of ObjectFlags, indicating which objects should be parsed during the 
		parse process.*/
		int mObjectFlags;

        /** A combination of ObjectFlags, indicating which objects have be parsed already.*/
        int& mParsedObjectFlags;

		/** Maps unique ids of skin data to the sids of the joints of this skin controller.*/
		SkinDataJointSidsMap mSkinDataJointSidsMap;

		/** Maps the Unique generated from the id of the COLLADA controller element to the 
		InstanceControllerDataList containing all instance controllers that reference the same controller.*/
		InstanceControllerDataListMap mInstanceControllerDataListMap;

		/** Maps unique ids of skin data to the source uri string.*/
		SkinDataSkinSourceMap mSkinDataSkinSourceMap;

		/** Set of all SkinController already created and written.*/
		SkinControllerSet mSkinControllerSet;

        /** Error handler to be used. */
        SaxParserErrorHandler* mSaxParserErrorHandler;

        /** Generated private parser for COLLADA 1.4. */
        COLLADASaxFWL14::ColladaParserAutoGen14Private* mPrivateParser14;
        /** Generated private parser for COLLADA 1.5. */
        COLLADASaxFWL15::ColladaParserAutoGen15Private* mPrivateParser15;

        /** Parser object which knows line and column numbers in parsed file. */
        GeneratedSaxParser::SaxParser* mXmlSaxParser;

    public:

        /** Constructor.
		@param colladaLoader The collada loader this file loader is being used by. Used to retrieve document 
		global properties.
		@param fileURI The name of the file to be loaded.
		@param saxParserErrorHandler The error handler all sax parser errors should be passed to.
		@param objectFlags Flags (Loader::ObjectFlags) of objects that should be parsed. Set these 
		if you don't want to parse the entire file, but only those parts required to create the objects in 
		objectFlags.
		@param parsedObjectFlags Flags (Loader::ObjectFlags) of objects already parsed by @a colladaLoader. 
		Will be set to all objects parsed after a call of load().*/
		FileLoader ( Loader* colladaLoader, 
			         const COLLADABU::URI& fileURI, 
					 SaxParserErrorHandler* saxParserErrorHandler, 
					 int objectFlags,
					 int& /*[in,out]*/ parsedObjectFlags);
 
        /** Destructor. */
        virtual ~FileLoader();

		/** The version of the collada document.*/
		COLLADAVersion getCOLLADAVersion() const { return mCOLLADAVersion; }

		/** Sets the parser to @a parserToBeSet.*/
        void setParser( COLLADASaxFWL14::ColladaParserAutoGen14* parserToBeSet );
        /** Sets the parser to @a parserToBeSet.*/
        void setParser( COLLADASaxFWL15::ColladaParserAutoGen15* parserToBeSet );

        /** Returns error handler for xml parser. */
        SaxParserErrorHandler* getErrorHandler() {return mSaxParserErrorHandler;}

		/** Returns the unknown element handler that stores the unknown elements as raw xml data.*/
		GeneratedSaxParser::RawUnknownElementHandler& getRawUnknownElementHandler() { return  mRawUnknownElementHandler; }

        /** Loads the data into the frame work data model.*/
		bool load();

		/** Returns the xml sax parser.*/
		const GeneratedSaxParser::SaxParser* getSaxParser() const { return mXmlSaxParser; }

		/** Returns a pointer to the file loader. */
		virtual FileLoader* getFileLoader() { return this; }

		/** Returns a pointer to the file loader. */
		virtual const FileLoader* getFileLoader() const { return this; }

		/** Returns the parsing status of the file loader.*/
		ParsingStatus getParsingStatus() const { return mParsingStatus; }

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
		void addFormula( COLLADAFW::Formula* formula ) { mFormulas.push_back(formula); }

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
		void addToSidTree( const char* colladaId, const char* colladaSid, TargetType* target )
		{
			SidTreeNode* newNode = addToSidTree( colladaId, colladaSid );
			newNode->setTarget( target );
		}

		/** Moves one node up in the sid tree. Call this method whenever an element, for which addToSidTree() was
		called, is closed.*/
		void moveUpInSidTree();

		/** Tries to resolve the a sidaddress. If resolving failed, null is returned.*/
		const SidTreeNode* resolveSid( const SidAddress& sidAddress);
		const SidTreeNode* resolveSid( const COLLADABU::URI& id, const String& sid);

		/** Tries to find element in sid tree with @a id. If not found, null is returned.*/ 
		SidTreeNode* findSidTreeNodeByStringId( const String& id); 

		/** Returns the absolute uri of the currently parsed file*/
		const COLLADABU::URI& getFileUri();

		/** The pair @a animationUniqueId, @a targetSidAddress to mUniqueIdSidAddressPairs.*/
		void addToAnimationSidAddressBindings( const AnimationInfo& animationInfo, const SidAddress& targetSidAddress );

		/** Returns the animation list with Unique id @a animationListUniqueId. If it could not be found, a new map 
		entry is created.*/
		COLLADAFW::AnimationList*& getAnimationListByUniqueId( const COLLADAFW::UniqueId& animationListUniqueId);

		/** Adds the pair @a skinDataUniqueId, @a jointSids to mSkinDataJointSidsMap.*/
		void addSkinDataJointSidsPair( const COLLADAFW::UniqueId& skinDataUniqueId, const StringList& jointSids );

		/** Returns the sids of the nodes used by a skin controller using skin data with unique id 
		@a skinDataUniqueId*/
		const StringList& getJointSidsBySkinDataUniqueId(const COLLADAFW::UniqueId& skinDataUniqueId) const;

		/** Adds the pair @a skinDataUniqueId, @a skinSource to mSkinDataSkinSourceMap.*/
		void addSkinDataSkinSourcePair( const COLLADAFW::UniqueId& skinDataUniqueId, const COLLADABU::URI& skinSource );

		/** Returns the skin source string of the skin controller, @a skinDataUniqueId was created from.*/
		const COLLADABU::URI* getSkinSourceBySkinDataUniqueId(const COLLADAFW::UniqueId& skinDataUniqueId) const;

		/** Returns the mapping of the Unique generated from the id of the COLLADA controller element to the 
		InstanceControllerDataList containing all instance controllers that reference the same controller.*/
		const InstanceControllerDataListMap& getInstanceControllerDataListMap() const { return mInstanceControllerDataListMap;}

		/** Returns the InstanceControllerDataList of the controller with Unique @a controllerUniqueId.*/
		const InstanceControllerDataList& getInstanceControllerDataListByControllerUniqueId(const COLLADAFW::UniqueId& controllerUniqueId)const;

		/** Returns the InstanceControllerDataList of the controller with Unique @a controllerUniqueId.*/
		InstanceControllerDataList& getInstanceControllerDataListByControllerUniqueId(const COLLADAFW::UniqueId& controllerUniqueId);

		/** Writes all the visual scenes.*/
		void writeVisualScenes();

		/** Writes all the library nodes.*/
		void writeLibraryNodes();

		/** Writes all the effects.*/
		void writeEffects();

		/** Writes all the lights.*/
		void writeLights();

		/** Writes all the cameras.*/
		void writeCameras();

		/** Creates all the animation lists.*/
		void createMissingAnimationLists();

		/** Stores the binding stored in @a binding in the appropriate animation list*/
		void createMissingAnimationList( const AnimationSidAddressBinding& binding );

		/** Creates a controller which instantiation is described by @a InstanceControllerData and that uses 
		the controller with id @a controllerDataUniqueId.*/
		bool createAndWriteSkinController( const InstanceControllerData& instanceControllerData, 
										   const COLLADAFW::UniqueId& controllerDataUniqueId,
							               const COLLADAFW::UniqueId& sourceUniqueId);

		/** Creates a controller which instantiation is described by @a InstanceControllerData and that uses 
		the controller with id @a controllerDataUniqueId. The sids used to resolve joints are @a sids.*/
		bool createAndWriteSkinController( const InstanceControllerData& instanceControllerData, 
										   const COLLADAFW::UniqueId& controllerDataUniqueId,
										   const COLLADAFW::UniqueId& sourceUniqueId,
										   const StringList& sids);


		/** Creates all skin controllers instantiated in the visual scene.*/
		bool createAndWriteSkinControllers();

		/** Writes all the morph controllers, stored in the loaders morph controller list.*/
		bool writeMorphControllers();

		/** Writes all animation lists.*/
		void writeAnimationLists();

	protected:
		/** Returns a pointer to the COLLADA loader. */
		Loader* getColladaLoader() { return mColladaLoader; }

		/** Returns a const pointer to the COLLADA document. */
		const Loader* getColladaLoader() const { return mColladaLoader; }

		/** Performs all the required post processing.:*/
		void postProcess();

        void setSaxParser( GeneratedSaxParser::SaxParser* parserToBeSet ) { mXmlSaxParser = parserToBeSet; }
        /** Sets the private parser to @a parserToBeSet.*/
        void setPrivateParser( COLLADASaxFWL14::ColladaParserAutoGen14Private* parserToBeSet )
        {mPrivateParser14 = parserToBeSet;}
        /** Sets the private parser to @a parserToBeSet.*/
        void setPrivateParser( COLLADASaxFWL15::ColladaParserAutoGen15Private* parserToBeSet )
        {mPrivateParser15 = parserToBeSet;}


    private:
		friend class VersionParser;

        /** Disable default copy ctor. */
		FileLoader( const FileLoader& pre );

        /** Disable default assignment operator. */
		const FileLoader& operator= ( const FileLoader& pre );


		/** Compares to SkinControllers. The comparison is suitable for using SkinController as key in stl
		containers but has no deeper meaning. The unique id of the SkinControllers themselves is not
		taken into account. Is basically compares if two SkinControllers describe exactly the same skin controller
		i.e. have the same source, joints and SkinControllerData.*/
		static bool compare( const COLLADAFW::SkinController& lhs, const COLLADAFW::SkinController& rhs);

		/** The version of the collada document.*/
		void setCOLLADAVersion(COLLADAVersion cOLLADAVersion);



	};
	
} // namespace COLLADASaxFWL

#endif // __COLLADASAXFWL_FILELOADER_H__
