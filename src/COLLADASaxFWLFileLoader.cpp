/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLAssetLoader.h"
#include "COLLADASaxFWLVisualSceneLoader.h"
#include "COLLADASaxFWLLibraryNodesLoader.h"
#include "COLLADASaxFWLLibraryMaterialsLoader.h"
#include "COLLADASaxFWLLibraryEffectsLoader.h"
#include "COLLADASaxFWLLibraryCamerasLoader.h"
#include "COLLADASaxFWLLibraryLightsLoader.h"
#include "COLLADASaxFWLLibraryImagesLoader.h"
#include "COLLADASaxFWLLibraryAnimationsLoader.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLGeometryLoader.h"
#include "COLLADASaxFWLSaxParserErrorHandler.h"
#include "COLLADASaxFWLSidAddress.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWAnimationList.h"

#include "COLLADAFWObject.h"

#if defined(COLLADABU_OS_WIN)
#pragma warning(disable:4355)
#endif


namespace COLLADASaxFWL
{

    //-----------------------------
	FileLoader::FileLoader ( Loader* colladaLoader, const COLLADABU::URI& fileURI, SaxParserErrorHandler* saxParserErrorHandler)
         : ColladaParserAutoGenPrivate(0, saxParserErrorHandler)
		 , mColladaLoader(colladaLoader)
		 , mFileURI(fileURI)
		 , mLibxmlSaxParse(this)
		 , mSidTreeRoot( new SidTreeNode("", 0) )
		 , mCurrentSidTreeNode( mSidTreeRoot )
	{
		setCallbackObject(this);
		registerUnknownElementHandler( &mRawUnknownElementHandler );
	}

	//-----------------------------
	FileLoader::~FileLoader()
	{
		delete mSidTreeRoot;
	}

	//-----------------------------
	bool FileLoader::load()
	{
		bool success = mLibxmlSaxParse.parseFile(mFileURI.toNativePath().c_str());
		return success;
	}

	//---------------------------------
	SidTreeNode* FileLoader::addToSidTree( const char* colladaId, const char* colladaSid )
	{
		mCurrentSidTreeNode = mCurrentSidTreeNode->createAndAddChild( colladaSid ? colladaSid : "");

		if ( colladaId && *colladaId )
		{
			mIdStringSidTreeNodeMap[colladaId] = mCurrentSidTreeNode;
		}
		return mCurrentSidTreeNode;
	}



	//---------------------------------
	void FileLoader::moveUpInSidTree()
	{
		assert(mCurrentSidTreeNode);
		mCurrentSidTreeNode = mCurrentSidTreeNode->getParent();
	}

	//---------------------------------
	const SidTreeNode* FileLoader::resolveSid( const SidAddress& sidAddress )
	{
		if ( !sidAddress.isValid() )
			return 0;

		SidTreeNode* startingPoint = 0;
		const String& id = sidAddress.getId();
		if ( !id.empty() )
		{
			// search for element with id 
			startingPoint = findSidTreeNodeByStringId( id );
		}

		if ( !startingPoint )
			return 0;

		SidTreeNode* currentNode = startingPoint;
		const SidAddress::SidList& sids = sidAddress.getSids();
		for ( size_t i = 0, count = sids.size(); i < count; ++i)
		{
			const String& currentSid = sids[i];
			currentNode = currentNode->findChildBySid( currentSid );
			
			if ( !currentNode )
				return 0;
		}
		return currentNode;
	}

	//-----------------------------
	SidTreeNode* FileLoader::findSidTreeNodeByStringId( const String& id )
	{
		IdStringSidTreeNodeMap::iterator it = mIdStringSidTreeNodeMap.find(id);
		if ( it == mIdStringSidTreeNodeMap.end() )
		{
			return 0;
		}
		else
		{
			return it->second;
		}
	}

	//-----------------------------
	void FileLoader::addToAnimationSidAddressBindings( const AnimationInfo& animationInfo, const SidAddress& targetSidAddress )
	{
		AnimationSidAddressBinding binding( animationInfo, targetSidAddress);
		mAnimationSidAddressBindings.push_back(binding);
	}

	COLLADAFW::AnimationList*& FileLoader::getAnimationListByUniqueId( const COLLADAFW::UniqueId& animationListUniqueId )
	{
		return mUniqueIdAnimationListMap[animationListUniqueId];
	}

	//-----------------------------
	void FileLoader::writeAndDeleteVisualScenes()
	{
		for ( size_t i = 0, count = mVisualScenes.size(); i < count; ++i)
		{
			COLLADAFW::VisualScene *visualScene = mVisualScenes[i];
			writer()->writeVisualScene(visualScene);
			FW_DELETE visualScene;
		}
	}

	//-----------------------------
	void FileLoader::writeAndDeleteEffects()
	{
		for ( size_t i = 0, count = mEffects.size(); i < count; ++i)
		{
			COLLADAFW::Effect *effect = mEffects[i];
			writer()->writeEffect(effect);
			FW_DELETE effect;
		}
	}

	//-----------------------------
	void FileLoader::createMissingAnimationLists()
	{
		AnimationSidAddressBindingList::const_iterator it = mAnimationSidAddressBindings.begin();
		for ( ; it != mAnimationSidAddressBindings.end(); ++it )
		{
			const AnimationSidAddressBinding& binding = *it;
			createMissingAnimationList( binding );

		}
	}

	//-----------------------------
	void FileLoader::createMissingAnimationList( const AnimationSidAddressBinding& binding )
	{
		const SidTreeNode* sidTreeNode = resolveSid( binding.sidAddress);
		if ( sidTreeNode )
		{
			if ( sidTreeNode->getTargetType() == SidTreeNode::TARGETTYPECLASS_ANIMATABLE )
			{
				COLLADAFW::Animatable* animatable = sidTreeNode->getAnimatableTarget();
				COLLADAFW::UniqueId animationListUniqueId = animatable->getAnimationList();
				if ( !animationListUniqueId.isValid() )
				{
					animationListUniqueId = getUniqueId( COLLADAFW::AnimationList::ID() );
					animatable->setAnimationList( animationListUniqueId );
				}
				COLLADAFW::AnimationList*& animationList = getAnimationListByUniqueId(animationListUniqueId);

				if ( !animationList )
				{
					animationList = new COLLADAFW::AnimationList( animationListUniqueId.getObjectId() );
				}

				// TODO handle this for arrays
				COLLADAFW::AnimationList::AnimationBinding animationBinding;
				animationBinding.animation = binding.animationInfo.uniqueId;
				animationBinding.animationClass = binding.animationInfo.animationClass;
				if ( animationBinding.animationClass == COLLADAFW::AnimationList::MATRIX4X4_ELEMENT )
				{
					animationBinding.firstIndex = binding.sidAddress.getFirstIndex();
					animationBinding.secondIndex = binding.sidAddress.getSecondIndex();
				}
				else
				{
					animationBinding.firstIndex = 0;
					animationBinding.secondIndex = 0;
				}
				animationList->getAnimationBindings().append( animationBinding );
			}
		}

	}

	//-----------------------------
	void FileLoader::writeAndDeleteAnimationLists()
	{
		UniqueIdAnimationListMap::const_iterator it = mUniqueIdAnimationListMap.begin();
		for ( ; it != mUniqueIdAnimationListMap.end(); ++it )
		{
			COLLADAFW::AnimationList* animationList = it->second;
			writer()->writeAnimationList( animationList );
			FW_DELETE animationList;
		}
	}

    //-----------------------------
    bool FileLoader::begin__asset ()
    {
		SaxVirtualFunctionTest(begin__asset());
		deleteFilePartLoader();
        AssetLoader* assetLoader = new AssetLoader(this);
        setPartLoader(assetLoader);
        setParser(assetLoader);
        return true;
    }

    //-----------------------------
	bool FileLoader::begin__visual_scene( const visual_scene__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__visual_scene(attributeData));
		deleteFilePartLoader();
		VisualSceneLoader* visualSceneLoader = new VisualSceneLoader(this, attributeData.id);
		setPartLoader(visualSceneLoader);
		setParser(visualSceneLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__geometry( const geometry__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__geometry(attributeData));
		deleteFilePartLoader();
		GeometryLoader* geometryLoader = new GeometryLoader(this);

		if ( attributeData.name )
			geometryLoader->setGeometryName ((const char *) attributeData.name);
        if ( attributeData.id )
            geometryLoader->setGeometryId ((const char *) attributeData.id);

		setPartLoader(geometryLoader);
		setParser(geometryLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_nodes( const library_nodes__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__library_nodes(attributeData));
		deleteFilePartLoader();
		LibraryNodesLoader* libraryNodesLoader = new LibraryNodesLoader(this);

		setPartLoader(libraryNodesLoader);
		setParser(libraryNodesLoader);
		addToSidTree( attributeData.id, 0);
		return true;
	}

	//-----------------------------
	const COLLADABU::URI& FileLoader::getFileUri()
	{
		return mFileURI;
	}

	//-----------------------------
	void FileLoader::setParser( IFilePartLoader* parserToBeSet )
	{
		setCallbackObject(parserToBeSet);
	}

	//-----------------------------
	bool FileLoader::begin__library_materials( const library_materials__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__library_materials(attributeData));
		deleteFilePartLoader();
		LibraryMaterialsLoader* libraryMaterialsLoader = new LibraryMaterialsLoader(this);

		setPartLoader(libraryMaterialsLoader);
		setParser(libraryMaterialsLoader);
		addToSidTree( attributeData.id, 0);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_effects( const library_effects__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__library_effects(attributeData));
		deleteFilePartLoader();
		LibraryEffectsLoader* libraryEffectsLoader = new LibraryEffectsLoader(this);

		setPartLoader(libraryEffectsLoader);
		setParser(libraryEffectsLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_cameras( const library_cameras__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__library_cameras(attributeData));
		deleteFilePartLoader();
		LibraryCamerasLoader* libraryCamerasLoader = new LibraryCamerasLoader(this);

		setPartLoader(libraryCamerasLoader);
		setParser(libraryCamerasLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_lights( const library_lights__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__library_lights(attributeData));
		deleteFilePartLoader();
		LibraryLightsLoader* libraryLightsLoader = new LibraryLightsLoader(this);

		setPartLoader(libraryLightsLoader);
		setParser(libraryLightsLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_images( const library_images__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__library_images(attributeData));
		deleteFilePartLoader();
		LibraryImagesLoader* libraryImagesLoader = new LibraryImagesLoader(this);

		setPartLoader(libraryImagesLoader);
		setParser(libraryImagesLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_animations( const library_animations__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__library_animations(attributeData));

		deleteFilePartLoader();
		LibraryAnimationsLoader* libraryAnimationsLoader = new LibraryAnimationsLoader(this);

		setPartLoader(libraryAnimationsLoader);
		setParser(libraryAnimationsLoader);
		return true;
	}

	//-----------------------------
    bool FileLoader::end__COLLADA()
    {
		SaxVirtualFunctionTest(end__COLLADA());
		createMissingAnimationLists();
		writeAndDeleteEffects();
		writeAndDeleteVisualScenes();
		writeAndDeleteAnimationLists();
        writer()->finish();
        return true;
    }

} // namespace COLLADASaxFWL
