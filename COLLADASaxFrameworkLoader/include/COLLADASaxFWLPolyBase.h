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

#include "COLLADAFWPrimitiveElement.h"


namespace COLLADASaxFWL
{

    class MeshLoader;


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
         * The parent element (TODO mesh, convex_mesh or spline).
         */
        MeshLoader* mParent;

        /** 
        * The type of the current primitive. Possible values are:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. 
        */
        COLLADAFW::PrimitiveElement::PrimitiveType mPrimitiveType;

        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        String mName;

        /**
        * The count attribute indicates the number of polygon primitives. 
        * Required attribute. 
        */
        size_t mCount;

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
        PolyBase ( MeshLoader* parent ) 
            : mPrimitiveType ( COLLADAFW::PrimitiveElement::UNDEFINED_PRIMITIVE_TYPE )
            , mParent ( parent ) 
            , mCount (0)
            , mInputArrayMaxOffset (0)
        {}

        /**
        * Constructor
        */
        PolyBase ( MeshLoader* parent, COLLADAFW::PrimitiveElement::PrimitiveType primitiveType ) 
            : mPrimitiveType ( primitiveType )
            , mParent ( parent ) 
            , mCount (0)
            , mInputArrayMaxOffset (0)
        {}

        /**
        * Destructor
        */
        virtual ~PolyBase() {}

        /** The type of the current primitive. Possible values are:
        <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. */
        const COLLADAFW::PrimitiveElement::PrimitiveType getPrimitiveType () const { return mPrimitiveType; }

        /** The type of the current primitive. Possible values are:
        <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. */
        void setPrimitiveType ( const COLLADAFW::PrimitiveElement::PrimitiveType primitiveType ) { mPrimitiveType = primitiveType; }

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
        size_t getCount () const { return mCount; }

        /**
        * Sets the count attribute.
        * @param atCount The new value for the count attribute.
        */
        void setCount ( size_t count ) { mCount = count; }

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
        const InputShared* appendInputElement ( InputShared* inputShared )
        {
            if ( inputShared != 0 )
            {
                unsigned int offset = inputShared->getOffset ();
                if ( offset > mInputArrayMaxOffset ) mInputArrayMaxOffset = offset;
                return mInputArray.append ( inputShared );
            }
            return 0;
        }

        /**
        * The input element may occur any number of times. This input is a 
        * local input with the  offset and set attributes.
        * @return const InputArray The array with the input elements.
        */
        const size_t getInputArrayMaxOffset () const 
        {
            return mInputArrayMaxOffset;
        }

        /**
         * The input element may occur any number of times. This input is a 
         * local input with the  offset and set attributes.
         * @param inputArray The array with the input elements.
         * @param maxOffset The maximal offset in the current input array.
         */
        void setInputArray ( const InputSharedArray& inputArray, const unsigned int maxOffset ) 
        { 
            mInputArray = inputArray; 
            mInputArrayMaxOffset = maxOffset;
        }

        /**
        * Returns the input element with the given semantic or 0 if it not exist.
        * @param semantic The semantic of the searched input element.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getInputBySemantic ( 
            const InputSemantic::Semantic& semantic, 
            const bool parent = false ) const;

        /**
        * Returns the positions input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getPositionInput ( const bool parent = true ) const
        {
            return getInputBySemantic ( InputSemantic::POSITION, parent );
        }

        /**
        * Returns the normals input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getNormalInput ( const bool parent = true ) const
        {
            return getInputBySemantic ( InputSemantic::NORMAL, parent );
        }

        /**
        * Returns the colors input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getColorInput ( const bool parent = true ) const
        {
            return getInputBySemantic ( InputSemantic::COLOR, parent );
        }

        /**
        * Returns the uv coordinates input element or 0 if it not exist.
        * @param parent True, if the vertex element of the parent mesh should also searched.
        * @return InputShared* Pointer to the searched input element or 0 if it not exist.
        */
        const InputShared* getUVCoordInput ( const bool parent = true ) const
        {
            return getInputBySemantic ( InputSemantic::UV, parent );
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
