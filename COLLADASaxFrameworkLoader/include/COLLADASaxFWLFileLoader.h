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
#include "COLLADASaxFWLColladaParserAutoGenPrivate.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADASaxFWLSidTreeNode.h"
#include "COLLADASaxFWLLoader.h"

#include "GeneratedSaxParserLibxmlSaxParser.h"
#include "GeneratedSaxParserRawUnknownElementHandler.h"

#include "COLLADAFWUniqueId.h"

#include "COLLADABUURI.h"


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
	class FileLoader : public IFilePartLoader, public ColladaParserAutoGenPrivate
    {
	private:
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


	private:
	
		/** The collada loader */
		Loader* mColladaLoader;

		/** The uri of the file that should be imported.*/
		COLLADABU::URI mFileURI;

		/** The parent (in the notion of the framework  data model) of the currently parsed element.*/
		COLLADAFW::Object* mObject;

		GeneratedSaxParser::LibxmlSaxParser mLibxmlSaxParse;

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

		/** The function map we use to parse the COLLADA file. It contains only those elements that are required 
		to parse all the objects listed in @a mObjectFlags.*/
		ColladaParserAutoGenPrivate::ElementFunctionMap mFunctionMap;

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

		/** Sets the parser to @a parserToBeSet.*/
		void setParser(IFilePartLoader* parserToBeSet);

		/** Loads the data into the frame work data model.*/
		bool load();

		/** Returns a pointer to the file loader. */
		virtual FileLoader* getFileLoader() { return this; }

		/** Returns a pointer to the file loader. */
		virtual const FileLoader* getFileLoader() const { return this; }

		/** Returns the UnknownElementHandler. It contains all the data contained in unknown elements.*/
		GeneratedSaxParser::RawUnknownElementHandler& getRawUnknownElementHandler() { return mRawUnknownElementHandler; }

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

		/** Tries to find element in sid tree with @a id. If not found, null is returned.*/ 
		SidTreeNode* findSidTreeNodeByStringId( const String& id); 

		/** Returns the absolute uri of the currently parsed file*/
		const COLLADABU::URI& getFileUri();

		/** The pair @a animationUniqueId, @a targetSidAddress to mUniqueIdSidAddressPairs.*/
		void addToAnimationSidAddressBindings( const AnimationInfo& animationInfo, const SidAddress& targetSidAddress );

		/** Returns the animation list with Unique id @a animationListUniqueId. If it could not be found, a new map 
		entry is created.*/
		COLLADAFW::AnimationList*& getAnimationListByUniqueId( const COLLADAFW::UniqueId& animationListUniqueId);

		/** Writes all the visual scenes.*/
		void writeVisualScenes();

		/** Writes all the library nodes.*/
		void writeLibraryNodes();

		/** Writes all the visual scenes.*/
		void writeEffects();

		/** Creates all the animation lists.*/
		void createMissingAnimationLists();

		/** Stores the binding stored in @a binding in the appropriate animation list*/
		void createMissingAnimationList( const AnimationSidAddressBinding& binding );


		/** Writes all animation lists.*/
		void writeAnimationLists();

	protected:
		/** Returns a pointer to the collada loader. */
		Loader* getColladaLoader() { return mColladaLoader; }

		/** Returns a const pointer to the collada document. */
		const Loader* getColladaLoader() const { return mColladaLoader; }

		/** Informs about the end of reading the collada file. */
		virtual bool end__COLLADA();

        /** Sax callback function for the beginning of the collada document asset information.*/
        virtual bool begin__asset();

        /** Starts loading the scene.*/
        virtual bool begin__scene();

		/** Starts loading a visual scene.*/
		virtual bool begin__geometry( const geometry__AttributeData& attributeData );

		/** Starts loading a visual scene.*/
		virtual bool begin__visual_scene( const visual_scene__AttributeData& attributeData );

		/** Starts loading a library nodes.*/
		virtual bool begin__library_nodes( const library_nodes__AttributeData& attributeData );

		/** Starts loading a library materials.*/
		virtual bool begin__library_materials( const library_materials__AttributeData& attributeData );

		/** Starts loading a library effects.*/
		virtual bool begin__library_effects( const library_effects__AttributeData& attributeData );

		/** Starts loading a library cameras.*/
		virtual bool begin__library_cameras( const library_cameras__AttributeData& attributeData );

		/** Starts loading a library lights.*/
		virtual bool begin__library_lights( const library_lights__AttributeData& attributeData );

		/** Starts loading a library images.*/
		virtual bool begin__library_images( const library_images__AttributeData& attributeData );

		/** Starts loading a library animations.*/
		virtual bool begin__library_animations( const library_animations__AttributeData& attributeData );

		/** Performs all the required post processing.:*/
		void postProcess();

    private:

        /** Disable default copy ctor. */
		FileLoader( const FileLoader& pre );

        /** Disable default assignment operator. */
		const FileLoader& operator= ( const FileLoader& pre );
	};
	
} // namespace COLLADASaxFWL

#endif // __COLLADASAXFWL_FILELOADER_H__
