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
#include "COLLADAMaxMorphControllerCreator.h"

#include "COLLADAFWMorphController.h"
#include "COLLADAFWMesh.h"

#include "MorphR3.h"

namespace COLLADAMax
{

    //------------------------------
	MorphControllerCreator::MorphControllerCreator( DocumentImporter* documentImporter )
		: ImporterBase(documentImporter)
	{}

    //------------------------------
	MorphControllerCreator::~MorphControllerCreator()
	{
	}

	//------------------------------
	bool MorphControllerCreator::create()
	{
		// create all the morph controller that are instantiated in the scene graph
		DocumentImporter::UniqueIdINodeMultiMapConstIterator firstInstance = getUniqueIdObjectINodesBegin();
		DocumentImporter::UniqueIdINodeMultiMapConstIterator lastInstance = getUniqueIdObjectINodesEnd();
		for ( DocumentImporter::UniqueIdINodeMultiMapConstIterator it = firstInstance; it != lastInstance; ++it )
		{
			const COLLADAFW::UniqueId& morphControllerUniqueId = it->first;
			INode* referencingINode = it->second;

			const COLLADAFW::MorphController* morphController = getMorphControllerByUniqueId( morphControllerUniqueId );
			if ( morphController )
			{
				if ( !createMorphController( morphController, referencingINode) )
				{
					return false;
				}
			}
		}

		// create all the morph controller that are the source of a skin controller
		const DocumentImporter::UniqueIdINodeMap& morphControllers = getMorphUniqueIdINodeMap();
		for ( DocumentImporter::UniqueIdINodeMap::const_iterator it = morphControllers.begin(); it != morphControllers.end(); ++it )
		{
			const COLLADAFW::UniqueId& morphControllerUniqueId = it->first;
			INode* referencingINode = it->second;

			const COLLADAFW::MorphController* morphController = getMorphControllerByUniqueId( morphControllerUniqueId );
			if ( morphController )
			{
				if ( !createMorphController( morphController, referencingINode) )
				{
					return false;
				}
			}
		}

		return true;
	}

	//------------------------------
	bool MorphControllerCreator::createMorphController( const COLLADAFW::MorphController* morphController, INode* referencingINode )
	{
		Object* sourceObject = getObjectByUniqueId( morphController->getSource() );

		if ( !sourceObject )
		{
			// TODO handle error
			// morph source object not present
			return true;
		}

		mMorphModifier = (MorphR3*) createMaxObject(OSM_CLASS_ID, MORPHER_CLASS_ID);

		if ( !mMorphModifier )
		{
			// TODO handle error
			// morph controller could not be created
			return true;
		}

		if ( (sourceObject->ClassID() == derivObjClassID) || (sourceObject->ClassID() == WSMDerivObjClassID) )
		{
			// Object is a derived object, just attach ourselves to it
			mDerivedObject = (IDerivedObject*) sourceObject;
		}
		else
		{
			// Create the derived object for the target and the modifier
			mDerivedObject = CreateDerivedObject(sourceObject);
		}

		mDerivedObject->AddModifier(mMorphModifier);
		mMorphModifier->cache.MakeCache(sourceObject);

		const COLLADAFW::FloatOrDoubleArray& morphWeights = morphController->getMorphWeights();
		const COLLADAFW::UniqueIdArray& morphTargets = morphController->getMorphTargets();
		// There is a maximum number of channels supported by the 3dsMax morpher:
		// Calculate the number of channels to process
		size_t colladaTargetCount = morphTargets.getCount();
		int channelCount = (int) min(colladaTargetCount, mMorphModifier->chanBank.size());

		bool weigtsAreAnimated = false;

		for (int i = 0; i < channelCount; ++i)
		{
			const COLLADAFW::UniqueId& targetUniqueId = morphTargets[i];
			Object* targetObject = getObjectByUniqueId( targetUniqueId );
			if ( !targetObject )
			{
				// TODO handle error
				// the target has not been created, might be missing in dae file
				return true;
			}
			INodeList targetINodes;
			getObjectINodesByUniqueId( targetUniqueId, targetINodes );
			INode* targetINode = 0;
			if ( !targetINodes.empty() )
			{
				// it does not seem to make a difference which INode we use, as long as it references the correct geometry
				targetINode = targetINodes[0];
			}
		
			morphChannel* channel = &mMorphModifier->chanBank[i];
			if ( targetINode )
			{
				channel->buildFromNode(targetINode);
				channel->mConnection = targetINode;
			}
			else
			{
				// Manually initializes this channel
				initializeChannelGeometry(channel, targetObject);
			}

			if ( weigtsAreAnimated )
			{

			}
			else
			{
				float weight = 0;
				if ( morphWeights.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT )
				{
					weight = (*morphWeights.getFloatValues())[i];
				}
				else if ( morphWeights.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
				{
					weight = (float)(*morphWeights.getDoubleValues())[i];
				}
				channel->cblock->SetValue(0, 0, weight * 100);
			}
		}

		//assign the morph controller to all INodes referencing it
		INodeList referencingINodes;
		getObjectINodesByUniqueId( morphController->getUniqueId(), referencingINodes );

		for ( size_t i = 0, count = referencingINodes.size(); i < count; ++i)
		{
			INode* referencingINode = referencingINodes[i];
			referencingINode->SetObjectRef(mDerivedObject);
		}

		addUniqueIdObjectPair( morphController->getUniqueId(), mDerivedObject );
		return true;
	}

	//------------------------------
	bool MorphControllerCreator::initializeChannelGeometry( morphChannel* channel, Object* geometryObject )
	{
		if ( !channel || !geometryObject )
		{
			return false;
		}

		Class_ID geometryObjectClassId = geometryObject->ClassID();
	
		MNMesh* polyMesh = 0;
		Mesh* triangleMesh = 0;
	
		if ( (geometryObjectClassId == EPOLYOBJ_CLASS_ID)  || (geometryObjectClassId.PartA() == POLYOBJ_CLASS_ID) )
		{
			polyMesh = &((PolyObject*)geometryObject)->GetMesh();
		}
		else if ( (geometryObjectClassId.PartA() == TRIOBJ_CLASS_ID) || (geometryObjectClassId.PartA() == EDITTRIOBJ_CLASS_ID ) )
		{
			triangleMesh = &((TriObject*)geometryObject)->GetMesh();
		}

		if ( !polyMesh && !triangleMesh )
		{
			// unsupported object type
			return true;
		}

		// Verify that the COLLADA source size matches the original mesh's vertex count
		int vertexCount = polyMesh ? polyMesh->VNum() : triangleMesh->numVerts;
		if (vertexCount != channel->mp->cache.count) 
		{
			return false;
		}

		// Set the channel's name and the necessary flags
		channel->mName = getObjectNameByObject(geometryObject).c_str();
		channel->mInvalid = true;
		channel->mActive = false;
		channel->mModded = false;


		// Allocate the channel's buffers and fill them with the relative vertex positions
		channel->AllocBuffers(vertexCount, vertexCount);
		channel->mSel.SetSize(vertexCount);
		channel->mSel.ClearAll();
		channel->mNumPoints = vertexCount;

		if ( polyMesh )
		{
			for (int i = 0; i < vertexCount; ++i)
			{
				channel->mPoints[i] = polyMesh->V( i )->p;
				channel->mDeltas[i] = (channel->mPoints[i] - channel->mp->cache.points[i]) / 100.0f;
				channel->mSel.Set(i, false);
				channel->mWeights[i] = 1.0f; // Not too sure of what the value should be here.
			}
		}
		else 
		{
			for (int i = 0; i < vertexCount; ++i)
			{
				channel->mPoints[i] = triangleMesh->verts[ i ];
				channel->mDeltas[i] = (channel->mPoints[i] - channel->mp->cache.points[i]) / 100.0f;
				channel->mSel.Set(i, false);
				channel->mWeights[i] = 1.0f; // Not too sure of what the value should be here.
			}
		}

		// Update all the UI stuff. Important? Must it be done for every channel?
		channel->mp->NotifyDependents(FOREVER,(PartID) PART_ALL,REFMSG_CHANGE);
		channel->mp->NotifyDependents(FOREVER,(PartID) PART_ALL,REFMSG_SUBANIM_STRUCTURE_CHANGED);
		channel->mp->Update_channelFULL();
		channel->mp->Update_channelParams();

		return true;
	}

} // namespace COLLADAMax
