/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_ARRAY_ELEMENT_H__
#define __COLLADASAXFWL_ARRAY_ELEMENT_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADAFWArrayPrimitiveType.h"
#include "COLLADAFWAnimationCurve.h"


namespace COLLADASaxFWL
{

    /** Base class for the storage for a homogenous array of reference values. */
    template < class Type >
    class BaseArrayElement
    {

    private:

        /**
         * The number of values in the array. Required.
         */
        unsigned int mCount;

        /**
         * A text string containing the unique identifier of this element. 
         * This value must be unique within the instance document. Optional.
         */
        String mId; 

        /**
         * xs:NCName The text string name of this element. Optional.
         */
        String mName; 

        /**
         * The arrayValues element stores values of the templates data type 
         * that reference values within the instance document.
         */
        COLLADAFW::ArrayPrimitiveType<Type> mValuesArray;

    public:

        /** Constructor. */
        BaseArrayElement () 
            : mCount (0) 
        {}

        /** Destructor. */
        virtual ~BaseArrayElement () {}

        /**
        * The number of values in the array. Required.
        */
        const unsigned int getCount () const { return mCount; }
        void setCount ( const unsigned int val ) { mCount = val; }

        /**
        * A text string containing the unique identifier of this element. 
        * This value must be unique within the instance document. Optional.
        */
        const String getId () const { return mId; }
        void setId ( const String val ) { mId = val; }

        /**
        * xs:NCName The text string name of this element. Optional.
        */
        const String getName () const { return mName; }
        void setName ( const String val ) { mName = val; }

        /**
         * The arrayValues element stores values of the templates data type 
         * that reference values within the instance document.
         * @return const ArrayPrimitiveType<Type> Array of the templates datatype.
         */
        const COLLADAFW::ArrayPrimitiveType<Type>& getValues () const 
        { 
            return mValuesArray; 
        }

        /**
        * The arrayValues element stores values of the templates data type 
        * that reference values within the instance document.
        * @return const ArrayPrimitiveType<Type> Array of the templates datatype.
        */
        COLLADAFW::ArrayPrimitiveType<Type>& getValues () 
        { 
            return mValuesArray; 
        }

        /**
         * The arrayValues element stores values of the templates data type 
         * that reference values within the instance document.
         * @param arrayValues Array of values.
         */
        void setValues ( const COLLADAFW::ArrayPrimitiveType<Type>& arrayValues ) 
        { 
            mValuesArray = arrayValues; 
        }

    };

    /**
     * Declares the storage for a homogenous array of floating-point values.
     * The <float_array> element stores the data values for generic use within 
     * the COLLADA schema. The arrays themselves are strongly typed but without 
     * semantics. They simply describe a sequence of floatingpoint values.
     */
    typedef BaseArrayElement < float > FloatArrayElement;

    /**
    * Declares the storage for a homogenous array of floating-point values.
    * The <double_array> element stores the data values for generic use within 
    * the COLLADA schema. The arrays themselves are strongly typed but without 
    * semantics. They simply describe a sequence of floatingpoint values.
    */
    typedef BaseArrayElement < double > DoubleArrayElement;


#ifdef COLLADASAXFWL_REAL_IS_FLOAT
	typedef FloatArrayElement RealArrayElement;
#else
	typedef DoubleArrayElement RealArrayElement;
#endif


    /**
     * Stores a homogenous array of integer values.
     * The <int_array> element stores the data values for generic use within 
     * the COLLADA schema. The arrays themselves are strongly typed but without 
     * semantics. They simply describe a sequence of integer values.
     */
    typedef BaseArrayElement < int > IntArrayElement;

    /**
    * Stores a homogenous array of integer values.
    * The <int_array> element stores the data values for generic use within 
    * the COLLADA schema. The arrays themselves are strongly typed but without 
    * semantics. They simply describe a sequence of integer values.
    */
    typedef BaseArrayElement < long long > Long64ArrayElement;

    /**
     * Declares the storage for a homogenous array of Boolean values.
     * The <bool_array> element stores data values for generic use within the 
     * COLLADA schema. The arrays themselves are strongly typed but without 
     * semantics. They simply describe a sequence of XML Boolean values.
     */
    typedef BaseArrayElement < bool > BoolArrayElement;

    /**
     * Stores a homogenous array of symbolic name values.
     * The <Name_array> element stores name values as data for generic use 
     * within the COLLADA schema. The array itself is strongly typed but 
     * without semantics. It simply stores a sequence of XML name values.
     */
    typedef BaseArrayElement < String > NameArrayElement;

    /**
     * Declares the storage for a homogenous array of ID reference values.
     * The <IDREF_array> element stores string values that reference IDs within 
     * the instance document.
     */
    typedef BaseArrayElement < String > IDREFArrayElement;

	/** Declares the storage for a homogenous array of interpolation type valuesvalues.*/
	typedef BaseArrayElement < COLLADAFW::AnimationCurve::InterpolationType > InterpolationTypeArrayElement;

}

#endif // __COLLADASAXFWL_ARRAY_ELEMENT_H__
