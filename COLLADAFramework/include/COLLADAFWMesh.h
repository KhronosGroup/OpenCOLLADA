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
#include "COLLADAFWPolygons.h"
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

        /**
         * TODO
         */
        PolygonsArray mPolygonsArray;

        /**
         * The number of polygons elements in the polylist list.
         */
        size_t mPolygonsArraySize;


    public:

        /** Constructor. */
        Mesh () : 
          mPolylistArray ( 0 ) 
        , mSourceArray ( 0 )
        {}

        /** Destructor. */
        virtual ~Mesh () 
        {
            delete mPolylistArray;
            delete mSourceArray;
        }

        /**
         * Provides the bulk of the mesh’s vertex data. See main entry.
         * @param sourceArraySize Parameter to get the size of the source array.
         * @return const SourceArray The source array.
         */
        const SourceArray& getSourceArray ( size_t& sourceArraySize ) const 
        { 
            sourceArraySize = mSourceArraySize;
            return mSourceArray; 
        }
        
        /**
         * Provides the bulk of the mesh’s vertex data. See main entry.
         * @param sourceArray The source array.
         * @param sourceArraySize The size of the source array.
         */
        void setSourceArray ( const SourceArray& sourceArray, const size_t sourceArraySize ) 
        { 
            mSourceArraySize = sourceArraySize;
            mSourceArray = sourceArray; 
        }

        /**
         * Returns the source element of the source array with the given id or 0 if it not exist.
         * @param sourceId The source id of the searched source element.
         * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
         */
        const Source* getSourceById ( const String& sourceId ) const
        {
            for ( size_t i=0; i<mSourceArraySize; ++i )
            {
                Source& source = mSourceArray [ i ];
                if ( COLLADASW::Utils::equals ( source.getId (), sourceId ) )
                    return &source;
            }

            return 0;
        }

        /**
         * Returns a pointer to the searched source element of the given input semantic.
         * @param semantic The input semantic, from which the source element is searched.
         * @return Source* Pointer to the searched source element.
         */
        const Source* getSourceByInputSemantic ( COLLADAFW::InputSemantic::Semantic semantic ) const
        {
            const InputUnshared* positionsInput = getVertices().getInputBySemantic ( semantic );
            if ( positionsInput == 0 ) return 0;

            COLLADASW::URI positionsInputSource = positionsInput->getSource ();
            String sourceId = positionsInputSource.getFragment ();
            return getSourceById ( sourceId );
        }

        /**
         * Describes the mesh-vertex attributes and establishes their topological identity.
         * @return const Vertices The mesh-vertex attributes.
         */
        Vertices& getVertices () { return mVertices; }

        /**
        * Describes the mesh-vertex attributes and establishes their topological identity.
        * @return const Vertices The mesh-vertex attributes.
        */
        const Vertices& getVertices () const { return mVertices; }

        /**
         * Describes the mesh-vertex attributes and establishes their topological identity.
         * @param vertices The mesh-vertex attributes.
         */
        void setVertices ( const Vertices& vertices ) { mVertices = vertices; }

        /**
        * Gets the polygons element array.
        * @param polygonsArraySize Parameter to store the size of the array.
        * @return Returns a reference to the array of polygons elements.
        */
        PolygonsArray& getPolygonsArray ( size_t& polygonsArraySize ) 
        { 
            polygonsArraySize = mPolygonsArraySize; 
            return mPolygonsArray; 
        }

        /**
        * Gets the polylist element array.
        * @param Pointer to the array of polylist elements.
        * @param polylistArraySize The number of elements in the polylist array.
        */
        void setPolygonsArray ( const PolygonsArray& polygonsArray, const size_t polygonsArraySize )  
        { 
            mPolygonsArraySize = polygonsArraySize;
            mPolygonsArray = polygonsArray; 
        }

        /**
        * Gets the polygons element array.
        * @param polygonsArraySize Parameter to store the size of the array.
        * @return Returns a constant reference to the array of polygons elements.
        */
        const PolygonsArray &getPolygonsArray ( size_t& polygonsArraySize ) const 
        { 
            polygonsArraySize = mPolygonsArraySize; 
            return mPolygonsArray; 
        }

        /**
        * Gets the polylist element array.
        * @param polylistSize Parameter to set the number of elements in the polylist list.
        * @return Returns a constant pointer to the array of polylist elements.
        */
        const PolylistArray& getPolylistArray ( size_t& polylistArraySize ) const 
        { 
            polylistArraySize = mPolylistArraySize;
            return mPolylistArray; 
        }

        /**
         * Sets the polylist element array.
         * @param polylistList Pointer to the polylist list to set.
         * @param polylistSize The number of elements in the polylist list.
         */
        void setPolylistArray ( const PolylistArray polylistArray, const size_t polylistArraySize ) 
        { 
            mPolylistArraySize = polylistArraySize;
            mPolylistArray = polylistArray; 
        }

    };
}

#endif // __COLLADA_MESH_H__