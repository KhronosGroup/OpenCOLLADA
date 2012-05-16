/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsMeshWriter.h"
#include "CommonBuffer.h"
#include "CommonFWriteBufferFlusher.h"

#include "DAE23dsChunkIDs.h"
#include "DAE23dsMeshSpliter.h"
#include "DAE23dsMeshSpliterDumper.h"

namespace DAE23ds
{



	bool multiplyMeshes = true;

	//------------------------------
	MeshWriter::MeshWriter( Writer* writer3ds, const COLLADAFW::Mesh* mesh )
		: MeshBase(writer3ds)
		, mMesh(mesh)
		, mBuffer(getBuffer())
		, mMeshAccessor(mesh)
		, mMeshPositions( mesh->getPositions() )
		, mMeshNormals( mesh->getNormals() )
		, mMeshUVCoordinates( mesh->getUVCoords() )
		, mMeshColors( mesh->getColors() )
	{
		Writer::MeshData meshData;
		meshData.meshUniqueId = mesh->getUniqueId();
		meshData.trianglesCount = mMeshAccessor.getTrianglesCount();
		meshData.positionsCount = mMeshPositions.getValuesCount();
		meshData.name = mesh->getName();
		setMeshData(meshData);
	}

	//------------------------------
	MeshWriter::~MeshWriter()
	{
	}

	//------------------------------
	bool MeshWriter::writeMeshIntoMultipleObjects( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoMultipleObjectsData& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance)
	{
		const COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometryInfo.fwInstanceGeometry;
		if ( alreadyUsingInstance && !getApplyTransformationsToMeshes() )
		{
			// the mesh has already been exported. No export needed, but we need to add the mesh object ids 
			const Writer::ObjectIdList& meshObjectIds = getInstanceGeometryObjectIds( Writer::InstanceGeometryIdentifier(alreadyUsingInstance,0));
			Writer::ObjectIdList::const_iterator it = meshObjectIds.begin();
			for ( ; it != meshObjectIds.end(); ++it )
			{
				const Writer::ObjectId& meshObjectId = *it;
				addInstanceGeometryObjectId( Writer::InstanceGeometryIdentifier(instanceGeometry,0), meshObjectId );
			}
		}
		else
		{
			// we need to export the mesh
			const COLLADAFW::MaterialBindingArray& materialBindings = instanceGeometry->getMaterialBindings();

//			writeMaterialBlocks(materialBindings);

			ObjectBlockData blockData;
			blockData.trianglesCount = MAX_TRIANGLES_PER_BLOCK;
			blockData.firstTriangleIndex = 0;
			//		blockData.verticesCount = MAX_INDEX_COUNT;

			// loop here over all blocks
			for ( ChunkLength i = 0; i  < data.fullBlocksCount; ++i )
			{
				writeMeshIntoObject( instanceGeometryInfo, blockData);
				blockData.firstTriangleIndex += blockData.trianglesCount;
			}

			// write the remaining triangles
			if ( data.remainingTriangles > 0)
			{
				blockData.trianglesCount = data.remainingTriangles;
				writeMeshIntoObject( instanceGeometryInfo, blockData);
			}
		}
		return true;
	}

	//------------------------------
	bool MeshWriter::writeMeshIntoObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const ObjectBlockData& blockData)
	{
		const COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometryInfo.fwInstanceGeometry;
		const COLLADAFW::MaterialBindingArray& materialBindings = instanceGeometry->getMaterialBindings();
		ChunkLength verticesLength = calculateVerticesLength(blockData.trianglesCount*3*3);

		ChunkLength facesMaterialsLength = calculateFacesMaterialsLength(blockData.trianglesCount, materialBindings);

		ChunkLength facesDescriptionLength = calculateFacesDescriptionLength(blockData.trianglesCount, facesMaterialsLength);

		// vertices  and faces description plus empty chunk
		ChunkLength triangularMeshLength = verticesLength + facesDescriptionLength+ EMPTY_CHUNK_LENGTH+TRI_LOCAL_LENGTH;

		ChunkLength editObjectLength = calculateObjectLength(triangularMeshLength);

		// object chunk
		mBuffer.copyToBuffer(EDIT_OBJECT);
		mBuffer.copyToBuffer(editObjectLength);

		Writer::ObjectId objectId = getAndIncreaseNextObjectId();
		const char* meshName3ds = Writer::calculateObjectNameFromObjectId( objectId );
		mBuffer.copyToBuffer(meshName3ds, Writer::getObjectNameLength());
		addInstanceGeometryObjectId(Writer::InstanceGeometryIdentifier(instanceGeometryInfo.fwInstanceGeometry, instanceGeometryInfo.instanceNumber), objectId);

		// triangular mesh
		mBuffer.copyToBuffer(OBJ_TRIMESH);
		mBuffer.copyToBuffer(triangularMeshLength);

		// vertices list mesh
		mBuffer.copyToBuffer(TRI_VERTEXL);
		mBuffer.copyToBuffer(verticesLength);
		mBuffer.copyToBuffer((CountType)(blockData.trianglesCount*3));
		writeVerticesForMultipleObjects(blockData.firstTriangleIndex, blockData.trianglesCount,instanceGeometryInfo.worldMatrix);

		// faces description
		mBuffer.copyToBuffer(TRI_FACEL1);
		mBuffer.copyToBuffer(facesDescriptionLength);
		mBuffer.copyToBuffer((CountType)(blockData.trianglesCount));
		writeTrianglesForMultipleObjects(blockData.trianglesCount);

		writeFaceMaterialsForMultipleObjects(materialBindings, blockData);

		writeMeshMatrix(instanceGeometryInfo.worldMatrix);
		return true;
	}


	//------------------------------
	bool MeshWriter::writeMeshIntoOneObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoOneObject& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance)
	{
		const COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometryInfo.fwInstanceGeometry;
		if ( alreadyUsingInstance && !getApplyTransformationsToMeshes() )
		{
			// the mesh has already been exported. No export needed, but we need to add the mesh object ids 
			const Writer::ObjectIdList& meshObjectIds = getInstanceGeometryObjectIds( Writer::InstanceGeometryIdentifier(alreadyUsingInstance,0));
			Writer::ObjectIdList::const_iterator it = meshObjectIds.begin();
			for ( ; it != meshObjectIds.end(); ++it )
			{
				const Writer::ObjectId& meshObjectId = *it;
				addInstanceGeometryObjectId( Writer::InstanceGeometryIdentifier(instanceGeometry,0), meshObjectId );
			}
		}
		else
		{
			const COLLADAFW::MaterialBindingArray& materialBindings = instanceGeometry->getMaterialBindings();

//			writeMaterialBlocks(materialBindings);

			// object chunk
			mBuffer.copyToBuffer(EDIT_OBJECT);
			mBuffer.copyToBuffer(data.editObjectLength);

			Writer::ObjectId objectId = getAndIncreaseNextObjectId();
			const char* meshName3ds = Writer::calculateObjectNameFromObjectId( objectId );
			mBuffer.copyToBuffer(meshName3ds, Writer::getObjectNameLength());
			addInstanceGeometryObjectId(Writer::InstanceGeometryIdentifier(instanceGeometryInfo.fwInstanceGeometry, instanceGeometryInfo.instanceNumber), objectId);

			// triangular mesh
			mBuffer.copyToBuffer(OBJ_TRIMESH);
			mBuffer.copyToBuffer(data.triangularMeshLength);

			// vertices list mesh
			mBuffer.copyToBuffer(TRI_VERTEXL);
			mBuffer.copyToBuffer(data.verticesLength);
			mBuffer.copyToBuffer((CountType)(mMeshPositions.getValuesCount()/3));
			writeVertices(instanceGeometryInfo.worldMatrix);

			// faces description
			mBuffer.copyToBuffer(TRI_FACEL1);
			mBuffer.copyToBuffer(data.facesDescriptionLength);
			mBuffer.copyToBuffer(data.trianglesCount);
			writeTriangles();

			writeFaceMaterials(materialBindings);
			writeMeshMatrix(instanceGeometryInfo.worldMatrix);
		}

		return true;
	}

	//------------------------------
	template<class T>
	void MeshWriter::transformAndWriteVertex( const T& vertex, float wm[3][4], size_t index)
	{
		float x = vertex[index];
		float y = vertex[index + 1];
		float z = vertex[index + 2];
		float tx = wm[0][0] * x + wm[0][1] * y + wm[0][2] * z + wm[0][3];
		float ty = wm[1][0] * x + wm[1][1] * y + wm[1][2] * z + wm[1][3];
		float tz = wm[2][0] * x + wm[2][1] * y + wm[2][2] * z + wm[2][3];

		mBuffer.copyToBuffer(tx);
		mBuffer.copyToBuffer(ty);
		mBuffer.copyToBuffer(tz);
	}


	//------------------------------
	template<class T>
	void MeshWriter::transformAndWriteVertex( const T& vertex, const COLLADABU::Math::Matrix4& worldMatrix, size_t index)
	{
		float x = (float)vertex[index];
		float y = (float)vertex[index + 1];
		float z = (float)vertex[index + 2];
		const COLLADABU::Math::Matrix4& wm = worldMatrix;
		float tx = (float)(wm.getElement(0,0) * x + wm.getElement(0,1) * y + wm.getElement(0,2) * z + wm.getElement(0,3));
		float ty = (float)(wm.getElement(1,0) * x + wm.getElement(1,1) * y + wm.getElement(1,2) * z + wm.getElement(1,3));
		float tz = (float)(wm.getElement(2,0) * x + wm.getElement(2,1) * y + wm.getElement(2,2) * z + wm.getElement(2,3));

		mBuffer.copyToBuffer(tx);
		mBuffer.copyToBuffer(ty);
		mBuffer.copyToBuffer(tz);
	}


	//------------------------------
	bool MeshWriter::writeVertices(const COLLADABU::Math::Matrix4& worldMatrix)
	{

		if ( mMeshPositions.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT )
		{
			const COLLADAFW::FloatArray* floatArray = mMeshPositions.getFloatValues();
			if ( getApplyTransformationsToMeshes() && multiplyMeshes )
			{
				// apply the world matrix to the vertices
				float wm[3][4];
				wm[0][0] = (float)worldMatrix.getElement(0,0);
				wm[0][1] = (float)worldMatrix.getElement(0,1);
				wm[0][2] = (float)worldMatrix.getElement(0,2);
				wm[0][3] = (float)worldMatrix.getElement(0,3);
				wm[1][0] = (float)worldMatrix.getElement(1,0);
				wm[1][1] = (float)worldMatrix.getElement(1,1);
				wm[1][2] = (float)worldMatrix.getElement(1,2);
				wm[1][3] = (float)worldMatrix.getElement(1,3);
				wm[2][0] = (float)worldMatrix.getElement(2,0);
				wm[2][1] = (float)worldMatrix.getElement(2,1);
				wm[2][2] = (float)worldMatrix.getElement(2,2);
				wm[2][3] = (float)worldMatrix.getElement(2,3);
				
				for ( size_t i = 0, count = floatArray->getCount()/3; i < count; ++i)
				{
					transformAndWriteVertex( *floatArray, wm, 3*i);
				}
			}
			else
			{
				// write vertices without any modifications
				// we can write the vertices directly to the mBuffer
				mBuffer.copyToBuffer(floatArray->getData(), floatArray->getCount());
			}
		}
		else if ( mMeshPositions.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray* doubleArray = mMeshPositions.getDoubleValues();
			if ( getApplyTransformationsToMeshes() && multiplyMeshes )
			{
				// apply the world matrix to the vertices
				for ( size_t i = 0, count = doubleArray->getCount()/3; i < count; ++i)
				{
					transformAndWriteVertex( *doubleArray, worldMatrix, 3*i);
				}
			}
			else
			{
				// write vertices without any modifications
				// we need to cast the values from double to float
				for ( size_t i = 0, count = doubleArray->getCount(); i < count; ++i)
				{
					mBuffer.copyToBuffer((float)((*doubleArray)[i]));
				}
			}

		}
		else
		{
			// neither float nor double
			assert(false);
			return false;
		}

		return true;
	}

	//------------------------------
	bool MeshWriter::writeVerticesForMultipleObjects(size_t firstTriangleIndex, CountType trianglesCount, const COLLADABU::Math::Matrix4& worldMatrix)
	{
		if ( mMeshPositions.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT )
		{
			MeshAccessor::TriangleType triangle = mMeshAccessor.getTriangle(firstTriangleIndex);
			const COLLADAFW::FloatArray* floatArray = mMeshPositions.getFloatValues();
			if ( getApplyTransformationsToMeshes() && multiplyMeshes )
			{
				// apply the world matrix to the vertices
				float wm[3][4];
				wm[0][0] = (float)worldMatrix.getElement(0,0);
				wm[0][1] = (float)worldMatrix.getElement(0,1);
				wm[0][2] = (float)worldMatrix.getElement(0,2);
				wm[0][3] = (float)worldMatrix.getElement(0,3);
				wm[1][0] = (float)worldMatrix.getElement(1,0);
				wm[1][1] = (float)worldMatrix.getElement(1,1);
				wm[1][2] = (float)worldMatrix.getElement(1,2);
				wm[1][3] = (float)worldMatrix.getElement(1,3);
				wm[2][0] = (float)worldMatrix.getElement(2,0);
				wm[2][1] = (float)worldMatrix.getElement(2,1);
				wm[2][2] = (float)worldMatrix.getElement(2,2);
				wm[2][3] = (float)worldMatrix.getElement(2,3);

				for ( IndexType i = 0; ; ++i)
				{
					// apply transformation
					transformAndWriteVertex( *floatArray, wm, 3*triangle.indices[0]);
					transformAndWriteVertex( *floatArray, wm, 3*triangle.indices[1]);
					transformAndWriteVertex( *floatArray, wm, 3*triangle.indices[2]);

					mMaterialIds[i] = triangle.materialId;
					if ( i >= trianglesCount - 1)
						break;
					triangle = mMeshAccessor.getNextTriangle();
				}
			}
			else
			{
				for ( IndexType i = 0; ; ++i)
				{
					// we can write the vertices directly to the mBuffer
					mBuffer.copyToBuffer(floatArray->getData() + 3*triangle.indices[0], 3);
					mBuffer.copyToBuffer(floatArray->getData() + 3*triangle.indices[1], 3);
					mBuffer.copyToBuffer(floatArray->getData() + 3*triangle.indices[2], 3);
					mMaterialIds[i] = triangle.materialId;
					if ( i >= trianglesCount - 1)
						break;
					triangle = mMeshAccessor.getNextTriangle();
				}
			}
		}
		else if ( mMeshPositions.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
		{
			// we need to cast the values from double to float
			const COLLADAFW::DoubleArray* doubleArray = mMeshPositions.getDoubleValues();

			MeshAccessor::TriangleType triangle = mMeshAccessor.getTriangle(firstTriangleIndex);

			if ( getApplyTransformationsToMeshes() && multiplyMeshes )
			{
				for ( IndexType i = 0; ; ++i)
				{
					// apply transformation
					transformAndWriteVertex( *doubleArray, worldMatrix, 3*triangle.indices[0]);
					transformAndWriteVertex( *doubleArray, worldMatrix, 3*triangle.indices[1]);
					transformAndWriteVertex( *doubleArray, worldMatrix, 3*triangle.indices[2]);

					mMaterialIds[i] = triangle.materialId;
					if ( i < trianglesCount - 1)
						break;

					triangle = mMeshAccessor.getNextTriangle();
				}
			}
			else
			{
				for ( IndexType i = 0; ; ++i)
				{
					// we need to cast the values from double to float
					IndexType index = 3*triangle.indices[0];
					mBuffer.copyToBuffer((float)((*doubleArray)[index++]));
					mBuffer.copyToBuffer((float)((*doubleArray)[index++]));
					mBuffer.copyToBuffer((float)((*doubleArray)[index++]));

					index = 3*triangle.indices[1];
					mBuffer.copyToBuffer((float)((*doubleArray)[index++]));
					mBuffer.copyToBuffer((float)((*doubleArray)[index++]));
					mBuffer.copyToBuffer((float)((*doubleArray)[index++]));

					index = 3*triangle.indices[2];
					mBuffer.copyToBuffer((float)((*doubleArray)[index++]));
					mBuffer.copyToBuffer((float)((*doubleArray)[index++]));
					mBuffer.copyToBuffer((float)((*doubleArray)[index++]));
					mMaterialIds[i] = triangle.materialId;
					if ( i < trianglesCount - 1)
						break;

					triangle = mMeshAccessor.getNextTriangle();
				}
			}
		}
		else
		{
			// neither float nor double
			assert(false);
			return false;
		}
		return true;
	}


	//------------------------------
	bool MeshWriter::writeFaceMaterials(const COLLADAFW::MaterialBindingArray& materialBindings)
	{
		for ( size_t i = 0, count = materialBindings.getCount(); i < count; ++i)
		{
			const COLLADAFW::MaterialBinding& materialBinding = materialBindings[i];
			COLLADAFW::MaterialId materialId = materialBinding.getMaterialId();

			const COLLADAFW::UniqueId& materialUniqueId = materialBinding.getReferencedMaterial();
			const COLLADAFW::Material* material = getFWMaterialByUniqueId(materialUniqueId);

			// calculate number of faces that use this material
			CountType faceCount = 0;

			const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mMesh->getMeshPrimitives();
			size_t meshPrimitivesCount = meshPrimitives.getCount();

			for ( size_t j = 0; j < meshPrimitivesCount; ++j)
			{
				const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives[j];

				COLLADAFW::MaterialId id = meshPrimitive->getMaterialId();
				if ( meshPrimitive->getMaterialId() != materialId)
				{
					// we are not interested in that primitive right now
					continue;
				}
				faceCount += calculateMeshPrimitivesTriangleCount( j );
			}

			MaterialNumber materialNumber = getMaterialNumberByUniqueId(materialUniqueId );
			const char* materialName = Writer::calculateMaterialNameFromMaterialNumer(materialNumber);


			// calculate size of the chunk
			// empty chunk 
			ChunkLength chunkLength = EMPTY_CHUNK_LENGTH;

			// materialname plus material plus one for null termination
			chunkLength	+= Writer::getMaterialNameLength();

			// plus sizeof(IndexType) for each face
			chunkLength	+= (ChunkLength)sizeof(IndexType)*faceCount;

			// plus size of face count
			chunkLength	+= (ChunkLength)sizeof(CountType);

			// write faces material
			mBuffer.copyToBuffer(TRI_FACES_MAT);
			mBuffer.copyToBuffer(chunkLength);
			mBuffer.copyToBuffer(materialName, Writer::getMaterialNameLength());
			mBuffer.copyToBuffer(faceCount);

			// we need to iterate over the primitives again to fill the facenuum array
			IndexType faceIndex = 0;
			for ( size_t i = 0; i < meshPrimitivesCount; ++i)
			{
				const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives[i];

				IndexType trianglesCount = calculateMeshPrimitivesTriangleCount( i );

				if ( meshPrimitive->getMaterialId() != materialId)
				{
					// we are not interested in that primitive right now
					// we only need to increase the index
					faceIndex += trianglesCount;
				}
				else
				{
					for ( size_t j = 0; j < trianglesCount; ++j)
					{
						mBuffer.copyToBuffer(faceIndex++);
					}
				}
			}
		}
		return true;
	}

	//------------------------------
	bool MeshWriter::writeFaceMaterialsForMultipleObjects(const COLLADAFW::MaterialBindingArray& materialBindings, const ObjectBlockData& blockData)
	{
		for ( size_t i = 0, count = materialBindings.getCount(); i < count; ++i)
		{
			const COLLADAFW::MaterialBinding& materialBinding = materialBindings[i];
			COLLADAFW::MaterialId materialId = materialBinding.getMaterialId();

			const COLLADAFW::UniqueId& materialUniqueId = materialBinding.getReferencedMaterial();

			// calculate number of faces that use this material
			CountType faceCount = 0;

			for ( size_t j = 0; j < blockData.trianglesCount; ++j)
			{
				COLLADAFW::MaterialId triangleMaterialId = mMaterialIds[j];
				if ( triangleMaterialId != materialId)
				{
					// we are not interested in that primitive right now
					continue;
				}
				faceCount++;
			}

			MaterialNumber materialNumber = getMaterialNumberByUniqueId(materialUniqueId );
			const char* materialName = Writer::calculateMaterialNameFromMaterialNumer(materialNumber);

			// calculate size of the chunk
			// empty chunk 
			ChunkLength chunkLength = EMPTY_CHUNK_LENGTH;

			// materialname plus material plus one for null termination
			chunkLength	+= Writer::getMaterialNameLength();

			// plus sizeof(IndexType) for each face
			chunkLength	+= (ChunkLength)sizeof(IndexType)*faceCount;

			// plus size of face count
			chunkLength	+= (ChunkLength)sizeof(CountType);

			// write faces material
			mBuffer.copyToBuffer(TRI_FACES_MAT);
			mBuffer.copyToBuffer(chunkLength);
			mBuffer.copyToBuffer(materialName, Writer::getMaterialNameLength());
			mBuffer.copyToBuffer(faceCount);

			// we need to iterate over the primitives again to fill the facenuum array
			IndexType faceIndex = 0;
			for ( size_t j = 0; j < blockData.trianglesCount; ++j)
			{
				
				COLLADAFW::MaterialId triangleMaterialId = mMaterialIds[j];
				if ( triangleMaterialId == materialId)
				{
					mBuffer.copyToBuffer((IndexType)j);
				}
			}
		}
		return true;
	}

	//------------------------------
	bool MeshWriter::writeTriangles()
	{

		const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mMesh->getMeshPrimitives();
		size_t meshPrimitivesCount = meshPrimitives.getCount();

		for ( size_t i = 0; i < meshPrimitivesCount; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives[i];

			const COLLADAFW::UIntValuesArray& positionsIndices = meshPrimitive->getPositionIndices();
			size_t positionsIndicesCount = positionsIndices.getCount();

			switch ( meshPrimitive->getPrimitiveType() )
			{
			case COLLADAFW::MeshPrimitive::TRIANGLES:
				{
					size_t trianglesCount = positionsIndicesCount/3;
					for ( size_t j = 0, index = 0; j < trianglesCount; ++j)
					{
						mBuffer.copyToBuffer( (CountType)(positionsIndices[index++]) );
						mBuffer.copyToBuffer( (CountType)(positionsIndices[index++]) );
						mBuffer.copyToBuffer( (CountType)(positionsIndices[index++]) );
						mBuffer.copyToBuffer( FACES_FLAGS );
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
				{
					const COLLADAFW::Tristrips* tristrips = (const COLLADAFW::Tristrips*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();
					size_t nextTristripStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						bool switchOrientation = false;
						for ( size_t j = nextTristripStartIndex + 2, lastVertex = nextTristripStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							if ( switchOrientation )
							{
								mBuffer.copyToBuffer( (IndexType)positionsIndices[j - 1] );
								mBuffer.copyToBuffer( (IndexType)positionsIndices[j - 2] );
								mBuffer.copyToBuffer( (IndexType)positionsIndices[j - 0] );
								switchOrientation = false;
							}
							else
							{
								mBuffer.copyToBuffer( (IndexType)positionsIndices[j - 2] );
								mBuffer.copyToBuffer( (IndexType)positionsIndices[j - 1] );
								mBuffer.copyToBuffer( (IndexType)positionsIndices[j - 0] );
								switchOrientation = true;
							}
							mBuffer.copyToBuffer( FACES_FLAGS );
						}
						nextTristripStartIndex += faceVertexCount;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
				{
					const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*)meshPrimitive;
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();

					size_t nextTrifanStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						if ( faceVertexCount < 3)
						{
							reportError("MeshWriter::writeTriangles", "Too few indices in mesh primitive in mesh \"" + mMesh->getName() + "\".", Writer::SEVERITY_WARNING);
							return false;
						}
						IndexType commonVertexIndex = (CountType)(positionsIndices[nextTrifanStartIndex]);
						IndexType lastVertexIndex = (CountType)(positionsIndices[nextTrifanStartIndex + 1]);
						for ( size_t j = nextTrifanStartIndex + 2, lastVertex = nextTrifanStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							CountType newVertex = (CountType)(positionsIndices[j]);
							mBuffer.copyToBuffer( commonVertexIndex );
							mBuffer.copyToBuffer( lastVertexIndex );
							mBuffer.copyToBuffer( newVertex );
							mBuffer.copyToBuffer( FACES_FLAGS );
							lastVertexIndex = newVertex;
						}
						nextTrifanStartIndex += faceVertexCount;
					}
					break;
				}
			default:
				reportError("MeshWriter::writeTriangles", "unsupported primitive type in mesh \"" + mMesh->getName() + "\".", Writer::SEVERITY_WARNING);
			}
		}
		return true;
	}

	//------------------------------
	bool MeshWriter::writeTrianglesForMultipleObjects(CountType trianglesCount)
	{
		// we simply need to write the numbers 0...trianglesCount
		for ( IndexType i = 0, index = 0; i < trianglesCount; ++i)
		{
			mBuffer.copyToBuffer(index++);
			mBuffer.copyToBuffer(index++);
			mBuffer.copyToBuffer(index++);
			mBuffer.copyToBuffer( FACES_FLAGS );
		}
		return true;
	}

	//------------------------------
	bool MeshWriter::writeMeshMatrix( const COLLADABU::Math::Matrix4& worldMatrix )
	{
		// write local matrix
		mBuffer.copyToBuffer(TRI_LOCAL);
		mBuffer.copyToBuffer(TRI_LOCAL_LENGTH);

		const COLLADABU::Math::Matrix4& matrix = (getApplyTransformationsToMeshes()&& !multiplyMeshes) ? worldMatrix : COLLADABU::Math::Matrix4::IDENTITY;

// 		for ( int j = 0; j < 4; ++j)
// 		{
// 			for ( int i = 0; i < 3; ++i)
// 			{
// 				mBuffer.copyToBuffer((float)matrix.getElement(i,j));
// 			}
// 		}

		for ( int i = 0; i < 3; ++i)
		{
			for ( int j = 0; j < 3; ++j)
			{
				mBuffer.copyToBuffer((float)matrix.getElement(i,j));
			}
		}

		mBuffer.copyToBuffer((float)matrix.getElement(0,3));
		mBuffer.copyToBuffer((float)matrix.getElement(1,3));
		mBuffer.copyToBuffer((float)matrix.getElement(2,3));

		return true;
	}

	//------------------------------
	IndexType MeshWriter::calculateMeshPrimitivesTriangleCount(size_t meshPrimitiveIndex)
	{
		return (IndexType)mMeshAccessor.getMeshPrimitiveTriangleCount(meshPrimitiveIndex);
	}


} // namespace DAE23ds
