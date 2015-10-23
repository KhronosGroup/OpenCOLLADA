/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_VALUE_TYPES_H__
#define __COLLADASTREAMWRITER_VALUE_TYPES_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
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
			DOUBLE, DOUBLE2, DOUBLE3, DOUBLE4,
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
        static const String& getColladaTypeString ( ColladaType colladaValueType ) 
        {
            switch ( colladaValueType )
            {
            case ValueType::BOOL: return CSWC::CSW_VALUE_TYPE_BOOL;
            case ValueType::BOOL2: return CSWC::CSW_VALUE_TYPE_BOOL2;
            case ValueType::BOOL3: return CSWC::CSW_VALUE_TYPE_BOOL3;
            case ValueType::BOOL4: return CSWC::CSW_VALUE_TYPE_BOOL4;
            case ValueType::INT: return CSWC::CSW_VALUE_TYPE_INT;
            case ValueType::INT2: return CSWC::CSW_VALUE_TYPE_INT2;
            case ValueType::INT3: return CSWC::CSW_VALUE_TYPE_INT3;
            case ValueType::INT4: return CSWC::CSW_VALUE_TYPE_INT4;
            case ValueType::FLOAT: return CSWC::CSW_VALUE_TYPE_FLOAT;
            case ValueType::FLOAT2: return CSWC::CSW_VALUE_TYPE_FLOAT2;
            case ValueType::FLOAT3: return CSWC::CSW_VALUE_TYPE_FLOAT3;
            case ValueType::FLOAT4: return CSWC::CSW_VALUE_TYPE_FLOAT4;
            case ValueType::FLOAT2x2: return CSWC::CSW_VALUE_TYPE_FLOAT2x2;
            case ValueType::FLOAT3x3: return CSWC::CSW_VALUE_TYPE_FLOAT3x3;
            case ValueType::FLOAT4x4: return CSWC::CSW_VALUE_TYPE_FLOAT4x4;
			case ValueType::DOUBLE: return CSWC::CSW_VALUE_TYPE_DOUBLE;
            case ValueType::DOUBLE2: return CSWC::CSW_VALUE_TYPE_DOUBLE2;
            case ValueType::DOUBLE3: return CSWC::CSW_VALUE_TYPE_DOUBLE3;
            case ValueType::DOUBLE4: return CSWC::CSW_VALUE_TYPE_DOUBLE4;
            case ValueType::STRING: return CSWC::CSW_VALUE_TYPE_STRING;
            case ValueType::SURFACE: return CSWC::CSW_VALUE_TYPE_SURFACE;
            case ValueType::SAMPLER_1D: return CSWC::CSW_VALUE_TYPE_SAMPLER_1D;
            case ValueType::SAMPLER_2D: return CSWC::CSW_VALUE_TYPE_SAMPLER_2D;
            case ValueType::SAMPLER_3D: return CSWC::CSW_VALUE_TYPE_SAMPLER_3D;
            case ValueType::SAMPLER_CUBE: return CSWC::CSW_VALUE_TYPE_SAMPLER_CUBE;
            case ValueType::SAMPLER_RECT: return CSWC::CSW_VALUE_TYPE_SAMPLER_RECT;
            case ValueType::SAMPLER_DEPTH: return CSWC::CSW_VALUE_TYPE_SAMPLER_DEPTH;
            case ValueType::VALUE_TYPE_UNSPECIFIED: 
            default: return CSWC::EMPTY_STRING;
            }
        }

    };
}

#endif // __COLLADASTREAMWRITER_VALUE_TYPES_H__
