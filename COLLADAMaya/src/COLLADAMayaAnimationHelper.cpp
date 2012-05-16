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

#include <maya/MAnimUtil.h>
#include <maya/MAnimControl.h>
#include <maya/MFnMatrixData.h>

#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaAnimationSampleCache.h"
#include "COLLADAMayaAnimationTools.h"
#include "COLLADAMayaAnimationHelper.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaSyntax.h"

namespace COLLADAMaya
{

    std::vector<float> AnimationHelper::mSamplingTimes;

    // -------------------------------------------
    MObject AnimationHelper::getAnimatingNode ( const MPlug& plug )
    {
        // Early withdrawal: check for no direct connections on plug
        MObject animating = DagHelper::getSourceNodeConnectedTo ( plug );
        if ( animating.isNull() ) return animating;

        // By-pass any unit conversion nodes
        while ( animating.hasFn ( MFn::kUnitConversion ) )
        {
            animating = DagHelper::getSourceNodeConnectedTo ( animating, ATTR_INPUt );
        }

        return animating;
    }

    // -------------------------------------------
    // Figure out whether a given plug is animated
    AnimationResult AnimationHelper::isAnimated ( 
        AnimationSampleCache *acache,
        const MObject& node,
        const String& attribute )
    {
        MStatus status;
        MPlug p = MFnDependencyNode ( node ).findPlug ( attribute.c_str(), &status );
        return ( status != MStatus::kSuccess ) ? kISANIM_None : isAnimated ( acache, p );
    }

    // -------------------------------------------
    AnimationResult AnimationHelper::isAnimated ( 
        AnimationSampleCache* cache,
        const MPlug& plug )
    {
        // First check for sampling in our cache -- if this exists, it overrides
        // all other considerations.  We could have sampling on a node without any
        // connections (for example, IK driven nodes).
        bool animated;
        if ( cache->findCachePlug ( plug, animated ) )
        {
            return ( !animated ) ? kISANIM_None : kISANIM_Sample;
        }
        else
        {
            // Get the connected animating object
            MObject connectedNode = getAnimatingNode ( plug );
            if ( connectedNode == MObject::kNullObj ) return kISANIM_None;
            else if ( connectedNode.hasFn ( MFn::kAnimCurve ) )
            {
                MFnAnimCurve curveFn ( connectedNode );
                AnimationResult result = curveFn.numKeys() >= 1 ? kISANIM_Curve : kISANIM_None;

                // The animCurve is considered to be static if it would return 
                // the same value regardless of the evaluation time. 
                // This basically means that the values of all the keys are 
                // the same and the y component of all the tangents is 0. 
                if ( ExportOptions::removeStaticCurves() )
                {
                    if ( result == kISANIM_Curve && curveFn.isStatic() ) 
                        result = kISANIM_None;
                }

                return result;
            }
            else if ( connectedNode.hasFn ( MFn::kCharacter ) )
            {
                return kISANIM_Character;
            }
        }
        return kISANIM_None;
    }

    class SamplingInterval
    {

    public:
        float start;
        float end;
        float period;
    };

    // -------------------------------------------
    // set the sampling function from the UI/command line.
    // Returns validity of the function
    bool AnimationHelper::setSamplingFunction ( const MFloatArray& function )
    {
        std::vector<SamplingInterval> parsedFunction;

        // Order and parse the given floats as a function
        uint elementCount = function.length();
        if ( elementCount > 1 && elementCount % 3 != 0 ) return false;

        if ( elementCount == 0 )
        {
            generateSamplingFunction();
            return true;
        }
        else if ( elementCount == 1 )
        {
            SamplingInterval interval;
            interval.start = ( float ) animationStartTime().as ( MTime::kSeconds );
            interval.end = ( float ) animationEndTime().as ( MTime::kSeconds );
            interval.period = function[0];
            parsedFunction.push_back ( interval );
        }
        else
        {
            uint intervalCount = elementCount / 3;
            parsedFunction.resize ( intervalCount );
            for ( uint i = 0; i < intervalCount; ++i )
            {
                SamplingInterval& interval = parsedFunction[i];
                interval.start = function[i * 3];
                interval.end = function[i * 3 + 1];
                interval.period = function[i * 3 + 2];
            }
        }

        // Check for a valid sampling function
        uint parsedFunctionSize = ( uint ) parsedFunction.size();
        for ( uint i = 0; i < parsedFunctionSize; ++i )
        {
            SamplingInterval& interval = parsedFunction[i];
            if ( interval.end <= interval.start ) return false;
            if ( interval.period > interval.end - interval.start ) return false;
            if ( i > 0 && parsedFunction[i - 1].end > interval.start ) return false;
            if ( interval.period <= 0.0f ) return false;
        }

        // Gather the sampling times
        mSamplingTimes.clear();

        float previousTime = ( float ) animationStartTime().as ( MTime::kSeconds );
        float previousPeriodTakenRatio = 1.0f;

        for ( std::vector<SamplingInterval>::iterator it = parsedFunction.begin(); it != parsedFunction.end(); ++it )
        {
            SamplingInterval& interval = ( *it );
            float time = interval.start;
            if ( time == previousTime )
            {
                // Continuity in the sampling, calculate overlap start time
                time = time + ( 1.0f - previousPeriodTakenRatio ) * interval.period;
            }

            for ( ; time <= interval.end - interval.period + FLT_TOLERANCE; time += interval.period )
            {
                mSamplingTimes.push_back ( time );
            }

            mSamplingTimes.push_back ( time );

            previousTime = interval.end;
            previousPeriodTakenRatio = ( interval.end - time ) / interval.period;
        }

        return true;
    }

    // -------------------------------------------
    void AnimationHelper::generateSamplingFunction()
    {
        mSamplingTimes.clear();

        // Avoid any potential precision accumulation problems by using the MTime class as an iterator
        MTime startT = animationStartTime();
        MTime endT = animationEndTime();
        for ( MTime currentT = startT; currentT <= endT; ++currentT )
        {
            mSamplingTimes.push_back ( ( float ) currentT.as ( MTime::kSeconds ) );
        }
    }

    // -------------------------------------------
    // Sample animated values for a given plug
    bool AnimationHelper::sampleAnimatedPlug ( 
        AnimationSampleCache* cache,
        const MPlug& plug,
        AnimationCurve* curve,
        ConversionFunctor* converter )
    {
        MStatus status;
        if ( cache == NULL ) return false;

        std::vector<float>* inputs = NULL;
        std::vector<float>* outputs = NULL;

        // Buffer temporarly the inputs and outputs, so they can be sorted
        if ( !cache->findCachePlug ( plug, inputs, outputs ) || inputs == NULL || outputs == NULL ) return false;

        uint inputCount = ( uint ) inputs->size();

        // Look for a matching plug in the animation cache...
        if ( ExportOptions::curveConstrainSampling() )
        {
            // Drop the keys and their outputs that don't belong to the attached animation curve
            MFnAnimCurve curveFn ( plug, &status );
            if ( status == MStatus::kSuccess && curveFn.numKeys() > 0 )
            {
                float startTime = ( float ) curveFn.time ( 0 ).as ( MTime::kSeconds );
                float endTime = ( float ) curveFn.time ( curveFn.numKeys() - 1 ).as ( MTime::kSeconds );
                uint count = 0;

                // To avoid memory re-allocations, start by counting the number of keys that are within the curve
                for ( uint i = 0; i < inputCount; ++i )
                {
                    if ( inputs->at ( i ) + FLT_TOLERANCE >= startTime && inputs->at ( i ) - FLT_TOLERANCE <= endTime ) ++count;
                }
                curve->setKeyCount ( count, COLLADASW::LibraryAnimations::LINEAR );

                // Copy over the keys belonging to the curve's timeframe
                for ( uint i = 0; i < inputCount; ++i )
                {
                    if ( inputs->at ( i ) + FLT_TOLERANCE >= startTime && inputs->at ( i ) - FLT_TOLERANCE <= endTime )
                    {
                        curve->getKey ( i )->input = inputs->at ( i );
                        curve->getKey ( i )->output = outputs->at ( i );
                    }
                }
            }
            else if ( status != MStatus::kSuccess )
            {
                // No curve found, so use the sampled inputs/outputs directly
                curve->setKeyCount ( inputs->size(), COLLADASW::LibraryAnimations::LINEAR );
                for ( uint i = 0; i < inputCount; ++i )
                {
                    curve->getKey ( i )->input = inputs->at ( i );
                    curve->getKey ( i )->output = outputs->at ( i );
                }
            }
        }
        else
        {
            curve->setKeyCount ( inputs->size(), COLLADASW::LibraryAnimations::LINEAR );
            for ( uint i = 0; i < inputCount; ++i )
            {
                curve->getKey ( i )->input = inputs->at ( i );
                curve->getKey ( i )->output = outputs->at ( i );
            }
        }

        // Convert the samples
        if ( converter != NULL )
        {
            curve->convertValues ( converter, converter );
        }

        return true;
    }

    // -------------------------------------------
    bool AnimationHelper::sampleAnimatedTransform ( 
        AnimationSampleCache* cache,
        const MPlug& plug,
        AnimationCurveList& curves )
    {
        if ( curves.size() != 16 ) return false;

        std::vector<float>* inputs = NULL,* outputs = NULL;
        if ( !cache->findCachePlug ( plug, inputs, outputs ) || inputs == NULL || outputs == NULL ) 
            return false;

        size_t keyCount = inputs->size();
        for ( size_t i = 0; i < 16; ++i )
        {
            curves[i]->setKeyCount ( keyCount, COLLADASW::LibraryAnimations::LINEAR );
            for ( size_t j = 0; j < keyCount; ++j )
            {
                AnimationKey* key = ( AnimationKey* ) curves[i]->getKey ( j );
                key->input = inputs->at ( j );
                key->output = outputs->at ( j*16 + i );

                // Either here with flag "convertUnits" or in method 
                // AnimationExporter::exportAnimationSource ( AnimationMultiCurve &animationCurve )
//                 if ( (i+1)%4 == 0 && (i+1) < 16 )
//                     key->output = MDistance::internalToUI ( outputs->at ( j*16 + i ) );
//                 else
//                     key->output = outputs->at ( j*16 + i );
            }
        }

        return true;
    }

    // Since Maya 5.0 doesn't support MAnimControl::animation[Start/End]Time(), wrap it with the MEL command
    //
    // [JHoerner]: use minTime/maxTime rather than animationStartTime/animationEndTime.  Usually our artists
    // use the former (narrower) range of the time slider and put "junk" beyond the edges.
#define TSTART "animationStartTime"
#define TEND   "animationEndTime"
    //#define TSTART "minTime"
    //#define TEND   "maxTime"

    // -------------------------------------------
    MTime AnimationHelper::animationStartTime()
    {
        MTime time ( MAnimControl::currentTime() );
        double result;
        MGlobal::executeCommand ( "playbackOptions -q -" TSTART, result );
        time.setValue ( result );
        return time;
    }

    // -------------------------------------------
    MTime AnimationHelper::animationEndTime()
    {
        MTime time ( MAnimControl::currentTime() );
        double result;
        MGlobal::executeCommand ( "playbackOptions -q -" TEND, result );
        time.setValue ( result );
        return time;
    }

    // -------------------------------------------
    void AnimationHelper::setAnimationStartTime ( float _time )
    {
        MTime time ( _time, MTime::kSeconds );
        double t = time.as ( MTime::uiUnit() );
        MGlobal::executeCommand ( MString ( "playbackOptions -" TSTART " " ) + t );
    }

    // -------------------------------------------
    void AnimationHelper::setAnimationEndTime ( float _time )
    {
        MTime time ( _time, MTime::kSeconds );
        double t = time.as ( MTime::uiUnit() );
        MGlobal::executeCommand ( MString ( "playbackOptions -" TEND " " ) + t );
    }

    // -------------------------------------------
    void AnimationHelper::getCurrentTime ( MTime& time )
    {
        time = MAnimControl::currentTime();
    }

    // -------------------------------------------
    void AnimationHelper::setCurrentTime ( const MTime& time )
    {
        MAnimControl::setCurrentTime ( time );
    }

    // -------------------------------------------
    MPlug AnimationHelper::getTargetedPlug ( MPlug parentPlug, int index )
    {
        if ( index >= 0 && parentPlug.isCompound() )
        {
            return parentPlug.child ( index );
        }
        else if ( index >= 0 && parentPlug.isArray() )
        {
            return parentPlug.elementByLogicalIndex ( index );
        }
        else return parentPlug;
    }

    // -------------------------------------------
    // Interpolation Type Handling
    //
    COLLADASW::LibraryAnimations::InterpolationType AnimationHelper::toInterpolation ( MFnAnimCurve::TangentType outType )
    {
        switch ( outType )
        {
        case MFnAnimCurve::kTangentGlobal:
            return COLLADASW::LibraryAnimations::BEZIER;

        case MFnAnimCurve::kTangentFixed:
            return COLLADASW::LibraryAnimations::BEZIER;

        case MFnAnimCurve::kTangentLinear:
            return COLLADASW::LibraryAnimations::LINEAR;

        case MFnAnimCurve::kTangentFlat:
            return COLLADASW::LibraryAnimations::BEZIER;

        case MFnAnimCurve::kTangentSmooth:
            return COLLADASW::LibraryAnimations::BEZIER;

        case MFnAnimCurve::kTangentStep:
            return COLLADASW::LibraryAnimations::STEP;

        case MFnAnimCurve::kTangentClamped:
            return COLLADASW::LibraryAnimations::BEZIER;

        default:
            return COLLADASW::LibraryAnimations::BEZIER;
        }
    }

    // -------------------------------------------
    MFnAnimCurve::TangentType AnimationHelper::toTangentType ( COLLADASW::LibraryAnimations::InterpolationType type )
    {
        switch ( type )
        {

        case COLLADASW::LibraryAnimations::STEP:
            return MFnAnimCurve::kTangentStep;

        case COLLADASW::LibraryAnimations::LINEAR:
            return MFnAnimCurve::kTangentLinear;

        case COLLADASW::LibraryAnimations::BEZIER:
            return MFnAnimCurve::kTangentFixed;

        default:
            return MFnAnimCurve::kTangentClamped;
        }
    }

    // -------------------------------------------
    const String AnimationHelper::mayaInfinityTypeToString ( MFnAnimCurve::InfinityType type )
    {
        switch ( type )
        {

        case MFnAnimCurve::kConstant:
            return MAYA_CONSTANT_INFINITY;

        case MFnAnimCurve::kLinear:
            return MAYA_LINEAR_INFINITY;

        case MFnAnimCurve::kCycle:
            return MAYA_CYCLE_INFINITY;

        case MFnAnimCurve::kCycleRelative:
            return MAYA_CYCLE_RELATIVE_INFINITY;

        case MFnAnimCurve::kOscillate:
            return MAYA_OSCILLATE_INFINITY;

        default:
            return MAYA_CONSTANT_INFINITY;
        }
    }

    /*
    // Pre/Post-Infinity Type Handling
    InfinityType::Infinity AnimationHelper::ConvertInfinity(MFnAnimCurve::InfinityType type)
    {
     switch (type)
     {
     case MFnAnimCurve::kConstant: return InfinityType::CONSTANT;
     case MFnAnimCurve::kLinear: return InfinityType::LINEAR;
     case MFnAnimCurve::kCycle: return InfinityType::CYCLE;
     case MFnAnimCurve::kCycleRelative: return InfinityType::CYCLE_RELATIVE;
     case MFnAnimCurve::kOscillate: return InfinityType::OSCILLATE;
     default: return Infinity::UNKNOWN;
     }
    }

    MFnAnimCurve::InfinityType AnimationHelper::ConvertInfinity(InfinityType::Infinity type)
    {
     switch (type)
     {
     case InfinityType::CONSTANT: return MFnAnimCurve::kConstant;
     case InfinityType::LINEAR: return MFnAnimCurve::kLinear;
     case InfinityType::CYCLE: return MFnAnimCurve::kCycle;
     case InfinityType::CYCLE_RELATIVE: return MFnAnimCurve::kCycleRelative;
     case InfinityType::OSCILLATE: return MFnAnimCurve::kOscillate;
     default: return MFnAnimCurve::kConstant;
     }
    }
    */

    // -------------------------------------------
    bool AnimationHelper::isPhysicsAnimation ( const MObject& o )
    {
        if ( o.hasFn ( MFn::kChoice ) )
        {
            MFnDependencyNode n ( o );
            MPlug p = n.findPlug ( "input" );
            uint choiceCount = p.numElements();

            for ( uint i = 0; i < choiceCount; ++i )
            {
                MPlug child = p.elementByPhysicalIndex ( i );
                MObject connection = DagHelper::getSourceNodeConnectedTo ( child );

                if ( !connection.isNull() && connection != o )
                    if ( isPhysicsAnimation ( connection ) ) return true;
            }
        }

        else if ( o.hasFn ( MFn::kRigidSolver ) || o.hasFn ( MFn::kRigid ) ) return true;

        return false;
    }

    // -------------------------------------------
    void AnimationHelper::checkForSampling ( 
        AnimationSampleCache* cache, 
        SampleType sampleType, 
        const MPlug& plug )
    {
        switch ( sampleType & kValueMask )
        {

        case kBoolean:
        case kSingle:
        {
            bool forceSampling = ExportOptions::isSampling();

            if ( !forceSampling )
            {
                MObject connection = AnimationHelper::getAnimatingNode ( plug );
                forceSampling |= !connection.isNull() && !connection.hasFn ( MFn::kCharacter ) && !connection.hasFn ( MFn::kAnimCurve );
                forceSampling &= !isPhysicsAnimation ( connection );
            }
            if ( forceSampling ) cache->cachePlug ( plug, false );

            break;
        }

        case kMatrix:
        {
            bool forceSampling = cache->findCacheNode ( plug.node() );
            if ( forceSampling ) cache->cachePlug ( plug, false );
            break;
        }

        case kVector:
        case kColour:
        {
            // Check for one node affecting the whole value.
            bool forceSampling = ExportOptions::isSampling();
            if ( !forceSampling )
            {
                MObject connection = AnimationHelper::getAnimatingNode ( plug );
                forceSampling |= !connection.isNull() && !connection.hasFn ( MFn::kCharacter ) && !connection.hasFn ( MFn::kAnimCurve );
                forceSampling &= !isPhysicsAnimation ( connection );
            }

            if ( forceSampling ) cache->cachePlug ( plug, false );
            else
            {
                // Check for nodes affecting the children.
                uint childCount = plug.numChildren();
                for ( uint i = 0; i < childCount; ++i )
                {
                    MObject connection = AnimationHelper::getAnimatingNode ( plug.child ( i ) );
                    bool sampleChild = !connection.isNull() && !connection.hasFn ( MFn::kCharacter ) && !connection.hasFn ( MFn::kAnimCurve );
                    sampleChild &= !isPhysicsAnimation ( connection );

                    if ( sampleChild ) cache->cachePlug ( plug.child ( i ), false );
                }
            }

            break;
        }
        }
    }
}