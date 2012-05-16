/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLDocumentProcessor.h"

#include "COLLADAFWNode.h"
#include "COLLADAFWIWriter.h"


namespace COLLADASaxFWL
{

	//-----------------------------
	DocumentProcessor::DocumentProcessor ( Loader* colladaLoader, 
		SaxParserErrorHandler* saxParserErrorHandler, 
		int objectFlags,
		int& parsedObjectFlags)
		: mColladaLoader( colladaLoader )
		, mCurrentSidTreeNode( colladaLoader->getSidTreeRoot() )
		, mIdStringSidTreeNodeMap( colladaLoader->getIdStringSidTreeNodeMap() )
		, mVisualScenes( colladaLoader->getVisualScenes() )
		, mLibraryNodes( colladaLoader->getLibraryNodes() )
		, mEffects( colladaLoader->getEffects() )
		, mLights( colladaLoader->getLights() )
		, mCameras( colladaLoader->getCameras() )
		, mKinematicsIntermediateData( colladaLoader->getKinematicsIntermediateData() )
		, mFormulasMap( colladaLoader->getFormulasMap() )
		, mAnimationSidAddressBindings( colladaLoader->getAnimationSidAddressBindings() )
		, mUniqueIdAnimationListMap( colladaLoader->getUniqueIdAnimationListMap() )
		, mObjectFlags( objectFlags )
		, mParsedObjectFlags( parsedObjectFlags )
		, mSkinDataJointSidsMap( colladaLoader->getSkinDataJointSidsMap() )
		, mInstanceControllerDataListMap( colladaLoader->getInstanceControllerDataListMap() )
		, mSkinDataSkinSourceMap( colladaLoader->getSkinDataSkinSourceMap() )
		, mSkinControllerSet( colladaLoader->getSkinControllerSet() )
		, mSaxParserErrorHandler( saxParserErrorHandler )
	{

	}	
    //------------------------------
	DocumentProcessor::~DocumentProcessor()
	{
	}

	//---------------------------------
	SidTreeNode* DocumentProcessor::addToSidTree( const char* colladaId, const char* colladaSid )
	{
		mCurrentSidTreeNode = mCurrentSidTreeNode->createAndAddChild( colladaSid ? colladaSid : "");

		if ( colladaId && *colladaId )
		{
			mIdStringSidTreeNodeMap[colladaId] = mCurrentSidTreeNode;
		}
		return mCurrentSidTreeNode;
	}

	//---------------------------------
	void DocumentProcessor::moveUpInSidTree()
	{
		COLLADABU_ASSERT(mCurrentSidTreeNode);
		mCurrentSidTreeNode = mCurrentSidTreeNode->getParent();
	}

	//---------------------------------
	const SidTreeNode* DocumentProcessor::resolveId( const String& id )
	{
		return findSidTreeNodeByStringId( id );
	}

	//---------------------------------
	const SidTreeNode* DocumentProcessor::resolveSid( const SidAddress& sidAddress )
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
			SidTreeNode* childNode = currentNode->findChildBySid( currentSid );

			if ( !childNode )
			{
				// we could not find the sid as a child of currentNode
				// lets try if the sid is in an instantiated element
				return resolveSidInInstance( currentNode, sidAddress, i);
			}
			else
			{
				currentNode = childNode;
			}
		}
		return currentNode;
	}

	//---------------------------------
	const SidTreeNode* DocumentProcessor::resolveSid( const COLLADABU::URI& id,  const String& sid)
	{
		SidAddress sidAddress(id, sid);
		return resolveSid(sidAddress);
	}

	//---------------------------------
	const SidTreeNode* DocumentProcessor::resolveSidInInstance( const SidTreeNode* instancingElement, const SidAddress& sidAddress,  size_t firstSidIndex)
	{
		// the sid address we use to resolve the sid in the instantiated element
		const COLLADABU::URI* uri = 0;

		//check if instancingElement instantiates an element
		switch ( instancingElement->getTargetType() )
		{
		case SidTreeNode::TARGETTYPECLASS_INTERMEDIATETARGETABLE:
			{
				IntermediateTargetable* iTargetable = instancingElement->getIntermediateTargetableTarget();
				switch ( iTargetable->getClassId() )
				{
				case INTERMEDIATETARGETABLE_TYPE::KINEMATICS_INSTANCE:
					{
						KinematicInstance* ki = intermediateTargetableSafeCast<KinematicInstance>(iTargetable);
						uri = &ki->getUrl();
						break;
					}
				}

			}
			// 		case SidTreeNode::TARGETTYPECLASS_OBJECT:
			// 			{
			// 				COLLADAFW::Object* iObject = instancingElement->getObjectTarget();
			// 				switch ( iObject->getClassId() )
			// 				{
			// 				case COLLADAFW::COLLADA_TYPE::JOINT:
			// 					{
			// 						KinematicInstance* ki = (KinematicInstance*) iObject;
			// 						uri = &ki->getUrl();
			// 					}
			// 				}
			// 			}
		}

		if ( !uri )
		{
			// we could not find an instantiated element
			return 0;
		}

		SidAddress newSidAddress( *uri );
		const SidAddress::SidList& allSids = sidAddress.getSids();
		size_t allSidsCount = allSids.size();
		for ( size_t i = firstSidIndex; i < allSidsCount; ++i)
		{
			newSidAddress.appendSid( allSids[i] );
		}	
		newSidAddress.setFirstIndex( sidAddress.getFirstIndex() );
		newSidAddress.setSecondIndex( sidAddress.getSecondIndex() );
		newSidAddress.setMemberSelection( sidAddress.getMemberSelection() );
		newSidAddress.setMemberSelectionName( sidAddress.getMemberSelectionName() );
		return resolveSid( newSidAddress );
	}


	//-----------------------------
	SidTreeNode* DocumentProcessor::findSidTreeNodeByStringId( const String& id )
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
	void DocumentProcessor::addToAnimationSidAddressBindings( const AnimationInfo& animationInfo, const SidAddress& targetSidAddress )
	{
		Loader::AnimationSidAddressBinding binding( animationInfo, targetSidAddress);
		mAnimationSidAddressBindings.push_back(binding);
	}

	COLLADAFW::AnimationList*& DocumentProcessor::getAnimationListByUniqueId( const COLLADAFW::UniqueId& animationListUniqueId )
	{
		return mUniqueIdAnimationListMap[animationListUniqueId];
	}

	//-----------------------------
	void DocumentProcessor::addSkinDataJointSidsPair( const COLLADAFW::UniqueId& skinDataUniqueId, const StringList& sidsOrIds, bool areIds )
	{
		Loader::JointSidsOrIds jointSidsOrIds;
		jointSidsOrIds.sidsOrIds = sidsOrIds;
		jointSidsOrIds.areIds = areIds;
		mSkinDataJointSidsMap[skinDataUniqueId]=jointSidsOrIds;
	}

	//-----------------------------
	const Loader::JointSidsOrIds& DocumentProcessor::getJointSidsOrIdsBySkinDataUniqueId( const COLLADAFW::UniqueId& skinDataUniqueId ) const
	{
		Loader::SkinDataJointSidsMap::const_iterator it = mSkinDataJointSidsMap.find(skinDataUniqueId);
		if ( it != mSkinDataJointSidsMap.end() )
		{
			return it->second;
		}
		else
		{
			return Loader::EMPTY_JOINTSIDSORIDS;
		}
	}

	//-----------------------------
	void DocumentProcessor::addSkinDataSkinSourcePair( const COLLADAFW::UniqueId& skinDataUniqueId, const COLLADABU::URI& skinSource )
	{
		mSkinDataSkinSourceMap[skinDataUniqueId]=skinSource;
	}

	//-----------------------------
	const COLLADABU::URI* DocumentProcessor::getSkinSourceBySkinDataUniqueId( const COLLADAFW::UniqueId& skinDataUniqueId ) const
	{
		Loader::SkinDataSkinSourceMap::const_iterator it = mSkinDataSkinSourceMap.find(skinDataUniqueId);
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
	const Loader::InstanceControllerDataList& DocumentProcessor::getInstanceControllerDataListByControllerUniqueId( const COLLADAFW::UniqueId& controllerUniqueId ) const
	{
		Loader::InstanceControllerDataListMap::const_iterator it = mInstanceControllerDataListMap.find(controllerUniqueId);
		if ( it != mInstanceControllerDataListMap.end())
		{
			return it->second;
		}
		else
		{
			return Loader::EMPTY_INSTANCE_CONTROLLER_DATALIST;
		}

	}

	//-----------------------------
	Loader::InstanceControllerDataList& DocumentProcessor::getInstanceControllerDataListByControllerUniqueId( const COLLADAFW::UniqueId& controllerUniqueId )
	{
		return mInstanceControllerDataListMap[controllerUniqueId];
	}



	//-----------------------------
	void DocumentProcessor::setCOLLADAVersion( COLLADAVersion cOLLADAVersion )
	{
		mCOLLADAVersion = cOLLADAVersion;
		mColladaLoader->setCOLLADAVersion(cOLLADAVersion);
	}

	//-----------------------------
	bool DocumentProcessor::createAndWriteSkinController( const Loader::InstanceControllerData& instanceControllerData, 
		const COLLADAFW::UniqueId& controllerDataUniqueId,
		const COLLADAFW::UniqueId& sourceUniqueId)
	{
		if ( !controllerDataUniqueId.isValid() )
			return false;
		const Loader::JointSidsOrIds& sidsOrIds = getJointSidsOrIdsBySkinDataUniqueId( controllerDataUniqueId );
		return createAndWriteSkinController( instanceControllerData, controllerDataUniqueId, sourceUniqueId, sidsOrIds.sidsOrIds, sidsOrIds.areIds );
	}

	//-----------------------------
	bool DocumentProcessor::createAndWriteSkinController( const Loader::InstanceControllerData& instanceControllerData, 
		const COLLADAFW::UniqueId& controllerDataUniqueId, 
		const COLLADAFW::UniqueId& sourceUniqueId,
		const StringList& sidsOrIds,
		bool resolveIds)
	{
		if ( !controllerDataUniqueId.isValid() )
			return false;

		const URIList& skeletonRoots = instanceControllerData.skeletonRoots;

		NodeList joints;

		for ( StringList::const_iterator it = sidsOrIds.begin(); it != sidsOrIds.end(); ++it)
		{
			const String sidOrId = *it;

			bool jointFound = false;

			if ( resolveIds )
			{
				const SidTreeNode* joint = resolveSid( sidOrId );
				if ( joint )
				{
					// the joint could be found
					if ( joint->getTargetType() == SidTreeNode::TARGETTYPECLASS_OBJECT )
					{
						const COLLADAFW::Object* object = joint->getObjectTarget();

						if ( object->getClassId() == COLLADAFW::Node::ID() )
						{
							joints.push_back( (COLLADAFW::Node*)object );

							jointFound = true;
							//search for the next joint
						}
						else
						{
							// we could resolve the sid, but is not a joint/node
						}
					}
					else
					{
						// we could resolve the sid, but is not a joint/node
					}
				}
			}
			else
			{
				for ( URIList::const_iterator skeletonIt = skeletonRoots.begin(); skeletonIt != skeletonRoots.end(); ++skeletonIt)
				{
					const COLLADABU::URI& skeletonUri = *skeletonIt;

					SidAddress sidAddress( skeletonUri, sidOrId );
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
			}


			if ( !jointFound )
			{
				std::stringstream msg;
				msg << "Could not resolve " << (resolveIds ? "id" : "sid") << " \"";
				msg << sidOrId << "\" referenced in skin controller.";
				if ( handleFWLError( SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg.str() ))
				{
					return false;
				}
			}
		}

		COLLADAFW::SkinController skinController( createUniqueId(COLLADAFW::SkinController::ID()));

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
		Loader::SkinControllerSet::const_iterator skinControllerIt = mSkinControllerSet.find( skinController );
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
	bool DocumentProcessor::createAndWriteSkinControllers()
	{
		Loader::InstanceControllerDataListMap::const_iterator mapIt = mInstanceControllerDataListMap.begin();

		for ( ; mapIt != mInstanceControllerDataListMap.end(); ++mapIt )
		{
			const COLLADAFW::UniqueId& skinDataUniqueId = mapIt->first;
			const Loader::InstanceControllerDataList& instanceControllerDataList = mapIt->second;

			Loader::InstanceControllerDataList::const_iterator listIt = instanceControllerDataList.begin();

			for ( ; listIt != instanceControllerDataList.end(); ++listIt)
			{
				const Loader::InstanceControllerData& instanceControllerData = *listIt;
				const COLLADABU::URI* sourceUrl = getSkinSourceBySkinDataUniqueId( skinDataUniqueId );

				if ( !sourceUrl )
				{
					// TODO handle error
					continue;
				}

				const COLLADAFW::UniqueId& sourceUniqueId = getUniqueIdByUrl(*sourceUrl, true);
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

	//------------------------------
	void DocumentProcessor::addKinematicsScene( KinematicsScene* kinematicsScene )
	{
		const COLLADABU::URI& uri = kinematicsScene->getUri();
		mKinematicsIntermediateData.getKinematicsScenes().insert(std::make_pair(uri, kinematicsScene));
	}

	//------------------------------
	KinematicsScene* DocumentProcessor::getKinematicsSceneByUri( const COLLADABU::URI& uri )
	{
		const KinematicsIntermediateData::KinematicsSceneMap& map = mKinematicsIntermediateData.getKinematicsScenes();
		KinematicsIntermediateData::KinematicsSceneMap::const_iterator it = map.find(uri);
		if ( it != map.end() )
		{
			return it->second;
		}
		else
		{
			return 0;
		}
	}

	//------------------------------
	void DocumentProcessor::addKinematicsController( KinematicsController* kinematicsController )
	{
		const COLLADABU::URI& uri = kinematicsController->getUri();
		mKinematicsIntermediateData.getKinematicsControllers().insert(std::make_pair(uri, kinematicsController));
	}

	//------------------------------
	KinematicsController* DocumentProcessor::getKinematicsControllerByUri( const COLLADABU::URI& uri )
	{
		const KinematicsIntermediateData::KinematicsControllerMap& map = mKinematicsIntermediateData.getKinematicsControllers();
		KinematicsIntermediateData::KinematicsControllerMap::const_iterator it = map.find(uri);
		if ( it != map.end() )
		{
			return it->second;
		}
		else
		{
			return 0;
		}
	}

	//------------------------------
	void DocumentProcessor::addKinematicsModel( KinematicsModel* kinematicsModel )
	{
		const COLLADABU::URI& uri = kinematicsModel->getUrl();
		mKinematicsIntermediateData.getKinematicsModels().insert(std::make_pair(uri, kinematicsModel));
	}

	//------------------------------
	KinematicsModel* DocumentProcessor::getKinematicsModelByUri( const COLLADABU::URI& uri )
	{
		const KinematicsIntermediateData::KinematicsModelMap& map = mKinematicsIntermediateData.getKinematicsModels();
		KinematicsIntermediateData::KinematicsModelMap::const_iterator it = map.find(uri);
		if ( it != map.end() )
		{
			return it->second;
		}
		else
		{
			return 0;
		}
	}

	//------------------------------
	void DocumentProcessor::addFormula( COLLADAFW::Formula* formula )
	{
		mFormulasMap.insert(std::make_pair(formula->getUniqueId(), formula));
	}

	//------------------------------
	COLLADAFW::Formula* DocumentProcessor::getFormulaByUniqueId( const COLLADAFW::UniqueId& uniqueId ) const
	{
		COLLADAFW::Formula* formula = 0;
		Loader::UniqueIdFormulaMap::const_iterator it = mFormulasMap.find(uniqueId);
		if ( it != mFormulasMap.end() )
		{
			formula = it->second;
		}
		return formula;
	}


} // namespace COLLADASaxFWL
