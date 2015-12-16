/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryAnimationClips.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
	ColladaAnimationClip::ColladaAnimationClip(const String& animationClipId, const String& animationClipSourceId)
		: mAnimationClipId(animationClipId), mAnimationClipSourceId(animationClipSourceId), mStartTime(-1.0f), mEndTime(-1.0f)
    {}

    //---------------------------------------------------------------
	ColladaAnimationClip::ColladaAnimationClip(const String& animationClipId, const String& animationClipSourceId, float &startTime, float &endTime)
		: mAnimationClipId(animationClipId), mAnimationClipSourceId(animationClipSourceId), mStartTime(startTime), mEndTime(endTime)
    {}

    //---------------------------------------------------------------
    ColladaAnimationClip::ColladaAnimationClip ( float &startTime, float &endTime )
            : mAnimationClipId ( ElementWriter::EMPTY_STRING ), mStartTime ( startTime ), mEndTime ( endTime )
    {}

    //---------------------------------------------------------------
    LibraryAnimationClips::LibraryAnimationClips ( COLLADASW::StreamWriter* streamWriter )
            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_ANIMATION_CLIPS )
    {}


    //---------------------------------------------------------------
    void LibraryAnimationClips::addAnimationClip ( const ColladaAnimationClip& animationClip )
    {
        // Opens the library, if it is not already open.
        openLibrary();
        mSW->openElement ( CSWC::CSW_ELEMENT_ANIMATION_CLIP );

        if ( !animationClip.getAnimationClipId().empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, animationClip.getAnimationClipId() );

        if (!animationClip.getName().empty())
            mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, animationClip.getName());

        if ( animationClip.getStartTime() != ( -1.0f ) )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_START, animationClip.getStartTime() );

        if ( animationClip.getEndTime() != ( -1.0f ) )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_END, animationClip.getEndTime() );

        const AnimationInstances instancedAnimations = animationClip.getInstancedAnimations();

        AnimationInstances::const_iterator instancedAnimationsIter = instancedAnimations.begin();
        for ( ; instancedAnimationsIter != instancedAnimations.end(); ++instancedAnimationsIter )
        {
            String instanceName = *instancedAnimationsIter;
            mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_ANIMATION );
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_URL, "#" + instanceName );
            mSW->closeElement();
        }
		
		if (animationClip.isAnimationEvent())
			animationClip.addExtraTechniques(mSW);

        mSW->closeElement();
    }


} //namespace COLLADASW
