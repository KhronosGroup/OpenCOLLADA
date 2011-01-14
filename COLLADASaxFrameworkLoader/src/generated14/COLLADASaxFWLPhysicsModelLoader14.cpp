/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPhysicsModelLoader14.h"


namespace COLLADASaxFWL
{


bool PhysicsModelLoader14::begin__physics_model( const COLLADASaxFWL14::physics_model__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__physics_model(attributeData));
COLLADASaxFWL::physics_model__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_model(attrData);
}


bool PhysicsModelLoader14::end__physics_model()
{
SaxVirtualFunctionTest14(end__physics_model());
return mLoader->end__physics_model();
}


bool PhysicsModelLoader14::begin__rigid_body( const COLLADASaxFWL14::rigid_body__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__rigid_body(attributeData));
COLLADASaxFWL::rigid_body__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
return mLoader->begin__rigid_body(attrData);
}


bool PhysicsModelLoader14::end__rigid_body()
{
SaxVirtualFunctionTest14(end__rigid_body());
return mLoader->end__rigid_body();
}


bool PhysicsModelLoader14::begin__rigid_body__technique_common()
{
SaxVirtualFunctionTest14(begin__rigid_body__technique_common());
return mLoader->begin__rigid_body__technique_common();
}


bool PhysicsModelLoader14::end__rigid_body__technique_common()
{
SaxVirtualFunctionTest14(end__rigid_body__technique_common());
return mLoader->end__rigid_body__technique_common();
}


bool PhysicsModelLoader14::begin__rigid_body__technique_common__dynamic( const COLLADASaxFWL14::rigid_body__technique_common__dynamic__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__rigid_body__technique_common__dynamic(attributeData));
COLLADASaxFWL::rigid_body__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
return mLoader->begin__rigid_body__technique_common__dynamic(attrData);
}


bool PhysicsModelLoader14::end__rigid_body__technique_common__dynamic()
{
SaxVirtualFunctionTest14(end__rigid_body__technique_common__dynamic());
return mLoader->end__rigid_body__technique_common__dynamic();
}


bool PhysicsModelLoader14::data__rigid_body__technique_common__dynamic( const bool value )
{
SaxVirtualFunctionTest14(data__rigid_body__technique_common__dynamic(value));
return mLoader->data__rigid_body__technique_common__dynamic(value);
}


bool PhysicsModelLoader14::begin__mass( const COLLADASaxFWL14::mass__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__mass(attributeData));
COLLADASaxFWL::mass__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__mass(attrData);
}


bool PhysicsModelLoader14::end__mass()
{
SaxVirtualFunctionTest14(end__mass());
return mLoader->end__mass();
}


bool PhysicsModelLoader14::data__mass( const float value )
{
SaxVirtualFunctionTest14(data__mass(value));
return mLoader->data__mass(value);
}


bool PhysicsModelLoader14::begin__rigid_body__technique_common__mass_frame()
{
SaxVirtualFunctionTest14(begin__rigid_body__technique_common__mass_frame());
return mLoader->begin__mass_frame();
}


bool PhysicsModelLoader14::end__rigid_body__technique_common__mass_frame()
{
SaxVirtualFunctionTest14(end__rigid_body__technique_common__mass_frame());
return mLoader->end__mass_frame();
}


bool PhysicsModelLoader14::begin__inertia( const COLLADASaxFWL14::inertia__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__inertia(attributeData));
COLLADASaxFWL::inertia__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__inertia(attrData);
}


bool PhysicsModelLoader14::end__inertia()
{
SaxVirtualFunctionTest14(end__inertia());
return mLoader->end__inertia();
}


bool PhysicsModelLoader14::data__inertia( const float* value, size_t length )
{
SaxVirtualFunctionTest14(data__inertia(value, length));
return mLoader->data__inertia(value, length);
}


bool PhysicsModelLoader14::begin__instance_physics_material( const COLLADASaxFWL14::instance_physics_material__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_physics_material(attributeData));
COLLADASaxFWL::instance_physics_material__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_physics_material__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_physics_material__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_physics_material__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_physics_material(attrData);
}


bool PhysicsModelLoader14::end__instance_physics_material()
{
SaxVirtualFunctionTest14(end__instance_physics_material());
return mLoader->end__instance_physics_material();
}


bool PhysicsModelLoader14::begin__rigid_body__technique_common__shape()
{
SaxVirtualFunctionTest14(begin__rigid_body__technique_common__shape());
return mLoader->begin__shape();
}


bool PhysicsModelLoader14::end__rigid_body__technique_common__shape()
{
SaxVirtualFunctionTest14(end__rigid_body__technique_common__shape());
return mLoader->end__shape();
}


bool PhysicsModelLoader14::begin__rigid_body__technique_common__shape__hollow( const COLLADASaxFWL14::rigid_body__technique_common__shape__hollow__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__rigid_body__technique_common__shape__hollow(attributeData));
COLLADASaxFWL::shape__hollow__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__shape__hollow(attrData);
}


bool PhysicsModelLoader14::end__rigid_body__technique_common__shape__hollow()
{
SaxVirtualFunctionTest14(end__rigid_body__technique_common__shape__hollow());
return mLoader->end__shape__hollow();
}


bool PhysicsModelLoader14::data__rigid_body__technique_common__shape__hollow( const bool value )
{
SaxVirtualFunctionTest14(data__rigid_body__technique_common__shape__hollow(value));
return mLoader->data__shape__hollow(value);
}


bool PhysicsModelLoader14::begin__density( const COLLADASaxFWL14::density__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__density(attributeData));
COLLADASaxFWL::density__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__density(attrData);
}


bool PhysicsModelLoader14::end__density()
{
SaxVirtualFunctionTest14(end__density());
return mLoader->end__density();
}


bool PhysicsModelLoader14::data__density( const float value )
{
SaxVirtualFunctionTest14(data__density(value));
return mLoader->data__density(value);
}


bool PhysicsModelLoader14::begin__plane()
{
SaxVirtualFunctionTest14(begin__plane());
return mLoader->begin__plane();
}


bool PhysicsModelLoader14::end__plane()
{
SaxVirtualFunctionTest14(end__plane());
return mLoader->end__plane();
}


bool PhysicsModelLoader14::begin__equation()
{
SaxVirtualFunctionTest14(begin__equation());
return mLoader->begin__equation();
}


bool PhysicsModelLoader14::end__equation()
{
SaxVirtualFunctionTest14(end__equation());
return mLoader->end__equation();
}


bool PhysicsModelLoader14::data__equation( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__equation(data, length));
return mLoader->data__equation(data, length);
}


bool PhysicsModelLoader14::begin__box()
{
SaxVirtualFunctionTest14(begin__box());
return mLoader->begin__box();
}


bool PhysicsModelLoader14::end__box()
{
SaxVirtualFunctionTest14(end__box());
return mLoader->end__box();
}


bool PhysicsModelLoader14::begin__half_extents()
{
SaxVirtualFunctionTest14(begin__half_extents());
return mLoader->begin__half_extents();
}


bool PhysicsModelLoader14::end__half_extents()
{
SaxVirtualFunctionTest14(end__half_extents());
return mLoader->end__half_extents();
}


bool PhysicsModelLoader14::data__half_extents( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__half_extents(data, length));
return mLoader->data__half_extents(data, length);
}


bool PhysicsModelLoader14::begin__sphere()
{
SaxVirtualFunctionTest14(begin__sphere());
return mLoader->begin__sphere();
}


bool PhysicsModelLoader14::end__sphere()
{
SaxVirtualFunctionTest14(end__sphere());
return mLoader->end__sphere();
}


bool PhysicsModelLoader14::begin__radius____float()
{
SaxVirtualFunctionTest14(begin__radius____float());
return mLoader->begin__radius___float();
}


bool PhysicsModelLoader14::end__radius____float()
{
SaxVirtualFunctionTest14(end__radius____float());
return mLoader->end__radius___float();
}


bool PhysicsModelLoader14::data__radius____float( const float value )
{
SaxVirtualFunctionTest14(data__radius____float(value));
return mLoader->data__radius___float(value);
}


bool PhysicsModelLoader14::begin__cylinder()
{
SaxVirtualFunctionTest14(begin__cylinder());
return mLoader->begin__cylinder();
}


bool PhysicsModelLoader14::end__cylinder()
{
SaxVirtualFunctionTest14(end__cylinder());
return mLoader->end__cylinder();
}


bool PhysicsModelLoader14::begin__height()
{
SaxVirtualFunctionTest14(begin__height());
return mLoader->begin__height();
}


bool PhysicsModelLoader14::end__height()
{
SaxVirtualFunctionTest14(end__height());
return mLoader->end__height();
}


bool PhysicsModelLoader14::data__height( const float value )
{
SaxVirtualFunctionTest14(data__height(value));
return mLoader->data__height(value);
}


bool PhysicsModelLoader14::begin__radius____float2()
{
SaxVirtualFunctionTest14(begin__radius____float2());
return mLoader->begin__radius___float2();
}


bool PhysicsModelLoader14::end__radius____float2()
{
SaxVirtualFunctionTest14(end__radius____float2());
return mLoader->end__radius___float2();
}


bool PhysicsModelLoader14::data__radius____float2( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__radius____float2(data, length));
return mLoader->data__radius___float2(data, length);
}


bool PhysicsModelLoader14::begin__capsule()
{
SaxVirtualFunctionTest14(begin__capsule());
return mLoader->begin__capsule();
}


bool PhysicsModelLoader14::end__capsule()
{
SaxVirtualFunctionTest14(end__capsule());
return mLoader->end__capsule();
}


bool PhysicsModelLoader14::begin__radius____float3()
{
SaxVirtualFunctionTest14(begin__radius____float3());
return mLoader->begin__radius___float3();
}


bool PhysicsModelLoader14::end__radius____float3()
{
SaxVirtualFunctionTest14(end__radius____float3());
return mLoader->end__radius___float3();
}


bool PhysicsModelLoader14::data__radius____float3( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__radius____float3(data, length));
return mLoader->data__radius___float3(data, length);
}


bool PhysicsModelLoader14::begin__instance_geometry( const COLLADASaxFWL14::instance_geometry__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_geometry(attributeData));
COLLADASaxFWL::instance_geometry__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_geometry(attrData);
}


bool PhysicsModelLoader14::end__instance_geometry()
{
SaxVirtualFunctionTest14(end__instance_geometry());
return mLoader->end__instance_geometry();
}


bool PhysicsModelLoader14::begin__rigid_constraint( const COLLADASaxFWL14::rigid_constraint__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__rigid_constraint(attributeData));
COLLADASaxFWL::rigid_constraint__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
return mLoader->begin__rigid_constraint(attrData);
}


bool PhysicsModelLoader14::end__rigid_constraint()
{
SaxVirtualFunctionTest14(end__rigid_constraint());
return mLoader->end__rigid_constraint();
}


bool PhysicsModelLoader14::begin__ref_attachment( const COLLADASaxFWL14::ref_attachment__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__ref_attachment(attributeData));
COLLADASaxFWL::ref_attachment__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL14::ref_attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT) == COLLADASaxFWL14::ref_attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT ) {
    attrData.rigid_body = attributeData.rigid_body;
    attrData.present_attributes |= COLLADASaxFWL::ref_attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT;
}
return mLoader->begin__ref_attachment(attrData);
}


bool PhysicsModelLoader14::end__ref_attachment()
{
SaxVirtualFunctionTest14(end__ref_attachment());
return mLoader->end__ref_attachment();
}


bool PhysicsModelLoader14::begin__attachment( const COLLADASaxFWL14::attachment__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__attachment(attributeData));
COLLADASaxFWL::attachment__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL14::attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT) == COLLADASaxFWL14::attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT ) {
    attrData.rigid_body = attributeData.rigid_body;
    attrData.present_attributes |= COLLADASaxFWL::attachment__AttributeData::ATTRIBUTE_RIGID_BODY_PRESENT;
}
return mLoader->begin__attachment(attrData);
}


bool PhysicsModelLoader14::end__attachment()
{
SaxVirtualFunctionTest14(end__attachment());
return mLoader->end__attachment();
}


bool PhysicsModelLoader14::begin__translate( const COLLADASaxFWL14::translate__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__translate(attributeData));
COLLADASaxFWL::translate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__translate(attrData);
}


bool PhysicsModelLoader14::end__translate()
{
SaxVirtualFunctionTest14(end__translate());
return mLoader->end__translate();
}


bool PhysicsModelLoader14::data__translate( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__translate(data, length));
return mLoader->data__translate(data, length);
}


bool PhysicsModelLoader14::begin__rotate( const COLLADASaxFWL14::rotate__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__rotate(attributeData));
COLLADASaxFWL::rotate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__rotate(attrData);
}


bool PhysicsModelLoader14::end__rotate()
{
SaxVirtualFunctionTest14(end__rotate());
return mLoader->end__rotate();
}


bool PhysicsModelLoader14::data__rotate( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__rotate(data, length));
return mLoader->data__rotate(data, length);
}


bool PhysicsModelLoader14::begin__rigid_constraint__technique_common()
{
SaxVirtualFunctionTest14(begin__rigid_constraint__technique_common());
return mLoader->begin__rigid_constraint__technique_common();
}


bool PhysicsModelLoader14::end__instance_rigid_body__technique_common()
{
SaxVirtualFunctionTest14(end__instance_rigid_body__technique_common());
return mLoader->end__instance_rigid_body__technique_common();
}


bool PhysicsModelLoader14::begin__enabled( const COLLADASaxFWL14::enabled__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__enabled(attributeData));
COLLADASaxFWL::enabled__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__enabled(attrData);
}


bool PhysicsModelLoader14::end__enabled()
{
SaxVirtualFunctionTest14(end__enabled());
return mLoader->end__enabled();
}


bool PhysicsModelLoader14::data__enabled( const bool value )
{
SaxVirtualFunctionTest14(data__enabled(value));
return mLoader->data__enabled(value);
}


bool PhysicsModelLoader14::begin__interpenetrate( const COLLADASaxFWL14::interpenetrate__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__interpenetrate(attributeData));
COLLADASaxFWL::interpenetrate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__interpenetrate(attrData);
}


bool PhysicsModelLoader14::end__interpenetrate()
{
SaxVirtualFunctionTest14(end__interpenetrate());
return mLoader->end__interpenetrate();
}


bool PhysicsModelLoader14::data__interpenetrate( const bool value )
{
SaxVirtualFunctionTest14(data__interpenetrate(value));
return mLoader->data__interpenetrate(value);
}


bool PhysicsModelLoader14::begin__limits()
{
SaxVirtualFunctionTest14(begin__limits());
return mLoader->begin__limits();
}


bool PhysicsModelLoader14::end__limits()
{
SaxVirtualFunctionTest14(end__limits());
return mLoader->end__limits();
}


bool PhysicsModelLoader14::begin__swing_cone_and_twist()
{
SaxVirtualFunctionTest14(begin__swing_cone_and_twist());
return mLoader->begin__swing_cone_and_twist();
}


bool PhysicsModelLoader14::end__swing_cone_and_twist()
{
SaxVirtualFunctionTest14(end__swing_cone_and_twist());
return mLoader->end__swing_cone_and_twist();
}


bool PhysicsModelLoader14::begin__min( const COLLADASaxFWL14::min__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__min(attributeData));
COLLADASaxFWL::min__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__min(attrData);
}


bool PhysicsModelLoader14::end__min()
{
SaxVirtualFunctionTest14(end__min());
return mLoader->end__min();
}


bool PhysicsModelLoader14::data__min( const float* value, size_t length )
{
SaxVirtualFunctionTest14(data__min(value, length));
return mLoader->data__min(value, length);
}


bool PhysicsModelLoader14::begin__max( const COLLADASaxFWL14::max__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__max(attributeData));
COLLADASaxFWL::max__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__max(attrData);
}


bool PhysicsModelLoader14::end__max()
{
SaxVirtualFunctionTest14(end__max());
return mLoader->end__max();
}


bool PhysicsModelLoader14::data__max( const float* value, size_t length )
{
SaxVirtualFunctionTest14(data__max(value, length));
return mLoader->data__max(value, length);
}


bool PhysicsModelLoader14::begin__spring()
{
SaxVirtualFunctionTest14(begin__spring());
return mLoader->begin__spring();
}


bool PhysicsModelLoader14::end__spring()
{
SaxVirtualFunctionTest14(end__spring());
return mLoader->end__spring();
}


bool PhysicsModelLoader14::begin__limits__linear()
{
SaxVirtualFunctionTest14(begin__limits__linear());
return mLoader->begin__limits__linear();
}


bool PhysicsModelLoader14::end__limits__linear()
{
SaxVirtualFunctionTest14(end__limits__linear());
return mLoader->end__limits__linear();
}


bool PhysicsModelLoader14::begin__angular()
{
SaxVirtualFunctionTest14(begin__angular());
return mLoader->begin__angular();
}


bool PhysicsModelLoader14::end__angular()
{
SaxVirtualFunctionTest14(end__angular());
return mLoader->end__angular();
}


bool PhysicsModelLoader14::begin__stiffness( const COLLADASaxFWL14::stiffness__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__stiffness(attributeData));
COLLADASaxFWL::stiffness__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__stiffness(attrData);
}


bool PhysicsModelLoader14::end__stiffness()
{
SaxVirtualFunctionTest14(end__stiffness());
return mLoader->end__stiffness();
}


bool PhysicsModelLoader14::data__stiffness( const float value )
{
SaxVirtualFunctionTest14(data__stiffness(value));
return mLoader->data__stiffness(value);
}


bool PhysicsModelLoader14::begin__damping( const COLLADASaxFWL14::damping__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__damping(attributeData));
COLLADASaxFWL::damping__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__damping(attrData);
}


bool PhysicsModelLoader14::end__damping()
{
SaxVirtualFunctionTest14(end__damping());
return mLoader->end__damping();
}


bool PhysicsModelLoader14::data__damping( const float value )
{
SaxVirtualFunctionTest14(data__damping(value));
return mLoader->data__damping(value);
}


bool PhysicsModelLoader14::begin__target_value( const COLLADASaxFWL14::target_value__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__target_value(attributeData));
COLLADASaxFWL::target_value__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__target_value(attrData);
}


bool PhysicsModelLoader14::end__target_value()
{
SaxVirtualFunctionTest14(end__target_value());
return mLoader->end__target_value();
}


bool PhysicsModelLoader14::data__target_value( const float value )
{
SaxVirtualFunctionTest14(data__target_value(value));
return mLoader->data__target_value(value);
}


bool PhysicsModelLoader14::begin__spring__linear()
{
SaxVirtualFunctionTest14(begin__spring__linear());
return mLoader->begin__spring__linear();
}


bool PhysicsModelLoader14::end__spring__linear()
{
SaxVirtualFunctionTest14(end__spring__linear());
return mLoader->end__spring__linear();
}


bool PhysicsModelLoader14::begin__instance_physics_model( const COLLADASaxFWL14::instance_physics_model__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_physics_model(attributeData));
COLLADASaxFWL::instance_physics_model__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_physics_model__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_physics_model__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_physics_model__AttributeData::ATTRIBUTE_URL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_physics_model__AttributeData::ATTRIBUTE_PARENT_PRESENT) == COLLADASaxFWL14::instance_physics_model__AttributeData::ATTRIBUTE_PARENT_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_physics_model__AttributeData::ATTRIBUTE_PARENT_PRESENT;
}
return mLoader->begin__instance_physics_model(attrData);
}


bool PhysicsModelLoader14::end__instance_physics_model()
{
SaxVirtualFunctionTest14(end__instance_physics_model());
return mLoader->end__instance_physics_model();
}


bool PhysicsModelLoader14::begin__instance_force_field( const COLLADASaxFWL14::instance_force_field__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_force_field(attributeData));
COLLADASaxFWL::instance_force_field__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_force_field__AttributeData::ATTRIBUTE_URI_PRESENT) == COLLADASaxFWL14::instance_force_field__AttributeData::ATTRIBUTE_URI_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_force_field__AttributeData::ATTRIBUTE_URI_PRESENT;
}
return mLoader->begin__instance_force_field(attrData);
}


bool PhysicsModelLoader14::end__instance_force_field()
{
SaxVirtualFunctionTest14(end__instance_force_field());
return mLoader->end__instance_force_field();
}


bool PhysicsModelLoader14::begin__instance_rigid_body( const COLLADASaxFWL14::instance_rigid_body__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_rigid_body(attributeData));
COLLADASaxFWL::instance_rigid_body__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.body = attributeData.body;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_rigid_body__AttributeData::ATTRIBUTE_TARGET_PRESENT) == COLLADASaxFWL14::instance_rigid_body__AttributeData::ATTRIBUTE_TARGET_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_rigid_body__AttributeData::ATTRIBUTE_TARGET_PRESENT;
}
return mLoader->begin__instance_rigid_body(attrData);
}


bool PhysicsModelLoader14::end__instance_rigid_body()
{
SaxVirtualFunctionTest14(end__instance_rigid_body());
return mLoader->end__instance_rigid_body();
}


bool PhysicsModelLoader14::begin__instance_rigid_body__technique_common()
{
SaxVirtualFunctionTest14(begin__instance_rigid_body__technique_common());
return mLoader->begin__instance_rigid_body__technique_common();
}


bool PhysicsModelLoader14::end__instance_rigid_body__technique_common()
{
SaxVirtualFunctionTest14(end__instance_rigid_body__technique_common());
return mLoader->end__instance_rigid_body__technique_common();
}


bool PhysicsModelLoader14::begin__angular_velocity()
{
SaxVirtualFunctionTest14(begin__angular_velocity());
return mLoader->begin__angular_velocity();
}


bool PhysicsModelLoader14::end__angular_velocity()
{
SaxVirtualFunctionTest14(end__angular_velocity());
return mLoader->end__angular_velocity();
}


bool PhysicsModelLoader14::data__angular_velocity( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__angular_velocity(data, length));
return mLoader->data__angular_velocity(data, length);
}


bool PhysicsModelLoader14::begin__velocity()
{
SaxVirtualFunctionTest14(begin__velocity());
return mLoader->begin__velocity();
}


bool PhysicsModelLoader14::end__velocity()
{
SaxVirtualFunctionTest14(end__velocity());
return mLoader->end__velocity();
}


bool PhysicsModelLoader14::data__velocity( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__velocity(data, length));
return mLoader->data__velocity(data, length);
}


bool PhysicsModelLoader14::begin__instance_rigid_body__technique_common__dynamic( const COLLADASaxFWL14::instance_rigid_body__technique_common__dynamic__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_rigid_body__technique_common__dynamic(attributeData));
COLLADASaxFWL::instance_rigid_body__technique_common__dynamic__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__instance_rigid_body__technique_common__dynamic(attrData);
}


bool PhysicsModelLoader14::end__instance_rigid_body__technique_common__dynamic()
{
SaxVirtualFunctionTest14(end__instance_rigid_body__technique_common__dynamic());
return mLoader->end__instance_rigid_body__technique_common__dynamic();
}


bool PhysicsModelLoader14::data__instance_rigid_body__technique_common__dynamic( const bool value )
{
SaxVirtualFunctionTest14(data__instance_rigid_body__technique_common__dynamic(value));
return mLoader->data__instance_rigid_body__technique_common__dynamic(value);
}


bool PhysicsModelLoader14::end__instance_rigid_body__technique_common__mass_frame()
{
SaxVirtualFunctionTest14(end__instance_rigid_body__technique_common__mass_frame());
return mLoader->begin__instance_rigid_body__technique_common__mass_frame();
}


bool PhysicsModelLoader14::end__instance_rigid_body__technique_common__mass_frame()
{
SaxVirtualFunctionTest14(end__instance_rigid_body__technique_common__mass_frame());
return mLoader->end__instance_rigid_body__technique_common__mass_frame();
}


bool PhysicsModelLoader14::end__instance_rigid_body__technique_common__shape()
{
SaxVirtualFunctionTest14(end__instance_rigid_body__technique_common__shape());
return mLoader->begin__instance_rigid_body__technique_common__shape();
}


bool PhysicsModelLoader14::end__instance_rigid_body__technique_common__shape()
{
SaxVirtualFunctionTest14(end__instance_rigid_body__technique_common__shape());
return mLoader->end__instance_rigid_body__technique_common__shape();
}


bool PhysicsModelLoader14::begin__instance_rigid_body__technique_common__shape__hollow( const COLLADASaxFWL14::instance_rigid_body__technique_common__shape__hollow__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_rigid_body__technique_common__shape__hollow(attributeData));
COLLADASaxFWL::instance_rigid_body__technique_common__shape__hollow__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__instance_rigid_body__technique_common__shape__hollow(attrData);
}


bool PhysicsModelLoader14::end__instance_rigid_body__technique_common__shape__hollow()
{
SaxVirtualFunctionTest14(end__instance_rigid_body__technique_common__shape__hollow());
return mLoader->end__instance_rigid_body__technique_common__shape__hollow();
}


bool PhysicsModelLoader14::data__instance_rigid_body__technique_common__shape__hollow( const bool value )
{
SaxVirtualFunctionTest14(data__instance_rigid_body__technique_common__shape__hollow(value));
return mLoader->data__instance_rigid_body__technique_common__shape__hollow(value);
}


bool PhysicsModelLoader14::begin__instance_rigid_constraint( const COLLADASaxFWL14::instance_rigid_constraint__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_rigid_constraint(attributeData));
COLLADASaxFWL::instance_rigid_constraint__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
attrData.constraint = attributeData.constraint;
return mLoader->begin__instance_rigid_constraint(attrData);
}


bool PhysicsModelLoader14::end__rigid_constraint()
{
SaxVirtualFunctionTest14(end__rigid_constraint());
return mLoader->end__instanc_rigid_constraint();
}



}
