/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAFramework.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MESHPRIMITIVEWITHFACEVERTEXCOUNT_H__
#define __COLLADAFW_MESHPRIMITIVEWITHFACEVERTEXCOUNT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshPrimitive.h"

namespace COLLADAFW
{

    /**
    Geometric primitives, which assemble values from the inputs into vertex attribute data. 
    Can be any combination of any primitive types in any order. 

    To describe geometric primitives that are formed from the vertex data, the <mesh> element may 
    contain zero or more of the primitive elements <lines>, <linestrips>, <polygons>, <polylist>,
    <triangles>, <trifans>, and <tristrips>.
    The <vertices> element under <mesh> is used to describe mesh-vertices. Polygons, triangles, and 
    so forth index mesh-vertices, not positions directly. Mesh-vertices must have at least one 
    <input> (unshared) element with a semantic attribute whose value is POSITION.
    For texture coordinates, COLLADA’s right-handed coordinate system applies; therefore, an ST 
    texture coordinate of [0,0] maps to the lower-left texel of a texture image, when loaded in a 
    professional 2-D texture viewer/editor.
    */
	template<class VertexCountType>
	class MeshPrimitiveWithFaceVertexCount : public MeshPrimitive
    {

    public:
		typedef ArrayPrimitiveType<VertexCountType> VertexCountArray;

    private:
        /**
         * Contains a list of integers, each specifying the number of vertices for one 
         * - polygon face 
         * - hole
         * - tristrip or trifan
         * element.
         */
        VertexCountArray mGroupedVerticesVertexCountArray;

    protected:

        /**
        * Constructor.
        */
		MeshPrimitiveWithFaceVertexCount ( const UniqueId& uniqueId, PrimitiveType primitiveType ) 
            : MeshPrimitive ( uniqueId, primitiveType )
     		, mGroupedVerticesVertexCountArray(VertexCountArray::OWNER) 
        {}

	public:	

        /**
        * Destructor.
        */
        virtual ~MeshPrimitiveWithFaceVertexCount() {}

        /**
        * Contains a list of integers, each specifying the number of vertices for one polygon face.
        */
        VertexCountArray& getGroupedVerticesVertexCountArray () { return mGroupedVerticesVertexCountArray; }

        /**
        * Contains a list of integers, each specifying the number of vertices for one polygon face.
        */
        const VertexCountArray& getGroupedVerticesVertexCountArray () const { return mGroupedVerticesVertexCountArray; }

        /**
        * Contains a list of integers, each specifying the number of vertices for one polygon face.
        */
        void setGroupedVerticesVertexCountArray ( const VertexCountArray& FaceVertexCountArray ) { mGroupedVerticesVertexCountArray = FaceVertexCountArray; }

        /*
        *	Returns the vertex count of the face on the specified index position.
        */
        const int getGroupedVerticesVertexCount ( const size_t faceIndex ) const 
        {
            if ( faceIndex >= mGroupedVerticesVertexCountArray.getCount () ) 
            {
                std::cerr << "Face index out of range: " << faceIndex << std::endl;
				COLLADABU_ASSERT ( "Face index out of range: " + faceIndex );
                return -1;
            }

            return mGroupedVerticesVertexCountArray [ faceIndex ];
        }

    };


}

#endif // __COLLADAFW_MESHPRIMITIVEWITHFACEVERTEXCOUNT_H__
