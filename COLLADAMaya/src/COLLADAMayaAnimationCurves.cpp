/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAnimationCurves.h"

#include "COLLADAMathUtils.h"


namespace COLLADAMaya
{

    // Declaring the type of evaluation for curves once.
    template <class T>
    bool BaseAnimationCurve<T>::mIs2DEvaluation = true;

    // --------------------------------------------------
    AnimationCurve::AnimationCurve ( const AnimationElement* parent, const String& baseId )
            : BaseAnimationCurve ( parent, baseId ) {}

    // --------------------------------------------------
    AnimationKey* AnimationCurve::addKey ( COLLADA::LibraryAnimations::InterpolationType interpolation )
    {
        AnimationKey* key;

        switch ( interpolation )
        {

        case COLLADA::LibraryAnimations::STEP:
            key = new AnimationKey;
            break;

        case COLLADA::LibraryAnimations::LINEAR:
            key = new AnimationKey;
            break;

        case COLLADA::LibraryAnimations::BEZIER:
            key = new AnimationKeyBezier;
            this->setHasTangents ( true );
            break;

        case COLLADA::LibraryAnimations::TCB:
            key = new AnimationKeyTCB;
            this->setHasTCB ( true );
            break;

        default:
            key = new AnimationKey;
            break;
        }

        key->interpolation = interpolation;

        keys.push_back ( key );

        return key;
    }

    // ----------------------------------------------------
    float AnimationCurve::evaluate ( float input ) const
    {
        bool evaluated = false;
        float evaluatedInput = 0.0f;

        // Check for empty curves and poses (curves with 1 key).

        if ( keys.size() == 0 ) return 0.0f;

        if ( keys.size() == 1 ) return keys.front()->output;

        float inputStart = keys.front()->input;

        float inputEnd = keys.back()->input;

        float inputSpan = inputEnd - inputStart;

        float outputStart = keys.front()->output;

        float outputEnd = keys.back()->output;

        float outputSpan = outputEnd - outputStart;

        // Account for pre-infinity mode
        float outputOffset = 0.0f;

        if ( input < inputStart )
        {
            float inputDifference = inputStart - input;

            switch ( preInfinity )
            {

            case MFnAnimCurve::kConstant:
            {
                evaluatedInput = outputStart;
                evaluated = true;
                break;
            }

            case MFnAnimCurve::kLinear:
            {
                evaluatedInput = outputStart + inputDifference * ( keys[1]->output - outputStart ) / ( keys[1]->input - inputStart );
                evaluated = true;
                break;
            }

            case MFnAnimCurve::kCycle:
            {
                float cycleCount = ceilf ( inputDifference / inputSpan );
                input += cycleCount * inputSpan;
                break;
            }

            case MFnAnimCurve::kCycleRelative:
            {
                float cycleCount = ceilf ( inputDifference / inputSpan );
                input += cycleCount * inputSpan;
                outputOffset -= cycleCount * outputSpan;
                break;
            }

            case MFnAnimCurve::kOscillate:
            {
                float cycleCount = ceilf ( inputDifference / ( 2.0f * inputSpan ) );
                input += cycleCount * 2.0f * inputSpan;
                input = inputEnd - fabsf ( input - inputEnd );
                break;
            }

            default:
                evaluatedInput = outputStart;
                evaluated = true;
                break;
            }
        }

        // Account for post-infinity mode

        else if ( input >= inputEnd )
        {
            float inputDifference = input - inputEnd;

            switch ( postInfinity )
            {

            case MFnAnimCurve::kConstant:
            {
                evaluatedInput = outputEnd;
                evaluated = true;
                break;
            }

            case MFnAnimCurve::kLinear:
            {
                evaluatedInput = outputEnd + inputDifference * ( keys[keys.size() - 2]->output - outputEnd ) / ( keys[keys.size() - 2]->input - inputEnd );
                evaluated = true;
                break;
            }

            case MFnAnimCurve::kCycle:
            {
                float cycleCount = ceilf ( inputDifference / inputSpan );
                input -= cycleCount * inputSpan;
                break;
            }

            case MFnAnimCurve::kCycleRelative:
            {
                float cycleCount = ceilf ( inputDifference / inputSpan );
                input -= cycleCount * inputSpan;
                outputOffset += cycleCount * outputSpan;
                break;
            }

            case MFnAnimCurve::kOscillate:
            {
                float cycleCount = ceilf ( inputDifference / ( 2.0f * inputSpan ) );
                input -= cycleCount * 2.0f * inputSpan;
                input = inputStart + fabsf ( input - inputStart );
                break;
            }

            default:
            {
                evaluatedInput = outputEnd;
                evaluated = true;
                break;
            }
            }
        }

        if ( !evaluated )
        {
            // Find the current interval
            AnimationKeyList::const_iterator it, start = keys.begin(), terminate = keys.end();

            // Binary search.

            while ( terminate - start > 3 )
            {
                // Find the median value between the iterators
                it = start + ( distance ( start, terminate ) / 2 );

                if ( ( *it )->input > input ) terminate = it;
                else start = it;
            }

            // Linear search is more efficient on the last interval

            for ( it = start; it != terminate; ++it )
            {
                if ( ( *it )->input >= input ) break;
            }

            if ( it == keys.begin() )
            {
                evaluatedInput = outputOffset + outputStart;
                evaluated = true;
            }

            if ( !evaluated )
            {
                // Get the keys and values for this interval
                const AnimationKey* startKey = * ( it - 1 );
                const AnimationKey* endKey = *it;
                float inputInterval = endKey->input - startKey->input;
                float outputInterval = endKey->output - startKey->output;

                // Interpolate the output.
                // Similar code is found in AnimationMultiCurve.cpp. If you update this, update the other one too.
                float output;

                switch ( startKey->interpolation )
                {

                case COLLADA::LibraryAnimations::LINEAR:
                {
                    output = startKey->output + ( input - startKey->input ) / inputInterval * outputInterval;
                    break;
                }

                case COLLADA::LibraryAnimations::BEZIER:
                {
                    if ( endKey->interpolation == COLLADA::LibraryAnimations::LINEAR )
                    {
                        output = startKey->output + ( input - startKey->input ) / inputInterval * outputInterval;
                        break;
                    }

                    if ( endKey->interpolation == COLLADA::LibraryAnimations::DEFAULT ||
                            endKey->interpolation == COLLADA::LibraryAnimations::STEP )
                    {
                        output = startKey->output;
                        break;
                    }

                    //Code that applies to both whether the endKey is Bezier or TCB.
                    AnimationKeyBezier* bkey1 = ( AnimationKeyBezier* ) startKey;

                    TangentPoint inTangent;

                    if ( endKey->interpolation == COLLADA::LibraryAnimations::BEZIER )
                    {
                        inTangent = ( ( AnimationKeyBezier* ) endKey )->inTangent;
                    }

                    else if ( endKey->interpolation == COLLADA::LibraryAnimations::TCB )
                    {
                        AnimationKeyTCB* tkey2 = ( AnimationKeyTCB* ) endKey;
                        TangentPoint tempTangent;
                        tempTangent.x = tempTangent.y = 0.0f;
                        const AnimationKey* nextKey = ( it + 1 ) < keys.end() ? ( * ( it + 1 ) ) : NULL;
                        computeTCBTangent ( startKey, endKey, nextKey, tkey2->tension, tkey2->continuity, tkey2->bias, inTangent, tempTangent );
                        //Change this when we've figured out the values of the vectors from TCB...
                        inTangent.x = endKey->input + inTangent.x;
                        inTangent.y = endKey->output + inTangent.y;
                    }

                    float t = ( input - startKey->input ) / inputInterval;

                    if ( mIs2DEvaluation ) t = findT ( bkey1->input, bkey1->outTangent.x, inTangent.x, endKey->input, input, t );

                    float b = bkey1->outTangent.y;

                    float c = inTangent.y;

                    float ti = 1.0f - t;

                    float br = 3.0f;

                    float cr = 3.0f;

                    if ( !mIs2DEvaluation )
                    {
                        br = inputInterval / ( bkey1->outTangent.x - startKey->input );
                        cr = inputInterval / ( endKey->input - inTangent.x );
                        br = COLLADA::MathUtils::clamp ( br, 0.01f, 100.0f );
                        cr = COLLADA::MathUtils::clamp ( cr, 0.01f, 100.0f );
                    }

                    output = startKey->output * ti * ti * ti + br * b * ti * ti * t + cr * c * ti * t * t + endKey->output * t * t * t;

                    break;
                }

                case COLLADA::LibraryAnimations::TCB:
                {
                    if ( endKey->interpolation == COLLADA::LibraryAnimations::LINEAR )
                    {
                        output = startKey->output + ( input - startKey->input ) / inputInterval * outputInterval;
                        break;
                    }

                    if ( endKey->interpolation == COLLADA::LibraryAnimations::DEFAULT ||
                            endKey->interpolation == COLLADA::LibraryAnimations::STEP )
                    {
                        output = startKey->output;
                        break;
                    }

                    // Calculate the start key's out-tangent.
                    AnimationKeyTCB* tkey1 = ( AnimationKeyTCB* ) startKey;

                    TangentPoint startTangent, tempTangent, endTangent;

                    startTangent.x = startTangent.y = tempTangent.x = tempTangent.y = endTangent.x = endTangent.y = 0.0f;

                    const AnimationKey* previousKey = ( it - 1 ) > keys.begin() ? ( * ( it - 2 ) ) : NULL;

                    computeTCBTangent ( previousKey, startKey, endKey, tkey1->tension, tkey1->continuity, tkey1->bias, tempTangent, startTangent );

                    // Calculate the end key's in-tangent.
                    float by = 0.0f, cy= 0.0f; //will be used in the Bezier equation.

                    float bx = 0.0f, cx = 0.0f; //will be used in FindT.. x equivalent of the point at b and c

                    if ( endKey->interpolation == COLLADA::LibraryAnimations::TCB )
                    {
                        AnimationKeyTCB* tkey2 = ( AnimationKeyTCB* ) endKey;
                        const AnimationKey* nextKey = ( it + 1 ) < keys.end() ? ( * ( it + 1 ) ) : NULL;
                        computeTCBTangent ( startKey, endKey, nextKey, tkey2->tension, tkey2->continuity, tkey2->bias, endTangent, tempTangent );
                        cy = endKey->output + endTangent.y; //Assuming the tangent is GOING from the point.
                        cx = endKey->output + endTangent.x;
                    }

                    else if ( endKey->interpolation == COLLADA::LibraryAnimations::BEZIER )
                    {
                        AnimationKeyBezier* tkey2 = ( AnimationKeyBezier* ) endKey;
                        endTangent = tkey2->inTangent;
                        cy = endTangent.y;
                        cx = endTangent.x;
                    }

                    float t = ( input - inputStart ) / inputInterval;

                    by = startKey->output - startTangent.y; //Assuming the tangent is GOING from the point.
                    bx = startKey->input - startTangent.x;

                    if ( mIs2DEvaluation ) t = findT ( tkey1->input, bx, cx, endKey->input, input, t );

                    //  else { //Need to figure out algorithm for easing in and out.
                    //   t = Ease(t, tkey1->easeIn, tkey1->easeOut);
                    //  }

                    float ti = 1.0f - t;

                    output = startKey->output*ti*ti*ti +
                             3*by*t*ti*ti +
                             3*cy*t*t*ti +
                             endKey->output*t*t*t;

                    break;
                }

                case COLLADA::LibraryAnimations::STEP:

                default:
                    output = startKey->output;
                    break;
                }

                evaluatedInput = outputOffset + output;

                evaluated = true;
            }
        }

        return evaluatedInput;
    }

    // ----------------------------------------------------
    void AnimationCurve::convertValues ( ConversionFunctor* valueConversion,
                                         ConversionFunctor* tangentConversion )
    {
        if ( valueConversion != NULL )
        {
            for ( AnimationKeyList::iterator it = keys.begin(); it != keys.end(); ++it )
            {
                ( *it )->output = ( *valueConversion ) ( ( *it )->output );
            }
        }

        if ( tangentConversion != NULL )
        {
            for ( AnimationKeyList::iterator it = keys.begin(); it != keys.end(); ++it )
            {
                if ( ( *it )->interpolation == COLLADA::LibraryAnimations::BEZIER )
                {
                    AnimationKeyBezier* bkey = ( AnimationKeyBezier* ) ( *it );
                    bkey->inTangent.v = ( *tangentConversion ) ( bkey->inTangent.v );
                    bkey->outTangent.v = ( *tangentConversion ) ( bkey->outTangent.v );
                }
            }
        }
    }


    // --------------------------------------------------
    AnimationMultiCurve::AnimationMultiCurve ( const AnimationElement* parent,
            const String& baseId, const uint dimension )
            : BaseAnimationCurve ( parent, baseId, dimension )
    {}

    // ----------------------------------------------------
    AnimationMKey* AnimationMultiCurve::addKey ( COLLADA::LibraryAnimations::InterpolationType interpolation )
    {
        AnimationMKey* key;

        switch ( interpolation )
        {

        case COLLADA::LibraryAnimations::STEP:
            key = new AnimationMKey ( mDimension );
            break;

        case COLLADA::LibraryAnimations::LINEAR:
            key = new AnimationMKey ( mDimension );
            break;

        case COLLADA::LibraryAnimations::BEZIER:
            this->setHasTangents ( true );
            key = new AnimationMKeyBezier ( mDimension );
            break;

        case COLLADA::LibraryAnimations::TCB:
            this->setHasTCB ( true );
            key = new AnimationMKeyTCB ( mDimension );
            break;

        default:
            key = new AnimationMKey ( mDimension );
            break;
        }

        key->interpolation = interpolation;

        keys.push_back ( key );

        return key;
    }

    // ----------------------------------------------------
    void AnimationMultiCurve::evaluate ( float input, float* output ) const
    {
        // Check for empty curves and poses (curves with 1 key).
        if ( keys.size() == 0 )
        {
            for ( uint i=0; i<mDimension; ++i ) output[i] = 0.0f;
        }

        else if ( keys.size() == 1 )
        {
            for ( uint i=0; i<mDimension; ++i ) output[i] = keys.front()->output[i];
        }

        else
        {
            // Find the current interval
            AnimationMKeyList::const_iterator it, start=keys.begin(), terminate=keys.end();
            // Binary search.

            while ( terminate - start > 3 )
            {
                // Find the median value between the iterators
                it = start + ( distance ( start, terminate ) / 2 );

                if ( ( *it )->input > input ) terminate = it;
                else start = it;
            }

            // Linear search is more efficient on the last interval

            for ( it = start; it != terminate; ++it )
            {
                if ( ( *it )->input > input ) break;
            }

            if ( it == keys.end() )
            {
                // We're sampling after the curve, return the last values
                const AnimationMKey* lastKey = keys.back();

                for ( uint i=0; i<mDimension; ++i ) output[i] = lastKey->output[i];
            }

            else if ( it == keys.begin() )
            {
                // We're sampling before the curve, return the first values
                const AnimationMKey* firstKey = keys.front();

                for ( uint i=0; i<mDimension; ++i ) output[i] = firstKey->output[i];
            }

            else
            {
                // Get the keys and values for this interval
                const AnimationMKey* startKey = * ( it - 1 );
                const AnimationMKey* endKey = *it;
                float inputInterval = endKey->input - startKey->input;

                // Interpolate the outputs.
                // Similar code is found in AnimationCurve.cpp. If you update this, update the other one too.

                switch ( startKey->interpolation )
                {

                case COLLADA::LibraryAnimations::LINEAR:

                    for ( uint i=0; i<mDimension; ++i )
                    {
                        output[i] = startKey->output[i] + ( input - startKey->input ) / inputInterval * ( endKey->output[i] - startKey->output[i] );
                    }

                    break;

                case COLLADA::LibraryAnimations::BEZIER:
                {
                    AnimationMKeyBezier* bkey1 = ( AnimationMKeyBezier* ) startKey;

                    for ( uint i=0; i<mDimension; ++i )
                    {
                        TangentPoint inTangent;

                        if ( endKey->interpolation == COLLADA::LibraryAnimations::BEZIER )
                            inTangent = ( ( AnimationMKeyBezier* ) endKey )->inTangent[i];
                        else inTangent = TangentPoint ( endKey->input, 0.0f );

                        float t = ( input - startKey->input ) / inputInterval;

                        if ( mIs2DEvaluation )
                            t = findT ( startKey->input, bkey1->outTangent[i].x, inTangent.x, endKey->input, input, t );

                        float b = bkey1->outTangent[i].v;

                        float c = inTangent.v;

                        float ti = 1.0f - t;

                        float br = inputInterval / ( bkey1->outTangent[i].u - startKey->input );

                        float cr = inputInterval / ( endKey->input - inTangent.u );

                        br = COLLADA::MathUtils::clamp ( br, 0.01f, 100.0f );

                        cr = COLLADA::MathUtils::clamp ( cr, 0.01f, 100.0f );

                        output[i] = startKey->output[i] * ti * ti * ti + br* b * ti * ti * t + cr * c * ti * t * t + endKey->output[i] * t * t * t;
                    }

                    break;
                }

                case COLLADA::LibraryAnimations::TCB: // Not implemented..

                case COLLADA::LibraryAnimations::STEP:

                default:

                    for ( uint i=0; i<mDimension; ++i ) output[i] = startKey->output[i];

                    break;
                }
            }
        }
    }

}