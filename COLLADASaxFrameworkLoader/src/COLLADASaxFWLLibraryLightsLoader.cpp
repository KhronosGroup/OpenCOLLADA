/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryLightsLoader.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWLight.h"
#include "COLLADAFWColor.h"


namespace COLLADASaxFWL
{

    //------------------------------
	LibraryLightsLoader::LibraryLightsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentColorValueIndex(0)
	{
	}

    //------------------------------
	LibraryLightsLoader::~LibraryLightsLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& LibraryLightsLoader::getUniqueId ()
    {
        if ( mCurrentLight )
            return mCurrentLight->getUniqueId ();
        return COLLADAFW::UniqueId::INVALID;
    }

    //------------------------------
	bool LibraryLightsLoader::end__library_lights()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__light( const light__AttributeData& attributeData )
	{
		mCurrentLight = FW_NEW COLLADAFW::Light( createUniqueIdFromId( attributeData.id, COLLADAFW::Light::ID()));

		if ( attributeData.name )
			mCurrentLight->setName( (const char*) attributeData.name );
		else if ( attributeData.id )
			mCurrentLight->setName( (const char*) attributeData.id );

        if ( attributeData.id )
            mCurrentLight->setOriginalId ( (const char*)attributeData.id );

		addToSidTree( attributeData.id, 0);

		return true;	
	}

	//------------------------------
	bool LibraryLightsLoader::end__light()
	{
		moveUpInSidTree();
		if ( (getObjectFlags() & Loader::LIGHT_FLAG) != 0 )
		{
			getFileLoader()->addLight( mCurrentLight );
		}
		mCurrentLight = 0;
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__light__technique_common__ambient()
	{
		mCurrentLight->setLightType(COLLADAFW::Light::AMBIENT_LIGHT);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__color____TargetableFloat3( const color____TargetableFloat3__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentLight->getColor());
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::end__color____TargetableFloat3()
	{
		// set alpha to a valid value, although it is not used by lights
		mCurrentLight->getColor().setAlpha(1);
		mCurrentColorValueIndex = 0;
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__color____TargetableFloat3( const float* data, size_t length )
	{
		COLLADAFW::Color& color = mCurrentLight->getColor();
		for ( size_t i = 0; i < length; ++i)
		{
			switch ( mCurrentColorValueIndex )
			{
			case 0:
				color.setRed(data[i]);
				break;
			case 1:
				color.setGreen(data[i]);
				break;
			case 2:
				color.setBlue(data[i]);
				break;
			}
			mCurrentColorValueIndex++;
		}
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__directional()
	{
		mCurrentLight->setLightType(COLLADAFW::Light::DIRECTIONAL_LIGHT);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__point()
	{
		mCurrentLight->setLightType(COLLADAFW::Light::POINT_LIGHT);
		return true;
	}

	bool LibraryLightsLoader::begin__constant_attenuation( const constant_attenuation__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentLight->getConstantAttenuation());
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__constant_attenuation( float value )
	{
		mCurrentLight->setConstantAttenuation(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::end__constant_attenuation()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__linear_attenuation( const linear_attenuation__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentLight->getLinearAttenuation());
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__linear_attenuation( float value )
	{
		mCurrentLight->setLinearAttenuation(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::end__linear_attenuation()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__quadratic_attenuation( const quadratic_attenuation__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentLight->getQuadraticAttenuation());
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__quadratic_attenuation( float value )
	{
		mCurrentLight->setQuadraticAttenuation(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::end__quadratic_attenuation()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__spot()
	{
		mCurrentLight->setLightType(COLLADAFW::Light::SPOT_LIGHT);
		return true;
	}
	
	//------------------------------
	bool LibraryLightsLoader::begin__falloff_angle( const falloff_angle__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentLight->getFallOffAngle());
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__falloff_angle( float value )
	{
		mCurrentLight->setFallOffAngle(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::end__falloff_angle()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__falloff_exponent( const falloff_exponent__AttributeData& attributeData )
	{
		addToSidTree( 0, attributeData.sid, &mCurrentLight->getFallOffExponent());
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__falloff_exponent( float value )
	{
		mCurrentLight->setFallOffExponent(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::end__falloff_exponent()
	{
		moveUpInSidTree();
		return true;
	}

} // namespace COLLADASaxFWL
