/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SPLINE_H__
#define __COLLADAFW_SPLINE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWMeshVertexData.h"
#include "COLLADAFWMeshPrimitive.h"

#include "COLLADABUUtils.h"


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
    class Spline : public Geometry
    {
    public:
    
        enum Interpolation
        {
            LINEAR,
            BEZIER
        };

        typedef ArrayPrimitiveType<Interpolation> InterpolationArray;

    private:

        /** 
         * The positions array. Positions can be stored as float or double values.
         * Positions have always a stride of three (XYZ parameters). We don't need to store
         * this information.
         */
        MeshVertexData mPositions;
        MeshVertexData mInTangents;
        MeshVertexData mOutTangents;
        InterpolationArray mInterpolations;

    public:

        /** Constructor. */
        Spline ( const UniqueId& uniqueId );

        /** Destructor. */
        virtual ~Spline ();

        /** 
        * The positions array. 
        * Positions can be stored as float or double values.
        * Positions have always a stride of three (X, Y and Z parameter). So we don't need to 
        * store this information.
        */
        const MeshVertexData& getPositions () const { return mPositions; }

        /** 
        * The positions array. 
        * Positions can be stored as float or double values.
        * Positions have always a stride of three (X, Y and Z parameter). So we don't need to 
        * store this information.
        */
        MeshVertexData& getPositions () { return mPositions; }

        const MeshVertexData& getInTangents () const { return mInTangents; }
        MeshVertexData& getInTangents () { return mInTangents; }

        const MeshVertexData& getOutTangents () const { return mOutTangents; }
        MeshVertexData& getOutTangents () { return mOutTangents; }

        const InterpolationArray& getInterpolations () const { return mInterpolations; }
        InterpolationArray& getInterpolations () { return mInterpolations; }
    };
}

#endif // __COLLADA_MESH_H__
