/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_FLOATORPARAM_H__
#define __COLLADAFW_FLOATORPARAM_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWAnimatable.h"
#include "COLLADAFWParam.h"


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
	class FloatOrParam : public Animatable
    {
    public:

        enum Type
        {
            FLOAT,
            PARAM
        };

	private:
	
        /** The value is represented by a literal floating-point scalar, for example:
        <float> 3.14 </float>. The sid attribute is optional. */
        float mFloatValue;

        /** The type of the current element. */
        Type mType;

		/** The value is represented by a reference to a previously defined parameter that can be 
        directly cast to a floatingpoint scalar. See main entry. */
        Param mParam;

	public:

        /** Constructor. */
        FloatOrParam ( float val ) 
            : mFloatValue ( val )
            , mType ( FLOAT ) 
        {};

        /** Constructor. */
        FloatOrParam ( const Param& param ) 
            : mFloatValue ( -1 )
            , mType ( PARAM ) 
            , mParam ( param )
        {};

        /** Destructor. */
		virtual ~FloatOrParam () {};

        /** The type of the current element. */
        FloatOrParam::Type getType () const { return mType; }
        void setType ( FloatOrParam::Type val ) { mType = val; }

        /** The value is represented by a literal floating-point scalar, for example:
        <float> 3.14 </float>. The sid attribute is optional. */
        float getFloatValue () const { return mFloatValue; }
        void setFloatValue ( float val ) { mFloatValue = val; }

        /** The value is represented by a reference to a previously defined parameter that can be 
        directly cast to a floatingpoint scalar. See main entry. */
        const Param& getParam () const { return mParam; }
        void setParam ( const Param& val ) { mParam = val; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_FLOATORPARAM_H__
