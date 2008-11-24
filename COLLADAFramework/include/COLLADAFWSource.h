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
#include "COLLADAFWTechniqueCommon.h"


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
        String mId;

        /** 
         * The text string name of this element. Optional.
         */
        String mName;

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
        DoubleArrayElement mDoubleArrayElement;

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

        /**
         * Specifies source information for the common profile that all COLLADA implementations 
         * must support. 
         */
        TechniqueCommon mTechniqueCommon;

    public:

        /** Constructor. */
        Source () {}

        /** Destructor. */
        virtual ~Source () {}

        /** 
        * A text string containing the unique identifier of the element. 
        * This value must be unique within the instance document. Required.
        * @return const String& The unique identifier of the element. 
        */
        const String& getId () const { return mId; }

        /**
         * A text string containing the unique identifier of the element. 
         * This value must be unique within the instance document. Required.
         * @param val The unique identifier of the element. 
         */
        void setId ( const String& val ) { mId = val; }

        /** 
        * The text string name of this element. Optional.
        * @return The text string name of this element. 
        */
        const String& getName () const { return mName; }

        /**
         * The text string name of this element. Optional.
         * @param val The text string name of this element.
         */
        void setName ( const String& val ) { mName = val; }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IntArrayElement The array element with the values array.
        */
        IntArrayElement& getIntArrayElement () { return mIntArrayElement; }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IntArrayElement The array element with the values array.
        */
        const IntArrayElement& getIntArrayElement () const { return mIntArrayElement; }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setIntArrayElement ( const IntArrayElement& arrayElement ) { mIntArrayElement = arrayElement; }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const BoolArrayElement The array element with the values array.
        */
        BoolArrayElement& getBoolArrayElement () 
        { 
            return mBoolArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const BoolArrayElement The array element with the values array.
        */
        const BoolArrayElement& getBoolArrayElement () const 
        { 
            return mBoolArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setBoolArrayElement ( const BoolArrayElement& arrayElement ) 
        { 
            mBoolArrayElement = arrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const FloatArrayElement The array element with the values array.
        */
        const FloatArrayElement& getFloatArrayElement () const 
        { 
            return mFloatArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const FloatArrayElement The array element with the values array.
        */
        FloatArrayElement& getFloatArrayElement () 
        { 
            return mFloatArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setFloatArrayElement ( const FloatArrayElement& arrayElement ) 
        { 
            mFloatArrayElement = arrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const FloatArrayElement The array element with the values array.
        */
        const DoubleArrayElement& getDoubleArrayElement () const 
        { 
            return mDoubleArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const FloatArrayElement The array element with the values array.
        */
        DoubleArrayElement& getDoubleArrayElement () 
        { 
            return mDoubleArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setDoubleArrayElement ( const DoubleArrayElement& arrayElement ) 
        { 
            mDoubleArrayElement = arrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const NameArrayElement The array element with the values array.
        */
        NameArrayElement& getNameArrayElement () 
        { 
            return mNameArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const NameArrayElement The array element with the values array.
        */
        const NameArrayElement& getNameArrayElement () const 
        { 
            return mNameArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setNameArrayElement ( const NameArrayElement& arrayElement ) 
        { 
            mNameArrayElement = arrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IDREFArrayElement The array element with the values array.
        */
        IDREFArrayElement& getIDREFArrayElement () 
        { 
            return mIDREFArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IDREFArrayElement The array element with the values array.
        */
        const IDREFArrayElement& getIDREFArrayElement () const 
        { 
            return mIDREFArrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        void setIDREFArrayElement ( const IDREFArrayElement& arrayElement ) 
        { 
            mIDREFArrayElement = arrayElement; 
        }

        /**
         * Specifies source information for the common profile that all COLLADA implementations 
         * must support. 
         * @return const COLLADAFW::TechniqueCommon&
         */
        const COLLADAFW::TechniqueCommon& getTechniqueCommon () const { return mTechniqueCommon; }

        /**
        * Specifies source information for the common profile that all COLLADA implementations 
        * must support. 
        * @return const COLLADAFW::TechniqueCommon&
        */
        COLLADAFW::TechniqueCommon& getTechniqueCommon () { return mTechniqueCommon; }

        /**
         * Specifies source information for the common profile that all COLLADA implementations 
         * must support. 
         * @param techniqueCommon The technique common element.
         */
        void setTechniqueCommon ( const COLLADAFW::TechniqueCommon techniqueCommon ) 
        { 
            mTechniqueCommon = techniqueCommon; 
        }

    };


    typedef Source* SourceArray;

}

#endif // __COLLADAFW_LALA_H__