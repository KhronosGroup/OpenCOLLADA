/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPhysicsModelLoader15.h"


namespace COLLADASaxFWL
{


bool PhysicsModelLoader15::begin__physics_model( const COLLADASaxFWL15::physics_model__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__physics_model(attributeData));
COLLADASaxFWL::physics_model__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_model(attrData);
}


bool PhysicsModelLoader15::end__physics_model()
{
SaxVirtualFunctionTest15(end__physics_model());
return mLoader->end__physics_model();
}


bool PhysicsModelLoader15::begin__rigid_body( const COLLADASaxFWL15::rigid_body__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__rigid_body(attributeData));
COLLADASaxFWL::rigid_body__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
return mLoader->begin__rigid_body(attrData);
}


bool PhysicsModelLoader15::end__rigid_body()
{
SaxVirtualFunctionTest15(end__rigid_body());
return mLoader->end__rigid_body();
}


bool PhysicsModelLoader15::begin__rigid_body_type____technique_common()
{
SaxVirtualFunctionTest15(begin__rigid_body_type____technique_common());
return mLoader->begin__rigid_body__technique_common();
}


bool PhysicsModelLoader15::end__rigid_body_type____technique_common()
{
SaxVirtualFunctionTest15(end__rigid_body_type____technique_common());
return mLoader->end__rigid_body__technique_common();
}


bool PhysicsModelLoader15::begin__rigid_body__technique_common__dynamic( const COLLADASaxFWL15::rigid_body__technique_common__dynamic__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__rigid_body__technique_common__dynamic(attributeData));
COLLADASaxFWL::rigid_body__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
return mLoader->begin__rigid_body__technique_common__dynamic(attrData);
}


bool PhysicsModelLoader15::end__rigid_body__technique_common__dynamic()
{
SaxVirtualFunctionTest15(end__rigid_body__technique_common__dynamic());
return mLoader->end__rigid_body__technique_common__dynamic();
}


bool PhysicsModelLoader15::data__rigid_body__technique_common__dynamic( const bool value )
{
SaxVirtualFunctionTest15(data__rigid_body__technique_common__dynamic(value));
return mLoader->data__rigid_body__technique_common__dynamic(value);
}


bool PhysicsModelLoader15::begin__mass( const COLLADASaxFWL15::mass__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__mass(attributeData));
COLLADASaxFWL::mass__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__mass(attrData);
}


bool PhysicsModelLoader15::end__mass()
{
SaxVirtualFunctionTest15(end__mass());
return mLoader->end__mass();
}


bool PhysicsModelLoader15::data__mass( const float value )
{
SaxVirtualFunctionTest15(data__mass(value));
return mLoader->data__mass(value);
}


bool PhysicsModelLoader15::begin__rigid_body__technique_common__mass_frame()
{
SaxVirtualFunctionTest15(begin__rigid_body__technique_common__mass_frame());
return mLoader->begin__mass_frame();
}


bool PhysicsModelLoader15::end__rigid_body__technique_common__mass_frame()
{
SaxVirtualFunctionTest15(end__rigid_body__technique_common__mass_frame());
return mLoader->end__mass_frame();
}


bool PhysicsModelLoader15::begin__inertia( const COLLADASaxFWL15::inertia__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__inertia(attributeData));
COLLADASaxFWL::inertia__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__inertia(attrData);
}


bool PhysicsModelLoader15::end__inertia()
{
SaxVirtualFunctionTest15(end__inertia());
return mLoader->end__inertia();
}


bool PhysicsModelLoader15::data__inertia( const float* value, size_t length )
{
SaxVirtualFunctionTest15(data__inertia(value, length));
return mLoader->data__inertia(value, length);
}


bool PhysicsModelLoader15::begin__instance_physics_material( const COLLADASaxFWL15::instance_physics_material__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_physics_material(attributeData));
COLLADASaxFWL::instance_physics_material__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_physics_material__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_physics_material__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_physics_material__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_physics_material(attrData);
}


bool PhysicsModelLoader15::end__instance_physics_material()
{
SaxVirtualFunctionTest15(end__instance_physics_material());
return mLoader->end__instance_physics_material();
}


bool PhysicsModelLoader15::begin__rigid_body__technique_common__shape()
{
SaxVirtualFunctionTest15(begin__rigid_body__technique_common__shape());
return mLoader->begin__shape();
}


bool PhysicsModelLoader15::end__rigid_body__technique_common__shape()
{
SaxVirtualFunctionTest15(end__rigid_body__technique_common__shape());
return mLoader->end__shape();
}


bool PhysicsModelLoader15::begin__rigid_body__technique_common__shape__hollow( const COLLADASaxFWL15::rigid_body__technique_common__shape__hollow__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__rigid_body__technique_common__shape__hollow(attributeData));
COLLADASaxFWL::shape__hollow__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__shape__hollow(attrData);
}


bool PhysicsModelLoader15::end__rigid_body__technique_common__shape__hollow()
{
SaxVirtualFunctionTest15(end__rigid_body__technique_common__shape__hollow());
return mLoader->end__shape__hollow();
}


bool PhysicsModelLoader15::data__rigid_body__technique_common__shape__hollow( const bool value )
{
SaxVirtualFunctionTest15(data__rigid_body__technique_common__shape__hollow(value));
return mLoader->data__shape__hollow(value);
}


bool PhysicsModelLoader15::begin__density( const COLLADASaxFWL15::density__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__density(attributeData));
COLLADASaxFWL::density__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__density(attrData);
}


bool PhysicsModelLoader15::end__density()
{
SaxVirtualFunctionTest15(end__density());
return mLoader->end__density();
}


bool PhysicsModelLoader15::data__density( const float value )
{
SaxVirtualFunctionTest15(data__density(value));
return mLoader->data__density(value);
}


bool PhysicsModelLoader15::begin__plane()
{
SaxVirtualFunctionTest15(begin__plane());
return mLoader->begin__plane();
}


bool PhysicsModelLoader15::end__plane()
{
SaxVirtualFunctionTest15(end__plane());
return mLoader->end__plane();
}


bool PhysicsModelLoader15::begin__equation()
{
SaxVirtualFunctionTest15(begin__equation());
return mLoader->begin__equation();
}


bool PhysicsModelLoader15::end__equation()
{
SaxVirtualFunctionTest15(end__equation());
return mLoader->end__equation();
}


bool PhysicsModelLoader15::data__equation( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__equation(data, length));
return mLoader->data__equation(data, length);
}


bool PhysicsModelLoader15::begin__box()
{
SaxVirtualFunctionTest15(begin__box());
return mLoader->begin__box();
}


bool PhysicsModelLoader15::end__box()
{
SaxVirtualFunctionTest15(end__box());
return mLoader->end__box();
}


bool PhysicsModelLoader15::begin__half_extents()
{
SaxVirtualFunctionTest15(begin__half_extents());
return mLoader->begin__half_extents();
}


bool PhysicsModelLoader15::end__half_extents()
{
SaxVirtualFunctionTest15(end__half_extents());
return mLoader->end__half_extents();
}


bool PhysicsModelLoader15::data__half_extents( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__half_extents(data, length));
return mLoader->data__half_extents(data, length);
}


bool PhysicsModelLoader15::begin__sphere()
{
SaxVirtualFunctionTest15(begin__sphere());
return mLoader->begin__sphere();
}


bool PhysicsModelLoader15::end__sphere()
{
SaxVirtualFunctionTest15(end__sphere());
return mLoader->end__sphere();
}


bool PhysicsModelLoader15::begin__radius____float_type()
{
SaxVirtualFunctionTest15(begin__radius____float_type());
return mLoader->begin__radius___float();
}


bool PhysicsModelLoader15::end__radius____float_type()
{
SaxVirtualFunctionTest15(end__radius____float_type());
return mLoader->end__radius___float();
}


bool PhysicsModelLoader15::data__radius____float_type( const float value )
{
SaxVirtualFunctionTest15(data__radius____float_type(value));
return mLoader->data__radius___float(value);
}


bool PhysicsModelLoader15::begin__cylinder____cylinder_type()
{
SaxVirtualFunctionTest15(begin__cylinder____cylinder_type());
return mLoader->begin__cylinder();
}


bool PhysicsModelLoader15::end__cylinder____cylinder_type()
{
SaxVirtualFunctionTest15(end__cylinder____cylinder_type());
return mLoader->end__cylinder();
}


bool PhysicsModelLoader15::begin__height()
{
SaxVirtualFunctionTest15(begin__height());
return mLoader->begin__height();
}


bool PhysicsModelLoader15::end__height()
{
SaxVirtualFunctionTest15(end__height());
return mLoader->end__height();
}


bool PhysicsModelLoader15::data__height( const float value )
{
SaxVirtualFunctionTest15(data__height(value));
return mLoader->data__height(value);
}


bool PhysicsModelLoader15::begin__radius____float2_type()
{
SaxVirtualFunctionTest15(begin__radius____float2_type());
return mLoader->begin__radius___float2();
}


bool PhysicsModelLoader15::end__radius____float2_type()
{
SaxVirtualFunctionTest15(end__radius____float2_type());
return mLoader->end__radius___float2();
}


bool PhysicsModelLoader15::data__radius____float2_type( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__radius____float2_type(data, length));
return mLoader->data__radius___float2(data, length);
}


bool PhysicsModelLoader15::begin__capsule()
{
SaxVirtualFunctionTest15(begin__capsule());
return mLoader->begin__capsule();
}


bool PhysicsModelLoader15::end__capsule()
{
SaxVirtualFunctionTest15(end__capsule());
return mLoader->end__capsule();
}


bool PhysicsModelLoader15::begin__radius____float3_type()
{
SaxVirtualFunctionTest15(begin__radius____float3_type());
return mLoader->begin__radius___float3();
}


bool PhysicsModelLoader15::end__radius____float3_type()
{
SaxVirtualFunctionTest15(end__radius____float3_type());
return mLoader->end__radius___float3();
}


bool PhysicsModelLoader15::data__radius____float3_type( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__radius____float3_type(data, length));
return mLoader->data__radius___float3(data, length);
}


bool PhysicsModelLoader15::begin__instance_geometry( const COLLADASaxFWL15::instance_geometry__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_geometry(attributeData));
COLLADASaxFWL::instance_geometry__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_geometry(attrData);
}


bool PhysicsModelLoader15::end__instance_geometry()
{
SaxVirtualFunctionTest15(end__instance_geometry());
return mLoader->end__instance_geometry();
}


bool PhysicsModelLoader15::begin__rigid_constraint( const COLLADASaxFWL15::rigid_constraint__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__rigid_constraint(attributeData));
COLLADASaxFWL::rigid_constraint__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
return mLoader->begin__rigid_constraint(attrData);
}


bool PhysicsModelLoader15::end__rigid_constraint()
{
SaxVirtualFunctionTest15(end__rigid_constraint());
return mLoader->end__rigid_constraint();
}


bool PhysicsModelLoader15::begin__ref_attachment( const COLLADASaxFWL15::ref_attachment__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__ref_attachment(attributeData));
COLLADASaxFWL::ref_attachment__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::ref_attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT) == COLLADASaxFWL15::ref_attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT ) {
    attrData.rigid_body = attributeData.rigid_body;
    attrData.present_attributes |= COLLADASaxFWL::ref_attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT;
}
return mLoader->begin__ref_attachment(attrData);
}


bool PhysicsModelLoader15::end__ref_attachment()
{
SaxVirtualFunctionTest15(end__ref_attachment());
return mLoader->end__ref_attachment();
}


bool PhysicsModelLoader15::begin__attachment( const COLLADASaxFWL15::attachment__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__attachment(attributeData));
COLLADASaxFWL::attachment__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT) == COLLADASaxFWL15::attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT ) {
    attrData.rigid_body = attributeData.rigid_body;
    attrData.present_attributes |= COLLADASaxFWL::attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT;
}
return mLoader->begin__attachment(attrData);
}


bool PhysicsModelLoader15::end__attachment()
{
SaxVirtualFunctionTest15(end__attachment());
return mLoader->end__attachment();
}


bool PhysicsModelLoader15::begin__translate( const COLLADASaxFWL15::translate__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__translate(attributeData));
COLLADASaxFWL::translate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__translate(attrData);
}


bool PhysicsModelLoader15::end__translate()
{
SaxVirtualFunctionTest15(end__translate());
return mLoader->end__translate();
}


bool PhysicsModelLoader15::data__translate( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__translate(data, length));
return mLoader->data__translate(data, length);
}


bool PhysicsModelLoader15::begin__rotate( const COLLADASaxFWL15::rotate__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__rotate(attributeData));
COLLADASaxFWL::rotate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__rotate(attrData);
}


bool PhysicsModelLoader15::end__rotate()
{
SaxVirtualFunctionTest15(end__rotate());
return mLoader->end__rotate();
}


bool PhysicsModelLoader15::data__rotate( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__rotate(data, length));
return mLoader->data__rotate(data, length);
}


bool PhysicsModelLoader15::begin__rigid_constraint____technique_common()
{
SaxVirtualFunctionTest15(begin__rigid_constraint____technique_common());
return mLoader->begin__rigid_constraint__technique_common();
}


bool PhysicsModelLoader15::end__instance_rigid_body_type____technique_common()
{
SaxVirtualFunctionTest15(end__instance_rigid_body_type____technique_common());
return mLoader->end__instance_rigid_body__technique_common();
}


bool PhysicsModelLoader15::begin__enabled( const COLLADASaxFWL15::enabled__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__enabled(attributeData));
COLLADASaxFWL::enabled__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__enabled(attrData);
}


bool PhysicsModelLoader15::end__enabled()
{
SaxVirtualFunctionTest15(end__enabled());
return mLoader->end__enabled();
}


bool PhysicsModelLoader15::data__enabled( const bool value )
{
SaxVirtualFunctionTest15(data__enabled(value));
return mLoader->data__enabled(value);
}


bool PhysicsModelLoader15::begin__interpenetrate( const COLLADASaxFWL15::interpenetrate__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__interpenetrate(attributeData));
COLLADASaxFWL::interpenetrate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__interpenetrate(attrData);
}


bool PhysicsModelLoader15::end__interpenetrate()
{
SaxVirtualFunctionTest15(end__interpenetrate());
return mLoader->end__interpenetrate();
}


bool PhysicsModelLoader15::data__interpenetrate( const bool value )
{
SaxVirtualFunctionTest15(data__interpenetrate(value));
return mLoader->data__interpenetrate(value);
}


bool PhysicsModelLoader15::begin__rigid_constraint__technique_common__limits()
{
SaxVirtualFunctionTest15(begin__rigid_constraint__technique_common__limits());
return mLoader->begin__limits();
}


bool PhysicsModelLoader15::end__rigid_constraint__technique_common__limits()
{
SaxVirtualFunctionTest15(end__rigid_constraint__technique_common__limits());
return mLoader->end__limits();
}


bool PhysicsModelLoader15::begin__swing_cone_and_twist()
{
SaxVirtualFunctionTest15(begin__swing_cone_and_twist());
return mLoader->begin__swing_cone_and_twist();
}


bool PhysicsModelLoader15::end__swing_cone_and_twist()
{
SaxVirtualFunctionTest15(end__swing_cone_and_twist());
return mLoader->end__swing_cone_and_twist();
}


bool PhysicsModelLoader15::begin__min____targetable_float3_type( const COLLADASaxFWL15::min____targetable_float3_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__min____targetable_float3_type(attributeData));
COLLADASaxFWL::min__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__min(attrData);
}


bool PhysicsModelLoader15::end__min____targetable_float3_type()
{
SaxVirtualFunctionTest15(end__min____targetable_float3_type());
return mLoader->end__min();
}


bool PhysicsModelLoader15::data__min____targetable_float3_type( const float* value, size_t length )
{
SaxVirtualFunctionTest15(data__min____targetable_float3_type(value, length));
return mLoader->data__min(value, length);
}


bool PhysicsModelLoader15::begin__max____targetable_float3_type( const COLLADASaxFWL15::max____targetable_float3_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__max____targetable_float3_type(attributeData));
COLLADASaxFWL::max__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__max(attrData);
}


bool PhysicsModelLoader15::end__max____targetable_float3_type()
{
SaxVirtualFunctionTest15(end__max____targetable_float3_type());
return mLoader->end__max();
}


bool PhysicsModelLoader15::data__max____targetable_float3_type( const float* value, size_t length )
{
SaxVirtualFunctionTest15(data__max____targetable_float3_type(value, length));
return mLoader->data__max(value, length);
}


bool PhysicsModelLoader15::begin__spring()
{
SaxVirtualFunctionTest15(begin__spring());
return mLoader->begin__spring();
}


bool PhysicsModelLoader15::end__spring()
{
SaxVirtualFunctionTest15(end__spring());
return mLoader->end__spring();
}


bool PhysicsModelLoader15::begin__rigid_constraint__technique_common__limits__linear()
{
SaxVirtualFunctionTest15(begin__rigid_constraint__technique_common__limits__linear());
return mLoader->begin__limits__linear();
}


bool PhysicsModelLoader15::end__rigid_constraint__technique_common__limits__linear()
{
SaxVirtualFunctionTest15(end__rigid_constraint__technique_common__limits__linear());
return mLoader->end__limits__linear();
}


bool PhysicsModelLoader15::begin__angular()
{
SaxVirtualFunctionTest15(begin__angular());
return mLoader->begin__angular();
}


bool PhysicsModelLoader15::end__angular()
{
SaxVirtualFunctionTest15(end__angular());
return mLoader->end__angular();
}


bool PhysicsModelLoader15::begin__stiffness____targetable_float3_type( const COLLADASaxFWL15::stiffness____targetable_float3_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__stiffness____targetable_float3_type(attributeData));
COLLADASaxFWL::stiffness__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__stiffness(attrData);
}


bool PhysicsModelLoader15::end__stiffness()
{
SaxVirtualFunctionTest15(end__stiffness());
return mLoader->end__stiffness();
}


bool PhysicsModelLoader15::data__stiffness( const float value )
{
SaxVirtualFunctionTest15(data__stiffness(value));
return mLoader->data__stiffness(value);
}


bool PhysicsModelLoader15::begin__damping____targetable_float3_type( const COLLADASaxFWL15::damping____targetable_float3_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__damping____targetable_float3_type(attributeData));
COLLADASaxFWL::damping__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__damping(attrData);
}


bool PhysicsModelLoader15::end__damping()
{
SaxVirtualFunctionTest15(end__damping());
return mLoader->end__damping();
}


bool PhysicsModelLoader15::data__damping( const float value )
{
SaxVirtualFunctionTest15(data__damping(value));
return mLoader->data__damping(value);
}


bool PhysicsModelLoader15::begin__target_value____targetable_float3_type( const COLLADASaxFWL15::target_value____targetable_float3_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__target_value____targetable_float3_type(attributeData));
COLLADASaxFWL::target_value__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__target_value(attrData);
}


bool PhysicsModelLoader15::end__target_value()
{
SaxVirtualFunctionTest15(end__target_value());
return mLoader->end__target_value();
}


bool PhysicsModelLoader15::data__target_value( const float value )
{
SaxVirtualFunctionTest15(data__target_value(value));
return mLoader->data__target_value(value);
}


bool PhysicsModelLoader15::begin__spring__linear()
{
SaxVirtualFunctionTest15(begin__spring__linear());
return mLoader->begin__spring__linear();
}


bool PhysicsModelLoader15::end__spring__linear()
{
SaxVirtualFunctionTest15(end__spring__linear());
return mLoader->end__spring__linear();
}


bool PhysicsModelLoader15::begin__instance_physics_model( const COLLADASaxFWL15::instance_physics_model__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_physics_model(attributeData));
COLLADASaxFWL::instance_physics_model__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_physics_model__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_physics_model__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_physics_model__AttributeData::ATTRIBUTE_URL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_physics_model__AttributeData::ATTRIBUTE_PARENT_PRESENT) == COLLADASaxFWL15::instance_physics_model__AttributeData::ATTRIBUTE_PARENT_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_physics_model__AttributeData::ATTRIBUTE_PARENT_PRESENT;
}
return mLoader->begin__instance_physics_model(attrData);
}


bool PhysicsModelLoader15::end__instance_physics_model()
{
SaxVirtualFunctionTest15(end__instance_physics_model());
return mLoader->end__instance_physics_model();
}


bool PhysicsModelLoader15::begin__instance_force_field( const COLLADASaxFWL15::instance_force_field__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_force_field(attributeData));
COLLADASaxFWL::instance_force_field__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_force_field__AttributeData::ATTRIBUTE_URI_PRESENT) == COLLADASaxFWL15::instance_force_field__AttributeData::ATTRIBUTE_URI_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_force_field__AttributeData::ATTRIBUTE_URI_PRESENT;
}
return mLoader->begin__instance_force_field(attrData);
}


bool PhysicsModelLoader15::end__instance_force_field()
{
SaxVirtualFunctionTest15(end__instance_force_field());
return mLoader->end__instance_force_field();
}


bool PhysicsModelLoader15::begin__instance_rigid_body( const COLLADASaxFWL15::instance_rigid_body__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_rigid_body(attributeData));
COLLADASaxFWL::instance_rigid_body__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.body = attributeData.body;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_rigid_body__AttributeData::ATTRIBUTE_TARGET_PRESENT) == COLLADASaxFWL15::instance_rigid_body__AttributeData::ATTRIBUTE_TARGET_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_rigid_body__AttributeData::ATTRIBUTE_TARGET_PRESENT;
}
return mLoader->begin__instance_rigid_body(attrData);
}


bool PhysicsModelLoader15::end__instance_rigid_body()
{
SaxVirtualFunctionTest15(end__instance_rigid_body());
return mLoader->end__instance_rigid_body();
}


bool PhysicsModelLoader15::begin__instance_rigid_body_type____technique_common()
{
SaxVirtualFunctionTest15(begin__instance_rigid_body_type____technique_common());
return mLoader->begin__instance_rigid_body__technique_common();
}


bool PhysicsModelLoader15::end__instance_rigid_body_type____technique_common()
{
SaxVirtualFunctionTest15(end__instance_rigid_body_type____technique_common());
return mLoader->end__instance_rigid_body__technique_common();
}


bool PhysicsModelLoader15::begin__angular_velocity()
{
SaxVirtualFunctionTest15(begin__angular_velocity());
return mLoader->begin__angular_velocity();
}


bool PhysicsModelLoader15::end__angular_velocity()
{
SaxVirtualFunctionTest15(end__angular_velocity());
return mLoader->end__angular_velocity();
}


bool PhysicsModelLoader15::data__angular_velocity( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__angular_velocity(data, length));
return mLoader->data__angular_velocity(data, length);
}


bool PhysicsModelLoader15::begin__velocity()
{
SaxVirtualFunctionTest15(begin__velocity());
return mLoader->begin__velocity();
}


bool PhysicsModelLoader15::end__velocity()
{
SaxVirtualFunctionTest15(end__velocity());
return mLoader->end__velocity();
}


bool PhysicsModelLoader15::data__velocity( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__velocity(data, length));
return mLoader->data__velocity(data, length);
}


bool PhysicsModelLoader15::begin__instance_rigid_body__technique_common__dynamic( const COLLADASaxFWL15::instance_rigid_body__technique_common__dynamic__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_rigid_body__technique_common__dynamic(attributeData));
COLLADASaxFWL::instance_rigid_body__technique_common__dynamic__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__instance_rigid_body__technique_common__dynamic(attrData);
}


bool PhysicsModelLoader15::end__instance_rigid_body__technique_common__dynamic()
{
SaxVirtualFunctionTest15(end__instance_rigid_body__technique_common__dynamic());
return mLoader->end__instance_rigid_body__technique_common__dynamic();
}


bool PhysicsModelLoader15::data__instance_rigid_body__technique_common__dynamic( const bool value )
{
SaxVirtualFunctionTest15(data__instance_rigid_body__technique_common__dynamic(value));
return mLoader->data__instance_rigid_body__technique_common__dynamic(value);
}


bool PhysicsModelLoader15::end__instance_rigid_body__technique_common__mass_frame()
{
SaxVirtualFunctionTest15(end__instance_rigid_body__technique_common__mass_frame());
return mLoader->begin__instance_rigid_body__technique_common__mass_frame();
}


bool PhysicsModelLoader15::end__instance_rigid_body__technique_common__mass_frame()
{
SaxVirtualFunctionTest15(end__instance_rigid_body__technique_common__mass_frame());
return mLoader->end__instance_rigid_body__technique_common__mass_frame();
}


bool PhysicsModelLoader15::end__instance_rigid_body__technique_common__shape()
{
SaxVirtualFunctionTest15(end__instance_rigid_body__technique_common__shape());
return mLoader->begin__instance_rigid_body__technique_common__shape();
}


bool PhysicsModelLoader15::end__instance_rigid_body__technique_common__shape()
{
SaxVirtualFunctionTest15(end__instance_rigid_body__technique_common__shape());
return mLoader->end__instance_rigid_body__technique_common__shape();
}


bool PhysicsModelLoader15::begin__instance_rigid_body__technique_common__shape__hollow( const COLLADASaxFWL15::instance_rigid_body__technique_common__shape__hollow__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_rigid_body__technique_common__shape__hollow(attributeData));
COLLADASaxFWL::instance_rigid_body__technique_common__shape__hollow__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__instance_rigid_body__technique_common__shape__hollow(attrData);
}


bool PhysicsModelLoader15::end__instance_rigid_body__technique_common__shape__hollow()
{
SaxVirtualFunctionTest15(end__instance_rigid_body__technique_common__shape__hollow());
return mLoader->end__instance_rigid_body__technique_common__shape__hollow();
}


bool PhysicsModelLoader15::data__instance_rigid_body__technique_common__shape__hollow( const bool value )
{
SaxVirtualFunctionTest15(data__instance_rigid_body__technique_common__shape__hollow(value));
return mLoader->data__instance_rigid_body__technique_common__shape__hollow(value);
}


bool PhysicsModelLoader15::begin__instance_rigid_constraint( const COLLADASaxFWL15::instance_rigid_constraint__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_rigid_constraint(attributeData));
COLLADASaxFWL::instance_rigid_constraint__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
attrData.constraint = attributeData.constraint;
return mLoader->begin__instance_rigid_constraint(attrData);
}


bool PhysicsModelLoader15::end__rigid_constraint()
{
SaxVirtualFunctionTest15(end__rigid_constraint());
return mLoader->end__instanc_rigid_constraint();
}



}
