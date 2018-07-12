/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryEffectsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryEffectsLoader15::end__library_effects()
{
SaxVirtualFunctionTest15(end__library_effects());
return mLoader->end__library_effects();
}


bool LibraryEffectsLoader15::begin__effect( const COLLADASaxFWL15::effect__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__effect(attributeData));
COLLADASaxFWL::effect__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__effect(attrData);
}


bool LibraryEffectsLoader15::end__effect()
{
SaxVirtualFunctionTest15(end__effect());
return mLoader->end__effect();
}


bool LibraryEffectsLoader15::begin__profile_COMMON( const COLLADASaxFWL15::profile_COMMON__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__profile_COMMON(attributeData));
COLLADASaxFWL::profile_COMMON__AttributeData attrData;
attrData.id = attributeData.id;
return mLoader->begin__profile_COMMON(attrData);
}


bool LibraryEffectsLoader15::end__profile_COMMON()
{
SaxVirtualFunctionTest15(end__profile_COMMON());
return mLoader->end__profile_COMMON();
}


bool LibraryEffectsLoader15::begin__newparam____fx_newparam_type( const COLLADASaxFWL15::newparam____fx_newparam_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__newparam____fx_newparam_type(attributeData));
COLLADASaxFWL::newparam____fx_newparam_common__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__newparam____fx_newparam_common(attrData);
}


bool LibraryEffectsLoader15::begin__newparam____fx_common_newparam_type( const COLLADASaxFWL15::newparam____fx_common_newparam_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__newparam____fx_common_newparam_type(attributeData));
COLLADASaxFWL::newparam____common_newparam_type__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__newparam____common_newparam_type(attrData);
}


bool LibraryEffectsLoader15::end__newparam____fx_common_newparam_type()
{
SaxVirtualFunctionTest15(end__newparam____fx_common_newparam_type());
return mLoader->end__newparam____common_newparam_type();
}


bool LibraryEffectsLoader15::begin__instance_image( const COLLADASaxFWL15::instance_image__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_image(attributeData));
COLLADASaxFWL::instance_image__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_image__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_image__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_image__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_image(attrData);
}


bool LibraryEffectsLoader15::end__instance_image()
{
SaxVirtualFunctionTest15(end__instance_image());
return mLoader->end__instance_image();
}


bool LibraryEffectsLoader15::begin__sampler2D____fx_sampler2D_type()
{
SaxVirtualFunctionTest15(begin__sampler2D____fx_sampler2D_type());
return mLoader->begin__sampler2D____fx_sampler2D_common();
}


bool LibraryEffectsLoader15::end__sampler2D____fx_sampler2D_type()
{
SaxVirtualFunctionTest15(end__sampler2D____fx_sampler2D_type());
return mLoader->end__sampler2D____fx_sampler2D_common();
}


bool LibraryEffectsLoader15::begin__param____NCName()
{
SaxVirtualFunctionTest15(begin__param____NCName());
return mLoader->begin__source____NCName();
}


bool LibraryEffectsLoader15::end__param____NCName()
{
SaxVirtualFunctionTest15(end__param____NCName());
return mLoader->end__source____NCName();
}


bool LibraryEffectsLoader15::data__param____NCName( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__param____NCName(data, length));
return mLoader->data__source____NCName(data, length);
}


bool LibraryEffectsLoader15::begin__wrap_s____fx_sampler_wrap_enum()
{
SaxVirtualFunctionTest15(begin__wrap_s____fx_sampler_wrap_enum());
return mLoader->begin__wrap_s____fx_sampler_wrap_common();
}


bool LibraryEffectsLoader15::end__wrap_s____fx_sampler_wrap_enum()
{
SaxVirtualFunctionTest15(end__wrap_s____fx_sampler_wrap_enum());
return mLoader->end__wrap_s____fx_sampler_wrap_common();
}


bool LibraryEffectsLoader15::data__wrap_s____fx_sampler_wrap_enum( const COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum value )
{
SaxVirtualFunctionTest15(data__wrap_s____fx_sampler_wrap_enum(value));
COLLADASaxFWL::ENUM__fx_sampler_wrap_common newValue;
switch (value) {
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__WRAP: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__WRAP; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__CLAMP: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__CLAMP; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__BORDER: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__BORDER; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__MIRROR: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__MIRROR; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__MIRROR_ONCE: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__MIRROR_ONCE; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__COUNT: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__COUNT; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__NOT_PRESENT: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__NOT_PRESENT; break;
}
return mLoader->data__wrap_s____fx_sampler_wrap_common(newValue);
}


bool LibraryEffectsLoader15::begin__wrap_t____fx_sampler_wrap_enum()
{
SaxVirtualFunctionTest15(begin__wrap_t____fx_sampler_wrap_enum());
return mLoader->begin__wrap_t____fx_sampler_wrap_common();
}


bool LibraryEffectsLoader15::end__wrap_t____fx_sampler_wrap_enum()
{
SaxVirtualFunctionTest15(end__wrap_t____fx_sampler_wrap_enum());
return mLoader->end__wrap_t____fx_sampler_wrap_common();
}


bool LibraryEffectsLoader15::data__wrap_t____fx_sampler_wrap_enum( const COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum value )
{
SaxVirtualFunctionTest15(data__wrap_t____fx_sampler_wrap_enum(value));
COLLADASaxFWL::ENUM__fx_sampler_wrap_common newValue;
switch (value) {
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__WRAP: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__WRAP; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__CLAMP: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__CLAMP; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__BORDER: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__BORDER; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__MIRROR: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__MIRROR; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__MIRROR_ONCE: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__MIRROR_ONCE; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__COUNT: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__COUNT; break;
case COLLADASaxFWL15::ENUM__fx_sampler_wrap_enum__NOT_PRESENT: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__NOT_PRESENT; break;
}
return mLoader->data__wrap_t____fx_sampler_wrap_common(newValue);
}


bool LibraryEffectsLoader15::begin__profile_common_type____technique( const COLLADASaxFWL15::profile_common_type____technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__profile_common_type____technique(attributeData));
COLLADASaxFWL::profile_COMMON__technique__AttributeData attrData;
attrData.id = attributeData.id;
attrData.sid = attributeData.sid;
return mLoader->begin__profile_COMMON__technique(attrData);
}


bool LibraryEffectsLoader15::end__profile_common_type____technique()
{
SaxVirtualFunctionTest15(end__profile_common_type____technique());
return mLoader->end__profile_COMMON__technique();
}


bool LibraryEffectsLoader15::begin__profile_COMMON__technique__constant()
{
SaxVirtualFunctionTest15(begin__profile_COMMON__technique__constant());
return mLoader->begin__profile_COMMON__technique__constant();
}


bool LibraryEffectsLoader15::end__profile_COMMON__technique__constant()
{
SaxVirtualFunctionTest15(end__profile_COMMON__technique__constant());
return mLoader->end__profile_COMMON__technique__constant();
}


bool LibraryEffectsLoader15::begin__lambert()
{
SaxVirtualFunctionTest15(begin__lambert());
return mLoader->begin__lambert();
}


bool LibraryEffectsLoader15::end__lambert()
{
SaxVirtualFunctionTest15(end__lambert());
return mLoader->end__lambert();
}


bool LibraryEffectsLoader15::begin__phong()
{
SaxVirtualFunctionTest15(begin__phong());
return mLoader->begin__phong();
}


bool LibraryEffectsLoader15::end__phong()
{
SaxVirtualFunctionTest15(end__phong());
return mLoader->end__phong();
}


bool LibraryEffectsLoader15::begin__emission()
{
SaxVirtualFunctionTest15(begin__emission());
return mLoader->begin__emission();
}


bool LibraryEffectsLoader15::end__emission()
{
SaxVirtualFunctionTest15(end__emission());
return mLoader->end__emission();
}


bool LibraryEffectsLoader15::begin__ambient____fx_common_color_or_texture_type()
{
SaxVirtualFunctionTest15(begin__ambient____fx_common_color_or_texture_type());
return mLoader->begin__ambient____common_color_or_texture_type();
}


bool LibraryEffectsLoader15::end__ambient____fx_common_color_or_texture_type()
{
SaxVirtualFunctionTest15(end__ambient____fx_common_color_or_texture_type());
return mLoader->end__ambient____common_color_or_texture_type();
}


bool LibraryEffectsLoader15::begin__diffuse()
{
SaxVirtualFunctionTest15(begin__diffuse());
return mLoader->begin__diffuse();
}


bool LibraryEffectsLoader15::end__diffuse()
{
SaxVirtualFunctionTest15(end__diffuse());
return mLoader->end__diffuse();
}


bool LibraryEffectsLoader15::begin__specular()
{
SaxVirtualFunctionTest15(begin__specular());
return mLoader->begin__specular();
}


bool LibraryEffectsLoader15::end__specular()
{
SaxVirtualFunctionTest15(end__specular());
return mLoader->end__specular();
}


bool LibraryEffectsLoader15::begin__shininess()
{
SaxVirtualFunctionTest15(begin__shininess());
return mLoader->begin__shininess();
}


bool LibraryEffectsLoader15::end__shininess()
{
SaxVirtualFunctionTest15(end__shininess());
return mLoader->end__shininess();
}


bool LibraryEffectsLoader15::begin__reflective()
{
SaxVirtualFunctionTest15(begin__reflective());
return mLoader->begin__reflective();
}


bool LibraryEffectsLoader15::end__reflective()
{
SaxVirtualFunctionTest15(end__reflective());
return mLoader->end__reflective();
}


bool LibraryEffectsLoader15::begin__reflectivity()
{
SaxVirtualFunctionTest15(begin__reflectivity());
return mLoader->begin__reflectivity();
}


bool LibraryEffectsLoader15::end__reflectivity()
{
SaxVirtualFunctionTest15(end__reflectivity());
return mLoader->end__reflectivity();
}


bool LibraryEffectsLoader15::begin__transparency()
{
SaxVirtualFunctionTest15(begin__transparency());
return mLoader->begin__transparency();
}


bool LibraryEffectsLoader15::end__transparency ()
{
SaxVirtualFunctionTest15(end__transparency ());
return mLoader->end__transparency();
}


bool LibraryEffectsLoader15::begin__index_of_refraction()
{
SaxVirtualFunctionTest15(begin__index_of_refraction());
return mLoader->begin__index_of_refraction();
}


bool LibraryEffectsLoader15::end__index_of_refraction()
{
SaxVirtualFunctionTest15(end__index_of_refraction());
return mLoader->end__index_of_refraction();
}


bool LibraryEffectsLoader15::begin__blinn()
{
SaxVirtualFunctionTest15(begin__blinn());
return mLoader->begin__blinn();
}


bool LibraryEffectsLoader15::end__blinn()
{
SaxVirtualFunctionTest15(end__blinn());
return mLoader->end__blinn();
}


bool LibraryEffectsLoader15::begin__transparent( const COLLADASaxFWL15::transparent__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__transparent(attributeData));
COLLADASaxFWL::transparent__AttributeData attrData;
switch (attributeData.opaque) {
case COLLADASaxFWL15::ENUM__fx_opaque_enum__A_ONE: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__A_ONE; break;
case COLLADASaxFWL15::ENUM__fx_opaque_enum__A_ZERO: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__A_ZERO; break;
case COLLADASaxFWL15::ENUM__fx_opaque_enum__RGB_ONE: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__RGB_ONE; break;
case COLLADASaxFWL15::ENUM__fx_opaque_enum__RGB_ZERO: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__RGB_ZERO; break;
case COLLADASaxFWL15::ENUM__fx_opaque_enum__COUNT: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__INVALID; break;
case COLLADASaxFWL15::ENUM__fx_opaque_enum__NOT_PRESENT: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__NOT_PRESENT; break;
}
return mLoader->begin__transparent(attrData);
}


bool LibraryEffectsLoader15::end__transparent()
{
SaxVirtualFunctionTest15(end__transparent());
return mLoader->end__transparent();
}


bool LibraryEffectsLoader15::begin__fx_common_color_or_texture_type____color( const COLLADASaxFWL15::fx_common_color_or_texture_type____color__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__fx_common_color_or_texture_type____color(attributeData));
COLLADASaxFWL::common_color_or_texture_type____color__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__common_color_or_texture_type____color(attrData);
}


bool LibraryEffectsLoader15::end__fx_common_color_or_texture_type____color()
{
SaxVirtualFunctionTest15(end__fx_common_color_or_texture_type____color());
return mLoader->end__common_color_or_texture_type____color();
}


bool LibraryEffectsLoader15::data__fx_common_color_or_texture_type____color( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__fx_common_color_or_texture_type____color(data, length));
return mLoader->data__common_color_or_texture_type____color(data, length);
}


bool LibraryEffectsLoader15::begin__fx_common_float_or_param_type____float( const COLLADASaxFWL15::fx_common_float_or_param_type____float__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__fx_common_float_or_param_type____float(attributeData));
COLLADASaxFWL::common_float_or_param_type____float__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__common_float_or_param_type____float(attrData);
}


bool LibraryEffectsLoader15::end__fx_common_float_or_param_type____float()
{
SaxVirtualFunctionTest15(end__fx_common_float_or_param_type____float());
return mLoader->end__common_float_or_param_type____float();
}


bool LibraryEffectsLoader15::data__fx_common_float_or_param_type____float( float value )
{
SaxVirtualFunctionTest15(data__fx_common_float_or_param_type____float(value));
return mLoader->data__common_float_or_param_type____float(value);
}


bool LibraryEffectsLoader15::begin__texture( const COLLADASaxFWL15::texture__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__texture(attributeData));
COLLADASaxFWL::texture__AttributeData attrData;
attrData.texture = attributeData.texture;
attrData.texcoord = attributeData.texcoord;
return mLoader->begin__texture(attrData);
}


bool LibraryEffectsLoader15::end__texture()
{
SaxVirtualFunctionTest15(end__texture());
return mLoader->end__texture();
}


bool LibraryEffectsLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryEffectsLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
