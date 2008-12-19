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
    class SourceBase 
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
         * The sources of semantic "POSITION" and "NORMAL" will be concatenated to one source and 
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
        SourceBase (  )
            :  mIsLoaded ( false )
            , mInitialIndex (0)
        {}

        /** Destructor. */
        virtual ~SourceBase () {}

		/**
		* The value type of the current values. 
		*/
		virtual DataType getDataType ()const =0;


        /**
        * Flag, if the source element is already loaded into the framework.
        */
        bool getIsLoaded () const { return mIsLoaded; }

        /**
        * Flag, if the source element is already loaded into the framework.
        */
        void setIsLoaded ( bool isLoaded ) { mIsLoaded = isLoaded; }

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
        * The number of values that are to be considered a unit during each access to the array.
        * The default is 1, indicating that a single value is accessed. Optional.
        */
        unsigned int getStride () const { return mStride; }

        /**
        * The number of values that are to be considered a unit during each access to the array.
        * The default is 1, indicating that a single value is accessed. Optional.
        */
        void setStride ( unsigned int Stride ) { mStride = Stride; }

        /**
        * This member will be used, if multiple source elements with the same input semantic are
        * referenced in the current mesh. 
        * The sources of semantic "POSITION" and "NORMAL" will be concated to one source and 
        * and one indices array.
        */
        size_t getInitialIndex () const { return mInitialIndex; }

        /**
        * This member will be used, if multiple source elements with the same input semantic are
        * referenced in the current mesh. 
        * The sources of semantic "POSITION" and "NORMAL" will be concated to one source and 
        * and one indices array.
        */
        void setInitialIndex ( size_t InitialIndex ) { mInitialIndex = InitialIndex; }

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
    template < class ArrayType, SourceBase::DataType dataType >
    class Source : public SourceBase
    {
	public:

    private:

        /**
        * Stores a homogeneous array of values.
        */
        ArrayType mArrayElement;

    public:

        /** Constructor. */
        Source ( ) 
            : SourceBase (  ) 
        {}

        /** Destructor. */
        virtual ~Source () 
        {
            //delete mArrayElement;
        }

		/**
		* The value type of the current values. All other arrays are empty!
		*/
		DataType getDataType () const { return dataType; }


		/**
		* Stores a homogeneous array of values.
		* The class contains members for all valid array element types, 
		* but there is always just one, which is initialized.
		* @return const IntArrayElement The array element with the values array.
		*/
		ArrayType& getArrayElement () 
		{
			return mArrayElement;
		}

		/**
		* Stores a homogeneous array of values.
		* The class contains members for all valid array element types, 
		* but there is always just one, which is initialized.
		* @return const IntArrayElement The array element with the values array.
		*/
		const ArrayType& getArrayElement() const
		{
			return mArrayElement;
		}

        /**
        * Stores a homogeneous array of values.
        * The class contains members for all valid array element types, 
        * but there is always just one, which is initialized.
        * @param arrayElement The array element with the values array.
        */
/*        void setArrayElement ( const ArrayType& arrayElement ) 
        { 
            mArrayElement = arrayElement; 
        }
*/
    };


	typedef Source < DoubleArrayElement, SourceBase::DATA_TYPE_DOUBLE > DoubleSource;
    typedef Source < FloatArrayElement, SourceBase::DATA_TYPE_FLOAT  > FloatSource;
    typedef Source < IntArrayElement, SourceBase::DATA_TYPE_INT  > IntSource;
    typedef Source < Long64ArrayElement, SourceBase::DATA_TYPE_LONG64  > Long64Source;
    typedef Source < BoolArrayElement, SourceBase::DATA_TYPE_BOOL  > BoolSource;

    typedef COLLADAFW::ArrayPrimitiveType<SourceBase*> SourceArray;

} // namespace COLLADASaxFWL

#endif // __COLLADASAXFWL_SOURCE_H__
