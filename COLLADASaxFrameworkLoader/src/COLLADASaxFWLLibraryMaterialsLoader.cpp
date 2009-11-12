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
#include "COLLADAFWExtraKeys.h"


namespace COLLADASaxFWL
{

    //------------------------------
	LibraryMaterialsLoader::LibraryMaterialsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentMaterial(0)
        , mInInstanceEffect (false)
	{

	}

    //------------------------------
	LibraryMaterialsLoader::~LibraryMaterialsLoader()
	{
	}

    //------------------------------
	bool LibraryMaterialsLoader::begin__material( const material__AttributeData& attributeData )
	{
		mCurrentMaterial = FW_NEW COLLADAFW::Material(getUniqueIdFromId(attributeData.id, COLLADAFW::Material::ID()));
		
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
        mInInstanceEffect = true;
		mCurrentMaterial->setInstantiatedEffect(getUniqueIdFromUrl(attributeData.url, COLLADAFW::Effect::ID()));
		return true;
	}

    //------------------------------
    bool LibraryMaterialsLoader::end__instance_effect ()
    {
        mInInstanceEffect = false;
        return true;
    }

	//------------------------------
	bool LibraryMaterialsLoader::end__library_materials()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

    //------------------------------
    const char* LibraryMaterialsLoader::getSecondKey ()
    {
        if ( mInInstanceEffect )
            return COLLADAFW::ExtraKeys::INSTANCE_EFFECT;
        else 
            return COLLADAFW::ExtraKeys::MATERIAL;
        return 0;
    }

    //------------------------------
    COLLADAFW::ExtraData* LibraryMaterialsLoader::getExtraData ()
    {
        return mCurrentMaterial;
    }

} // namespace COLLADASaxFWL
