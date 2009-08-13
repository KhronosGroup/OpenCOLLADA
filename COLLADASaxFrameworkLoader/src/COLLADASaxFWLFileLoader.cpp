/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLSaxParserErrorHandler.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADASaxFWLVersionParser.h"

#include "COLLADAFWConstants.h"
#include "COLLADAFWVisualScene.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWSkinController.h"
#include "COLLADAFWMorphController.h"
#include "COLLADAFWIWriter.h"

#include "COLLADAFWObject.h"

#if defined(GENERATEDSAXPARSER_XMLPARSER_LIBXML)
#	include "GeneratedSaxParserLibxmlSaxParser.h"
#elif defined(GENERATEDSAXPARSER_XMLPARSER_EXPAT)
#	include "GeneratedSaxParserExpatSaxParser.h"
#else
#	error "No prepocesser flag set to chose the xml parser to use"
#endif

#if defined(COLLADABU_OS_WIN)
#pragma warning(disable:4355)
#endif

using namespace COLLADASaxFWL14;

namespace COLLADASaxFWL
{

    //-----------------------------
	FileLoader::FileLoader ( Loader* colladaLoader, 
							 const COLLADABU::URI& fileURI, 
							 SaxParserErrorHandler* saxParserErrorHandler, 
							 int objectFlags,
							 int& parsedObjectFlags)
         : mColladaLoader( colladaLoader )
		 , mFileURI( fileURI )
         , mParsingStatus( PARSING_NOT_STARTED )
		 , mCurrentSidTreeNode( colladaLoader->getSidTreeRoot() )
		 , mIdStringSidTreeNodeMap( colladaLoader->getIdStringSidTreeNodeMap() )
		 , mVisualScenes( colladaLoader->getVisualScenes() )
		 , mLibraryNodes( colladaLoader->getLibraryNodes() )
		 , mEffects( colladaLoader->getEffects() )
		 , mLights( colladaLoader->getLights() )
		 , mCameras( colladaLoader->getCameras() )
		 , mFormulas( colladaLoader->getFormulaList() )
		 , mUniqueIdAnimationListMap( colladaLoader->getUniqueIdAnimationListMap() )
		 , mObjectFlags( objectFlags )
		 , mParsedObjectFlags( parsedObjectFlags )
		 , mSkinControllerSet( compare )
         , mSaxParserErrorHandler( saxParserErrorHandler )
         , mPrivateParser14( 0 )
         , mPrivateParser15( 0 )
         , mXmlSaxParser( 0 )
	{

	}

	//-----------------------------
	FileLoader::~FileLoader()
	{
	}

	//-----------------------------
	bool FileLoader::load()
	{
        VersionParser parser( mSaxParserErrorHandler, this, mObjectFlags, mParsedObjectFlags );
        mParsingStatus = PARSING_PARSING;
        bool success = parser.createAndLaunchParser();
        mParsingStatus = PARSING_FINISHED;
        return success;
	}

	//---------------------------------
	void FileLoader::postProcess()
	{
		if ( (getObjectFlags() & Loader::ANIMATION_LIST_FLAG) != 0 )
		{
			createMissingAnimationLists();
		}

		if ( (getObjectFlags() & Loader::EFFECT_FLAG) != 0 )
		{
			writeEffects();
		}

		if ( (getObjectFlags() & Loader::LIGHT_FLAG) != 0 )
		{
			writeLights();
		}

		if ( (getObjectFlags() & Loader::CAMERA_FLAG) != 0 )
		{
			writeCameras();
		}

		if ( (getObjectFlags() & Loader::CONTROLLER_FLAG) != 0 )
		{
			createAndWriteSkinControllers();
			writeMorphControllers();
		}

		if ( (getObjectFlags() & Loader::VISUAL_SCENES_FLAG) != 0 )
		{
			writeVisualScenes();
		}

		if ( (getObjectFlags() & Loader::LIBRARY_NODES_FLAG) != 0 )
		{
			writeLibraryNodes();
		}

		if ( (getObjectFlags() & Loader::ANIMATION_LIST_FLAG) != 0 )
		{
			writeAnimationLists();
		}

		if ( (getObjectFlags() & Loader::FORMULA_FLAG) != 0 )
		{
			linkAndWriteFormulas();
		}

		if ( (getObjectFlags() & Loader::KINEMATICS_FLAG) != 0 )
		{
			createAndWriteKinematicsScene();
		}

		writer()->finish();
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

		size_t i = 0;

		if ( !sids.empty() && (sids.front() == startingPoint->getSid()) )
		{
			// the first one is the start element it self exclude it from recursive search
			i = 1;
		}

		for ( size_t count = sids.size(); i < count; ++i)
		{
			const String& currentSid = sids[i];
			currentNode = currentNode->findChildBySid( currentSid );
			
			if ( !currentNode )
				return 0;
		}
		return currentNode;
	}

	//---------------------------------
	const SidTreeNode* FileLoader::resolveSid( const COLLADABU::URI& id,  const String& sid)
	{
		SidAddress sidAddress(id, sid);
		return resolveSid(sidAddress);
	}

	//-----------------------------
	SidTreeNode* FileLoader::findSidTreeNodeByStringId( const String& id )
	{
		Loader::IdStringSidTreeNodeMap::iterator it = mIdStringSidTreeNodeMap.find(id);
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
	void FileLoader::addSkinDataJointSidsPair( const COLLADAFW::UniqueId& skinDataUniqueId, const StringList& jointSids )
	{
		mSkinDataJointSidsMap[skinDataUniqueId]=jointSids;
	}

	//-----------------------------
	const StringList& FileLoader::getJointSidsBySkinDataUniqueId( const COLLADAFW::UniqueId& skinDataUniqueId ) const
	{
		SkinDataJointSidsMap::const_iterator it = mSkinDataJointSidsMap.find(skinDataUniqueId);
		if ( it != mSkinDataJointSidsMap.end() )
		{
			return it->second;
		}
		else
		{
			return EMPTY_STRING_LIST;
		}
	}

	//-----------------------------
	void FileLoader::addSkinDataSkinSourcePair( const COLLADAFW::UniqueId& skinDataUniqueId, const COLLADABU::URI& skinSource )
	{
		mSkinDataSkinSourceMap[skinDataUniqueId]=skinSource;
	}

	//-----------------------------
	const COLLADABU::URI* FileLoader::getSkinSourceBySkinDataUniqueId( const COLLADAFW::UniqueId& skinDataUniqueId ) const
	{
		SkinDataSkinSourceMap::const_iterator it = mSkinDataSkinSourceMap.find(skinDataUniqueId);
		if ( it != mSkinDataSkinSourceMap.end() )
		{
			return &it->second;
		}
		else
		{
			return 0;
		}
	}

	//-----------------------------
	const FileLoader::InstanceControllerDataList& FileLoader::getInstanceControllerDataListByControllerUniqueId( const COLLADAFW::UniqueId& controllerUniqueId ) const
	{
		InstanceControllerDataListMap::const_iterator it = mInstanceControllerDataListMap.find(controllerUniqueId);
		if ( it != mInstanceControllerDataListMap.end())
		{
			return it->second;
		}
		else
		{
			return EMPTY_INSTANCE_CONTROLLER_DATALIST;
		}

	}

	//-----------------------------
	FileLoader::InstanceControllerDataList& FileLoader::getInstanceControllerDataListByControllerUniqueId( const COLLADAFW::UniqueId& controllerUniqueId )
	{
		return mInstanceControllerDataListMap[controllerUniqueId];
	}


	//-----------------------------
	void FileLoader::writeVisualScenes()
	{
		for ( size_t i = 0, count = mVisualScenes.size(); i < count; ++i)
		{
			COLLADAFW::VisualScene *visualScene = mVisualScenes[i];
			writer()->writeVisualScene(visualScene);
		}
	}

	//-----------------------------
	void FileLoader::writeLibraryNodes()
	{
		for ( size_t i = 0, count = mLibraryNodes.size(); i < count; ++i)
		{
			COLLADAFW::LibraryNodes *libraryNodes = mLibraryNodes[i];
			writer()->writeLibraryNodes(libraryNodes);
		}
	}

	//-----------------------------
	void FileLoader::writeEffects()
	{
		for ( size_t i = 0, count = mEffects.size(); i < count; ++i)
		{
			COLLADAFW::Effect *effect = mEffects[i];
			writer()->writeEffect(effect);
		}
	}

	//-----------------------------
	void FileLoader::writeLights()
	{
		for ( size_t i = 0, count = mLights.size(); i < count; ++i)
		{
			COLLADAFW::Light *light = mLights[i];
			writer()->writeLight(light);
		}
	}

	//-----------------------------
	void FileLoader::writeCameras()
	{
		for ( size_t i = 0, count = mCameras.size(); i < count; ++i)
		{
			COLLADAFW::Camera *camera = mCameras[i];
			writer()->writeCamera(camera);
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
				
				switch ( binding.sidAddress.getMemberSelection() )
				{
				case SidAddress::MEMBER_SELECTION_ONE_INDEX:
					animationBinding.firstIndex = binding.sidAddress.getFirstIndex();
					animationBinding.secondIndex = 0;
					animationBinding.animationClass = COLLADAFW::AnimationList::ARRAY_ELEMENT_1D;
					break;
				case SidAddress::MEMBER_SELECTION_TWO_INDICES:
					animationBinding.firstIndex = binding.sidAddress.getFirstIndex();
					animationBinding.secondIndex = binding.sidAddress.getSecondIndex();
					animationBinding.animationClass = COLLADAFW::AnimationList::ARRAY_ELEMENT_2D;
					break;
				default:
					animationBinding.firstIndex = 0;
					animationBinding.secondIndex = 0;
				}

				animationList->getAnimationBindings().append( animationBinding );
			}
		}

	}

	//-----------------------------
	bool FileLoader::createAndWriteSkinController( const InstanceControllerData& instanceControllerData, 
												   const COLLADAFW::UniqueId& controllerDataUniqueId,
												   const COLLADAFW::UniqueId& sourceUniqueId)
	{
		if ( !controllerDataUniqueId.isValid() )
			return false;
		const StringList& sids = getJointSidsBySkinDataUniqueId( controllerDataUniqueId );
		return createAndWriteSkinController( instanceControllerData, controllerDataUniqueId, sourceUniqueId, sids );
	}

	//-----------------------------
	bool FileLoader::createAndWriteSkinController( const InstanceControllerData& instanceControllerData, 
												   const COLLADAFW::UniqueId& controllerDataUniqueId, 
												   const COLLADAFW::UniqueId& sourceUniqueId,
												   const StringList& sids)
	{
		if ( !controllerDataUniqueId.isValid() )
			return false;

		const URIList& skeletonRoots = instanceControllerData.skeletonRoots;

		NodeList joints;

		for ( StringList::const_iterator it = sids.begin(); it != sids.end(); ++it)
		{
			const String sid = *it;

			bool jointFound = false;

			for ( URIList::const_iterator skeletonIt = skeletonRoots.begin(); skeletonIt != skeletonRoots.end(); ++skeletonIt)
			{
				const COLLADABU::URI& skeletonUri = *skeletonIt;

				SidAddress sidAddress( skeletonUri, sid );
				const SidTreeNode* joint = resolveSid( sidAddress );
				if ( joint )
				{
					// the joint could be found
					if ( joint->getTargetType() != SidTreeNode::TARGETTYPECLASS_OBJECT )
					{
						// we could resolve the sid, but is not a joint/node
						break;
					}

					const COLLADAFW::Object* object = joint->getObjectTarget();

					if ( object->getClassId() != COLLADAFW::Node::ID() )
					{
						// we could resolve the sid, but is not a joint/node
						break;
					}

					joints.push_back( (COLLADAFW::Node*)object );

					jointFound = true;
					//search for the next joint
					break;
				}
			}
			if ( !jointFound )
			{
				std::stringstream msg;
				msg << "Could not resolve sid \"" << sid << "\" referenced in skin controller.";
				return handleFWLError( SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg.str() );
		}
		}

		COLLADAFW::SkinController skinController( getUniqueId(COLLADAFW::SkinController::ID()).getObjectId());

		COLLADAFW::UniqueIdArray &jointsUniqueIds = skinController.getJoints();
		jointsUniqueIds.allocMemory( joints.size() );
		jointsUniqueIds.setCount(joints.size());

		size_t i = 0;
		NodeList::const_iterator it = joints.begin();
		for ( ; it != joints.end(); ++it, ++i )
		{
			const COLLADAFW::Node* node = *it;
			jointsUniqueIds[i] = node->getUniqueId();
		}

		skinController.setSkinControllerData(controllerDataUniqueId);
		skinController.setSource(sourceUniqueId);

		bool success = true;
		// Check if we have already wrote a skin controller that describes the same controller, i.e. has same
		// source, skin data and joints. If so, do not write it again and reference the previously used in the
		// scene graph
		const COLLADAFW::SkinController* skinControllerToWrite = 0;
		SkinControllerSet::const_iterator skinControllerIt = mSkinControllerSet.find( skinController );
		if ( skinControllerIt == mSkinControllerSet.end() )
		{
			skinControllerToWrite = &skinController;
			success = writer()->writeController(skinControllerToWrite);
			mSkinControllerSet.insert( skinController );
		}
		else
		{
			skinControllerToWrite = &(*skinControllerIt);
		}

		instanceControllerData.instanceController->setInstanciatedObjectId( skinControllerToWrite->getUniqueId() );

		return success;
	}


	//-----------------------------
	bool FileLoader::createAndWriteSkinControllers()
	{
		InstanceControllerDataListMap::const_iterator mapIt = mInstanceControllerDataListMap.begin();

		for ( ; mapIt != mInstanceControllerDataListMap.end(); ++mapIt )
		{
			const COLLADAFW::UniqueId& skinDataUniqueId = mapIt->first;
			const InstanceControllerDataList& instanceControllerDataList = mapIt->second;

			InstanceControllerDataList::const_iterator listIt = instanceControllerDataList.begin();
		
			for ( ; listIt != instanceControllerDataList.end(); ++listIt)
			{
				const InstanceControllerData& instanceControllerData = *listIt;
				const COLLADABU::URI* sourceUrl = getSkinSourceBySkinDataUniqueId( skinDataUniqueId );

				if ( !sourceUrl )
				{
					// TODO handle error
					continue;
				}

				const COLLADAFW::UniqueId& sourceUniqueId = getUniqueIdFromUrl(*sourceUrl);
				if ( !sourceUniqueId.isValid() )
				{
					// TODO handle error
					continue;
				}
				if ( !createAndWriteSkinController( instanceControllerData, skinDataUniqueId, sourceUniqueId ) )
					return false;
			}
		}
		return true;
	}

	//-----------------------------
	bool FileLoader::writeMorphControllers()
	{
		const Loader::MorphControllerList& morphControllerList = mColladaLoader->getMorphControllerList();
		Loader::MorphControllerList::const_iterator it = morphControllerList.begin();
		for ( ; it != morphControllerList.end(); ++it)
		{
			const COLLADAFW::MorphController* morphController = *it;
			const COLLADAFW::UniqueId& morphControllerUniqueId = morphController->getUniqueId();
			const InstanceControllerDataList& instanceControllerDataList = getInstanceControllerDataListByControllerUniqueId(morphControllerUniqueId);

			// Set the InstanciatedObjectId of the instance controller
			InstanceControllerDataList::const_iterator it = instanceControllerDataList.begin();
			for ( ; it != instanceControllerDataList.end(); ++it )
			{
				const InstanceControllerData& instanceControllerData = *it;
				instanceControllerData.instanceController->setInstanciatedObjectId( morphControllerUniqueId );
			}

			if ( ! writer()->writeController( morphController ) )
				return false;
		}
		return true;
	}

	//-----------------------------
	void FileLoader::writeAnimationLists()
	{
		Loader::UniqueIdAnimationListMap::const_iterator it = mUniqueIdAnimationListMap.begin();
		for ( ; it != mUniqueIdAnimationListMap.end(); ++it )
		{
			COLLADAFW::AnimationList* animationList = it->second;
			writer()->writeAnimationList( animationList );
		}
	}

	//-----------------------------
	const COLLADABU::URI& FileLoader::getFileUri()
	{
		return mFileURI;
	}

	//-----------------------------
    void FileLoader::setParser( COLLADASaxFWL14::ColladaParserAutoGen14* parserToBeSet )
	{
        assert(mPrivateParser14);
        mPrivateParser14->setCallbackObject(parserToBeSet);
	}

    //-----------------------------
    void FileLoader::setParser( COLLADASaxFWL15::ColladaParserAutoGen15* parserToBeSet )
    {
        assert(mPrivateParser15);
        mPrivateParser15->setCallbackObject(parserToBeSet);
    }

	//-----------------------------
	bool FileLoader::compare( const COLLADAFW::SkinController& lhs, const COLLADAFW::SkinController& rhs )
	{

		if (lhs.getSkinControllerData() < rhs.getSkinControllerData() )
			return true;
		if (lhs.getSkinControllerData() > rhs.getSkinControllerData() )
			return false;

		if (lhs.getSource() < rhs.getSource() )
			return true;
		if (lhs.getSource() > rhs.getSource() )
			return false;

		const COLLADAFW::UniqueIdArray& lhsJoints = lhs.getJoints();
		const COLLADAFW::UniqueIdArray& rhsJoints = rhs.getJoints();
		size_t lhsJointsCount = lhsJoints.getCount();
		size_t rhsJointsCount = rhsJoints.getCount();
		if (lhsJointsCount < rhsJointsCount )
			return true;
		if (lhsJointsCount > rhsJointsCount )
			return false;

		for ( size_t i = 0; i < lhsJointsCount; ++i)
		{
			const COLLADAFW::UniqueId& lhsJoint = lhsJoints[i];
			const COLLADAFW::UniqueId& rhsJoint = rhsJoints[i];
			if (lhsJoint < rhsJoint )
				return true;
			if (lhsJoint > rhsJoint )
				return false;
		}

		return false;
	}

	void FileLoader::setCOLLADAVersion( COLLADAVersion cOLLADAVersion )
	{
		mCOLLADAVersion = cOLLADAVersion;
		mColladaLoader->setCOLLADAVersion(cOLLADAVersion);
	}
} // namespace COLLADASaxFWL
