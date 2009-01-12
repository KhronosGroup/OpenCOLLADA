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
//#include "COLLADAFWMeshPositions.h"
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

		TriObject* triangleObject = CreateNewTriObject();

		Mesh& triangleMesh = triangleObject->GetMesh();

		
		if ( !importMeshPositions(triangleObject) )
			return false;

		if ( !importMeshNormals(triangleObject) )
			return false;

		triangleMesh.InvalidateGeomCache();

		const COLLADAFW::UniqueId& uniqueID = mesh->getUniqueId();

		addUniqueIdObjectPair(uniqueID, triangleObject);

		INodeList objectNodeList;
		getObjectINodesByUniqueId(uniqueID, objectNodeList);
		for ( size_t i = 0, count = objectNodeList.size(); i<count; ++i)
			objectNodeList[i]->SetObjectRef(triangleObject);

		return true;
	}

	//------------------------------
	bool GeometryImporter::importMeshPositions( TriObject* triangleObject )
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
		triangleMesh.setNumFaces(trianglesCount);
		COLLADAFW::MeshPrimitiveArray& meshPrimitiveArray =  mesh->getMeshPrimitives();
		size_t faceIndex = 0;
		for ( size_t i = 0, count = meshPrimitiveArray.getCount(); i < count; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitiveArray[i];
			if ( ! meshPrimitive )
				continue;
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
	bool GeometryImporter::importMeshNormals( TriObject* triangleObject )
	{
		COLLADAFW::Mesh* mesh = (COLLADAFW::Mesh*) mGeometry;

		if ( !mesh->hasNormals() )
			return true;

		Mesh& triangleMesh = triangleObject->GetMesh();
	
		triangleMesh.SpecifyNormals();
		MeshNormalSpec* normalsSpecifier = triangleMesh.GetSpecifiedNormals();

		normalsSpecifier->ClearNormals();
		size_t numFaces = triangleMesh.getNumFaces();
		normalsSpecifier->SetNumFaces(numFaces);

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
	bool GeometryImporter::importMeshUVCoords( TriObject* triangleObject )
	{

		return true;
	}

} // namespace COLLADAMax
