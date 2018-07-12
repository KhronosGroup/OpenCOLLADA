/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADASaxFrameworkLoader.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_PH_ELEMENT_H__
#define __COLLADASAXFWL_PH_ELEMENT_H__

#include "COLLADASaxFWLPrimitiveBase.h"


namespace COLLADASaxFWL
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

    public:

        /**
        * Constructor
        */
        PHElement () {}

        /**
        * Destructor
        */
        virtual ~PHElement() {}

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
        * @return HArray& Reference to the ph array.
        */
        HArray& getHArray () 
        { 
            return mHArray; 
        }

        /**
        * Contains a list of unsigned ints that specifies the indices of a hole inthe polygon 
        * specified by <p>. Occures once or more in a ph element.
        * @return HArray& Const reference to the ph array.
        */
        const HArray& getHArray () const 
        { 
            return mHArray; 
        }

        /**
        * Contains a list of unsigned ints that specifies the indices of a hole inthe polygon 
        * specified by <p>. Occures once or more in a ph element.
        * @param hArray Reference to the ph array.
        */
        void setHArray ( const HArray& hArray ) 
        { 
            mHArray = hArray; 
        }

    };

    /**
     * Array of ph elements.
     */
    typedef COLLADAFW::ArrayPrimitiveType<PHElement*> PHArray;
}


#endif // __COLLADASAXFWL_PH_ELEMENT_H__
