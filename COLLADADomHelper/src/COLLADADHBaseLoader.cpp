/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADADHStableHeaders.h"
#include "COLLADADHBaseLoader.h"


namespace COLLADADH
{

    //-----------------------------
	BaseLoader::BaseLoader ( daeDocument* daeDoc )
         : mDaeDocument ( daeDoc )
	{
	}
	
    //-----------------------------
	BaseLoader::~BaseLoader()
	{
	}

    //-----------------------------
    const daeDocument* BaseLoader::getDaeDocument () const
    {
        return mDaeDocument;
    }

    //-----------------------------
    daeDocument* BaseLoader::getDaeDocument () 
    {
        return mDaeDocument;
    }

} // namespace COLLADADH
