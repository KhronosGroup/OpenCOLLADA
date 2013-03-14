/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryEffectsLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryEffectsLoader14::end__library_effects()
{
SaxVirtualFunctionTest14(end__library_effects());
return mLoader->end__library_effects();
}


bool LibraryEffectsLoader14::begin__effect( const COLLADASaxFWL14::effect__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__effect(attributeData));
COLLADASaxFWL::effect__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__effect(attrData);
}


bool LibraryEffectsLoader14::end__effect()
{
SaxVirtualFunctionTest14(end__effect());
return mLoader->end__effect();
}


bool LibraryEffectsLoader14::begin__profile_COMMON( const COLLADASaxFWL14::profile_COMMON__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__profile_COMMON(attributeData));
COLLADASaxFWL::profile_COMMON__AttributeData attrData;
attrData.id = attributeData.id;
return mLoader->begin__profile_COMMON(attrData);
}


bool LibraryEffectsLoader14::end__profile_COMMON()
{
SaxVirtualFunctionTest14(end__profile_COMMON());
return mLoader->end__profile_COMMON();
}


bool LibraryEffectsLoader14::begin__newparam____fx_newparam_common( const COLLADASaxFWL14::newparam____fx_newparam_common__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__newparam____fx_newparam_common(attributeData));
COLLADASaxFWL::newparam____fx_newparam_common__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__newparam____fx_newparam_common(attrData);
}


bool LibraryEffectsLoader14::begin__newparam____common_newparam_type( const COLLADASaxFWL14::newparam____common_newparam_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__newparam____common_newparam_type(attributeData));
COLLADASaxFWL::newparam____common_newparam_type__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__newparam____common_newparam_type(attrData);
}


bool LibraryEffectsLoader14::end__newparam____common_newparam_type()
{
SaxVirtualFunctionTest14(end__newparam____common_newparam_type());
return mLoader->end__newparam____common_newparam_type();
}

bool LibraryEffectsLoader14::begin__newparam____cg_newparam( const COLLADASaxFWL14::newparam____cg_newparam__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__newparam____cg_newparam(attributeData));
COLLADASaxFWL::newparam____cg_newparam__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__newparam____cg_newparam(attrData);
}

bool LibraryEffectsLoader14::begin__surface____fx_surface_common( const COLLADASaxFWL14::surface____fx_surface_common__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__surface____fx_surface_common(attributeData));
COLLADASaxFWL::surface____fx_surface_common__AttributeData attrData;
switch (attributeData.type) {
case COLLADASaxFWL14::ENUM__fx_surface_type_enum__UNTYPED: attrData.type=COLLADASaxFWL::ENUM__fx_surface_type__UNTYPED; break;
case COLLADASaxFWL14::ENUM__fx_surface_type_enum__1D: attrData.type=COLLADASaxFWL::ENUM__fx_surface_type__1D; break;
case COLLADASaxFWL14::ENUM__fx_surface_type_enum__2D: attrData.type=COLLADASaxFWL::ENUM__fx_surface_type__2D; break;
case COLLADASaxFWL14::ENUM__fx_surface_type_enum__3D: attrData.type=COLLADASaxFWL::ENUM__fx_surface_type__3D; break;
case COLLADASaxFWL14::ENUM__fx_surface_type_enum__RECT: attrData.type=COLLADASaxFWL::ENUM__fx_surface_type__RECT; break;
case COLLADASaxFWL14::ENUM__fx_surface_type_enum__CUBE: attrData.type=COLLADASaxFWL::ENUM__fx_surface_type__CUBE; break;
case COLLADASaxFWL14::ENUM__fx_surface_type_enum__DEPTH: attrData.type=COLLADASaxFWL::ENUM__fx_surface_type__DEPTH; break;
case COLLADASaxFWL14::ENUM__fx_surface_type_enum__COUNT: attrData.type=COLLADASaxFWL::ENUM__fx_surface_type__INVALID; break;
case COLLADASaxFWL14::ENUM__fx_surface_type_enum__NOT_PRESENT: attrData.type=COLLADASaxFWL::ENUM__fx_surface_type__NOT_PRESENT; break;
}
return mLoader->begin__surface____fx_surface_common(attrData);
}


bool LibraryEffectsLoader14::end__surface____fx_surface_common()
{
SaxVirtualFunctionTest14(end__surface____fx_surface_common());
return mLoader->end__surface____fx_surface_common();
}


bool LibraryEffectsLoader14::begin__init_from____fx_surface_init_from_common( const COLLADASaxFWL14::init_from____fx_surface_init_from_common__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__init_from____fx_surface_init_from_common(attributeData));
COLLADASaxFWL::init_from____fx_surface_init_from_common__AttributeData attrData;
attrData.mip = attributeData.mip;
attrData.slice = attributeData.slice;
switch (attributeData.face) {
case COLLADASaxFWL14::ENUM__fx_surface_face_enum__POSITIVE_X: attrData.face=COLLADASaxFWL::ENUM__fx_surface_face__POSITIVE_X; break;
case COLLADASaxFWL14::ENUM__fx_surface_face_enum__NEGATIVE_X: attrData.face=COLLADASaxFWL::ENUM__fx_surface_face__NEGATIVE_X; break;
case COLLADASaxFWL14::ENUM__fx_surface_face_enum__POSITIVE_Y: attrData.face=COLLADASaxFWL::ENUM__fx_surface_face__POSITIVE_Y; break;
case COLLADASaxFWL14::ENUM__fx_surface_face_enum__NEGATIVE_Y: attrData.face=COLLADASaxFWL::ENUM__fx_surface_face__NEGATIVE_Y; break;
case COLLADASaxFWL14::ENUM__fx_surface_face_enum__POSITIVE_Z: attrData.face=COLLADASaxFWL::ENUM__fx_surface_face__POSITIVE_Z; break;
case COLLADASaxFWL14::ENUM__fx_surface_face_enum__NEGATIVE_Z: attrData.face=COLLADASaxFWL::ENUM__fx_surface_face__NEGATIVE_Z; break;
case COLLADASaxFWL14::ENUM__fx_surface_face_enum__COUNT: attrData.face=COLLADASaxFWL::ENUM__fx_surface_face__INVALID; break;
case COLLADASaxFWL14::ENUM__fx_surface_face_enum__NOT_PRESENT: attrData.face=COLLADASaxFWL::ENUM__fx_surface_face__NOT_PRESENT; break;
}
return mLoader->begin__init_from____fx_surface_init_from_common(attrData);
}


bool LibraryEffectsLoader14::end__init_from____fx_surface_init_from_common()
{
SaxVirtualFunctionTest14(end__init_from____fx_surface_init_from_common());
return mLoader->end__init_from____fx_surface_init_from_common();
}


bool LibraryEffectsLoader14::data__init_from____fx_surface_init_from_common( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__init_from____fx_surface_init_from_common(data, length));
return mLoader->data__init_from____fx_surface_init_from_common(data, length);
}


bool LibraryEffectsLoader14::begin__sampler2D____fx_sampler2D_common()
{
SaxVirtualFunctionTest14(begin__sampler2D____fx_sampler2D_common());
return mLoader->begin__sampler2D____fx_sampler2D_common();
}


bool LibraryEffectsLoader14::end__sampler2D____fx_sampler2D_common()
{
SaxVirtualFunctionTest14(end__sampler2D____fx_sampler2D_common());
return mLoader->end__sampler2D____fx_sampler2D_common();
}


bool LibraryEffectsLoader14::begin__source____NCName()
{
SaxVirtualFunctionTest14(begin__source____NCName());
return mLoader->begin__source____NCName();
}


bool LibraryEffectsLoader14::end__source____NCName()
{
SaxVirtualFunctionTest14(end__source____NCName());
return mLoader->end__source____NCName();
}


bool LibraryEffectsLoader14::data__source____NCName( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__source____NCName(data, length));
return mLoader->data__source____NCName(data, length);
}


bool LibraryEffectsLoader14::begin__wrap_s____fx_sampler_wrap_common()
{
SaxVirtualFunctionTest14(begin__wrap_s____fx_sampler_wrap_common());
return mLoader->begin__wrap_s____fx_sampler_wrap_common();
}


bool LibraryEffectsLoader14::end__wrap_s____fx_sampler_wrap_common()
{
SaxVirtualFunctionTest14(end__wrap_s____fx_sampler_wrap_common());
return mLoader->end__wrap_s____fx_sampler_wrap_common();
}


bool LibraryEffectsLoader14::data__wrap_s____fx_sampler_wrap_common( const COLLADASaxFWL14::ENUM__fx_sampler_wrap_common value )
{
SaxVirtualFunctionTest14(data__wrap_s____fx_sampler_wrap_common(value));
COLLADASaxFWL::ENUM__fx_sampler_wrap_common newValue;
switch (value) {
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__NONE: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__NONE; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__WRAP: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__WRAP; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__MIRROR: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__MIRROR; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__CLAMP: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__CLAMP; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__BORDER: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__BORDER; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__COUNT: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__COUNT; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__NOT_PRESENT: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__NOT_PRESENT; break;
}
return mLoader->data__wrap_s____fx_sampler_wrap_common(newValue);
}


bool LibraryEffectsLoader14::begin__wrap_t____fx_sampler_wrap_common()
{
SaxVirtualFunctionTest14(begin__wrap_t____fx_sampler_wrap_common());
return mLoader->begin__wrap_t____fx_sampler_wrap_common();
}


bool LibraryEffectsLoader14::end__wrap_t____fx_sampler_wrap_common()
{
SaxVirtualFunctionTest14(end__wrap_t____fx_sampler_wrap_common());
return mLoader->end__wrap_t____fx_sampler_wrap_common();
}


bool LibraryEffectsLoader14::data__wrap_t____fx_sampler_wrap_common( const COLLADASaxFWL14::ENUM__fx_sampler_wrap_common value )
{
SaxVirtualFunctionTest14(data__wrap_t____fx_sampler_wrap_common(value));
COLLADASaxFWL::ENUM__fx_sampler_wrap_common newValue;
switch (value) {
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__NONE: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__NONE; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__WRAP: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__WRAP; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__MIRROR: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__MIRROR; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__CLAMP: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__CLAMP; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__BORDER: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__BORDER; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__COUNT: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__COUNT; break;
case COLLADASaxFWL14::ENUM__fx_sampler_wrap_common__NOT_PRESENT: newValue=COLLADASaxFWL::ENUM__fx_sampler_wrap_common__NOT_PRESENT; break;
}
return mLoader->data__wrap_t____fx_sampler_wrap_common(newValue);
}


bool LibraryEffectsLoader14::begin__profile_COMMON__technique( const COLLADASaxFWL14::profile_COMMON__technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__profile_COMMON__technique(attributeData));
COLLADASaxFWL::profile_COMMON__technique__AttributeData attrData;
attrData.id = attributeData.id;
attrData.sid = attributeData.sid;
return mLoader->begin__profile_COMMON__technique(attrData);
}


bool LibraryEffectsLoader14::end__profile_COMMON__technique()
{
SaxVirtualFunctionTest14(end__profile_COMMON__technique());
return mLoader->end__profile_COMMON__technique();
}


bool LibraryEffectsLoader14::begin__profile_COMMON__technique__constant()
{
SaxVirtualFunctionTest14(begin__profile_COMMON__technique__constant());
return mLoader->begin__profile_COMMON__technique__constant();
}


bool LibraryEffectsLoader14::end__profile_COMMON__technique__constant()
{
SaxVirtualFunctionTest14(end__profile_COMMON__technique__constant());
return mLoader->end__profile_COMMON__technique__constant();
}


bool LibraryEffectsLoader14::begin__lambert()
{
SaxVirtualFunctionTest14(begin__lambert());
return mLoader->begin__lambert();
}


bool LibraryEffectsLoader14::end__lambert()
{
SaxVirtualFunctionTest14(end__lambert());
return mLoader->end__lambert();
}


bool LibraryEffectsLoader14::begin__phong()
{
SaxVirtualFunctionTest14(begin__phong());
return mLoader->begin__phong();
}


bool LibraryEffectsLoader14::end__phong()
{
SaxVirtualFunctionTest14(end__phong());
return mLoader->end__phong();
}


bool LibraryEffectsLoader14::begin__emission()
{
SaxVirtualFunctionTest14(begin__emission());
return mLoader->begin__emission();
}


bool LibraryEffectsLoader14::end__emission()
{
SaxVirtualFunctionTest14(end__emission());
return mLoader->end__emission();
}


bool LibraryEffectsLoader14::begin__ambient____common_color_or_texture_type()
{
SaxVirtualFunctionTest14(begin__ambient____common_color_or_texture_type());
return mLoader->begin__ambient____common_color_or_texture_type();
}


bool LibraryEffectsLoader14::end__ambient____common_color_or_texture_type()
{
SaxVirtualFunctionTest14(end__ambient____common_color_or_texture_type());
return mLoader->end__ambient____common_color_or_texture_type();
}


bool LibraryEffectsLoader14::begin__diffuse()
{
SaxVirtualFunctionTest14(begin__diffuse());
return mLoader->begin__diffuse();
}


bool LibraryEffectsLoader14::end__diffuse()
{
SaxVirtualFunctionTest14(end__diffuse());
return mLoader->end__diffuse();
}


bool LibraryEffectsLoader14::begin__specular()
{
SaxVirtualFunctionTest14(begin__specular());
return mLoader->begin__specular();
}


bool LibraryEffectsLoader14::end__specular()
{
SaxVirtualFunctionTest14(end__specular());
return mLoader->end__specular();
}


bool LibraryEffectsLoader14::begin__shininess()
{
SaxVirtualFunctionTest14(begin__shininess());
return mLoader->begin__shininess();
}


bool LibraryEffectsLoader14::end__shininess()
{
SaxVirtualFunctionTest14(end__shininess());
return mLoader->end__shininess();
}


bool LibraryEffectsLoader14::begin__reflective()
{
SaxVirtualFunctionTest14(begin__reflective());
return mLoader->begin__reflective();
}


bool LibraryEffectsLoader14::end__reflective()
{
SaxVirtualFunctionTest14(end__reflective());
return mLoader->end__reflective();
}


bool LibraryEffectsLoader14::begin__reflectivity()
{
SaxVirtualFunctionTest14(begin__reflectivity());
return mLoader->begin__reflectivity();
}


bool LibraryEffectsLoader14::end__reflectivity()
{
SaxVirtualFunctionTest14(end__reflectivity());
return mLoader->end__reflectivity();
}


bool LibraryEffectsLoader14::begin__transparency()
{
SaxVirtualFunctionTest14(begin__transparency());
return mLoader->begin__transparency();
}


bool LibraryEffectsLoader14::end__transparency()
{
SaxVirtualFunctionTest14(end__transparency());
return mLoader->end__transparency();
}


bool LibraryEffectsLoader14::begin__index_of_refraction()
{
SaxVirtualFunctionTest14(begin__index_of_refraction());
return mLoader->begin__index_of_refraction();
}


bool LibraryEffectsLoader14::end__index_of_refraction()
{
SaxVirtualFunctionTest14(end__index_of_refraction());
return mLoader->end__index_of_refraction();
}


bool LibraryEffectsLoader14::begin__blinn()
{
SaxVirtualFunctionTest14(begin__blinn());
return mLoader->begin__blinn();
}


bool LibraryEffectsLoader14::end__blinn()
{
SaxVirtualFunctionTest14(end__blinn());
return mLoader->end__blinn();
}


bool LibraryEffectsLoader14::begin__transparent( const COLLADASaxFWL14::transparent__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__transparent(attributeData));
COLLADASaxFWL::transparent__AttributeData attrData;
switch (attributeData.opaque) {
case COLLADASaxFWL14::ENUM__fx_opaque_enum__A_ONE: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__A_ONE; break;
case COLLADASaxFWL14::ENUM__fx_opaque_enum__RGB_ZERO: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__RGB_ZERO; break;
case COLLADASaxFWL14::ENUM__fx_opaque_enum__COUNT: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__INVALID; break;
case COLLADASaxFWL14::ENUM__fx_opaque_enum__NOT_PRESENT: attrData.opaque=COLLADASaxFWL::ENUM__fx_opaque__NOT_PRESENT; break;
}
return mLoader->begin__transparent(attrData);
}


bool LibraryEffectsLoader14::end__transparent()
{
SaxVirtualFunctionTest14(end__transparent());
return mLoader->end__transparent();
}


bool LibraryEffectsLoader14::begin__common_color_or_texture_type____color( const COLLADASaxFWL14::common_color_or_texture_type____color__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__common_color_or_texture_type____color(attributeData));
COLLADASaxFWL::common_color_or_texture_type____color__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__common_color_or_texture_type____color(attrData);
}


bool LibraryEffectsLoader14::end__common_color_or_texture_type____color()
{
SaxVirtualFunctionTest14(end__common_color_or_texture_type____color());
return mLoader->end__common_color_or_texture_type____color();
}


bool LibraryEffectsLoader14::data__common_color_or_texture_type____color( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__common_color_or_texture_type____color(data, length));
return mLoader->data__common_color_or_texture_type____color(data, length);
}


bool LibraryEffectsLoader14::begin__common_float_or_param_type____float( const COLLADASaxFWL14::common_float_or_param_type____float__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__common_float_or_param_type____float(attributeData));
COLLADASaxFWL::common_float_or_param_type____float__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__common_float_or_param_type____float(attrData);
}


bool LibraryEffectsLoader14::end__common_float_or_param_type____float()
{
SaxVirtualFunctionTest14(end__common_float_or_param_type____float());
return mLoader->end__common_float_or_param_type____float();
}


bool LibraryEffectsLoader14::data__common_float_or_param_type____float( float value )
{
SaxVirtualFunctionTest14(data__common_float_or_param_type____float(value));
return mLoader->data__common_float_or_param_type____float(value);
}


bool LibraryEffectsLoader14::begin__texture( const COLLADASaxFWL14::texture__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__texture(attributeData));
COLLADASaxFWL::texture__AttributeData attrData;
attrData.texture = attributeData.texture;
attrData.texcoord = attributeData.texcoord;
return mLoader->begin__texture(attrData);
}


bool LibraryEffectsLoader14::end__texture()
{
SaxVirtualFunctionTest14(end__texture());
return mLoader->end__texture();
}


bool LibraryEffectsLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryEffectsLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
