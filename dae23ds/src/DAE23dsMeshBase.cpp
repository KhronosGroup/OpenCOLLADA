/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "dae23dsStableHeaders.h"
#include "DAE23dsMeshBase.h"

#include "Commonitoa.h"


namespace DAE23ds
{

	//------------------------------
	MeshBase::MeshBase( Writer* writer3ds, const Writer::MeshData& meshData )
		: BaseWriter(writer3ds)
		, mMeshData(meshData)
		, mGeometryMaterialBindingSet( Writer::compare )
	{
	}

	MeshBase::MeshBase( Writer* writer3ds )
		: BaseWriter(writer3ds)
		, mGeometryMaterialBindingSet( Writer::compare )
	{
		mMeshData.positionsCount = 0;
		mMeshData.trianglesCount = 0;
	}

	//------------------------------
	MeshBase::~MeshBase()
	{

	}


	//------------------------------
	bool MeshBase::handle()
	{
		const COLLADAFW::UniqueId& meshUniqueId = mMeshData.meshUniqueId;
		const Writer::GeometryUniqueIdInstanceGeometryInfoMap& instanceGeometryMap = getGeometryUniqueIdInstanceGeometryInfoMap();
		Writer::GeometryUniqueIdInstanceGeometryInfoMap::const_iterator lowerBound = instanceGeometryMap.lower_bound(meshUniqueId);
		Writer::GeometryUniqueIdInstanceGeometryInfoMap::const_iterator upperBound = instanceGeometryMap.upper_bound(meshUniqueId);

		for ( Writer::GeometryUniqueIdInstanceGeometryInfoMap::const_iterator it = lowerBound; it != upperBound; ++it)
		{
			const Writer::InstanceGeometryInfo& instanceGeometryInfo = it->second;

			handleMesh(instanceGeometryInfo);
		}

		return true;
	}

	//------------------------------
	bool MeshBase::handleMesh(const Writer::InstanceGeometryInfo& instanceGeometryInfo)
	{
		const COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometryInfo.fwInstanceGeometry;

		Writer::GeometryMaterialBinding geometryMaterialBinding;
		geometryMaterialBinding.fwInstanceGeometry = instanceGeometry;

		const COLLADAFW::InstanceGeometry* alreadyUsingInstance = 0;
		// check if the mesh with the instanceGeometrys geometryMaterialBinding has already been handled
		Writer::GeometryMaterialBindingSet::const_iterator it = mGeometryMaterialBindingSet.find(geometryMaterialBinding);
		if ( it == mGeometryMaterialBindingSet.end() )
		{
			// it has not been handle. Add to set and handle
			mGeometryMaterialBindingSet.insert(geometryMaterialBinding);
		}
		else
		{
			alreadyUsingInstance = (*it).fwInstanceGeometry;
		}

		size_t verticesCount = mMeshData.positionsCount / 3;
		if ( verticesCount > MAX_INDEX_COUNT )
		{

			return handleMeshIntoMultipleObjects(instanceGeometryInfo, alreadyUsingInstance );;
		}
		else
		{
			return handleMeshIntoOneObject( instanceGeometryInfo, alreadyUsingInstance );
		}
	}

	void MeshBase::calculateBlockCountAndRemainingTriangles( size_t trianglesCount, ChunkLength&  remainingTriangles, ChunkLength& blockCount, ChunkLength& fullBlockCount)
	{
		fullBlockCount = (ChunkLength)(trianglesCount / MAX_TRIANGLES_PER_BLOCK);
		remainingTriangles = (ChunkLength)(trianglesCount - fullBlockCount*MAX_TRIANGLES_PER_BLOCK);

		blockCount = fullBlockCount + (remainingTriangles == 0 ? 0 : 1);
	}

	//------------------------------
	bool MeshBase::handleMeshIntoMultipleObjects( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const COLLADAFW::InstanceGeometry* alreadyUsingInstance)
	{
		const COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometryInfo.fwInstanceGeometry;
		const COLLADAFW::MaterialBindingArray& materialBindings = instanceGeometry->getMaterialBindings();

		size_t trianglesCount = calculateTrianglesCount();

		ChunkLength remainingTriangles;
		ChunkLength blockCount;
		ChunkLength fullBlockCount;

		calculateBlockCountAndRemainingTriangles( trianglesCount, remainingTriangles, blockCount, fullBlockCount );

		ChunkLength verticesLength = calculateTotalVerticesLengthMultiObject(trianglesCount, blockCount);

//		ChunkLength materialNamesLength = calculateMaterialNamesLength(materialBindings);

		ChunkLength facesMaterialsLength = calculateFacesMaterialsLength(MAX_TRIANGLES_PER_BLOCK, materialBindings);

		ChunkLength remainderFacesMaterialsLength = calculateFacesMaterialsLength(remainingTriangles, materialBindings);


		ChunkLength facesDescriptionLength = calculateFacesDescriptionLengthMultiObject(trianglesCount, blockCount, facesMaterialsLength, remainderFacesMaterialsLength, fullBlockCount);

		// vertices  and faces description plus empty chunk for each block
		ChunkLength triangularMeshesLength = verticesLength + facesDescriptionLength+ (EMPTY_CHUNK_LENGTH + TRI_LOCAL_LENGTH)*blockCount;

		ChunkLength editObjectLength = calculateTotalObjectLengthMultiObject(triangularMeshesLength, blockCount);

		// triangle mesh 
		//plus plus empty chunk
		ChunkLength edit3DSLength = editObjectLength + EMPTY_CHUNK_LENGTH;

		// add mesh version size
		edit3DSLength += MESH_VERSION_CHUNK_LENGTH;

		// edit 3ds plus plus empty chunk
		ChunkLength mainLength = edit3DSLength + EMPTY_CHUNK_LENGTH;

		// add M3D3DS_VERSION version size
		mainLength += M3D_VERSION_CHUNK_LENGTH;

		WriteMeshIntoMultipleObjectsData data;
		data.editObjectLength = editObjectLength;
		data.fullBlocksCount = fullBlockCount;
		data.remainingTriangles = remainingTriangles;

		return writeMeshIntoMultipleObjects( instanceGeometryInfo, data, alreadyUsingInstance );
	}

	//------------------------------
	bool MeshBase::handleMeshIntoOneObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const COLLADAFW::InstanceGeometry* alreadyUsingInstance)
	{
		const COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometryInfo.fwInstanceGeometry;
		const COLLADAFW::MaterialBindingArray& materialBindings = instanceGeometry->getMaterialBindings();

		CountType trianglesCount = (CountType)calculateTrianglesCount();

		ChunkLength verticesLength = calculateVerticesLength();

//		ChunkLength materialNamesLength = calculateMaterialNamesLength(materialBindings);

		ChunkLength facesMaterialsLength = calculateFacesMaterialsLength(trianglesCount, materialBindings);

		ChunkLength facesDescriptionLength = calculateFacesDescriptionLength(trianglesCount, facesMaterialsLength);

		// vertices  and faces description plus empty chunk
		ChunkLength triangularMeshLength = verticesLength + facesDescriptionLength+ EMPTY_CHUNK_LENGTH + TRI_LOCAL_LENGTH;

		ChunkLength editObjectLength = calculateObjectLength(triangularMeshLength);

		WriteMeshIntoOneObject data;
		data.editObjectLength = editObjectLength;
		data.facesDescriptionLength = facesDescriptionLength;
		data.trianglesCount = trianglesCount;
		data.triangularMeshLength = triangularMeshLength;
		data.verticesLength = verticesLength;

		return writeMeshIntoOneObject( instanceGeometryInfo, data, alreadyUsingInstance );
	}

	//------------------------------
	ChunkLength MeshBase::calculateVerticesLength()
	{
		// size of empty chunk
		// size of the vertex count + size of the floats
		return calculateVerticesLength((ChunkLength)(mMeshData.positionsCount));
	}

	//------------------------------
	ChunkLength MeshBase::calculateVerticesLength(ChunkLength verticesCount_times3)
	{
		// size of empty chunk
		// size of the vertex count + size of the floats
		return EMPTY_CHUNK_LENGTH + sizeof(CountType) + verticesCount_times3 * (ChunkLength)sizeof(float);
	}

	//------------------------------
	ChunkLength MeshBase::calculateTotalVerticesLengthMultiObject( size_t trianglesCount, ChunkLength blockCount )
	{

		// size of empty chunk for each vertices chunk
		// size of the vertex count for each vertices chunk
		// size of the floats
		return (EMPTY_CHUNK_LENGTH + sizeof(CountType)) * blockCount + (ChunkLength)(3 * 3 * trianglesCount * sizeof(float));
	}

	//------------------------------
	ChunkLength MeshBase::calculateObjectLength(ChunkLength triangularMeshLength)
	{
		// size of empty chunk
		// name of the object/mesh with null termination 
		// triangle mesh size
		return EMPTY_CHUNK_LENGTH + (ChunkLength)(OBJECT_NAME_LENGTH) + triangularMeshLength;
	}

	//------------------------------
	ChunkLength MeshBase::calculateTotalObjectLengthMultiObject(ChunkLength triangularMeshesLength, ChunkLength blockCount)
	{
		// size of empty chunk for each block
		// name of the object/mesh with null termination for each block
		// triangle meshes sizes
		return blockCount*(EMPTY_CHUNK_LENGTH + (ChunkLength)(OBJECT_NAME_LENGTH)) + triangularMeshesLength;
	}

	//------------------------------
	size_t MeshBase::calculateTrianglesCount()
	{
		return mMeshData.trianglesCount;
	}

	//------------------------------
// 	ChunkLength MeshBase::calculateMaterialNamesLength( const COLLADAFW::MaterialBindingArray& materialBindings)
// 	{
// 		ChunkLength length = 0;
// 
// 		for ( size_t i = 0, count = materialBindings.getCount(); i < count; ++i)
// 		{
// 			const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding = materialBindings[i];
// 			// length of the name plus one for null termination
// 			length += calculateMaterialNameLengthFromMaterialBinding(materialBinding);
// 		}
// 		return length;
// 	}

	//------------------------------
	ChunkLength MeshBase::calculateFacesMaterialsLength(CountType trianglesCount, const COLLADAFW::MaterialBindingArray& materialBindings)
	{
		// the size is determined by:
		// 1) the number of materials and their name length
		// 2) the triangles count

		if ( trianglesCount == 0)
		{
			return 0;
		}

		if ( materialBindings.empty() )
		{
			return 0;
			// TODO: This works only if either all faces have a material assigned or none
		}

		ChunkLength length = 0;
		// each triangle appears exactly once in a facenum array
		length += trianglesCount * sizeof(IndexType);

		ChunkLength materialsCount = (ChunkLength)materialBindings.getCount();

		//fix size for each material
		// empty chunk length of faces material
		// material name length
		// nFaces length
		length += (EMPTY_CHUNK_LENGTH + sizeof(CountType) + Writer::getMaterialNameLength() ) * materialsCount;

		return length;
	}

	//------------------------------
	ChunkLength MeshBase::calculateFacesDescriptionLength(CountType trianglesCount, ChunkLength facesMaterialsLength)
	{
		// size of empty chunk
		// faces count
		// triangles indices + flag
		// faces materials
		return EMPTY_CHUNK_LENGTH + sizeof(CountType) + sizeof(CountType) * 4 * trianglesCount + facesMaterialsLength; 
	}

	//------------------------------
	ChunkLength MeshBase::calculateFacesDescriptionLengthMultiObject(size_t trianglesCount, ChunkLength blockCount, ChunkLength facesMaterialsLength, ChunkLength remainderFacesMaterialsLength, ChunkLength fullBlocksCount)
	{
		// size of empty chunk for each block
		// faces count for each block
		// triangles indices + flag
		// faces materials for each block
		return   (EMPTY_CHUNK_LENGTH + sizeof(CountType))*blockCount 
			+ facesMaterialsLength * fullBlocksCount + remainderFacesMaterialsLength
			+ sizeof(CountType) * 4 * trianglesCount; 
	}


// 	ChunkLength MeshBase::calculateMaterialNameLengthFromMaterialBinding( const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding)
// 	{
// 		COLLADAFW::MaterialId materialId = materialBinding.getMaterialId();
// 		static char mBuffer[Common::Itoa<COLLADAFW::MaterialId>::MINIMUM_BUFFERSIZE_10];
// 		size_t bytesWritten = Common::itoa( materialId, mBuffer, 10);
// 		return (ChunkLength)(sizeof(MATERIAL_NAME_PREFIX) + bytesWritten);
// 	}

	// Do not use in threads!!!!!!!!!!!
// 	const char* MeshBase::calculateMaterialNameFromMaterialBinding( const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding, ChunkLength& length)
// 	{
// 		COLLADAFW::MaterialId materialId = materialBinding.getMaterialId();
// 		static char buffer[Common::Itoa<COLLADAFW::MaterialId>::MINIMUM_BUFFERSIZE_10 + sizeof(MATERIAL_NAME_PREFIX)];
// 		static bool bufferInitialized = false;
// 		if ( !bufferInitialized )
// 		{
// 			memcpy(buffer, MATERIAL_NAME_PREFIX, sizeof(MATERIAL_NAME_PREFIX));
// 			bufferInitialized = true;
// 		}
// 		size_t bytesWritten = Common::itoa( materialId, buffer + sizeof(MATERIAL_NAME_PREFIX) - 1, 10);
// 		length =  (ChunkLength)(sizeof(MATERIAL_NAME_PREFIX) + bytesWritten );
// 		return buffer;
// 	}

} // namespace DAE23ds
