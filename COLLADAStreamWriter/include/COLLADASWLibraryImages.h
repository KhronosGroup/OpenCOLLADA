/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_IMAGES_H__
#define __COLLADASTREAMWRITER_LIBRARY_IMAGES_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWImage.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_images\> and @a \<images\>'s*/
    class LibraryImages : public Library
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_images\> and @a \<images\>'s
        should be written to.
        */
        LibraryImages ( StreamWriter* streamWriter );

        /** Destructor*/
        virtual ~LibraryImages() {}

    protected:

        /** Adds @a \<image\> element. If not already opened, it opens @a \<library_images\>*/
        void addImage ( const Image& image );

    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_IMAGES_H__
