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
#include "COLLADAMaxSkinControllerDataImporter.h"

#include "COLLADAFWSkinControllerData.h"
#include "COLLADAFWSkinController.h"

#include "iskin.h"


namespace COLLADAMax
{

    //------------------------------
	SkinControllerDataImporter::SkinControllerDataImporter( DocumentImporter* documentImporter, const COLLADAFW::SkinControllerData* skinControllerData )
		: ImporterBase(documentImporter)
		, mSkinControllerData(skinControllerData)
		, mSkinModifier(0)
	{
	}

    //------------------------------
	SkinControllerDataImporter::~SkinControllerDataImporter()
	{
	}

	//------------------------------
	bool SkinControllerDataImporter::import()
	{
		const COLLADAFW::UniqueId& skinControllerDataUniqueId = mSkinControllerData->getUniqueId();
		const DocumentImporter::UniqueIdControllerMultiMap& uniqueIdControllerMap = getUniqueIdControllerMap();

		DocumentImporter::UniqueIdControllerMultiMap::const_iterator rangeBegin = uniqueIdControllerMap.lower_bound(skinControllerDataUniqueId);
		DocumentImporter::UniqueIdControllerMultiMap::const_iterator rangeEnd = uniqueIdControllerMap.upper_bound(skinControllerDataUniqueId);

		for (DocumentImporter::UniqueIdControllerMultiMap::const_iterator it = rangeBegin; it != rangeEnd; ++it)
		{
			const COLLADAFW::Controller* controller = it->second;
			if ( controller->getControllerType() == COLLADAFW::Controller::CONTROLLER_TYPE_SKIN )
			{
				if ( !createSkinModifier( (COLLADAFW::SkinController*)controller, mSkinControllerData) )
					return false;
			}
		}

		return true;
	}

	//------------------------------
	bool SkinControllerDataImporter::createSkinModifier( const COLLADAFW::SkinController* skinController, const COLLADAFW::SkinControllerData* skinControllerData )
	{
		mSkinModifier = (Modifier*) createMaxObject(OSM_CLASS_ID, SKIN_CLASSID);

		if ( !mSkinModifier )
			return true;

		Object* object = getObjectByUniqueId(skinController->getSource());
		
		if ( !object )
		{
			// TODO handle error
			// skin source object not present
			return true;
		}


		//probably we need to check if object is already a derived object
		mDerivedObject = CreateDerivedObject(object);

		mDerivedObject->AddModifier(mSkinModifier);

		ISkinImportData* importSkin = (ISkinImportData*) mSkinModifier->GetInterface(I_SKINIMPORTDATA);
		if ( !importSkin ) 
			return true;

		INodeList referencingINodes;
		getObjectINodesByUniqueId( skinController->getUniqueId(), referencingINodes );
		assert( referencingINodes.size() == 1 );

		if ( referencingINodes.size() < 1 )
		{
			// TODO handle error
			// each skin controller can be referenced only once in the frame work
			return true;
		}

		INode* referencingINode = referencingINodes[0];
		referencingINode->SetObjectRef(mDerivedObject);

		Matrix3 bindShapeMatrix;
		Matrix4ToMaxMatrix3( bindShapeMatrix, skinControllerData->getBindShapeMatrix());

		// BUG. This call may cause a crash if the EPoly.dlo - MNMath.dll when using an Editable Poly mesh with a Skin Modifier
		referencingINode->EvalWorldState(0);

		// Set the bind shape's initial TM and apply it to the current transform
		// in order to recreate the correct environment
		importSkin->SetSkinTm(referencingINode, bindShapeMatrix, bindShapeMatrix);


		size_t boneCount = skinControllerData->getJointsCount();
		const COLLADAFW::UniqueIdArray& joints = skinController->getJoints();
		const COLLADAFW::Matrix4Array& inverseBindVertices = skinControllerData->getInverseBindMatrices();

		INodeList bones; 
		bones.resize(boneCount);
		for (size_t i = 0; i < boneCount; ++i)
		{
			const COLLADAFW::UniqueId& jointUniqueId = joints[i];
			if ( !jointUniqueId.isValid() ) 
				continue;

			INode* jointNode = getINodeByUniqueId( jointUniqueId );

			if ( !jointNode )
			{
				// todo handle error.
				//there must exist a corresponding inode
				return true;
			}

			bones[i] = jointNode;
			if (importSkin->AddBoneEx(bones[i], true))
			{
				// Record the bone's INode and set the correct initial transform matrix
				Matrix3 bindPose;
				Matrix4ToMaxMatrix3( bindPose, inverseBindVertices[i] );

				bindPose.Invert();
				importSkin->SetBoneTm( jointNode, bindPose, bindPose );
			}
		}

		// As noted in the Sparks knowledge base: "Problem importing weights into Physique modifier"
		// For some reason the node must be evaluated after all the bones are added,
		// in order to be able to add the custom weights using the AddWeights function.
		referencingINode->EvalWorldState(0);

		// Pre-allocate these guys to avoid many memory allocation/re-allocation.
		Tab<INode*> vertexBones;
		Tab<float> vertexWeights; 

		// Assign to the skin the vertex joint-weight pairs
		size_t vertexCount = skinControllerData->getVertexCount();
		const COLLADAFW::UIntValuesArray& jointsPerVertex = skinControllerData->getJointsPerVertex();
		const COLLADAFW::UIntValuesArray& jointIndices = skinControllerData->getJointIndices();
		const COLLADAFW::UIntValuesArray& weightIndices = skinControllerData->getWeightIndices();
		const COLLADAFW::FloatOrDoubleArray& weights = skinControllerData->getWeights();

		size_t index = 0;
		for (size_t i = 0; i < vertexCount; ++i)
		{
			size_t pairCount = jointsPerVertex[i];
			if ( pairCount == 0 )
				continue;

			vertexBones.SetCount((int) pairCount);
			vertexWeights.SetCount((int) pairCount);
			if ( weights.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT )
			{
				const COLLADAFW::FloatArray* floatWeights = weights.getFloatValues();
				for (size_t j = 0; j < pairCount; ++j, ++index)
				{
					vertexBones[j] = bones[jointIndices[index]];
					vertexWeights[j] = (*floatWeights)[weightIndices[index]];
				}
			}
			else if ( weights.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
			{
				const COLLADAFW::DoubleArray* doubleWeights = weights.getDoubleValues();
				for (size_t j = 0; j < pairCount; ++j, ++index)
				{
					vertexBones[j] = bones[jointIndices[index]];
					vertexWeights[j] = (float)(*doubleWeights)[weightIndices[index]];
				}
			}

			// Enforce the weights for this vertex in the skin modifier
			importSkin->AddWeights(referencingINode, (int) i, vertexBones, vertexWeights);
		}


		return true;
	}

} // namespace COLLADAMax
