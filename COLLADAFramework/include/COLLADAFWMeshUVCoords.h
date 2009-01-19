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


namespace COLLADAFW
{

    /** TODO Documentation */
	class MeshUVCoords : public MeshFloatDoubleInputs
    {
	private:
	
        /** The stride can differ, so we have to set. */
        unsigned long long mStride;

	public:

        /** Constructor. */
        MeshUVCoords() : MeshFloatDoubleInputs () {};

        /** Constructor. */
        MeshUVCoords ( DataType type ) : MeshFloatDoubleInputs ( type ) {}

        /** Destructor. */
        virtual ~MeshUVCoords() {};

        /** The stride can differ, so we have to set. */
        unsigned long long getStride () const { return mStride; }

        /** The stride can differ, so we have to set. */
        void setStride ( unsigned long long Stride ) { mStride = Stride; }

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
