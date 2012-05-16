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
#include "COLLADAFWFloatOrDoubleArray.h"

#include <assert.h>


namespace COLLADAFW
{

    /** Base class for mesh input elements, like positions, normals, colors, texcoord, ... */
	class MeshVertexData : public FloatOrDoubleArray
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

	public:

        /** Constructor. */
        MeshVertexData ()
            : FloatOrDoubleArray()
			, mInputInfosArray (0)
        {}

        /** Constructor. */
		MeshVertexData ( DataType type )
            : FloatOrDoubleArray(type)
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
            setType ( DATA_TYPE_FLOAT );
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
            setType ( DATA_TYPE_DOUBLE );
			FloatOrDoubleArray::appendValues ( valuesArray );

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


	private:

		/** Disable default copy ctor. */
		MeshVertexData( const MeshVertexData& pre );

		/** Disable default assignment operator. */
		const MeshVertexData& operator= ( const MeshVertexData& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MESHINPUTS_H__
