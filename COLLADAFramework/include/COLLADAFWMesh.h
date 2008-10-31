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
#include "COLLADAFWPolylist.h"
#include "COLLADAFWVertices.h"
#include "COLLADAFWSource.h"


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
    class Mesh
    {

    private:

        /**
         * Provides the bulk of the mesh’s vertex data. See main entry.
         */
        SourceArray mSourceArray;

        /**
         * The size of the current source array.
         */
        size_t mSourceArraySize;

        /**
         * Describes the mesh-vertex attributes and establishes
         * their topological identity.
         */
        Vertices mVertices;

        /**
        * The mesh element may contain any number of polylist elements.  
        * A polylist list contains polygon primitives that cannot contain holes. 
        */
        PolylistArray mPolylistArray;

        /**
         * The number of polylist elements in the polylist list.
         */
        size_t mPolylistArraySize;

    public:

        /** Constructor. */
        Mesh () : mPolylistArray ( 0 ) {}

        /** Destructor. */
        virtual ~Mesh () 
        {
            delete[] mPolylistArray;
        }

        /**
         * Provides the bulk of the mesh’s vertex data. See main entry.
         * @param sourceArraySize Parameter to get the size of the source array.
         * @return const SourceArray The source array.
         */
        const SourceArray getSourceArray ( size_t& sourceArraySize ) const 
        { 
            sourceArraySize = mSourceArraySize;
            return mSourceArray; 
        }
        
        /**
         * Provides the bulk of the mesh’s vertex data. See main entry.
         * @param sourceArray The source array.
         * @param sourceArraySize The size of the source array.
         */
        void setSourceArray ( const SourceArray sourceArray, const size_t sourceArraySize ) 
        { 
            mSourceArraySize = sourceArraySize;
            mSourceArray = sourceArray; 
        }


//         /**
//         * Gets the polygons element array.
//         * @return Returns a reference to the array of polygons elements.
//         */
//         domPolygons_Array &getPolygons_array() { return elemPolygons_array; }
//         /**
//         * Gets the polygons element array.
//         * @return Returns a constant reference to the array of polygons elements.
//         */
//         const domPolygons_Array &getPolygons_array() const { return elemPolygons_array; }

        /**
        * Gets the polylist element array.
        * @param polylistSize Parameter to set the number of elements in the polylist list.
        * @return Returns a pointer to the array of polylist elements.
        */
        PolylistArray getPolylistArray ( size_t& polylistArraySize ) 
        {
            polylistArraySize = mPolylistArraySize;
            return mPolylistArray; 
        }

        /**
        * Gets the polylist element array.
        * @param polylistSize Parameter to set the number of elements in the polylist list.
        * @return Returns a constant pointer to the array of polylist elements.
        */
        const PolylistArray getPolylistArray ( size_t& polylistArraySize ) const 
        { 
            polylistArraySize = mPolylistArraySize;
            return mPolylistArray; 
        }

        /**
         * Sets the polylist element array.
         * @param polylistList Pointer to the polylist list to set.
         * @param polylistSize The number of elements in the polylist list.
         */
        void setPolylistArray ( Polylist polylistArray[], const size_t polylistArraySize ) 
        { 
            mPolylistArraySize = polylistArraySize;
            mPolylistArray = polylistArray; 
        }

    };
}

#endif // __COLLADA_MESH_H__