/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "dae23dsStableHeaders.h"
#include "DAE23dsMaterialsBase.h"


namespace DAE23ds
{

    //------------------------------
	MaterialsBase::MaterialsBase( Writer* writer3ds )
		: BaseWriter( writer3ds )
		, mUniqueIdFWMaterialMap(getUniqueIdFWMaterialMap())
//		, mUniqueIdFWImageMap(getUniqueIdFWImageMap())
		, mUniqueIdFWEffectMap(getUniqueIdFWEffectMap())
	{

	}

    //------------------------------
	MaterialsBase::~MaterialsBase()
	{
	}

	//------------------------------
	const COLLADAFW::EffectCommon* MaterialsBase::getEffectCommon( const COLLADAFW::Material* material)
	{
		const COLLADAFW::UniqueId& effectUniqueId = material->getInstantiatedEffect();
		const COLLADAFW::Effect* effect = getFWEffectByUniqueId(effectUniqueId);
		const COLLADAFW::CommonEffectPointerArray& commonEffects = effect->getCommonEffects();

		if ( commonEffects.getCount() == 0 )
		{
			return 0;
		}
		else
		{
			return commonEffects[0];
		}
	}

	//------------------------------
	ChunkLength MaterialsBase::calculateMaterialColorLength( const COLLADAFW::Material* material)
	{
		ChunkLength length = 0;

		const COLLADAFW::EffectCommon* effectCommon = getEffectCommon(material);
		assert(effectCommon);

		if ( effectCommon->getAmbient().isColor() )
		{
			length += COLOR_CHUNK_LENGTH_RGB_BYTE;
		}

		if ( effectCommon->getDiffuse().isColor() )
		{
			length += COLOR_CHUNK_LENGTH_RGB_BYTE;
		}

		if ( effectCommon->getSpecular().isColor() )
		{
			length += COLOR_CHUNK_LENGTH_RGB_BYTE;
		}

		return length; 
	}

	//------------------------------
	ChunkLength MaterialsBase::calculateMaterialBlockLength( const COLLADAFW::Material* material)
	{
		ChunkLength length = 0;

		// empty chunk length of the material block
		// plus empty chunk length of the name
		length += 2 * EMPTY_CHUNK_LENGTH;

		// add length required for the color chunks

		length += calculateMaterialColorLength( material );

		length += Writer::getMaterialNameLength();
		return length;
	}


} // namespace DAE23ds
