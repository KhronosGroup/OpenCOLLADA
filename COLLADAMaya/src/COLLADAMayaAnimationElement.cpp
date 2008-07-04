/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAnimationElement.h"
#include "COLLADAMayaAnimationCurves.h"


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