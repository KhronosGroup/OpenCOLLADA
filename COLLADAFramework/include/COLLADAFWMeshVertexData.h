/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MESHINPUTS_H__
#define __COLLADAFW_MESHINPUTS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWArrayPrimitiveType.h"

#include <assert.h>


namespace COLLADAFW
{

    /** Base class for mesh input elements, like positions, normals, colors, texcoord, ... */
	class MeshVertexData
    {
    public:

        /** Values can be stored as float or double values. */
        enum DataType
        {
            DATA_TYPE_FLOAT,
            DATA_TYPE_DOUBLE, 
            DATA_TYPE_UNKNOWN
        };

        /**
        * Additional informations about multiple inputs.
        */
        struct InputInfos
        {
            String mName;
            size_t mStride;
            size_t mLength;
        };
        typedef ArrayPrimitiveType<InputInfos*> InputInfosArray;

    private:

        /** Array with additional informations about multiple input elements. */
        InputInfosArray mInputInfosArray;

    protected:

        /** The data type of the stored position values. */
        DataType mType;

        /** The position values. */
        FloatArray mValuesF;
        DoubleArray mValuesD;

	public:

        /** Constructor. */
        MeshVertexData ()
            : mType ( DATA_TYPE_UNKNOWN )
            , mValuesF(FloatArray::OWNER)
            , mValuesD(DoubleArray::OWNER)
            , mInputInfosArray (0)
        {}

        /** Constructor. */
		MeshVertexData ( DataType type )
            : mType ( type )
            , mValuesF(FloatArray::OWNER)
            , mValuesD(DoubleArray::OWNER)
            , mInputInfosArray (0)
        {}

        /** Destructor. */
        virtual ~MeshVertexData() 
        {
            for ( size_t i=0; i<mInputInfosArray.getCount(); ++i )
            {
                delete mInputInfosArray [i];
            }
            mInputInfosArray.releaseMemory ();
        }

        /** The data type of the stored position values. */
        const COLLADAFW::MeshVertexData::DataType getType () const { return mType; }

        /** The data type of the stored position values. */
        void setType ( const COLLADAFW::MeshVertexData::DataType Type ) { mType = Type; }

        /** Returns the count of stored elements in the array. */
        const size_t getValuesCount () const
        {
            if ( mType == DATA_TYPE_FLOAT ) return mValuesF.getCount ();
            if ( mType == DATA_TYPE_DOUBLE ) return mValuesD.getCount ();
            return 0;
        }

        /**
        * Returns the number of uv sets.
        */
        size_t getNumInputInfos () const { return mInputInfosArray.getCount (); }

        /**
        * Appends the values in the array on the list of values and stores the information
        * of the current input.
        * @param const FloatArray& valuesArray The list of values.
        * @param const String& name The name of the current element.
        * @param const size_t stride The data stride.
        */
        void appendValues ( const FloatArray& valuesArray, const String& name, const size_t stride )
        {
            setType ( DATA_TYPE_FLOAT );
            appendValues ( valuesArray );

            InputInfos* info = new InputInfos();
            info->mLength = valuesArray.getCount ();
            info->mName = name;
            info->mStride = stride;

            mInputInfosArray.append ( info );
        }

        /**
        * Appends the values in the array on the list of values and stores the information
        * of the current input.
        * @param const FloatArray& valuesArray The list of values.
        * @param const String& name The name of the current element.
        * @param const size_t stride The data stride.
        */
        void appendValues ( const DoubleArray& valuesArray, const String& name, const size_t stride )
        {
            setType ( DATA_TYPE_DOUBLE );
            appendValues ( valuesArray );

            InputInfos* info = new InputInfos();
            info->mLength = valuesArray.getCount ();
            info->mName = name;
            info->mStride = stride;

            mInputInfosArray.append ( info );
        }

        /** The stride at the specified index. */
        String getName ( size_t index ) const 
        { 
            assert ( index <= mInputInfosArray.getCount() ); 
            return mInputInfosArray[index]->mName; 
        }

        /** The stride at the specified index. */
        size_t getStride ( size_t index ) const 
        { 
            assert ( index <= mInputInfosArray.getCount() ); 
            return mInputInfosArray[index]->mStride; 
        }

        /** The stride can differ, so we have to set. */
        size_t getLength ( size_t index ) const 
        { 
            assert ( index <= mInputInfosArray.getCount() ); 
            return mInputInfosArray[index]->mLength; 
        }

        /** Returns the position values array as a template array. */
        template <class T>
        ArrayPrimitiveType<T>& getValues ()
        {
            if ( mType == DATA_TYPE_FLOAT ) return mValuesF;
            if ( mType == DATA_TYPE_DOUBLE ) return mValuesD;
            return 0;
        }

        /** Returns the position values array as a float array. */
        const FloatArray* getFloatValues () const 
        {
            if ( mType == DATA_TYPE_FLOAT ) 
                return ( ArrayPrimitiveType<float>* ) &mValuesF;
            return 0;
        }

        /** Returns the position values array as a double array. */
        const DoubleArray* getDoubleValues () const 
        {
            if ( mType == DATA_TYPE_DOUBLE ) 
                return ( ArrayPrimitiveType<double>* ) &mValuesD;
            return 0;
        }

        /** Returns the position values array as a float array. */
        FloatArray* getFloatValues ()
        {
            if ( mType == DATA_TYPE_FLOAT ) 
                return ( ArrayPrimitiveType<float>* ) &mValuesF;
            return 0;
        }

        /** Returns the position values array as a double array. */
        DoubleArray* getDoubleValues ()
        {
            if ( mType == DATA_TYPE_DOUBLE ) 
                return ( ArrayPrimitiveType<double>* ) &mValuesD;
            return 0;
        }

//         /** Appends the values of the input array to the end of values array. 
//         The programmer must ensure, that the memory allocated, 
//         was large enough to hold another element. No new memory is allocated.*/
//         template <class Type>
//         bool appendValues ( const ArrayPrimitiveType <Type>& valuesArray ) const
//         {
//             if ( mType == DATA_TYPE_DOUBLE ) 
//             {
//                 mValuesD->appendValues ( valuesArray );
//                 return true;
//             }
//             else if ( mType == DATA_TYPE_FLOAT ) 
//             {
//                 mValuesF->appendValues ( valuesArray );
//                 return true;
//             }
// 
//             return false;
//         }

        /** Set the C-style data array.*/
        void setData ( float* data, const size_t count )
        { 
            if ( mType == DATA_TYPE_FLOAT ) mValuesF.setData ( data, count );
        }

        /** Set the C-style data array.*/
        void setData ( double* data, const size_t count )
        { 
            if ( mType == DATA_TYPE_DOUBLE ) mValuesD.setData ( data, count );
        }

        /** Appends the values of the input array to the end of values array. 
        The programmer must ensure, that the memory allocated, 
        was large enough to hold another element. No new memory is allocated.*/
        bool appendValues ( const FloatArray& valuesArray ) 
        {
            if ( mType == DATA_TYPE_FLOAT ) 
            {
                mValuesF.appendValues ( valuesArray );
                return true;
            }

            return false;
        }

        /** Appends the values of the input array to the end of values array. 
        The programmer must ensure, that the memory allocated, 
        was large enough to hold another element. No new memory is allocated.*/
        bool appendValues ( const DoubleArray& valuesArray ) 
        {
            if ( mType == DATA_TYPE_DOUBLE ) 
            {
                mValuesD.appendValues ( valuesArray );
                return true;
            }

            return false;
        }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MESHINPUTS_H__
