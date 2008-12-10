/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWGeometricElement.h"


namespace COLLADAFW
{

    //------------------------------
	GeometricElement::GeometricElement ( GeometricType elementType )
        : mType ( elementType )
	{
	}
	
    //------------------------------
	GeometricElement::~GeometricElement()
	{
	}


} // namespace COLLADAFW
