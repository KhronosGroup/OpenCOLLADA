/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAnimationElement.h"
#include "COLLADAMayaAnimationCurves.h"


namespace COLLADAMaya
{

    // ----------------------------------------------------------
    AnimationElement::AnimationElement (
        MPlug plug,
        const String& baseId,
        const String& subId,
        const String& nodeId,
        const String parameters[],
        const bool convertUnits,
        SampleType sampleType )
    : mBaseId ( baseId )
    , mNodeId ( nodeId )
    , mTargetSid ( subId )
    , mPlug ( plug )
    , mIsSampling ( false )
    , mParameters ( parameters )
    , mSampleType ( sampleType )
    , mAnimatedCurves ( NULL )
    , mConversion ( NULL )
    , mIsCompound ( false )
    , mIsRelativeAnimation ( false )
    , mArrayElement ( -1 )
    , mConvertUnits ( convertUnits )
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

//         if ( ( ( mSampleType & kAngle ) == kAngle ) ||
//                 ( ( mSampleType & kQualifiedAngle ) == kQualifiedAngle ) )
//         {
//             MGlobal::displayError ( MString ( "Unknown dimension: " ) + mSampleType );
//             return 0;
//         }

        if ( ( mSampleType & kBoolean ) == kBoolean )
            return 1;

        else if ( ( mSampleType & kMatrix ) == kMatrix )
            return 16;

        else if ( ( mSampleType & kColour ) == kColour )
            return 4;

        else if ( ( mSampleType & kVector ) == kVector )
            return 3;

        else if ( ( ( mSampleType & kSingle ) == kSingle ) ||
            ( ( mSampleType & kAngle ) == kAngle ) ||
            ( ( mSampleType & kQualifiedAngle ) == kQualifiedAngle ) )
            return 1;

        std::cerr << "Unknown sampleType: " << mSampleType << std::endl;

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
