/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAStreamWriter.h"
#include "COLLADACameraOptic.h"
#include "COLLADASWC.h"
#include <assert.h>

namespace COLLADA
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
    {}

    // ---------------------------------------------------
    void BaseOptic::add () const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_OPTICS );
        mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE_COMMON );

        addTextureExtraTechniques ( *mSW );

        this->addTypeSpecificInfos ();

        mSW->closeElement(); // COLLADA_ELEMENT_TECHNIQUE_COMMON
        mSW->closeElement(); // COLLADA_ELEMENT_OPTICS
    }

    // --------------------------------------------
    void PerspectiveOptic::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_CAMERA_PERSPECTIVE );

        assert ( !( !mHasXFov && !mHasYFov) );
        assert ( !( mHasAspectRatio && mHasXFov && mHasYFov) );
        assert ( mHasZNear );
        assert ( mHasZFar );

        if ( mHasXFov )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_XFOV );
            mSW->appendValues ( mXFov );
            mSW->closeElement(); // COLLADA_ELEMENT_XFOV
        }

        if ( mHasYFov )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_YFOV );
            mSW->appendValues ( mYFov );
            mSW->closeElement(); // COLLADA_ELEMENT_YFOV
        }

        if ( mHasAspectRatio )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_ASPECT_RATIO );
            mSW->appendValues ( mAspectRatio );
            mSW->closeElement(); // COLLADA_ELEMENT_ASPECT_RATIO
        }

        mSW->openElement ( CSWC::COLLADA_ELEMENT_ZNEAR );
        mSW->appendValues ( mZNear );
        mSW->closeElement(); // COLLADA_ELEMENT_ZNEAR

        mSW->openElement ( CSWC::COLLADA_ELEMENT_ZFAR );
        mSW->appendValues ( mZFar );
        mSW->closeElement(); // COLLADA_ELEMENT_ZFAR

        mSW->closeElement(); // COLLADA_ELEMENT_CAMERA_PERSPECTIVE
    }

    // --------------------------------------------
    void OrthographicOptic::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_CAMERA_ORTHOGRAPHIC );

        assert ( !mHasXMag && !mHasYMag );
        assert ( mHasAspectRatio && mHasXMag && mHasYMag );
        assert ( !mHasZNear );
        assert ( !mHasZFar );

        if ( mHasXMag )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_XMAG );
            mSW->appendValues ( mXMag );
            mSW->closeElement(); // COLLADA_ELEMENT_XMAG
        }

        if ( mHasYMag )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_YMAG );
            mSW->appendValues ( mYMag );
            mSW->closeElement(); // COLLADA_ELEMENT_YMAG
        }

        if ( mHasAspectRatio )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_ASPECT_RATIO );
            mSW->appendValues ( mAspectRatio );
            mSW->closeElement(); // COLLADA_ELEMENT_ASPECT_RATIO
        }

        mSW->openElement ( CSWC::COLLADA_ELEMENT_ZNEAR );
        mSW->appendValues ( mZNear );
        mSW->closeElement(); // COLLADA_ELEMENT_ZNEAR

        mSW->openElement ( CSWC::COLLADA_ELEMENT_ZFAR );
        mSW->appendValues ( mZFar );
        mSW->closeElement(); // COLLADA_ELEMENT_ZFAR

        mSW->closeElement(); // COLLADA_ELEMENT_CAMERA_ORTHOGRAPHIC
    }


} //namespace COLLADA
