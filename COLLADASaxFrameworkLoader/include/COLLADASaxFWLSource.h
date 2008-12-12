/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SOURCE_H__
#define __COLLADASAXFWL_SOURCE_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLTechniqueCommon.h"
#include "COLLADASaxFWLArrayElement.h"

#include "COLLADAFWObject.h"
#include "COLLADAFWArray.h"


namespace COLLADASaxFWL
{

    /**
     * Base source class for hold source element pointers in an array.
     */
    class SourceBase : public COLLADAFW::ObjectTemplate<COLLADAFW::COLLADA_TYPE::SOURCE>
    {

    public:

        enum DataType
        {
            DATA_TYPE_INT, 
            DATA_TYPE_LONG64, 
            DATA_TYPE_FLOAT,
            DATA_TYPE_DOUBLE,
            DATA_TYPE_BOOL,
            DATA_TYPE_NAME,
            DATA_TYPE_IDREF,
            DATA_TYPE_UNKNOWN
        };

    private:

        /** 
        * A text string containing the unique identifier of the element. This value must be unique
        * within the instance document. Required.
        */
        String mId;

        /**
        * The value type of the current values. 
        */
        DataType mDataType;

        /**
        * The number of values that are to be considered a unit during each access to the array.
        * The default is 1, indicating that a single value is accessed. Optional.
        */
        unsigned int mStride; 

        /**
         * Flag, if the source element is already loaded into the framework.
         */
        bool mIsLoaded;

        /**
         * This member will be used, if multiple source elements with the same input semantic are
         * referenced in the current mesh. 
         * The sources of semantic "POSITION" and "NORMAL" will be concated to one source and 
         * and one indices array.
         */
        size_t mInitialIndex;

    public:

//         /** Constructor. */
//         SourceBase ( COLLADAFW::ObjectId objectId )
//             : COLLADAFW::Object < COLLADAFW::COLLADA_TYPE::SOURCE > ( objectId )
//             , mDataType ( DATA_TYPE_UNKNOWN )
//             , mIsLoaded ( false )
//             , mInitialIndex (0)
//         {}

        /** Constructor. */
        SourceBase (  COLLADAFW::ObjectId objectId, DataType valueType )
            : COLLADAFW::ObjectTemplate < COLLADAFW::COLLADA_TYPE::SOURCE > ( objectId )
            , mDataType ( valueType )
            , mIsLoaded ( false )
            , mInitialIndex (0)
        {}

        /** Destructor. */
        virtual ~SourceBase () {}

        /**
        * Flag, if the source element is already loaded into the framework.
        */
        const bool getIsLoaded () const { return mIsLoaded; }

        /**
        * Flag, if the source element is already loaded into the framework.
        */
        void setIsLoaded ( const bool isLoaded ) { mIsLoaded = isLoaded; }

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
        * The value type of the current values. All other arrays are empty!
        */
        SourceBase::DataType& getDataType () { return mDataType; }

        /**
        * The value type of the current values. All other arrays are empty!
        */
        const SourceBase::DataType& getDataType () const { return mDataType; }

        /**
        * The value type of the current values. All other arrays are empty!
        */
        void setDataType ( const SourceBase::DataType& dataType ) { mDataType = dataType; }

        /**
        * The number of values that are to be considered a unit during each access to the array.
        * The default is 1, indicating that a single value is accessed. Optional.
        */
        const unsigned int getStride () const { return mStride; }

        /**
        * The number of values that are to be considered a unit during each access to the array.
        * The default is 1, indicating that a single value is accessed. Optional.
        */
        void setStride ( const unsigned int Stride ) { mStride = Stride; }

        /**
        * This member will be used, if multiple source elements with the same input semantic are
        * referenced in the current mesh. 
        * The sources of semantic "POSITION" and "NORMAL" will be concated to one source and 
        * and one indices array.
        */
        const size_t getInitialIndex () const { return mInitialIndex; }

        /**
        * This member will be used, if multiple source elements with the same input semantic are
        * referenced in the current mesh. 
        * The sources of semantic "POSITION" and "NORMAL" will be concated to one source and 
        * and one indices array.
        */
        void setInitialIndex ( const size_t InitialIndex ) { mInitialIndex = InitialIndex; }

    };

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
    template < class Type >
    class Source : public SourceBase
    {

    private:

        /**
        * Stores a homogenous array of values.
        */
        Type* mArrayElement;

    public:

        /** Constructor. */
        Source ( COLLADAFW::ObjectId objectId, SourceBase::DataType valueType ) 
            : SourceBase ( objectId, valueType ) 
            , mArrayElement (0)
        {}

        /** Destructor. */
        virtual ~Source () 
        {
            delete mArrayElement;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IntArrayElement The array element with the values array.
        */
        template < class Type >
        Type* getArrayElement () 
        {
            return mArrayElement;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IntArrayElement The array element with the values array.
        */
        template < class Type >
        const Type* getIntArrayElement () const 
        { 
            return mArrayElement;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @param arrayElement The array element with the values array.
        */
        template < class Type >
        void setArrayElement ( Type* arrayElement ) 
        { 
            mArrayElement = arrayElement; 
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IntArrayElement The array element with the values array.
        */
        IntArrayElement* getIntArrayElement () 
        {
            if ( getDataType () == SourceBase::DATA_TYPE_INT )
                return ( IntArrayElement* ) mArrayElement; 
            return 0;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IntArrayElement The array element with the values array.
        */
        const IntArrayElement* getIntArrayElement () const 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_INT )
                return ( IntArrayElement* ) mArrayElement; 
            return 0;
        }

//         /**
//         * Stores a homogenous array of values.
//         * The class contains members for all valid array element types, 
//         * but there is always just one, which is initialised.
//         * @param arrayElement The array element with the values array.
//         */
//         void setIntArrayElement ( const IntArrayElement& arrayElement ) 
//         { 
//             mIntArrayElement = arrayElement; 
//         }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IntArrayElement The array element with the values array.
        */
        Long64ArrayElement* getLong64ArrayElement () 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_LONG64 )
                return ( Long64ArrayElement* ) mArrayElement; 
            return 0;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IntArrayElement The array element with the values array.
        */
        const Long64ArrayElement* getLong64ArrayElement () const 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_LONG64 )
                return ( Long64ArrayElement* ) mArrayElement; 
            return 0;
        }

//         /**
//         * Stores a homogenous array of values.
//         * The class contains members for all valid array element types, 
//         * but there is always just one, which is initialised.
//         * @param arrayElement The array element with the values array.
//         */
//         void setLong64ArrayElement ( const Long64ArrayElement& arrayElement ) 
//         { 
//             mLong64ArrayElement = arrayElement; 
//         }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const BoolArrayElement The array element with the values array.
        */
        BoolArrayElement* getBoolArrayElement () 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_BOOL )
                return ( BoolArrayElement* ) mArrayElement; 
            return 0;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const BoolArrayElement The array element with the values array.
        */
        const BoolArrayElement* getBoolArrayElement () const 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_BOOL )
                return ( BoolArrayElement* ) mArrayElement; 
            return 0;
        }

//         /**
//         * Stores a homogenous array of values.
//         * The class contains members for all valid array element types, 
//         * but there is always just one, which is initialised.
//         * @param arrayElement The array element with the values array.
//         */
//         void setBoolArrayElement ( const BoolArrayElement& arrayElement ) 
//         { 
//             mBoolArrayElement = arrayElement; 
//         }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const FloatArrayElement The array element with the values array.
        */
        const FloatArrayElement* getFloatArrayElement () const 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_FLOAT )
                return ( FloatArrayElement* ) mArrayElement; 
            return 0;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const FloatArrayElement The array element with the values array.
        */
        FloatArrayElement* getFloatArrayElement () 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_FLOAT )
                return ( FloatArrayElement* ) mArrayElement; 
            return 0;
        }

//         /**
//         * Stores a homogenous array of values.
//         * The class contains members for all valid array element types, 
//         * but there is always just one, which is initialised.
//         * @param arrayElement The array element with the values array.
//         */
//         void setFloatArrayElement ( const FloatArrayElement& arrayElement ) 
//         { 
//             mFloatArrayElement = arrayElement; 
//         }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const FloatArrayElement The array element with the values array.
        */
        const DoubleArrayElement* getDoubleArrayElement () const 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_DOUBLE )
                return ( DoubleArrayElement* ) mArrayElement; 
            return 0;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const FloatArrayElement The array element with the values array.
        */
        DoubleArrayElement* getDoubleArrayElement () 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_DOUBLE )
                return ( DoubleArrayElement* ) mArrayElement; 
            return 0;
        }

//         /**
//         * Stores a homogenous array of values.
//         * The class contains members for all valid array element types, 
//         * but there is always just one, which is initialised.
//         * @param arrayElement The array element with the values array.
//         */
//         void setDoubleArrayElement ( const DoubleArrayElement& arrayElement ) 
//         { 
//             mDoubleArrayElement = arrayElement; 
//         }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const NameArrayElement The array element with the values array.
        */
        NameArrayElement* getNameArrayElement () 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_NAME )
                return ( NameArrayElement* ) mArrayElement; 
            return 0;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const NameArrayElement The array element with the values array.
        */
        const NameArrayElement* getNameArrayElement () const 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_NAME )
                return ( NameArrayElement* ) mArrayElement; 
            return 0;
        }

//         /**
//         * Stores a homogenous array of values.
//         * The class contains members for all valid array element types, 
//         * but there is always just one, which is initialised.
//         * @param arrayElement The array element with the values array.
//         */
//         void setNameArrayElement ( const NameArrayElement& arrayElement ) 
//         { 
//             mNameArrayElement = arrayElement; 
//         }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IDREFArrayElement The array element with the values array.
        */
        IDREFArrayElement* getIDREFArrayElement () 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_IDREF )
                return ( IDREFArrayElement* ) mArrayElement; 
            return 0;
        }

        /**
        * Stores a homogenous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialised.
        * @return const IDREFArrayElement The array element with the values array.
        */
        const IDREFArrayElement* getIDREFArrayElement () const 
        { 
            if ( getDataType () == SourceBase::DATA_TYPE_IDREF )
                return ( IDREFArrayElement* ) mArrayElement; 
            return 0;
        }

//         /**
//         * Stores a homogenous array of values.
//         * The class contains members for all valid array element types, 
//         * but there is always just one, which is initialised.
//         * @param arrayElement The array element with the values array.
//         */
//         void setIDREFArrayElement ( const IDREFArrayElement& arrayElement ) 
//         { 
//             mIDREFArrayElement = arrayElement; 
//         }

    };


    typedef Source < DoubleArrayElement > DoubleSource;
    typedef Source < FloatArrayElement > FloatSource;
    typedef Source < IntArrayElement > IntSource;
    typedef Source < Long64ArrayElement > Long64Source;
    typedef Source < BoolArrayElement > BoolSource;

    typedef COLLADAFW::ArrayPrimitiveType<SourceBase*> SourceArray;

} // namespace COLLADASaxFWL

#endif // __COLLADASAXFWL_SOURCE_H__
