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

	/** Creates a DerivedObject from object. If object is a DerivedObject, a derived object using the same base
	object and the same modifiers is created. If not, a derived object with object as base object is created 
	(not modifiers are assigned in this case)*/
	IDerivedObject* createDerivedObject( Object* object)
	{
		IDerivedObject* createdDerivedObject = 0;
		if ( (object->ClassID() == derivObjClassID) || (object->ClassID() == WSMDerivObjClassID) )
		{
			Object* baseObject = object;

			// Modifiers are applied to the object, acquire the base object
			while ( baseObject->SuperClassID() == GEN_DERIVOB_CLASS_ID )
			{
				IDerivedObject * derivedObject = ( IDerivedObject* ) baseObject;
				baseObject = derivedObject->GetObjRef();
			}

			// Object is a derived object
			IDerivedObject* derivedObject = (IDerivedObject*) object;

			createdDerivedObject = CreateDerivedObject(baseObject);

			for ( int i = 0, count = derivedObject->NumModifiers(); i < count; ++i )
			{
				createdDerivedObject->AddModifier(derivedObject->GetModifier( i ));
			}
		}
		else
		{
			// Create the derived object for the target and the modifier
			createdDerivedObject = CreateDerivedObject(object);
		}
		return createdDerivedObject;
	}

	//------------------------------
	bool SkinControllerDataImporter::createSkinModifier( const COLLADAFW::SkinController* skinController, const COLLADAFW::SkinControllerData* skinControllerData )
	{
		Object* object = getObjectByUniqueId(skinController->getSource());
		
		if ( !object )
		{
			// TODO handle error
			// skin source object not present
			return true;
		}

		INodeList referencingINodes;
		getObjectINodesByUniqueId( skinController->getUniqueId(), referencingINodes );
		assert( referencingINodes.size() >= 1 );

		if ( referencingINodes.size() < 1 )
		{
			// This skin controller is never instantiated
			return true;
		}

		std::vector<Matrix3> overwrittenTMs;

		Matrix3 bindShapeMatrix;
		Matrix4ToMaxMatrix3( bindShapeMatrix, skinControllerData->getBindShapeMatrix());

		for ( size_t i = 0, count = referencingINodes.size(); i < count; ++i )
		{
			INode* referencingINode = referencingINodes[i];
			Matrix3 overwrittenTM = referencingINode->GetNodeTM(TIME_INITIAL_POSE);
			referencingINode->SetNodeTM(TIME_INITIAL_POSE, bindShapeMatrix);
			overwrittenTMs.push_back(overwrittenTM);
		}

		// We use this node to fill the skin controller
		INode* firstReferencingINode = referencingINodes[0];

		Modifier* maxSkinModifier = (Modifier*) createMaxObject(OSM_CLASS_ID, SKIN_CLASSID);

		if ( !maxSkinModifier )
			return true;

		mDerivedObject = createDerivedObject( object );
		mDerivedObject->AddModifier(maxSkinModifier);

		ISkinImportData* importSkin = (ISkinImportData*) maxSkinModifier->GetInterface(I_SKINIMPORTDATA);
		if ( !importSkin ) 
			return true;

		firstReferencingINode->SetObjectRef(mDerivedObject);

		// BUG. This call may cause a crash if the EPoly.dlo - MNMath.dll when using an Editable Poly mesh with a Skin Modifier
		firstReferencingINode->EvalWorldState(0);

		// Set the bind shape's initial TM and apply it to the current transform
		// in order to recreate the correct environment
		importSkin->SetSkinTm(firstReferencingINode, bindShapeMatrix, bindShapeMatrix);


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
		firstReferencingINode->EvalWorldState(0);

		// Pre-allocate these guys to avoid many memory allocation/re-allocation.
		Tab<INode*> vertexBones;
		Tab<float> vertexWeights; 

		// Assign to the skin the vertex joint-weight pairs
		size_t vertexCount = skinControllerData->getVertexCount();
		const COLLADAFW::UIntValuesArray& jointsPerVertex = skinControllerData->getJointsPerVertex();
		const COLLADAFW::IntValuesArray& jointIndices = skinControllerData->getJointIndices();
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
			importSkin->AddWeights(firstReferencingINode, (int) i, vertexBones, vertexWeights);
		}

		// From Josée Carrier of the SPARKS SDK support:
		// There is a known issue in 3dsMax 8 with the UI. Force a refresh by modifying a param block element.
		//-
		// skin_advance = 2: from enum in maxsdk\samples\modifiers\bonesdef\BonesDef_Constants.h
		int skin_advance = 2;
		IParamBlock2* pblock_advance = maxSkinModifier->GetParamBlockByID(skin_advance);
		// skin_advance_bonelimit=7: from enum in maxsdk\samples\modifiers\bonesdef\BonesDef_Constants.h
		int skin_advance_bonelimit = 7;
		// Get and set the parameter value to force a refresh
		int tmpBoneLimit = 20;
		pblock_advance->GetValue(skin_advance_bonelimit, 0, tmpBoneLimit, FOREVER);
		pblock_advance->SetValue(skin_advance_bonelimit, 0, tmpBoneLimit);
		//-



		assert(referencingINodes.size() == overwrittenTMs.size());
		for ( size_t i = 0, count = referencingINodes.size(); i < count; ++i )
		{
			INode* referencingINode = referencingINodes[i];
			Matrix3& overwrittenTM = overwrittenTMs[i];
			referencingINode->SetObjectRef(mDerivedObject);
			referencingINode->SetNodeTM(TIME_INITIAL_POSE, overwrittenTM);
		}

		return true;
	}

} // namespace COLLADAMax
