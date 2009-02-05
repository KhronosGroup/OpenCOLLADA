/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryEffectsLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWEffect.h"

namespace COLLADASaxFWL
{

    //------------------------------
	LibraryEffectsLoader::LibraryEffectsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentEffect(0)
		, mCurrentProfile(PROFILE_UNKNOWN)

	{
	}
	
    //------------------------------
	LibraryEffectsLoader::~LibraryEffectsLoader()
	{
	}


	//------------------------------
	bool LibraryEffectsLoader::begin__effect( const effect__AttributeData& attributeData )
	{
		mCurrentEffect = FW_NEW COLLADAFW::Effect(getUniqueIdFromId(attributeData.id, COLLADAFW::Effect::ID()).getObjectId());
		if ( attributeData.name )
			mCurrentEffect->setName((const char*)attributeData.name);
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__effect()
	{
		bool success = writer()->writeEffect(mCurrentEffect);
		FW_DELETE mCurrentEffect;
		mCurrentEffect = 0;
		return success;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__library_effects()
	{
		finish();
		return true;
	}

} // namespace COLLADASaxFWL
