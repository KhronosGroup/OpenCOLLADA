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

#ifndef __COLLADASTREAMWRITER_VISUAL_SCENES_H__
#define __COLLADASTREAMWRITER_VISUAL_SCENES_H__

#include "COLLADAPrerequisites.h"
#include "COLLADALibrary.h"

namespace COLLADA
{

    /** Class to simply the creation of @a \<library_visual_scenes\> and @a \<visual_scene\>'s*/

    class LibraryVisualScenes : public Library
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_visual_scenes\> and @a \<visual_scene\>'s
        should be written to.
        */
        LibraryVisualScenes ( StreamWriter * streamWriter );

        /** Destructor*/
        virtual ~LibraryVisualScenes() {}

    protected:
        /** Writes the opening @a \<visual_scene\> tag and, if necessary the opening @a \<library_visual_scenes\> tag.
        closeVisualScene() must be use to close the opened tags.
        @param id the id of the visual scene*/
        void openVisualScene ( const String & id = EMPTY_STRING );

        /** Closes the tag opened by openVisualScene()*/
        void closeVisualScene();

    private:
        TagCloser mCurrentVisualSceneCloser;  //!< Used to close the current visual scene
    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_VISUAL_SCENES_H__
