/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
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
