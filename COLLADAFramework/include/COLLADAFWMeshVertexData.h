/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MESHINPUTS_H__
#define __COLLADAFW_MESHINPUTS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWArrayPrimitiveType.h"
#include "COLLADAFWFloatDoubleOrIntType.h"
#include "COLLADAFWFloatOrDoubleArray.h"
#include "COLLADAFWIntArray.h"

#include <assert.h>


namespace COLLADAFW
{

    /** Base class for mesh input elements, like positions, normals, colors, texcoord, ... */
	class MeshVertexData : public FloatOrDoubleArray, public IntArray
    {
    public:

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
        // IntArray mIntArray;

	public:

        /** Constructor. */
        MeshVertexData ()
            : FloatOrDoubleArray()
            , IntArray()
			, mInputInfosArray (0)
            // , mIntArray()
        {}

        /** Constructor. */
		MeshVertexData ( FloatDoubleOrIntArray::DataType type )
            : FloatOrDoubleArray(type)
            , IntArray(type)
			, mInputInfosArray (0)
            // , mIntArray(type)
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

        /**
        * Returns the number of uv sets.
        */
        size_t getNumInputInfos () const { return mInputInfosArray.getCount (); }

		/** Returns the InputInfosArray.*/
		const InputInfosArray& getInputInfosArray() const { return mInputInfosArray; }

        /**
        * Appends the values in the array on the list of values and stores the information
        * of the current input.
        * @param const FloatArray& valuesArray The list of values.
        * @param const String& name The name of the current element.
        * @param const size_t stride The data stride.
        */
        void appendValues ( const FloatArray& valuesArray, const String& name, const size_t stride )
        {
            FloatOrDoubleArray::setType ( FloatDoubleOrIntArray::DATA_TYPE_FLOAT );
			FloatOrDoubleArray::appendValues ( valuesArray );

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
            FloatOrDoubleArray::setType ( FloatDoubleOrIntArray::DATA_TYPE_DOUBLE );
			FloatOrDoubleArray::appendValues ( valuesArray );

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
        void appendValues ( const IntValuesArray& valuesArray, const String& name, const size_t stride )
        {
            IntArray::setType ( FloatDoubleOrIntArray::DATA_TYPE_INT );
			IntArray::appendValues ( valuesArray );

            InputInfos* info = new InputInfos();
            info->mLength = valuesArray.getCount ();
            info->mName = name;
            info->mStride = stride;

            mInputInfosArray.append ( info );
        }

        /** The stride at the specified index. */
        String getName ( size_t index ) const
        {
			COLLADABU_ASSERT ( index <= mInputInfosArray.getCount() );
            if ( index >= mInputInfosArray.getCount () ) return 0;
            return mInputInfosArray[index]->mName;
        }

        /** The stride at the specified index. */
        size_t getStride ( size_t index ) const
        {
            COLLADABU_ASSERT ( index <= mInputInfosArray.getCount() );
            if ( index >= mInputInfosArray.getCount () ) return 0;
            return mInputInfosArray[index]->mStride;
        }

        /** The stride can differ, so we have to set. */
        size_t getLength ( size_t index ) const
        {
            COLLADABU_ASSERT ( index <= mInputInfosArray.getCount() );
            if ( index >= mInputInfosArray.getCount () ) return 0;
            return mInputInfosArray[index]->mLength;
        }


		/** Appends the values of the input array to the end of values array.
		The programmer must ensure, that the memory allocated,
		was large enough to hold another element. No new memory is allocated.*/
		bool appendValues ( const FloatArray& valuesArray )
		{
			return FloatOrDoubleArray::appendValues ( valuesArray );
		}

		/** Appends the values of the input array to the end of values array.
		The programmer must ensure, that the memory allocated,
		was large enough to hold another element. No new memory is allocated.*/
		bool appendValues ( const DoubleArray& valuesArray )
		{
			return FloatOrDoubleArray::appendValues ( valuesArray );
		}

		/** Appends the values of the input array to the end of values array.
		The programmer must ensure, that the memory allocated,
		was large enough to hold another element. No new memory is allocated.*/
		bool appendValues ( const IntValuesArray& valuesArray )
		{
			return IntArray::appendValues ( valuesArray );
		}

        FloatDoubleOrIntArray::DataType getType() const 
        {
            if ( IntArray::getType() == FloatDoubleOrIntArray::DATA_TYPE_INT ) return IntArray::getType();
            else return FloatOrDoubleArray::getType();
        }

        void setType( FloatDoubleOrIntArray::DataType type ) 
        {
            if( type == FloatDoubleOrIntArray::DATA_TYPE_INT )
            {
                IntArray::setType(type);
                FloatOrDoubleArray::setType(FloatDoubleOrIntArray::DATA_TYPE_UNKNOWN);
            }
            else
            {
                IntArray::setType(FloatDoubleOrIntArray::DATA_TYPE_UNKNOWN);
                FloatOrDoubleArray::setType(type);

            }
        }

        size_t getValuesCount() const 
        {
            if ( IntArray::getType() == FloatDoubleOrIntArray::DATA_TYPE_INT ) return IntArray::getValuesCount();
            else return FloatOrDoubleArray::getValuesCount();
        }

        bool empty() const
        {
            if ( IntArray::getType() == FloatDoubleOrIntArray::DATA_TYPE_INT) return  IntArray::empty();
            else return FloatOrDoubleArray::empty();
        }

        void clear() 
        {
            IntArray::clear();
            FloatOrDoubleArray::clear();
        }

        template <class T>
        ArrayPrimitiveType<T>& getValues(){
            if( IntArray::getType() == FloatDoubleOrIntArray::DATA_TYPE_INT ) 
            {
                return IntArray::getValues<int>();
            }
            else
            {
                return FloatOrDoubleArray::getValues<T>();   
            }
            
        }
		void setData( float* data, const size_t count )
        {
            FloatOrDoubleArray::setData(data, count);
        }

		void setData( double* data, const size_t count )
        {
            FloatOrDoubleArray::setData(data, count);
        }

        void setData( int* data, const size_t count ) 
        {
            IntArray::setData(data, count);
        }
	private:

		/** Disable default copy ctor. */
		MeshVertexData( const MeshVertexData& pre );

		/** Disable default assignment operator. */
		const MeshVertexData& operator= ( const MeshVertexData& pre );

	};
        // template<>
        // ArrayPrimitiveType<double>& MeshVetexData::getValues<double>() {
        //     return FloatOrDoubleArray::getValues<double>();
        // }

        // template<>
        // ArrayPrimitiveType<float>& MeshVetexData::getValues<float>() {
        //     return FloatOrDoubleArray::getValues<float>();
        // }
        // template<>
        // ArrayPrimitiveType<int>& MeshVetexData::getValues<int>() {
        //     return IntArray::getValues<int>();
        // }

} // namespace COLLADAFW

#endif // __COLLADAFW_MESHINPUTS_H__
