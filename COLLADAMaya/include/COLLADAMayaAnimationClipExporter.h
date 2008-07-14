/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
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
