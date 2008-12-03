/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_FLOATORPARAM_H__
#define __COLLADAFW_FLOATORPARAM_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** 
    A type that describes the scalar attributes of fixed-function shader elements inside 
    <profile_COMMON> effects.
    This type describes the attributes and related elements of the following elements:
    • <index_of_refraction>
    • <reflectivity>
    • <shininess>
    • <transparency>

    Note: Exactly one of the child elements <float> or <param> must appear. 
    They are mutually exclusive.
    */
	class FloatOrParam 	
    {
    public:

        enum Type
        {
            FLOAT,
            PARAM
        }

	private:
	
        /** The type of the current element. */
        Type mType;

        /** The sid attribute is optional. */
        String mSid;

        /** The value is represented by a literal floating-point scalar, for example:
        <float> 3.14 </float>. The sid attribute is optional. */
        float mFloatValue;

        /** The value is represented by a reference to a previously defined parameter that can be 
        directly cast to a floatingpoint scalar. See main entry. */
        Param mParam;

	public:

        /** Constructor. */
        FloatOrParam ( const float val, const String sid="" ) 
            : mFloatValue ( val )
            , mType ( FLOAT ) 
            , mSid ( sid )
        {};

        /** Constructor. */
        FloatOrParam ( const Param& param ) 
            : mParam ( param )
            , mType ( PARAM ) 
        {};

        /** Destructor. */
		virtual ~FloatOrParam () {};

	private:

        /** Disable default copy ctor. */
		FloatOrParam( const FloatOrParam& pre );

        /** Disable default assignment operator. */
		const FloatOrParam& operator= ( const FloatOrParam& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_FLOATORPARAM_H__
