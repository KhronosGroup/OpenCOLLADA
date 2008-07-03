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
#ifndef __COLLADA_MAYA_ANIMATED_ELEMENT_H__
#define __COLLADA_MAYA_ANIMATED_ELEMENT_H__

#include "ColladaMayaPrerequisites.h"
#include "COLLADAMayaAnimationTools.h"
#include "COLLADAMayaConversion.h"

namespace COLLADAMaya
{

    // ----------------------------------------------------------
    /**
    * Each AnimationElement holds the animation curves for one animatable element,
    * such as a single floating-point value, a 3D std::vector or a matrix.
    */

    class AnimationElement;

    class AnimationCurve;

    /** Animation curve list */
    typedef std::vector<AnimationCurve*> AnimationCurveList;

    /** The list with the animated elements. */
    typedef std::vector<AnimationElement*> AnimatedElementList;


    // ----------------------------------------------------------
    /**
    * This class represents an animation element. It holds a list of animated curves.
    */

    class AnimationElement
    {

    private:

        /** The ids of the current element. */
        String mBaseId;
        String mSubId;
        String mNodeId;

        /** The plug, which is the connection to the animated attribute. */
        MPlug mPlug;

        /** true, if it is a sampled animation. */
        bool mIsSampling;

        /** The parameters of the current attribute. */
        const String* mParameters;

        /** The sample type of the current attribute. Could be for example a single one or a vector. */
        SampleType mSampleType;

        /** The list of the animated curves of the current element. */
        AnimationCurveList mAnimatedCurves;

        /** The conversion functor, for example to convert radians to degrees. */
        ConversionFunctor* mConversion;

        /** A list with sub animated elements. */
        AnimatedElementList mAnimatedChildElements;

        /** True, if the current animated element has grouped attributes. Children exist. */
        bool mIsCompound;

    public:

        /** Constructor */
        AnimationElement ( MPlug plug, const String& baseId,
                           const String& subId, const String& nodeId,
                           const String parameters[], SampleType sampleType=kSingle );
        virtual ~AnimationElement();

        /** Returns the base id. */
        const String& getBaseId() const
        {
            return mBaseId;
        }

        const String& getSubId() const
        {
            return mSubId;
        }

        const String& getNodeId() const
        {
            return mNodeId;
        }

        void setNodeId ( String nodeId )
        {
            mNodeId = nodeId;
        }

        /** Returns the plug of the current element. */
        const MPlug& getPlug() const
        {
            return mPlug;
        }

        /** Returns the parameters of the current plug. */
        const String* getParameters() const
        {
            return mParameters;
        }

        /** Returns the sample type of the current plug. */
        SampleType getSampleType() const
        {
            return mSampleType;
        }

        void setSampleType ( SampleType sampleType )
        {
            mSampleType = sampleType;
        }

        /** The conversion functor, for example to convert radians to degrees */
        ConversionFunctor* getConversion()
        {
            return mConversion;
        }

        /** Set the conversion functor for the values of the plug. */
        void setConversion ( ConversionFunctor* conversion )
        {
            mConversion = conversion;
        }

        /** The dimension of the current plug. If it is for example a vector or a single value. */
        uint getDimension() const;

        /** Adds a animated curve to the current element. */
        void addAnimatedCurve ( AnimationCurve* animatedCurve )
        {
            mAnimatedCurves.push_back ( animatedCurve );
        }

        const AnimationCurveList& getAnimatedCurves() const
        {
            return mAnimatedCurves;
        }

        /** true, if it is a sampled animation. */
        bool isSampling() const
        {
            return mIsSampling;
        }

        void setIsSampling ( bool _isSampling )
        {
            mIsSampling = _isSampling;
        }

        /** Adds a animated element to list of child elements of the current element. */
        void addChildElement ( AnimationElement* childElement )
        {
            mAnimatedChildElements.push_back ( childElement );
        }

        /** Returns the list with the animated child elements. */
        const AnimatedElementList& getAnimatedChildElements() const
        {
            return mAnimatedChildElements;
        }

        /** Recursive call, if the element or a child element has a curve. */
        bool hasCurves() const;

        /** true, if the attributes of the current element are grouped. */
        bool isCompoundElement() const
        {
            return mIsCompound;
        }

        void isCompoundElement ( bool isCompound )
        {
            mIsCompound = isCompound;
        }

    };

}

#endif // __COLLADA_MAYA_ANIMATED_ELEMENT_H__

