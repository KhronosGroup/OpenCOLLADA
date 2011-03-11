/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADASaxFWLInputUnshared.h"

#include "COLLADAFWObject.h"
#include "COLLADAFWArray.h"
#include "COLLADAFWMeshPrimitive.h"


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
#ifdef COLLADASAXFWL_REAL_IS_FLOAT
			DATA_TYPE_REAL = DATA_TYPE_FLOAT,
#else
			DATA_TYPE_REAL = DATA_TYPE_DOUBLE,
#endif
			DATA_TYPE_BOOL,
			DATA_TYPE_NAME,
			DATA_TYPE_IDREF,
			DATA_TYPE_INTERPOLATIONTYPE,
			DATA_TYPE_UNKNOWN
		};

		/** Describes one parameter in a COLLADA accessor.*/
		struct AccessorParameter
		{
			String name;
			String type;

			bool operator==( const SourceBase::AccessorParameter& rhs) const
			{
				return ( name == rhs.name) && ( type == rhs.type );
			}

			bool operator!=( const SourceBase::AccessorParameter& rhs) const
			{
				return ( name != rhs.name) || ( type != rhs.type );
			}

		};

		/** List of all parameters of an accessor, defining the meaning of the values in an array.*/
		typedef std::vector< AccessorParameter > Accessor;
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
        unsigned long long mStride; 

        /**
         * This member will be used, if multiple source elements with the same input semantic are
         * referenced in the current mesh. 
         */
        size_t mInitialIndex;

        /**
         * Flags, if the source element is already loaded into the framework. A source element 
         * can be referenced from the same input element in multiple primitive elements or from
         * different input elements (NORMALS, COLOR, TEXCOORD, ...). It should be loaded only once
         * from every input element.
         */
        COLLADAFW::ArrayPrimitiveType<InputSemantic::Semantic> mLoadedInputElements;

		/** The accessor of the source.*/
		Accessor mAccessor;

    public:

        /** Constructor. */
        SourceBase (  )
            : mInitialIndex (0)
            , mLoadedInputElements ( COLLADAFW::MeshPrimitiveArray::OWNER )
        {}

        /** Destructor. */
        virtual ~SourceBase () 
        {
            mLoadedInputElements.clear();
        }

		/**
		* The value type of the current values. 
		*/
		virtual DataType getDataType ()const =0;

        /**
        * Adds the current input element in the list of already loaded input elements.
        * Returns true, if the input element was not already in the list and was successfully added.
        * A source element can be referenced from the same input element in multiple primitive 
        * elements or from different input elements (NORMALS, COLOR, TEXCOORD, ...). It should be 
        * loaded only once from every input element.
        */
        bool addLoadedInputElement ( const InputSemantic::Semantic& semantic )
        {
            if ( !isLoadedInputElement ( semantic ) )
            {
                mLoadedInputElements.append ( semantic );
                return true;
            }
            return false;
        }

        /**
        * Checks if the current input element is already in the list of loaded input elements.
        * Returns true, if the input element was not already in the list and was successfully added.
        * A source element can be referenced from the same input element in multiple primitive 
        * elements or from different input elements (NORMALS, COLOR, TEXCOORD, ...). It should be 
        * loaded only once from every input element.
        */
        bool isLoadedInputElement ( const InputSemantic::Semantic& semantic )
        {
            const size_t numLoadedInputElements = mLoadedInputElements.getCount ();
            for ( size_t i=0; i<numLoadedInputElements; ++i )
            {
                InputSemantic::Semantic& currentSemantic = mLoadedInputElements [i];
                if ( currentSemantic == semantic ) return true;
            }

            return false;
        }

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
        unsigned long long getStride () const { return mStride; }

        /**
        * The number of values that are to be considered a unit during each access to the array.
        * The default is 1, indicating that a single value is accessed. Optional.
        */
        void setStride ( unsigned long long Stride ) { mStride = Stride; }

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

		/** Appends an accessor parameter to the source's  accessor.*/
		void appendAccessorParameter( const AccessorParameter& parameter ) { mAccessor.push_back( parameter ); }

		/** Returns the accessor.*/
		const Accessor& getAccessor() const { return mAccessor; }

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
    private:

        /**
        * Stores a homogeneous array of values.
        */
        ArrayType mArrayElement;

    public:

        /** Constructor. */
        Source () : SourceBase () {}

        /** Destructor. */
        virtual ~Source () 
		{
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

    };


	typedef Source < DoubleArrayElement, SourceBase::DATA_TYPE_DOUBLE > DoubleSource;
    typedef Source < FloatArrayElement, SourceBase::DATA_TYPE_FLOAT  > FloatSource;
    typedef Source < IntArrayElement, SourceBase::DATA_TYPE_INT  > IntSource;
    typedef Source < Long64ArrayElement, SourceBase::DATA_TYPE_LONG64  > Long64Source;
    typedef Source < BoolArrayElement, SourceBase::DATA_TYPE_BOOL  > BoolSource;

#ifdef COLLADASAXFWL_REAL_IS_FLOAT
	typedef FloatSource RealSource;
#else
	typedef DoubleSource RealSource;
#endif


    typedef COLLADAFW::ArrayPrimitiveType<SourceBase*> SourceArray;

} // namespace COLLADASaxFWL

#endif // __COLLADASAXFWL_SOURCE_H__
