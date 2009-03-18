/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryLightsLoader.h"

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
	bool LibraryLightsLoader::dataColor( const float* data, size_t length )
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
	bool LibraryLightsLoader::endColor( )
	{
		// set alpha to a valid value, although it is not used by lights
		mCurrentLight->getColor().setAlpha(1);
		mCurrentColorValueIndex = 0;
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::end__library_lights()
	{
		SaxVirtualFunctionTest(end__library_lights());
		finish();
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__light( const light__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__light(attributeData));
		mCurrentLight = FW_NEW COLLADAFW::Light( getUniqueIdFromId( attributeData.id, COLLADAFW::Light::ID()).getObjectId() );

		if ( attributeData.name )
			mCurrentLight->setName( (const char*) attributeData.name );
		else if ( attributeData.id )
			mCurrentLight->setName( (const char*) attributeData.id );

		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::end__light()
	{
		SaxVirtualFunctionTest(end__light());
		bool success = writer()->writeLight(mCurrentLight);
		FW_DELETE mCurrentLight;
		mCurrentLight = 0;
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__light__technique_common__ambient()
	{
		SaxVirtualFunctionTest(begin__light__technique_common__ambient());
		mCurrentLight->setLightType(COLLADAFW::Light::AMBIENT_LIGHT);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::end__color____TargetableFloat3()
	{
		SaxVirtualFunctionTest(end__color____TargetableFloat3());
		return endColor();
	}

	//------------------------------
	bool LibraryLightsLoader::data__color____TargetableFloat3( const float* data, size_t length )
	{
		SaxVirtualFunctionTest(data__color____TargetableFloat3(data, length));
		return dataColor(data, length);
	}

	//------------------------------
	bool LibraryLightsLoader::begin__directional()
	{
		SaxVirtualFunctionTest(begin__directional());
		mCurrentLight->setLightType(COLLADAFW::Light::DIRECTIONAL_LIGHT);
		return true;
	}

#if 0
	//------------------------------
	bool LibraryLightsLoader::end__directional__color()
	{
		return endColor();
	}

	//------------------------------
	bool LibraryLightsLoader::data__directional__color( const double* data, size_t length )
	{
		return dataColor(data, length);
	}
#endif

	//------------------------------
	bool LibraryLightsLoader::begin__point()
	{
		SaxVirtualFunctionTest(begin__point());
		mCurrentLight->setLightType(COLLADAFW::Light::POINT_LIGHT);
		return true;
	}

#if 0
	//------------------------------
	bool LibraryLightsLoader::end__point__color()
	{
		return endColor();
	}

	//------------------------------
	bool LibraryLightsLoader::data__point__color( const double* data, size_t length )
	{
		return dataColor(data, length);
	}
#endif
	//------------------------------
	bool LibraryLightsLoader::data__constant_attenuation( float value )
	{
		SaxVirtualFunctionTest(data__constant_attenuation(value));
		mCurrentLight->setConstantAttenuation(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__linear_attenuation( float value )
	{
		SaxVirtualFunctionTest(data__linear_attenuation(value));
		mCurrentLight->setLinearAttenuation(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__quadratic_attenuation( float value )
	{
		SaxVirtualFunctionTest(data__quadratic_attenuation(value));
		mCurrentLight->setQuadraticAttenuation(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::begin__spot()
	{
		SaxVirtualFunctionTest(begin__spot());
		mCurrentLight->setLightType(COLLADAFW::Light::SPOT_LIGHT);
		return true;
	}
	
#if 0
	//------------------------------
	bool LibraryLightsLoader::end__spot__color()
	{
		return endColor();
	}

	//------------------------------
	bool LibraryLightsLoader::data__spot__color( const double* data, size_t length )
	{
		return dataColor(data, length);
	}
#endif

#if 0
	//------------------------------
	bool LibraryLightsLoader::data__spot__constant_attenuation( double value )
	{
		mCurrentLight->setConstantAttenuation(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__spot__linear_attenuation( double value )
	{
		mCurrentLight->setLinearAttenuation(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__spot__quadratic_attenuation( double value )
	{
		mCurrentLight->setQuadraticAttenuation(value);
		return true;
	}
#endif
	//------------------------------
	bool LibraryLightsLoader::data__falloff_angle( float value )
	{
		SaxVirtualFunctionTest(data__falloff_angle(value));
		mCurrentLight->setFallOffAngle(value);
		return true;
	}

	//------------------------------
	bool LibraryLightsLoader::data__falloff_exponent( float value )
	{
		SaxVirtualFunctionTest(data__falloff_exponent(value));
		mCurrentLight->setFallOffExponent(value);
		return true;
	}
} // namespace COLLADASaxFWL
