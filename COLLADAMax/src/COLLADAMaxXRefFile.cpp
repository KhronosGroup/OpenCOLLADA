/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAMaxStableHeaders.h"

#include "COLLADAMaxControllerExporter.h"
#include "COLLADAMaxGeometriesExporter.h"
#include "COLLADAMaxVisualSceneExporter.h"
#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxTypes.h"
#include "COLLADAMaxConversionFunctor.h"

#include "COLLADASWSource.h"
#include "COLLADASWBaseInputElement.h"
#include "COLLADASWPrimitves.h"
#include "COLLADASWURI.h"

#include <max.h>
#include <iskin.h>
#include "MorphR3.h"

namespace COLLADAMax
{


    //---------------------------------------------------------------
    ControllerExporter::ControllerExporter ( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADASW::LibraryControllers ( streamWriter ),
			mExportSceneGraph(exportSceneGraph),
			mDocumentExporter(documentExporter)
    {}


	//---------------------------------------------------------------
	COLLADASW::String ControllerExporter::getControllerId( const ExportNode& exportNode, size_t number, Controller::ControllerType controllerType )
	{
		switch ( controllerType )
		{
		case Controller::SKIN:
			return GeometriesExporter::getGeometryId(exportNode) + LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX + COLLADASW::Utils::toString(number);
		case Controller::MORPH:
			return GeometriesExporter::getGeometryId(exportNode) + LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX + COLLADASW::Utils::toString(number);
		}
		return EMPTY_STRING;
	}


	//---------------------------------------------------------------
	void ControllerExporter::doExport()
	{
		doExport ( mExportSceneGraph->getRootExportNode() );
		closeLibrary();
	}



	//---------------------------------------------------------------
	void ControllerExporter::doExport( ExportNode* exportNode )
	{
		if ( !exportNode->getIsInVisualScene() )
			return;

		exportControllers(exportNode);

		size_t numberOfChildren = exportNode->getNumberOfChildren();
		for ( size_t i = 0; i < numberOfChildren; ++i )
			doExport ( exportNode->getChild ( i ) );
	}

	//---------------------------------------------------------------
	void ControllerExporter::exportControllers( ExportNode* exportNode )
	{
		ControllerList* controllerList = exportNode->getControllerList();

		if ( !controllerList->hasControllers() )
			return;

		size_t controllerCount = controllerList->getControllerCount();
		for ( size_t j = 0; j < controllerCount; ++j)
		{
			size_t i = controllerCount - j - 1;
	
			Controller* controller = controllerList->getController(i);

			ObjectIdentifier poseAfter(controller->getDerivedObject(), (int)i);

			if ( mDocumentExporter->isExportedObject(poseAfter) )
			{
				if ( controller->getType() == Controller::SKIN )
					determineReferencedJoints(exportNode, (SkinController*)controller);
				continue;
			}

			String controllerId = getControllerId(*exportNode, controllerCount - i, controller->getType());
			String controllerSource;
			if ( i <  controllerCount - 1)
			{
				ExportNode* previousControllerExportNode = mDocumentExporter->getExportedObjectExportNode(ObjectIdentifier(controllerList->getController(i+1)->getDerivedObject(), (int)i+1));
				assert( previousControllerExportNode );
				controllerSource = '#' +  getControllerId(*previousControllerExportNode, controllerCount - i - 1, controllerList->getController(i+1)->getType());
			}
			else
			{
				ExportNode* geometryExportNode = mDocumentExporter->getExportedObjectExportNode(ObjectIdentifier(exportNode->getInitialPose()));
				assert( geometryExportNode );
				controllerSource = '#' + GeometriesExporter::getGeometryId(*geometryExportNode);
			}
			exportController(exportNode, controller, controllerId, controllerSource);
			mDocumentExporter->insertExportedObject(poseAfter, exportNode);
		}
	}


	//---------------------------------------------------------------
	void ControllerExporter::exportController( ExportNode* exportNode, Controller* controller, const String& controllerId, const String& controllerSource )
	{
		if ( controller->getControllerType() == Controller::SKIN )
			exportSkinController(exportNode, (SkinController*)controller, controllerId, controllerSource);
		else if ( controller->getControllerType() == Controller::MORPH )
			exportMorphController(exportNode, (MorphController*)controller, controllerId, controllerSource);

		closeController();
	}


	//---------------------------------------------------------------
	void ControllerExporter::exportSkinController( ExportNode* exportNode, SkinController* skinController, const String& controllerId, const String& skinSource )
	{
		ISkin* skin = skinController->getSkin();

		if ( !skin )
			return;

		openSkin(controllerId, skinSource);
	
		INode* iNode = exportNode->getINode();

		Matrix3 bindShapeTransformationMatrix;
		skin->GetSkinInitTM(iNode, bindShapeTransformationMatrix, true);	
		double  bindShapeTransformationArray[4][4];
		VisualSceneExporter::matrix3ToDouble4x4(bindShapeTransformationArray, bindShapeTransformationMatrix);

		addBindShapeTransform(bindShapeTransformationArray);

		int jointCount = skin->GetNumBones();
		INodeList boneINodes;


		// Export joints source
		String jointsId = controllerId + JOINTS_SOURCE_ID_SUFFIX;
		COLLADASW::NameSource jointSource(mSW);
		jointSource.setId(jointsId);
		jointSource.setArrayId(jointsId + ARRAY_ID_SUFFIX);
		jointSource.setAccessorStride(1);
		jointSource.getParameterNameList().push_back("JOINT");
		jointSource.setAccessorCount(jointCount);
		jointSource.prepareToAppendValues();

		for (int i = 0; i <  jointCount; ++i)
		{
			// there should not be any null bone.
			// the ISkin::GetBone, not GetBoneFlat, function is called here.
			INode* boneNode = skin->GetBone(i);
			assert(boneNode);
			boneINodes.push_back(boneNode);

			ExportNode* jointExportNode = mExportSceneGraph->getExportNode(boneNode);
			assert(jointExportNode);

			if ( !jointExportNode->hasSid() )
				jointExportNode->setSid(mExportSceneGraph->createJointSid());

			jointExportNode->setIsJoint();

			jointSource.appendValues(jointExportNode->getSid());
		}
		jointSource.finish();

		determineReferencedJoints(exportNode, skinController);

		//export inverse bind matrix source
		String inverseBindMatrixId = controllerId + BIND_POSES_SOURCE_ID_SUFFIX;
		COLLADASW::Float4x4Source inverseBindMatrixSource(mSW);
		inverseBindMatrixSource.setId(inverseBindMatrixId);
		inverseBindMatrixSource.setArrayId(inverseBindMatrixId + ARRAY_ID_SUFFIX);
		inverseBindMatrixSource.setAccessorStride(16);
		inverseBindMatrixSource.getParameterNameList().push_back("TRANSFORM");
		inverseBindMatrixSource.setAccessorCount(jointCount);
		inverseBindMatrixSource.prepareToAppendValues();

		for (int i = 0; i <  jointCount; ++i)
		{
			INode* boneNode = boneINodes[i];

			Matrix3 bindPose;
			int success = skin->GetBoneInitTM(boneNode, bindPose);
			assert(success == SKIN_OK);
			bindPose.Invert();

			double bindPoseArray[4][4];
			VisualSceneExporter::matrix3ToDouble4x4(bindPoseArray, bindPose);
			inverseBindMatrixSource.appendValues(bindPoseArray);
		}
		inverseBindMatrixSource.finish();


		ISkinContextData* contextData = skin->GetContextInterface(iNode);
		int vertexCount = contextData->GetNumPoints();
		
		//count weights, excluding the ones that are
		int weightsCount = 1;
		for (int i = 0; i < vertexCount; ++i)
		{
			int jointCount = contextData->GetNumAssignedBones(i);
			for (int p = 0; p < jointCount; ++p)
			{
				float weight = contextData->GetBoneWeight(i, p);
				if ( !COLLADASW::MathUtils::equals(weight, 1.0f) )
					weightsCount++;
			}
		}

		//export weights source
		String weightsId = controllerId + WEIGHTS_SOURCE_ID_SUFFIX;
		COLLADASW::FloatSource weightsSource(mSW);
		weightsSource.setId(weightsId);
		weightsSource.setArrayId(weightsId + ARRAY_ID_SUFFIX);
		weightsSource.setAccessorStride(1);
		weightsSource.getParameterNameList().push_back("WEIGHT");
		weightsSource.setAccessorCount(weightsCount);
		weightsSource.prepareToAppendValues();

		weightsSource.appendValues(1.0);
		for (int i = 0; i < vertexCount; ++i)
		{
			int jointCount = contextData->GetNumAssignedBones(i);
			for (int p = 0; p < jointCount; ++p)
			{
				float weight = contextData->GetBoneWeight(i, p);
				if ( !COLLADASW::MathUtils::equals(weight, 1.0f) )
					weightsSource.appendValues(weight);
			}
		}
		weightsSource.finish();

		COLLADASW::JointsElement joints(mSW);
		joints.getInputList().push_back(COLLADASW::Input(COLLADASW::JOINT, "#" + jointsId));
		joints.getInputList().push_back(COLLADASW::Input(COLLADASW::BINDMATRIX, "#" + inverseBindMatrixId));
		joints.add();

		COLLADASW::VertexWeightsElement vertexWeights(mSW);
		COLLADASW::Input weightInput(COLLADASW::WEIGHT, "#" + weightsId);
		vertexWeights.getInputList().push_back(COLLADASW::Input(COLLADASW::JOINT, "#" + jointsId, 0));
		vertexWeights.getInputList().push_back(COLLADASW::Input(COLLADASW::WEIGHT, "#" + weightsId, 1));
		vertexWeights.setCount(vertexCount);

		vertexWeights.prepareToAppendVCountValues();

		for (int i = 0; i < vertexCount; ++i)
			vertexWeights.appendValues(contextData->GetNumAssignedBones(i));

		vertexWeights.CloseVCountAndOpenVElement();

		int currentIndex = 1;
		for (int i = 0; i < vertexCount; ++i)
		{
			int jointCount = contextData->GetNumAssignedBones(i);
			for (int p = 0; p < jointCount; ++p)
			{
				vertexWeights.appendValues(contextData->GetAssignedBone(i, p));
				float weight = contextData->GetBoneWeight(i, p);
				if ( !COLLADASW::MathUtils::equals(weight, 1.0f) )
				{
					vertexWeights.appendValues(currentIndex++);
				}
				else
				{
					vertexWeights.appendValues(0);
				}
			}
		}



		vertexWeights.finish();


#if 0
		int vertexCount = iskin->GetNumVertices();
		colladaSkin->SetInfluenceCount(vertexCount);
		for (int i = 0; i < vertexCount; ++i)
		{
			FCDSkinControllerVertex* vertex = colladaSkin->GetVertexInfluence(i);
			int pairCount = iskin->GetNumAssignedBones(i);
			vertex->SetPairCount(pairCount);
			for (int p = 0; p < pairCount; ++p)
			{
				FCDJointWeightPair* pair = vertex->GetPair(p);
				pair->weight = iskin->GetBoneWeight(i, p);
				pair->jointIndex = iskin->GetAssignedBone(i, p);
			}
		}


#endif
		closeSkin();
	}


	//---------------------------------------------------------------
	void ControllerExporter::exportMorphController( ExportNode* exportNode, MorphController* morphController, const String& controllerId, const String& morphSource )
	{
		MorphR3* morpher = morphController->getMorph();


		FloatList listOfWeights;
		StringList listOfTargetIds;

		String weightsId = controllerId + WEIGHTS_SOURCE_ID_SUFFIX;

		size_t channelBankCount = morpher->chanBank.size();
		for ( size_t i = 0; i<channelBankCount; ++i)
		{
			morphChannel& channel = morpher->chanBank[i];
			
			if (!channel.mActive || channel.mNumPoints == 0) 
				continue;

			INode* targetINode = channel.mConnection;

			listOfWeights.push_back(ConversionFunctors::fromPercent(channel.cblock->GetFloat(morphChannel::cblock_weight_index, mDocumentExporter->getOptions().getAnimationStart())));

			Control* weightController = channel.cblock->GetController(morphChannel::cblock_weight_index);
			mDocumentExporter->getAnimationExporter()->addAnimatedFloat(weightController, weightsId, EMPTY_STRING, (int)i, true, &ConversionFunctors::fromPercent );

			if ( !targetINode )
			{
				MorphControllerHelperGeometry morphControllerHelperGeometry;
				morphControllerHelperGeometry.exportNode = exportNode;
				morphControllerHelperGeometry.controllerId = controllerId;
				morphControllerHelperGeometry.morphController = morphController;
				morphControllerHelperGeometry.channelBankindex = i;
				
				String targetId = ExportSceneGraph::getMorphControllerHelperId(morphControllerHelperGeometry);
				listOfTargetIds.push_back(targetId);
			}
			else
			{
				ExportNode* targetExportNode = mExportSceneGraph->getExportNode(targetINode);
				assert(targetExportNode);

				ExportNode* geometryExportNode = mDocumentExporter->getExportedObjectExportNode(ObjectIdentifier(targetExportNode->getInitialPose()));
				assert( geometryExportNode );
//				listOfTargetIds.push_back(geometryExportNode);
				listOfTargetIds.push_back(GeometriesExporter::getGeometryId(*geometryExportNode));
			}
		}

		openMorph(controllerId, EMPTY_STRING, morphSource);

		//export weights source
		String targetId = controllerId + TARGETS_SOURCE_ID_SUFFIX;
		COLLADASW::IdRefSource targetsSource(mSW);
		targetsSource.setId(targetId);
		targetsSource.setArrayId(targetId + ARRAY_ID_SUFFIX);
		targetsSource.setAccessorStride(1);
		targetsSource.getParameterNameList().push_back("MORPH_TARGET");
		targetsSource.setAccessorCount((unsigned long)listOfTargetIds.size());
		targetsSource.prepareToAppendValues();

		for ( StringList::const_iterator it = listOfTargetIds.begin(); it != listOfTargetIds.end(); ++it)
			targetsSource.appendValues(*it);

		targetsSource.finish();


		//export weights source
		COLLADASW::FloatSource weightsSource(mSW);
		weightsSource.setId(weightsId);
		weightsSource.setArrayId(weightsId + ARRAY_ID_SUFFIX);
		weightsSource.setAccessorStride(1);
		weightsSource.getParameterNameList().push_back("MORPH_WEIGHT");
		weightsSource.setAccessorCount((unsigned long)listOfWeights.size());
		weightsSource.prepareToAppendValues();
		
		for ( FloatList::const_iterator it = listOfWeights.begin(); it != listOfWeights.end(); ++it)
			weightsSource.appendValues(*it);
		
		weightsSource.finish();


		COLLADASW::TargetsElement targets(mSW);
		targets.getInputList().push_back(COLLADASW::Input(COLLADASW::MORPH_TARGET, "#" + targetId));
		targets.getInputList().push_back(COLLADASW::Input(COLLADASW::MORPH_WEIGHT, "#" + weightsId));
		targets.add();

		closeMorph();

	}


	void ControllerExporter::determineReferencedJoints(ExportNode* exportNode, SkinController* skinController)
	{
		ISkin* skin = skinController->getSkin();

		int jointCount = skin->GetNumBones();

		ExportNodeSet referencedJoints;

		for (int i = 0; i <  jointCount; ++i)
		{
			// there should not be any null bone.
			// the ISkin::GetBone, not GetBoneFlat, function is called here.
			INode* boneNode = skin->GetBone(i);
			assert(boneNode);

			ExportNode* jointExportNode = mExportSceneGraph->getExportNode(boneNode);
			assert(jointExportNode);

			referencedJoints.insert(jointExportNode);
		}

		determineSkeletonRoots(referencedJoints, exportNode->getControllerList());
	}



	//---------------------------------------------------------------
	void ControllerExporter::determineSkeletonRoots( const ExportNodeSet &referencedJoints, ControllerList * controllerList)
	{
		for ( ExportNodeSet::const_iterator it = referencedJoints.begin(); it!=referencedJoints.end(); ++it)
		{
			ExportNode* joint = *it;
			if ( !isOneParentInSet(joint, referencedJoints) )
				controllerList->addReferencedJoint(joint);
		}
	}

	//---------------------------------------------------------------
	bool ControllerExporter::isOneParentInSet( ExportNode *joint, const ExportNodeSet &jointSet )
	{
		ExportNode* parentNode = joint->getParent();
		
		if ( !parentNode )
			return false;

		if ( jointSet.count(parentNode) != 0 )
			return true;

		return isOneParentInSet(parentNode, jointSet);
	}

}
