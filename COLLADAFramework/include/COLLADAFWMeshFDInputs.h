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


namespace COLLADAFW
{

    /** Base class for mesh input elements, like positions, normals, colors, texcoord, ... */
	class MeshFloatDoubleInputs
    {
    public:

        /** Positions can be stored as float or double values. */
        enum DataType
        {
            DATA_TYPE_FLOAT,
            DATA_TYPE_DOUBLE, 
            DATA_TYPE_UNKNOWN
        };

    protected:

        /** The data type of the stored position values. */
        DataType mType;

        /** The position values. */
        FloatArray mValuesF;
        DoubleArray mValuesD;

	public:

        /** Constructor. */
        MeshFloatDoubleInputs ()
            : mType ( DATA_TYPE_UNKNOWN ),
			mValuesF(FloatArray::OWNER),
			mValuesD(DoubleArray::OWNER)
        {}

        /** Constructor. */
		MeshFloatDoubleInputs ( DataType type )
            : mType ( type ),
			mValuesF(FloatArray::OWNER),
			mValuesD(DoubleArray::OWNER)
        {}

        /** Destructor. */
        virtual ~MeshFloatDoubleInputs() 
        {
        }

        /** The data type of the stored position values. */
        const COLLADAFW::MeshFloatDoubleInputs::DataType getType () const { return mType; }

        /** The data type of the stored position values. */
        void setType ( const COLLADAFW::MeshFloatDoubleInputs::DataType Type ) { mType = Type; }

        /** Returns the count of stored elements in the array. */
        const size_t getElementsCount () const
        {
            if ( mType == DATA_TYPE_FLOAT ) return mValuesF.getCount ();
            if ( mType == DATA_TYPE_DOUBLE ) return mValuesD.getCount ();
            return 0;
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
