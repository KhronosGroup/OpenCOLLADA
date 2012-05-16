/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWShader.h"

namespace COLLADASW
{

    // ----------------------------
    Shader::Shader ( 
        StreamWriter* sw, 
        const Scope& scope/*=SCOPE_UNDEFINED*/, 
        const Stage& stage/*=STAGE_UNDEFINED */ ) 
    : ElementWriter ( sw )
    , mScope ( scope )
    , mStage ( stage )
    {}

    // ----------------------------
    void Shader::openShader()
    {
        mShaderCloser = mSW->openElement ( CSWC::CSW_ELEMENT_SHADER );

        const String& stageName = getStageNameByScopeAndStage ( mScope, mStage );
        if ( !stageName.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_STAGE, getStageNameByScopeAndStage ( mScope, mStage ) );
    }

    // ----------------------------
    void Shader::closeShader()
    {
        mShaderCloser.close();
    }

    // ----------------------------
    void Shader::addCompilerTarget( const String& val )
    {
        mSW->appendTextElement ( CSWC::CSW_ELEMENT_COMPILER_TARGET, val );
    }

    // ----------------------------
    void Shader::addCompilerOptions( const String& val )
    {
        mSW->appendTextElement ( CSWC::CSW_ELEMENT_COMPILER_OPTIONS, val );
    }

    // ----------------------------
    void Shader::addName( const String& name, const String& source/*="" */ )
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_NAME );
        if ( !source.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SOURCE, source );
        mSW->appendText ( name );
        mSW->closeElement ();
    }

    // ----------------------------
    const String& Shader::getStageNameByScopeAndStage ( 
        const Shader::Scope& scope, 
        const Shader::Stage& stage )
    {
        switch ( scope )
        {
        case SCOPE_CG: 
            {
                switch ( stage )
                {
                case STAGE_VERTEX: return CSWC::CSW_FX_SHADER_STAGE_VERTEX;
                case STAGE_FRAGMENT: return CSWC::CSW_FX_SHADER_STAGE_FRAGMENT;
                case STAGE_UNDEFINED: return CSWC::EMPTY_STRING;
                }
            }
        case SCOPE_GLSL: 
            {
                switch ( stage )
                {
                case STAGE_VERTEX: return CSWC::CSW_FX_SHADER_STAGE_VERTEXPROGRAM;
                case STAGE_FRAGMENT: return CSWC::CSW_FX_SHADER_STAGE_FRAGMENTPROGRAM;
                case STAGE_UNDEFINED: return CSWC::EMPTY_STRING;
                }
            }
        case SCOPE_UNDEFINED: 
        default:
            return CSWC::EMPTY_STRING;
        }
    }

    // ----------------------------
    const Shader::Stage Shader::getStageTypeByName ( const String& stageName )
    {
        if ( Utils::equalsIgnoreCase ( stageName, CSWC::CSW_FX_SHADER_STAGE_VERTEX ) ||
            Utils::equalsIgnoreCase ( stageName, CSWC::CSW_FX_SHADER_STAGE_VERTEXPROGRAM ) )
        {
            return STAGE_VERTEX;
        }
        else if ( Utils::equalsIgnoreCase ( stageName, CSWC::CSW_FX_SHADER_STAGE_FRAGMENT ) ||
            Utils::equalsIgnoreCase ( stageName, CSWC::CSW_FX_SHADER_STAGE_FRAGMENTPROGRAM ) )
        {
            return STAGE_FRAGMENT;
        }
        else return STAGE_UNDEFINED;
    }
}
