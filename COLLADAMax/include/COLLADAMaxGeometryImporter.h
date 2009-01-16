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

#ifndef __COLLADAMAX_GEOMETRYIMPORTER_H__
#define __COLLADAMAX_GEOMETRYIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"

namespace COLLADAFW
{
	class Geometry;
	class Mesh;
};


namespace COLLADAMax
{

    /** TODO Documentation */
	class GeometryImporter 	: public ImporterBase
	{
	private:
		/** The geometry that should be imported.*/
		const COLLADAFW::Geometry* mGeometry;

		/** The number of all triangles in all primitives that contain triangles (Triangles, 
		Tristrips, Trisfans).*/
		size_t mTotalTrianglesCount;
	
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



		/** Performs all operations to ensure that the geometry is referenced by the all nodes
		that need to reference it.*/
		bool handleReferences(COLLADAFW::Geometry* geometry, Object* object);

	private:

        /** Disable default copy ctor. */
		GeometryImporter( const GeometryImporter& pre );

        /** Disable default assignment operator. */
		const GeometryImporter& operator= ( const GeometryImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_GEOMETRYIMPORTER_H__
