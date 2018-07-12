/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYLIGHTSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYLIGHTSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryLightsLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryLightsLoader15 : public IParserImpl15
{
private:
LibraryLightsLoader* mLoader;

public:
LibraryLightsLoader15(LibraryLightsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_lights();

virtual bool begin__light( const COLLADASaxFWL15::light__AttributeData& attributeData );

virtual bool end__light();

virtual bool begin__light_type____technique_common();

virtual bool end__light_type____technique_common();

virtual bool begin__light__technique_common__ambient();

virtual bool end__light__technique_common__ambient();

virtual bool begin__color____targetable_float3_type( const COLLADASaxFWL15::color____targetable_float3_type__AttributeData& attributeData );

virtual bool end__color____targetable_float3_type();

virtual bool data__color____targetable_float3_type( const float* data, size_t length );

virtual bool begin__directional();

virtual bool end__directional();

virtual bool begin__point();

virtual bool end__point();

virtual bool begin__constant_attenuation( const COLLADASaxFWL15::constant_attenuation__AttributeData& attributeData );

virtual bool end__constant_attenuation();

virtual bool data__constant_attenuation( float value );

virtual bool begin__linear_attenuation( const COLLADASaxFWL15::linear_attenuation__AttributeData& attributeData );

virtual bool end__linear_attenuation();

virtual bool data__linear_attenuation( float value );

virtual bool begin__quadratic_attenuation( const COLLADASaxFWL15::quadratic_attenuation__AttributeData& attributeData );

virtual bool end__quadratic_attenuation();

virtual bool data__quadratic_attenuation( float value );

virtual bool begin__falloff_angle( const COLLADASaxFWL15::falloff_angle__AttributeData& attributeData );

virtual bool end__falloff_angle();

virtual bool data__falloff_angle( float value );

virtual bool begin__falloff_exponent( const COLLADASaxFWL15::falloff_exponent__AttributeData& attributeData );

virtual bool end__falloff_exponent();

virtual bool data__falloff_exponent( float value );

virtual bool begin__spot();

virtual bool end__spot();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryLightsLoader15(const LibraryLightsLoader15&);
/** Disable default assignment operator. */
const LibraryLightsLoader15& operator=(const LibraryLightsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYLIGHTSLOADER15_H__
