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
#include "COLLADAMaxGeometryImporter.h"

#include "COLLADAFWTypes.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWMesh.h"
#include "COLLADAFWTriangles.h"
#include "COLLADAFWTristrips.h"
#include "COLLADAFWTrifans.h"
#include "COLLADAFWPolygons.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAMax
{


	bool isSupportedMeshPrimitive(const COLLADAFW::MeshPrimitive* meshPrimitive)
	{
		COLLADAFW::MeshPrimitive::PrimitiveType type = meshPrimitive->getPrimitiveType();
		return    (type == COLLADAFW::MeshPrimitive::TRIANGLES) 
			|| (type == COLLADAFW::MeshPrimitive::TRIANGLE_FANS) 
			|| (type == COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS) 
			|| (type == COLLADAFW::MeshPrimitive::POLYGONS) 
			|| (type == COLLADAFW::MeshPrimitive::POLYLIST); 
	}

	GeometryImporter::GeometryImporter( DocumentImporter* documentImporter, const COLLADAFW::Geometry* geometry )
		:	ImporterBase(documentImporter)
		, mGeometry(geometry)
		, mTotalTrianglesCount(0)
		, mLargestMapChannel(0)
		, mHasVertexColor(false)
	{

	}

    //------------------------------
	GeometryImporter::~GeometryImporter()
	{
	}

	//------------------------------
	bool GeometryImporter::import()
	{
		if ( mGeometry->getType() == COLLADAFW::Geometry::GEO_TYPE_MESH )
		{
			importMesh();
		}
		return true;
	}

	//------------------------------
	bool GeometryImporter::importMesh( )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		bool success = true;
		mTotalTrianglesCount = mesh->getTrianglesTriangleCount() + mesh->getTristripsTriangleCount() + mesh->getTrifansTriangleCount();

		if ( mesh->getPolygonsPolygonCount() > 0 )
		{
			success = importPolygonMesh();
		}
		else if ( mTotalTrianglesCount > 0 )
		{
			success = importTriangleMesh();
		}

		if ( mHasVertexColor && success)
		{
			addVertexColorObjects( mGeometry->getUniqueId() );
		}


		return success;
	}

	//------------------------------
	bool GeometryImporter::importTriangleMesh( )
	{

		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		TriObject* triangleObject = CreateNewTriObject();

		Mesh& triangleMesh = triangleObject->GetMesh(); 

		
		if ( !importTriangleMeshPositions(triangleObject) )
			return false;

		if ( !importTriangleMeshNormals(triangleObject) )
			return false;

		if ( !importTriangleMeshUVCoords(triangleObject) )
			return false;

		triangleMesh.InvalidateGeomCache();
		triangleMesh.InvalidateTopologyCache();

		handleObjectReferences(mesh, triangleObject);

		return true;
	}


	//------------------------------
	bool GeometryImporter::importTriangleMeshPositions( TriObject* triangleObject )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		Mesh& triangleMesh = triangleObject->GetMesh();

		const COLLADAFW::MeshVertexData& meshPositions = mesh->getPositions();

		int positionsCount = (int)meshPositions.getValuesCount() / 3;

		triangleMesh.setNumVerts(positionsCount);

		if ( meshPositions.getType() == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray* positionsArray = meshPositions.getDoubleValues();
			for ( int i = 0; i < positionsCount; ++i)
			{
				triangleMesh.setVert(i, convertSpaceUnit((float)(*positionsArray)[3*i]), 
					                    convertSpaceUnit((float)(*positionsArray)[3*i + 1]), 
										convertSpaceUnit((float)(*positionsArray)[3*i + 2]));
			}
		}
		else
		{
			const COLLADAFW::FloatArray* positionsArray = meshPositions.getFloatValues();
			for ( int i = 0; i < positionsCount; ++i)
			{
				triangleMesh.setVert(i, convertSpaceUnit((*positionsArray)[3*i]), 
					                    convertSpaceUnit((*positionsArray)[3*i + 1]), 
										convertSpaceUnit((*positionsArray)[3*i + 2]));
			}
		}

		triangleMesh.setNumFaces((int)mTotalTrianglesCount);
		COLLADAFW::MeshPrimitiveArray& meshPrimitiveArray =  mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		DocumentImporter::FWMaterialIdMaxMtlIdMap& fWMaterialIdMaxMtlIdMap = getMaterialIdMapByGeometryUniqueId(mGeometry->getUniqueId());
		createFWMaterialIdMaxMtlIdMap( meshPrimitiveArray, fWMaterialIdMaxMtlIdMap);
		for ( size_t i = 0, count = meshPrimitiveArray.getCount(); i < count; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitiveArray[i];
			if ( ! meshPrimitive )
				continue;
			// We use the frame work material id as max material id
			MtlID maxMaterialId = (MtlID)meshPrimitive->getMaterialId();
			switch (meshPrimitive->getPrimitiveType())
			{
			case COLLADAFW::MeshPrimitive::TRIANGLES:
				{
					const COLLADAFW::Triangles* triangles = (const COLLADAFW::Triangles*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& positionIndices =  triangles->getPositionIndices();
					for ( size_t j = 0, count = positionIndices.getCount() ; j < count; j+=3 )
					{
						Face& face = triangleMesh.faces[faceIndex];
//						face.setMatID(fWMaterialIdMaxMtlIdMap[meshPrimitive->getMaterialId()]);
						if ( maxMaterialId != 0 )
							face.setMatID(maxMaterialId);
						face.setEdgeVisFlags(1, 1, 1);
						face.setVerts(positionIndices[j], positionIndices[j + 1], positionIndices[j + 2]);
						++faceIndex;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
				{
					const COLLADAFW::Tristrips* tristrips = (const COLLADAFW::Tristrips*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& positionIndices =  tristrips->getPositionIndices();
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();
					size_t nextTristripStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						bool switchOrientation = false;
						for ( size_t j = nextTristripStartIndex + 2, lastVertex = nextTristripStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							Face& face = triangleMesh.faces[faceIndex];
//   						face.setMatID(fWMaterialIdMaxMtlIdMap[meshPrimitive->getMaterialId()]);
							face.setEdgeVisFlags(1, 1, 1);
							if ( maxMaterialId != 0 )
								face.setMatID(maxMaterialId);
							if ( switchOrientation )
							{
								face.setVerts(positionIndices[j - 1], positionIndices[j - 2], positionIndices[j]);
								switchOrientation = false;
							}
							else
							{
								face.setVerts(positionIndices[j - 2], positionIndices[j - 1], positionIndices[j]);
								switchOrientation = true;
							}
							++faceIndex;
						}
						nextTristripStartIndex += faceVertexCount;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
				{
					const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& positionIndices =  trifans->getPositionIndices();
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();
					size_t nextTrifanStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						unsigned int commonVertexIndex = positionIndices[nextTrifanStartIndex];
						for ( size_t j = nextTrifanStartIndex + 2, lastVertex = nextTrifanStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							Face& face = triangleMesh.faces[faceIndex];
//   						face.setMatID(fWMaterialIdMaxMtlIdMap[meshPrimitive->getMaterialId()]);
							if ( maxMaterialId != 0 ) 
								face.setMatID(maxMaterialId);
							face.setEdgeVisFlags(1, 1, 1);
							face.setVerts(commonVertexIndex, positionIndices[j - 1], positionIndices[j]);
							++faceIndex;
						}
						nextTrifanStartIndex += faceVertexCount;
					}
					break;
				}
			default:
				continue;
			}


		}
		return true;
	}

	//------------------------------
	bool GeometryImporter::importTriangleMeshNormals( TriObject* triangleObject )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		if ( !mesh->hasNormals() )
			return true;

		Mesh& triangleMesh = triangleObject->GetMesh();
	
		triangleMesh.SpecifyNormals();
		MeshNormalSpec* normalsSpecifier = triangleMesh.GetSpecifiedNormals();

		normalsSpecifier->ClearNormals();
		size_t numFaces = triangleMesh.getNumFaces();
		normalsSpecifier->SetNumFaces((int)numFaces);

		// fill in the normals
		const COLLADAFW::MeshVertexData& meshNormals = mesh->getNormals();
		int normalCount = (int)meshNormals.getValuesCount()/3;

		normalsSpecifier->SetNumNormals(normalCount);

		if ( meshNormals.getType() == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray* normalsArray = meshNormals.getDoubleValues();
			for ( int i = 0; i < normalCount; ++i)
			{
				Point3 normal((*normalsArray)[i*3], (*normalsArray)[i*3 + 1], (*normalsArray)[i*3 + 2]);
				normalsSpecifier->Normal(i) = normal.Normalize();
				normalsSpecifier->SetNormalExplicit(i, true);
			}
		}
		else
		{
			const COLLADAFW::FloatArray* normalsArray = meshNormals.getFloatValues();
			for ( int i = 0; i < normalCount; ++i)
			{
				Point3 normal((*normalsArray)[i*3], (*normalsArray)[i*3 + 1], (*normalsArray)[i*3 + 2]);
				normalsSpecifier->Normal(i) = normal.Normalize();
				normalsSpecifier->SetNormalExplicit(i, true);
			}
		}

		//assign normals to faces (triangles)
		const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		for ( size_t i = 0, count = meshPrimitives.getCount(); i < count; ++i )
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives[i];
			size_t trianglesCount = meshPrimitive->getFaceCount();

			const COLLADAFW::UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices();
			if (isSupportedMeshPrimitive(meshPrimitive))
			{
				if ( skipMeshData( meshPrimitive, normalIndices, faceIndex ) )
				{
					continue;
				}
			}
			else
			{
				continue;
			}

			switch (meshPrimitive->getPrimitiveType())
			{
			case COLLADAFW::MeshPrimitive::TRIANGLES:
				{
					for ( size_t j = 0; j < trianglesCount; ++j)
					{
						MeshNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
						normalFace.SpecifyAll();
						normalFace.SetNormalID(0, normalIndices[3*j]);
						normalFace.SetNormalID(1, normalIndices[3*j + 1]);
						normalFace.SetNormalID(2, normalIndices[3*j + 2]);
						++faceIndex;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
				{
					const COLLADAFW::Tristrips* tristrips = (const COLLADAFW::Tristrips*) meshPrimitive;
					assert(tristrips);
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();
					size_t nextTristripStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						bool switchOrientation = false;
						for ( size_t j = nextTristripStartIndex + 2, lastVertex = nextTristripStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							MeshNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
							normalFace.SpecifyAll();
							if ( switchOrientation )
							{
								normalFace.SetNormalID(0, normalIndices[j - 1]);
								normalFace.SetNormalID(1, normalIndices[j - 2]);
								normalFace.SetNormalID(2, normalIndices[j]);
								switchOrientation = false;
							}
							else
							{
								normalFace.SetNormalID(0, normalIndices[j - 2]);
								normalFace.SetNormalID(1, normalIndices[j - 1]);
								normalFace.SetNormalID(2, normalIndices[j]);
								switchOrientation = true;
							}
							++faceIndex;
						}
						nextTristripStartIndex += faceVertexCount;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
				{
					const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*) meshPrimitive;
					assert(trifans);
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();
					size_t nextTrifanStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						unsigned int commonVertexIndex = normalIndices[nextTrifanStartIndex];
						for ( size_t j = nextTrifanStartIndex + 2, lastVertex = nextTrifanStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							MeshNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
							normalFace.SpecifyAll();
							normalFace.SetNormalID(0, commonVertexIndex);
							normalFace.SetNormalID(1, normalIndices[j - 1]);
							normalFace.SetNormalID(2, normalIndices[j]);
							++faceIndex;
						}
						nextTrifanStartIndex += faceVertexCount;
					}
					break;
				}
			default:
				continue;
			}
		}

		// TODO uncomment
//		normalsSpecifier->CheckNormals();

		return true;
	}

	//------------------------------
	template<class NumberArray>
	void GeometryImporter::setTriangleMeshUVVertices(const NumberArray& uvArray, MeshMap& meshMap, size_t stride, size_t startPosition, size_t vertsCount)
	{
		size_t uvIndex = startPosition;

		switch ( stride )
		{
		case 1:
			{
				for ( size_t i = 0; i < vertsCount; ++i)
				{
					UVVert& textureVertex = meshMap.tv[i];
					textureVertex.x = (float)uvArray[uvIndex++];
				}
				break;
			}
		case 2:
			{
				for ( size_t i = 0; i < vertsCount; ++i)
				{
					UVVert& textureVertex = meshMap.tv[i];
					textureVertex.x = (float)uvArray[uvIndex++];
					textureVertex.y = (float)uvArray[uvIndex++];
				}
				break;
			}
		case 3:
			{
				for ( size_t i = 0; i < vertsCount; ++i)
				{
					UVVert& textureVertex = meshMap.tv[i];
					float x = (float)uvArray[uvIndex++];
					float y = (float)uvArray[uvIndex++];
					float z = (float)uvArray[uvIndex++];
					textureVertex.Set(x, y, z);
				}
				break;
			}
		case 4:
			{
				for ( size_t i = 0; i < vertsCount; ++i)
				{
					UVVert& textureVertex = meshMap.tv[i];
					float x = (float)uvArray[uvIndex++];
					float y = (float)uvArray[uvIndex++];
					float z = (float)uvArray[uvIndex++];
					textureVertex.Set(x, y, z);
					uvIndex++;
				}
				break;
			}
		default:
			assert(false);
		}

	}



	//------------------------------
	void GeometryImporter::fillTriangleMeshMapPerSet( const COLLADAFW::MeshVertexData& uvCoordinates,
		const COLLADAFW::MeshVertexData::InputInfosArray& inputInfos,
		size_t sourceIndex,
		MeshMap& meshMap)
	{
		const COLLADAFW::MeshVertexData::InputInfos* inputInfo = inputInfos[ sourceIndex ];

		size_t stride = inputInfo->mStride;
		size_t vertsCount = inputInfo->mLength / stride;

		// calculate first index position
		size_t startPosition = 0;
		for ( size_t i = 0; i < sourceIndex; ++i)
		{
			const COLLADAFW::MeshVertexData::InputInfos* inputInfo = inputInfos[ sourceIndex ];
			startPosition += inputInfo->mLength;
		}

		meshMap.setNumVerts((int)vertsCount);

		if ( uvCoordinates.getType() == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray& uvArray = *uvCoordinates.getDoubleValues();
			setTriangleMeshUVVertices(uvArray, meshMap, stride, startPosition, vertsCount);
		}
		else
		{
			const COLLADAFW::FloatArray& uvArray = *uvCoordinates.getFloatValues();
			setTriangleMeshUVVertices(uvArray, meshMap, stride, startPosition, vertsCount);
		}

	}



	//------------------------------
	void GeometryImporter::setTriangleMeshUVVerticesPerPrimitiveAndChannel( const COLLADAFW::MeshPrimitive* meshPrimitive,
		MeshMap& meshMap,
		const COLLADAFW::UIntValuesArray& uvIndices,
		unsigned int initialIndex,
		size_t& currentFaceIndex)
	{
	switch (meshPrimitive->getPrimitiveType())
		{
		case COLLADAFW::MeshPrimitive::TRIANGLES:
			{
				for ( size_t j = 0, count = uvIndices.getCount() ; j < count; j+=3 )
				{
					TVFace& face = meshMap.tf[currentFaceIndex];
					face.setTVerts( uvIndices[j] - initialIndex, uvIndices[j + 1] - initialIndex, uvIndices[j + 2] - initialIndex);
					++currentFaceIndex;
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
						TVFace& face = meshMap.tf[currentFaceIndex];
						if ( switchOrientation )
						{
							face.setTVerts( uvIndices[j - 1]  - initialIndex, uvIndices[j - 2] - initialIndex, uvIndices[j] - initialIndex);
							switchOrientation = false;
						}
						else
						{
							face.setTVerts( uvIndices[j - 2] - initialIndex, uvIndices[j - 1] - initialIndex, uvIndices[j] - initialIndex);
							switchOrientation = true;
						}
						++currentFaceIndex;
					}
					nextTristripStartIndex += faceVertexCount;
				}
				break;
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
			{
				const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*) meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();
				size_t nextTrifanStartIndex = 0;
				for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
				{
					unsigned int faceVertexCount = faceVertexCountArray[k];
					unsigned int commonVertexIndex = uvIndices[nextTrifanStartIndex] - initialIndex;
					for ( size_t j = nextTrifanStartIndex + 2, lastVertex = nextTrifanStartIndex +  faceVertexCount; j < lastVertex; ++j )
					{
						TVFace& face = meshMap.tf[currentFaceIndex];
						face.setTVerts( commonVertexIndex, uvIndices[j - 1] - initialIndex, uvIndices[j] - initialIndex);
						++currentFaceIndex;
					}
					nextTrifanStartIndex += faceVertexCount;
				}
				break;
			}
		default:
			return;
		}
	}


	//------------------------------
	size_t getTriangleMeshPrimitiveTriangleCount( const COLLADAFW::MeshPrimitive* meshPrimitive)
	{
		const COLLADAFW::UIntValuesArray& faceVertexCountArray = meshPrimitive->getPositionIndices();

		switch (meshPrimitive->getPrimitiveType())
		{
		case COLLADAFW::MeshPrimitive::TRIANGLES:
			{
				return meshPrimitive->getPositionIndices().getCount()/3;
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
			{
				const COLLADAFW::Tristrips* tristrips = (const COLLADAFW::Tristrips*) meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();
				size_t triangleCount = 0;
				for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
				{
					unsigned int faceVertexCount = faceVertexCountArray[k];
					triangleCount += (faceVertexCount > 2) ? (faceVertexCount - 2) : 0;
				}
				return triangleCount;
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
			{
				const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*) meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();
				size_t triangleCount = 0;
				for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
				{
					unsigned int faceVertexCount = faceVertexCountArray[k];
					triangleCount += (faceVertexCount > 2) ? (faceVertexCount - 2) : 0;
				}
				return triangleCount;
			}
		default:
			return 0;
		}
	}

	//------------------------------
	bool GeometryImporter::importTriangleMeshUVCoords( TriObject* triangleObject )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		createSetSourcePairMapChannelMap();

		Mesh& triangleMesh = triangleObject->GetMesh();

		triangleMesh.setNumMaps( mLargestMapChannel + 1 );

		int facesCount = (int)mTotalTrianglesCount;

		// reset all texture indices of all used maps
		for ( int i = 0; i <= mLargestMapChannel; ++i )
		{
			MeshMap& meshMap = triangleMesh.Map(i);
			meshMap.setNumFaces( facesCount );
			memset( meshMap.tf, 0, sizeof(TVFace) * facesCount);
		}

		const COLLADAFW::MeshVertexData& uvCoordinates = mesh->getUVCoords();
		const COLLADAFW::MeshVertexData& vertexColors = mesh->getColors();
		const COLLADAFW::MeshVertexData::InputInfosArray& uvInputInfos = uvCoordinates.getInputInfosArray();
		const COLLADAFW::MeshVertexData::InputInfosArray& vertexColorInputInfos = vertexColors.getInputInfosArray();

		SetSourcePairMapChannelMap::const_iterator it = mSetSourcePairMapChannelMap.begin();
		for ( ; it != mSetSourcePairMapChannelMap.end(); ++it )
		{
			const SetSourcePair& setSourcePair = it->first;
			const size_t& sourceIndex = setSourcePair.second;
			// check that the channel is a texture channel and not a color channel
			long setIndex = setSourcePair.first;
			int mapChannel = it->second;
			triangleMesh.setMapSupport(mapChannel, true);

			assert( (mapChannel != 0) || ( setIndex < 0) );
			MeshMap& meshMap = triangleMesh.Map(mapChannel);
			if ( setIndex >= 0 )
			{
				fillTriangleMeshMapPerSet( uvCoordinates, uvInputInfos, sourceIndex, meshMap);
			}
			else if ( mapChannel == 0 )
			{
				fillTriangleMeshMapPerSet( vertexColors, vertexColorInputInfos, sourceIndex, meshMap);
			}
		}


		COLLADAFW::MeshPrimitiveArray& meshPrimitiveArray =  mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		for ( size_t i = 0, count = meshPrimitiveArray.getCount(); i < count; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitiveArray[i];
			if ( ! meshPrimitive )
				continue;

			if (isSupportedMeshPrimitive(meshPrimitive))
			{
				size_t currentFaceIndex = faceIndex;

				//uv
				const COLLADAFW::IndexListArray& uvIndexArray = meshPrimitive->getUVCoordIndicesArray();
				for ( size_t j = 0, count = uvIndexArray.getCount(); j < count; ++j)
				{
					const COLLADAFW::IndexList& uvIndexList = *uvIndexArray[j];
					size_t sourceIndex = mUVInitialIndexSourceIndexMap[uvIndexList.getInitialIndex()];
					size_t setIndex = uvIndexList.getSetIndex();
					SetSourcePair setSourcePair( (long)setIndex, sourceIndex);
					int mapChannel = mSetSourcePairMapChannelMap[ setSourcePair ];

					unsigned int initialIndex = (unsigned int)uvIndexList.getInitialIndex();

					const COLLADAFW::UIntValuesArray& uvIndices =  uvIndexList.getIndices();

					MeshMap& meshMap = triangleMesh.Map(mapChannel);

					currentFaceIndex = faceIndex;

					setTriangleMeshUVVerticesPerPrimitiveAndChannel( meshPrimitive, meshMap, uvIndices, initialIndex, currentFaceIndex);
				}

				// vertex color color
				const COLLADAFW::IndexListArray& colorIndexArray = meshPrimitive->getColorIndicesArray();
				for ( size_t j = 0, count = colorIndexArray.getCount(); j < count; ++j)
				{
					const COLLADAFW::IndexList& colorIndexList = *colorIndexArray[j];
					size_t sourceIndex = mColorInitialIndexSourceIndexMap[colorIndexList.getInitialIndex()];
					size_t setIndex = colorIndexList.getSetIndex();
					SetSourcePair setSourcePair( -(long)(setIndex + 1), sourceIndex);
					int mapChannel = mSetSourcePairMapChannelMap[ setSourcePair ];
					if ( mapChannel != 0)
						continue;

					unsigned int initialIndex = (unsigned int)colorIndexList.getInitialIndex();

					const COLLADAFW::UIntValuesArray& colorIndices =  colorIndexList.getIndices();

					MeshMap& meshMap = triangleMesh.Map(mapChannel);

					currentFaceIndex = faceIndex;

					setTriangleMeshUVVerticesPerPrimitiveAndChannel( meshPrimitive, meshMap, colorIndices, initialIndex, currentFaceIndex);
					mHasVertexColor = true;
				}

				if ( faceIndex == currentFaceIndex )
				{
					// setTriangleMeshUVVerticesPerPrimitiveAndChannel was never called. we need to count triangle here
					faceIndex += getTriangleMeshPrimitiveTriangleCount(meshPrimitive);
				}
				else
				{ 
					// currentFaceIndex was properly set by the last setTriangleMeshUVVerticesPerPrimitiveAndChannel call
					faceIndex = currentFaceIndex;
				}
			}

		}
		return true;
	}


	//------------------------------
	bool GeometryImporter::importPolygonMesh( )
	{

		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		PolyObject* polygonObject = CreateEditablePolyObject();
		MNMesh& polygonMesh = polygonObject->GetMesh();


		if ( !importPolygonMeshPositions(polygonObject) )
			return false;

		if ( !importPolygonMeshNormals(polygonObject) )
			return false;

		if ( !importPolygonMeshUVCoords(polygonObject) )
			return false;


		polygonMesh.InvalidateGeomCache();

		handleObjectReferences(mesh, polygonObject);

		return true;
	}

	//------------------------------
	bool GeometryImporter::importPolygonMeshPositions( PolyObject* polygonObject )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		MNMesh& polgonMesh = polygonObject->GetMesh();

		const COLLADAFW::MeshVertexData& meshPositions = mesh->getPositions();

		int positionsCount = (int)meshPositions.getValuesCount() / 3;

		polgonMesh.setNumVerts(positionsCount);

		if ( meshPositions.getType() == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray* positionsArray = meshPositions.getDoubleValues();
			for ( int i = 0; i < positionsCount; ++i)
			{
				MNVert* vertex = polgonMesh.V(i);
				vertex->p = Point3( convertSpaceUnit((float)(*positionsArray)[3*i]), 
					                convertSpaceUnit((float)(*positionsArray)[3*i + 1]), 
									convertSpaceUnit((float)(*positionsArray)[3*i + 2]));
			}
		}
		else
		{
			const COLLADAFW::FloatArray* positionsArray = meshPositions.getFloatValues();
			for ( int i = 0; i < positionsCount; ++i)
			{
				MNVert* vertex = polgonMesh.V(i);
				vertex->p = Point3( convertSpaceUnit((*positionsArray)[3*i]),
					                convertSpaceUnit((*positionsArray)[3*i + 1]), 
									convertSpaceUnit((*positionsArray)[3*i + 2]));
			}
		}

		size_t polygonsCount = mTotalTrianglesCount + mesh->getPolygonsPolygonCount();
		polgonMesh.setNumFaces((int)polygonsCount);
		COLLADAFW::MeshPrimitiveArray& meshPrimitiveArray =  mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		for ( size_t i = 0, count = meshPrimitiveArray.getCount(); i < count; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitiveArray[i];
			if ( ! meshPrimitive )
				continue;
			MtlID maxMaterialId = (MtlID)meshPrimitive->getMaterialId();
			switch ( meshPrimitive->getPrimitiveType() )
			{
			case COLLADAFW::MeshPrimitive::TRIANGLES:
				{
					const COLLADAFW::Triangles* triangles = (const COLLADAFW::Triangles*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& positionIndices =  triangles->getPositionIndices();
					for ( size_t j = 0, count = positionIndices.getCount() ; j < count; j+=3 )
					{
						MNFace* face = polgonMesh.F((int)faceIndex);
						face->MakePoly(3, (int*) (&positionIndices[j]));
						if ( maxMaterialId != 0 )
							face->material = maxMaterialId;

						++faceIndex;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
				{
					const COLLADAFW::Tristrips* tristrips = (const COLLADAFW::Tristrips*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& positionIndices =  tristrips->getPositionIndices();
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();
					size_t nextTristripStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						bool switchOrientation = false;
						for ( size_t j = nextTristripStartIndex + 2, lastVertex = nextTristripStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							MNFace* face = polgonMesh.F((int)faceIndex);
							if ( switchOrientation )
							{
								int indices[3];
								indices[0] = (int)positionIndices[j - 1];
								indices[1] = (int)positionIndices[j - 2];
								indices[2] = (int)positionIndices[j ];
								face->MakePoly(3, indices);
								if ( maxMaterialId != 0 )
									face->material = maxMaterialId;
								switchOrientation = false;
							}
							else
							{
								face->MakePoly(3, (int*) (&positionIndices[j - 2]));
								if ( maxMaterialId != 0 )
									face->material = maxMaterialId;
								switchOrientation = true;
							}

							++faceIndex;
						}
						nextTristripStartIndex += faceVertexCount;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
				{
					const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& positionIndices =  trifans->getPositionIndices();
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();
					size_t nextTrifanStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						int trianglePositionsIndices[3];
						//the first vertex is the same for all fans
						trianglePositionsIndices[0] = (int)positionIndices[nextTrifanStartIndex];
						for ( size_t j = nextTrifanStartIndex + 2, lastVertex = nextTrifanStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							trianglePositionsIndices[1] = (int)positionIndices[j - 1];
							trianglePositionsIndices[2] = (int)positionIndices[j];
							MNFace* face = polgonMesh.F((int)faceIndex);
							face->MakePoly(3, trianglePositionsIndices);
							if ( maxMaterialId != 0 )
								face->material = maxMaterialId;

							++faceIndex;
						}
						nextTrifanStartIndex += faceVertexCount;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::POLYGONS:
				{
					const COLLADAFW::Polygons* polygons = (const COLLADAFW::Polygons*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& positionIndices =  polygons->getPositionIndices();
					const COLLADAFW::IntValuesArray& faceVertexCountArray = polygons->getGroupedVerticesVertexCountArray();
					size_t currentIndex = 0;
					for ( size_t j = 0, count = faceVertexCountArray.getCount() ; j < count; ++j )
					{
						int faceVertexCount = faceVertexCountArray[j];
						// TODO for now, we ignore holes in polygons
						if ( faceVertexCount <= 0 )
							continue;
						MNFace* face = polgonMesh.F((int)faceIndex);
						face->MakePoly(faceVertexCount, (int*) (&positionIndices[currentIndex]));
						if ( maxMaterialId != 0 )
							face->material = maxMaterialId;
						currentIndex += faceVertexCount;
						++faceIndex;
					}
					break;
				}
			}

		}
		return true;
	}

	//------------------------------
	bool GeometryImporter::importPolygonMeshNormals( PolyObject* polygonObject )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		if ( !mesh->hasNormals() )
			return true;

		MNMesh& polygonMesh = polygonObject->GetMesh();

		polygonMesh.SpecifyNormals();
		MNNormalSpec* normalsSpecifier = polygonMesh.GetSpecifiedNormals();

		normalsSpecifier->ClearNormals();
		size_t numFaces = polygonMesh.FNum();
		normalsSpecifier->SetNumFaces((int)numFaces);

		// fill in the normals
		const COLLADAFW::MeshVertexData& meshNormals = mesh->getNormals();
		int normalCount = (int)meshNormals.getValuesCount()/3;

		normalsSpecifier->SetNumNormals(normalCount);

		if ( meshNormals.getType() == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray* normalsArray = meshNormals.getDoubleValues();
			for ( int i = 0; i < normalCount; ++i)
			{
				Point3 normal((*normalsArray)[i*3], (*normalsArray)[i*3 + 1], (*normalsArray)[i*3 + 2]);
				normalsSpecifier->Normal(i) = normal.Normalize();
				normalsSpecifier->SetNormalExplicit(i, true);
			}
		}
		else
		{
			const COLLADAFW::FloatArray* normalsArray = meshNormals.getFloatValues();
			for ( int i = 0; i < normalCount; ++i)
			{
				Point3 normal((*normalsArray)[i*3], (*normalsArray)[i*3 + 1], (*normalsArray)[i*3 + 2]);
				normalsSpecifier->Normal(i) = normal.Normalize();
				normalsSpecifier->SetNormalExplicit(i, true);
			}
		}

		//assign normals to faces (polygons)
		const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		for ( size_t i = 0, count = meshPrimitives.getCount(); i < count; ++i )
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives[i];
			const COLLADAFW::UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices();


			if (isSupportedMeshPrimitive(meshPrimitive))
			{
				if ( skipMeshData( meshPrimitive, normalIndices, faceIndex ) )
				{
					continue;
				}
			}
			else
			{
				continue;
			}

			switch ( meshPrimitive->getPrimitiveType() )
			{
			case COLLADAFW::MeshPrimitive::TRIANGLES:
				{
					size_t faceCount = meshPrimitive->getFaceCount();
					for ( size_t j = 0; j < faceCount; ++j)
					{
						MNNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
						normalFace.SetDegree(3);
						normalFace.SpecifyAll();
						normalFace.SetNormalID(0, normalIndices[3*j]);
						normalFace.SetNormalID(1, normalIndices[3*j + 1]);
						normalFace.SetNormalID(2, normalIndices[3*j + 2]);
						++faceIndex;
					}
				}
				break;
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
							MNNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
							normalFace.SetDegree(3);
							normalFace.SpecifyAll();
							if ( switchOrientation )
							{
								normalFace.SetNormalID(0, normalIndices[j - 1]);
								normalFace.SetNormalID(1, normalIndices[j - 2]);
								normalFace.SetNormalID(2, normalIndices[j]);
								switchOrientation = false;
							}
							else
							{
								normalFace.SetNormalID(0, normalIndices[j - 2]);
								normalFace.SetNormalID(1, normalIndices[j - 1]);
								normalFace.SetNormalID(2, normalIndices[j]);
								switchOrientation = true;
							}
							++faceIndex;
						}
						nextTristripStartIndex += faceVertexCount;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
				{
					const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();
					size_t nextTrifanStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						unsigned int commonVertexIndex = normalIndices[nextTrifanStartIndex];
						for ( size_t j = nextTrifanStartIndex + 2, lastVertex = nextTrifanStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							MNNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
							normalFace.SetDegree(3);
							normalFace.SpecifyAll();
							normalFace.SetNormalID(0, commonVertexIndex);
							normalFace.SetNormalID(1, normalIndices[j - 1]);
							normalFace.SetNormalID(2, normalIndices[j]);
							++faceIndex;
						}
						nextTrifanStartIndex += faceVertexCount;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::POLYGONS:
				{
					COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) meshPrimitive;

					COLLADAFW::IntValuesArray& faceVertexCountArray = polygons->getGroupedVerticesVertexCountArray();
					size_t currentIndex = 0;
					for ( size_t j = 0, count = faceVertexCountArray.getCount(); j < count; ++j)
					{
						int faceVertexCount = faceVertexCountArray[j];

						// TODO for now, we ignore holes in polygons
						if ( faceVertexCount <= 0 )
							continue;

						MNNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
						normalFace.SetDegree((int)faceVertexCount);
						normalFace.SpecifyAll();
						for ( int k = 0; k < faceVertexCount; ++k)
						{
							normalFace.SetNormalID(k, normalIndices[currentIndex + k]);
						}
						currentIndex += faceVertexCount;
						++faceIndex;
					}
				}
				break;
			default:
				continue;
			}

		}

		normalsSpecifier->CheckNormals();

		return true;
	}

	//------------------------------
	template<class NumberArray> 
	void GeometryImporter::setPolygonMeshUVVertices( const NumberArray& uvArray, MNMap* meshMap, size_t stride, size_t startPosition, size_t vertsCount )
	{
		size_t uvIndex = startPosition;

		switch ( stride )
		{
		case 1:
			{
				for ( size_t i = 0; i < vertsCount; ++i)
				{
					UVVert& textureVertex = meshMap->v[i];
					textureVertex.x = (float)uvArray[uvIndex++];
				}
				break;
			}
		case 2:
			{
				for ( size_t i = 0; i < vertsCount; ++i)
				{
					UVVert& textureVertex = meshMap->v[i];
					textureVertex.x = (float)uvArray[uvIndex++];
					textureVertex.y = (float)uvArray[uvIndex++];
				}
				break;
			}
		case 3:
			{
				for ( size_t i = 0; i < vertsCount; ++i)
				{
					UVVert& textureVertex = meshMap->v[i];
					float x = (float)uvArray[uvIndex++];
					float y = (float)uvArray[uvIndex++];
					float z = (float)uvArray[uvIndex++];
					textureVertex.Set(x, y, z);
				}
				break;
			}
		case 4:
			{
				for ( size_t i = 0; i < vertsCount; ++i)
				{
					UVVert& textureVertex = meshMap->v[i];
					float x = (float)uvArray[uvIndex++];
					float y = (float)uvArray[uvIndex++];
					float z = (float)uvArray[uvIndex++];
					textureVertex.Set(x, y, z);
					uvIndex++;
				}
				break;
			}
		default:
			assert(false);
		}

	}

	//------------------------------
	void GeometryImporter::setPolygonMeshUVVerticesPerPrimitiveAndChannel( const COLLADAFW::MeshPrimitive* meshPrimitive,
														 MNMap* meshMap,
														 const COLLADAFW::UIntValuesArray& uvIndices,
														 unsigned int initialIndex,
														 size_t& currentFaceIndex)
	{

		if ( skipMeshData( meshPrimitive, uvIndices, currentFaceIndex ) )
		{
			return;
		}

		int indices[3];
		switch (meshPrimitive->getPrimitiveType())
		{
		case COLLADAFW::MeshPrimitive::TRIANGLES:
			{
				for ( size_t j = 0, count = uvIndices.getCount() ; j < count; j+=3 )
				{
					MNMapFace* face = meshMap->F((int)currentFaceIndex);
					indices[0] = (int)(uvIndices[j] - initialIndex);
					indices[1] = (int)(uvIndices[j+1] - initialIndex);
					indices[2] = (int)(uvIndices[j+2] - initialIndex);
					face->MakePoly( 3, indices );
					++currentFaceIndex;
				}
				break;
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
			{
				const COLLADAFW::Tristrips* tristrips = (const COLLADAFW::Tristrips*) meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();
				size_t nextTristripStartIndex = 0;
				int indices[3];
				for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
				{
					unsigned int faceVertexCount = faceVertexCountArray[k];
					bool switchOrientation = false;
					for ( size_t j = nextTristripStartIndex + 2, lastVertex = nextTristripStartIndex +  faceVertexCount; j < lastVertex; ++j )
					{
						MNMapFace* face = meshMap->F((int)currentFaceIndex);
						if ( switchOrientation )
						{
							indices[0] = (int)(uvIndices[j - 1]  - initialIndex);
							indices[1] = (int)(uvIndices[j - 2] - initialIndex);
							indices[2] = (int)(uvIndices[j] - initialIndex);
							face->MakePoly( 3, indices );
							switchOrientation = false;
						}
						else
						{
							indices[0] = (int)(uvIndices[j - 2] - initialIndex);
							indices[1] = (int)(uvIndices[j - 1] - initialIndex);
							indices[2] = (int)(uvIndices[j] - initialIndex);
							face->MakePoly( 3, indices );
							switchOrientation = true;
						}
						++currentFaceIndex;
					}
					nextTristripStartIndex += faceVertexCount;
				}
				break;
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
			{
				const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*) meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();
				size_t nextTrifanStartIndex = 0;
				int indices[3];
				for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
				{
					unsigned int faceVertexCount = faceVertexCountArray[k];
					unsigned int commonVertexIndex = uvIndices[nextTrifanStartIndex] - initialIndex;
					indices[0] = (int)(commonVertexIndex);
					for ( size_t j = nextTrifanStartIndex + 2, lastVertex = nextTrifanStartIndex +  faceVertexCount; j < lastVertex; ++j )
					{
						MNMapFace* face = meshMap->F((int)currentFaceIndex);
						indices[1] = (int)(uvIndices[j - 1] - initialIndex);
						indices[2] = (int)(uvIndices[j] - initialIndex);
						face->MakePoly( 3, indices );
						++currentFaceIndex;
					}
					nextTrifanStartIndex += faceVertexCount;
				}
				break;
			}
		case COLLADAFW::MeshPrimitive::POLYGONS:
			{
				const COLLADAFW::Polygons* polygons = (const COLLADAFW::Polygons*) meshPrimitive;
				const COLLADAFW::IntValuesArray& faceVertexCountArray = polygons->getGroupedVerticesVertexCountArray();
				size_t currentIndex = 0;
				for ( size_t j = 0, count = faceVertexCountArray.getCount() ; j < count; ++j )
				{
					int faceVertexCount = faceVertexCountArray[j];
					// TODO for now, we ignore holes in polygons
					if ( faceVertexCount <= 0 )
						continue;
					MNMapFace* face = meshMap->F((int)currentFaceIndex);
					int* indices = new int[faceVertexCount];
					for ( int j = 0; j < faceVertexCount; ++j)
					{
						indices[j] = uvIndices[ currentIndex + j ] - initialIndex;
					}

					face->MakePoly(faceVertexCount, indices);
					currentIndex += faceVertexCount;
					++currentFaceIndex;
					delete[] indices;
				}
				break;
			}
		default:
			return;
		}
	}

	//------------------------------
	size_t getPolygonMeshPrimitiveFaceCount( const COLLADAFW::MeshPrimitive* meshPrimitive)
	{

		switch (meshPrimitive->getPrimitiveType())
		{
		case COLLADAFW::MeshPrimitive::TRIANGLES:
		case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
		case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
				return getTriangleMeshPrimitiveTriangleCount( meshPrimitive );
		case COLLADAFW::MeshPrimitive::POLYGONS:
			{
				const COLLADAFW::Polygons* polygons = (const COLLADAFW::Polygons*) meshPrimitive;
				const COLLADAFW::IntValuesArray& faceVertexCountArray = polygons->getGroupedVerticesVertexCountArray();
				size_t faceCount = 0;
				for ( size_t j = 0, count = faceVertexCountArray.getCount() ; j < count; ++j )
				{
					int faceVertexCount = faceVertexCountArray[j];
					// TODO for now, we ignore holes in polygons
					if ( faceVertexCount > 0 )
					{
						faceCount++;
					}
				}
				return faceCount;
			}
		default:
			return 0;
		}
	}


	//------------------------------
	void GeometryImporter::fillPolygonMeshMapPerSet( const COLLADAFW::MeshVertexData& uvCoordinates,
		                                        const COLLADAFW::MeshVertexData::InputInfosArray& inputInfos,
		                                        size_t sourceIndex,
			                                    MNMap* meshMap)
	{
		const COLLADAFW::MeshVertexData::InputInfos* inputInfo = inputInfos[ sourceIndex ];

		size_t stride = inputInfo->mStride;
		size_t vertsCount = inputInfo->mLength / stride;

		// calculate first index position
		size_t startPosition = 0;
		for ( size_t i = 0; i < sourceIndex; ++i)
		{
			const COLLADAFW::MeshVertexData::InputInfos* inputInfo = inputInfos[ i ];
			startPosition += inputInfo->mLength;
		}

		meshMap->setNumVerts((int)vertsCount);


		if ( uvCoordinates.getType() == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray& uvArray = *uvCoordinates.getDoubleValues();
			setPolygonMeshUVVertices(uvArray, meshMap, stride, startPosition, vertsCount);
		}
		else
		{
			const COLLADAFW::FloatArray& uvArray = *uvCoordinates.getFloatValues();
			setPolygonMeshUVVertices(uvArray, meshMap, stride, startPosition, vertsCount);
		}

	}


	//------------------------------
	bool GeometryImporter::importPolygonMeshUVCoords( PolyObject* polygonObject )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		createSetSourcePairMapChannelMap();

		MNMesh& polygonMesh = polygonObject->GetMesh();

		polygonMesh.SetMapNum( mLargestMapChannel + 1 );

		int facesCount = polygonMesh.FNum();;

		// reset all texture indices of all used maps
		for ( int i = 0; i <= mLargestMapChannel; ++i )
		{
			// enable / initialize the Map
			polygonMesh.InitMap(i);
//			MNMap& meshMap = polygonMesh.M(i);
//			meshMap.setNumFaces( facesCount );
//			memset( meshMap.tf, 0, sizeof(TVFace) * facesCount);
		}

		const COLLADAFW::MeshVertexData& uvCoordinates = mesh->getUVCoords();
		const COLLADAFW::MeshVertexData& vertexColors = mesh->getColors();
		const COLLADAFW::MeshVertexData::InputInfosArray& uvInputInfos = uvCoordinates.getInputInfosArray();
		const COLLADAFW::MeshVertexData::InputInfosArray& vertexColorInputInfos = vertexColors.getInputInfosArray();


		SetSourcePairMapChannelMap::const_iterator it = mSetSourcePairMapChannelMap.begin();
		bool hasColorChannel = false;
		for ( ; it != mSetSourcePairMapChannelMap.end(); ++it )
		{
			const SetSourcePair& setSourcePair = it->first;
			const size_t& sourceIndex = setSourcePair.second;
			// check that the channel is a texture channel and not a color channel
			long setIndex = setSourcePair.first;
			int mapChannel = it->second;
			MNMap* meshMap = polygonMesh.M(mapChannel);

			assert( (mapChannel != 0) || ( setIndex < 0) );
			if ( setIndex >= 0 )
			{
				fillPolygonMeshMapPerSet( uvCoordinates, uvInputInfos, sourceIndex, meshMap);
			}
			else if ( !hasColorChannel )
			{
				fillPolygonMeshMapPerSet( vertexColors, vertexColorInputInfos, sourceIndex, meshMap);
				hasColorChannel = true;
			}

		}


		COLLADAFW::MeshPrimitiveArray& meshPrimitiveArray =  mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		for ( size_t i = 0, count = meshPrimitiveArray.getCount(); i < count; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitiveArray[i];
			if ( ! meshPrimitive )
				continue;

			if (isSupportedMeshPrimitive(meshPrimitive))
			{
				size_t currentFaceIndex = faceIndex;

				const COLLADAFW::IndexListArray& uvIndexArray = meshPrimitive->getUVCoordIndicesArray();
				for ( size_t j = 0, count = uvIndexArray.getCount(); j < count; ++j)
				{
					const COLLADAFW::IndexList& uvIndexList = *uvIndexArray[j];
					size_t sourceIndex = mUVInitialIndexSourceIndexMap[uvIndexList.getInitialIndex()];
					size_t setIndex = uvIndexList.getSetIndex();
					SetSourcePair setSourcePair( (long)setIndex, sourceIndex);
					int mapChannel = mSetSourcePairMapChannelMap[ setSourcePair ];

					unsigned int initialIndex = (unsigned int)uvIndexList.getInitialIndex();

					const COLLADAFW::UIntValuesArray& uvIndices =  uvIndexList.getIndices();

					MNMap* meshMap = polygonMesh.M(mapChannel);

					currentFaceIndex = faceIndex;

					setPolygonMeshUVVerticesPerPrimitiveAndChannel( meshPrimitive, meshMap, uvIndices, initialIndex, currentFaceIndex);


				}

				// vertex color color
				const COLLADAFW::IndexListArray& colorIndexArray = meshPrimitive->getColorIndicesArray();
				for ( size_t j = 0, count = colorIndexArray.getCount(); j < count; ++j)
				{
					const COLLADAFW::IndexList& colorIndexList = *colorIndexArray[j];
					size_t sourceIndex = mColorInitialIndexSourceIndexMap[colorIndexList.getInitialIndex()];
					size_t setIndex = colorIndexList.getSetIndex();
					SetSourcePair setSourcePair( -(long)(setIndex + 1), sourceIndex);
					int mapChannel = mSetSourcePairMapChannelMap[ setSourcePair ];
					if ( mapChannel != 0)
						continue;

					unsigned int initialIndex = (unsigned int)colorIndexList.getInitialIndex();

					const COLLADAFW::UIntValuesArray& colorIndices =  colorIndexList.getIndices();

					MNMap* meshMap = polygonMesh.M(mapChannel);

					currentFaceIndex = faceIndex;

					setPolygonMeshUVVerticesPerPrimitiveAndChannel( meshPrimitive, meshMap, colorIndices, initialIndex, currentFaceIndex);
					polygonMesh.SetDisplayVertexColors(0);
					mHasVertexColor = true;
				}

				if ( faceIndex == currentFaceIndex )
				{
					// setTriangleMeshUVVerticesPerPrimitiveAndChannel was never called. we need to count triangle here
					faceIndex += getPolygonMeshPrimitiveFaceCount(meshPrimitive);
				}
				else
				{ 
					// currentFaceIndex was properly set by the last setTriangleMeshUVVerticesPerPrimitiveAndChannel call
					faceIndex = currentFaceIndex;
				}
			}
		}
		return true;
	}


	//------------------------------
	void GeometryImporter::createFWMaterialIdMaxMtlIdMap( const COLLADAFW::MeshPrimitiveArray& primitiveArray, DocumentImporter::FWMaterialIdMaxMtlIdMap& materialMap )
	{
		MtlID nextMaxMaterialId = 1;
		for ( size_t i = 0, count = primitiveArray.getCount(); i < count; ++i )
		{
			const COLLADAFW::MeshPrimitive* primitive = primitiveArray[i];

			if (isSupportedMeshPrimitive(primitive))
			{
				COLLADAFW::MaterialId fWMaterialId = primitive->getMaterialId();
				if ( materialMap.count(fWMaterialId) == 0 )
				{
					materialMap[fWMaterialId] = nextMaxMaterialId++;
				}
			}
		}
	}

	//------------------------------
	void GeometryImporter::createSetSourcePairMapChannelMap()
	{
		if ( mGeometry->getType() != COLLADAFW::Geometry::GEO_TYPE_MESH )
			return;

		bool usedMapChannels[MAX_MESHMAPS + NUM_HIDDENMAPS];
		memset(usedMapChannels, false, sizeof(bool) * (MAX_MESHMAPS + NUM_HIDDENMAPS));

		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		const COLLADAFW::MeshVertexData& colors = mesh->getColors();
		const COLLADAFW::MeshVertexData::InputInfosArray& colorInputInfos = colors.getInputInfosArray();
		size_t colorInitialIndex = 0;
		for ( size_t i = 0, count = colorInputInfos.getCount(); i < count; ++i)
		{
			const COLLADAFW::MeshVertexData::InputInfos* inputInfo = colorInputInfos[i];
			size_t& sourceIndex = i;
			mColorInitialIndexSourceIndexMap.insert(std::make_pair(colorInitialIndex, sourceIndex));
			mColorSourceIndexInitialIndexMap.insert(std::make_pair(sourceIndex, colorInitialIndex));
			colorInitialIndex += (inputInfo->mLength / inputInfo->mStride);
		}

		const COLLADAFW::MeshVertexData& uvCoords = mesh->getUVCoords();
		const COLLADAFW::MeshVertexData::InputInfosArray& uVInputInfos = uvCoords.getInputInfosArray();
		size_t uVInitialIndex = 0;
		for ( size_t i = 0, count = uVInputInfos.getCount(); i < count; ++i)
		{
			size_t& sourceIndex = i;
			const COLLADAFW::MeshVertexData::InputInfos* inputInfo = uVInputInfos[sourceIndex];
			mUVInitialIndexSourceIndexMap.insert(std::make_pair(uVInitialIndex, sourceIndex));
			mUVSourceIndexInitialIndexMap.insert(std::make_pair(sourceIndex, uVInitialIndex));
			uVInitialIndex += (inputInfo->mLength / inputInfo->mStride);
		}


		const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mesh->getMeshPrimitives();

		// first try
		for ( size_t i = 0, count = meshPrimitives.getCount(); i < count; ++i )
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives[i];

			if (isSupportedMeshPrimitive(meshPrimitive))
			{
				const COLLADAFW::IndexListArray& uvIndices = meshPrimitive->getUVCoordIndicesArray();
				const COLLADAFW::IndexListArray& colorIndices = meshPrimitive->getColorIndicesArray();

				assignMapChannels<true, true>( colorIndices, mColorInitialIndexSourceIndexMap, usedMapChannels);
				assignMapChannels<false, true>( uvIndices, mUVInitialIndexSourceIndexMap, usedMapChannels);
			}
		}

		// second try
		for ( size_t i = 0, count = meshPrimitives.getCount(); i < count; ++i )
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives[i];
			if (isSupportedMeshPrimitive(meshPrimitive))
			{
				const COLLADAFW::IndexListArray& uvIndices = meshPrimitive->getUVCoordIndicesArray();
				const COLLADAFW::IndexListArray& colorIndices = meshPrimitive->getColorIndicesArray();

				if ( !assignMapChannels<true, false>( colorIndices, mColorInitialIndexSourceIndexMap, usedMapChannels) )
				{
					break;
				}
				if ( !assignMapChannels<false, false>( uvIndices, mUVInitialIndexSourceIndexMap, usedMapChannels) )
				{
					break;
				}
			}
		}

		// fill the setMapChannelMap for this geometry
		DocumentImporter::SetMapChannelMap& setMapChannelMap = getSetMapChannelByGeometryUniqueId( mGeometry->getUniqueId() );
		SetSourcePairMapChannelMap::const_iterator it = mSetSourcePairMapChannelMap.begin();
		for ( ; it != mSetSourcePairMapChannelMap.end(); ++it )
		{
			const SetSourcePair& setSourcePair = it->first;
			long setIndex = setSourcePair.first;
			if ( setIndex >= 0)
			{
				setMapChannelMap[setIndex] = it->second;
			}
		}
	}

	template<bool isColorChannel, bool isFirstTry>
	bool GeometryImporter::assignMapChannels( const COLLADAFW::IndexListArray& indices, 
		                                      const InitialIndexSourceIndexMap& initialIndexSourceIndexMap,
											  bool usedMapChannels[MAX_MESHMAPS + NUM_HIDDENMAPS])
	{
		for ( size_t j = 0, count = indices.getCount(); j < count; ++j)
		{
			const COLLADAFW::IndexList* indexList = indices[j];
			size_t setIndex = indexList->getSetIndex();
			size_t initialIndex = indexList->getInitialIndex();
			InitialIndexSourceIndexMap::const_iterator sourecIndexIt = initialIndexSourceIndexMap.find(initialIndex);
			assert(sourecIndexIt != initialIndexSourceIndexMap.end());
			size_t sourceIndex = sourecIndexIt->second;
			SetSourcePair setSourcePair( isColorChannel ? -(long)(setIndex+1) : (long)setIndex, sourceIndex);
			SetSourcePairMapChannelMap::const_iterator it = mSetSourcePairMapChannelMap.find( setSourcePair );

			// check if we have already assigned a map channel to this color set/ source combination
			if ( it != mSetSourcePairMapChannelMap.end() )
				continue; 

			// assign a map channel
			int favoredMapChannel = isColorChannel ? ((setIndex == 1) ? 0 : (int)setIndex) : ((setIndex == 0) ? 1 : (int)setIndex);

			if ( isFirstTry )
			{
				if ( favoredMapChannel <= MAX_MESHMAPS)
				{
					if ( !usedMapChannels[favoredMapChannel + NUM_HIDDENMAPS]) 
					{
						mSetSourcePairMapChannelMap.insert( std::make_pair(setSourcePair, favoredMapChannel));
						
						if ( favoredMapChannel > mLargestMapChannel )
							mLargestMapChannel = favoredMapChannel;
						
						usedMapChannels[favoredMapChannel + NUM_HIDDENMAPS] = true;
					}
				}
			}
			else
			{
				// assign a map channel
				int mapChannelIndex = 1;

				// Use the next unused map channel
				while ( true )
				{
					if ( mapChannelIndex > MAX_MESHMAPS)
						return false;

					if ( !usedMapChannels[mapChannelIndex + NUM_HIDDENMAPS] )
					{
						mSetSourcePairMapChannelMap.insert( std::make_pair(setSourcePair, mapChannelIndex));

						if ( mapChannelIndex > mLargestMapChannel )
							mLargestMapChannel = mapChannelIndex;

						usedMapChannels[mapChannelIndex + NUM_HIDDENMAPS] = true;
						break;
					}

					++mapChannelIndex;
				}
			}
		}
		return true;
	}

	bool GeometryImporter::skipMeshData( const COLLADAFW::MeshPrimitive* meshPrimitive,
										 const COLLADAFW::UIntValuesArray& dataIndices,
										 size_t& faceIndex)
	{
		const COLLADAFW::UIntValuesArray& positionIndices = meshPrimitive->getPositionIndices();

		size_t positionIndicesCount = positionIndices.getCount();

		if ( dataIndices.getCount() != positionIndicesCount )
		{
			switch (meshPrimitive->getPrimitiveType())
			{
			case COLLADAFW::MeshPrimitive::TRIANGLES:
				{
					faceIndex += positionIndicesCount/3;
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
			case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
				{
					faceIndex += (positionIndicesCount > 2) ? (positionIndicesCount - 2) : 0;
					break;
				}
			}
			// todo handle error
			return true;
		}
		else
		{
			return false;
		}
	}


} // namespace COLLADAMax
