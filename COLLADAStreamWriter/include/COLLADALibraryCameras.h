/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_CAMERAS_H__
#define __COLLADASTREAMWRITER_LIBRARY_CAMERAS_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADALibrary.h"
#include "COLLADACamera.h"

namespace COLLADA
{

    /** Class to simply the creation of @a \<library_cameras\> and @a \<cameras\>'s*/
    class LibraryCameras : public Library, public BaseExtraTechnique
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_cameras\> and @a \<cameras\>'s
        should be written to.
        */
        LibraryCameras ( StreamWriter* streamWriter );

        /** Destructor*/
        virtual ~LibraryCameras() {}

    protected:

        /** Adds @a \<camera\> element. If not already opened, it opens @a \<library_cameras\>*/
        void addCamera ( const Camera& camera );

    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_CAMERAS_H__