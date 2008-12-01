/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADADHStableHeaders.h"
#include "COLLADADHBaseLoader.h"
#include "COLLADADHLoader.h"

namespace COLLADADH
{

    //-----------------------------
	BaseLoader::BaseLoader ( Loader* colladaLoader, domCOLLADA* colladaRoot )
         : mDomCollada ( colladaRoot ),
		   mColladaLoader(colladaLoader)
	{
	}
	
    //-----------------------------
	BaseLoader::~BaseLoader()
	{
	}

    //-----------------------------
    const domCOLLADA* BaseLoader::getDomCollada () const
    {
        return mDomCollada;
    }

    //-----------------------------
    domCOLLADA* BaseLoader::getDomCollada () 
    {
        return mDomCollada;
    }

	const COLLADAFW::UniqueId& BaseLoader::getUniqueId( daeElement* element, COLLADAFW::ClassId classId )
	{
		if ( !getColladaLoader() )
			return COLLADAFW::UniqueId::INVALID;
		
		return getColladaLoader()->getUniqueId(element, classId);
	}
} // namespace COLLADADH
