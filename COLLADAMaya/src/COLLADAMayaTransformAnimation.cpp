/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaTransformAnimation.h"

#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWSkew.h"
#include "COLLADAFWTranslate.h"


namespace COLLADAMaya
{

    //------------------------------
	TransformAnimation::TransformAnimation() : mTransformation (0)
	{
	}
	
    //------------------------------
	TransformAnimation::~TransformAnimation()
	{
	}

    //------------------------------
    void TransformAnimation::setTransformation ( const COLLADAFW::Transformation* val )
    {
        if ( val == 0 ) mTransformation = 0;
        switch ( val->getTransformationType () )
        {
        case COLLADAFW::Transformation::ROTATE:
            {
                COLLADAFW::Rotate* rotation = ( COLLADAFW::Rotate* ) val;
                mTransformation = new COLLADAFW::Rotate ( *rotation );
                break;
            }
        case COLLADAFW::Transformation::SCALE:
            {
                COLLADAFW::Scale* scale = ( COLLADAFW::Scale* ) val;
                mTransformation = new COLLADAFW::Scale ( *scale );
                break;
            }
        case COLLADAFW::Transformation::SKEW:
            {
                COLLADAFW::Skew* skew = ( COLLADAFW::Skew* ) val;
                mTransformation = new COLLADAFW::Skew ( *skew );
                break;
            }
        case COLLADAFW::Transformation::TRANSLATE:
            {
                COLLADAFW::Translate* translate = ( COLLADAFW::Translate* ) val;
                mTransformation = new COLLADAFW::Translate ( *translate );
                break;
            }
        default:
            MGlobal::displayError ( "No valid animatable transformation!" );
        }
    }
} // namespace COLLADAMaya
