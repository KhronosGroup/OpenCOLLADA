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

#ifndef __COLLADAMAX_GEOMETRYIMPORTER_H__
#define __COLLADAMAX_GEOMETRYIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"
#include "COLLADAFWMeshPrimitive.h"

#include "COLLADAFWMeshVertexData.h"

class MNMap;

namespace COLLADAFW
{
	class Geometry;
	class Mesh;
};


namespace COLLADAMax
{

    /** Imports a geometry into the max scene.
	If the geometry is referenced by a node that has already been imported, the geometry
	is attached to that nodes, otherwise the geometry does not belong to a node.*/
	class GeometryImporter 	: public ImporterBase
	{
	private:

		/** Maps initial indices from index list of multiple texture or color inputs to the index of the source*/
		typedef std::map<size_t /* initial index*/, size_t /* Source index*/> InitialIndexSourceIndexMap;

		/** Maps index of the source to the initial indices from index list of multiple texture or color inputs*/
		typedef std::map<size_t /* Source index*/, size_t /* initial index*/> SourceIndexInitialIndexMap;

		/** set index -1 corresponds to color channel.*/
		typedef std::pair<long/*set index negative for color positive for uv*/,size_t /* initial index*/> SetSourcePair;
		typedef std::map<SetSourcePair, int /* max map channel*/> SetSourcePairMapChannelMap;

	private:
		/** The geometry that should be imported.*/
		const COLLADAFW::Geometry* mGeometry;

		/** The number of all triangles in all primitives that contain triangles (Triangles, 
		Tristrips, Trisfans).*/
		size_t mTotalTrianglesCount;

		/** Maps a set index, source ( data source in MeshVertexData) pair to the max map channel.*/
		SetSourcePairMapChannelMap mSetSourcePairMapChannelMap;

		/** Maps initial indices from index list of multiple texture inputs to the index of the source*/
		InitialIndexSourceIndexMap mUVInitialIndexSourceIndexMap;

		/** Maps index of the source to the initial indices from index list of multiple texture inputs*/
		SourceIndexInitialIndexMap mUVSourceIndexInitialIndexMap;

		/** Maps initial indices from index list of multiple color inputs to the index of the source*/
		InitialIndexSourceIndexMap mColorInitialIndexSourceIndexMap;

		/** Maps index of the source to the initial indices from index list of multiple color inputs*/
		SourceIndexInitialIndexMap mColorSourceIndexInitialIndexMap;

		/** The number of the largest map channel used.*/
		int mLargestMapChannel;

		/** True, if the geometry has per vertex color.*/
		bool mHasVertexColor;

	public:

        /** Constructor. */
		GeometryImporter( DocumentImporter* documentImporter, const COLLADAFW::Geometry* geometry );

        /** Destructor. */
		virtual ~GeometryImporter();

		/** Performs the import of the geometry.
		@return True on success, false otherwise.*/
		bool import();


		/** Performs the import of the mesh.
		@return True on success, false otherwise.*/
		bool importMesh();

		/** Performs the import of a mesh that contains only triangles.
		@return True on success, false otherwise.*/
		bool importTriangleMesh();

		/** Performs the import of the mesh positions of a mesh that contains only triangles.
		@return True on success, false otherwise.*/
		bool importTriangleMeshPositions( TriObject* triangleObject );

		/** Performs the import of the mesh normals of a mesh that contains only triangles.
		@return True on success, false otherwise.*/
		bool importTriangleMeshNormals( TriObject* triangleObject );

		/** Performs the import of the mesh uv coordinates of a mesh that contains only triangles.
		@return True on success, false otherwise.*/
		bool importTriangleMeshUVCoords( TriObject* triangleObject );


		/** Performs the import of a mesh that contains polygons.
		@return True on success, false otherwise.*/
		bool importPolygonMesh();

		/** Performs the import of the mesh positions of a mesh that contains polygons.
		@return True on success, false otherwise.*/
		bool importPolygonMeshPositions( PolyObject* polygonObject );

		/** Performs the import of the mesh normals of a mesh that contains polygons.
		@return True on success, false otherwise.*/
		bool importPolygonMeshNormals( PolyObject* polygonObject );

		/** Performs the import of the mesh uv coordinates of a mesh that contains polygons.
		@return True on success, false otherwise.*/
		bool importPolygonMeshUVCoords( PolyObject* polygonObject );



		/** Fills the map with pair of frame work material ids of the used by primitives in @a primitiveArray
		and material ids used in Max. The max material ids start with 1 and are increased for each new
		framework material id.*/
		void createFWMaterialIdMaxMtlIdMap( const COLLADAFW::MeshPrimitiveArray& primitiveArray, DocumentImporter::FWMaterialIdMaxMtlIdMap& materialMap);
	private:

        /** Disable default copy ctor. */
		GeometryImporter( const GeometryImporter& pre );

        /** Disable default assignment operator. */
		const GeometryImporter& operator= ( const GeometryImporter& pre );

		/** Creates the SetSourcePairMapChannelMap using the current geometry.*/
		void createSetSourcePairMapChannelMap();

		/** assigns map channel to inputs in the indexlist array add inserts them to mSetSourcePairMapChannelMap.
		@return false if all map channel are used, true otherwise.*/
		template<bool isColorChannel, bool isFirstTry>
		bool assignMapChannels( const COLLADAFW::IndexListArray& indices, 
			const InitialIndexSourceIndexMap& initialIndexSourceIndexMap,
			bool usedMapChannels[MAX_MESHMAPS + NUM_HIDDENMAPS]);

		/** Sets the uv vertices stored in uvArray into @a meshMap. 
		@param uvArray The vertices source
		@param meshMap The mesh map to be filled 
		@param stride The size of the uv vertex tuples
		@param startPosition The index of the first vertexs first component in the uvArray
		@param vertsCount the number of vertices to copy. Must be equal to the number set with MeshMap::setNumFaces()*/
		template<class NumberArray>
		void setTriangleMeshUVVertices(const NumberArray& uvArray, MeshMap& meshMap, size_t stride, size_t startPosition, size_t vertsCount);

		/** Sets the uv vertices stored in uvArray into @a meshMap. 
		@param uvArray The vertices source
		@param meshMap The mesh map to be filled 
		@param stride The size of the uv vertex tuples
		@param startPosition The index of the first vertexs first component in the uvArray
		@param vertsCount the number of vertices to copy. Must be equal to the number set with MeshMap::setNumFaces()*/
		template<class NumberArray> 
		void setPolygonMeshUVVertices(const NumberArray& uvArray, MNMap* meshMap, size_t stride, size_t startPosition, size_t vertsCount);

		void setPolygonMeshUVVerticesPerPrimitiveAndChannel( const COLLADAFW::MeshPrimitive* meshPrimitive, MNMap* meshMap, const COLLADAFW::UIntValuesArray& uvIndices, unsigned int initialIndex, size_t& currentFaceIndex);

		void fillPolygonMeshMapPerSet( const COLLADAFW::MeshVertexData& uvCoordinates, const COLLADAFW::MeshVertexData::InputInfosArray& inputInfos, size_t sourceIndex, MNMap* meshMap);
	
		void setTriangleMeshUVVerticesPerPrimitiveAndChannel( const COLLADAFW::MeshPrimitive* meshPrimitive, MeshMap& meshMap, const COLLADAFW::UIntValuesArray& uvIndices, unsigned int initialIndex, size_t& currentFaceIndex);
	
		void fillTriangleMeshMapPerSet( const COLLADAFW::MeshVertexData& uvCoordinates, const COLLADAFW::MeshVertexData::InputInfosArray& inputInfos, size_t sourceIndex, MeshMap& meshMap);
		
		/** Checks if @a dataIndices contains data. If so, it returns false. Otherwise it returns true and increases @a faceIndex
		by the number of faces of @a meshPrimitive.*/
		bool skipMeshData( const COLLADAFW::MeshPrimitive* meshPrimitive, const COLLADAFW::UIntValuesArray& dataIndices, size_t& faceIndex);
	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_GEOMETRYIMPORTER_H__
