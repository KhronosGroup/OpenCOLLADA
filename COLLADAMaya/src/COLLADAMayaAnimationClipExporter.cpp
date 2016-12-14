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
#include "COLLADAMayaExportOptions.h"

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
			
			MarkersList::iterator markerIter = animationClip->markers.begin();
			for (; markerIter != animationClip->markers.end(); ++markerIter)
			{
				COLLADASW::MarkersSW swMarkerElement;
				
				COLLADASW::WideString markerName;
				if (ExportOptions::exportEncodedNames())
					markerName = COLLADABU::StringUtils::checkNCNameWithUCS2Encoding(markerIter->ID.asWChar(), true);
				else
					markerName = COLLADABU::StringUtils::checkNCName(markerIter->ID.asWChar(), true);

				swMarkerElement.ID = COLLADABU::StringUtils::wideString2utf8String(markerName);
				swMarkerElement.time = markerIter->time;

				animationClip->colladaClip->getMarkersList().push_back(swMarkerElement);
			}

			addAnimationClip ( *animationClip->colladaClip);
        }

        closeLibrary();
    }

} // namespace COLLADAMaya
