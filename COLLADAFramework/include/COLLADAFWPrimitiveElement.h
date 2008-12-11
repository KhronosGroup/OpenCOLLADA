/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAFramework.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_POLY_BASE_H__
#define __COLLADAFW_POLY_BASE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWConstants.h"


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
    class PrimitiveElement
    {

    public:

        /** The types of primitives. */
	    enum PrimitiveType
	    {
		    LINES, /**< A list of lines. Only one element is contained in the face-vertex count list.
			    It represents the total number of line vertices. The total number of lines is
			    equal to half the total number of line vertices. */
		    LINE_STRIPS, /**< A list of continuous lines. Each element in the face-vertex count list
			    represents the number of consecutive line vertices before restarting. */
		    POLYGONS, /**< A list of polygons. All the polygons may be triangles.
			    This is the most common primitive type. The polygons may have holes. Each element in the
			    face-vertex count list represent the number of vertices for one polygon. */
            POLYLIST,
            TRIANGLES, 
		    TRIANGLE_FANS, /**< A list of triangle fans. Each element in the face-vertex count list
			    represents the number of vertices for one fan. A triangle fan is defined by re-using the first
			    vertex for every triangle. Advancing pairs are then used in order to generate adjacent triangles
			    such that if there are 5 vertices, then 3 triangles are created: {0,1,2}, {0,2,3} and {0,3,4}. */
		    TRIANGLE_STRIPS, /**< A list of continuous triangles. Each element in the face-vertex count list
			    represents the number of vertices for one strip. A triangle strip is defined by re-using two
			    advancing vertices from the previous triangle for the next triangle. If there are 5 vertices in 
			    the strip, then 3 triangles are created: {0,1,2}, {1,2,3}, {2,3,4}. Note that vertex winding must
			    also be taken into consideration and every even triangle in the strip has its vertices swapped
			    from the above pattern. */
		    POINTS, /**< A list of Camera-facing sprites. The face-vertex count list will contain one element that 
			    represents the total number of points. Two non-COLLADA geometry sources (POINT_SIZE and POINT_ROTATION)
			    are specific to this type. */
            UNDEFINED_PRIMITIVE_TYPE
	    };

    private:

        /** 
        * The type of the current primitive. Possible values are:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. 
        */
        PrimitiveType mPrimitiveType;

        /**
        * The attribute indicates the number of polygon faces in the current primitive element.
        */
        size_t mFaceCount;

        /**
         * Contains a list of integers, each specifying the number of vertices for one polygon face.
         */
        UIntValuesArray mFaceVertexCountArray;

        /**
        * The material attribute declares a symbol for a material. This symbol 
        * is bound to a material at  the time of instantiation. If the material 
        * attribute is not specified then the lighting and  shading results are 
        * application defined. Optional attribute. 
        */
        String mMaterial;

        /** 
        * The index list of the positions array. 
        */
        UIntValuesArray mPositionIndices;

        /** 
        * The index list of the normals array. 
        */
        UIntValuesArray mNormalIndices;

        /** 
        * The index list of the colors array. 
        */
        UIntValuesArray mColorIndices;

        /** 
        * The index list of the uv coordinates array. 
        */
        UIntValuesArray mUVCoordIndices;

        /**
         * The index list of the edges ( the index list is referencing on the position indices )
         */
        UIntValuesArray mEdgeIndices;

    public:	

        /**
        * Constructor.
        */
        PrimitiveElement () 
            : mPrimitiveType ( UNDEFINED_PRIMITIVE_TYPE )
            , mFaceCount ( 0 )
        {}

        /**
        * Constructor.
        */
        PrimitiveElement ( PrimitiveType primitiveType ) 
            : mPrimitiveType ( primitiveType )
            , mFaceCount ( 0 )
        {}

        /**
        * Destructor.
        */
        virtual ~PrimitiveElement() {}

        /** The type of the current primitive. Possible values are:
        <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. */
        const PrimitiveElement::PrimitiveType getPrimitiveType () const { return mPrimitiveType; }

        /** The type of the current primitive. Possible values are:
        <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. */
        void setPrimitiveType ( const PrimitiveElement::PrimitiveType PrimitiveType ) { mPrimitiveType = PrimitiveType; }

        /**
        * Gets the count attribute.
        * @return Returns a domUint of the count attribute.
        */
        const size_t getFaceCount () const { return mFaceCount; }

        /**
        * Sets the count attribute.
        * @param atCount The new value for the count attribute.
        */
        void setFaceCount ( const size_t count ) { mFaceCount = count; }

        /**
        * Contains a list of integers, each specifying the number of vertices for one polygon face.
        */
        COLLADAFW::UIntValuesArray& getFaceVertexCountArray () { return mFaceVertexCountArray; }

        /**
        * Contains a list of integers, each specifying the number of vertices for one polygon face.
        */
        const COLLADAFW::UIntValuesArray& getFaceVertexCountArray () const { return mFaceVertexCountArray; }

        /**
        * Contains a list of integers, each specifying the number of vertices for one polygon face.
        */
        void setFaceVertexCountArray ( const COLLADAFW::UIntValuesArray& FaceVertexCountArray ) { mFaceVertexCountArray = FaceVertexCountArray; }

        /**
        * Gets the material attribute.
        * @return Returns a xsNCName of the material attribute.
        */
        String getMaterial () const { return mMaterial; }

        /**
        * Sets the material attribute.
        * @param atMaterial The new value for the material attribute.
        */
        void setMaterial ( const String& material ) { mMaterial = material; }

        /** 
        * The index list of the positions array. 
        */
        COLLADAFW::UIntValuesArray& getPositionIndices () { return mPositionIndices; }

        /** 
        * The index list of the positions array. 
        */
        void setPositionIndices ( const COLLADAFW::UIntValuesArray& PositionIndices ) { mPositionIndices = PositionIndices; }

        /** 
        * The index list of the normals array. 
        */
        COLLADAFW::UIntValuesArray& getNormalIndices () { return mNormalIndices; }

        /** 
        * The index list of the normals array. 
        */
        void setNormalIndices ( const COLLADAFW::UIntValuesArray& NormalIndices ) { mNormalIndices = NormalIndices; }

        /** 
        * The index list of the colors array. 
        */
        COLLADAFW::UIntValuesArray& getColorIndices () { return mColorIndices; }

        /** 
        * The index list of the colors array. 
        */
        void setColorIndices ( const COLLADAFW::UIntValuesArray& ColorIndices ) { mColorIndices = ColorIndices; }

        /** 
        * The index list of the uv coordinates array. 
        */
        COLLADAFW::UIntValuesArray& getUVCoordIndices () { return mUVCoordIndices; }

        /** 
        * The index list of the uv coordinates array. 
        */
        void setUVCoordIndices ( const COLLADAFW::UIntValuesArray& UVCoordIndices ) { mUVCoordIndices = UVCoordIndices; }

        /**
        * The index list of the edges ( the index list is referencing on the position indices )
        */
        COLLADAFW::UIntValuesArray& getEdgeIndices () { return mEdgeIndices; }

        /**
        * The index list of the edges ( the index list is referencing on the position indices )
        */
        void setEdgeIndices ( const COLLADAFW::UIntValuesArray& EdgeIndices ) { mEdgeIndices = EdgeIndices; }

        /**
        * Initialize the index list of the edges ( the index list is referencing on the position indices )
        */
        COLLADAFW::UIntValuesArray& initializeEdgeIndices ( COLLADAFW::UIntValuesArray& edgeIndices )
        {
            // TODO Create the edges... Geht nicht mehr, bin platt, denken klappt heut nicht mehr, sorry!

            // Go through the list of faces and write the edge indices for every face.
            for ( size_t faceIndex=0; faceIndex<mFaceCount; ++faceIndex )
            {
                // The number of vertices of the current face.
                unsigned int faceVertexCount = mFaceVertexCountArray [ faceIndex ];
                
            }

            return edgeIndices;
        }

    };

    
    typedef ArrayPrimitiveType<PrimitiveElement*> PrimitiveElementsArray;

}

#endif // __COLLADAFW_POLY_BASE_H__
