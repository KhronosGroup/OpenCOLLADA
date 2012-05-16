/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MESHBASE_H__
#define __DAE23DS_MESHBASE_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsBaseWriter.h"

#include "DAE23dsMeshAccessor.h"



namespace DAE23ds
{

	class MeshBase : public BaseWriter
	{
	protected:
		/** Used */
		struct ObjectBlockData
		{
			//			ChunkLength verticesCount;	
			CountType trianglesCount;
			size_t firstTriangleIndex;
		};

		struct WriteMeshIntoMultipleObjectsData
		{
			ChunkLength editObjectLength;
			ChunkLength fullBlocksCount;
			ChunkLength remainingTriangles;
		};


		struct WriteMeshIntoOneObject
		{
			ChunkLength editObjectLength;
			ChunkLength triangularMeshLength;
			ChunkLength verticesLength;
			ChunkLength facesDescriptionLength;
			CountType trianglesCount;
		};

	private:
		Writer::MeshData mMeshData;

		/** Set of GeometryMaterialBinding that have been handled already. Is used to avoid multiple export of identical meshes.*/
		Writer::GeometryMaterialBindingSet mGeometryMaterialBindingSet;

	public:

		/** Constructor. */
		MeshBase(Writer* writer3ds, const Writer::MeshData& meshData);

		/** Constructor. */
		MeshBase(Writer* writer3ds);

		/** Destructor. */
		virtual ~MeshBase();

		/** handles the mesh.*/
		bool handle();

		static void calculateBlockCountAndRemainingTriangles( size_t trianglesCount, ChunkLength& remainingTriangles, ChunkLength& blockCount, ChunkLength& fullBlockCount);
	
	private:

		/** Disable default copy ctor. */
		MeshBase( const MeshBase& pre );

		/** Disable default assignment operator. */
		const MeshBase& operator= ( const MeshBase& pre );

		/** Writes the mesh using @a materialBindings to assign materials.*/
		bool handleMesh(const Writer::InstanceGeometryInfo& instanceGeometryInfo);

		/** Writes the mesh using @a materialBindings to assign materials.*/
		bool handleMeshIntoOneObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const COLLADAFW::InstanceGeometry* alreadyUsingInstance );

		/** Writes the mesh using @a materialBindings to assign materials.*/
		bool handleMeshIntoMultipleObjects( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const COLLADAFW::InstanceGeometry* alreadyUsingInstance);


		/** Writes the mesh using @a materialBindings to assign materials.*/
		virtual bool writeMeshIntoMultipleObjects( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoMultipleObjectsData& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance) = 0;

		/** Writes the mesh using @a materialBindings to assign materials.*/
		virtual bool writeMeshIntoOneObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoOneObject& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance) = 0;


	protected:
		void setMeshData(const Writer::MeshData& meshData) { mMeshData = meshData; }


		/** Calculates the length of the vertices of the current mesh.*/
		ChunkLength calculateVerticesLength();

		/** Calculates the length of the vertices for a mesh with  (verticesCount_times3 / 3) vertices.*/
		ChunkLength calculateVerticesLength(ChunkLength verticesCount_times3);

		/** Calculates the length of all the vertices of the current mesh, if written into multiple objects.*/
		ChunkLength calculateTotalVerticesLengthMultiObject(size_t trianglesCount, ChunkLength blockCount );

		/** Calculates the length of the object of the current mesh given the length of the triangular mesh.*/
		ChunkLength calculateObjectLength(ChunkLength triangularMeshLength);

		/** Calculates the length of all the object of the current mesh given the length of the triangular mesh.*/
		ChunkLength calculateTotalObjectLengthMultiObject(ChunkLength triangularMeshLength, ChunkLength blockCount);

		/** Calculates the number of triangles in the mesh.*/
		size_t calculateTrianglesCount();

		/** Calculates the length including null termination of all materials names.*/
//		ChunkLength calculateMaterialNamesLength( const COLLADAFW::MaterialBindingArray& materialBindings);

		/** Calculates the length of all material faces.*/
		ChunkLength calculateFacesMaterialsLength(CountType trianglesCount, const COLLADAFW::MaterialBindingArray& materialBindings);

		/** Calculates the length of the faces description, given the number of triangles.*/
		ChunkLength calculateFacesDescriptionLength(CountType trianglesCount, ChunkLength facesMaterialsLength);

		/** Calculates the length of the faces description, given the number of triangles and blocks. The calculated size is for all object blocks.*/
		ChunkLength calculateFacesDescriptionLengthMultiObject(size_t trianglesCount, ChunkLength blockCount, ChunkLength facesMaterialsLength, ChunkLength remainderFacesMaterialsLength, ChunkLength fullBlocksCount);

		bool splitMeshInChunks();
		
//		ChunkLength calculateMaterialNameLengthFromMaterialBinding( const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding);
		
//		const char* calculateMaterialNameFromMaterialBinding( const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding, ChunkLength& length);
		
		const char* calculateMeshNameWithBlockIndex( ChunkLength blockIndex, const String& meshName );

	};


} // namespace DAE23DS

#endif // __DAE23DS_MESHBASE_H__
