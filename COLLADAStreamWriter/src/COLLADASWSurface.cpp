/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASWStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWSurface.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    const String Surface::SURFACE_SID_SUFFIX = "-surface";

    //---------------------------------------------------------------
    Surface::Surface ( SurfaceType surfaceType, const String& sid )
        : BaseExtraTechnique ()
        , mSid ( sid )
        , mType ( surfaceType )
        , mFormat ( "" )
        , mMipLevels ( 0 )
        , mMipmapGenerate ( false )
    {}


    //---------------------------------------------------------------
    Surface::Surface()
        : BaseExtraTechnique ()
        , mSid ( "" )
        , mType ( SURFACE_TYPE_UNSPECIFIED )
    {}

    //---------------------------------------------------------------
    const String& Surface::getSurfaceTypeString ( SurfaceType surfaceType )
    {
        switch ( surfaceType )
        {
        case Surface::SURFACE_TYPE_1D:
            return CSWC::CSW_SURFACE_TYPE_1D;
        case Surface::SURFACE_TYPE_2D:
            return CSWC::CSW_SURFACE_TYPE_2D;
        case Surface::SURFACE_TYPE_3D:
            return CSWC::CSW_SURFACE_TYPE_3D;
        case Surface::SURFACE_TYPE_CUBE:
            return CSWC::CSW_SURFACE_TYPE_CUBE;
        case Surface::SURFACE_TYPE_DEPTH:
            return CSWC::CSW_SURFACE_TYPE_DEPTH;
        case Surface::SURFACE_TYPE_RECT:
            return CSWC::CSW_SURFACE_TYPE_RECT;
        case Surface::SURFACE_TYPE_UNTYPED:
            return CSWC::CSW_SURFACE_TYPE_UNTYPED;
        default:
            return CSWC::EMPTY_STRING;
        }
    }

    // ----------------------------------------
    void Surface::add ( StreamWriter* sw ) const
    {
        sw->openElement ( CSWC::CSW_ELEMENT_SURFACE );
        sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_TYPE, getSurfaceTypeString ( mType ) );

        getInitOption ().add ( sw );

        if ( !mFormat.empty() )
            sw->appendTextElement ( CSWC::CSW_ELEMENT_FORMAT, mFormat );

        if ( mFormatHint.getIsInitialized() ) mFormatHint.add();

        if ( !( mSize.width==0 && mSize.height==0 && mSize.depth==0 ) )
        {
            sw->openElement ( CSWC::CSW_ELEMENT_SIZE );
            sw->appendValues( mSize.width, mSize.height, mSize.depth );
            sw->closeElement();
        }

        if ( !( mViewportRatio.width==1 && mViewportRatio.height==1 ) )
        {
            sw->openElement ( CSWC::CSW_ELEMENT_VIEWPORT_RATIO );
            sw->appendValues( mViewportRatio.width, mViewportRatio.height );
            sw->closeElement();
        }

        if ( mMipLevels != 0 )
        {
            sw->openElement ( CSWC::CSW_ELEMENT_MIP_LEVELS );
            sw->appendValues( mMipLevels );
            sw->closeElement();
        }

        if ( mMipmapGenerate )
        {
            sw->openElement ( CSWC::CSW_ELEMENT_MIPMAP_GENERATE );
            sw->appendValues( mMipmapGenerate );
            sw->closeElement();
        }

        this->addExtraTechniques ( sw );

        // addGenerator()

        sw->closeElement(); // COLLADASW_ELEMENT_SURFACE
    }

}
