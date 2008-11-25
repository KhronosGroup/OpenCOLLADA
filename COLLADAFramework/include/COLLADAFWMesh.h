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
        * Contains polygon primitives which may contain holes.
         */
        PolygonsArray mPolygonsArray;


    public:

        /** Constructor. */
        Mesh ()
        {}

        /** Destructor. */
        virtual ~Mesh () 
        {
//             delete mPolylistArray;
//             delete mSourceArray;
        }

        /**
         * Provides the bulk of the mesh’s vertex data. See main entry.
         * @param sourceArraySize Parameter to get the size of the source array.
         * @return const SourceArray The source array.
         */
        const SourceArray& getSourceArray () const 
        { 
            return mSourceArray; 
        }
        
        /**
         * Provides the bulk of the mesh’s vertex data. See main entry.
         * @param sourceArray The source array.
         * @param sourceArraySize The size of the source array.
         */
        void setSourceArray ( const SourceArray& sourceArray ) 
        { 
            mSourceArray = sourceArray; 
        }

        /**
         * Returns the source element of the source array with the given id or 0 if it not exist.
         * @param sourceId The source id of the searched source element.
         * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
         */
        const SourceBase* getSourceById ( const String& sourceId ) const
        {
            for ( size_t i=0; i<mSourceArray.getCount (); ++i )
            {
                SourceBase* source = mSourceArray [ i ];
                if ( COLLADASW::Utils::equals ( source->getId (), sourceId ) )
                    return source;
            }

            return 0;
        }

        /**
         * Returns a pointer to the searched source element of the given input semantic.
         * @param semantic The input semantic, from which the source element is searched.
         * @return Source* Pointer to the searched source element.
         */
        const SourceBase* getSourceByInputSemantic ( InputSemantic::Semantic semantic ) const
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
        * @return Returns a reference to the array of polygons elements.
        */
        PolygonsArray& getPolygonsArray () 
        { 
            return mPolygonsArray; 
        }

        /**
        * Gets the polygons element array.
        * @return Returns a constant reference to the array of polygons elements.
        */
        const PolygonsArray &getPolygonsArray () const 
        { 
            return mPolygonsArray; 
        }

        /**
        * Gets the polylist element array.
        * @param Pointer to the array of polylist elements.
        */
        void setPolygonsArray ( const PolygonsArray& polygonsArray )  
        { 
            mPolygonsArray = polygonsArray; 
        }

        /**
        * Gets the polylist element array.
        * @return Returns a constant pointer to the array of polylist elements.
        */
        const PolylistArray& getPolylistArray () const 
        { 
            return mPolylistArray; 
        }

        /**
         * Sets the polylist element array.
         * @param polylistList Pointer to the polylist list to set.
         */
        void setPolylistArray ( const PolylistArray& polylistArray ) 
        { 
            mPolylistArray = polylistArray; 
        }

    };
}

#endif // __COLLADA_MESH_H__