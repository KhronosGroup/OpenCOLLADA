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


#include "COLLADASWSource.h"
#include "COLLADASWLibraryAnimations.h"

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
	void LibraryAnimationClips::addAnimationClip(const ColladaAnimationClip& animationClip)
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
		
//		if (animationClip.isAnimationEvent())
//			animationClip.addExtraTechniques(mSW);

		std::vector<float> valuesTime;
		std::vector<String> valuesID;

		MarkersList markers = const_cast<ColladaAnimationClip&>(animationClip).getMarkersList();

		MarkersList::const_iterator markerIter = markers.begin();
		for (; markerIter != markers.end(); ++markerIter)
		{
			valuesTime.push_back(markerIter->time);
			valuesID.push_back(markerIter->ID);
		}


		if (!valuesTime.empty())
		{
			mSW->openElement(CSWC::CSW_ELEMENT_EXTRA);
			{
				mSW->openElement(CSWC::CSW_ELEMENT_TECHNIQUE);
				mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_PROFILE, "OpenCOLLADAMaya");
				{
					mSW->openElement(CSWC::CSW_ELEMENT_EVENT);

					const String sourceId = "-marker";

					mSW->openElement(CSWC::CSW_ELEMENT_TIMESTAMPS);
					mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_ID, animationClip.getAnimationClipId() + sourceId + LibraryAnimations::INPUT_SOURCE_ID_SUFFIX + LibraryAnimations::ARRAY_ID_SUFFIX);
					mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_COUNT, (unsigned long)valuesTime.size());
					mSW->appendValues(valuesTime);
					mSW->closeElement();
									
					mSW->openElement(CSWC::CSW_ELEMENT_MARKERS);
					mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_ID, animationClip.getAnimationClipId() + sourceId + LibraryAnimations::NAME_SOURCE_ID_SUFFIX + LibraryAnimations::ARRAY_ID_SUFFIX);
					mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_COUNT, (unsigned long)valuesID.size());
					mSW->appendValues(valuesID);
					mSW->closeElement();

					mSW->closeElement();
				}
				mSW->closeElement();
			}
			mSW->closeElement();
		}



        mSW->closeElement();
    }


} //namespace COLLADASW
