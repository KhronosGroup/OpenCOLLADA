/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MATransformAnimation.h"

#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWSkew.h"
#include "COLLADAFWTranslate.h"


namespace DAE2MA
{

    //------------------------------
	TransformAnimation::TransformAnimation()  
        : BaseAnimation ()
        , mTransformation (0)
        , mTransformPhase (0)
        , mIsJointTransform (false)
	{
	}
	
    //------------------------------
	TransformAnimation::~TransformAnimation()
	{
	}

    //------------------------------
    void TransformAnimation::setTransformation ( const COLLADAFW::Transformation* val )
    {
        mTransformation = val;
    }

} // namespace DAE2MA
