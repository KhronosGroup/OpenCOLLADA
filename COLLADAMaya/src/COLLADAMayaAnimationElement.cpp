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
#include "COLLADAMayaAnimationElement.h"


namespace COLLADAMaya
{

    // ----------------------------------------------------------
    AnimationElement::AnimationElement ( MPlug plug, const String& baseId,
                                         const String& subId, const String& nodeId,
                                         const String parameters[], SampleType sampleType )
            : mAnimatedCurves ( NULL ), mPlug ( plug ), mBaseId ( baseId ),
            mSubId ( subId ), mNodeId ( nodeId ), mIsCompound ( false ),
            mParameters ( parameters ), mSampleType ( sampleType ), mConversion ( NULL )
    {}

    // ----------------------------------------------------------
    AnimationElement::~AnimationElement()
    {
        if ( mConversion != NULL ) delete mConversion;

        {
            // Delete the added curves
            AnimationCurveList::iterator it = mAnimatedCurves.begin();

            for ( ; it!=mAnimatedCurves.end(); ++it )
            {
                AnimationCurve* curve = *it;
                delete curve;
            }

            mAnimatedCurves.clear();
        }

        {
            // Delete the childs
            AnimatedElementList::iterator it = mAnimatedChildElements.begin();

            for ( ; it!=mAnimatedChildElements.end(); ++it )
            {
                AnimationElement* animatedElement = *it;
                delete animatedElement;
            }

            mAnimatedChildElements.clear();
        }
    }

    // ----------------------------------------------------------
    uint AnimationElement::getDimension() const
    {
        if ( ( ( mSampleType & kSingle ) == kSingle ) ||
                ( ( mSampleType & kBoolean ) == kBoolean ) )
            return 1;

        if ( ( mSampleType & kVector ) == kVector )
            return 3;

        if ( ( mSampleType & kColour ) == kColour )
            return 4;

        if ( ( mSampleType & kMatrix ) == kMatrix )
            return 16;

        if ( ( ( mSampleType & kAngle ) == kAngle ) ||
                ( ( mSampleType & kQualifiedAngle ) == kQualifiedAngle ) )
        {
            MGlobal::displayError ( MString ( "Unknown dimension: " ) + mSampleType );
            return 0;
        }

        MGlobal::displayError ( MString ( "Unknown sampleType: " ) + mSampleType );

        return 0;
    }

    // --------------------------------------------------
    bool AnimationElement::hasCurves() const
    {
        if ( mAnimatedCurves.size() > 0 ) return true;

        AnimatedElementList::const_iterator it = mAnimatedChildElements.begin();

        for ( ; it!=mAnimatedChildElements.end(); ++it )
        {
            if ( ( *it )->hasCurves() ) return true;
        }

        return false;
    }

}