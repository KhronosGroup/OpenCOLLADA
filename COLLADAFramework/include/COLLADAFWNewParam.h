/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_NEWPARAM_H__
#define __COLLADAFW_NEWPARAM_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWSemantic.h"
#include "COLLADAFWModifier.h"
#include "COLLADAFWArray.h"


namespace COLLADAFW
{

    /** 
    Creates a new, named <param> (FX) object in the FX Runtime, and assigns it a type, an 
    initial value, and additional attributes at declaration time.
    Parameters are typed data objects that are created in the FX Runtime and are available to 
    compilers and functions at run time.
    */
	class NewParam 	
    {
    public:

        /** The different parameter types. */
        enum ParamType
        {
            PARAM_TYPE_FLOAT,
            PARAM_TYPE_FLOAT2,
            PARAM_TYPE_FLOAT3,
            PARAM_TYPE_FLOAT4,
            PARAM_TYPE_SURFACE,
            PARAM_TYPE_SURFACE2D
        };

	private:

        /** Identifier for this parameter (that is, the variable name). Required. */
        String mSid;

        /** Adds a strongly typed annotation remark to the parent object. */
        Array<Annotate> mAnnotateArray;

        /** Provides metainformation that describes the purpose of a parameter declaration. */
	    Semantic mSemantic;

        /** Provides additional information about the volatility or linkage of a <newparam> declaration. */
        Modifier mModifier;

        /** The parameter’s type. Must be exactly one of the following:
        <float>, <float2>, <float3>, <float4>, <surface>, <sampler2D> */
        ParamType mParamType;

	public:

        /** Constructor. */
        NewParam ( const ParamType& paramType ) 
            : mParamType ( paramType )
        {}

        /** Destructor. */
        virtual ~NewParam() {}

	private:

        /** Disable default copy ctor. */
		NewParam( const NewParam& pre );

        /** Disable default assignment operator. */
		const NewParam& operator= ( const NewParam& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_NEWPARAM_H__
