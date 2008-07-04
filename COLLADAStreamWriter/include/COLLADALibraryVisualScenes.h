/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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
