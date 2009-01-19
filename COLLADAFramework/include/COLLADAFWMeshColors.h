/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MESHCOLORS_H__
#define __COLLADAFW_MESHCOLORS_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class MeshColors : public MeshFloatDoubleInputs
    {
	private:
	
        /**
        * The number of values that are to be considered a unit during each access to the array.
        * The default is 1, indicating that a single value is accessed. Optional.
        */
        unsigned long long mStride;

	public:

        /** Constructor. */
        MeshColors () : MeshFloatDoubleInputs () {}

        /** Constructor. */
		MeshColors ( DataType type ) : MeshFloatDoubleInputs ( type ) {}

        /** Destructor. */
		virtual ~MeshColors() {}

        /** Returns the count of stored elements in the array. */
        const size_t getColorsCount () const
        {
            return getElementsCount ();
        }

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

        /** Returns the position values array as a template array. */
        template <class T>
        ArrayPrimitiveType<T>* getColors ()
        {
            return getValues ();
        }

        /** Returns the position values array as a float array. */
        ArrayPrimitiveType<float>* getFloatColors ()
        {
            return getFloatValues ();
        }

        /** Returns the position values array as a double array. */
        ArrayPrimitiveType<double>* getDoubleColors ()
        {
            return getDoubleValues ();
        }

        /** Returns the position values array as a float array. */
        const ArrayPrimitiveType<float>* getFloatColors () const 
        {
            return getFloatValues ();
        }

        /** Returns the position values array as a double array. */
        const ArrayPrimitiveType<double>* getDoubleColors () const 
        {
            return getDoubleValues ();
        }

    };

} // namespace COLLADAFW

#endif // __COLLADAFW_MESHCOLORS_H__
