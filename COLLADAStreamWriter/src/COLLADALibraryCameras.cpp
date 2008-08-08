/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryCameras.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    LibraryCameras::LibraryCameras ( COLLADA::StreamWriter* streamWriter )
    : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_CAMERAS )
    , BaseExtraTechnique()
    {}


    //---------------------------------------------------------------
    void LibraryCameras::addCamera ( const Camera& camera )
    {
        openLibrary();
        camera.add();
    }


} //namespace COLLADA
