/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAFramework.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_POLY_BASE_H__
#define __COLLADAFW_POLY_BASE_H__

#include "COLLADAFWInputShared.h"


namespace COLLADAFW
{

    /**
    * The Polylist element provides the information needed to bind vertex attributes
    * together and  then organize those vertices into individual polygons. The
    * polygons described in Polylist can  contain arbitrary numbers of vertices.
    * Unlike the polygons element, the Polylist element cannot  contain polygons
    * with holes.
    */
    class PolyBase 
    {

    private:

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

    public:	

        /**
        * Constructor
        */
        PolyBase () 
            : mCount ( 0 )
        {}

        /**
        * Destructor
        */
        virtual ~PolyBase() {}

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
         * The input element may occur any number of times. This input is a 
         * local input with the  offset and set attributes.
         * @param inputArray The array with the input elements.
         */
        void setInputArray ( const InputSharedArray& inputArray ) 
        { 
            mInputArray = inputArray; 
        }

    };

}

#endif // __COLLADAFW_POLY_BASE_H__
