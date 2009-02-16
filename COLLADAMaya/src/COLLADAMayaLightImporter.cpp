/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaLightImporter.h"


namespace COLLADAMaya
{

    //------------------------------
	LightImporter::LightImporter ( DocumentImporter* documentImporter ) 
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	LightImporter::~LightImporter()
	{
	}

    //------------------------------
    void LightImporter::importLight ( const COLLADAFW::Light* camera )
    {

    }

} // namespace COLLADAMaya
