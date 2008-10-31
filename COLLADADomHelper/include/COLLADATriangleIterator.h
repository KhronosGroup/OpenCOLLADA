#ifndef __COLLADA_TRIANGLEITERATOR_H__
#define __COLLADA_TRIANGLEITERATOR_H__

namespace COLLADADomHelper
{

    /** Iterates vertex wise over triangles.
    Can handle trifans and tristripps, too.
    Is also able to work with per index and per vertex data.
    Even with a mixture of the two.
    */
    class TriangleIterator
    {

    public:
        /** Describes input semantics for triangles.
        */
        enum Order
        {
            OTHER = 0x00,
            VERTEX = 0x01,
            NORMAL = 0x02,
            COLOR = 0x04,
            TEXCOORD = 0x08
        };

    public:
        /// The rendering operation type to perform
        enum OperationType {
            /// A list of points, 1 vertex per point
            OT_POINT_LIST = 1,
            /// A list of lines, 2 vertices per line
            OT_LINE_LIST = 2,
            /// A strip of connected lines, 1 vertex per line plus 1 start vertex
            OT_LINE_STRIP = 3,
            /// A list of triangles, 3 vertices per triangle
            OT_TRIANGLE_LIST = 4,
            /// A strip of triangles, 3 vertices for the first triangle, and 1 per triangle after that
            OT_TRIANGLE_STRIP = 5,
            /// A fan of triangles, 3 vertices for the first triangle, and 1 per triangle after that
            OT_TRIANGLE_FAN = 6
        };

        /** C-tor.
        @param triangles <p> element of the <triangles>, <tristrips> or <trifans> element to iterate over.
        */
        TriangleIterator( const domPRef& triangles );
        /** C-tor.
        @param triangles <triangles> element to iterate over.
        */
		TriangleIterator( const domTrianglesRef& triangles );

        /** D-tor.
        */
        virtual ~TriangleIterator();

        /** Check if this iterator has more vertices.
        @return true if this iterator has at least one more vertex.
        */
        bool hasMoreVertex();

        /** Move to next vertex.
        */
        void nextVertex( );

        /** Get data for current vertex. The data may be defined per index or per vertex.
        All parameters are output parameters.
        @param position Position of current vertex.
        @param normal Normal of current vertex.
        @param color Color of current vertex.
        @param tex Texture coordinates of current vertex.
        @param order Mask that indicates which of the other parameters have been set. @see Order.
        */
        void getVertex( domFloat *position, domFloat *normal, domFloat *color, domFloat *tex, int &order );

        /** Get number of vertices this iterator handles.
        @return Number of vertices.
        */
        domUint getVertexCount()const
        {
            return mVertexCount;
        }

        /** Get number of triangles this iterator handles.
        @return Number of triangles.
        */
        domUint getTriangleCount() const
        {
            return mTriangleCount;
        }

        /** Find out if this iterators data have normals.
        @return true if normals are present.
        */
		bool hasNormals() const
		{
			return mHasNormals;
		}

        /** Find out if this iterators data have texture coordinates.
        @return true if texture coordinates are present.
        */
		bool hasTexCoords() const
		{
			return mHasTexCoords;
		}

        /** Find out if this iterators data have texture colors.
        @return true if colors are present.
        */
		bool hasColors() const
		{
			return mHasColors;
		}

        /** Find out which kind of triangles this iterator handles.
        @return Kind of data.
        */
        OperationType getType()const{return mType;}

        /** Find out if normals are defined per Vertex.
        @return true if normals are defined per Vertex.
        */
        bool areNormalsPerVertex() const;

        /** Find out if colors are defined per Vertex.
        @return true if colors are defined per Vertex.
        */
        bool areColorsPerVertex() const;

        /** Find out if texture coordinates are defined per Vertex.
        @return true if texture coordinates are defined per Vertex.
        */
        bool areTexCoordsPerVertex() const;

		/** Retrieves the size of the n-tuple for texcoords
		@return
		*/
		unsigned int getTexCoordSize() const;

    public:
        /** Get position of a vertex.
        @param index Index of vertex as used in <p> element.
        @param position Output parameter.
        */
        virtual void getPosition( const size_t index, domFloat* position );

        /** Get normal of a vertex.
        @param index Index of vertex as used in <p> element.
        @param normal Output parameter.
        */
        virtual void getNormal( const size_t index, domFloat* normal );

        /** Get color of a vertex.
        @param index Index of vertex as used in <p> element.
        @param color Output parameter.
        */
        virtual void getColor( const size_t index, domFloat* color );

        /** Get texture coordinate of a vertex.
        @param index Index of vertex as used in <p> element.
        @param texCoord Output parameter.
        */
        virtual void getTexCoord( const size_t index, domFloat* texCoord );
	
	protected:
        size_t getVertexCount(const domVerticesRef& vertices);

        /** Initializes this iterator.
        @param array Array of <input> elements. 
                T may be domInputLocalOffset_Array or domInputLocal_Array.
                U is an element of T. Thus it may be domInputLocalOffset or domInputLocal
        */
        template <typename T, typename U>
		void init( const T &array );

        /** Initializes positions.
        @param input <input> element to check. T may be domInputLocalOffset or domInputLocal.
        @param order Output parameter. Sets vertex mask if necessary.
        @return true if the passed <input> element contains positions.
        */
        template <typename T>
        bool initVertex(T* const input, int* const order);

        /** Initializes normals.
        @param input <input> element to check. T may be domInputLocalOffset or domInputLocal.
        @param order Output parameter. Sets normal mask if necessary.
        @return true if the passed <input> element contains normals.
        */
        template <typename T>
        bool initNormal(T* const input, int* const order);

        /** Initializes colors.
        @param input <input> element to check. T may be domInputLocalOffset or domInputLocal.
        @param order Output parameter. Sets color mask if necessary.
        @return true if the passed <input> element contains colors
        */
        template <typename T>
        bool initColor(T* const input, int* const order);

        /** Initializes texture coordinates.
        @param input <input> element to check. T may be domInputLocalOffset or domInputLocal.
        @param order Output parameter. Sets texture coordinate mask if necessary.
        @return true if the passed <input> element contains texture coordinates.
        */
        template <typename T>
        bool initTexcoord(T* const input, int* const order);

    protected:
        ///Current index inside <p> element.
        size_t mCurrentVertexIndex;
        ///Number of vertices.
        domUint mVertexCount;
        ///Number of triangles.
        domUint mTriangleCount;
        ///Stores which data are defined by index.
        std::vector<Order> mIndexedDataOrder;
        ///Stores which data are defined by vertex.
        std::vector<Order> mPerVertexDataOrder;
        ///Vertices to handle.
        domVerticesRef mVertices;
        ///Normals to handle.
        domSourceRef mNormals;
        ///Colors to handle.
        domSourceRef mColors;
        ///Texture coordinates to handle.
        domSourceRef mTextures;
        ///<p> element to handle.
        domPRef mP;
        ///Kind of triangles.
        OperationType mType;
		///Flags indicating which data is present.
		bool mHasNormals, mHasTexCoords, mHasColors;

    };   
};

#endif //__COLLADA_TRIANGLEITERATOR_H__
