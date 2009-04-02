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

    private:

        /**
        * The list of the unique maya animation names.
        */
        COLLADABU::IDList mAnimationIdList;

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
         * Imports the data of an animtion curve (no formula).
         */
        void importAnimationCurve ( COLLADAFW::AnimationCurve* animationCurve );

        /**
         * Imports the data of a bezier curve.
         */
        void importBezierCurve ( 
            MayaDM::AnimCurveTL& animCurve, 
            COLLADAFW::AnimationCurve* animationCurve );

    private:

        /** Disable default copy ctor. */
		AnimationImporter( const AnimationImporter& pre );

        /** Disable default assignment operator. */
		const AnimationImporter& operator= ( const AnimationImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_ANIMATIONIMPORTER_H__
