/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MESHWRITER_H__
#define __DAE23DS_MESHWRITER_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsMeshBase.h"

#include "DAE23dsChunkIDs.h"

namespace Common
{
	class Buffer;
}

namespace DAE23ds
{
	class Writer;

	class MeshWriter : public MeshBase
	{
	private:

		const COLLADAFW::Mesh* mMesh;

		Common::Buffer& mBuffer;

		// material ids of the triangles in the last block written
		COLLADAFW::MaterialId mMaterialIds[MAX_TRIANGLES_PER_BLOCK];

		MeshAccessor mMeshAccessor;

		const COLLADAFW::MeshVertexData& mMeshPositions;
		const COLLADAFW::MeshVertexData& mMeshNormals;
		const COLLADAFW::MeshVertexData& mMeshUVCoordinates;
		const COLLADAFW::MeshVertexData& mMeshColors;


	public:

        /** Constructor. */
		MeshWriter(Writer* writer3ds, const COLLADAFW::Mesh* mesh );

        /** Destructor. */
		virtual ~MeshWriter();

		/** Writes the mesh using @a materialBindings to assign materials.*/
		bool writeMeshIntoOneObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoOneObject& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance);

		/** Writes the mesh using @a materialBindings to assign materials.*/
		bool writeMeshIntoMultipleObjects( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoMultipleObjectsData& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance);

		/** Writes the mesh using @a materialBindings to assign materials.*/
		bool writeMeshIntoObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo);

		/** Writes the mesh using @a materialBindings to assign materials and data provided in @a blockData.*/
		bool writeMeshIntoObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const ObjectBlockData& blockData);

		/** Writes the vertices/position as floats into @a buffer.*/
		bool writeVertices(const COLLADABU::Math::Matrix4& worldMatrix);

		/** Writes the positions for @a trianglesCount triangles, starting at @a firstTriangleIndex.*/
		bool writeVerticesForMultipleObjects(size_t firstTriangleIndex, CountType trianglesCount, const COLLADABU::Math::Matrix4& worldMatrix);

		/** Writes all the triangles/fans/strips into @a buffer.*/
		bool writeTriangles();


		/** Writes the numbers 0...@a trianglesCount into @a buffer.*/
		bool writeTrianglesForMultipleObjects(CountType trianglesCount);

		/** writes the faces materials.*/
		bool writeFaceMaterials(const COLLADAFW::MaterialBindingArray& materialBindings);

		/** */
		bool writeFaceMaterialsForMultipleObjects(const COLLADAFW::MaterialBindingArray& materialBindings, const ObjectBlockData& blockData);

		/** Writes the mesh matrix of the tri object.*/
		bool writeMeshMatrix(const COLLADABU::Math::Matrix4& worldMatrix);

		/** Calculates the number of triangles in the @a  meshPrimitiveIndex'th meshPrimitive.*/
		IndexType calculateMeshPrimitivesTriangleCount(size_t meshPrimitiveIndex);

	private:

        /** Disable default copy ctor. */
		MeshWriter( const MeshWriter& pre );

        /** Disable default assignment operator. */
		const MeshWriter& operator= ( const MeshWriter& pre );

		bool splitMeshInChunks();
		
		template<class T> 
		void transformAndWriteVertex( const T& vertex, float wm[3][4], size_t index);
		
		template<class T> 
		void transformAndWriteVertex( const T& vertex, const COLLADABU::Math::Matrix4& worldMatrix, size_t index);
	};

} // namespace DAE23ds

#endif // __DAE23DS_MESHWRITER_H__
