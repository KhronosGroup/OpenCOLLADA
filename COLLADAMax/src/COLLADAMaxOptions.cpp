/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxOptions.h"

namespace COLLADAMax
{


    Options::Options()
    {

        mNormals = true;
        mTriangulate = false;
        mXrefs = false;
        mTangents = false;
        mAnimations = false;
        mSampleAnimation = false;
        mCreateClip = false;
        mBakeMatrices = false;
        mRelativePaths = true;
        mSelectionOnly = false;

        mAnimationStart = TIME_INITIAL_POSE;
        mAnimationEnd = TIME_PosInfinity;

    }



}
