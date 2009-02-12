/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryMaterialsLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWMaterial.h"
#include "COLLADAFWEffect.h"

namespace COLLADASaxFWL
{

    //------------------------------
	LibraryMaterialsLoader::LibraryMaterialsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentMaterial(0)
	{

	}

    //------------------------------
	LibraryMaterialsLoader::~LibraryMaterialsLoader()
	{
	}

    //------------------------------
	bool LibraryMaterialsLoader::begin__material( const material__AttributeData& attributeData )
	{
		mCurrentMaterial = FW_NEW COLLADAFW::Material(getUniqueIdFromId(attributeData.id, COLLADAFW::Material::ID()).getObjectId());
		if ( attributeData.name )
			mCurrentMaterial->setName((const char*)attributeData.name);
        else if ( attributeData.id )
            mCurrentMaterial->setName((const char*)attributeData.id);
		return true;
	}

	//------------------------------
	bool LibraryMaterialsLoader::end__material()
	{
		bool success = writer()->writeMaterial(mCurrentMaterial);
		FW_DELETE mCurrentMaterial;
		mCurrentMaterial = 0;
		return success;
	}

    //------------------------------
	bool LibraryMaterialsLoader::begin__material__instance_effect( const instance_effect__AttributeData& attributeData )
	{
		mCurrentMaterial->setInstantiatedEffect(getUniqueIdFromUrl(attributeData.url, COLLADAFW::Effect::ID()));
		return true;
	}

	//------------------------------
	bool LibraryMaterialsLoader::end__library_materials()
	{
		finish();
		return true;
	}


} // namespace COLLADASaxFWL
