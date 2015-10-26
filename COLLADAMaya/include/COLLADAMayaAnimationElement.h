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

#ifndef __COLLADA_MAYA_ANIMATED_ELEMENT_H__
#define __COLLADA_MAYA_ANIMATED_ELEMENT_H__

#include "COLLADAMayaPrerequisites.h"
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
		String mOriginalBaseId;
        String mNodeId;
        String mTargetSid;
        String mOriginalColladaId;

        /** The plug, which is the connection to the animated attribute. */
        MPlug mPlug;

        /** true, if it is a sampled animation. */
        bool mIsSampling;

        /** The parameters of the current attribute. */
        const String* mParameters;

        /** The sample type of the current attribute. Could be for example a single one or a vector. */
        SampleType mSampleType;

		MEulerRotation::RotationOrder mOrder;

        /** The list of the animated curves of the current element. */
        AnimationCurveList mAnimatedCurves;

        /** The conversion functor, for example to convert radians to degrees. */
        ConversionFunctor* mConversion;

        /** A list with sub animated elements. */
        AnimatedElementList mAnimatedChildElements;

        /** True, if the current animated element has grouped attributes. Children exist. */
        bool mIsCompound;

        /** Flag to indicate that the animation should be applied relative to the default value. */
        bool mIsRelativeAnimation;

        /** The array element of the animated value. */
        int mArrayElement;

        /** True, if the internal units has to be converted into the UI units.  */
        bool mConvertUnits;

		bool mNeedToexport;

    public:

        /** Constructor. */
        AnimationElement (
            MPlug plug,
            const String& baseId,
            const String& targetSid,
            const String& nodeId,
            const String parameters[],
            const bool convertUnits,
			MEulerRotation::RotationOrder euler,
            SampleType sampleType = kSingle
			);

        /** Destructor. */
        virtual ~AnimationElement();

        const COLLADAMaya::String& getOriginalColladaId () const { return mOriginalColladaId; }
        void setOriginalColladaId ( const COLLADAMaya::String& val ) { mOriginalColladaId = val; }

        /** Returns the base id. */
        const String& getBaseId() const
        {
            return mBaseId;
        }

		void setBaseId(String name)
		{
			mBaseId = name;
		}
		
		void setOriginalBaseId(String name)
		{
			mOriginalBaseId = name;
		}

		const String& getOriginalBaseId() const
		{
			return mOriginalBaseId;
		}

        const String& getTargetSid() const
        {
            return mTargetSid;
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

        /** Returns, if the internal units has to be converted into the UI units. */
        const bool getConvertUnits () const 
        { 
            return mConvertUnits; 
        }

        /** Returns the sample type of the current plug. */
        SampleType getSampleType() const
        {
            return mSampleType;
        }

        /** Set the sample type of the current plug. */
        void setSampleType ( SampleType sampleType )
        {
            mSampleType = sampleType;
        }

		MEulerRotation::RotationOrder getOrder() const
		{
			return mOrder;
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

		void clearAnimatedCurve()
		{
			mAnimatedCurves.clear();
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

        /** Flag to indicate that the animation should be applied relative to the default value. */
        const bool getIsRelativeAnimation() const
        {
            return mIsRelativeAnimation;
        }

        /** Flag to indicate that the animation should be applied relative to the default value. */
        void setIsRelativeAnimation( bool val )
        {
            mIsRelativeAnimation = val;
        }

        /** The array element of the animated value. */
        const int getArrayElement() const
        {
            return mArrayElement;
        }

        /** The array element of the animated value. */
        void setArrayElement ( int val )
        {
            mArrayElement = val;
        }

		const bool isExported() const
		{
			return mNeedToexport;
		}

		void isExported(bool val)
		{
			mNeedToexport = val;
		}
    };

}

#endif // __COLLADA_MAYA_ANIMATED_ELEMENT_H__

