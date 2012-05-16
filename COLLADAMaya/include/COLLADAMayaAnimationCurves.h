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

#ifndef __COLLADA_MAYA_ANIMATION_CURVES_H__
#define __COLLADA_MAYA_ANIMATION_CURVES_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaAnimationElement.h"
#include "COLLADAMayaAnimationKeys.h"
#include "COLLADAMayaTangentPoint.h"
#include "COLLADAMayaConversion.h"

#include "COLLADASWLibraryAnimationClips.h"
#include "COLLADASWLibraryAnimations.h"

#include <maya/MFnAnimCurve.h>

namespace COLLADAMaya
{

    class AnimationElement;

    // ----------------------------------------------------------
    /**
    * Represents the base of an animation curve.
    */
    template <class T>
    class BaseAnimationCurve
    {

    protected:

        /** List of keys. */
        typedef typename std::vector<T*> KeyList;

        // Curve information
        KeyList mKeys;
        MFnAnimCurve::InfinityType mPreInfinity, mPostInfinity;

        // The animation element owning this curve.
        const AnimationElement* mParent;

        // What sort of evaluation we do, 1D or 2D
        static bool mIs2DEvaluation;

        // The number of compound or merged curves of an element
        uint mDimension;

    private:

        // The ids of the current curve
        String mBaseId;

        /** true, if there exist some steps with tangents in the curve. */
        bool mHasTangents;
        bool mHasTCB;

        /** The parameters of the current curve. */
        String* mParameters;

        /**
          * The index of the current curve in the list of curve elements.
          * Needed to detect the correct parameter.
          */
        uint mCurveIndex;

        /**
          * The animCurve is considered to be static if it would return
          * the same value regardless of the evaluation time.
          * This basically means that the values of all the keys are
          * the same and the y component of all the tangents is 0.
          */
        bool mIsStatic;

    public:

        /** Returns the owning element of the current curve */
        const AnimationElement* getParent() const
        {
            return mParent;
        }

        /** The id of the parent's node. */
        const String& getNodeId() const
        {
            return mParent->getNodeId();
        }

        /** Adds a key in depend of the interpolation type to the curve. */
        virtual T* addKey ( COLLADASW::LibraryAnimations::InterpolationType interpolation ) = 0;

        /** Resizes the current key std::vector. */
        void setKeyCount ( size_t count, COLLADASW::LibraryAnimations::InterpolationType interpolation );

        /** Retrieves the list of keys for the animation curve.
        @return The list of keys. */
        inline KeyList getKeys()
        {
            return mKeys;
        }

        /** Retrieves the list of keys for the animation curve.
        @return The list of keys. */
        inline const KeyList getKeys() const
        {
            return mKeys;    /**< See above. */
        }

        /** Get the key at the current index */
        T* getKey ( size_t index ) const;

        /** Returns the number of keys in the curve. */
        size_t getKeyCount() const
        {
            return mKeys.size();
        };

        /** Retrieves the number of dimensions for the curve.
        @return The number of dimensions for the curve. */
        const uint getDimension() const
        {
            return mDimension;
        }

        /** The number of dimensions for the curve. */
        void setDimension ( uint dimension )
        {
            mDimension = dimension;
        }

        /** Retrieves the type of behavior for the curve if the input value is
        outside the input interval defined by the curve keys and less than any key input value.*/
        void setPreInfinity ( MFnAnimCurve::InfinityType _preInfinity )
        {
            mPreInfinity = _preInfinity;
        }

        /** The pre-infinity behavior of the curve. */
        MFnAnimCurve::InfinityType getPreInfinity() const
        {
            return mPreInfinity;
        }

        /** Retrieves the type of behavior for the curve if the input value is
        outside the input interval defined by the curve keys and greater than any key input value. */
        void setPostInfinity ( MFnAnimCurve::InfinityType _postInfinity )
        {
            mPostInfinity = _postInfinity;
        }

        /** The post-infinity behavior of the curve. */
        MFnAnimCurve::InfinityType getPostInfinity() const
        {
            return mPostInfinity;
        }

        /** Returns the parameters of the current curve. */
        const String* getParameters() const
        {
            return mParent->getParameters();
        }

        // void setParameters(String* parameters) { mParameters = parameters; }

        /** Flag to sign, if the curve has tangents and we have to create the tangents for every key. */
        bool hasTangents() const
        {
            return mHasTangents;
        }

        /** Flag to sign, if the curve has tangents and we have to create the tangents for every key. */
        void setHasTangents ( bool _hasTangents )
        {
            mHasTangents = _hasTangents;
        }

        /** Flag to sign, if the curve has tcbs and we have to create the values for every key. */
        bool hasTCB () const
        {
            return mHasTCB;
        }

        /** Flag to sign, if the curve has tcbs and we have to create the values for every key. */
        void setHasTCB ( bool _hasTCB )
        {
            mHasTCB = _hasTCB;
        }

        /** Turns on or off the 2D Curve Evaluation.
        @param flag An on or off boolean flag.*/
        inline void set2DCurveEvaluation ( bool flag )
        {
            mIs2DEvaluation = flag;
        }

        /** Returns whether 2D Curve Evaluation is on or off.
        @return A boolean that indicates if the 2D Curve Evaluation is on or off. */
        inline bool is2DCurveEvaluation()
        {
            return mIs2DEvaluation;
        }

        /** The base id of the current curve. */
        const String& getBaseId() const
        {
            return mBaseId;
        }

        /** The base id of the current curve. */
        void setBaseId ( const String& baseId )
        {
            mBaseId = baseId;
        };

        /** Get the sub id of the animated element. */
        const String& getTargetSid() const
        {
            return mParent->getTargetSid();
        }

        /** Get the source id of the animated element. */
        const String getSourceId() const
        {
            return mParent->getBaseId() + "_" + this->getBaseId();
        }

        /** The index of the current curve in the list of curve elements.
        Needed to detect the correct parameter. */
        uint getCurveIndex() const
        {
            return mCurveIndex;
        }

        /** The index of the current curve in the list of curve elements.
        Needed to detect the correct parameter. */
        void setCurveIndex ( uint curveIndex )
        {
            mCurveIndex = curveIndex;
        }

        /**
        * The animCurve is considered to be static if it would return
        * the same value regardless of the evaluation time.
        * This basically means that the values of all the keys are
        * the same and the y component of all the tangents is 0.
        */
        const bool getIsStatic() const { return mIsStatic; }

        /**
        * The animCurve is considered to be static if it would return
        * the same value regardless of the evaluation time.
        * This basically means that the values of all the keys are
        * the same and the y component of all the tangents is 0.
        */
        void setIsStatic( bool val ) { mIsStatic = val; }

        /** The array element of the animated value. */
        const int getArrayElement() const
        {
            return mParent->getArrayElement();
        }

    protected:

        BaseAnimationCurve ( const AnimationElement* parent,
                             const String& baseId,
                             const uint dimension = 0 )
                : mParent ( parent )
                , mDimension ( dimension )
                , mBaseId ( baseId )
                , mHasTangents ( false )
                , mHasTCB ( false )
                , mParameters ( NULL )
                , mCurveIndex ( 0 )
                , mIsStatic ( false )
                , mPreInfinity ( MFnAnimCurve::kConstant )
                , mPostInfinity ( MFnAnimCurve::kConstant )
        {
            // Set the parenting dimension as default
            if ( dimension==0 ) mDimension = parent->getDimension();
        }

        /** Destructor */
        virtual ~BaseAnimationCurve();

        /**
        * Computes the tcb tangent.
        * @todo documentation
        * @param previousKey
        * @param currentKey
        * @param nextKey
        * @param tens
        * @param cont
        * @param bias
        * @param leftTangent
        * @param rightTangent
        * @return void
        */
        void computeTCBTangent ( const AnimationKey* previousKey,
                                 const AnimationKey* currentKey,
                                 const AnimationKey* nextKey,
                                 const float tens,
                                 const float cont,
                                 const float bias,
                                 TangentPoint& leftTangent,
                                 TangentPoint& rightTangent ) const;

        /** Uses iterative method to accurately pin-point the 't' of the Bezier
        equation that corresponds to the current time. */
        float findT ( float cp0x,
                      float cp1x,
                      float cp2x,
                      float cp3x,
                      float input,
                      float initialGuess ) const;

    };


    // --------------------------------------------------
    template<class T>
    BaseAnimationCurve<T>::~BaseAnimationCurve()
    {
        mParent = NULL;

        typename KeyList::iterator it = mKeys.begin();

        for ( ; it!=mKeys.end(); ++it )
        {
            T* key = *it;
            delete key;
        }

        mKeys.clear();
    }

    // --------------------------------------------------
    /**
    * BaseAnimationCurve: the member functions are declared in the header file,
    * cause otherwise we will get an unresolved external linkage error.
    */
    template<class T>
    T* BaseAnimationCurve<T>::getKey ( size_t index ) const
    {
        if ( mKeys.size() < index )
            std::cerr << "Key index not valid! "  + index << std::endl;

        return mKeys[index];
    }

    /**
    * @todo documentation
    * @param count
    * @param interpolation
    * @return void
    */
    template<class T>
    void BaseAnimationCurve<T>::setKeyCount (
        size_t count,
        COLLADASW::LibraryAnimations::InterpolationType interpolation )
    {
        size_t oldCount = mKeys.size();
        if ( oldCount < count )
        {
            for ( ; oldCount < count; ++oldCount ) addKey ( interpolation );
        }
        else if ( count < oldCount )
        {
            while ( mKeys.size() > count )
            {
                delete mKeys[mKeys.size()-1];
                mKeys.pop_back();
            }
        }
    }

    // ---------------------------------------------------
    template<class T>
    void BaseAnimationCurve<T>::computeTCBTangent (
        const AnimationKey* previousKey,
        const AnimationKey* currentKey,
        const AnimationKey* nextKey,
        const float tens,
        const float cont,
        const float bias,
        TangentPoint& leftTangent,
        TangentPoint& rightTangent ) const
    {
        if ( currentKey == NULL )
        {
            std::cerr << "Current key is null!" << std::endl;
            return;
        }

        // Calculate the intervals and allow for time differences of both sides.
        TangentPoint pCurrentMinusPrevious;
        TangentPoint pNextMinusCurrent;

        //If the previous key or the last key is NULL, do make one up...
        if ( !previousKey )
        {
            if ( nextKey ) pCurrentMinusPrevious.x = nextKey->input - currentKey->input;
            else pCurrentMinusPrevious.x = 0.5f; //Case where there is only one TCB key.. should not happen.

            pCurrentMinusPrevious.y = 0.0f;
        }
        else
        {
            pCurrentMinusPrevious.x = previousKey->input - currentKey->input;
            pCurrentMinusPrevious.y = previousKey->output - currentKey->output;
        }

        if ( !nextKey )
        {
            if ( previousKey ) pNextMinusCurrent.x = currentKey->input - previousKey->input;
            else pNextMinusCurrent.x = 0.5f; //Case where there is only one TCB key.. ?

            pNextMinusCurrent.y = 0.0f;
        }
        else
        {
            pNextMinusCurrent.x = nextKey->input - currentKey->input;
            pNextMinusCurrent.y = nextKey->output - currentKey->output;
        }

        //Calculate the constants applied that contain the continuity, tension, and bias.
        float k1 = ( ( 1.0f - tens ) * ( 1.0f - cont ) * ( 1.0f + bias ) ) /2;
        float k2 = ( ( 1.0f - tens ) * ( 1.0f + cont ) * ( 1.0f - bias ) ) /2;
        float k3 = ( ( 1.0f - tens ) * ( 1.0f + cont ) * ( 1.0f + bias ) ) /2;
        float k4 = ( ( 1.0f - tens ) * ( 1.0f - cont ) * ( 1.0f - bias ) ) /2;

        leftTangent.x = k1 * pCurrentMinusPrevious.x + k2 * pNextMinusCurrent.x;
        leftTangent.y = k1 * pCurrentMinusPrevious.y + k2 * pNextMinusCurrent.y;
        rightTangent.x = k3 * pCurrentMinusPrevious.x + k4 * pNextMinusCurrent.x;
        rightTangent.y = k3 * pCurrentMinusPrevious.y + k4 * pNextMinusCurrent.y;
    }

    // ---------------------------------------------------
    template<class T>
    float BaseAnimationCurve<T>::findT ( float cp0x,
                                         float cp1x,
                                         float cp2x,
                                         float cp3x,
                                         float input,
                                         float initialGuess ) const
    {
        float localTolerance = 0.001f;
        float highT = 1.0f;
        float lowT = 0.0f;

        //Optimize here, start with a more intuitive value than 0.5
        float midT = 0.5f;

        if ( initialGuess <= 0.1 ) midT = 0.1f; //clamp to 10% or 90%, because if miss, the cost is too high.
        else if ( initialGuess >= 0.9 ) midT = 0.9f;
        else midT = initialGuess;

        bool once = true;
        while ( ( highT-lowT ) > localTolerance )
        {
            if ( once ) once = false;
            else midT = ( highT - lowT ) / 2.0f + lowT;

            float ti = 1.0f - midT; // (1 - t)
            float calculatedTime = cp0x*ti*ti*ti + 3*cp1x*midT*ti*ti + 3*cp2x*midT*midT*ti + cp3x*midT*midT*midT;

            if ( fabsf ( calculatedTime - input ) <= localTolerance ) break; //If we 'fall' very close, we like it and break.

            if ( calculatedTime > input ) highT = midT;
            else lowT = midT;
        }

        return midT;
    }

    // --------------------------------------------------
    /**
    * Represent an animation curve.
    */

    class AnimationCurve : public BaseAnimationCurve<AnimationKey>
    {

    public:

        AnimationCurve ( const AnimationElement* parent, const String& baseId );
        virtual ~AnimationCurve() {};

        /**
        * Adds a key of the given interpolation type to the curve.
        * If it is a tangent or a tcb interpolation type, the flag of using this will be set.
        */
        AnimationKey* addKey ( COLLADASW::LibraryAnimations::InterpolationType interpolation );

        /** Applies a conversion function to the key output values of the animation curve.
        * @param valueConversion The conversion function to use on the key outputs.
        * @param tangentConversion The conversion function to use on the key tangents.
        */
        void convertValues ( ConversionFunctor* valueConversion,
                             ConversionFunctor* tangentConversion );

        /**
        Main workhorse for the animation system:
        Evaluates the curve for a given input
        @param input An input value.
        @return output A floating-point value. */
        float evaluate ( float input ) const;

    };

    /** Animation curve list */
    typedef std::vector<AnimationCurve*> AnimationCurveList;


    /**
    A COLLADA multi-dimensional animation curve.

    This is a utility class that is used to convert multiple
    animation curves into one animation curve that has multiple
    dimensions, but only one list of key inputs.
    */

    class AnimationMultiCurve : public BaseAnimationCurve<AnimationMKey>
    {

    public:
        /** Constructor.
        The number of dimensions will not change in the lifetime of a multi-dimensional curve.
        @param the animation element, that owns the animation curve.
        @param dimension The number of dimensions for the animation curve. */
        AnimationMultiCurve ( const AnimationElement* parent, const String& baseId, const uint dimension );
        virtual ~AnimationMultiCurve() {};

        /** Adds a key in depend of the interpolation type to the curve. */
        AnimationMKey* addKey ( COLLADASW::LibraryAnimations::InterpolationType interpolation );

        /** Samples all the curves for a given input.
        @param input An input value.
        @param output An array of floating-point values to fill in with the sampled values. */
        void evaluate ( float input, float* output ) const;
    };

}

#endif // __COLLADA_MAYA_ANIMATION_CURVES_H__

