/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ANNOTATE_H__
#define __COLLADAFW_ANNOTATE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWValueType.h"


namespace COLLADAFW
{

    /** 
    Adds a strongly typed annotation remark to the parent object.
    
    Annotations represent objects of the form SYMBOL = VALUE, where SYMBOL is a user-defined 
    identifier and VALUE is a strongly typed value. Annotations communicate metainformation from 
    the Effect Runtime to the application only and are not interpreted by the COLLADA document.
    */
	class Annotate 	
    {
	private:
	
        /** The text string name of this element that represents the SYMBOL in an object of
        the form SYMBOL = VALUE. Required. */
        String mName;

        /** A strongly typed value that represents the VALUE in an object of the form 
        SYMBOL = VALUE. Consists of a COLLADA type element that contains a value of that type. 
        Valid type elements are:
        bool, bool2, bool3, bool4, 
        int, int2, int3, int4, 
        float, float2, float3, float4, 
        float2x2, float3x3, float4x4, 
        string */
        ValueType mValue;

	public:

        /** Constructor. */
		Annotate();

        /** Destructor. */
		virtual ~Annotate();

        /** The text string name of this element that represents the SYMBOL in an object of
        the form SYMBOL = VALUE. Required. */
        const String getName () const { return mName; }

        /** The text string name of this element that represents the SYMBOL in an object of
        the form SYMBOL = VALUE. Required. */
        void setName ( const String Name ) { mName = Name; }

        /** A strongly typed value that represents the VALUE in an object of the form 
        SYMBOL = VALUE. Consists of a COLLADA type element that contains a value of that type. 
        Valid type elements are:
        bool, bool2, bool3, bool4, 
        int, int2, int3, int4, 
        float, float2, float3, float4, 
        float2x2, float3x3, float4x4, 
        string */
        const ValueType getValue () const { return mValue; }

        /** A strongly typed value that represents the VALUE in an object of the form 
        SYMBOL = VALUE. Consists of a COLLADA type element that contains a value of that type. 
        Valid type elements are:
        bool, bool2, bool3, bool4, 
        int, int2, int3, int4, 
        float, float2, float3, float4, 
        float2x2, float3x3, float4x4, 
        string */
        void setValue ( const ValueType Value ) { mValue = Value; }

	private:

        /** Disable default copy ctor. */
		Annotate( const Annotate& pre );

        /** Disable default assignment operator. */
		const Annotate& operator= ( const Annotate& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_ANNOTATE_H__
