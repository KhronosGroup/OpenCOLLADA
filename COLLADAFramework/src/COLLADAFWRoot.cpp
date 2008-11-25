/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWRoot.h"
#include "COLLADAFWILoader.h"

namespace COLLADAFW
{
	
	//--------------------------------------------------------------------
	Root::~Root()
	{
	}

	bool Root::loadDocument( const String& fileName )
	{
		if ( !mLoader || !mWriter )
			return false;
		return mLoader->loadDocument(fileName, mWriter); 
	}

} // namespace COLLADAFW
