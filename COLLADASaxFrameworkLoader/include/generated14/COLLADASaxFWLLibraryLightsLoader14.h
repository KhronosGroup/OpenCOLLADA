/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYLIGHTSLOADER14_H__
#define __COLLADASAXFWL_LIBRARYLIGHTSLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryLightsLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryLightsLoader14 : public IParserImpl14
{
private:
LibraryLightsLoader* mLoader;

public:
LibraryLightsLoader14(LibraryLightsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_lights();

virtual bool begin__light( const COLLADASaxFWL14::light__AttributeData& attributeData );

virtual bool end__light();

virtual bool begin__light__technique_common();

virtual bool end__light__technique_common();

virtual bool begin__light__technique_common__ambient();

virtual bool end__light__technique_common__ambient();

virtual bool begin__color____TargetableFloat3( const COLLADASaxFWL14::color____TargetableFloat3__AttributeData& attributeData );

virtual bool end__color____TargetableFloat3();

virtual bool data__color____TargetableFloat3( const float* data, size_t length );

virtual bool begin__directional();

virtual bool end__directional();

virtual bool begin__point();

virtual bool end__point();

virtual bool begin__constant_attenuation( const COLLADASaxFWL14::constant_attenuation__AttributeData& attributeData );

virtual bool end__constant_attenuation();

virtual bool data__constant_attenuation( float value );

virtual bool begin__linear_attenuation( const COLLADASaxFWL14::linear_attenuation__AttributeData& attributeData );

virtual bool end__linear_attenuation();

virtual bool data__linear_attenuation( float value );

virtual bool begin__quadratic_attenuation( const COLLADASaxFWL14::quadratic_attenuation__AttributeData& attributeData );

virtual bool end__quadratic_attenuation();

virtual bool data__quadratic_attenuation( float value );

virtual bool begin__falloff_angle( const COLLADASaxFWL14::falloff_angle__AttributeData& attributeData );

virtual bool end__falloff_angle();

virtual bool data__falloff_angle( float value );

virtual bool begin__falloff_exponent( const COLLADASaxFWL14::falloff_exponent__AttributeData& attributeData );

virtual bool end__falloff_exponent();

virtual bool data__falloff_exponent( float value );

virtual bool begin__spot();

virtual bool end__spot();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryLightsLoader14(const LibraryLightsLoader14&);
/** Disable default assignment operator. */
const LibraryLightsLoader14& operator=(const LibraryLightsLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYLIGHTSLOADER14_H__
