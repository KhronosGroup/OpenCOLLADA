/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYEFFECTSLOADER14_H__
#define __COLLADASAXFWL_LIBRARYEFFECTSLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryEffectsLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryEffectsLoader14 : public IParserImpl14
{
private:
LibraryEffectsLoader* mLoader;

public:
LibraryEffectsLoader14(LibraryEffectsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_effects();

virtual bool begin__effect( const COLLADASaxFWL14::effect__AttributeData& attributeData );

virtual bool end__effect();

virtual bool begin__profile_COMMON( const COLLADASaxFWL14::profile_COMMON__AttributeData& attributeData );

virtual bool end__profile_COMMON();

virtual bool begin__newparam____fx_newparam_common( const COLLADASaxFWL14::newparam____fx_newparam_common__AttributeData& attributeData );

virtual bool begin__newparam____common_newparam_type( const COLLADASaxFWL14::newparam____common_newparam_type__AttributeData& attributeData );

virtual bool end__newparam____common_newparam_type();

virtual bool begin__newparam____cg_newparam( const COLLADASaxFWL14::newparam____cg_newparam__AttributeData& attributeData );

virtual bool begin__surface____fx_surface_common( const COLLADASaxFWL14::surface____fx_surface_common__AttributeData& attributeData );

virtual bool end__surface____fx_surface_common();

virtual bool begin__init_from____fx_surface_init_from_common( const COLLADASaxFWL14::init_from____fx_surface_init_from_common__AttributeData& attributeData );

virtual bool end__init_from____fx_surface_init_from_common();

virtual bool data__init_from____fx_surface_init_from_common( const ParserChar* data, size_t length );

virtual bool begin__sampler2D____fx_sampler2D_common();

virtual bool end__sampler2D____fx_sampler2D_common();

virtual bool begin__source____NCName();

virtual bool end__source____NCName();

virtual bool data__source____NCName( const ParserChar* data, size_t length );

virtual bool begin__wrap_s____fx_sampler_wrap_common();

virtual bool end__wrap_s____fx_sampler_wrap_common();

virtual bool data__wrap_s____fx_sampler_wrap_common( const COLLADASaxFWL14::ENUM__fx_sampler_wrap_common value );

virtual bool begin__wrap_t____fx_sampler_wrap_common();

virtual bool end__wrap_t____fx_sampler_wrap_common();

virtual bool data__wrap_t____fx_sampler_wrap_common( const COLLADASaxFWL14::ENUM__fx_sampler_wrap_common value );

virtual bool begin__profile_COMMON__technique( const COLLADASaxFWL14::profile_COMMON__technique__AttributeData& attributeData );

virtual bool end__profile_COMMON__technique();

virtual bool begin__profile_COMMON__technique__constant();

virtual bool end__profile_COMMON__technique__constant();

virtual bool begin__lambert();

virtual bool end__lambert();

virtual bool begin__phong();

virtual bool end__phong();

virtual bool begin__emission();

virtual bool end__emission();

virtual bool begin__ambient____common_color_or_texture_type();

virtual bool end__ambient____common_color_or_texture_type();

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

virtual bool end__transparency();

virtual bool begin__index_of_refraction();

virtual bool end__index_of_refraction();

virtual bool begin__blinn();

virtual bool end__blinn();

virtual bool begin__transparent( const COLLADASaxFWL14::transparent__AttributeData& attributeData );

virtual bool end__transparent();

virtual bool begin__common_color_or_texture_type____color( const COLLADASaxFWL14::common_color_or_texture_type____color__AttributeData& attributeData );

virtual bool end__common_color_or_texture_type____color();

virtual bool data__common_color_or_texture_type____color( const float* data, size_t length );

virtual bool begin__common_float_or_param_type____float( const COLLADASaxFWL14::common_float_or_param_type____float__AttributeData& attributeData );

virtual bool end__common_float_or_param_type____float();

virtual bool data__common_float_or_param_type____float( float value );

virtual bool begin__texture( const COLLADASaxFWL14::texture__AttributeData& attributeData );

virtual bool end__texture();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryEffectsLoader14(const LibraryEffectsLoader14&);
/** Disable default assignment operator. */
const LibraryEffectsLoader14& operator=(const LibraryEffectsLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYEFFECTSLOADER14_H__
