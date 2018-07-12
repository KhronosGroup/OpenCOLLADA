/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLInputUnshared.h"

using namespace COLLADAFW;


namespace COLLADASaxFWL
{

	//------------------------------
	InputUnshared::InputUnshared( InputSemantic::Semantic semantic, const COLLADABU::URI& source ) 
		: mSemantic ( semantic )
		, mSource ( source )
	{
	}

	//------------------------------
	InputUnshared::InputUnshared( const String& semantic, const String& source ) 
		: mSemantic ( getSemanticFromString(semantic) )
		, mSource ( source )
	{
	}


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
		size_t hash = COLLADABU::calculateHashUpper( semanticStr );
		switch ( hash )
		{
		case InputSemantic::BINORMAL_HASH: 
			return InputSemantic::BINORMAL;
		case InputSemantic::COLOR_HASH: 
			return InputSemantic::COLOR;
		case InputSemantic::CONTINUITY_HASH: 
			return InputSemantic::CONTINUITY;
		case InputSemantic::IMAGE_HASH: 
			return InputSemantic::IMAGE;
		case InputSemantic::INPUT_HASH: 
			return InputSemantic::INPUT;
		case InputSemantic::IN_TANGENT_HASH: 
			return InputSemantic::IN_TANGENT;
		case InputSemantic::INTERPOLATION_HASH: 
			return InputSemantic::INTERPOLATION;
		case InputSemantic::INV_BIND_MATRIX_HASH: 
			return InputSemantic::INV_BIND_MATRIX;
		case InputSemantic::JOINT_HASH: 
			return InputSemantic::JOINT;
		case InputSemantic::LINEAR_STEPS_HASH: 
			return InputSemantic::LINEAR_STEPS;
		case InputSemantic::MORPH_TARGET_HASH: 
			return InputSemantic::MORPH_TARGET;
		case InputSemantic::MORPH_WEIGHT_HASH: 
			return InputSemantic::MORPH_WEIGHT;
		case InputSemantic::NORMAL_HASH: 
			return InputSemantic::NORMAL;
		case InputSemantic::OUTPUT_HASH: 
			return InputSemantic::OUTPUT;
		case InputSemantic::OUT_TANGENT_HASH: 
			return InputSemantic::OUT_TANGENT;
		case InputSemantic::POSITION_HASH: 
			return InputSemantic::POSITION;
		case InputSemantic::TANGENT_HASH: 
			return InputSemantic::TANGENT;
		case InputSemantic::TEXBINORMAL_HASH: 
			return InputSemantic::TEXBINORMAL;
		case InputSemantic::TEXCOORD_HASH: 
			return InputSemantic::TEXCOORD;
		case InputSemantic::TEXTANGENT_HASH: 
			return InputSemantic::TEXTANGENT;
		case InputSemantic::UV_HASH: 
			return InputSemantic::UV;
		case InputSemantic::VERTEX_HASH: 
			return InputSemantic::VERTEX;
		case InputSemantic::WEIGHT_HASH: 
			return InputSemantic::WEIGHT;
		}

        return InputSemantic::UNKNOWN;
    }

}
