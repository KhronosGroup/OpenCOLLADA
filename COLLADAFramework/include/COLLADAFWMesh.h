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
#include "COLLADAFWGeometricElement.h"
#include "COLLADAFWMeshPositions.h"
#include "COLLADAFWMeshNormals.h"
#include "COLLADAFWMeshColors.h"
#include "COLLADAFWMeshUVCoords.h"
#include "COLLADAFWPrimitiveElement.h"


namespace COLLADAFW
{

    class Geometry;

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
    class Mesh : public GeometricElement
    {
    public:


    private:

        /**
         * The parent geometry element.
         */
        Geometry* mGeometry;

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

        /** 
        * The colors array. 
        * Colors can be stored as float or double values.
        * Colors can have different strides (RGB or RGBA parameters). We need to store this 
        * information!
        */
        MeshColors mColors;

        /** 
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
        PrimitiveElementsArray mPrimitiveElements;

    public:

        /** Constructor. */
        Mesh ( Geometry* geometry ) 
            : GeometricElement ( GeometricElement::GEO_TYPE_MESH ) 
            , mGeometry ( geometry )
//             , mPositions (0)
//             , mNormals (0)
//             , mColors (0)
//             , mUVCoords (0)
        {}

        /** Destructor. */
        virtual ~Mesh () 
        {
//             delete mPositions;
//             delete mNormals;
//             delete mColors;
//             delete mUVCoords;
        }

        /**
        * The parent geometry element.
        */
        const Geometry* getGeometry () const { return mGeometry; }

        /**
        * The parent geometry element.
        */
        Geometry* getGeometry () { return mGeometry; }

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

        /**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
        */
        PrimitiveElementsArray& getPrimitiveElements () { return mPrimitiveElements; }

        /**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
        */
        const PrimitiveElementsArray& getPrimitiveElements () const { return mPrimitiveElements; }

        /**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
        */
        void setPrimitiveElements ( const PrimitiveElementsArray& primitiveElements ) { mPrimitiveElements = primitiveElements; }

        /**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
        */
        PrimitiveElement* appendPrimitiveElement ( PrimitiveElement* primitiveElement ) 
        { return mPrimitiveElements.append ( primitiveElement ); }

    };
}

#endif // __COLLADA_MESH_H__