/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryJointsLoader.h"

namespace COLLADASaxFWL
{

    //------------------------------
	LibraryJointsLoader::LibraryJointsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
	{
		mJointsLoader.setHandlingFilePartLoader(this);
	}

    //------------------------------
	LibraryJointsLoader::~LibraryJointsLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& LibraryJointsLoader::getUniqueId ()
    {
        return mJointsLoader.getUniqueId ();
    }

    //------------------------------
	bool LibraryJointsLoader::end__library_joints()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

} // namespace COLLADASaxFWL
