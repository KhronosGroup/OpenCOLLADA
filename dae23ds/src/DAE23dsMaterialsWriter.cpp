/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "dae23dsStableHeaders.h"
#include "DAE23dsMaterialsWriter.h"
#include "CommonBuffer.h"


namespace DAE23ds
{

    //------------------------------
	MaterialsWriter::MaterialsWriter( Writer* writer3ds )
		: MaterialsBase( writer3ds )
		, mBuffer(getBuffer())
    {

	}

    //------------------------------
	MaterialsWriter::~MaterialsWriter()
	{
	}

	//------------------------------
	bool MaterialsWriter::writeColorBlock(const COLLADAFW::Color& color, ChunkID chunkId)
	{
		// write color chunk
		mBuffer.copyToBuffer(chunkId);
		mBuffer.copyToBuffer(COLOR_CHUNK_LENGTH_RGB_BYTE);

		//write color chunk rgb byte
		mBuffer.copyToBuffer(COL_TRU);
		mBuffer.copyToBuffer(CHUNK_RGB_BYTE_LENGTH);

		// we need to round
		unsigned char red = (unsigned char)(color.getRed()*255.0 + 0.5);
		unsigned char green = (unsigned char)(color.getGreen()*255.0 + 0.5);
		unsigned char blue = (unsigned char)(color.getBlue()*255.0 + 0.5);

		mBuffer.copyToBuffer(red);
		mBuffer.copyToBuffer(green);
		mBuffer.copyToBuffer(blue);
		return true;
	}


	//------------------------------
	bool MaterialsWriter::write()
	{
		Writer::UniqueIdFWMaterialMap::const_iterator it = mUniqueIdFWMaterialMap.begin();
		for ( ; it != mUniqueIdFWMaterialMap.end(); ++it )
		{
			const COLLADAFW::Material* material = &it->second;

			MaterialNumber materialNumber = getAndIncreaseNextMaterialNumber();
			addUniqueIdMaterialNumberPair( material->getUniqueId(), materialNumber);
			const char* materialName = Writer::calculateMaterialNameFromMaterialNumer( materialNumber );

			//empty chunk length
			ChunkLength materialNameChunkLength = EMPTY_CHUNK_LENGTH;
			materialNameChunkLength += Writer::getMaterialNameLength();

			ChunkLength materialBlockLength = 0;

			// material block empty chunk
			materialBlockLength += EMPTY_CHUNK_LENGTH;

			// the name chunk
			materialBlockLength += materialNameChunkLength;

			//all the color chunks
			materialBlockLength += calculateMaterialColorLength(material);

			// write material block
			mBuffer.copyToBuffer(EDIT_MATERIAL);
			mBuffer.copyToBuffer(materialBlockLength);

			// write name
			mBuffer.copyToBuffer(MATERIAL_NAME);
			mBuffer.copyToBuffer(materialNameChunkLength);
			mBuffer.copyToBuffer(materialName, Writer::getMaterialNameLength());

			const COLLADAFW::EffectCommon* effectCommon = getEffectCommon(material);
			assert(effectCommon);

			if ( effectCommon->getAmbient().isColor() )
			{
				writeColorBlock(effectCommon->getAmbient().getColor(), MATERIAL_AMBIENT_COLOR);
			}

			if ( effectCommon->getDiffuse().isColor() )
			{
				writeColorBlock(effectCommon->getDiffuse().getColor(), MATERIAL_DIFFUSE_COLOR);
			}

			if ( effectCommon->getSpecular().isColor() )
			{
				writeColorBlock(effectCommon->getSpecular().getColor(), MATERIAL_SPECULAR_COLOR);
			}

		}
		return true;
	}
} // namespace DAE23ds
