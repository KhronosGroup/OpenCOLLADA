/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SOURCE_H__
#define __COLLADAFW_SOURCE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWArrayElement.h"


namespace COLLADAFW
{

    /** 
     * Declares a data repository that provides values according to the 
     * semantics of an <input> element that refers to it. 
     * A data source is a well-known source of information that can be accessed 
     * through an established communication channel.
     * The data source provides access methods to the information. These access 
     * methods implement various techniques according to the representation of 
     * the information. The information may be stored locally as an array of 
     * data or a program that generates the data.
     */
    class Source
    {

    private:
        
        /** 
         * A text string containing the unique identifier of the element. This value must be unique
         * within the instance document. Required.
         */
        String mSourceId;

        /** 
         * The text string name of this element. Optional.
         */
        String mSourceName;

        /**
         * Stores a homogenous array of values.
         * The class contains members for all valid array element types, 
         * but there is always just one, which is initialised.
         */
        IntArrayElement mIntArrayElement;

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        */
        FloatArrayElement mFloatArrayElement;

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        */
        BoolArrayElement mBoolArrayElement;

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        */
        NameArrayElement mNameArrayElement;

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        */
        IDREFArrayElement mIDREFArrayElement;

        /** The id of the array*/
        String mArrayId;

        /** The value of the count attribute of the accessor*/
        unsigned long mAccessorCount;

        /** The value of the stride attribute of the accessor*/
        unsigned long mAccessorStride;

    public:

        /** Constructor. */
        Source () {}

        /** Destructor. */
        virtual ~Source () {}

        /** 
        * A text string containing the unique identifier of the element. This value must be unique
        * within the instance document. Required.
        */
        const String& getSourceId () const { return mSourceId; }
        void setSourceId ( const String val ) { mSourceId = val; }

        /** 
        * The text string name of this element. Optional.
        */
        const String& getSourceName () const { return mSourceName; }
        void setSourceName ( const String val ) { mSourceName = val; }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IntArrayElement The array element with the values array.
        */
        const IntArrayElement getIntArrayElement () const { return mIntArrayElement; }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setIntArrayElement ( const IntArrayElement arrayElement ) { mIntArrayElement = arrayElement; }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const BoolArrayElement The array element with the values array.
        */
        const BoolArrayElement getBoolArrayElement () const 
        { 
            return mBoolArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setBoolArrayElement ( const BoolArrayElement arrayElement ) 
        { 
            mBoolArrayElement = arrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const FloatArrayElement The array element with the values array.
        */
        const FloatArrayElement getFloatArrayElement () const 
        { 
            return mFloatArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setFloatArrayElement ( const FloatArrayElement arrayElement ) 
        { 
            mFloatArrayElement = arrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const NameArrayElement The array element with the values array.
        */
        const NameArrayElement getNameArrayElement () const 
        { 
            return mNameArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setNameArrayElement ( const NameArrayElement arrayElement ) 
        { 
            mNameArrayElement = arrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IDREFArrayElement The array element with the values array.
        */
        const IDREFArrayElement getIDREFArrayElement () const 
        { 
            return mIDREFArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setIDREFArrayElement ( const IDREFArrayElement arrayElement ) 
        { 
            mIDREFArrayElement = arrayElement; 
        }

    };


    typedef Source* SourceArray;

}

#endif // __COLLADAFW_LALA_H__