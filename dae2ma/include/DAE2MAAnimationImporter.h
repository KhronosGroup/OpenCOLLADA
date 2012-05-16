/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_ANIMATIONIMPORTER_H__
#define __DAE2MA_ANIMATIONIMPORTER_H__

#include "DAE2MAPrerequisites.h"
#include "DAE2MABaseImporter.h"
#include "DAE2MAMayaTransform.h"

#include "COLLADAFWAnimationCurve.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWTransformation.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWSkew.h"
#include "COLLADAFWTranslate.h"

#include "MayaDMAnimCurveTL.h"
#include "MayaDMAnimCurveTU.h"
#include "MayaDMAnimCurveTA.h"
#include "MayaDMTransform.h"


namespace DAE2MA
{

    /** TODO Documentation */
	class AnimationImporter : public BaseImporter 
	{
	private:
	
        /** The standard name for an animation. */
        static const String ANIMATION_NAME;

        /** The framerate of the animation. */
        static const double ANIM_FRAMERATE;

        /**
         * Most common tangent type of keyframes in this curve. Used as a performance optimization 
         * during file store/retrieve. The following are legal values: 
         */
        enum TangentType
        {
            TANGENT_TYPE_FIXED = 1, // Collada: BEZIER
            TANGENT_TYPE_LINEAR = 2, // Collada: STEP
            TANGENT_TYPE_FLAT = 3, // Collada: BEZIER
            TANGENT_TYPE_DEFAULT = 4, // Collada: BEZIER
            TANGENT_TYPE_STEP = 5, // Collada: STEP
            TANGENT_TYPE_SLOW = 6, // Collada: BEZIER
            TANGENT_TYPE_FAST = 7, // Collada: BEZIER
            TANGENT_TYPE_SPLINE = 9, // Collada: BEZIER
            TANGENT_TYPE_CLAMPED = 10, // Collada: BEZIER
            TANGENT_TYPE_PLATEAU = 16, // Collada: BEZIER
            TANGENT_TYPE_STEP_NEXT = 17 // Collada: BEZIER
        };

        /**
        * Store the minimum and the maximum animation time.
        */
        class PlaybackOptions
        {
        private:
            double mMinStartTime;
            double mMaxEndTime;
        public:
            PlaybackOptions () : mMinStartTime (0), mMaxEndTime (0) {}
            virtual ~PlaybackOptions () {}

            void setTimeValue ( double timeValue )
            {
                if ( timeValue > mMaxEndTime )
                    mMaxEndTime = timeValue;
                else if ( timeValue < mMinStartTime )
                    mMinStartTime = timeValue;
            }

            const double getMinStartTime () const { return mMinStartTime; }
            const double getMaxEndTime () const { return mMaxEndTime; }
        };

    private:

        /**
         * The list of the unique animation ids.
         */
        UniqueIdVec mAnimationIds;

        /**
        * The list of the unique animation list ids.
        */
        UniqueIdVec mAnimationListIds;

        /**
         * The map holds for every unique animation id the maya animatio curve.
         */
        std::map<COLLADAFW::UniqueId, std::vector<MayaDM::AnimCurve*> > mMayaDMAnimationCurves;

        /**
         * Store the minimum and the maximum animation time.
         */
        PlaybackOptions mPlaybackOptions;

        /**
         * Holds the animation ids of animations on scale transformations.
         */
        UniqueIdVec mScaleAnimations;

    public:

        /** Constructor. */
        AnimationImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~AnimationImporter();

        /**
         * Imports the the data of the current animation.
         */
        void importAnimation ( const COLLADAFW::Animation* animation );

        /**
         * Get the minimum and the maximum time values of the animations to get the start 
         * time and the end time of the animation. This times we have to set as the 
         * "playbackOptions" in the "sceneConfigurationScriptNode".
         */
        void importPlaybackOptions ();

        /**
        * Makes the connections between the animations and the animated objects.
        */
        void writeConnections ( const COLLADAFW::AnimationList* animationList );

        /**
         * Check if the current animation list is a scale animation. Store the scale animations
         * in a list.
         */
        void detectScaleAnimations ( const COLLADAFW::AnimationList* animationList );

    private:

        void connectMorphControllers ( 
            const COLLADAFW::UniqueId& animationListId, 
            const COLLADAFW::AnimationList::AnimationBindings& animationBindings );

        void connectEffects ( 
            const COLLADAFW::UniqueId& animationListId, 
            const COLLADAFW::AnimationList::AnimationBindings& animationBindings );

        void connectTransforms ( 
            const COLLADAFW::UniqueId& animationListId, 
            const COLLADAFW::AnimationList::AnimationBindings& animationBindings );

        void writeTranslateConnections ( 
            const COLLADAFW::Transformation* transformation, 
            const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
            const MayaDM::Transform* transform );

        void writeSkewConnections ( 
            const COLLADAFW::Transformation* transformation, 
            const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
            const MayaDM::Transform* transform );

        void writeScaleConnections ( 
            const COLLADAFW::Transformation* transformation, 
            const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
            const MayaDM::Transform* transform );

        /**
         * Makes the connections between 
         */
        void writeRotateConnections ( 
            const COLLADAFW::Transformation* transformation, 
            const MayaTransform::TransformPhase& transformPhase, 
            const bool isJointTransform, 
            const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
            const MayaDM::Transform* transform );

        /**
         * Imports the data of an animtion curve (no formula).
         */
        void importAnimationCurve ( COLLADAFW::AnimationCurve* animationCurve );

        /**
         * Imports the data of a a curve.
         */
        void writeAnimationCurve ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            const TangentType& tangentType = TANGENT_TYPE_DEFAULT );

        /**
         * Multiple interpolation types. Curve by keys.
         */
        void writeAnimationCurveByKeys (
            const COLLADAFW::AnimationCurve* animationCurve );

        /**
         * Set the key in tangents.
         */
        void setKeyTangentInTypes ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            MayaDM::AnimCurve* animCurve );

        /**
        * Set the key out tangents.
        */
        void setKeyTangentOutTypes ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            MayaDM::AnimCurve* animCurve );

        /**
        * Set the key tangent locks (all the same value).
        */
        void setKeyTangentLocks ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            MayaDM::AnimCurve* animCurve, 
            const bool keyTanLocked );

        /**
         * Set the key time values.
         * The anim curve node is an "animCurve" that takes an attribute of type "time" as input 
         * and has an output attribute of type "distance".
         */
        void setKeyTimeValues ( 
            const COLLADAFW::AnimationCurve* fwAnimationCurve, 
            MayaDM::AnimCurveTL* animCurveTL, 
            const size_t outputIndex );

        /**
        * Set the key time values.
        * The anim curve node is an "animCurve" that takes an attribute of type "time" as input 
        * and has an output attribute of type "distance".
        */
        void setKeyTimeValues ( 
            const COLLADAFW::AnimationCurve* fwAnimationCurve, 
            MayaDM::AnimCurveTU* animCurveTU, 
            const size_t outputIndex );

        /**
        * Set the key time values.
        * The anim curve node node is an "animCurve" that takes an attribute of type "time" as 
        * input and has an output attribute of type "angle".
        */
        void setKeyTimeValues ( 
            const COLLADAFW::AnimationCurve* fwAnimationCurve, 
            MayaDM::AnimCurveTA* animCurveTA, 
            const size_t outputIndex );

        /**
        * Set the in tangent values.
        */
        void setWeightedInTangents ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
            const size_t outputIndex, 
            MayaDM::AnimCurve* animCurve );

        void setWeightedInTangentYValues ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
            const size_t outputIndex, 
            MayaDM::AnimCurve* animCurve );

        void setWeightedInTangentXValues ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
            const size_t outputIndex, 
            MayaDM::AnimCurve* animCurve );

        /**
        * Set the out tangent values.
        */
        void setWeightedOutTangents ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
            const size_t outputIndex, 
            MayaDM::AnimCurve* animCurve );

        void setWeightedOutTangentYValues ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
            const size_t outputIndex, 
            MayaDM::AnimCurve* animCurve );

        void setWeightedOutTangentXValues ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            const COLLADAFW::PhysicalDimension& outPhysicalDimension, 
            const size_t outputIndex, 
            MayaDM::AnimCurve* animCurve );

        /**
        * Set the in tangent values.
        */
        void setNonWeightedInTangents ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            MayaDM::AnimCurve* animCurve, 
            const size_t outputIndex,
            const bool normalize = true );

        /**
        * Set the out tangent values.
        */
        void setNonWeightedOutTangents ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            MayaDM::AnimCurve* animCurve, 
            const size_t outputIndex,
            const bool normalize = true );

        /**
        * Returns true, if the given id is in the list.
        */
        const bool findAnimation ( const COLLADAFW::UniqueId& animationId );

        /**
         * Returns true, if the given id is in the list.
         */
        const bool findAnimationList ( const COLLADAFW::UniqueId& animationListId );

        /**
        * The map holds for every unique animation id the maya animatio curve.
        */
        const std::vector<MayaDM::AnimCurve*>* findMayaDMAnimCurves ( 
            const COLLADAFW::UniqueId& animationId );


        /**
        * Returns true, if the animation with the current id is a scale animation.
        */
        const bool isScaleAnimation ( const COLLADAFW::UniqueId& animationId );

        /** Disable default copy ctor. */
		AnimationImporter( const AnimationImporter& pre );

        /** Disable default assignment operator. */
		const AnimationImporter& operator= ( const AnimationImporter& pre );

	};

} // namespace DAE2MA

#endif // __DAE2MA_ANIMATIONIMPORTER_H__
