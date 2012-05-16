/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_ACCESSOR_H__
#define __COLLADASAXFWL_ACCESSOR_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADAFWParam.h"

#include "COLLADABUURI.h"


namespace COLLADASaxFWL
{

    /** 
     * Describes a stream of values from an array data source.
     * The <accessor> element declares an access pattern into one of the array elements 
     * <float_array>, <int_array>, <Name_array>, <bool_array>, and <IDREF_array> or into an 
     * external array source. The arrays can be organized in either an interleaved or 
     * noninterleaved manner, depending on the offset and stride attributes.
     * The output of the accessor is described by its child <param> elements.
     */
    class Accessor
    {

    private:

        /**
         *  The number of times the array is accessed. Required.
         */
        unsigned int mCount; 

        /**
         * The index of the first value to be read from the array. The default is 0. Optional.
         */
        unsigned int mOffset; 

        /**
         * The location of the array to access using a URI expression. Required. This element may
         * refer to a COLLADA array element or to an array data source outside the scope of the
         * instance document; the source does not need to be a COLLADA document.
         */
        COLLADABU::URI mSource;

        /**
         * The number of values that are to be considered a unit during each access to the array.
         * The default is 1, indicating that a single value is accessed. Optional.
         */
        unsigned int mStride; 

        /**
         * The type attribute of the <param> element, when it is a child of the <accessor> element, 
         * is restricted to the set of array types: int, float, Name, bool, and IDREF. 
         */
        COLLADAFW::ParamArray mParamArray;

    public:

        /** Constructor. */
        Accessor () {}

        /** Destructor. */
        virtual ~Accessor () {}

        /**
        *  The number of times the array is accessed. Required.
        */
        const unsigned int getCount () const { return mCount; }
        void setCount ( const unsigned int count ) { mCount = count; }

        /**
        * The index of the first value to be read from the array. The default is 0. Optional.
        */
        const unsigned int getOffset () const { return mOffset; }
        void setOffset ( const unsigned int offset ) { mOffset = offset; }

        /**
        * The location of the array to access using a URI expression. Required. This element may
        * refer to a COLLADA array element or to an array data source outside the scope of the
        * instance document; the source does not need to be a COLLADA document.
        */
        const COLLADABU::URI getSource () const { return mSource; }
        void setSource ( const COLLADABU::URI source ) { mSource = source; }

        /**
        * The number of values that are to be considered a unit during each access to the array.
        * The default is 1, indicating that a single value is accessed. Optional.
        */
        const unsigned int getStride () const { return mStride; }
        void setStride ( const unsigned int stride ) { mStride = stride; }

        /**
        * The type attribute of the <param> element, when it is a child of the <accessor> element, 
        * is restricted to the set of array types: int, float, Name, bool, and IDREF. 
        */
        const COLLADAFW::ParamArray getParamArray () const { return mParamArray; }

        /**
        * The type attribute of the <param> element, when it is a child of the <accessor> element, 
        * is restricted to the set of array types: int, float, Name, bool, and IDREF. 
        */
        void setParamArray ( const COLLADAFW::ParamArray paramArray ) 
        { 
            mParamArray = paramArray; 
        }

    };
}

#endif // __COLLADASAXFWL_ACCESSOR_H__
