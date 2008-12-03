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
    class Mesh : public GeometricElement
    {

    private:

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
        Mesh () : GeometricElement ( GeometricElement::GEO_TYPE_MESH ) {}

        /** Destructor. */
        virtual ~Mesh () {}

        /**
         * Returns a pointer to the searched source element of the given input semantic.
         * @param semantic The input semantic, from which the source element is searched.
         * @return Source* Pointer to the searched source element.
         */
        const SourceBase* getSourceByInputSemantic ( InputSemantic::Semantic semantic ) const
        {
            const InputUnshared* positionsInput = getVertices().getInputBySemantic ( semantic );
            if ( positionsInput == 0 ) return 0;

            COLLADABU::URI positionsInputSource = positionsInput->getSource ();
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