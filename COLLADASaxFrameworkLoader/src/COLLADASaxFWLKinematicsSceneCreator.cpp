/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLKinematicsSceneCreator.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADAFWKinematicsScene.h"
#include "COLLADAFWKinematicsModel.h"
#include "COLLADAFWTranslate.h"
#include "COLLADAFWRotate.h"

namespace COLLADASaxFWL
{

	void appendTransformations( COLLADAFW::TransformationPointerArray& target, TransformationList source, bool invert = false)
	{
		if ( invert )
		{
			TransformationList::const_reverse_iterator sourceIt = source.rbegin();
			TransformationList::const_reverse_iterator listEnd = source.rend();
			for ( ; sourceIt != listEnd; ++sourceIt )
			{
				COLLADAFW::Transformation* sourceTransformation = *sourceIt;
				COLLADAFW::Transformation* invertedTransformation = 0;
				if ( sourceTransformation->getTransformationType() == COLLADAFW::Transformation::TRANSLATE )
				{
					COLLADAFW::Translate* sourceTranslate = (COLLADAFW::Translate*)sourceTransformation;
					COLLADAFW::Translate* invertedTranslate = FW_NEW COLLADAFW::Translate();
					invertedTranslate->setTranslation( -sourceTranslate->getTranslation() );
					invertedTransformation = invertedTranslate;
				}
				else if ( sourceTransformation->getTransformationType() == COLLADAFW::Transformation::ROTATE )
				{
					COLLADAFW::Rotate* sourceRotate = (COLLADAFW::Rotate*)sourceTransformation;
					COLLADAFW::Rotate* invertedRotate = FW_NEW COLLADAFW::Rotate();
					invertedRotate->setRotationAxis( sourceRotate->getRotationAxis() );
					invertedRotate->setRotationAngle( -sourceRotate->getRotationAngle() );
					invertedTransformation = invertedRotate;
				}
				assert( invertedTransformation );
				target.append( invertedTransformation );
			}
		}
		else
		{
			TransformationList::const_iterator sourceIt = source.begin();
			for ( ; sourceIt != source.end(); ++sourceIt )
			{
				target.append( (*sourceIt)->clone() );
			}
		}
	}

    //------------------------------
	KinematicsSceneCreator::KinematicsSceneCreator( DocumentProcessor* documentProcessor )
		: mKinematicsScene(0)
		, mDocumentProcessor(documentProcessor)
		, mKinematicsIntermediateData( documentProcessor->getKinematicsIntermediateData())
		, mLargestLinkNumber(0)
		, mLargestJointIndex(0)
	{

	}

    //------------------------------
	KinematicsSceneCreator::~KinematicsSceneCreator()
	{
	}

	//------------------------------
	COLLADAFW::KinematicsScene* KinematicsSceneCreator::createAndGetKinematicsScene()
	{
		mKinematicsScene = FW_NEW COLLADAFW::KinematicsScene();

		//Kinematics models
		COLLADAFW::KinematicsModelArray& fwKinematicsModels = mKinematicsScene->getKinematicsModels();

		const KinematicsIntermediateData::KinematicsModelList& kinematicsModels = mKinematicsIntermediateData.getKinematicsModels();
		KinematicsIntermediateData::KinematicsModelList::const_iterator modelIt = kinematicsModels.begin();
		for ( ; modelIt != kinematicsModels.end(); ++modelIt )
		{
			KinematicsModel* kinematicsModel = *modelIt;

			COLLADAFW::KinematicsModel* fwKinematicsModel = createFWKinematicsModel(kinematicsModel);
			fwKinematicsModels.append( fwKinematicsModel );
			mLargestJointIndex = 0;
			mJointIndexMap.clear();
		}

		//Kinematics controllers
		COLLADAFW::KinematicsControllerArray& fwKinematicsControllers = mKinematicsScene->getKinematicsControllers();

		const KinematicsIntermediateData::KinematicsControllerMap& kinematicsControllers = mKinematicsIntermediateData.getKinematicsControllers();
		KinematicsIntermediateData::KinematicsControllerMap::const_iterator controllerIt = kinematicsControllers.begin();
		for ( ; controllerIt != kinematicsControllers.end(); ++controllerIt )
		{
			KinematicsController* kinematicsController = controllerIt->second;

			COLLADAFW::KinematicsController* fwKinematicsController = createFWKinematicsController(kinematicsController);
			fwKinematicsControllers.append( fwKinematicsController );
		}


		//Instance kinematics scenes
		COLLADAFW::InstanceKinematicsSceneArray& fwInstanceKinematicsScenes = mKinematicsScene->getInstanceKinematicsScenes();

		const KinematicsIntermediateData::KinematicsInstanceKinematicsScenes& instanceKinematicsScenes = mKinematicsIntermediateData.getInstanceKinematicsScenes();
		KinematicsIntermediateData::KinematicsInstanceKinematicsScenes::const_iterator instanceKinematicsSceneIt = instanceKinematicsScenes.begin();
		for ( ; instanceKinematicsSceneIt != instanceKinematicsScenes.end(); ++instanceKinematicsSceneIt )
		{
			KinematicsInstanceKinematicsScene* instanceKinematicsScene= *instanceKinematicsSceneIt;

			COLLADAFW::InstanceKinematicsScene* fwInstanceKinematicsScene = createFWInstanceKinematicsScene(instanceKinematicsScene);
			fwInstanceKinematicsScenes.append( fwInstanceKinematicsScene );
		}

		return mKinematicsScene;
	}

	//------------------------------
	COLLADAFW::KinematicsModel* KinematicsSceneCreator::createFWKinematicsModel(KinematicsModel* kinematicsModel)
	{
		COLLADAFW::UniqueId uniqueId = mDocumentProcessor->createUniqueIdFromUrl( kinematicsModel->getUri(), COLLADAFW::KinematicsModel::ID(), true);
		COLLADAFW::KinematicsModel* fwKinematicsModel = FW_NEW COLLADAFW::KinematicsModel(uniqueId);

		COLLADAFW::SizeTValuesArray& fwBaseLinks = fwKinematicsModel->getBaseLinks();

		const KinematicLinkList& baseLinks = kinematicsModel->getBaseLinks();

		KinematicLinkList::const_iterator it = baseLinks.begin();

		for ( ; it != baseLinks.end(); ++it )
		{
			KinematicLink* link = *it;
			fwBaseLinks.append( mLargestLinkNumber );
			mLinkNumberStack.push(mLargestLinkNumber++);
			createJointLinkConnections( link, fwKinematicsModel );
		}

		return fwKinematicsModel;
	}

	//------------------------------
	void KinematicsSceneCreator::createJointLinkConnections(const KinematicLink* link, COLLADAFW::KinematicsModel* fwKinematicsModel)
	{
		COLLADAFW::KinematicsModel::LinkJointConnections& linkJointConnections = fwKinematicsModel->getLinkJointConnections();

		const TransformationList& linkTransformations = link->getTransformations();

		const KinematicAttachmentList& attachments = link->getAttachments();
		KinematicAttachmentList::const_iterator it = attachments.begin();
		for ( ; it != attachments.end(); ++it )
		{
			KinematicAttachment* attachment = *it;
			
			const SidAddress& jointAddress = attachment->getJoint();
			const SidTreeNode* jointTreeNode = mDocumentProcessor->resolveSid( jointAddress );
			if ( !jointTreeNode )
			{
				//TODO: handle error
				continue;
			}

			COLLADAFW::Joint* joint = 0;
			// Used if the joint is an instance joint in collada
			const COLLADAFW::UniqueId* jointUniqueId = 0;

			if ( jointTreeNode->getTargetType() == SidTreeNode::TARGETTYPECLASS_INTERMEDIATETARGETABLE )
			{
				//this must be a KinematicInstance
				const KinematicInstance* instanceJoint = intermediateTargetableSafeCast<KinematicInstance>(jointTreeNode->getIntermediateTargetableTarget());
				assert(instanceJoint);
				SidAddress referencedJointAddress( instanceJoint->getUrl() );
				const SidTreeNode* referencedJointTreeNode = mDocumentProcessor->resolveSid( referencedJointAddress );
				
				assert( referencedJointTreeNode->getTargetType() == SidTreeNode::TARGETTYPECLASS_OBJECT );
				jointUniqueId = &instanceJoint->getReplacingObjectUniqueId();
				joint = COLLADAFW::objectSafeCast<COLLADAFW::Joint>(referencedJointTreeNode->getObjectTarget());
			}
			else if ( jointTreeNode->getTargetType() == SidTreeNode::TARGETTYPECLASS_OBJECT )
			{
				joint = COLLADAFW::objectSafeCast<COLLADAFW::Joint>(jointTreeNode->getObjectTarget());
			}

			if ( !joint )
			{
				//TODO: handle error
				assert(joint);
				continue;
			}

			size_t jointIndex = 0;
			JointIndexMap::const_iterator jointIndexIt = mJointIndexMap.find(joint);
			if ( jointIndexIt == mJointIndexMap.end() )
			{
				// this joint is not in the kinematics model. Add it here.
				jointIndex = mLargestJointIndex;
				mJointIndexMap[joint] = mLargestJointIndex++;
				COLLADAFW::JointPointerArray& fwJoints = fwKinematicsModel->getJoints();
				// If the joint is in the kinematics model in COLLADA we clone it completely, if it 
				// is instantiated we need to take the unique id from the instance
				COLLADAFW::Joint* clonedJoint = jointUniqueId ? joint->clone(*jointUniqueId) : joint->clone();
				fwJoints.append( clonedJoint );

				const COLLADAFW::JointPrimitivePointerArray& jointPrimitives = joint->getJointPrimitives();
				const COLLADAFW::JointPrimitivePointerArray& clonedJointPrimitives = clonedJoint->getJointPrimitives();
				assert(jointPrimitives.getCount() == clonedJointPrimitives.getCount() );
				for ( size_t j = 0; j < jointPrimitives.getCount(); ++j)
				{
					mOriginalClonedJointPrimitiveMap.insert(std::make_pair(jointPrimitives[j], clonedJointPrimitives[j] ));
				}

			}
			else
			{
				// this joint is in the kinematics model. take it.
				jointIndex = jointIndexIt->second;
			}

			COLLADAFW::KinematicsModel::LinkJointConnection *linkJointConnection = FW_NEW COLLADAFW::KinematicsModel::LinkJointConnection( mLinkNumberStack.top(), jointIndex );

			COLLADAFW::TransformationPointerArray& linkJointConnectionTransformations =linkJointConnection->getTransformations();
			linkJointConnectionTransformations.reallocMemory( attachment->getTransformations().size());
			appendTransformations(linkJointConnectionTransformations, attachment->getTransformations());
			linkJointConnections.append(linkJointConnection);
			createJointLinkConnections(attachment, jointIndex, fwKinematicsModel);
		}
		
	}

	//------------------------------
	void KinematicsSceneCreator::createJointLinkConnections(const KinematicAttachment* attachment, size_t jointIndex, COLLADAFW::KinematicsModel* fwKinematicsModel)
	{
		COLLADAFW::KinematicsModel::LinkJointConnections& linkJointConnections = fwKinematicsModel->getLinkJointConnections();

		const TransformationList& linkTransformations = attachment->getTransformations();

		mLinkNumberStack.push(mLargestLinkNumber++);

		const KinematicLink& link = attachment->getLink();

		COLLADAFW::KinematicsModel::LinkJointConnection *linkJointConnection = FW_NEW COLLADAFW::KinematicsModel::LinkJointConnection( mLinkNumberStack.top(), jointIndex );

		COLLADAFW::TransformationPointerArray& linkJointConnectionTransformations =linkJointConnection->getTransformations();
		linkJointConnectionTransformations.reallocMemory( link.getTransformations().size() );
		appendTransformations(linkJointConnectionTransformations, link.getTransformations(), true);
		linkJointConnections.append(linkJointConnection);
		createJointLinkConnections(&link, fwKinematicsModel);
		mLinkNumberStack.pop();
	}

	//------------------------------
	COLLADAFW::KinematicsController* KinematicsSceneCreator::createFWKinematicsController(KinematicsController* kinematicsController)
	{
		COLLADAFW::UniqueId uniqueId = mDocumentProcessor->createUniqueIdFromUrl( kinematicsController->getUri(), COLLADAFW::KinematicsController::ID(), true);
		COLLADAFW::KinematicsController* fwKinematicsController = FW_NEW COLLADAFW::KinematicsController(uniqueId);

		// get instance kinematics models
		const KinematicsInstanceKinematicsModels& instanceKinematicsModels =  kinematicsController->getKinematicsInstanceKinematicsModels();
		KinematicsInstanceKinematicsModels::const_iterator instanceIt = instanceKinematicsModels.begin();

		typedef std::vector<COLLADAFW::UniqueId> UniqueIdVector;
		UniqueIdVector instanceKinematicsModelVector;

		for ( ; instanceIt != instanceKinematicsModels.end(); ++instanceIt )
		{
			const KinematicsInstanceKinematicsModel& instanceKinematicsModel = *instanceIt;

			COLLADAFW::UniqueId kinematicsModelUniqueId = processInstanceKinematicsModel(instanceKinematicsModel);
			if ( kinematicsModelUniqueId.isValid() )
			{
				instanceKinematicsModelVector.push_back(kinematicsModelUniqueId);
			}
		}

		// fill kinematicsModelUniqueIds
		COLLADAFW::UniqueIdArray& kinematicsModelUniqueIds = fwKinematicsController->getKinematicsModelUniqueIds();
		size_t instanceKinematicsModelsCount = instanceKinematicsModelVector.size();
		kinematicsModelUniqueIds.allocMemory( instanceKinematicsModelsCount );
		for ( size_t i = 0; i < instanceKinematicsModelsCount; ++i)
		{
			kinematicsModelUniqueIds[i] = instanceKinematicsModelVector[i];
		}
		kinematicsModelUniqueIds.setCount( instanceKinematicsModelsCount );

		// create axis infos
		COLLADAFW::AxisInfoArray& fwAxisInfos = fwKinematicsController->getAxisInfos();

 		const AxisInfoList& axisInfos = kinematicsController->getAxisInfos();

		AxisInfoList::const_iterator axisInfoIt = axisInfos.begin();

		for ( ; axisInfoIt != axisInfos.end(); ++axisInfoIt )
		{
			const AxisInfo& axisInfo = *axisInfoIt;

			bool success = true;
			COLLADAFW::AxisInfo fwAxisInfo = createFWAxisInfo(axisInfo, success);
			if ( success )
			{
				fwAxisInfos.append(fwAxisInfo);
			}

// 			fwAxisInfos.append( mLargestLinkNumber );
// 			mLinkNumberStack.push(mLargestLinkNumber++);
// 			createJointLinkConnections( axisInfo, fwKinematicsController );
		}

		return fwKinematicsController;
	}

	//------------------------------
	COLLADAFW::AxisInfo KinematicsSceneCreator::createFWAxisInfo( const AxisInfo& axisInfo, bool& success )
	{
		const SidAddress& jointPrimitiveAddress = axisInfo.getJointPrimitiveRefAddress();
		const SidTreeNode* jointPrimitiveSidTreeNode = mDocumentProcessor->resolveSid( jointPrimitiveAddress );
		if ( !jointPrimitiveSidTreeNode )
		{
			// TODO report error joint primitive could not be resolved
			success = false;
			return COLLADAFW::AxisInfo();
		}

		if ( jointPrimitiveSidTreeNode->getTargetType() != SidTreeNode::TARGETTYPECLASS_OBJECT )
		{
			// TODO report error joint primitive could not be resolved
			success = false;
			return COLLADAFW::AxisInfo();
		}

		COLLADAFW::Object* object = jointPrimitiveSidTreeNode->getObjectTarget();

		if ( object->getClassId() != COLLADAFW::JointPrimitive::ID() )
		{
			// TODO report error joint primitive could not be resolved
			success = false;
			return COLLADAFW::AxisInfo();
		}

		COLLADAFW::JointPrimitive* jointPrimitive= (COLLADAFW::JointPrimitive*)object;

		success = true;
		COLLADAFW::AxisInfo fwAxisInfo;
		fwAxisInfo.setIsActive( axisInfo.getIsActive() );
		fwAxisInfo.setIsLocked( axisInfo.getIsLocked() );
		fwAxisInfo.setIndex( axisInfo.getIndex() );

		JointPrimitiveJointPrimitiveMap::const_iterator it = mOriginalClonedJointPrimitiveMap.find(jointPrimitive);
		if ( it == mOriginalClonedJointPrimitiveMap.end() )
		{
			fwAxisInfo.setJointPrimitive( 0 );

		}
		else
		{
			fwAxisInfo.setJointPrimitive( it->second );
		}
		return fwAxisInfo;
	}

	//------------------------------
	COLLADAFW::UniqueId KinematicsSceneCreator::processInstanceKinematicsModel(const KinematicsInstanceKinematicsModel& instanceKinematicsModel)
	{
		COLLADAFW::UniqueId kinematicsModelUniqueId =  mDocumentProcessor->createUniqueIdFromUrl( instanceKinematicsModel.getUrl(), true );
		if ( !kinematicsModelUniqueId.isValid() )
		{
			return COLLADAFW::UniqueId::INVALID;
		}

		return kinematicsModelUniqueId;
	}

	//------------------------------
	COLLADAFW::InstanceKinematicsScene* KinematicsSceneCreator::createFWInstanceKinematicsScene( KinematicsInstanceKinematicsScene* instanceKinematicsScene )
	{
		//COLLADAFW::UniqueId uniqueId = mDocumentProcessor->createUniqueIdFromUrl( instanceKinematicsScene->getUrl(), COLLADAFW::KinematicsController::ID(), true);
		COLLADAFW::UniqueId uniqueId = mDocumentProcessor->createUniqueId( COLLADAFW::KinematicsController::ID());
		COLLADAFW::InstanceKinematicsScene* fwInstanceKinematicsScene = FW_NEW COLLADAFW::InstanceKinematicsScene(uniqueId, COLLADAFW::UniqueId::INVALID);

		const COLLADABU::URI& instanceKinematicsUrl = instanceKinematicsScene->getUrl();
		KinematicsScene* kinematicsScene =  mDocumentProcessor->getKinematicsSceneByUri(instanceKinematicsUrl);
		if ( !kinematicsScene )
		{
			String msg = "Kinematics scene \"" + instanceKinematicsUrl.getURIString() + "\" could not be found.";

			mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg);
			return 0;
		}

		const KinematicsBindJointAxes& kinematicsBindJointAxes = instanceKinematicsScene->getBindJointAxes();
		
		KinematicsBindJointAxes::const_iterator kinematicsBindJointAxisIt = kinematicsBindJointAxes.begin();
		for ( ; kinematicsBindJointAxisIt != kinematicsBindJointAxes.end(); ++kinematicsBindJointAxisIt )
		{
			KinematicsBindJointAxis* kinematicsBindJointAxis= *kinematicsBindJointAxisIt;


			// find the unique id of the node a link is bound to
			const String& nodeId = kinematicsBindJointAxis->getTarget().getId();
			COLLADABU::URI nodeUri = instanceKinematicsScene->getUrl();
			nodeUri.setFragment(nodeId);
			const COLLADAFW::UniqueId nodeUniqueId = mDocumentProcessor->getUniqueIdByUrl(nodeUri, true);
			if ( !nodeUniqueId.isValid() )
			{
				String msg = "Node with id \"" + nodeId + "\" referenced in <bind_joint_axis> in <bind_kinematics_model> in.";
				
				mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg);
				continue;
			}

			resolveJoint(kinematicsScene, kinematicsBindJointAxis);

		}
		
		return fwInstanceKinematicsScene;
	}

	//------------------------------
	const COLLADAFW::UniqueId& KinematicsSceneCreator::resolveJoint( KinematicsScene* kinematicsScene, KinematicsBindJointAxis* kinematicsBindJointAxis )
	{
		const KinematicsInstanceArticulatedSystems& instanceArticulatedSystems = kinematicsScene->getKinematicsInstanceArticulatedSystems();
		KinematicsInstanceArticulatedSystems::const_iterator it = instanceArticulatedSystems.begin();
// 		for (; it != instanceArticulatedSystems.end(); ++it)
// 		{
// 			const KinematicsInstanceArticulatedSystem* instanceArticulatedSystem = *it;
// 
// 			const COLLADABU::URI& articulatedSystemUrl = instanceArticulatedSystem->getUrl();
// 
// 			KinematicsController* controller = mDocumentProcessor->getKinematicsControllerByUri(articulatedSystemUrl);
// 
// 			if ( !controller )
// 			{
// 				String msg = "Articulated scene \"" + articulatedSystemUrl.getURIString() + "\" could not be found.";
// 
// 				mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg);
// 				continue;
// 			}
// 
// 			controller->getKinematicsInstanceKinematicsModels()
// 		}

// 		const KinematicsInstanceArticulatedSystems& instanceArticulatedSystems = kinematicsScene->getKinematicsInstanceArticulatedSystems();
// 		KinematicsInstanceArticulatedSystems::const_iterator it = instanceArticulatedSystems.begin();
// 		for (; it != instanceArticulatedSystems.end(); ++it)
// 		{
// 			const KinematicsInstanceArticulatedSystem* instanceArticulatedSystem = *it;
// 
// 			const COLLADABU::URI& articulatedSystemUrl = instanceArticulatedSystem->getUrl();
// 
// 			KinematicsController* controller = mDocumentProcessor->getKinematicsControllerByUri(articulatedSystemUrl);
// 
// 			if ( !controller )
// 			{
// 				String msg = "Articulated scene \"" + articulatedSystemUrl.getURIString() + "\" could not be found.";
// 
// 				mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg);
// 				continue;
// 			}
// 
// 			controller->getKinematicsInstanceKinematicsModels()
// 		}
		return COLLADAFW::UniqueId::INVALID;
	}

} // namespace COLLADASaxFWL
