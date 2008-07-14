/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAnimationClipExporter.h"

namespace COLLADAMaya
{

    //---------------------------------------------------------------
    AnimationClipExporter::AnimationClipExporter ( COLLADA::StreamWriter* _streamWriter )
            : COLLADA::LibraryAnimationClips ( _streamWriter )
    {}

    //---------------------------------------------------------------
    void AnimationClipExporter::exportAnimationClips ( const AnimationClipList* animationClips )
    {
        AnimationClipList::const_iterator clipIter = animationClips->begin();

        for ( ; clipIter!= animationClips->end(); ++clipIter )
        {
            AnimationClip* animationClip = *clipIter;
            addAnimationClip ( *animationClip->colladaClip );
        }

        closeLibrary();
    }

} // namespace COLLADAMaya
