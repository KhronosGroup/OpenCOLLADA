/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_ANIMATIONIMPORTER_H__
#define __COLLADAMAYA_ANIMATIONIMPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADAFWAnimationCurve.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWTransformation.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWSkew.h"
#include "COLLADAFWTranslate.h"

#include "COLLADABUIDList.h"

#include "MayaDMAnimCurveTL.h"
#include "MayaDMAnimCurveTU.h"
#include "MayaDMAnimCurveTA.h"
#include "MayaDMTransform.h"


namespace COLLADAMaya
{

    /** TODO Documentation */
	class AnimationImporter : public BaseImporter 
	{
	private:
	
        /** The standard name for an animation. */
        static const String ANIMATION_NAME;

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

    private:

        /**
        * The list of the unique maya animation names.
        */
        COLLADABU::IDList mAnimationIdList;

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
         * The map holds for every animation curve a list of node ids, which use this connections.
         */

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
        * The map holds for every unique animation id the maya animatio curve.
        */
        const std::vector<MayaDM::AnimCurve*>* findMayaDMAnimCurves ( 
            const COLLADAFW::UniqueId& animationId );

        /**
        * Makes the connections between the animations and the animated objects.
        */
        void writeConnections ( const COLLADAFW::AnimationList* animationList );

        void writeEffectConnections ( 
            const COLLADAFW::UniqueId& animationListId, 
            const COLLADAFW::AnimationList::AnimationBindings& animationBindings );

        void writeTransformConnections ( 
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
            const COLLADAFW::AnimationList::AnimationBindings& animationBindings, 
            const MayaDM::Transform* transform );

    private:

        /**
         * Imports the data of an animtion curve (no formula).
         */
        void importAnimationCurve ( COLLADAFW::AnimationCurve* animationCurve );

        /**
         * Imports the data of a a curve.
         */
        void writeAnimationCurve ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            const TangentType& tangentType = TANGENT_TYPE_DEFAULT, 
            const TangentType& keyTangentOutType = TANGENT_TYPE_DEFAULT );

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
        * Returns the value at the given position of the given array as double value.
        */
        double getDoubleValue ( 
            const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
            const size_t position );

        /**
        * Returns true, if the given id is in the list.
        */
        const bool findAnimation ( const COLLADAFW::UniqueId& animationId );

        /**
         * Returns true, if the given id is in the list.
         */
        const bool findAnimationList ( const COLLADAFW::UniqueId& animationListId );

    private:

        /** Disable default copy ctor. */
		AnimationImporter( const AnimationImporter& pre );

        /** Disable default assignment operator. */
		const AnimationImporter& operator= ( const AnimationImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_ANIMATIONIMPORTER_H__
