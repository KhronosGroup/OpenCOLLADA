/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsSceneGraphWriter.h"
#include "DAE23dsChunkIDs.h"

#include "CommonBuffer.h"


namespace DAE23ds
{

	const char DUMMY[]="$$$DUMMY"; 


	//------------------------------
	SceneGraphWriter::SceneGraphWriter( Writer* writer3ds, const COLLADAFW::VisualScene* visualScene, const Writer::LibraryNodesList& libraryNodesList )
		: SceneGraphBase( writer3ds, visualScene, libraryNodesList )
		, mBuffer(getBuffer())
		, mUniqueIdNodeMap(getUniqueIdNodeMap())
		, mNext3dsNodeId(0)
	{
	}

	//------------------------------
	SceneGraphWriter::~SceneGraphWriter()
	{
	}

	//------------------------------
	bool SceneGraphWriter::write( ChunkLength scenegraphLength )
	{
		// write key frame chunk
		mBuffer.copyToBuffer(KEYF3DS);
		mBuffer.copyToBuffer(scenegraphLength);

		// write KFHDR chunk
		mBuffer.copyToBuffer(KEYF_HDR);
		mBuffer.copyToBuffer((ChunkLength)(EMPTY_CHUNK_LENGTH + sizeof(short)+ sizeof(long) + sizeof(FILENAME)));
		mBuffer.copyToBuffer((short)5); //revision 5
		mBuffer.copyToBuffer( FILENAME, sizeof(FILENAME));
		// we always write only one frame
		mBuffer.copyToBuffer((long)100); //animation length

		// write KEYF_FRAMES chunk
		mBuffer.copyToBuffer(KEYF_FRAMES);
		mBuffer.copyToBuffer((ChunkLength)(EMPTY_CHUNK_LENGTH + 2*sizeof(long)));
		// we always begin and end at frame 0
		mBuffer.copyToBuffer((long)0); //first_frame
		mBuffer.copyToBuffer((long)100); //last_frame

		// write current time chunk
		mBuffer.copyToBuffer(KEYF_CURTIME);
		mBuffer.copyToBuffer((ChunkLength)(EMPTY_CHUNK_LENGTH + sizeof(long)));
		// we always start with frame 0
		mBuffer.copyToBuffer((long)0);  //current frame

		writeNodes( mVisualScene->getRootNodes(), (short)0xFFFF);
		return true;
	}

	//------------------------------
	bool SceneGraphWriter::writeNodes( const COLLADAFW::NodePointerArray& nodesToWriter, short parent3dsNodeId)
	{
		for ( size_t i = 0, count = nodesToWriter.getCount(); i < count; ++i)
		{
			writeNode(nodesToWriter[i], parent3dsNodeId);
		}
		return true;
	}

	//------------------------------
	bool SceneGraphWriter::writeNode(const COLLADAFW::Node* nodeToWriter, short parent3dsNodeId )
	{
		short nodeId = mNext3dsNodeId++;

		writeNode( DUMMY, sizeof(DUMMY), nodeId, parent3dsNodeId, nodeToWriter->getTransformationMatrix() );

		writeInstanceGeometries( nodeToWriter->getInstanceGeometries(), nodeId);

		writeNodes(nodeToWriter->getChildNodes(), nodeId);

		writeInstanceNodes( nodeToWriter->getInstanceNodes(), nodeId );

		return true;
	}

	//------------------------------
	bool SceneGraphWriter::writeNode(const char* objectRefName, ChunkLength objectRefLength, short nodeId, short parent3dsNodeId, const COLLADABU::Math::Matrix4& matrix )
	{
		// empty chunk + node name + 3 short flags
		ChunkLength nodeHDRLength = EMPTY_CHUNK_LENGTH + objectRefLength + 3*sizeof(short);

		// empty chunk + node id
		ChunkLength nodeIDLength = EMPTY_CHUNK_LENGTH + sizeof(short);

		// empty chunk + node hdr + node id
		ChunkLength objectDesLength = EMPTY_CHUNK_LENGTH + nodeHDRLength + nodeIDLength;


		if ( !getApplyTransformationsToMeshes() )
		{
			objectDesLength += PIVOT_LENGTH;
			objectDesLength += POS_TRACK_TAG_LENGTH;
			objectDesLength += SCL_TRACK_TAG_LENGTH;
			objectDesLength += ROT_TRACK_TAG_LENGTH;
		}

		// object description
		mBuffer.copyToBuffer(KEYF_OBJDES);
		mBuffer.copyToBuffer(objectDesLength);

		// node id
		mBuffer.copyToBuffer(KEYF_NODE_ID);
		mBuffer.copyToBuffer(nodeIDLength);
		mBuffer.copyToBuffer(nodeId);

		// node HDR (hierarchy)
		mBuffer.copyToBuffer(KEYF_OBJHIERARCH);
		mBuffer.copyToBuffer(nodeHDRLength);
		mBuffer.copyToBuffer(objectRefName, objectRefLength);
		static const short flags1 = 0x4000;
		static const short flags2 = 0x0000;
		mBuffer.copyToBuffer(flags1);
		mBuffer.copyToBuffer(flags2);
		mBuffer.copyToBuffer(parent3dsNodeId);


		if ( !getApplyTransformationsToMeshes() )
		{
			COLLADABU::Math::Vector3 translation = COLLADABU::Math::Vector3::ZERO;
			bool exportTranslation = false;

			COLLADABU::Math::Vector3 rotationAxis = COLLADABU::Math::Vector3::UNIT_Z;
			double rotationAngle = 0; // in radians
			bool exportRotation = false;

			COLLADABU::Math::Vector3 scaleVector = COLLADABU::Math::Vector3::UNIT_SCALE;
			bool exportScale = false;

			// add transformations
			if ( !matrix.isIdentiy() )
			{
				translation = matrix.getTrans();

				COLLADABU::Math::Matrix3 matrix3;
				matrix.extract3x3Matrix(matrix3);

				scaleVector = matrix.getScale();

				double scaleFactor = scaleVector[0]*scaleVector[1]*scaleVector[2];

				// if true, transformation is not a rotation, we neither export the scale nor the rotation
				bool doNotExportScale = COLLADABU::Math::Utils::equalsZero(scaleFactor);

				if ( !doNotExportScale )
				{
					// we need to divide matrix3 by scaleFactor to ensure that it is orthonormal in case where 
					// there is a scale in matrix3
					double inverseScaleFactor = 1 / scaleFactor;
					( inverseScaleFactor* matrix3 ).toAxisAngle( rotationAxis, rotationAngle);
				}
				else
				{
					// transformation is not a rotation, we do not export the scale
					// TODO: handle error
				}
			}


			// PIVOT
			mBuffer.copyToBuffer(PIVOT);
			mBuffer.copyToBuffer(PIVOT_LENGTH);
			// we write an identity pivot
			mBuffer.copyToBuffer((float)0); //position x
			mBuffer.copyToBuffer((float)0); //position y
			mBuffer.copyToBuffer((float)0); //position z


			// Array of 4 short whose meaning is unknown
			static const short unknownShort4Array[] = {0,0,0,0};

			// POS_TRACK_TAG
			mBuffer.copyToBuffer(POS_TRACK_TAG);
			mBuffer.copyToBuffer(POS_TRACK_TAG_LENGTH);
			mBuffer.copyToBuffer((short)0); //flags
			mBuffer.copyToBuffer(unknownShort4Array, 4); //unknown short array[4]
			mBuffer.copyToBuffer((short)1); //keys, we only export one key
			mBuffer.copyToBuffer((short)0); //unknown, always 0
			//struct
			mBuffer.copyToBuffer((short)0); //framenum, always 0
			mBuffer.copyToBuffer((long)0); //unknown long, always 0
			mBuffer.copyToBuffer((float)translation[0]); //position x
			mBuffer.copyToBuffer((float)translation[1]); //position y
			mBuffer.copyToBuffer((float)translation[2]); //position z

			// ROT_TRACK_TAG
			mBuffer.copyToBuffer(ROT_TRACK_TAG);
			mBuffer.copyToBuffer(ROT_TRACK_TAG_LENGTH);
			mBuffer.copyToBuffer((short)0); //flags
			mBuffer.copyToBuffer(unknownShort4Array, 4); //unknown short array[4]
			mBuffer.copyToBuffer((short)1); //keys, we only export one key
			mBuffer.copyToBuffer((short)0); //unknown, always 0
			//struct
			mBuffer.copyToBuffer((short)0); //framenum, always 0
			mBuffer.copyToBuffer((long)0); //unknown long, always 0
			mBuffer.copyToBuffer((float)rotationAngle); //rotation angle
			mBuffer.copyToBuffer((float)rotationAxis[0]); //axis x
			mBuffer.copyToBuffer((float)rotationAxis[1]); //axis y
			mBuffer.copyToBuffer((float)rotationAxis[2]); //axis z

			// SCL_TRACK_TAG
			mBuffer.copyToBuffer(SCL_TRACK_TAG);
			mBuffer.copyToBuffer(SCL_TRACK_TAG_LENGTH);
			mBuffer.copyToBuffer((short)0); //flags
			mBuffer.copyToBuffer(unknownShort4Array, 4); //unknown short array[4]
			mBuffer.copyToBuffer((short)1); //keys, we only export one key
			mBuffer.copyToBuffer((short)0); //unknown, always 0
			//struct
			mBuffer.copyToBuffer((short)0); //framenum, always 0
			mBuffer.copyToBuffer((long)0); //unknown long, always 0
			mBuffer.copyToBuffer((float)scaleVector[0]); //scale x
			mBuffer.copyToBuffer((float)scaleVector[1]); //scale y
			mBuffer.copyToBuffer((float)scaleVector[2]); //scale z
		}

		return true;
	}


	//------------------------------
	void SceneGraphWriter::writeInstanceGeometries( const COLLADAFW::InstanceGeometryPointerArray& instanceGeometries, short parent3dsNodeId )
	{
		for ( size_t i = 0, count = instanceGeometries.getCount(); i < count; ++i)
		{
			COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometries[i];
			const Writer::ObjectIdList& objectIds = getInstanceGeometryObjectIds( Writer::InstanceGeometryIdentifier(instanceGeometry, getNextInstanceNumber(instanceGeometry)) );
			Writer::ObjectIdList::const_iterator it = objectIds.begin();
			for ( ; it != objectIds.end(); ++it )
			{
				const Writer::ObjectId& objectId = *it;
				short nodeId = mNext3dsNodeId++;
				const char* objectName = Writer::calculateObjectNameFromObjectId( objectId );

				writeNode( objectName, (ChunkLength)(Writer::getObjectNameLength()), nodeId, parent3dsNodeId, COLLADABU::Math::Matrix4::IDENTITY);
			}
		}
	}

	//------------------------------
	void SceneGraphWriter::writeInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodes, short parent3dsNodeId)
	{
		for ( size_t i = 0, count = instanceNodes.getCount(); i < count; ++i)
		{
			const COLLADAFW::InstanceNode* instanceNode = instanceNodes[i];
			const COLLADAFW::UniqueId& referencedNodeUniqueId = instanceNode->getInstanciatedObjectId();
			Writer::UniqueIdNodeMap::const_iterator it = mUniqueIdNodeMap.find( referencedNodeUniqueId );
			if ( it != mUniqueIdNodeMap.end() )
			{
				const COLLADAFW::Node* referencedNode = it->second;
				writeNode( referencedNode, parent3dsNodeId );
			}
		}
	}

} // namespace DAE23ds
