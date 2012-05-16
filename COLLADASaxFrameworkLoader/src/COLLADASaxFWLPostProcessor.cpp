/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPostProcessor.h"

#include "COLLADASaxFWLFormulasLinker.h"
#include "COLLADASaxFWLKinematicsSceneCreator.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWMorphController.h"
#include "COLLADAFWFormulas.h"
#include "COLLADAFWKinematicsScene.h"


namespace COLLADASaxFWL
{

    //------------------------------
	PostProcessor::PostProcessor( Loader* colladaLoader, SaxParserErrorHandler* saxParserErrorHandler, int objectFlags, int& /*[in,out]*/ parsedObjectFlags )
		: DocumentProcessor( colladaLoader, saxParserErrorHandler, objectFlags, parsedObjectFlags)
	{
	}	
    //------------------------------
	PostProcessor::~PostProcessor()
	{
	}

	//---------------------------------
	void PostProcessor::postProcess()
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
	}

	//-----------------------------
	void PostProcessor::writeVisualScenes()
	{
		for ( size_t i = 0, count = mVisualScenes.size(); i < count; ++i)
		{
			COLLADAFW::VisualScene *visualScene = mVisualScenes[i];
			writer()->writeVisualScene(visualScene);
		}
	}

	//-----------------------------
	void PostProcessor::writeLibraryNodes()
	{
		for ( size_t i = 0, count = mLibraryNodes.size(); i < count; ++i)
		{
			COLLADAFW::LibraryNodes *libraryNodes = mLibraryNodes[i];
			writer()->writeLibraryNodes(libraryNodes);
		}
	}

	//-----------------------------
	void PostProcessor::writeEffects()
	{
		for ( size_t i = 0, count = mEffects.size(); i < count; ++i)
		{
			COLLADAFW::Effect *effect = mEffects[i];
			writer()->writeEffect(effect);
		}
	}

	//-----------------------------
	void PostProcessor::writeLights()
	{
		for ( size_t i = 0, count = mLights.size(); i < count; ++i)
		{
			COLLADAFW::Light *light = mLights[i];
			writer()->writeLight(light);
		}
	}

	//-----------------------------
	void PostProcessor::writeCameras()
	{
		for ( size_t i = 0, count = mCameras.size(); i < count; ++i)
		{
			COLLADAFW::Camera *camera = mCameras[i];
			writer()->writeCamera(camera);
		}
	}

	//-----------------------------
	void PostProcessor::createMissingAnimationLists()
	{
		Loader::AnimationSidAddressBindingList::const_iterator it = mAnimationSidAddressBindings.begin();
		for ( ; it != mAnimationSidAddressBindings.end(); ++it )
		{
			const Loader::AnimationSidAddressBinding& binding = *it;
			createMissingAnimationList( binding );
		}
	}

	//-----------------------------
	void PostProcessor::createMissingAnimationList( const Loader::AnimationSidAddressBinding& binding )
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
					animationListUniqueId = createUniqueId( COLLADAFW::AnimationList::ID() );
					animatable->setAnimationList( animationListUniqueId );
				}
				COLLADAFW::AnimationList*& animationList = getAnimationListByUniqueId(animationListUniqueId);

				if ( !animationList )
				{
					animationList = new COLLADAFW::AnimationList( animationListUniqueId );
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
	bool PostProcessor::writeMorphControllers()
	{
		const Loader::MorphControllerList& morphControllerList = mColladaLoader->getMorphControllerList();
		Loader::MorphControllerList::const_iterator it = morphControllerList.begin();
		for ( ; it != morphControllerList.end(); ++it)
		{
			const COLLADAFW::MorphController* morphController = *it;
			const COLLADAFW::UniqueId& morphControllerUniqueId = morphController->getUniqueId();
			const Loader::InstanceControllerDataList& instanceControllerDataList = getInstanceControllerDataListByControllerUniqueId(morphControllerUniqueId);

			// Set the InstanciatedObjectId of the instance controller
			Loader::InstanceControllerDataList::const_iterator it = instanceControllerDataList.begin();
			for ( ; it != instanceControllerDataList.end(); ++it )
			{
				const Loader::InstanceControllerData& instanceControllerData = *it;
				instanceControllerData.instanceController->setInstanciatedObjectId( morphControllerUniqueId );
			}

			if ( ! writer()->writeController( morphController ) )
				return false;
		}
		return true;
	}

	//-----------------------------
	void PostProcessor::writeAnimationLists()
	{
		Loader::UniqueIdAnimationListMap::const_iterator it = mUniqueIdAnimationListMap.begin();
		for ( ; it != mUniqueIdAnimationListMap.end(); ++it )
		{
			COLLADAFW::AnimationList* animationList = it->second;
			writer()->writeAnimationList( animationList );
		}
	}

	//-----------------------------
	void PostProcessor::linkAndWriteFormulas()
	{
		COLLADAFW::Formulas* formulas = FW_NEW COLLADAFW::Formulas();
		COLLADAFW::FormulaArray& formulaList = formulas->getFormulas();

		Loader::UniqueIdFormulaMap::const_iterator it = mFormulasMap.begin();
		for (; it != mFormulasMap.end(); ++it)
		{
			formulaList.append( it->second );
		}

		FormulasLinker formulasLinker(this, formulaList);
		formulasLinker.link();

		writer()->writeFormulas(formulas);
		FW_DELETE formulas;
	}

	//-----------------------------
	void PostProcessor::createAndWriteKinematicsScene()
	{
		KinematicsSceneCreator kinematicsSceneCreator( this );
		COLLADAFW::KinematicsScene* kinematicsScene = kinematicsSceneCreator.createAndGetKinematicsScene();
		writer()->writeKinematicsScene( kinematicsScene );
		FW_DELETE kinematicsScene;
	}




} // namespace COLLADASaxFWL
