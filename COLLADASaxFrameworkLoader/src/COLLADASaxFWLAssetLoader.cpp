/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLAssetLoader.h"


namespace COLLADASaxFWL
{

    //------------------------------
    AssetLoader::AssetLoader ( IFilePartLoader* callingFilePartLoader ) 
        : FilePartLoader ( callingFilePartLoader )
        , mAsset ( new COLLADAFW::FileInfo () )
	{
	}
	
    //------------------------------
	AssetLoader::~AssetLoader()
	{
	}

} // namespace COLLADASaxFWL
