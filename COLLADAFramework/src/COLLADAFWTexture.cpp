/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWTexture.h"


namespace COLLADAFW
{

    //------------------------------
    Texture::Texture ( const UniqueId& uniqueId )
        : ObjectTemplate<COLLADA_TYPE::TEXTURE>(uniqueId)
    {
    }

    //------------------------------
	Texture::~Texture()
	{
	}

} // namespace COLLADAFW
