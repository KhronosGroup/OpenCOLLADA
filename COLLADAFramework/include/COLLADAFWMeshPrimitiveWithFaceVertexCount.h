/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
		typedef COLLADAFW::ArrayPrimitiveType<VertexCountType> VertexCountArray;

    private:
        /**
         * Contains a list of integers, each specifying the number of vertices for one polygon face.
         */
        VertexCountArray mFaceVertexCountArray;

    protected:	
        /**
        * Constructor.
        */
		MeshPrimitiveWithFaceVertexCount ( PrimitiveType primitiveType ) : 
			 MeshPrimitive(primitiveType)
     		, mFaceVertexCountArray(VertexCountArray::OWNER) {}

	public:	
        /**
        * Destructor.
        */
        virtual ~MeshPrimitiveWithFaceVertexCount() {}

        /**
        * Contains a list of integers, each specifying the number of vertices for one polygon face.
        */
        VertexCountArray& getFaceVertexCountArray () { return mFaceVertexCountArray; }

        /**
        * Contains a list of integers, each specifying the number of vertices for one polygon face.
        */
        const VertexCountArray& getFaceVertexCountArray () const { return mFaceVertexCountArray; }

        /**
        * Contains a list of integers, each specifying the number of vertices for one polygon face.
        */
        void setFaceVertexCountArray ( const VertexCountArray& FaceVertexCountArray ) { mFaceVertexCountArray = FaceVertexCountArray; }

		/**
		* Initialize the index list of the edges ( the index list is referencing on the position indices )
		*/
		VertexCountArray& initializeEdgeIndices ( VertexCountArray& edgeIndices )
		{
			// TODO Create the edges... Geht nicht mehr, bin platt, denken klappt heut nicht mehr, sorry!

			// Go through the list of faces and write the edge indices for every face.
			for ( size_t faceIndex=0; faceIndex<getFaceCount(); ++faceIndex )
			{
				// The number of vertices of the current face.
				unsigned int faceVertexCount = mFaceVertexCountArray [ faceIndex ];

			}

			return edgeIndices;
		}


    };


}

#endif // __COLLADAFW_MESHPRIMITIVEWITHFACEVERTEXCOUNT_H__
