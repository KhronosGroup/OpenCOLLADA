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

#ifndef __COLLADA_MAYA_ANIMATION_CLIP_EXPORTER_H__
#define __COLLADA_MAYA_ANIMATION_CLIP_EXPORTER_H__

#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaAnimationTools.h"

#include "COLLADALibraryAnimationClips.h"


namespace COLLADAMaya
{

    // ----------------------------------------------------------
    /**
    * Class to export the animation clips.
    */

    class AnimationClipExporter : public COLLADA::LibraryAnimationClips
    {

    public:

        /** Constructor */
        AnimationClipExporter ( COLLADA::StreamWriter* _streamWriter );
        virtual ~AnimationClipExporter() {};

        /** Exports all animation clips from the member animation list. */
        void exportAnimationClips ( const AnimationClipList* animationClips );
    };
}


#endif // __COLLADA_MAYA_ANIMATION_CLIP_EXPORTER_H__
