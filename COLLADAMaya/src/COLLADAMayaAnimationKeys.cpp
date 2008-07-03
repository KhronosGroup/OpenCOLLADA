/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAnimationKeys.h"


namespace COLLADAMaya
{

    // --------------------------------------------
    AnimationMKey::AnimationMKey ( uint _dimension )
            : dimension ( _dimension )
    {
        output = new float[dimension];
    }

    // --------------------------------------------
    AnimationMKey::~AnimationMKey()
    {
        delete output;
    }

    // --------------------------------------------
    AnimationMKeyBezier::AnimationMKeyBezier ( uint dimension )
            : AnimationMKey ( dimension )
    {
        inTangent = new TangentPoint[dimension];
        outTangent = new TangentPoint[dimension];
    }

    // --------------------------------------------
    AnimationMKeyBezier::~AnimationMKeyBezier()
    {
        delete[] inTangent;
        delete[] outTangent;
    }

    // --------------------------------------------
    AnimationMKeyTCB::AnimationMKeyTCB ( uint dimension )
            : AnimationMKey ( dimension )
    {
        tension = new float[dimension];
        continuity = new float[dimension];
        bias = new float[dimension];
        easeIn = new float[dimension];
        easeOut = new float[dimension];
    }

    // --------------------------------------------
    AnimationMKeyTCB::~AnimationMKeyTCB()
    {
        delete tension;
        delete continuity;
        delete bias;
        delete easeIn;
        delete easeOut;
    }
}