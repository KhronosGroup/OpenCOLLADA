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
				COLLADABU_ASSERT( invertedTransformation );
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

		const KinematicsIntermediateData::KinematicsModelMap& kinematicsModels = mKinematicsIntermediateData.getKinematicsModels();
		KinematicsIntermediateData::KinematicsModelMap::const_iterator modelIt = kinematicsModels.begin();
		for ( ; modelIt != kinematicsModels.end(); ++modelIt )
		{
			KinematicsModel* kinematicsModel = modelIt->second;

			COLLADAFW::KinematicsModel* fwKinematicsModel = createFWKinematicsModel(kinematicsModel);
			mKinematicsModelFWKinematicsModelMap.insert(std::make_pair(kinematicsModel, fwKinematicsModel));
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
		COLLADAFW::UniqueId uniqueId = mDocumentProcessor->createUniqueIdFromUrl( kinematicsModel->getUrl(), COLLADAFW::KinematicsModel::ID(), true);
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

		//TODO UNUSED const TransformationList& linkTransformations = link->getTransformations();

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
				COLLADABU_ASSERT(instanceJoint);
				SidAddress referencedJointAddress( instanceJoint->getUrl() );
				const SidTreeNode* referencedJointTreeNode = mDocumentProcessor->resolveSid( referencedJointAddress );
				
				COLLADABU_ASSERT( referencedJointTreeNode->getTargetType() == SidTreeNode::TARGETTYPECLASS_OBJECT );
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
				COLLADABU_ASSERT(joint);
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
				COLLADABU_ASSERT(jointPrimitives.getCount() == clonedJointPrimitives.getCount() );
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

		// @TODO UNUSED const TransformationList& linkTransformations = attachment->getTransformations();

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
		COLLADAFW::UniqueId kinematicsModelUniqueId =  mDocumentProcessor->getUniqueIdByUrl( instanceKinematicsModel.getUrl(), true );
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
		COLLADAFW::UniqueId uniqueId = mDocumentProcessor->createUniqueId( COLLADAFW::InstanceKinematicsScene::ID());
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
				String msg = "Node with id \"" + nodeId + "\" referenced in <bind_joint_axis> in <bind_kinematics_model> could not be found.";
				
				mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg);
				continue;
			}

			size_t linkNumber = 0;
			COLLADAFW::KinematicsModel* kinematicsModel = 0;
			if ( !resolveLink(kinematicsScene, kinematicsBindJointAxis, &linkNumber, &kinematicsModel) )
			{
				String msg;
				switch ( kinematicsBindJointAxis->getAxis().getValueType() )
				{
				case KinematicsAxis::VALUETYPE_PARAM:
					msg = "Axis with sid \"" + *kinematicsBindJointAxis->getAxis().getParamValue() + "\" could not be resolved.";
					break;
				case KinematicsAxis::VALUETYPE_SIDREF:
					msg = "Axis with sid address \"" + kinematicsBindJointAxis->getAxis().getSidrefValue()->getSidAddressString() + "\" could not be resolved.";
					break;
				}
				//todo: handle error smarter
//				mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg);
				continue;
			}


			// find the kin model id
			const COLLADAFW::KinematicsModelArray& kinematicsModels = mKinematicsScene->getKinematicsModels();
			size_t kinModelId = std::numeric_limits<size_t>::max();
			for ( size_t i = 0; i < kinematicsModels.getCount(); ++i)
			{
				if ( kinematicsModels[i] == kinematicsModel )
				{
					kinModelId = i;
					break;
				}
			}

			COLLADAFW::InstanceKinematicsScene::NodeLinkBinding nodeLinkBinding = {nodeUniqueId, kinModelId, linkNumber};
			mNodeLinkBindingSet.insert(nodeLinkBinding);

		}
			
		COLLADAFW::InstanceKinematicsScene::NodeLinkBindingArray& nodeLinkBindings = fwInstanceKinematicsScene->getNodeLinkBindings();
		size_t nodeLinkBindingCount = mNodeLinkBindingSet.size();
		nodeLinkBindings.allocMemory(nodeLinkBindingCount);
		nodeLinkBindings.setCount( nodeLinkBindingCount );
		NodeLinkBindingSet::const_iterator it = mNodeLinkBindingSet.begin();
		for ( size_t i = 0; it != mNodeLinkBindingSet.end(); ++it, ++i)
		{
			nodeLinkBindings[i] = *it;
		}

		mNodeLinkBindingSet.clear();
		return fwInstanceKinematicsScene;
	}

	//------------------------------
	bool KinematicsSceneCreator::resolveLink( KinematicsScene* kinematicsScene, 
		                                      KinematicsBindJointAxis* kinematicsBindJointAxis,
		                                      size_t* linkNumber,
		                                      COLLADAFW::KinematicsModel** kinModel  )
	{
		const KinematicsInstanceKinematicsModels& instanceKinematicsModels = kinematicsScene->getKinematicsInstanceKinematicsModels();
		KinematicsInstanceKinematicsModels::const_iterator it = instanceKinematicsModels.begin();

		const KinematicsAxis& axis = kinematicsBindJointAxis->getAxis();
		KinematicsAxis::ValueType axisValueType = axis.getValueType();
		if ( axisValueType != KinematicsAxis::VALUETYPE_PARAM )
		{
			return false;
		}
		const String& param = *axis.getParamValue();

		for (; it != instanceKinematicsModels.end(); ++it)
		{
			const KinematicsInstanceKinematicsModel& instanceKinematicsModel = *it;

			const COLLADABU::URI& kinematicsModelUrl = instanceKinematicsModel.getUrl();

			KinematicsModel* kinematicsModel = mDocumentProcessor->getKinematicsModelByUri(kinematicsModelUrl);

			if ( !kinematicsModel )
			{
				String msg = "Kinematics Model \"" + kinematicsModelUrl.getURIString() + "\" could not be found.";

				mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg);
				continue;
			}

			KinematicsNewParam* newParam = instanceKinematicsModel.getNewParamBySid(param);

			if ( !newParam )
			{
				continue;
			}

			KinematicsNewParam::ValueType newParamValueType = newParam->getValueType();
			if ( newParamValueType != KinematicsNewParam::VALUETYPE_SIDREF )
			{
				continue;
			}

			const SidAddress& jointSidAddress = *newParam->getSidrefValue();

			const SidTreeNode* jointSidTreeNode = mDocumentProcessor->resolveSid(jointSidAddress);

			if ( !jointSidTreeNode || (jointSidTreeNode->getTargetType() != SidTreeNode::TARGETTYPECLASS_OBJECT) )
			{
				String msg = "Joint with sid address \"" + jointSidAddress.getSidAddressString() + 
					         "\" referenced in kinematics model \"" + kinematicsModel->getUrl().getURIString() + "\" could not be found.";
				//todo: handle error smarter

//				mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg);
				continue;
			}

			COLLADAFW::Object* jointPrimitiveObject = jointSidTreeNode->getObjectTarget();
			COLLADAFW::JointPrimitive* jointPrimitive = COLLADAFW::objectSafeCast<COLLADAFW::JointPrimitive>( jointPrimitiveObject );

			if ( !jointPrimitive )
			{
				String msg = "Element with sid address \"" + jointSidAddress.getSidAddressString() + 
					"\" referenced in kinematics model \"" + kinematicsModel->getUrl().getURIString() + "\" is not a joint primitive.";
				mDocumentProcessor->handleFWLError(SaxFWLError::ERROR_UNEXPECTED_ELEMENT, msg);
				continue;
			}

			KinematicsModelFWKinematicsModelMap::const_iterator it = mKinematicsModelFWKinematicsModelMap.find(kinematicsModel);
			// there hast to be always a corresponding fw kin model
			COLLADABU_ASSERT( it != mKinematicsModelFWKinematicsModelMap.end());

			COLLADAFW::KinematicsModel* fwKinematicsModel = it->second;

			*linkNumber = findLinkByJOintPrimitive( fwKinematicsModel, jointPrimitive);

			if ( *linkNumber == std::numeric_limits<size_t>::max() )
			{
				continue;
			}

			*kinModel = fwKinematicsModel;

			return true;

// 			instanceKinematicsModel->getKinematicsNewParams()
// 			kinematicsModel->getKinematicsInstanceKinematicsModels()
		}

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
		return false;
	}

	//------------------------------
	size_t KinematicsSceneCreator::findLinkByJOintPrimitive( const COLLADAFW::KinematicsModel* fwKinModel, const COLLADAFW::JointPrimitive* jointPrimitive )
	{
		// find the joint containing the joint primitive
		const COLLADAFW::JointPointerArray& joints = fwKinModel->getJoints();
		size_t joindIndex = std::numeric_limits<size_t>::max();
		const COLLADAFW::UniqueId& jointPrimitiveUniqueId = jointPrimitive->getUniqueId();
		size_t jointsCount = joints.getCount();
		for ( size_t i = 0; (i<jointsCount) && (joindIndex == std::numeric_limits<size_t>::max()); ++i )
		{
			const COLLADAFW::Joint* joint = joints[i];
			const COLLADAFW::JointPrimitivePointerArray& jointPrimitives = joint->getJointPrimitives();
			size_t jointPrimitivesCount = jointPrimitives.getCount();
			for ( size_t j = 0; (j<jointPrimitivesCount) && (joindIndex == std::numeric_limits<size_t>::max()); ++j )
			{
				const COLLADAFW::JointPrimitive* jointPrimitive2 = jointPrimitives[j];
				const COLLADAFW::UniqueId& jointPrimitiveUniqueId2 = jointPrimitive2->getUniqueId();
				if ( jointPrimitiveUniqueId == jointPrimitiveUniqueId2 )
				{
					joindIndex = i;
				}
			}
		}

		// joint primitive could not be found in kin model
		if ( joindIndex == std::numeric_limits<size_t>::max() )
		{
			return std::numeric_limits<size_t>::max();
		}

		// search all the link joint connection for the one with joint index joindIndex
		const COLLADAFW::KinematicsModel::LinkJointConnections& linkJointConnections = fwKinModel->getLinkJointConnections();
		size_t linkJointConnectionsCount = linkJointConnections.getCount();
		size_t linkNumber = std::numeric_limits<size_t>::max();
		for ( size_t i = 0; i < linkJointConnectionsCount; ++i)
		{
			const COLLADAFW::KinematicsModel::LinkJointConnection* linkJointConnection = linkJointConnections[i];
			if ( linkJointConnection->getJointIndex() == joindIndex )
			{
				linkNumber = std::min( linkNumber, linkJointConnection->getLinkNumber());
			}
		}

		return linkNumber;
	}

} // namespace COLLADASaxFWL
