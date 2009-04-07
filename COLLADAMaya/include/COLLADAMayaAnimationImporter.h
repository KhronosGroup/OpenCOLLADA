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

        enum TangentType
        {
            TANGENT_TYPE_FIXED = 1,
            TANGENT_TYPE_LINEAR = 2,
            TANGENT_TYPE_FLAT = 3,
            TANGENT_TYPE_DEFAULT = 4,
            TANGENT_TYPE_STEP = 5,
            TANGENT_TYPE_SLOW = 6,
            TANGENT_TYPE_FAST = 7,
            TANGENT_TYPE_SPLINE = 9,
            TANGENT_TYPE_CLAMPED = 10, // BEZIER
            TANGENT_TYPE_PLATEAU = 16,
            TANGENT_TYPE_STEP_NEXT = 17
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
        * Writes the connection attributes into the maya ascii file. 
        */
        void writeConnections ();

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
         * Imports the data of a bezier curve.
         */
        void importBezierCurve ( 
            const COLLADAFW::AnimationCurve* animationCurve, 
            const TangentType& tangentType, 
            const bool weightedTangents = false, 
            const bool keyTanLocked = true );

        void setKeyTimeValues ( 
            const COLLADAFW::AnimationCurve* fwAnimationCurve, 
            MayaDM::AnimCurveTL& animCurveTL, 
            const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
            const COLLADAFW::FloatOrDoubleArray &outputValuesArray, 
            const size_t outputIndex );

    private:

        /** Disable default copy ctor. */
		AnimationImporter( const AnimationImporter& pre );

        /** Disable default assignment operator. */
		const AnimationImporter& operator= ( const AnimationImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_ANIMATIONIMPORTER_H__
