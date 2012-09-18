/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADASaxFWLMeshPrimitiveInputList.h"
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
     * � Vertex position
     * � Vertex color
     * � Vertex normal
     * � Vertex texture coordinate
     * The mesh also includes a description of how the vertices are organized to 
     * form the geometric shape of the mesh. The mesh vertices are collated into 
     * geometric primitives such as polygons, triangles, or lines.
     */
    class MeshLoader : public SourceArrayLoader
    {
    public:

        struct PrimitiveInput 
        {
            String mName;
            size_t mOffset;
            size_t mStride;
            size_t mSetIndex;
            size_t mInitialIndex;
        };

	private:
		enum PrimitiveType
		{
			NONE,
			TRIANGLES,
			TRISTRIPS,
			TRIFANS,
			POLYGONS,
			POLYGONS_HOLE,
			POLYLIST,
			LINESTRIPS,
			LINES
		};
    private:

		/** The unique id of the mesh.*/
		COLLADAFW::UniqueId mMeshUniqueId;

        /**
         * The framework mesh element, to load the data. 
         */
        COLLADAFW::Mesh* mMesh;

		/** The mapping of collada symbols to material ids.*/
		GeometryMaterialIdInfo& mMaterialIdInfo;

		/** The material symbol of the current mesh. Is only used for primitives, for which the 
		the framework object is not created in the begin__* method.*/
		String mCurrentMeshMaterial;

		/** The mesh primitive being filled by the parser.*/
		COLLADAFW::MeshPrimitive* mCurrentMeshPrimitive;

        /**
         * Describes the mesh-vertex attributes and establishes
         * their topological identity.
         */
        Vertices mVerticesInputs;

        /** Flag is true, if we are currently in the vertices part. */
        bool mInVertices;

		/** The vertex input being parse.*/
		InputUnshared* mCurrentVertexInput;

		/**
		* Describes the mesh-vertex attributes and establishes
		* their topological identity.
		*/
		MeshPrimitiveInputList mMeshPrimitiveInputs;

		/** The mesh primitive input being parse.*/
		InputSharedArray* mCurrentMeshPrimitiveInput;

		/** The offset of the next index received from the sax parser.*/
		size_t mCurrentOffset;

		/** The max offset of the current MeshPrimitive.*/
		size_t mCurrentMaxOffset;

		/** The vertex count of the current MeshPrimitive.*/
		size_t mCurrentVertexCount;

		/** The vertex count after the last face of the current MeshPrimitive was completed.*/
		size_t mCurrentLastPrimitiveVertexCount;

		/** Used only when loading ph elements of polygons. Indicates, if the last found p element, 
		which is a child of a ph element is empty, i.e. contains no indices. This memeber is set in 
		end__ph__p and read in end__h and data__h*/
		bool mCurrentPhHasEmptyP;

		/** The expected vertex count of the current MeshPrimitive. Uses this, if the face vertex count can be
		predicted or calculated, before reading the p elements.*/
		size_t mCurrentExpectedVertexCount;

		/** The number of faces of the current MeshPrimitive. Uses this, if the face count cannot be calculated
		using the values above. (for collada polygons).*/
		size_t mCurrentFaceOrLineCount;

		/** The value of the count attribute in the COLLADA primitive. Might be used to pre-alloc memory.*/
		size_t mCurrentCOLLADAPrimitiveCount;

        /** Variables for the offsets of the index input elements. */
        unsigned long long mPositionsOffset; 
		unsigned int mPositionsIndexOffset; 
        bool mUsePositions;

        unsigned long long mNormalsOffset; 
		unsigned int mNormalsIndexOffset; 
        bool mUseNormals;

        unsigned long long mTangentsOffset; 
        unsigned int mTangentsIndexOffset; 
        bool mUseTangents;

        unsigned long long mBinormalsOffset; 
        unsigned int mBinormalsIndexOffset; 
        bool mUseBinormals;

        /** Multiple colors. */
        std::vector<PrimitiveInput> mColorList;

        /** Multiple texcoordinates. */
        std::vector<PrimitiveInput> mTexCoordList;

        /** The type of the current primitive element. */
		PrimitiveType mCurrentPrimitiveType;

		/** Number of already closed p elements in current primitive.*/
		unsigned int mPOrPhElementCountOfCurrentPrimitive;

        /** We need a variable for the second key name. */
        String mSecondKey;

        /** Flag for the extra tag preservation, to know if we are parsing in the mesh. */
        bool mInMesh;

    public:

        /** Constructor. */
		MeshLoader ( IFilePartLoader* callingFilePartLoader, const String& geometryId, const String& geometryName );

        /** Destructor. */
        virtual ~MeshLoader () { delete mMesh; }

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

        /** Returns the mesh that has just been loaded.*/
		COLLADAFW::Mesh* getMesh() { return mMesh; }

		/** Sax callback function for the beginning of a source element.*/
		virtual bool begin__source(const source__AttributeData& attributes);

		/** Sax callback function for the ending of a source element.*/
		virtual bool end__source();
		
		/** Cleans up everything and gives control to calling file part loader.*/
		virtual bool end__mesh();

        /** Flag for the extra tag preservation, to know if we are parsing in the mesh. */
        const bool& isInMesh () const { return mInMesh; }
        void setInMesh ( const bool& val ) { mInMesh = val; }

		/** Sax callback function for the beginning of a vertices element.*/
		virtual bool begin__vertices( const vertices__AttributeData& attributeData );

		/** Sax callback function for the ending of a vertices element.*/
		virtual bool end__vertices();


		/** Sax callback function for the beginning of a input element.*/
		virtual bool begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData );

		/** Sax callback function for the ending of a input element.*/
		virtual bool end__input____InputLocal();


		/** Sax callback function for the beginning of a triangles element.*/
		virtual bool begin__triangles( const triangles__AttributeData& attributeData );

		/** Sax callback function for the ending of a triangles element.*/
		virtual bool end__triangles();


		/** Sax callback function for the beginning of a triangles input element.*/
		virtual bool begin__input____InputLocalOffset( const input____InputLocalOffset__AttributeData& attributeData );

		/** Sax callback function for the ending of a triangles input element.*/
		virtual bool end__input____InputLocalOffset();


		/** Sax callback function for the beginning of a p.*/
		virtual bool begin__p();

		/** Sax callback function for the ending of a p.*/
		virtual bool end__p();

		/** Sax callback function for the data of a p within a triangles element element.*/
		virtual bool data__p( const unsigned long long* data, size_t length );


		/** Sax callback function for the beginning of a polylist element.*/
		virtual bool begin__polylist( const polylist__AttributeData& attributeData );

		/** Sax callback function for the ending of a polylist element.*/
		virtual bool end__polylist();


		/** Sax callback function for the beginning of a lines element.*/
		virtual bool begin__lines( const lines__AttributeData& attributeData );

		/** Sax callback function for the ending of a lines element.*/
		virtual bool end__lines();


		/** Sax callback function for the beginning of a line strips element.*/
		virtual bool begin__linestrips( const linestrips__AttributeData& attributeData );

		/** Sax callback function for the ending of a line strips element.*/
		virtual bool end__linestrips();


		/** Sax callback function for the beginning of a polylist vcount element.*/
		virtual bool begin__vcount();

		/** Sax callback function for the ending of a polylist vcount element.*/
		virtual bool end__vcount();

		/** Sax callback function for the data of a polylist vcount element.*/
		virtual bool data__vcount( const unsigned long long*, size_t length );


		/** Sax callback function for the beginning of a polygons element.*/
		virtual bool begin__polygons( const polygons__AttributeData& attributeData );

		/** Sax callback function for the ending of a polygons element.*/
		virtual bool end__polygons();


		/** Sax callback function for the beginning of a polygons ph element.*/
		virtual bool begin__ph();

		/** Sax callback function for the ending of a polygons ph element.*/
		virtual bool end__ph();


		/** Sax callback function for the beginning of a polygons h element inside a ph element.*/
		virtual bool begin__h();

		/** Sax callback function for the ending of a polygons h element inside a ph element.*/
		virtual bool end__h();

		/** Sax callback function for the data of a polygons h element inside a ph element.*/
		virtual bool data__h( const uint64* data, size_t length );


		/** Sax callback function for the beginning of a polygons element.*/
		virtual bool begin__tristrips( const tristrips__AttributeData& attributeData );

		/** Sax callback function for the ending of a polygons element.*/
		virtual bool end__tristrips();


		/** Sax callback function for the beginning of a polygons element.*/
		virtual bool begin__trifans( const trifans__AttributeData& attributeData );

		/** Sax callback function for the ending of a polygons element.*/
		virtual bool end__trifans();


		/** Stores the information provided by the attributes of an input element for all mesh primitives.*/
		bool beginInput(const input____InputLocalOffset__AttributeData& attributeData);


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


		/** Sets the offsets for the different semantics (positions normals etc)*/
		void initializeOffsets();
        void initializeTexCoordsOffset ();
        void initializeColorsOffset ();
        void initializeNormalsOffset ();
        void initializeTangentsOffset ();
        void initializeBinormalsOffset ();
        void initializePositionsOffset ();

		/** Writes all the indices in data into the indices array of the current mesh primitive.*/
		bool writePrimitiveIndices ( const unsigned long long* data, size_t length );

        /**
         * Get the number of all indices in all p elements in the current primitive element.
         */
        size_t getNumOfPrimitiveIndices ( const MeshPrimitiveInputList* polyBaseElement );

        /**
         * Go through the list of input elements of the current poly base and get the 
         * source data of the input elements and write it into the source elements.
         * Attention: if there are multiple sources for the same semantic, we have to 
         * concat the source arrays and the indices!
         */
        void loadSourceElements ( const MeshPrimitiveInputList& polyBaseElement );

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
        bool loadTexCoordsSourceElement ( const InputShared& input );

        /** 
        * Load the tangent source element of the current input element into the framework mesh
        */

        bool loadTexBinormalSourceElement( const InputShared & input );

        /** 
        * Load the tangent source element of the current input element into the framework mesh
        */

        bool loadTexTangentSourceElement( const InputShared & input );

        /**
        * Appends the values of the source in the list with the dimension of source's stride.
        */
        bool appendVertexValues ( 
            SourceBase* sourceBase, 
            COLLADAFW::MeshVertexData& vertexData );
    };
}

#endif // __COLLADASAXFWL_MESHLOADER_H__
