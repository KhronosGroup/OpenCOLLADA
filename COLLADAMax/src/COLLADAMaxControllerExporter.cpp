/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxControllerExporter.h"
#include "COLLADAMaxGeometriesExporter.h"
#include "COLLADAMaxVisualSceneExporter.h"
#include "COLLADAMaxTypes.h"

#include "COLLADASource.h"
#include "COLLADABaseInputElement.h"
#include "COLLADAPrimitves.h"
#include "COLLADAURI.h"

#include <max.h>
#include <iskin.h>

namespace COLLADAMax
{


    //---------------------------------------------------------------
    ControllerExporter::ControllerExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADA::LibraryControllers ( streamWriter ),
			mExportSceneGraph(exportSceneGraph),
			mDocumentExporter(documentExporter)
    {}


	//---------------------------------------------------------------
	COLLADA::String ControllerExporter::getControllerId( const ExportNode& exportNode, size_t number )
	{
		return GeometriesExporter::getGeometryId(exportNode) + LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX + COLLADA::Utils::toString(number);
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
		for ( size_t i = 0; i < controllerCount; ++i)
		{
			String controllerId = getControllerId(*exportNode, controllerCount - i);
			String controllerSource;
			if ( i <  controllerCount - 1)
				controllerSource = '#' +  getControllerId(*exportNode, controllerCount - i - 1);
			else
				controllerSource = '#' + GeometriesExporter::getGeometryId(*exportNode);
			exportController(exportNode, controllerList->getController(i), controllerId, controllerSource);
		}
	}


	//---------------------------------------------------------------
	void ControllerExporter::exportController( ExportNode* exportNode, Controller* controller, const String& controllerId, const String& controllerSource )
	{
		if ( controller->getControllerType() == Controller::SKIN )
			exportSkinController(exportNode, (SkinController*)controller, controllerId, controllerSource);

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
		COLLADA::NameSource jointSource(mSW);
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

			ExportNode* boneExportNode = mExportSceneGraph->getExportNode(boneNode);
			assert(boneExportNode);

			if ( !boneExportNode->hasSid() )
				boneExportNode->setSid(mExportSceneGraph->createJointSid());

			exportNode->getControllerList()->addReferencedJoint(boneExportNode);
			boneExportNode->setIsJoint();

			jointSource.appendValues(boneExportNode->getSid());

		}
		jointSource.finish();


		//export inverse bind matrix source
		String inverseBindMatrixId = controllerId + BIND_POSES_SOURCE_ID_SUFFIX;
		COLLADA::Float4x4Source inverseBindMatrixSource(mSW);
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
				if ( !COLLADA::MathUtils::equals(weight, 1.0f) )
					weightsCount++;
			}
		}

		//export weights source
		String weightsId = controllerId + WEIGHTS_SOURCE_ID_SUFFIX;
		COLLADA::FloatSource weightsSource(mSW);
		weightsSource.setId(weightsId);
		weightsSource.setArrayId(weightsId + ARRAY_ID_SUFFIX);
		weightsSource.setAccessorStride(1);
		weightsSource.getParameterNameList().push_back("TRANSFORM");
		weightsSource.setAccessorCount(weightsCount);
		weightsSource.prepareToAppendValues();

		weightsSource.appendValues(1.0);
		for (int i = 0; i < vertexCount; ++i)
		{
			int jointCount = contextData->GetNumAssignedBones(i);
			for (int p = 0; p < jointCount; ++p)
			{
				float weight = contextData->GetBoneWeight(i, p);
				if ( !COLLADA::MathUtils::equals(weight, 1.0f) )
					weightsSource.appendValues(weight);
			}
		}
		weightsSource.finish();

		COLLADA::JointsElement joints(mSW);
		joints.getInputList().push_back(COLLADA::Input(COLLADA::JOINT, "#" + jointsId));
		joints.getInputList().push_back(COLLADA::Input(COLLADA::BINDMATRIX, "#" + inverseBindMatrixId));
		joints.add();

		COLLADA::VertexWeightsElement vertexWeights(mSW);
		COLLADA::Input weightInput(COLLADA::WEIGHT, "#" + weightsId);
		vertexWeights.getInputList().push_back(COLLADA::Input(COLLADA::JOINT, "#" + jointsId, 0));
		vertexWeights.getInputList().push_back(COLLADA::Input(COLLADA::WEIGHT, "#" + weightsId, 1));
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
				if ( !COLLADA::MathUtils::equals(weight, 1.0f) )
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

}
