/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADASaxFrameworkLoader.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_POLY_BASE_H__
#define __COLLADASAXFWL_POLY_BASE_H__

#include "COLLADASaxFWLPrimitiveBase.h"
#include "COLLADASaxFWLInputShared.h"

#include "COLLADAFWMeshPrimitive.h"


namespace COLLADASaxFWL
{

    class MeshLoader;
	class Vertices;


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
    class PolyBase 
    {

    private:

        /** 
        * The type of the current primitive. Possible values are:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. 
        */
        COLLADAFW::MeshPrimitive::PrimitiveType mPrimitiveType;

        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        String mName;

        /**
        * The attribute indicates the number of polygon faces in the current primitive element.
        */
        size_t mFaceCount;

        /**
         * The number of all indices in all p elements in the current primitive element.
         */
        size_t mIndexCount;

        /**
        * The material attribute declares a symbol for a material. This symbol 
        * is bound to a material at  the time of instantiation. If the material 
        * attribute is not specified then the lighting and  shading results are 
        * application defined. Optional attribute. 
        */
        String mMaterial;

        /**
        * The input element may occur any number of times. This input is a local
        * input with the  offset and set attributes. 
        */
        InputSharedArray mInputArray;

        /**
         * The maximal offset value in the input element.
         */
        unsigned int mInputArrayMaxOffset;
	
		Vertices& mVertices;


        /**
        * Contains a array of integers that specify the vertex attributes
        * (indices) for an individual Polylist ("p" stands for "primitive").
        * The p element may occur not or more. 
        */
        PArray mPArray;

    public:	

        /**
        * Constructor
        */
        PolyBase ( Vertices& vertices ) 
            : mPrimitiveType ( COLLADAFW::MeshPrimitive::UNDEFINED_PRIMITIVE_TYPE )
            , mFaceCount (0)
            , mInputArrayMaxOffset (0)
            , mIndexCount (0)
			, mVertices(vertices)
        {}

        /**
        * Constructor
        */
 /*       PolyBase ( MeshLoader* parent, COLLADAFW::MeshPrimitive::PrimitiveType primitiveType ) 
            : mPrimitiveType ( primitiveType )
            , mFaceCount (0)
            , mInputArrayMaxOffset (0)
            , mIndexCount (0)
        {}
*/
        /**
        * Destructor
        */
        virtual ~PolyBase() {}

        /**
        * The number of all indices in all p elements in the current primitive element.
        */
        const size_t getIndexCount () const { return mIndexCount; }

        /**
        * The number of all indices in all p elements in the current primitive element.
        */
        void setIndexCount ( const size_t indexCount ) { mIndexCount = indexCount; }

        /** The type of the current primitive. Possible values are:
        <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. */
        const COLLADAFW::MeshPrimitive::PrimitiveType getPrimitiveType () const { return mPrimitiveType; }

        /** The type of the current primitive. Possible values are:
        <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. */
        void setPrimitiveType ( const COLLADAFW::MeshPrimitive::PrimitiveType primitiveType ) { mPrimitiveType = primitiveType; }

        /**
        * Gets the name attribute.
        * @return Returns a xsNCName of the name attribute.
        */
        const String& getName () const { return mName; }

        /**
        * Sets the name attribute.
        * @param atName The new value for the name attribute.
        */
        void setName ( const String& name ) { mName = name; }

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
         * The input element may occur any number of times. This input is a 
         * local input with the  offset and set attributes.
         * @return const InputArray The array with the input elements.
         */
        const InputSharedArray& getInputArray () const 
        {
            return mInputArray; 
        }

        /**
         * Appends an input element in the list of input elements. 
         * Handle with care, new memory will be allocated!
         */
        const InputShared* appendInputElement ( InputShared* inputShared );

        /**
        * The input element may occur any number of times. This input is a 
        * local input with the  offset and set attributes.
        * @return const InputArray The array with the input elements.
        */
        const size_t getInputArrayMaxOffset () const 
        {
            return mInputArrayMaxOffset;
        }

//         /**
//          * The input element may occur any number of times. This input is a 
//          * local input with the  offset and set attributes.
//          * @param inputArray The array with the input elements.
//          * @param maxOffset The maximal offset in the current input array.
//          */
//         void setInputArray ( const InputSharedArray& inputArray, const unsigned int maxOffset ) 
//         { 
//             mInputArray = inputArray; 
//             mInputArrayMaxOffset = maxOffset;
//         }

        /**
        * Returns the input element with the given semantic or 0 if it not exist.
        * @param semantic The semantic of the searched input element.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getInputBySemantic ( const InputSemantic::Semantic& semantic ) const;

        /**
        * Returns the positions input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getPositionInput () const
        {
            return getInputBySemantic ( InputSemantic::POSITION );
        }

        /**
        * Returns the normals input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getNormalInput () const
        {
            return getInputBySemantic ( InputSemantic::NORMAL );
        }

        /**
        * Returns the colors input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getColorInput () const
        {
            return getInputBySemantic ( InputSemantic::COLOR );
        }

        /**
        * Returns the uv coordinates input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getUVCoordInput () const
        {
            return getInputBySemantic ( InputSemantic::UV );
        }

        /**
        * Contains a array of integers that specify the vertex attributes
        * (indices) for an individual Polylist ("p" stands for "primitive").
        * The p element may occur not or more. 
        * @return PArray& Reference to the ph array.
        */
        PArray& getPArray () 
        { 
            return mPArray; 
        }

        /**
        * Contains a array of integers that specify the vertex attributes
        * (indices) for an individual Polylist ("p" stands for "primitive").
        * The p element may occur not or more. 
        * @return PArray& Const reference to the ph array.
        */
        const PArray& getPArray () const 
        { 
            return mPArray; 
        }

        /**
        * Contains a array of integers that specify the vertex attributes
        * (indices) for an individual Polylist ("p" stands for "primitive").
        * The p element may occur not or more. 
        * @param pArray Reference to the ph array.
        * @param pArraySize The parameter to get the size of the returned array.
        */
        void setPArray ( const PArray& pArray ) 
        { 
            mPArray = pArray; 
        }

    };

    
    typedef COLLADAFW::ArrayPrimitiveType<PolyBase*> PolyBaseArray;

}

#endif // __COLLADASAXFWL_POLY_BASE_H__
