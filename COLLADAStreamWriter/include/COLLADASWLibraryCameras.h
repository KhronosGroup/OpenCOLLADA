/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_CAMERAS_H__
#define __COLLADASTREAMWRITER_LIBRARY_CAMERAS_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWCamera.h"

namespace COLLADASW
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

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_CAMERAS_H__
