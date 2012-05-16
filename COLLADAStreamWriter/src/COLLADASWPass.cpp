/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWPass.h"

namespace COLLADASW
{

    // ----------------------------
    Pass::Pass( StreamWriter* sw ) : ElementWriter ( sw )
    {

    }

    // ----------------------------
    void Pass::openPass( const String &sid /*= "" */ )
    {
        mPassCloser = mSW->openElement ( CSWC::CSW_ELEMENT_PASS );
        if ( !sid.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_SID, sid );
    }

    // ----------------------------
    void Pass::closePass()
    {
        mPassCloser.close();
    }

    // ----------------------------
    void Pass::addColorTarget( 
        const String& val, 
        const int index/*=-1*/, 
        const int slice/*=-1*/, 
        const int mip/*=-1*/, 
        SurfaceInitOption::Face face /*= SurfaceInitOption::POSITIVE_X */ )
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_COLOR_TARGET );
        if ( index > -1 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_INDEX, index );
        if ( slice > -1 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SLICE, slice );
        if ( mip > -1 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_MIP, mip );
        if ( face != SurfaceInitOption::POSITIVE_X )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_FACE, SurfaceInitOption::getFaceString ( face ) );

        mSW->appendValues ( val );
        mSW->closeElement ();
    }

    // ----------------------------
    void Pass::addDepthTarget( const String& val, const int index/*=-1*/, const int slice/*=-1*/, const int mip/*=-1*/, SurfaceInitOption::Face face /*= SurfaceInitOption::POSITIVE_X */ )
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_DEPTH_TARGET );
        if ( index > -1 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_INDEX, index );
        if ( slice > -1 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SLICE, slice );
        if ( mip > -1 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_MIP, mip );
        if ( face != SurfaceInitOption::POSITIVE_X )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_FACE, SurfaceInitOption::getFaceString ( face ) );

        mSW->appendValues ( val );
        mSW->closeElement ();
    }

    // ----------------------------
    void Pass::addStencilTarget( const String& val, const int index/*=-1*/, const int slice/*=-1*/, const int mip/*=-1*/, SurfaceInitOption::Face face /*= SurfaceInitOption::POSITIVE_X */ )
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_STENCIL_TARGET );
        if ( index > -1 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_INDEX, index );
        if ( slice > -1 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SLICE, slice );
        if ( mip > -1 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_MIP, mip );
        if ( face != SurfaceInitOption::POSITIVE_X )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_FACE, SurfaceInitOption::getFaceString ( face ) );

        mSW->appendValues ( val );
        mSW->closeElement ();
    }

    // ----------------------------
    void Pass::addColorClear( const Color& val, unsigned int index/*=0 */ )
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_COLOR_CLEAR );
        if ( index > 0 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_INDEX, index );
        mSW->appendValues ( val );
        mSW->closeElement ();
    }

    // ----------------------------
    void Pass::addDepthClear( const float val, unsigned int index/*=0 */ )
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_DEPTH_CLEAR );
        if ( index > 0 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_INDEX, index );
        mSW->appendValues ( val );
    }

    // ----------------------------
    void Pass::addStencilClear( const unsigned char val, unsigned int index/*=0 */ )
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_STENCIL_CLEAR );
        if ( index > 0 )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_INDEX, index );
        mSW->appendValues ( val );
    }

    // ----------------------------
    void Pass::addDraw( const String& draw )
    {
        mSW->appendTextElement ( CSWC::CSW_ELEMENT_DRAW, draw );
    }
}
