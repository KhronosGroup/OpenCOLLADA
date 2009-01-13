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
#include "COLLADAFWPolygons.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAMax
{

	GeometryImporter::GeometryImporter( DocumentImporter* documentImporter, const COLLADAFW::Geometry* geometry )
		:	ImporterBase(documentImporter),
		mGeometry(geometry)
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
    	if ( mesh->getPolygonsCount() > 0 )
		{
			importPolygonMesh();
		}
		else if ( mesh->getTrianglesCount() > 0 )
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

		size_t trianglesCount = mesh->getTrianglesCount();
		triangleMesh.setNumFaces((int)trianglesCount);
		COLLADAFW::MeshPrimitiveArray& meshPrimitiveArray =  mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		for ( size_t i = 0, count = meshPrimitiveArray.getCount(); i < count; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitiveArray[i];
			if ( ! meshPrimitive )
				continue;
			// TODO: support fans and strips
			// for now, we support only triangles
			if ( meshPrimitive->getPrimitiveType() != COLLADAFW::MeshPrimitive::TRIANGLES )
				continue;

			const COLLADAFW::Triangles* triangles = (const COLLADAFW::Triangles*) meshPrimitive;
			assert(triangles);
			const COLLADAFW::UIntValuesArray& positionIndices =  triangles->getPositionIndices();
			for ( size_t j = 0, count = positionIndices.getCount() ; j < count; j+=3 )
			{
				Face& face = triangleMesh.faces[faceIndex];
				face.setVerts(positionIndices[j], positionIndices[j + 1], positionIndices[j + 2]);
				++faceIndex;
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
			for ( size_t j = 0; j < trianglesCount; ++j)
			{
				const COLLADAFW::UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices();
				MeshNormalFace& normalFace = normalsSpecifier->Face((int) faceIndex);
				normalFace.SpecifyAll();
				normalFace.SetNormalID(0, normalIndices[3*j]);
				normalFace.SetNormalID(1, normalIndices[3*j + 1]);
				normalFace.SetNormalID(2, normalIndices[3*j + 2]);
				++faceIndex;
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

		polygonMesh.InvalidateGeomCache();

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

		size_t polygonsCount = mesh->getPolygonsCount() + mesh->getTrianglesCount();
		polgonMesh.setNumFaces((int)polygonsCount);
		COLLADAFW::MeshPrimitiveArray& meshPrimitiveArray =  mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		for ( size_t i = 0, count = meshPrimitiveArray.getCount(); i < count; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitiveArray[i];
			if ( ! meshPrimitive )
				continue;
			// TODO support fans strips 
			// for now, we support only triangles
			switch ( meshPrimitive->getPrimitiveType() )
			{
			case COLLADAFW::MeshPrimitive::TRIANGLES:
				{
					const COLLADAFW::Triangles* triangles = (const COLLADAFW::Triangles*) meshPrimitive;
					assert(triangles);
					const COLLADAFW::UIntValuesArray& positionIndices =  triangles->getPositionIndices();
					for ( size_t j = 0, count = positionIndices.getCount() ; j < count; j+=3 )
					{
						MNFace* face = polgonMesh.F((int)faceIndex);
						face->MakePoly(3, (int*) (&positionIndices[j]));

						++faceIndex;
					}
					break;
				}
			case COLLADAFW::MeshPrimitive::POLYGONS:
				{
					const COLLADAFW::Polygons* polygons = (const COLLADAFW::Polygons*) meshPrimitive;
					assert(polygons);
					const COLLADAFW::UIntValuesArray& positionIndices =  polygons->getPositionIndices();
					const COLLADAFW::IntValuesArray& faceVertexCountArray = polygons->getFaceVertexCountArray();
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
			if ( meshPrimitive->getPrimitiveType() == COLLADAFW::MeshPrimitive::TRIANGLES )
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
			else if ( meshPrimitive->getPrimitiveType() == COLLADAFW::MeshPrimitive::POLYGONS )
			{
				COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) meshPrimitive;

				COLLADAFW::IntValuesArray& faceVertexCountArray = polygons->getFaceVertexCountArray();
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
