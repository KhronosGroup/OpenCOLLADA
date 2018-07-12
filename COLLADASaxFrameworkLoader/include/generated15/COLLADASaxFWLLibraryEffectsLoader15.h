/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYEFFECTSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYEFFECTSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryEffectsLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryEffectsLoader15 : public IParserImpl15
{
private:
LibraryEffectsLoader* mLoader;

public:
LibraryEffectsLoader15(LibraryEffectsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_effects();

virtual bool begin__effect( const COLLADASaxFWL15::effect__AttributeData& attributeData );

virtual bool end__effect();

virtual bool begin__profile_COMMON( const COLLADASaxFWL15::profile_COMMON__AttributeData& attributeData );

virtual bool end__profile_COMMON();

virtual bool begin__newparam____fx_newparam_type( const COLLADASaxFWL15::newparam____fx_newparam_type__AttributeData& attributeData );

virtual bool begin__newparam____fx_common_newparam_type( const COLLADASaxFWL15::newparam____fx_common_newparam_type__AttributeData& attributeData );

virtual bool end__newparam____fx_common_newparam_type();

virtual bool begin__instance_image( const COLLADASaxFWL15::instance_image__AttributeData& attributeData );

virtual bool end__instance_image();

virtual bool begin__sampler2D____fx_sampler2D_type();

virtual bool end__sampler2D____fx_sampler2D_type();

virtual bool begin__param____NCName();

virtual bool end__param____NCName();

virtual bool data__param____NCName( const ParserChar* data, size_t length );

virtual bool begin__wrap_s____fx_sampler_wrap_enum();

virtual bool end__wrap_s____fx_sampler_wrap_enum();

virtual bool data__wrap_s____fx_sampler_wrap_enum( const COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum value );

virtual bool begin__wrap_t____fx_sampler_wrap_enum();

virtual bool end__wrap_t____fx_sampler_wrap_enum();

virtual bool data__wrap_t____fx_sampler_wrap_enum( const COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum value );

virtual bool begin__profile_common_type____technique( const COLLADASaxFWL15::profile_common_type____technique__AttributeData& attributeData );

virtual bool end__profile_common_type____technique();

virtual bool begin__profile_COMMON__technique__constant();

virtual bool end__profile_COMMON__technique__constant();

virtual bool begin__lambert();

virtual bool end__lambert();

virtual bool begin__phong();

virtual bool end__phong();

virtual bool begin__emission();

virtual bool end__emission();

virtual bool begin__ambient____fx_common_color_or_texture_type();

virtual bool end__ambient____fx_common_color_or_texture_type();

virtual bool begin__diffuse();

virtual bool end__diffuse();

virtual bool begin__specular();

virtual bool end__specular();

virtual bool begin__shininess();

virtual bool end__shininess();

virtual bool begin__reflective();

virtual bool end__reflective();

virtual bool begin__reflectivity();

virtual bool end__reflectivity();

virtual bool begin__transparency();

virtual bool end__transparency ();

virtual bool begin__index_of_refraction();

virtual bool end__index_of_refraction();

virtual bool begin__blinn();

virtual bool end__blinn();

virtual bool begin__transparent( const COLLADASaxFWL15::transparent__AttributeData& attributeData );

virtual bool end__transparent();

virtual bool begin__fx_common_color_or_texture_type____color( const COLLADASaxFWL15::fx_common_color_or_texture_type____color__AttributeData& attributeData );

virtual bool end__fx_common_color_or_texture_type____color();

virtual bool data__fx_common_color_or_texture_type____color( const float* data, size_t length );

virtual bool begin__fx_common_float_or_param_type____float( const COLLADASaxFWL15::fx_common_float_or_param_type____float__AttributeData& attributeData );

virtual bool end__fx_common_float_or_param_type____float();

virtual bool data__fx_common_float_or_param_type____float( float value );

virtual bool begin__texture( const COLLADASaxFWL15::texture__AttributeData& attributeData );

virtual bool end__texture();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryEffectsLoader15(const LibraryEffectsLoader15&);
/** Disable default assignment operator. */
const LibraryEffectsLoader15& operator=(const LibraryEffectsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYEFFECTSLOADER15_H__
