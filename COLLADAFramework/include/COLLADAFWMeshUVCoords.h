/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MESHUVCOORDS_H__
#define __COLLADAFW_MESHUVCOORDS_H__

#include "COLLADAFWPrerequisites.h"
#include <assert.h>


namespace COLLADAFW
{

    /** TODO Documentation */
	class MeshUVCoords : public MeshFloatDoubleInputs
    {
    public:

        struct UVSetInfo
        {
            String mName;
            size_t mStride;
            size_t mLength;
        };

    private:
	
        /** Array with the UVSetInfos. */
        ArrayPrimitiveType<UVSetInfo*> mUVSetInfos;

	public:

        /** Constructor. */
        MeshUVCoords () 
            : MeshFloatDoubleInputs ()
            , mUVSetInfos (0) 
        {}

        /** Constructor. */
        MeshUVCoords ( DataType type ) 
            : MeshFloatDoubleInputs ( type )
            , mUVSetInfos (0) 
        {}

        /** Destructor. */
        virtual ~MeshUVCoords() {}

        /**
         * Returns the number of uv sets.
         */
        size_t getNumUVSets () const { return mUVSetInfos.getCount (); }

        /**
         * Appends the values in the array on the list of values and stores the information
         * of the current input.
         * @param const FloatArray& valuesArray The list of values.
         * @param const String& name The name of the current element.
         * @param const size_t stride The data stride.
         */
        void appendUVSet ( const FloatArray& valuesArray, const String& name, const size_t stride )
        {
            setType ( DATA_TYPE_FLOAT );
            appendValues ( valuesArray );

            UVSetInfo* uvSetInfo = new UVSetInfo();
            uvSetInfo->mLength = valuesArray.getCount ();
            uvSetInfo->mName = name;
            uvSetInfo->mStride = stride;

            mUVSetInfos.append ( uvSetInfo );
        }

        /**
        * Appends the values in the array on the list of values and stores the information
        * of the current input.
        * @param const FloatArray& valuesArray The list of values.
        * @param const String& name The name of the current element.
        * @param const size_t stride The data stride.
        */
        void appendUVSet ( const DoubleArray& valuesArray, const String& name, const size_t stride )
        {
            setType ( DATA_TYPE_DOUBLE );
            appendValues ( valuesArray );

            UVSetInfo* uvSetInfo = new UVSetInfo();
            uvSetInfo->mLength = valuesArray.getCount ();
            uvSetInfo->mName = name;
            uvSetInfo->mStride = stride;

//            if ( mUVSetInfos.getCount() <= 0 ) mUVSetInfos.setData ( uvSetInfo,  );
            mUVSetInfos.append ( uvSetInfo );
        }

        /** The stride at the specified index. */
        String getUVSetName ( size_t index ) const 
        { 
            assert ( index <= mUVSetInfos.getCount() ); 
            return mUVSetInfos[index]->mName; 
        }

        /** The stride at the specified index. */
        size_t getStride ( size_t index ) const 
        { 
            assert ( index <= mUVSetInfos.getCount() ); 
            return mUVSetInfos[index]->mStride; 
        }

        /** The stride can differ, so we have to set. */
        size_t getLength ( size_t index ) const 
        { 
            assert ( index <= mUVSetInfos.getCount() ); 
            return mUVSetInfos[index]->mLength; 
        }

        /** Returns the position values array as a template array. */
        template <class T>
        ArrayPrimitiveType<T>* getUVCoords ()
        {
            return getValues ();
        }

        /** Returns the position values array as a float array. */
        ArrayPrimitiveType<float>* getFloatUVCoords ()
        {
            return getFloatValues ();
        }

        /** Returns the position values array as a double array. */
        ArrayPrimitiveType<double>* getDoubleUVCoords ()
        {
            return getDoubleValues ();
        }

        /** Returns the position values array as a float array. */
        const ArrayPrimitiveType<float>* getFloatUVCoords () const 
        {
            return getFloatValues ();
        }

        /** Returns the position values array as a double array. */
        const ArrayPrimitiveType<double>* getDoubleUVCoords () const 
        {
            return getDoubleValues ();
        }

        /** Returns the count of stored elements in the array. */
        const size_t getUVCoordsCount () const
        {
            return getElementsCount ();
        }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MESHUVCOORDS_H__
