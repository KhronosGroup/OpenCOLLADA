/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MESH_H__
#define __COLLADAFW_MESH_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWMeshPositions.h"
#include "COLLADAFWMeshNormals.h"
#include "COLLADAFWMeshColors.h"
#include "COLLADAFWMeshUVCoords.h"
#include "COLLADAFWMeshPrimitive.h"


namespace COLLADAFW
{

    /** 
     * Describes basic geometric meshes using vertex and primitive information.
     * Meshes embody a general form of geometric description that primarily 
     * includes vertex and primitive information.
     * Vertex information is the set of attributes associated with a point on 
     * the surface of the mesh. Each vertex includes data for attributes such as:
     * • Vertex position
     * • Vertex color
     * • Vertex normal
     * • Vertex texture coordinate
     * The mesh also includes a description of how the vertices are organized to 
     * form the geometric shape of the mesh. The mesh vertices are collated into 
     * geometric primitives such as polygons, triangles, or lines.
     */
    class Mesh : public Geometry
    {
    public:


    private:

        /** 
         * The positions array. 
         * Positions can be stored as float or double values.
         * Positions have always a stride of three (XYZ parameters). We don't need to store
         * this information.
         */
        MeshPositions mPositions;

        /** 
        * The normals array. 
        * Normals can be stored as float or double values.
        * Normals have always a stride of three (XYZ parameters). We don't need to store this 
        * information.
        */
        MeshNormals mNormals;

        /** TODO support multiple color sets
        * The colors array. 
        * Colors can be stored as float or double values.
        * Colors can have different strides (RGB or RGBA parameters). We need to store this 
        * information!
        */
        MeshColors mColors;

        /** TODO support multiple uv sets
        * The uv coordinates array. 
        * UV coordinates can be stored as float or double values.
        * UV coordinates can have different strides (ST, STU, STUV parameters). We need to store 
        * this information!
        */
        MeshUVCoords mUVCoords;

        /**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Each primitive element holds the index arrays of the used input elements
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
        */
        MeshPrimitiveArray mMeshPrimitives;

    public:

        /** Constructor. */
        Mesh ( ObjectId objectId );

        /** Destructor. */
        virtual ~Mesh ();


        /** 
        * The positions array. 
        * Positions can be stored as float or double values.
        * Positions have always a stride of three (X, Y and Z parameter). So we don't need to 
        * store this information.
        */
        const MeshPositions& getPositions () const { return mPositions; }

        /** 
        * The positions array. 
        * Positions can be stored as float or double values.
        * Positions have always a stride of three (X, Y and Z parameter). So we don't need to 
        * store this information.
        */
        MeshPositions& getPositions () { return mPositions; }

        /** 
        * The positions array. 
        * Positions can be stored as float or double values.
        * Positions have always a stride of three (X, Y and Z parameter). So we don't need to 
        * store this information.
        */
        void setPositions ( MeshPositions& positions ) { mPositions = positions; }

        /** 
        * The normals array. 
        * Normals can be stored as float or double values.
        * Normals have always a stride of three (X, Y and Z parameter). We don't need to store 
        * this information.
        */
        const MeshNormals& getNormals () const { return mNormals; }

        /** 
        * The normals array. 
        * Normals can be stored as float or double values.
        * Normals have always a stride of three (X, Y and Z parameter). We don't need to store 
        * this information.
        */
        MeshNormals& getNormals () { return mNormals; }

        /** 
        * The normals array. 
        * Normals can be stored as float or double values.
        * Normals have always a stride of three (X, Y and Z parameter). We don't need to store 
        * this information.
        */
        void setNormals ( MeshNormals& Normals ) { mNormals = Normals; }

		/**
         * Checks, if the mesh has normals.
         */
		bool hasNormals ( )const;

        /*
         * Counts the number of all normals in the current mesh. This is the sum of the number of
         * normals of all primitive elements into the mesh object.
         */
        const size_t getNormalsCount () const;

        /** 
        * The colors array. 
        * Colors can be stored as float or double values.
        * Colors have always a stride of three (X, Y and Z parameter). We don't need to store 
        * this information.
        */
        const MeshColors& getColors () const { return mColors; }

        /** 
        * The colors array. 
        * Colors can be stored as float or double values.
        * Colors have always a stride of three (X, Y and Z parameter). We don't need to store 
        * this information.
        */
        MeshColors& getColors () { return mColors; }

        /** 
        * The colors array. 
        * Colors can be stored as float or double values.
        * Colors have always a stride of three (X, Y and Z parameter). We don't need to store 
        * this information.
        */
        void setColors ( MeshColors& Colors ) { mColors = Colors; }

		/**Checks, if the mesh has colors.*/
		bool hasColors ( )const;

		/** 
        * The uv coordinates array. 
        * UV coordinates can be stored as float or double values.
        * UV coordinates have always a stride of three (X, Y and Z parameter). We don't need to store 
        * this information.
        */
        const MeshUVCoords& getUVCoords () const { return mUVCoords; }

        /** 
        * The uv coordinates array. 
        * UV coordinates can be stored as float or double values.
        * UV coordinates have always a stride of three (X, Y and Z parameter). We don't need to store 
        * this information.
        */
        MeshUVCoords& getUVCoords () { return mUVCoords; }

        /** 
        * The uv coordinates array. 
        * UV coordinates can be stored as float or double values.
        * UV coordinates have always a stride of three (X, Y and Z parameter). We don't need to store 
        * this information.
        */
        void setUVCoords ( MeshUVCoords& UVCoords ) { mUVCoords = UVCoords; }

		/**Checks, if the mesh has UVCoords.*/
		bool hasUVCoords ( )const;

        /**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
        */
        MeshPrimitiveArray& getMeshPrimitives () { return mMeshPrimitives; }

        /**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
        */
        const MeshPrimitiveArray& getMeshPrimitives () const { return mMeshPrimitives; }

        /**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
        */
        void setMeshPrimitives ( const MeshPrimitiveArray& primitiveElements ) { mMeshPrimitives = primitiveElements; }

		/**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
        */
        MeshPrimitive* appendPrimitive ( MeshPrimitive* primitiveElement ) 
        { return mMeshPrimitives.append ( primitiveElement ); }

		/** Counts the number of all triangles in all Triangle primitives.*/
		size_t getTrianglesTriangleCount();

		/** Counts the number of all triangles in all Tristrips primitives. This is the number
		of triangles one get, if the tristrips are converted to triagles.*/
		size_t getTristripsTriangleCount();

		/** Counts the number of all triangles in all Trifans primitives. This is the number
		of triangles one get, if the tristrips are converted to triagles.*/
		size_t getTrifansTriangleCount();

		/** Counts the number of all polygons in all polygons primitives.*/
		size_t getPolygonsPolygonCount();


		/** Counts the number of all primitives in all primitives of type @a primitiveType.
		@note For Triangles, polygons this is the number of faces (The primitives are faces). For 
		Tristrips and Trisfans this the number of strips and fans (The primitives are not faces).*/
		size_t getPrimitiveCount(MeshPrimitive::PrimitiveType primitiveType);


		/** Counts the number of all primitives in all primitives of type @a primitiveType.
		@note For Triangles, polygons this is the number of primitives (The primitive are faces). 
		For Tristrips and Trisfans this the number of triangles the strips an fans consist of
		(The primitives are not faces, but the triangles they consist of).*/
		size_t getFaceCount(MeshPrimitive::PrimitiveType primitiveType);


		/** Counts the number of all tristrips in all Tristrip primitives.
		TODO not implemented */
		size_t getTristripsTristripCount();

		/** Counts the number of all trifans in all Trifans primitives.
		TODO not implemented */
		size_t getTrifansTrifanCount();



		/** Counts the number of all Triangle primitives.*/
		size_t getTrianglesCount();

		/** Counts the number of all Tristrips primitives.*/
		size_t getTristripsCount();

		/** Counts the number of all Trifans primitives.*/
		size_t getTrifansCount();

		/** Counts the number of all Polygons primitives.*/
		size_t getPolygonsCount();

		/** Counts the number of all mesh primitives of type @a primitiveType in the mesh, i.e.
		it counts the number of primitives of type @a primitiveType in mMeshPrimitives.*/
		size_t getMeshPrimitiveCount(MeshPrimitive::PrimitiveType primitiveType);

	
        /*
         * Counts the number of all faces in all primitive elements in the current mesh.
         */
        const size_t getFacesCount () const;
};
}

#endif // __COLLADA_MESH_H__
