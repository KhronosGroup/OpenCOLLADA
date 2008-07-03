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

#ifndef __COLLADASTREAMWRITER_LIBRARY_ANIMATION_CLIPS_H__
#define __COLLADASTREAMWRITER_LIBRARY_ANIMATION_CLIPS_H__

#include "COLLADAPrerequisites.h"
#include "COLLADALibrary.h"
#include <vector>

namespace COLLADA
{
    /** The list of animation instances. */
    typedef std::vector<String> AnimationInstances;


    class ColladaAnimationClip
    {

    public:
        ColladaAnimationClip ( const String& animationClipId = ElementWriter::EMPTY_STRING );
        ColladaAnimationClip ( const String& animationClipId, float& startTime, float& endTime );
        ColladaAnimationClip ( float& startTime, float& endTime );

        /** Returns a reference to then image id*/
        const String& getAnimationClipId() const
        {
            return mAnimationClipId;
        }

        /** Retrieves the start time marker position for this animation clip.
        When using the animation clip, all the animation curves will need
        to be synchronized in order for the animation to start at the start time.
        @return The start time marker position, in seconds. */
        float getStartTime() const
        {
            return mStartTime;
        }

        /** Sets the start time marker position for this animation clip.
        @param startTime The new start time marker position. */
        void setStartTime ( float startTime )
        {
            mStartTime = startTime;
        }

        /** Retrieves the end time marker position for this animation clip.
        When using the animation clip, all the animation curves will need
        to be synchronized in order for the animation to complete at the end time.
        @return The end time marker position, in seconds. */
        float getEndTime() const
        {
            return mEndTime;
        }

        /** Sets the end time marker position for this animation clip.
        @param endTime The end time marker position. */
        void setEndTime ( float endTime )
        {
            mEndTime = endTime;
        }

        /** Adds an animation instance to the list of instantiated animations. */
        void setInstancedAnimation ( const String& animationId )
        {
            mInstancedAnimations.push_back ( animationId );
        }

        /** Returns the list with the instanced animations. */
        const AnimationInstances& getInstancedAnimations() const
        {
            return mInstancedAnimations;
        }

    private:

        /** The id of the current animation clip. */
        String mAnimationClipId;

        /** The start time of the current clip. */
        float mStartTime;

        /** The end time of the current clip. */
        float mEndTime;

        /** The list of animations, which use this clip. */
        AnimationInstances mInstancedAnimations;
    };


    /** Class to simply the creation of @a \<library_images\> and @a \<images\>'s*/

    class LibraryAnimationClips : public Library
    {

    public:
        LibraryAnimationClips ( StreamWriter* streamWriter );

    protected:

        /** Adds @a \<animation_clip\> element. If not already opened, it opens @a \<library_animation_clips\>*/
        void addAnimationClip ( const ColladaAnimationClip& animationClip );

    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_ANIMATION_CLIPS_H__