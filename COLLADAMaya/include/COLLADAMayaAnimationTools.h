/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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

