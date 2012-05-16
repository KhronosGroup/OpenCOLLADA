/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsSceneGraphHandler.h"
#include "DAE23dsMeshBase.h"


namespace DAE23ds
{
	static const ChunkLength STATIC_SCENGRAPH_LENGHT = EMPTY_CHUNK_LENGTH  //main key frame chunk
		                                             + EMPTY_CHUNK_LENGTH + sizeof(short)+ sizeof(long) + sizeof(FILENAME) //KFHDR
   		                                             + EMPTY_CHUNK_LENGTH + 2*sizeof(long)//KEYF_FRAMES
                                                     + EMPTY_CHUNK_LENGTH + sizeof(long); //KFCURTIME
													 
	const char DUMMY[]="$$$DUMMY"; 

	//------------------------------
	SceneGraphHandler::SceneGraphHandler( Writer* writer3ds, const COLLADAFW::VisualScene* visualScene, const Writer::LibraryNodesList& libraryNodesList )
		: SceneGraphBase( writer3ds, visualScene, libraryNodesList )
		, mUniqueIdNodeMap(getUniqueIdNodeMap())
		, mSceneGraphLength( STATIC_SCENGRAPH_LENGHT )
	{
	}

	//------------------------------
	SceneGraphHandler::~SceneGraphHandler()
	{
	}	

	//------------------------------
	bool SceneGraphHandler::handle()
	{
		NodeInfo nodeInfo( COLLADABU::Math::Matrix4::IDENTITY );
		mNodeInfoStack.push( nodeInfo );

		handleNodes( mVisualScene->getRootNodes());

		return true;
	}

	//------------------------------
	bool SceneGraphHandler::handleNodes( const COLLADAFW::NodePointerArray& nodesToWriter)
	{
		for ( size_t i = 0, count = nodesToWriter.getCount(); i < count; ++i)
		{
			handleNode(nodesToWriter[i]);
		}
		return true;
	}

	//------------------------------
	bool SceneGraphHandler::handleNode(const COLLADAFW::Node* nodeToWriter)
	{
		const NodeInfo& parentNodeInfo = mNodeInfoStack.top();
		const COLLADABU::Math::Matrix4& parentWorldMatrix = parentNodeInfo.worldTransformation;
		COLLADABU::Math::Matrix4 worldMatrix = parentWorldMatrix * nodeToWriter->getTransformationMatrix();
		NodeInfo nodeInfo( worldMatrix );
		mNodeInfoStack.push(nodeInfo);

		addNodeLength( sizeof(DUMMY) , 1, nodeToWriter->getTransformationMatrix());

		handleInstanceGeometries( nodeToWriter, worldMatrix );

		handleNodes(nodeToWriter->getChildNodes());

		handleInstanceNodes( nodeToWriter->getInstanceNodes() );

		mNodeInfoStack.pop();
		return true;
	}

	//------------------------------
	void SceneGraphHandler::handleInstanceGeometries( const COLLADAFW::Node* node, const COLLADABU::Math::Matrix4& matrix )
	{
		const COLLADAFW::InstanceGeometryPointerArray& instanceGeometries = node->getInstanceGeometries();
		for ( size_t i = 0, count = instanceGeometries.getCount(); i < count; ++i)
		{
			COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometries[i];

 			Writer::InstanceGeometryInfo instanceGeometryInfo( instanceGeometry, matrix, getNextInstanceNumber(instanceGeometry) );

			const COLLADAFW::UniqueId& meshUniqueId = instanceGeometry->getInstanciatedObjectId();
			const Writer::MeshData& meshdata = getMeshData( meshUniqueId );


			ChunkLength fullBlockCount = 1;
			ChunkLength nameLength = 0;
			ChunkLength remainingTriangles;
			ChunkLength blockCount = 1;
			ChunkLength objectNameLength = OBJECT_NAME_LENGTH;

			if ( meshdata.positionsCount > MAX_INDEX_COUNT )
			{
				MeshBase::calculateBlockCountAndRemainingTriangles( meshdata.trianglesCount, remainingTriangles, blockCount, fullBlockCount );
//				nameLength = (ChunkLength)(min(meshdata.name.length() + 4, MAX_OBJECT_NAME_LENGTH) + 1);
			}
			else
			{
//				nameLength = (ChunkLength)(min(meshdata.name.length(), MAX_OBJECT_NAME_LENGTH) + 1);
			}

//			addNodeLength( nameLength, fullBlockCount, COLLADABU::Math::Matrix4::IDENTITY );
			addNodeLength( objectNameLength, blockCount, COLLADABU::Math::Matrix4::IDENTITY );

 			addInstanceGeometryInstanceGeometryInfoPair(instanceGeometry->getInstanciatedObjectId(), instanceGeometryInfo);
		}
	}

	//------------------------------
	void SceneGraphHandler::handleInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodes)
	{
		for ( size_t i = 0, count = instanceNodes.getCount(); i < count; ++i)
		{
			const COLLADAFW::InstanceNode* instanceNode = instanceNodes[i];
			const COLLADAFW::UniqueId& referencedNodeUniqueId = instanceNode->getInstanciatedObjectId();
			Writer::UniqueIdNodeMap::const_iterator it = mUniqueIdNodeMap.find( referencedNodeUniqueId );
			if ( it != mUniqueIdNodeMap.end() )
			{
				const COLLADAFW::Node* referencedNode = it->second;
				handleNode( referencedNode );
			}
		}
	}

	//------------------------------
	void SceneGraphHandler::addNodeLength( ChunkLength objectRefLength, ChunkLength factor, const COLLADABU::Math::Matrix4& matrix )
	{
		// empty chunk + node name + 3 short flags
		ChunkLength nodeHDRLength = EMPTY_CHUNK_LENGTH + objectRefLength + 3*sizeof(short);

		// empty chunk + node id
		ChunkLength nodeIDLength = EMPTY_CHUNK_LENGTH + sizeof(short);

		// empty chunk + node hdr + node id
		ChunkLength objectDesLength = EMPTY_CHUNK_LENGTH + nodeHDRLength + nodeIDLength;

		if ( !getApplyTransformationsToMeshes() )
		{

			// add transformations
			objectDesLength += PIVOT_LENGTH;
			objectDesLength += POS_TRACK_TAG_LENGTH;
			objectDesLength += SCL_TRACK_TAG_LENGTH;
			objectDesLength += ROT_TRACK_TAG_LENGTH;
		}


		mSceneGraphLength += factor * objectDesLength;
	}


} // namespace DAE23ds
