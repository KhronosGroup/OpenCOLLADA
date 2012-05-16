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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaAnimationClipExporter.h"

namespace COLLADAMaya
{

    //---------------------------------------------------------------
    AnimationClipExporter::AnimationClipExporter ( COLLADASW::StreamWriter* _streamWriter )
            : COLLADASW::LibraryAnimationClips ( _streamWriter )
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
