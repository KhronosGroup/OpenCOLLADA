/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_ANIMATION_H__
#define __COLLADASTREAMWRITER_LIBRARY_ANIMATION_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWInputList.h"
#include "COLLADABUURI.h"

#include <vector>
#include <list>

namespace COLLADASW
{
    /**
     * Class which represent an animation element.
     * This is needed, cause we have to be able to nest multiple animations.
     */

    class Animation : public ElementWriter
    {

    public:
        Animation ( StreamWriter* streamWriter ) : ElementWriter ( streamWriter ) {}

        /** Writes the opening @a \<Animation\>  tag and, if necessary the opening @a \<library_animations\> tag.
        closeAnimation() must be use to close the opened tags.
        @param id the id of the animation
        @param name the name of the animation*/
        void openAnimation ( const String& id = EMPTY_STRING, const String& name = EMPTY_STRING );

        /** Closes the tag opened by openAnimation()*/
        void closeAnimation();

    private:

        /** The closer for the current animation tag. */
        TagCloser mAnimationCloser;
    };

    /**
     * Class to simply the creation of @a \<library_geometries\> and @a \<geometry\>'s
     */

    class LibraryAnimations : public Library
    {

    public:

        class Sampler
        {
			/** semantics formerly defined here have been moved to COLLADASWInputList.h */ 
        private:

            /** The id of the sampler*/
            String mId;

            /** The list of inputs of the sampler*/
            InputList mInputList;

        public:
            /** Constructor
            @param id The id of the sampler.
            */
            Sampler ( StreamWriter * streamWriter, const String& id );

            /** Returns a const reference of the sampler id*/
            const String& getId() const
            {
                return mId;
            }

            /** Adds an input element to the sampler*/
			void addInput ( InputSemantic::Semantics semantic, const COLLADABU::URI& source );

            /** Returns a const reference of the Inputlist*/
            const InputList& getInputList() const
            {
                return mInputList;
            }
        };


        LibraryAnimations ( StreamWriter * streamWriter );

        static const String LINEAR_NAME;
        static const String BEZIER_NAME;
        static const String CARDINAL_NAME;
        static const String HERMITE_NAME;
        static const String BSPLINE_NAME;
        static const String TCB_NAME;
        static const String STEP_NAME;

        /** An animation curve interpolation type. */
        enum InterpolationType
        {
            LINEAR=0, /**< Linear interpolation. Uses the average slope between the previous key
       and the next key. */
            BEZIER,  /**< Bezier interpolation. Uses two 2D control points for each segment,
       wrongly called in-tangent and out-tangent in COLLADASW. */
            CARDINAL,
            HERMITE,
            BSPLINE,
            STEP,  /**< No interpolation. Uses the output value of the previous key until the
       next key time is reached. */
            TCB,  /**< TCB interpolation. Uses Tension, Continuity and Bias values to generate
       Hermite tangents. This interpolation type is not standard COLLADASW. */
            DEFAULT = STEP
        };

        static const String INPUT_SOURCE_ID_SUFFIX;
        static const String OUTPUT_SOURCE_ID_SUFFIX;
        static const String INTANGENT_SOURCE_ID_SUFFIX;
        static const String OUTTANGENT_SOURCE_ID_SUFFIX;
        static const String INTERPOLATION_SOURCE_ID_SUFFIX;
        static const String TCBS_SOURCE_ID_SUFFIX;
        static const String EASES_SOURCE_ID_SUFFIX;
        static const String ARRAY_ID_SUFFIX;

        static const String SAMPLER_ID_SUFFIX;

    protected:

        /** Writes the opening @a \<Animation\>  tag and, if necessary the opening @a \<library_animations\> tag.
        closeAnimation() must be use to close the opened tags.
        @param id the id of the animation
        @param name the name of the animation*/
        void openAnimation ( const String& id = EMPTY_STRING, const String& name = EMPTY_STRING );

        /** Closes the tag opened by openAnimation()*/
        void closeAnimation();

        /** Adds the @a sampler to the stream*/
        void addSampler ( const Sampler& sampler );

        /** Adds channel with @a source and @a target to the animation*/
        void addChannel ( const URI& source, const String& target );

        /** Returns the name of the interpolation type*/
        static const String& getNameOfInterpolation ( const InterpolationType& type );


    private:

        /** This vector holds all open animations. We need this to nest multiple animations. */
        std::vector<Animation*> mOpenAnimations;

    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_ANIMATION_H__
