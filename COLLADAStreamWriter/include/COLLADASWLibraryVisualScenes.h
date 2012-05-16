/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_VISUAL_SCENES_H__
#define __COLLADASTREAMWRITER_VISUAL_SCENES_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_visual_scenes\> and @a \<visual_scene\>'s*/

    class LibraryVisualScenes : public Library
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_visual_scenes\> and @a \<visual_scene\>'s
        should be written to.
        */
        LibraryVisualScenes ( StreamWriter* streamWriter );

        /** Destructor*/
        virtual ~LibraryVisualScenes() {}

    protected:
        /** Writes the opening @a \<visual_scene\> tag and, if necessary the opening @a \<library_visual_scenes\> tag.
        closeVisualScene() must be use to close the opened tags.
        @param id the id of the visual scene*/
        void openVisualScene ( const String& nodeId = EMPTY_STRING, const String& nodeName = EMPTY_STRING );

        /** Closes the tag opened by openVisualScene()*/
        void closeVisualScene();

    private:
        TagCloser mCurrentVisualSceneCloser;  //!< Used to close the current visual scene
    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_VISUAL_SCENES_H__
