/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryMaterialsLoader.h"
#include "COLLADASaxFWLLoader.h"

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
		SaxVirtualFunctionTest(begin__material(attributeData)); 
		mCurrentMaterial = FW_NEW COLLADAFW::Material(getUniqueIdFromId(attributeData.id, COLLADAFW::Material::ID()).getObjectId());
		
        if ( attributeData.name )
			mCurrentMaterial->setName ( (const char*)attributeData.name );
        else if ( attributeData.id )
            mCurrentMaterial->setName ( (const char*)attributeData.id );
		
        if ( attributeData.id )
            mCurrentMaterial->setOriginalId ( (const char*)attributeData.id );

        return true;
	}

	//------------------------------
	bool LibraryMaterialsLoader::end__material()
	{
		SaxVirtualFunctionTest(end__material()); 
		bool success = true;
		if ( (getObjectFlags() & Loader::MATERIAL_FLAG) != 0 )
		{
			success = writer()->writeMaterial(mCurrentMaterial);
		}

		FW_DELETE mCurrentMaterial;
		mCurrentMaterial = 0;
		return success;
	}

    //------------------------------
	bool LibraryMaterialsLoader::begin__instance_effect( const instance_effect__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__instance_effect(attributeData)); 
		mCurrentMaterial->setInstantiatedEffect(getUniqueIdFromUrl(attributeData.url, COLLADAFW::Effect::ID()));
		return true;
	}

	//------------------------------
	bool LibraryMaterialsLoader::end__library_materials()
	{
		SaxVirtualFunctionTest(end__library_materials()); 
		finish();
		return true;
	}


} // namespace COLLADASaxFWL
