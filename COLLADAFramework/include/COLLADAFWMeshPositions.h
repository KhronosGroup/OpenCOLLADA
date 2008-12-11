/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_POSITIONS_H__
#define __COLLADAFW_POSITIONS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshFDInputs.h"


namespace COLLADAFW
{

    /** 
    * The positions array. 
    * Positions can be stored as float or double values.
    * Positions have always a stride of three (X, Y and Z parameter). So we don't need to 
    * store this information.
    */
    class MeshPositions : public MeshFloatDoubleInputs
    {

    private:
	
	public:

        /** Constructor. */
        MeshPositions () : MeshFloatDoubleInputs () {}

        /** Constructor. */
        MeshPositions ( DataType type ) : MeshFloatDoubleInputs ( type ) {}

        /** Destructor. */
        virtual ~MeshPositions() {}

        /** Returns the position values array as a template array. */
        template <class T>
        ArrayPrimitiveType<T>* getPositions ()
        {
            return getValues ();
        }

        /** Returns the position values array as a float array. */
        const ArrayPrimitiveType<float>* getFloatPositions () const
        {
            return getFloatValues ();
        }

        /** Returns the position values array as a double array. */
        const ArrayPrimitiveType<double>* getDoublePositions () const 
        {
            return getDoubleValues ();
        }

        /** Returns the position values array as a float array. */
        ArrayPrimitiveType<float>* getFloatPositions ()
        {
            return getFloatValues ();
        }

        /** Returns the position values array as a double array. */
        ArrayPrimitiveType<double>* getDoublePositions ()
        {
            return getDoubleValues ();
        }

        /** Returns the count of stored elements in the array. */
        const size_t getPositionsCount () const
        {
            return getElementsCount ();
        }

    };

} // namespace COLLADAFW

#endif // __COLLADAFW_POSITIONS_H__
