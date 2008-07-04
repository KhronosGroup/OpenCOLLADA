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

#ifndef __COLLADA_MAYA_ANIMATION_HELPER_H__
#define __COLLADA_MAYA_ANIMATION_HELPER_H__

#include "COLLADAMayaAnimationCurves.h"
#include "COLLADAMayaAnimationSampleCache.h"

#include "COLLADALibraryAnimations.h"

#include <maya/MFnAnimCurve.h>
#include <maya/MTime.h>
#include <maya/MDGContext.h>

namespace COLLADAMaya
{

#undef GetCurrentTime

    class AnimationSampleCache;


    /** The default tolerance for double-sized floating-point comparison functions. */
#define DBL_TOLERANCE 0.0001
    /** The default tolerance for single-sized floating-point comparison functions. */
#define FLT_TOLERANCE 0.0001f


    /** Contains the infinity types and their conversion functions. */

    namespace InfinityType
    {
        /** An infinity type.
        They determine what happens when evaluating an animation curve outside of its bounds. */
        enum Infinity
        {
            CONSTANT = 0,  /**< Uses the output value of the closest animation key. This is the default infinity type. */
            LINEAR,    /**< Takes the distance between the closest animation key input value and the evaluation time.
          Multiplies this distance against the instant slope at the closest animation key and offsets the
          result with the closest animation key output value. */
            CYCLE,    /**< Iteratively removes or adds the animation curve time length to the evaluation time until it is
          within the animation curve time interval and evaluates it. */
            CYCLE_RELATIVE,  /**< Iteratively removes or adds the animation curve time length to the evaluation time until it is
          within the animation curve time interval and evaluates it. Adds to the evaluation output the
          number of iteration done multiplied by the difference between the animation curve
          start and end key outputs. */
            OSCILLATE,   /**< Iteratively removes or adds the animation curve time length to the evaluation time until it is
          within the animation curve time interval. If the number of iterations done is even, evaluate the
          new evaluation time, otherwise evaluate (animation curve time length - evaluation time). */

            UNKNOWN,   /**< An unknown infinity type. */
            DEFAULT = CONSTANT
        };
    };


    // -------------------------------------------------------
    /**
    * todo Doku
    */

    class AnimationHelper
    {

    public:
        static std::vector<float> samplingTimes;

    public:
        // Returns whether the plug has any sort of animation, keyed or expression-wise.
        static AnimationResult isAnimated ( AnimationSampleCache* cache, const MObject& node, const String& attribute );
        static AnimationResult isAnimated ( AnimationSampleCache* cache, const MPlug& plug );
        static MObject getAnimatingNode ( const MPlug& plug );

        // Sample animated data
        static bool isPhysicsAnimation ( const MObject& o );
        static void checkForSampling ( AnimationSampleCache* cache, SampleType sampleType, const MPlug& plug );
        static bool setSamplingFunction ( const MFloatArray& function );
        static void generateSamplingFunction();

        static bool sampleAnimatedPlug ( AnimationSampleCache* cache, const MPlug& plug, AnimationCurve* curve, ConversionFunctor* converter );
        static void sampleAnimatedTransform ( AnimationSampleCache* cache, const MPlug& plug, AnimationCurveList& curves );

        // Since Maya 5.0 doesn't support MAnimControl::animation[Start/End]Time(), wrap it with the MEL command
        static MTime animationStartTime();
        static MTime animationEndTime();
        static void setAnimationStartTime ( float time );
        static void setAnimationEndTime ( float time );
        static void getCurrentTime ( MTime& time );
        static void setCurrentTime ( const MTime& time );

        // Handle animation targetting
        static MPlug getTargetedPlug ( MPlug parentPlug, int index );

        // Interpolation Type Handling
        static COLLADA::LibraryAnimations::InterpolationType toInterpolation ( MFnAnimCurve::TangentType outType );
        static MFnAnimCurve::TangentType toTangentType ( COLLADA::LibraryAnimations::InterpolationType type );

        static const String mayaInfinityTypeToString ( MFnAnimCurve::InfinityType type );

    private:

        /** Don't create an object of this class. */
        AnimationHelper() {};

    };
}

#endif // __COLLADA_MAYA_ANIMATION_HELPER_H__
