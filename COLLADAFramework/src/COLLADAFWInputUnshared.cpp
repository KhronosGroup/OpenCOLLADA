/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWInputUnshared.h"


namespace COLLADAFW
{

    // ----------------------------
    const String& InputUnshared::getSemanticAsString ( const InputSemantic::Semantic semantic )
    {
        switch ( semantic )
        {
        case InputSemantic::BINORMAL: return Constants::SEMANTIC_BINORMAL;
        case InputSemantic::COLOR: return Constants::SEMANTIC_COLOR;
        case InputSemantic::CONTINUITY: return Constants::SEMANTIC_CONTINUITY;
        case InputSemantic::IMAGE: return Constants::SEMANTIC_IMAGE;
        case InputSemantic::INPUT: return Constants::SEMANTIC_INPUT;
        case InputSemantic::IN_TANGENT: return Constants::SEMANTIC_IN_TANGENT;
        case InputSemantic::INTERPOLATION: return Constants::SEMANTIC_INTERPOLATION;
        case InputSemantic::INV_BIND_MATRIX: return Constants::SEMANTIC_INV_BIND_MATRIX;
        case InputSemantic::JOINT: return Constants::SEMANTIC_JOINT;
        case InputSemantic::LINEAR_STEPS: return Constants::SEMANTIC_LINEAR_STEPS;
        case InputSemantic::MORPH_TARGET: return Constants::SEMANTIC_MORPH_TARGET;
        case InputSemantic::MORPH_WEIGHT: return Constants::SEMANTIC_MORPH_WEIGHT;
        case InputSemantic::NORMAL: return Constants::SEMANTIC_NORMAL;
        case InputSemantic::OUTPUT: return Constants::SEMANTIC_OUTPUT;
        case InputSemantic::OUT_TANGENT: return Constants::SEMANTIC_OUT_TANGENT;
        case InputSemantic::POSITION: return Constants::SEMANTIC_POSITION;
        case InputSemantic::TANGENT: return Constants::SEMANTIC_TANGENT;
        case InputSemantic::TEXBINORMAL: return Constants::SEMANTIC_TEXBINORMAL;
        case InputSemantic::TEXCOORD: return Constants::SEMANTIC_TEXCOORD;
        case InputSemantic::TEXTANGENT: return Constants::SEMANTIC_TEXTANGENT;
        case InputSemantic::UV: return Constants::SEMANTIC_UV;
        case InputSemantic::VERTEX: return Constants::SEMANTIC_VERTEX;
        case InputSemantic::WEIGHT: return Constants::SEMANTIC_WEIGHT;
        case InputSemantic::UNKNOWN:  
        default: return Constants::EMPTY_STRING;
        }
    }

    // ----------------------------
    const InputSemantic::Semantic InputUnshared::getSemanticFromString ( const String& semanticStr )
    {
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_BINORMAL ) )
            return InputSemantic::BINORMAL;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_COLOR ) )
            return InputSemantic::COLOR;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_CONTINUITY ) )
            return InputSemantic::CONTINUITY;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_IMAGE ) )
            return InputSemantic::IMAGE;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_INPUT ) )
            return InputSemantic::INPUT;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_IN_TANGENT ) )
            return InputSemantic::IN_TANGENT;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_INTERPOLATION ) )
            return InputSemantic::INTERPOLATION;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_INV_BIND_MATRIX ) )
            return InputSemantic::INV_BIND_MATRIX;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_JOINT ) )
            return InputSemantic::JOINT;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_LINEAR_STEPS ) )
            return InputSemantic::LINEAR_STEPS;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_MORPH_TARGET ) )
            return InputSemantic::MORPH_TARGET;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_MORPH_WEIGHT ) )
            return InputSemantic::MORPH_WEIGHT;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_NORMAL ) )
            return InputSemantic::NORMAL;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_OUTPUT ) )
            return InputSemantic::OUTPUT;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_OUT_TANGENT ) )
            return InputSemantic::OUT_TANGENT;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_POSITION ) )
            return InputSemantic::POSITION;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_TANGENT ) )
            return InputSemantic::TANGENT;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_TEXBINORMAL ) )
            return InputSemantic::TEXBINORMAL;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_TEXCOORD ) )
            return InputSemantic::TEXCOORD;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_TEXTANGENT ) )
            return InputSemantic::TEXTANGENT;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_UV ) )
            return InputSemantic::UV;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_VERTEX ) )
            return InputSemantic::VERTEX;
        if ( COLLADASW::Utils::equalsIgnoreCase ( semanticStr, Constants::SEMANTIC_WEIGHT ) )
            return InputSemantic::WEIGHT;

        return InputSemantic::UNKNOWN;
    }
}