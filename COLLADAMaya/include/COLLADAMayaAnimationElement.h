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

