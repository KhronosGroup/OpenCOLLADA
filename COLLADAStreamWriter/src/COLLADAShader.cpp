/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAShader.h"

namespace COLLADA
{

    // ----------------------------
    Shader::Shader( StreamWriter* sw, String stage/*="" */ ) : ElementWriter ( sw ), mStage ( stage )
    {

    }

    // ----------------------------
    void Shader::openShader()
    {
        mShaderCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_SHADER );

        if ( !mStage.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_STAGE, mStage );
    }

    // ----------------------------
    void Shader::closeShader()
    {
        mShaderCloser.close();
    }

    // ----------------------------
    void Shader::addCompilerTarget( const String& val )
    {
        mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_COMPILER_TARGET, val );
    }

    // ----------------------------
    void Shader::addCompilerOptions( const String& val )
    {
        mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_COMPILER_OPTIONS, val );
    }

    // ----------------------------
    void Shader::addName( const String& name, const String& source/*="" */ )
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_NAME );
        if ( !source.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SOURCE, source );
        mSW->appendText ( name );
        mSW->closeElement ();
    }

}