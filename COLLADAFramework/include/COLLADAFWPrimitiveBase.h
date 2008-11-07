/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_PRIMITIVE_BASE_H__
#define __COLLADAFW_PRIMITIVE_BASE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWConstants.h"


namespace COLLADAFW
{

    /** 
     * Base class for the primitives. This are the p and h elements.  
     * The indices in a <p> (“primitive”) (or <h>) element refer to different inputs depending on 
     * their order. The first index in a <p> element refers to all inputs with an offset of 0. The 
     * second index refers to all inputs with an offset of 1. Each vertex of the polygon is made 
     * up of one index into each input. After each input is used, the next index again refers to 
     * the inputs with offset of 0 and begins a new vertex.
     * The winding order of vertices produced is counter-clockwise and describes the front side of 
     * each polygon. If the primitives are assembled without vertex normals then the application 
     * may generate per-primitive normals to enable lighting.
     */
    class PrimitiveBase
    {

    private:

        /**
         * Contains a list of unsigned ints that specifies the vertex attributes (indices) for an 
         * individual polygon or for a hole in a polygon.
         */
        UIntValuesArray mUIntValuesArray;

        /**
         * The number of unsigned int values in the values array.
         */
        size_t mUIntValuesArraySize;

    public:

        /** Constructor. */
        PrimitiveBase () 
            : mUIntValuesArray ( 0 ) 
        {}

        /** Destructor. */
        virtual ~PrimitiveBase () 
        {
            delete[] mUIntValuesArray; 
        }

        /**
         * Contains a list of unsigned ints that specifies the vertex attributes (indices) for an 
         * individual polygon or for a hole in a polygon.
         * @param valuesArraySize The size parameter of the returned array.
         * @return const PrimitiveBase::ValuesArray& Reference to the values array.
         */
        const UIntValuesArray& getUIntValuesArray ( size_t& valuesArraySize ) const 
        { 
            valuesArraySize = mUIntValuesArraySize;
            return mUIntValuesArray; 
        }

        /**
         * Contains a list of unsigned ints that specifies the vertex attributes (indices) for an 
         * individual polygon or for a hole in a polygon.
         * @param valuesArraySize The size parameter of the returned array.
         * @return const PrimitiveBase::ValuesArray& Reference to the values array.
         */
        UIntValuesArray& getUIntValuesArray ( size_t& valuesArraySize ) 
        { 
            valuesArraySize = mUIntValuesArraySize;
            return mUIntValuesArray; 
        }

        /**
         * Contains a list of unsigned ints that specifies the vertex attributes (indices) for an 
         * individual polygon or for a hole in a polygon.
         * @param valuesArray Reference to the values array.
         * @param valuesArraySize The size parameter of the values array.
         */
        void setUIntValuesArray ( 
            const UIntValuesArray& valuesArray, 
            const size_t valuesArraySize ) 
        {
            mUIntValuesArraySize = valuesArraySize;
            mUIntValuesArray = valuesArray; 
        }

    };


    /**
     * The p element for the polygon vertex attribute indices.
     */
    typedef PrimitiveBase PElement;
    typedef PElement* PArray;

    /**
    * The h element for the polygons hole vertex attribute indices.
    */
    typedef PrimitiveBase HElement;
    typedef HElement* HArray;

}

#endif // __COLLADAFW_PRIMITIVE_BASE_H__