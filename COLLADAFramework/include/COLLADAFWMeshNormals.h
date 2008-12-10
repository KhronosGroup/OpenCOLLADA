/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_NORMALINPUTS_H__
#define __COLLADAFW_NORMALINPUTS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshFDInputs.h"


namespace COLLADAFW
{

    /** TODO Documentation */
    class MeshNormals : public MeshFloatDoubleInputs
    {
	private:
	
	public:

        /** Constructor. */
        MeshNormals ( DataType type ) : MeshFloatDoubleInputs ( type ) {}

        /** Destructor. */
        virtual ~MeshNormals() {}

        /** Returns the count of stored elements in the array. */
        const size_t getNormalsCount () const
        {
            return getElementsCount ();
        }

        /** Returns the position values array as a template array. */
        template <class T>
        ArrayPrimitiveType<T>* getNormals ()
        {
            return getValues ();
        }

        /** Returns the position values array as a float array. */
        ArrayPrimitiveType<float>* getFloatNormals ()
        {
            return getFloatValues ();
        }

        /** Returns the position values array as a double array. */
        ArrayPrimitiveType<double>* getDoubleNormals ()
        {
            return getDoubleValues ();
        }

        /** Returns the position values array as a float array. */
        const ArrayPrimitiveType<float>* getFloatNormals () const 
        {
            return getFloatValues ();
        }

        /** Returns the position values array as a double array. */
        const ArrayPrimitiveType<double>* getDoubleNormals () const 
        {
            return getDoubleValues ();
        }
	};

} // namespace COLLADAFW

#endif // __COLLADAFW_NORMALINPUTS_H__
