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
#include "COLLADASaxFWLAssetLoader.h"
#include "COLLADASaxFWLSceneLoader.h"
#include "COLLADASaxFWLVisualSceneLoader.h"
#include "COLLADASaxFWLLibraryNodesLoader.h"
#include "COLLADASaxFWLLibraryMaterialsLoader.h"
#include "COLLADASaxFWLLibraryEffectsLoader.h"
#include "COLLADASaxFWLLibraryCamerasLoader.h"
#include "COLLADASaxFWLLibraryLightsLoader.h"
#include "COLLADASaxFWLLibraryImagesLoader.h"
#include "COLLADASaxFWLLibraryAnimationsLoader.h"
#include "COLLADASaxFWLLibraryControllersLoader.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLGeometryLoader.h"
#include "COLLADASaxFWLSaxParserErrorHandler.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADASaxFWLColladaParserAutoGenFunctionMapFactory.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWSkinController.h"

#include "COLLADAFWObject.h"

#if defined(COLLADABU_OS_WIN)
#pragma warning(disable:4355)
#endif


namespace COLLADASaxFWL
{

	enum LibraryFlags
	{
		COLLADA_NO_FLAGS                     = 0,    
		COLLADA_ASSET                        = 1<< 0,
		COLLADA_LIBRARY_ANIMATION_CLIPS      = 1<< 1,
		COLLADA_LIBRARY_ANIMATIONS           = 1<< 2,
		COLLADA_LIBRARY_ARTICULATED_SYSTEMS  = 1<< 3,
		COLLADA_LIBRARY_CAMERAS              = 1<< 4,
		COLLADA_LIBRARY_CONTROLLERS          = 1<< 5,
		COLLADA_LIBRARY_EFFECTS              = 1<< 6,
		COLLADA_LIBRARY_FORCE_FIELDS         = 1<< 7,
		COLLADA_LIBRARY_FORMULAS             = 1<< 8,
		COLLADA_LIBRARY_GEOMETRIES           = 1<< 9,
		COLLADA_LIBRARY_IMAGES               = 1<<10,
		COLLADA_LIBRARY_JOINTS               = 1<<11,
		COLLADA_LIBRARY_KINEMATICS_MODELS    = 1<<12,
		COLLADA_LIBRARY_KINEMATICS_SCENES    = 1<<13,
		COLLADA_LIBRARY_LIGHTS               = 1<<14,
		COLLADA_LIBRARY_MATERIALS            = 1<<15,
		COLLADA_LIBRARY_NODES                = 1<<16,
		COLLADA_LIBRARY_PHYSICS_MATERIALS    = 1<<17,
		COLLADA_LIBRARY_PHYSICS_MODELS       = 1<<18,
		COLLADA_LIBRARY_PHYSICS_SCENES       = 1<<19,
		COLLADA_LIBRARY_VISUAL_SCENES        = 1<<20,
		COLLADA_SCENE                        = 1<<21
	};

	struct LibraryFlagsFunctionMapPair
	{
		LibraryFlags flag;
		const ColladaParserAutoGenPrivate::ElementFunctionMap& functionMap;
	};


	LibraryFlagsFunctionMapPair COLLADA_ASSET_PAIR = {COLLADA_ASSET, FunctionMapFactory::createFunctionMap__asset__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_ANIMATION_CLIPS_PAIR = {COLLADA_LIBRARY_ANIMATION_CLIPS, FunctionMapFactory::createFunctionMap__library_animation_clips__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_ANIMATIONS_PAIR = {COLLADA_LIBRARY_ANIMATIONS, FunctionMapFactory::createFunctionMap__library_animations__allChildren() };
//	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_ARTICULATED_SYSTEMS_PAIR = {COLLADA_LIBRARY_ARTICULATED_SYSTEMS, FunctionMapFactory::createFunctionMap__library_articulated_systems__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_CAMERAS_PAIR = {COLLADA_LIBRARY_CAMERAS, FunctionMapFactory::createFunctionMap__library_cameras__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_CONTROLLERS_PAIR = {COLLADA_LIBRARY_CONTROLLERS, FunctionMapFactory::createFunctionMap__library_controllers__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_EFFECTS_PAIR = {COLLADA_LIBRARY_EFFECTS, FunctionMapFactory::createFunctionMap__library_effects__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_FORCE_FIELDS_PAIR = {COLLADA_LIBRARY_FORCE_FIELDS, FunctionMapFactory::createFunctionMap__library_force_fields__allChildren() };
//	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_FORMULAS_PAIR = {COLLADA_LIBRARY_FORMULAS, FunctionMapFactory::createFunctionMap__library_formulas__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_GEOMETRIES_PAIR = {COLLADA_LIBRARY_GEOMETRIES, FunctionMapFactory::createFunctionMap__library_geometries__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_IMAGES_PAIR = {COLLADA_LIBRARY_IMAGES, FunctionMapFactory::createFunctionMap__library_images__allChildren() };
//	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_JOINTS_PAIR = {COLLADA_LIBRARY_JOINTS, FunctionMapFactory::createFunctionMap__library_joints__allChildren() };
//	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_KINEMATICS_MODELS_PAIR = {COLLADA_LIBRARY_KINEMATICS_MODELS, FunctionMapFactory::createFunctionMap__library_kinematics_models__allChildren() };
//	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_KINEMATICS_SCENES_PAIR = {COLLADA_LIBRARY_KINEMATICS_SCENES, FunctionMapFactory::createFunctionMap__library_kinematics_scenes__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_LIGHTS_PAIR = {COLLADA_LIBRARY_LIGHTS, FunctionMapFactory::createFunctionMap__library_lights__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_MATERIALS_PAIR = {COLLADA_LIBRARY_MATERIALS, FunctionMapFactory::createFunctionMap__library_materials__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_NODES_PAIR = {COLLADA_LIBRARY_NODES, FunctionMapFactory::createFunctionMap__library_nodes__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_PHYSICS_MATERIALS_PAIR = {COLLADA_LIBRARY_PHYSICS_MATERIALS, FunctionMapFactory::createFunctionMap__library_physics_materials__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_PHYSICS_MODELS_PAIR = {COLLADA_LIBRARY_PHYSICS_MODELS, FunctionMapFactory::createFunctionMap__library_physics_models__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_PHYSICS_SCENES_PAIR = {COLLADA_LIBRARY_PHYSICS_SCENES, FunctionMapFactory::createFunctionMap__library_physics_scenes__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_LIBRARY_VISUAL_SCENES_PAIR = {COLLADA_LIBRARY_VISUAL_SCENES, FunctionMapFactory::createFunctionMap__library_visual_scenes__allChildren() };
	LibraryFlagsFunctionMapPair COLLADA_SCENE_PAIR = {COLLADA_SCENE, FunctionMapFactory::createFunctionMap__scene__allChildren() };


	LibraryFlagsFunctionMapPair libraryFlagsFunctionMapMap[] = {COLLADA_ASSET_PAIR,
		                                                        COLLADA_LIBRARY_ANIMATION_CLIPS_PAIR,
		                                                        COLLADA_LIBRARY_ANIMATIONS_PAIR,
		                                                        COLLADA_LIBRARY_CAMERAS_PAIR,
		                                                        COLLADA_LIBRARY_CONTROLLERS_PAIR,
		                                                        COLLADA_LIBRARY_EFFECTS_PAIR,
		                                                        COLLADA_LIBRARY_FORCE_FIELDS_PAIR,
		                                                        COLLADA_LIBRARY_GEOMETRIES_PAIR,
		                                                        COLLADA_LIBRARY_IMAGES_PAIR,
		                                                        COLLADA_LIBRARY_LIGHTS_PAIR,
		                                                        COLLADA_LIBRARY_MATERIALS_PAIR,
		                                                        COLLADA_LIBRARY_NODES_PAIR,
				                                                COLLADA_LIBRARY_PHYSICS_MATERIALS_PAIR,
		                                                        COLLADA_LIBRARY_PHYSICS_MODELS_PAIR,
		                                                        COLLADA_LIBRARY_PHYSICS_SCENES_PAIR,
		                                                        COLLADA_LIBRARY_VISUAL_SCENES_PAIR,
		                                                        COLLADA_SCENE_PAIR};

	size_t libraryFlagsFunctionMapMapSize = sizeof(libraryFlagsFunctionMapMap)/sizeof(LibraryFlagsFunctionMapPair);

	template<class Flags>
	bool setInFirstUnsetInSecond(int firstFlags, int secondFlags, Flags flag)
	{
		return ( (firstFlags & flag) != 0 ) && ( (secondFlags & flag) == 0 );
	}


    //-----------------------------
	FileLoader::FileLoader ( Loader* colladaLoader, 
							 const COLLADABU::URI& fileURI, 
							 SaxParserErrorHandler* saxParserErrorHandler, 
							 int objectFlags,
							 int& parsedObjectFlags)
         : ColladaParserAutoGenPrivate(0, saxParserErrorHandler)
		 , mColladaLoader(colladaLoader)
		 , mFileURI(fileURI)
		 , mLibxmlSaxParse(this)
		 , mCurrentSidTreeNode( colladaLoader->getSidTreeRoot() )
		 , mIdStringSidTreeNodeMap( colladaLoader->getIdStringSidTreeNodeMap() )
		 , mVisualScenes( colladaLoader->getVisualScenes() )
		 , mLibraryNodes( colladaLoader->getLibraryNodes() )
		 , mEffects( colladaLoader->getEffects() )
		 , mUniqueIdAnimationListMap( colladaLoader->getUniqueIdAnimationListMap() )
		 , mObjectFlags( objectFlags )
		 , mParsedObjectFlags( parsedObjectFlags )
	{

		// A combination of ObjectFlags, indicating which objects will have been parsed, after load() 
		// has been called. These will be contained for sure.
		// We need this to ensure that objects that are store by the Loader ( visual scene, library nodes, 
		// effects, cameras, lights) are parsed only once.
		int mAfterLoadParsedObjectFlags = mParsedObjectFlags | mObjectFlags;

		setCallbackObject(this);
//		registerUnknownElementHandler( &mRawUnknownElementHandler );

		if ( (objectFlags & Loader::ALL_OBJECTS_MASK ) != Loader::ALL_OBJECTS_MASK )
		{
			// we need to set a customized function map, since we don't need all COLLADA libraries 
			//determine which COLLADA elements we need to parse to get all date needed to parse objects in mObjectFlags
			int requiredFunctionMaps = 0;

			if ( (mObjectFlags & Loader::ASSET_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_ASSET;
			}

			if ( (mObjectFlags & Loader::SCENE_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_SCENE;
			}

			if ( setInFirstUnsetInSecond(mObjectFlags, mParsedObjectFlags, Loader::VISUAL_SCENES_FLAG) )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_VISUAL_SCENES;
				requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
			}

			if ( setInFirstUnsetInSecond(mObjectFlags, mParsedObjectFlags, Loader::LIBRARY_NODES_FLAG) )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_NODES;
				requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
			}

			if ( (mObjectFlags & Loader::GEOMETRY_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_GEOMETRIES;
			}

			if ( (mObjectFlags & Loader::MATERIAL_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_MATERIALS;
			}

			if ( setInFirstUnsetInSecond(mObjectFlags, mParsedObjectFlags, Loader::EFFECT_FLAG) )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_EFFECTS;
				requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
			}

			if ( (mObjectFlags & Loader::CAMERA_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_CAMERAS;
				//requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
			}

			if ( (mObjectFlags & Loader::IMAGE_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_IMAGES;
			}

			if ( (mObjectFlags & Loader::LIGHT_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_LIGHTS;
			}

			if ( (mObjectFlags & Loader::ANIMATION_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;
			}

			if ( (mObjectFlags & Loader::ANIMATION_LIST_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_ANIMATIONS;

				requiredFunctionMaps|= COLLADA_LIBRARY_VISUAL_SCENES;
				mAfterLoadParsedObjectFlags |= Loader::VISUAL_SCENES_FLAG;

				requiredFunctionMaps|= COLLADA_LIBRARY_NODES;
				mAfterLoadParsedObjectFlags |= Loader::LIBRARY_NODES_FLAG;

				requiredFunctionMaps|= COLLADA_LIBRARY_EFFECTS;
				mAfterLoadParsedObjectFlags |= Loader::EFFECT_FLAG;

				//requiredFunctionMaps|= COLLADA_LIBRARY_CAMERAS;
				//requiredFunctionMaps|= COLLADA_LIBRARY_LIGHTS;
			}

			if ( (mObjectFlags & Loader::CONTROLLER_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_CONTROLLERS;

				requiredFunctionMaps|= COLLADA_LIBRARY_VISUAL_SCENES;
				mAfterLoadParsedObjectFlags |= Loader::VISUAL_SCENES_FLAG;

				requiredFunctionMaps|= COLLADA_LIBRARY_NODES;
				mAfterLoadParsedObjectFlags |= Loader::LIBRARY_NODES_FLAG;
			}

			if ( (mObjectFlags & Loader::SKIN_CONTROLLER_DATA_FLAG) != 0 )
			{
				requiredFunctionMaps|= COLLADA_LIBRARY_CONTROLLERS;
			}


			// Fills function map
			for ( size_t i = 0; i < libraryFlagsFunctionMapMapSize; ++i )
			{
				const LibraryFlagsFunctionMapPair& libraryFlagsFunctionMapPair = libraryFlagsFunctionMapMap[i];
				if ( (requiredFunctionMaps & libraryFlagsFunctionMapPair.flag) != 0 )
				{
					mFunctionMap.insert(libraryFlagsFunctionMapPair.functionMap.begin(), libraryFlagsFunctionMapPair.functionMap.end());
				}
			}

			setElementFunctionMap(&mFunctionMap);

			parsedObjectFlags = mAfterLoadParsedObjectFlags;
		}
	}

	//-----------------------------
	FileLoader::~FileLoader()
	{
	}

	//-----------------------------
	bool FileLoader::load()
	{
		bool success = mLibxmlSaxParse.parseFile(mFileURI.toNativePath().c_str());
		postProcess();
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

		if ( (getObjectFlags() & Loader::CONTROLLER_FLAG) != 0 )
		{
			createAndWriteSkinControllers();
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
		for ( size_t i = 0, count = sids.size(); i < count; ++i)
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
	void FileLoader::addSkinDataJointSidsMap( const COLLADAFW::UniqueId& skinDataUniqueId, const StringList& jointSids )
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
	bool FileLoader::createAndWriteSkinController( const InstanceControllerData& instanceControllerData, const COLLADAFW::UniqueId& controllerDataUniqueId )
	{
		if ( !controllerDataUniqueId.isValid() )
			return false;

		const StringList& sids = getJointSidsBySkinDataUniqueId( controllerDataUniqueId );
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
				return false;
		}

		COLLADAFW::SkinController* skinController = FW_NEW COLLADAFW::SkinController( getUniqueId(COLLADAFW::SkinController::ID()).getObjectId());

		COLLADAFW::UniqueIdArray &jointsUniqueIds = skinController->getBones();
		jointsUniqueIds.allocMemory( joints.size() );
		jointsUniqueIds.setCount(joints.size());

		size_t i = 0;
		NodeList::const_iterator it = joints.begin();
		for ( ; it != joints.end(); ++it, ++i )
		{
			const COLLADAFW::Node* node = *it;
			jointsUniqueIds[i] = node->getUniqueId();
		}

		skinController->setSkinControllerData(controllerDataUniqueId);

		instanceControllerData.instanceController->setInstanciatedObjectId( skinController->getUniqueId() );

		bool success = writer()->writeController(skinController);

		FW_DELETE skinController;

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
				createAndWriteSkinController( instanceControllerData, skinDataUniqueId);
			}
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
    bool FileLoader::begin__asset ()
    {
		SaxVirtualFunctionTest(begin__asset());
		deleteFilePartLoader();
        AssetLoader* assetLoader = new AssetLoader(this);
        setPartLoader(assetLoader);
        setParser(assetLoader);
        return true;
    }

    //------------------------------
    bool FileLoader::begin__scene ()
    {
        SaxVirtualFunctionTest(begin__scene()); 
        deleteFilePartLoader();
        SceneLoader* sceneLoader = new SceneLoader(this);
        setPartLoader(sceneLoader);
        setParser(sceneLoader);
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
	bool FileLoader::begin__library_controllers( const library_controllers__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__library_controllers(attributeData));

		deleteFilePartLoader();
		LibraryControllersLoader* libraryControllersLoader = new LibraryControllersLoader(this);

		setPartLoader(libraryControllersLoader);
		setParser(libraryControllersLoader);
		return true;
	}

	//-----------------------------
    bool FileLoader::end__COLLADA()
    {
		SaxVirtualFunctionTest(end__COLLADA());
        return true;
    }

} // namespace COLLADASaxFWL
