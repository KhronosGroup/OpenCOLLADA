/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWCameraOptic.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    // ---------------------------------------------------
    BaseOptic::BaseOptic ( StreamWriter* streamWriter )
        : ElementWriter ( streamWriter )
        , BaseExtraTechnique ( )
        , mHasXFov ( false )
        , mHasYFov ( false )
        , mHasXMag ( false )
        , mHasYMag ( false )
        , mHasAspectRatio ( false )
        , mHasZNear ( false )
        , mHasZFar ( false )
        , mXMagSid ( "" )
        , mXFovSid ( "" )
        , mYFovSid ( "" )
        , mZNearSid ( "" )
        , mZFarSid ( "" )
    {}

    // ---------------------------------------------------
    void BaseOptic::add () const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_OPTICS );
        mSW->openElement ( CSWC::CSW_ELEMENT_TECHNIQUE_COMMON );

        addExtraTechniques ( mSW );

        this->addTypeSpecificInfos ();

        mSW->closeElement(); // COLLADASW_ELEMENT_TECHNIQUE_COMMON
        mSW->closeElement(); // COLLADASW_ELEMENT_OPTICS
    }

    // --------------------------------------------
    void BaseOptic::setZFar( const float val, const bool useDefaultSid /*= false*/, const String& sid/*="" */ )
    {
        mZFar = val;
        if ( useDefaultSid ) mZFarSid = CSWC::CSW_ELEMENT_ZFAR;
        else mZFarSid = sid; 
        mHasZFar = true;
    }

    // --------------------------------------------
    void BaseOptic::setZNear( const float val, const bool useDefaultSid /*= false*/, const String& sid/*="" */ )
    {
        mZNear = val; 
        if ( useDefaultSid ) mZNearSid = CSWC::CSW_ELEMENT_ZNEAR;
        else mZNearSid = sid; 
        mHasZNear = true;
    }

    // --------------------------------------------
    void BaseOptic::setAspectRatio( float val, const bool useDefaultSid /*= false*/, const String& sid/*="" */ )
    {
        mAspectRatio = val; 
        if ( useDefaultSid ) mAspectRatioSid = CSWC::CSW_ELEMENT_ASPECT_RATIO;
        else mAspectRatioSid = sid;
        mHasAspectRatio = true;
    }

    // --------------------------------------------
    void BaseOptic::setXFov( float val, const bool useDefaultSid /*= false*/, const String& sid/*="" */ )
    {
        mXFov = val; 
        if ( useDefaultSid ) mXFovSid = CSWC::CSW_ELEMENT_XFOV;
        else mXFovSid = sid; 
        mHasXFov = true;
    }

    // --------------------------------------------
    void BaseOptic::setYFov( float val, const bool useDefaultSid /*= false*/, const String& sid/*="" */ )
    {
        mYFov = val; 
        if ( useDefaultSid ) mYFovSid = CSWC::CSW_ELEMENT_YFOV;
        else mYFovSid = sid; 
        mHasYFov = true;
    }

    // --------------------------------------------
    void BaseOptic::setXMag( float val, bool useDefaultSid /*= false*/, const String& sid/*="" */ )
    {
        mXMag = val; 
        if ( useDefaultSid ) mXMagSid = CSWC::CSW_ELEMENT_XMAG;
        else mXMagSid = sid; 
        mHasXMag = true;
    }

    // --------------------------------------------
    void BaseOptic::setYMag( float val, const bool useDefaultSid /*= false*/, const String& sid/*="" */ )
    {
        mYMag = val; 
        if ( useDefaultSid ) mYMagSid = CSWC::CSW_ELEMENT_YMAG;
        else mYMagSid = sid;
        mHasYMag = true;
    }

    // --------------------------------------------
    void PerspectiveOptic::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_CAMERA_PERSPECTIVE );

		COLLADABU_ASSERT ( !( !mHasXFov && !mHasYFov) );
        COLLADABU_ASSERT ( !( mHasAspectRatio && mHasXFov && mHasYFov) );
        COLLADABU_ASSERT ( mHasZNear );
        COLLADABU_ASSERT ( mHasZFar );

        if ( mHasXFov )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_XFOV );
            if ( !mXFovSid.empty() )
                mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_SID, mXFovSid );
            mSW->appendValues ( mXFov );
            mSW->closeElement(); // COLLADASW_ELEMENT_XFOV
        }

        if ( mHasYFov )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_YFOV );
            if ( !mYFovSid.empty() )
                mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_SID, mYFovSid );
            mSW->appendValues ( mYFov );
            mSW->closeElement(); // COLLADASW_ELEMENT_YFOV
        }

        if ( mHasAspectRatio )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_ASPECT_RATIO );
            mSW->appendValues ( mAspectRatio );
            mSW->closeElement(); // COLLADASW_ELEMENT_ASPECT_RATIO
        }

        mSW->openElement ( CSWC::CSW_ELEMENT_ZNEAR );
        if ( !mZNearSid.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_SID, mZNearSid );
        mSW->appendValues ( mZNear );
        mSW->closeElement(); // COLLADASW_ELEMENT_ZNEAR

        mSW->openElement ( CSWC::CSW_ELEMENT_ZFAR );
        if ( !mZFarSid.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_SID, mZFarSid );
        mSW->appendValues ( mZFar );
        mSW->closeElement(); // COLLADASW_ELEMENT_ZFAR

        mSW->closeElement(); // COLLADASW_ELEMENT_CAMERA_PERSPECTIVE
    }

    // --------------------------------------------
    void OrthographicOptic::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_CAMERA_ORTHOGRAPHIC );

        COLLADABU_ASSERT ( !( !mHasXMag && !mHasYMag ) );
        COLLADABU_ASSERT ( !( mHasAspectRatio && mHasXMag && mHasYMag ) );
        COLLADABU_ASSERT ( mHasZNear );
        COLLADABU_ASSERT ( mHasZFar );

        if ( mHasXMag )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_XMAG );
            if ( !mXMagSid.empty() )
                mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_SID, mXMagSid );
            mSW->appendValues ( mXMag );
            mSW->closeElement(); // COLLADASW_ELEMENT_XMAG
        }

        if ( mHasYMag )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_YMAG );
            mSW->appendValues ( mYMag );
            mSW->closeElement(); // COLLADASW_ELEMENT_YMAG
        }

        if ( mHasAspectRatio )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_ASPECT_RATIO );
            mSW->appendValues ( mAspectRatio );
            mSW->closeElement(); // COLLADASW_ELEMENT_ASPECT_RATIO
        }

        mSW->openElement ( CSWC::CSW_ELEMENT_ZNEAR );
        if ( !mZNearSid.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_SID, mZNearSid );
        mSW->appendValues ( mZNear );
        mSW->closeElement(); // COLLADASW_ELEMENT_ZNEAR

        mSW->openElement ( CSWC::CSW_ELEMENT_ZFAR );
        if ( !mZFarSid.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_SID, mZFarSid );
        mSW->appendValues ( mZFar );
        mSW->closeElement(); // COLLADASW_ELEMENT_ZFAR

        mSW->closeElement(); // COLLADASW_ELEMENT_CAMERA_ORTHOGRAPHIC
    }


} //namespace COLLADASW
