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

#ifndef __COLLADA_MAYA_ANIMATION_TOOLS_H__
#define __COLLADA_MAYA_ANIMATION_TOOLS_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADASWLibraryAnimationClips.h"

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
        // Color value: R, G, B, A
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

        COLLADASW::ColladaAnimationClip* colladaClip;
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

