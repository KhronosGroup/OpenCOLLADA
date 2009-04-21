/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	class VisualScene;
	class Effect;
}


namespace COLLADASaxFWL
{
	class Loader;
	class SidTreeNode;
	class SidAddress;
	class FilePartLoader;
	class SaxParserErrorHandler;

	/** Loader to a COLLADA document. Referenced documents are not loaded.*/
	class FileLoader : public IFilePartLoader, public ColladaParserAutoGenPrivate
    {
	private:
		/** Maps the id of a collada element to the corresponding sit tree node.*/
		typedef std::map<String /*id*/, SidTreeNode*> IdStringSidTreeNodeMap;

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

		/** Maps unique ids of animation list to the corresponding animation list.*/
		typedef std::map< COLLADAFW::UniqueId , COLLADAFW::AnimationList* > UniqueIdAnimationListMap;

		/** List of visual scenes.*/
		typedef std::vector<COLLADAFW::VisualScene*> VisualSceneList;

		/** List of effects.*/
		typedef std::vector<COLLADAFW::Effect*> EffectList;

	private:
	
		/** The collada loader */
		Loader* mColladaLoader;

		/** The uri of the file that should be imported.*/
		COLLADABU::URI mFileURI;

		/** The parent (in the notion of the framework  data model) of the currently parsed element.*/
		COLLADAFW::Object* mObject;

		GeneratedSaxParser::LibxmlSaxParser mLibxmlSaxParse;

		/** The root node of the sid tree. This tree is used to resolve sids.*/
		SidTreeNode *mSidTreeRoot;

		/** The current node within the sid tree.*/
		SidTreeNode *mCurrentSidTreeNode;

		/** Maps an uri to the corresponding node in the sid tree.*/
		IdStringSidTreeNodeMap mIdStringSidTreeNodeMap;

		/** List of all visual scenes in the file. They are send to the writer and deleted, when the file has 
		completely been parsed.*/
		VisualSceneList mVisualScenes;

		/** List of all effects in the file. They are send to the writer and deleted, when the file has 
		completely been parsed.*/
		EffectList mEffects;

		/** List all the connections of animations and sid addresses of the targets.*/
		AnimationSidAddressBindingList mAnimationSidAddressBindings;

		/** Maps unique ids of animation list to the corresponding animation list. All animation list in this map 
		will be deleted by the FileLoader.*/
		UniqueIdAnimationListMap mUniqueIdAnimationListMap;

		/** An unknown element handler that stores the unknown elements as raw xml data.*/
		GeneratedSaxParser::RawUnknownElementHandler mRawUnknownElementHandler;

	public:

        /** Constructor.
		@param colladaLoader The collada loader this file loader is being used by. Used to retrieve document 
		global properties.
		@param fileURI The name of the file to be loaded.*/
		FileLoader ( Loader* colladaLoader, const COLLADABU::URI& fileURI, SaxParserErrorHandler* saxParserErrorHandler = 0 );

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


		/** Adds @a visualScene to the list of visual scenes. It will be sent to the writer and delete by the
		file loader.*/
		void addVisualScene( COLLADAFW::VisualScene* visualScene ) { mVisualScenes.push_back(visualScene); }

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
		void writeAndDeleteVisualScenes();

		/** Writes all the visual scenes.*/
		void writeAndDeleteEffects();

		/** Creates all the animation lists.*/
		void createMissingAnimationLists();

		/** Stores the binding stored in @a binding in the appropriate animation list*/
		void createMissingAnimationList( const AnimationSidAddressBinding& binding );


		/** Writes all animation lists.*/
		void writeAndDeleteAnimationLists();

	protected:
		/** Returns a pointer to the collada loader. */
		Loader* getColladaLoader() { return mColladaLoader; }

		/** Returns a const pointer to the collada document. */
		const Loader* getColladaLoader() const { return mColladaLoader; }

		/** Informs about the end of reading the collada file. */
		virtual bool end__COLLADA();

        /** Sax callback function for the beginning of the collada document asset information.*/
        virtual bool begin__asset();

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

    private:

        /** Disable default copy ctor. */
		FileLoader( const FileLoader& pre );

        /** Disable default assignment operator. */
		const FileLoader& operator= ( const FileLoader& pre );
	};
	
} // namespace COLLADASaxFWL

#endif // __COLLADASAXFWL_FILELOADER_H__
