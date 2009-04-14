/*
    Copyright (c) 2008 NetAllied Systems GmbH

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

#include "COLLADABUIDList.h"

#include "MayaDMAnimCurveTL.h"


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
         * The map holds for every unique animation id the maya animatio curve.
         */
        std::map<COLLADAFW::UniqueId, std::vector<MayaDM::AnimCurveTL> > mMayaDMAnimationCurves;

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
        const std::vector<MayaDM::AnimCurveTL>* findMayaDMAnimationCurve ( const COLLADAFW::UniqueId& animationId );

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
            const TangentType& keyTangentOutType = TANGENT_TYPE_DEFAULT, 
            const bool weightedTangents = false, 
            const bool keyTanLocked = true );

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
            MayaDM::AnimCurveTL &animCurveTL );

        /**
        * Set the key out tangents.
        */
        void setKeyTangentOutTypes ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            MayaDM::AnimCurveTL &animCurveTL );

        /**
        * Set the key tangent locks (all the same value).
        */
        void setKeyTangentLocks ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            MayaDM::AnimCurveTL &animCurveTL, 
            const bool keyTanLocked );

        /**
         * Set the key time values.
         */
        void setKeyTimeValues ( 
            const COLLADAFW::AnimationCurve* fwAnimationCurve, 
            MayaDM::AnimCurveTL& animCurveTL, 
            const size_t outputIndex );

        /**
        * Set the in tangent values.
        */
        void setInTangents ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            MayaDM::AnimCurveTL &animCurveTL, 
            const size_t outputIndex );

        /**
         * Returns the value at the given position of the given array as double value.
         */
        double getDoubleValue ( 
            const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
            const size_t position );

        /**
        * Set the out tangent values.
        */
        void setOutTangents ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            MayaDM::AnimCurveTL &animCurveTL, 
            const size_t outputIndex );

    private:

        /** Disable default copy ctor. */
		AnimationImporter( const AnimationImporter& pre );

        /** Disable default assignment operator. */
		const AnimationImporter& operator= ( const AnimationImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_ANIMATIONIMPORTER_H__
