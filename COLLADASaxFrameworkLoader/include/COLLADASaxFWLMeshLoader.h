/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_MESHLOADER_H__
#define __COLLADASAXFWL_MESHLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLGeometricElement.h"
#include "COLLADASaxFWLVertices.h"
#include "COLLADASaxFWLSource.h"
#include "COLLADASaxFWLPolyBase.h"

#include "COLLADAFWMesh.h"


namespace COLLADASaxFWL
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
    class MeshLoader : public ColladaGeometricElement
    {
    public:


    private:

        /**
         * The framework mesh element, to load the data.
         */
        COLLADAFW::Mesh* mMesh;

        /**
         * Describes the mesh-vertex attributes and establishes
         * their topological identity.
         */
        Vertices mVertices;

        /**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
         */
        //PolyBaseArray mPolyBaseElements;

    public:

        /** Constructor. */
        MeshLoader ()
            : ColladaGeometricElement ( GeometricElement::GEO_TYPE_MESH )
            , mMesh ( 0 )
        {}

        /** Destructor. */
        virtual ~MeshLoader () {}

        /**
        * The framework mesh element, to load the data.
        */
        const COLLADAFW::Mesh* getMesh () const { return mMesh; }

        /**
        * The framework mesh element, to load the data.
        */
        COLLADAFW::Mesh* getMesh () { return mMesh; }

        /**
        * Returns the vertex input element with the given semantic or 0 if it not exist.
        * @param semantic The semantic of the searched input element.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputUnshared* getVertexInputBySemantic ( const InputSemantic::Semantic& semantic ) const; 

        /**
         * Returns a pointer to the searched source element of the given input semantic, 
         * if it is a vertex input element.
         * @param semantic The input semantic, from which the source element is searched.
         * @return Source* Pointer to the searched source element.
         */
        const SourceBase* getSourceByInputSemanticFromVertices ( const InputSemantic::Semantic& semantic ) const;

        /**
        * Returns a pointer to the positions source element.
        * @return Source* Pointer to the positions source element.
        */
        const SourceBase* getPositionsSource () const;

        /**
        * Returns a pointer to the positions source element with float values.
        * @return Source* Pointer to the positions source element.
        */
        const FloatSource* MeshLoader::getPositionsFloatSource () const;

        /**
        * Returns a pointer to the positions source element with float values.
        * @return Source* Pointer to the positions source element.
        */
        const DoubleSource* MeshLoader::getPositionsDoubleSource () const;

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

//         /**
//         * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
//         * Can be any combination of the following in any order:
//         * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
//         */
//         const COLLADASaxFWL::PolyBaseArray& getPolyBaseElements () const { return mPolyBaseElements; }
// 
//         /**
//         * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
//         * Can be any combination of the following in any order:
//         * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
//         */
//         void setPolyBaseElements ( const COLLADASaxFWL::PolyBaseArray& polyBaseElements ) 
//         { 
//             mPolyBaseElements = polyBaseElements; 
//         }

        /**
         * Append a poly base element into the mesh (convert the data from sax to framework data).
         */
        void addPolyBaseElement ( const PolyBase& polyBaseElement );
        
        /**
         * Go through the list of input elements of the current poly base and get the 
         * source data of the input elements and write it into the source elements.
         * Attention: if there are multiple sources for the same semantic, we have to 
         * concat the source arrays and the indices!
         */
        void loadSourceElements ( const PolyBase& polyBaseElement );

        /**
         * Load the source element of the current input element into the framework mesh.
         */
        bool loadSourceElement ( const InputShared& input );

        /**
        * Load the positions source element of the current input element into the framework mesh.
        */
        bool loadPositionsSourceElement ( const InputShared& input );

        /**
        * Load the normals source element of the current input element into the framework mesh.
        */
        bool loadNormalsSourceElement ( const InputShared& input );

        /**
        * Load the colors source element of the current input element into the framework mesh.
        */
        bool loadColorsSourceElement ( const InputShared& input );

        /**
        * Load the uv coordinates source element of the current input element into the framework mesh.
        */
        bool loadUVCoordsSourceElement ( const InputShared& input );

    };
}

#endif // __COLLADASAXFWL_MESHLOADER_H__