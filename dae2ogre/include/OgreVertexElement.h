#ifndef __OGRE_VERTEX_ELEMENT_H__
#define __OGRE_VERTEX_ELEMENT_H__

#include "DAE2OgrePrerequisites.h"

namespace Ogre
{
    // Integer formats of fixed bit width
    typedef unsigned int uint32;
    typedef unsigned short uint16;
    typedef unsigned char uint8;
    typedef uint32 RGBA;
    typedef uint32 ARGB;
    typedef uint32 ABGR;
    typedef uint32 BGRA;

    /// Vertex element semantics, used to identify the meaning of vertex buffer contents
    enum VertexElementSemantic {
        /// Position, 3 reals per vertex
        VES_POSITION = 1,
        /// Blending weights
        VES_BLEND_WEIGHTS = 2,
        /// Blending indices
        VES_BLEND_INDICES = 3,
        /// Normal, 3 reals per vertex
        VES_NORMAL = 4,
        /// Diffuse colours
        VES_DIFFUSE = 5,
        /// Specular colours
        VES_SPECULAR = 6,
        /// Texture coordinates
        VES_TEXTURE_COORDINATES = 7,
        /// Binormal (Y axis if normal is Z)
        VES_BINORMAL = 8,
        /// Tangent (X axis if normal is Z)
        VES_TANGENT = 9

    };

    /// Vertex element type, used to identify the base types of the vertex contents
    enum VertexElementType
    {
        VET_FLOAT1 = 0,
        VET_FLOAT2 = 1,
        VET_FLOAT3 = 2,
        VET_FLOAT4 = 3,
        /// alias to more specific colour type - use the current rendersystem's colour packing
        VET_COLOUR = 4,
        VET_SHORT1 = 5,
        VET_SHORT2 = 6,
        VET_SHORT3 = 7,
        VET_SHORT4 = 8,
        VET_UBYTE4 = 9,
        /// D3D style compact colour
        VET_COLOUR_ARGB = 10,
        /// GL style compact colour
        VET_COLOUR_ABGR = 11
    };

    class VertexElement
    {

    public:
        /// The source vertex buffer, as bound to an index using VertexBufferBinding
        unsigned short mSource;
        /// The offset in the buffer that this element starts at
        size_t mOffset;
        /// The type of element
        VertexElementType mType;
        /// The meaning of the element
        VertexElementSemantic mSemantic;
        /// Index of the item, only applicable for some elements like texture coords
        unsigned short mIndex;

        VertexElement();
        VertexElement( unsigned short source, size_t offset, VertexElementType type, VertexElementSemantic semantic, unsigned short index );
        virtual ~VertexElement();

        /// Utility method for helping to calculate offsets
        static size_t getTypeSize( VertexElementType etype );
    };

    enum IndexType {
        IT_16BIT,
        IT_32BIT
    };

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

}

#endif //__OGRE_VERTEX_ELEMENT_H__
