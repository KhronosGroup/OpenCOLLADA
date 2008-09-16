/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_LIBRARY_IMAGES_H__
#define __COLLADASTREAMWRITER_LIBRARY_IMAGES_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADALibrary.h"
#include "COLLADAImage.h"

namespace COLLADA
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

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_IMAGES_H__