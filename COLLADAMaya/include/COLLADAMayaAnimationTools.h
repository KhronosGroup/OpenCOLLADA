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

#ifndef __COLLADA_MAYA_ANIMATION_TOOLS_H__
#define __COLLADA_MAYA_ANIMATION_TOOLS_H__

#include "ColladaMayaPrerequisites.h"
#include "COLLADALibraryAnimationClips.h"

namespace COLLADAMaya
{

    // ----------------------------------------------------------
    // Use this enum when export/importing an animation to tell the expected type
    enum SampleType
    {
        // Just one float
        kSingle = 0x01,
        // Vector value: X, Y, Z
        kVector = 0x02,
        // Color value: R, G, B
        kColour = 0x03,
        // Matrix
        kMatrix = 0x04,
        // Boolean
        kBoolean = 0x05,

        // Angle type, there will be rad <-> degree conversions
        kAngle = 0x10,
        kQualifiedAngle = 0x30,
        // Length factor will be applied
        kLength = 0x40,

        kFlagMask = 0xF0,
        kValueMask = 0x07
    };



    // ----------------------------------------------------------
    /** The different types of animations */
    enum AnimationResult
    {
        kISANIM_None = 0,
        kISANIM_Curve,
        kISANIM_Sample,
        kISANIM_Character,
    };

    // ----------------------------------------------------------
    /**
     * Organizes the data of an animation clip.
     */

    class AnimationClip
    {

    public:

        AnimationClip() {};

        virtual ~AnimationClip()
        {
            delete colladaClip;
        }

        MObject characterNode;

        COLLADA::ColladaAnimationClip* colladaClip;
        MObjectArray animCurves;
        MPlugArray plugs;

        /** Returns the plug */
        int findPlug ( const MPlug& p );

        /** Gets the id of the current clip. */
        const String& getClipId() const
        {
            return colladaClip->getAnimationClipId();
        }

    };

    typedef std::vector<AnimationClip*> AnimationClipList;

    // ----------------------------------------------------------
    /**
    * Organizes the data of an animation character.
    */

    class AnimationCharacter
    {

    public:
        // Import-only
        AnimationClipList clips;
        MObject characterNode;
        MPlugArray plugs;
        MTime startTime;
    };

    typedef std::vector<AnimationCharacter> AnimationCharacterList;

}

#endif // __COLLADA_MAYA_ANIMATION_TOOLS_H__

