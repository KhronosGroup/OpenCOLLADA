/*
Copyright (c) 2008 NetAllied Systems GmbH

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

	GeometryImporter::GeometryImporter( DocumentImporter* documentImporter, const COLLADAFW::Geometry* geometry )
		:	ImporterBase(documentImporter)
		, mGeometry(geometry)
		, mTotalTrianglesCount(0)

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

		triangleMesh.InvalidateGeomCache();
		triangleMesh.InvalidateTopologyCache();

		handleReferences(mesh, triangleObject);

		return true;
	}


	//------------------------------
	bool GeometryImporter::importTriangleMeshPositions( TriObject* triangleObject )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		Mesh& triangleMesh = triangleObject->GetMesh();

		const COLLADAFW::MeshPositions& meshPositions = mesh->getPositions();

		int positionsCount = (int)meshPositions.getPositionsCount() / 3;

		triangleMesh.setNumVerts(positionsCount);

		if ( meshPositions.getType() == COLLADAFW::MeshPositions::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray* positionsArray = meshPositions.getDoublePositions();
			for ( int i = 0; i < positionsCount; ++i)
			{
				triangleMesh.setVert(i, (float)(*positionsArray)[3*i], (float)(*positionsArray)[3*i + 1], (float)(*positionsArray)[3*i + 2]);
			}
		}
		else
		{
			const COLLADAFW::FloatArray* positionsArray = meshPositions.getFloatPositions();
			for ( int i = 0; i < positionsCount; i+=3)
			{
				triangleMesh.setVert(i, (*positionsArray)[i], (*positionsArray)[i + 1], (*positionsArray)[i + 2]);
			}
		}

		triangleMesh.setNumFaces((int)mTotalTrianglesCount);
		COLLADAFW::MeshPrimitiveArray& meshPrimitiveArray =  mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		for ( size_t i = 0, count = meshPrimitiveArray.getCount(); i < count; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitiveArray[i];
			if ( ! meshPrimitive )
				continue;
			switch (meshPrimitive->getPrimitiveType())
			{
			case COLLADAFW::MeshPrimitive::TRIANGLES:
				{
					const COLLADAFW::Triangles* triangles = (const COLLADAFW::Triangles*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& positionIndices =  triangles->getPositionIndices();
					for ( size_t j = 0, count = positionIndices.getCount() ; j < count; j+=3 )
					{
						Face& face = triangleMesh.faces[faceIndex];
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
						for ( size_t j = nextTristripStartIndex + 2, lastVertex = nextTristripStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							Face& face = triangleMesh.faces[faceIndex];
							face.setEdgeVisFlags(1, 1, 1);
							face.setVerts(positionIndices[j - 2], positionIndices[j - 1], positionIndices[j]);
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
		const COLLADAFW::MeshNormals& meshNormals = mesh->getNormals();
		int normalCount = (int)meshNormals.getNormalsCount()/3;

		normalsSpecifier->SetNumNormals(normalCount);

		if ( meshNormals.getType() == COLLADAFW::MeshNormals::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray* normalsArray = meshNormals.getDoubleNormals();
			for ( int i = 0; i < normalCount; ++i)
			{
				Point3 normal((*normalsArray)[i*3], (*normalsArray)[i*3 + 1], (*normalsArray)[i*3 + 2]);
				normalsSpecifier->Normal(i) = normal.Normalize();
				normalsSpecifier->SetNormalExplicit(i, true);
			}
		}
		else
		{
			const COLLADAFW::FloatArray* normalsArray = meshNormals.getFloatNormals();
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
					const COLLADAFW::UIntValuesArray& normalIndices =  tristrips->getNormalIndices();
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();
					size_t nextTristripStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						for ( size_t j = nextTristripStartIndex + 2, lastVertex = nextTristripStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							MeshNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
							normalFace.SpecifyAll();
							normalFace.SetNormalID(0, normalIndices[j - 2]);
							normalFace.SetNormalID(1, normalIndices[j - 1]);
							normalFace.SetNormalID(2, normalIndices[j]);
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
					const COLLADAFW::UIntValuesArray& normalIndices =  trifans->getNormalIndices();
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

		normalsSpecifier->CheckNormals();

		return true;
	}

	//------------------------------
	bool GeometryImporter::importTriangleMeshUVCoords( TriObject* triangleObject )
	{

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

		//polygonMesh.InvalidateGeomCache();

		handleReferences(mesh, polygonObject);

		return true;
	}

	//------------------------------
	bool GeometryImporter::importPolygonMeshPositions( PolyObject* polygonObject )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		MNMesh& polgonMesh = polygonObject->GetMesh();

		const COLLADAFW::MeshPositions& meshPositions = mesh->getPositions();

		int positionsCount = (int)meshPositions.getPositionsCount() / 3;

		polgonMesh.setNumVerts(positionsCount);

		if ( meshPositions.getType() == COLLADAFW::MeshPositions::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray* positionsArray = meshPositions.getDoublePositions();
			for ( int i = 0; i < positionsCount; ++i)
			{
				MNVert* vertex = polgonMesh.V(i);
				vertex->p = Point3( (float)(*positionsArray)[3*i], (float)(*positionsArray)[3*i + 1], (float)(*positionsArray)[3*i + 2]);
			}
		}
		else
		{
			const COLLADAFW::FloatArray* positionsArray = meshPositions.getFloatPositions();
			for ( int i = 0; i < positionsCount; i+=3)
			{
				MNVert* vertex = polgonMesh.V(i);
				vertex->p = Point3((*positionsArray)[i], (*positionsArray)[i + 1], (*positionsArray)[i + 2]);
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
						for ( size_t j = nextTristripStartIndex + 2, lastVertex = nextTristripStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							MNFace* face = polgonMesh.F((int)faceIndex);
							face->MakePoly(3, (int*) (&positionIndices[j - 2]));

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
		const COLLADAFW::MeshNormals& meshNormals = mesh->getNormals();
		int normalCount = (int)meshNormals.getNormalsCount()/3;

		normalsSpecifier->SetNumNormals(normalCount);

		if ( meshNormals.getType() == COLLADAFW::MeshNormals::DATA_TYPE_DOUBLE )
		{
			const COLLADAFW::DoubleArray* normalsArray = meshNormals.getDoubleNormals();
			for ( int i = 0; i < normalCount; ++i)
			{
				Point3 normal((*normalsArray)[i*3], (*normalsArray)[i*3 + 1], (*normalsArray)[i*3 + 2]);
				normalsSpecifier->Normal(i) = normal.Normalize();
				normalsSpecifier->SetNormalExplicit(i, true);
			}
		}
		else
		{
			const COLLADAFW::FloatArray* normalsArray = meshNormals.getFloatNormals();
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
			switch ( meshPrimitive->getPrimitiveType() )
			{
			case COLLADAFW::MeshPrimitive::TRIANGLES:
				{
					size_t faceCount = meshPrimitive->getFaceCount();
					for ( size_t j = 0; j < faceCount; ++j)
					{
						const COLLADAFW::UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices();
						MNNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
						normalFace.SpecifyAll();
						normalFace.SetDegree(3);
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
					const COLLADAFW::UIntValuesArray& normalIndices =  tristrips->getNormalIndices();
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();
					size_t nextTristripStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						for ( size_t j = nextTristripStartIndex + 2, lastVertex = nextTristripStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							MNNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
							normalFace.SpecifyAll();
							normalFace.SetDegree(3);
							normalFace.SetNormalID(0, normalIndices[j - 2]);
							normalFace.SetNormalID(1, normalIndices[j - 1]);
							normalFace.SetNormalID(2, normalIndices[j]);
							++faceIndex;
						}
						nextTristripStartIndex += faceVertexCount;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
				{
					const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*) meshPrimitive;
					const COLLADAFW::UIntValuesArray& normalIndices =  trifans->getNormalIndices();
					const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();
					size_t nextTrifanStartIndex = 0;
					for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
					{
						unsigned int faceVertexCount = faceVertexCountArray[k];
						unsigned int commonVertexIndex = normalIndices[nextTrifanStartIndex];
						for ( size_t j = nextTrifanStartIndex + 2, lastVertex = nextTrifanStartIndex +  faceVertexCount; j < lastVertex; ++j )
						{
							MNNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
							normalFace.SpecifyAll();
							normalFace.SetDegree(3);
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
					for ( size_t j = 0, count = faceVertexCountArray.getCount(); j < count; ++j)
					{
						int faceVertexCount = faceVertexCountArray[j];

						// TODO for now, we ignore holes in polygons
						if ( faceVertexCount <= 0 )
							continue;

						const COLLADAFW::UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices();
						MNNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
						normalFace.SpecifyAll();

						normalFace.SetDegree((int)faceVertexCount);
						for ( int k = 0; k < faceVertexCount; ++k)
						{
							normalFace.SetNormalID(k, normalIndices[3*j + k]);
						}
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
	bool GeometryImporter::importPolygonMeshUVCoords( PolyObject* polygonObject )
	{
		return true;
	}

	//------------------------------
	bool GeometryImporter::handleReferences( COLLADAFW::Geometry* geometry, Object* object )
	{
		const COLLADAFW::UniqueId& uniqueID = geometry->getUniqueId();

		addUniqueIdObjectPair(uniqueID, object);

		INodeList objectNodeList;
		getObjectINodesByUniqueId(uniqueID, objectNodeList);
		for ( size_t i = 0, count = objectNodeList.size(); i<count; ++i)
			objectNodeList[i]->SetObjectRef(object);
		
		return true;
	}

} // namespace COLLADAMax
