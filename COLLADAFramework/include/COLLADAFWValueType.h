/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_VALUE_TYPE_H__
#define __COLLADAFW_VALUE_TYPE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWConstants.h"

#include "COLLADABUUtils.h"


namespace COLLADAFW
{

    /** Valid type elements are:
    bool, bool2, bool3, bool4, int, int2, int3, int4, float,
    float2, float3, float4, float2x2, float3x3, float4x4, string */
    class ValueType
    {

    public:

        /** The datatype of the param's value. */
        enum ColladaType
        {
            BOOL, BOOL2, BOOL3, BOOL4,
            INT, INT2, INT3, INT4,
            FLOAT, FLOAT2, FLOAT3, FLOAT4,
            FLOAT2x2, FLOAT3x3, FLOAT4x4, 
            STRING,
            SURFACE, 
            SAMPLER_1D, SAMPLER_2D, SAMPLER_3D, 
            SAMPLER_CUBE, SAMPLER_RECT, SAMPLER_DEPTH,
            VALUE_TYPE_UNSPECIFIED
        };

    public:

        /** Constructor. */
        ValueType () {}

        /** Destructor. */
        ~ValueType () {}

        /** Returns the param value type as string. */
        static const String& getValueTypeAsString ( ColladaType colladaValueType ) 
        {
            switch ( colladaValueType )
            {
            case ValueType::BOOL: return Constants::VALUE_TYPE_BOOL;
            case ValueType::BOOL2: return Constants::VALUE_TYPE_BOOL2;
            case ValueType::BOOL3: return Constants::VALUE_TYPE_BOOL3;
            case ValueType::BOOL4: return Constants::VALUE_TYPE_BOOL4;
            case ValueType::INT: return Constants::VALUE_TYPE_INT;
            case ValueType::INT2: return Constants::VALUE_TYPE_INT2;
            case ValueType::INT3: return Constants::VALUE_TYPE_INT3;
            case ValueType::INT4: return Constants::VALUE_TYPE_INT4;
            case ValueType::FLOAT: return Constants::VALUE_TYPE_FLOAT;
            case ValueType::FLOAT2: return Constants::VALUE_TYPE_FLOAT2;
            case ValueType::FLOAT3: return Constants::VALUE_TYPE_FLOAT3;
            case ValueType::FLOAT4: return Constants::VALUE_TYPE_FLOAT4;
            case ValueType::FLOAT2x2: return Constants::VALUE_TYPE_FLOAT2x2;
            case ValueType::FLOAT3x3: return Constants::VALUE_TYPE_FLOAT3x3;
            case ValueType::FLOAT4x4: return Constants::VALUE_TYPE_FLOAT4x4;
            case ValueType::STRING: return Constants::VALUE_TYPE_STRING;
            case ValueType::SURFACE: return Constants::VALUE_TYPE_SURFACE;
            case ValueType::SAMPLER_1D: return Constants::VALUE_TYPE_SAMPLER_1D;
            case ValueType::SAMPLER_2D: return Constants::VALUE_TYPE_SAMPLER_2D;
            case ValueType::SAMPLER_3D: return Constants::VALUE_TYPE_SAMPLER_3D;
            case ValueType::SAMPLER_CUBE: return Constants::VALUE_TYPE_SAMPLER_CUBE;
            case ValueType::SAMPLER_RECT: return Constants::VALUE_TYPE_SAMPLER_RECT;
            case ValueType::SAMPLER_DEPTH: return Constants::VALUE_TYPE_SAMPLER_DEPTH;
            case ValueType::VALUE_TYPE_UNSPECIFIED: 
            default: return Constants::EMPTY_STRING;
            }
        }

        static const ColladaType getValueTypeFromString ( const String& valueType )
        {
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_BOOL ) ) 
                return ValueType::BOOL;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_BOOL2 ) ) 
                return ValueType::BOOL2;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_BOOL3 ) ) 
                return ValueType::BOOL3;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_BOOL4 ) ) 
                return ValueType::BOOL4;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_INT ) ) 
                return ValueType::INT;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_INT2 ) ) 
                return ValueType::INT2;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_INT3 ) ) 
                return ValueType::INT3;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_INT4 ) ) 
                return ValueType::INT4;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_FLOAT ) ) 
                return ValueType::FLOAT;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_FLOAT2 ) ) 
                return ValueType::FLOAT2;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_FLOAT3 ) ) 
                return ValueType::FLOAT3;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_FLOAT4 ) ) 
                return ValueType::FLOAT4;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_FLOAT2x2 ) ) 
                return ValueType::FLOAT2x2;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_FLOAT3x3 ) ) 
                return ValueType::FLOAT3x3;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_FLOAT4x4 ) ) 
                return ValueType::FLOAT4x4;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_STRING ) ) 
                return ValueType::STRING;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_SURFACE ) ) 
                return ValueType::SURFACE;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_SAMPLER_1D ) ) 
                return ValueType::SAMPLER_1D;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_SAMPLER_2D ) ) 
                return ValueType::SAMPLER_2D;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_SAMPLER_3D ) ) 
                return ValueType::SAMPLER_3D;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_SAMPLER_CUBE ) ) 
                return ValueType::SAMPLER_CUBE;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_SAMPLER_RECT ) ) 
                return ValueType::SAMPLER_RECT;
            if ( COLLADABU::Utils::equalsIgnoreCase ( valueType, Constants::VALUE_TYPE_SAMPLER_DEPTH ) ) 
                return ValueType::SAMPLER_DEPTH;
            return ValueType::VALUE_TYPE_UNSPECIFIED;
        }
    };
}

#endif // __COLLADAFW_VALUE_TYPE_H__
