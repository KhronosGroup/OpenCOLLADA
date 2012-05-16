/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxExtraDataHandler.h"
#include "generated14/COLLADASaxFWLColladaParserAutoGen14Attributes.h"

#include "GeneratedSaxParserUtils.h"


namespace COLLADAMax
{

	static const char* MAX_EXTRA_ATTRIBUTE_SKYLIGHT = "skylight";
	static const char* MAX_EXTRA_ATTRIBUTE_CAST_SHADOWS = "cast_shadows";
	static const char* MAX_EXTRA_ATTRIBUTE_COLOR_MAP_AMOUNT = "color_map_amount";
	static const char* MAX_EXTRA_ATTRIBUTE_COLOR_MAP_ON = "color_map_on";
	static const char* MAX_EXTRA_ATTRIBUTE_INTENSITY_ON = "intensity_on";
	static const char* MAX_EXTRA_ATTRIBUTE_MODE = "mode";
	static const char* MAX_EXTRA_ATTRIBUTE_MULTIPLIER = "multiplier";
	static const char* MAX_EXTRA_ATTRIBUTE_RAY_BIAS = "ray_bias";
	static const char* MAX_EXTRA_ATTRIBUTE_RAYS_PER_SAMPLE = "rays_per_sample";



	//------------------------------
	ExtraDataHandler::ExtraDataHandler(DocumentImporter* colladaImporter)
		: ImporterBase(colladaImporter)
		, mTextBuffer()
		, mExtraTagType(EXTRA_TAG_TYPE_UNKNOWN)
		, mCurrentElementUniqueId()
	{

	}

	//------------------------------
	ExtraDataHandler::~ExtraDataHandler()
	{

	}


	//------------------------------
	bool ExtraDataHandler::elementBegin( const COLLADASaxFWL::ParserChar* elementName, const GeneratedSaxParser::xmlChar** attributes )
	{

		switch ( mExtraTagType )
		{
		case EXTRA_TAG_TYPE_UNKNOWN:
			{
				if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_SKYLIGHT) == 0 )
				{
					mExtraTagType = EXTRA_TAG_TYPE_SKYLIGHT;
					mExtraParameters.skyLightParameters.castShadows = false;
					mExtraParameters.skyLightParameters.colorMapAmount = 100;
					mExtraParameters.skyLightParameters.colorMapOn = true;
					mExtraParameters.skyLightParameters.intensityOn = true;
					mExtraParameters.skyLightParameters.mode = 1.0f;
					mExtraParameters.skyLightParameters.multiplier = 1.0f;
					mExtraParameters.skyLightParameters.rayBias = 0.004999995f;
					mExtraParameters.skyLightParameters.raysPerSample = 20;
				}
			}
			break;
		}
		return true;
	}

	//------------------------------
	bool ExtraDataHandler::elementEnd( const COLLADASaxFWL::ParserChar* elementName )
	{
		bool failed = false;
		switch ( mExtraTagType )
		{
		case EXTRA_TAG_TYPE_SKYLIGHT:
			{
				if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_SKYLIGHT) == 0 )
				{
					mExtraTagType = EXTRA_TAG_TYPE_UNKNOWN;
					addUniqueIdSkyLightParametersPair(mCurrentElementUniqueId, mExtraParameters.skyLightParameters);
				} 
				else if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_CAST_SHADOWS) == 0 )
				{
					bool val = GeneratedSaxParser::Utils::toBool(mTextBuffer.c_str(), failed);
					if ( !failed )
					{
						mExtraParameters.skyLightParameters.castShadows = val;
					}
				}
				else if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_COLOR_MAP_AMOUNT) == 0 )
				{
					float val = GeneratedSaxParser::Utils::toFloat(mTextBuffer.c_str(), failed);
					if ( !failed )
					{
						mExtraParameters.skyLightParameters.colorMapAmount = val;
					}
				}
				else if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_COLOR_MAP_ON) == 0 )
				{
					bool val = GeneratedSaxParser::Utils::toBool(mTextBuffer.c_str(), failed);
					if ( !failed )
					{
						mExtraParameters.skyLightParameters.colorMapOn = val;
					}
				}
				else if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_INTENSITY_ON) == 0 )
				{
					bool val = GeneratedSaxParser::Utils::toBool(mTextBuffer.c_str(), failed);
					if ( !failed )
					{
						mExtraParameters.skyLightParameters.castShadows = val;
					}
				}
				else if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_MODE) == 0 )
				{
					float val = GeneratedSaxParser::Utils::toFloat(mTextBuffer.c_str(), failed);
					if ( !failed )
					{
						mExtraParameters.skyLightParameters.mode = val;
					}
				}
				else if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_MULTIPLIER) == 0 )
				{
					float val = GeneratedSaxParser::Utils::toFloat(mTextBuffer.c_str(), failed);
					if ( !failed )
					{
						mExtraParameters.skyLightParameters.multiplier = val;
					}
				}
				else if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_RAY_BIAS) == 0 )
				{
					float val = GeneratedSaxParser::Utils::toFloat(mTextBuffer.c_str(), failed);
					if ( !failed )
					{
						mExtraParameters.skyLightParameters.rayBias = val;
					}
				}
				else if ( strcmp(elementName, MAX_EXTRA_ATTRIBUTE_RAYS_PER_SAMPLE) == 0 )
				{
					int val = GeneratedSaxParser::Utils::toSint32(mTextBuffer.c_str(), failed);
					if ( !failed )
					{
						mExtraParameters.skyLightParameters.raysPerSample = val;
					}
				}
			}
			break;
		}

		mTextBuffer.clear();
		return true;
	}

	//------------------------------
	bool ExtraDataHandler::textData( const COLLADASaxFWL::ParserChar* text, size_t textLength )
	{
		mTextBuffer.append(text, textLength);
		return true;
	}

	//------------------------------
	bool ExtraDataHandler::parseElement( const COLLADASaxFWL::ParserChar* profileName, const COLLADASaxFWL::StringHash& elementHash, const COLLADAFW::UniqueId& uniqueId )
	{
		mCurrentElementUniqueId = uniqueId;

		switch ( elementHash )
		{
		case COLLADASaxFWL14::HASH_ELEMENT_LIGHT:
			if ( strcmp(profileName, "OpenCOLLADA3dsMax") == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		default:
			return false;
		}
	}

}
