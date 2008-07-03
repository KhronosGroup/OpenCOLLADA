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

#ifndef __COLLADASTREAMWRITER_LIBRARY_ANIMATION_H__
#define __COLLADASTREAMWRITER_LIBRARY_ANIMATION_H__

#include "COLLADAPrerequisites.h"
#include "COLLADALibrary.h"
#include "COLLADAInputList.h"

#include <vector>
#include <list>

namespace COLLADA
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

        public:
            /** Semantics allowed in an @a \<input\> element*/
            enum Semantic
            {
                POSITION,
                INTERPOLATION,
                LINEAR_STEPS,
                INPUT,
                OUTPUT,
                IN_TANGENT,
                OUT_TANGENT,
                CONTINUITY
            };

            /** Holds all information about an @a \<input\> element.*/

            struct Input
            {
                Semantic semantic;
                String source;
            };

            /** A list of inputs*/
            typedef std::vector<Input>  InputList;

        private:
            /** The id of the sampler*/
            String mId;

            /** The list of inputs of the sampler*/
            InputList mInputList;


        public:
            /** Constructor
            @param id The id of the sampler.
            */
            Sampler ( const String& id ) : mId ( id ) {}

            /** Returns a const reference of the sampler id*/
            const String& getId() const
            {
                return mId;
            }

            /** Adds an input element to the sampler*/
            void addInput ( Semantic semantic, const String & source );

            /** Returns a const reference of the Inputlist*/
            const InputList& getInputList() const
            {
                return mInputList;
            }

            /** Returns the element name of the given type semantic. */
            static const String& getElementNameBySemantic ( Semantic semantic );


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
       wrongly called in-tangent and out-tangent in COLLADA. */
            CARDINAL,
            HERMITE,
            BSPLINE,
            STEP,  /**< No interpolation. Uses the output value of the previous key until the
       next key time is reached. */
            TCB,  /**< TCB interpolation. Uses Tension, Continuity and Bias values to generate
       Hermite tangents. This interpolation type is not standard COLLADA. */
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
        void addChannel ( const String& source, const String& target );

        /** Returns the name of the interpolation type*/
        static const String& getNameOfInterpolation ( const InterpolationType& type );



#if 0
        /** Returns the suffix string of the given type semantic. */
        static String getSuffixBySemantic ( Semantics type );
#endif


    private:

        /** This vector holds all open animations. We need this to nest multiple animations. */
        std::vector<Animation*> mOpenAnimations;

    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_ANIMATION_H__
