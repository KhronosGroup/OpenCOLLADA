/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAFramework.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_PH_ELEMENT_H__
#define __COLLADAFW_PH_ELEMENT_H__

#include "COLLADAFWPrimitiveBase.h"


namespace COLLADAFW
{

    /**
    * Describes a polygon that contains one or more holes.
    */
    class PHElement
    {

    private:  

        /**
         * Contains a list of UInts that specifies the vertex attributes (indices) for an 
         * individual polygon. Occures once in a ph element.
         */
        PElement mPElement;

        /**
         * Contains a list of unsigned ints that specifies the indices of a hole inthe polygon 
         * specified by <p>. Occures once or more in a ph element.
         */
        HArray mHArray;

        /**
         * Contains the number of primitives in the @mHArray array. 
         */
        size_t mHArraySize;

    public:

        /**
        * Constructor
        */
        PHElement () 
            : mHArray ( 0 )
        {}

        /**
        * Destructor
        */
        virtual ~PHElement() 
        {
            delete[] mHArray;
        }

        /**
        * Contains a list of UInts that specifies the vertex attributes (indices) for an 
        * individual polygon. Occures once in a ph element.
        */
        PElement& getPElement () { return mPElement; }
        const PElement& getPElement () const { return mPElement; }
        void setPElement ( const PElement& pElement ) { mPElement = pElement; }

        /**
        * Contains a list of unsigned ints that specifies the indices of a hole inthe polygon 
        * specified by <p>. Occures once or more in a ph element.
        * @param hArraySize The parameter to get the size of the returned array.
        * @return HArray& Reference to the ph array.
        */
        HArray& getHArray ( size_t& hArraySize ) 
        { 
            hArraySize = mHArraySize;
            return mHArray; 
        }

        /**
        * Contains a list of unsigned ints that specifies the indices of a hole inthe polygon 
        * specified by <p>. Occures once or more in a ph element.
        * @param hArraySize The parameter to get the size of the returned array.
        * @return HArray& Const reference to the ph array.
        */
        const HArray& getHArray ( size_t& hArraySize ) const 
        { 
            hArraySize = mHArraySize;
            return mHArray; 
        }

        /**
        * Contains a list of unsigned ints that specifies the indices of a hole inthe polygon 
        * specified by <p>. Occures once or more in a ph element.
        * @param hArray Reference to the ph array.
        * @param hArraySize The parameter to get the size of the returned array.
        */
        void setHArray ( const HArray& hArray, const size_t hArraySize  ) 
        { 
            mHArraySize = hArraySize;
            mHArray = hArray; 
        }

    };

    /**
     * Array of ph elements.
     */
    typedef PHElement* PHArray;
}


#endif // __COLLADAFW_PH_ELEMENT_H__
