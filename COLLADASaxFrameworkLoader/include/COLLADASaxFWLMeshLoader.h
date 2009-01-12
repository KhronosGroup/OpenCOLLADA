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
#include "COLLADASaxFWLVertices.h"
#include "COLLADASaxFWLSource.h"
#include "COLLADASaxFWLPolyBase.h"
#include "COLLADASaxFWLSourceArrayLoader.h"

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
    class MeshLoader : public SourceArrayLoader
    {
    private:

        /**
         * The framework mesh element, to load the data.
         */
        COLLADAFW::Mesh* mMesh;

		/** The mesh primitive being filled by the parser.*/
		COLLADAFW::MeshPrimitive* mCurrentMeshPrimitive;

        /**
         * Describes the mesh-vertex attributes and establishes
         * their topological identity.
         */
        Vertices mVerticesInputs;

		/** The vertex input being parse.*/
		InputUnshared* mCurrentVertexInput;

		/**
		* Describes the mesh-vertex attributes and establishes
		* their topological identity.
		*/
		PolyBase mMeshPrimitiveInputs;

		/** The mesh primitive input being parse.*/
		InputSharedArray* mCurrentMeshPrimitiveInput;

		/** The offset of the next index received from the sax parser.*/
		size_t mCurrentOffset;

		/** The max offset of the current MeshPrimitive.*/
		size_t mCurrentMaxOffset;

		/** The vertex count of the current MeshPrimitive.*/
		size_t mCurrentVertexCount;

		/** The expected vertex count of the current MeshPrimitive. Uses this, if the face vertex count can be
		predicted or calculated, before reading the p elements.*/
		size_t mCurrentExpectedVertexCount;

		/**
        * Geometric primitives, which assemble values from the inputs into vertex attribute data. 
        * Can be any combination of the following in any order:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
         */
        //PolyBaseArray mPolyBaseElements;


        // Variables for the offsets of the index input elements.
        size_t mPositionsOffset; 
        bool mUsePositions;
        size_t mNormalsOffset; 
        bool mUseNormals;
        size_t mColorsOffset; 
        bool mUseColors;
        size_t mUVCoordsOffset; 
        bool mUseUVCoords;

    public:

        /** Constructor. */
		MeshLoader ( IFilePartLoader* callingFilePartLoader, const String& geometryId, const String& geometryName );

        /** Destructor. */
        virtual ~MeshLoader () {}

		/** Sax callback function for the beginning of a source element.*/
		virtual bool begin__mesh__source(const mesh__source__AttributeData& attributes);

		/** Sax callback function for the ending of a source element.*/
		virtual bool end__mesh__source();
		
		/** Cleans up everything and gives control to calling file part loader.*/
		virtual bool end__mesh();


		/** Sax callback function for the beginning of a vertices element.*/
		virtual bool begin__mesh__vertices( const mesh__vertices__AttributeData& attributeData );

		/** Sax callback function for the ending of a vertices element.*/
		virtual bool end__mesh__vertices();


		/** Sax callback function for the beginning of a input element.*/
		virtual bool begin__vertices__input( const vertices__input__AttributeData& attributeData );

		/** Sax callback function for the ending of a input element.*/
		virtual bool end__vertices__input();


		/** Sax callback function for the beginning of a triangles element.*/
		virtual bool begin__mesh__triangles( const mesh__triangles__AttributeData& attributeData );

		/** Sax callback function for the ending of a triangles element.*/
		virtual bool end__mesh__triangles();


		/** Sax callback function for the beginning of a triangles input element.*/
		virtual bool begin__triangles__input( const triangles__input__AttributeData& attributeData );

		/** Sax callback function for the ending of a triangles input element.*/
		virtual bool end__triangles__input();


		/** Sax callback function for the beginning of a p within a triangles element element.*/
		virtual bool begin__triangles__p();

		/** Sax callback function for the ending of a p within a triangles element element.*/
		virtual bool end__triangles__p();

		/** Sax callback function for the data of a p within a triangles element element.*/
		virtual bool data__triangles__p( const unsigned long long* data, size_t length );


		/** Sax callback function for the beginning of a polylist element.*/
		virtual bool begin__mesh__polylist( const mesh__polylist__AttributeData& attributeData );

		/** Sax callback function for the ending of a polylist element.*/
		virtual bool end__mesh__polylist();


		/** Sax callback function for the beginning of a polylist input element.*/
		virtual bool begin__polylist__input( const polylist__input__AttributeData& attributeData );

		/** Sax callback function for the ending of a polylist input element.*/
		virtual bool end__polylist__input();


		/** Sax callback function for the beginning of a polylist vcount element.*/
		virtual bool begin__polylist__vcount();

		/** Sax callback function for the ending of a polylist vcount element.*/
		virtual bool end__polylist__vcount();

		/** Sax callback function for the data of a polylist vcount element.*/
		virtual bool data__polylist__vcount( const unsigned long long*, size_t length );


		/** Sax callback function for the beginning of a polylist p element.*/
		virtual bool begin__polylist__p();

		/** Sax callback function for the ending of a polylist p element.*/
		virtual bool end__polylist__p();

		/** Sax callback function for the data of a polylist p element.*/
		virtual bool data__polylist__p( const unsigned long long* value, size_t length );


		/** Stores the information provided by the attributes of an input element for all mesh primitives.*/
		bool beginInput(const triangles__input__AttributeData& attributeData);


	private:

		/** Initializes all the current values, i.e. values used while parsing a mesh primitive.*/
		void initCurrentValues();

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
        const FloatSource* getPositionsFloatSource () const;

        /**
        * Returns a pointer to the positions source element with float values.
        * @return Source* Pointer to the positions source element.
        */
        const DoubleSource* getPositionsDoubleSource () const;

        /**
         * Describes the mesh-vertex attributes and establishes their topological identity.
         * @return const Vertices The mesh-vertex attributes.
         */
        Vertices& getVertices () { return mVerticesInputs; }

        /**
        * Describes the mesh-vertex attributes and establishes their topological identity.
        * @return const Vertices The mesh-vertex attributes.
        */
        const Vertices& getVertices () const { return mVerticesInputs; }

        /**
         * Describes the mesh-vertex attributes and establishes their topological identity.
         * @param vertices The mesh-vertex attributes.
         */
        void setVertices ( const Vertices& vertices ) { mVerticesInputs = vertices; }

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
        void addPolyBaseElement ( const COLLADASaxFWL::PolyBase* polyBaseElement );

        /**
         * Load the index lists.
         * @param primitiveElement
         * @param polyBaseElement
         * @return void
         */
        void loadIndexLists ( 
            COLLADAFW::MeshPrimitive* primitiveElement, 
            const PolyBase* polyBaseElement );

        /**
         * Generate the face vertex count array if necessary and set it into the mesh.
         * @param primitiveElement
         * @param polyBaseElement
         * @return void
         */
        void loadFaceVertexCountArray ( 
            COLLADAFW::MeshPrimitive* primitiveElement, 
            const PolyBase* polyBaseElement );

        /**
         * Initialize the size of the index lists, check for used source elements and get 
         * the offset values of the index lists.
         */
        bool initializeIndexLists ( 
            COLLADAFW::MeshPrimitive* primitiveElement, 
            const PolyBase* polyBaseElement );

		/** Sets the offsets for the different semantics (positions normals etc)*/
		bool initializeOffsets();

        /**
         * Push the index values of the current p element in the list of indexes of the current 
         * input elements.
         */
        void writePElementIndices ( 
            const PElement* pElement, 
            COLLADAFW::MeshPrimitive* primitiveElement, 
            const size_t maxOffset );


		/** Writes all the indices in data into the indices array of the current mesh primitive.*/
		void writePrimitiveIndices ( const unsigned long long* data, size_t length );

        /**
         * Get the number of all indices in all p elements in the current primitive element.
         */
        size_t getNumOfPrimitiveIndices ( const PolyBase* polyBaseElement );

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