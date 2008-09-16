/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAStreamWriter.h"
#include "COLLADALibraryImages.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    LibraryImages::LibraryImages ( COLLADA::StreamWriter* streamWriter )
            : Library ( streamWriter,CSWC::COLLADA_ELEMENT_LIBRARY_IMAGES )
    {}


    //---------------------------------------------------------------
    void LibraryImages::addImage ( const Image& image )
    {
        openLibrary();

        image.add ( mSW );
    }


} //namespace COLLADA
