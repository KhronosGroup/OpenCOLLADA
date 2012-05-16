/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryLights.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    LibraryLights::LibraryLights ( COLLADASW::StreamWriter* streamWriter )
    : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_LIGHTS )
    , BaseExtraTechnique()
    {}


    //---------------------------------------------------------------
    void LibraryLights::addLight ( const Light& light )
    {
        openLibrary();
        light.add();
    }


} //namespace COLLADASW
