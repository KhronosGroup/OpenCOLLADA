/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryImages.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    LibraryImages::LibraryImages ( COLLADASW::StreamWriter* streamWriter )
            : Library ( streamWriter,CSWC::CSW_ELEMENT_LIBRARY_IMAGES )
    {}


    //---------------------------------------------------------------
    void LibraryImages::addImage ( const Image& image )
    {
        openLibrary();

        image.add ( mSW );
    }


} //namespace COLLADASW
