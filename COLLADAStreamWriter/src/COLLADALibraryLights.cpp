/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryLights.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    LibraryLights::LibraryLights ( COLLADA::StreamWriter* streamWriter )
    : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_LIGHTS )
    , BaseExtraTechnique()
    {}


    //---------------------------------------------------------------
    void LibraryLights::addLight ( const Light& light )
    {
        openLibrary();
        light.add();
    }


} //namespace COLLADA
