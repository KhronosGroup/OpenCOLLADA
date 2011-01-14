/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_PHYSICSMODELLOADER14_H__
#define __COLLADASAXFWL_PHYSICSMODELLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLPhysicsModelLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class PhysicsModelLoader14 : public IParserImpl14
{
private:
PhysicsModelLoader* mLoader;

public:
PhysicsModelLoader14(PhysicsModelLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__physics_model( const COLLADASaxFWL14::physics_model__AttributeData& attributeData );

virtual bool end__physics_model();

virtual bool begin__rigid_body( const COLLADASaxFWL14::rigid_body__AttributeData& attributeData );

virtual bool end__rigid_body();

virtual bool begin__rigid_body__technique_common();

virtual bool end__rigid_body__technique_common();

virtual bool begin__rigid_body__technique_common__dynamic( const COLLADASaxFWL14::rigid_body__technique_common__dynamic__AttributeData& attributeData );

virtual bool end__rigid_body__technique_common__dynamic();

virtual bool data__rigid_body__technique_common__dynamic( const bool value );

virtual bool begin__mass( const COLLADASaxFWL14::mass__AttributeData& attributeData );

virtual bool end__mass();

virtual bool data__mass( const float value );

virtual bool begin__rigid_body__technique_common__mass_frame();

virtual bool end__rigid_body__technique_common__mass_frame();

virtual bool begin__inertia( const COLLADASaxFWL14::inertia__AttributeData& attributeData );

virtual bool end__inertia();

virtual bool data__inertia( const float* value, size_t length );

virtual bool begin__instance_physics_material( const COLLADASaxFWL14::instance_physics_material__AttributeData& attributeData );

virtual bool end__instance_physics_material();

virtual bool begin__rigid_body__technique_common__shape();

virtual bool end__rigid_body__technique_common__shape();

virtual bool begin__rigid_body__technique_common__shape__hollow( const COLLADASaxFWL14::rigid_body__technique_common__shape__hollow__AttributeData& attributeData );

virtual bool end__rigid_body__technique_common__shape__hollow();

virtual bool data__rigid_body__technique_common__shape__hollow( const bool value );

virtual bool begin__density( const COLLADASaxFWL14::density__AttributeData& attributeData );

virtual bool end__density();

virtual bool data__density( const float value );

virtual bool begin__plane();

virtual bool end__plane();

virtual bool begin__equation();

virtual bool end__equation();

virtual bool data__equation( const float* data, size_t length );

virtual bool begin__box();

virtual bool end__box();

virtual bool begin__half_extents();

virtual bool end__half_extents();

virtual bool data__half_extents( const float* data, size_t length );

virtual bool begin__sphere();

virtual bool end__sphere();

virtual bool begin__radius____float();

virtual bool end__radius____float();

virtual bool data__radius____float( const float value );

virtual bool begin__cylinder();

virtual bool end__cylinder();

virtual bool begin__height();

virtual bool end__height();

virtual bool data__height( const float value );

virtual bool begin__radius____float2();

virtual bool end__radius____float2();

virtual bool data__radius____float2( const float* data, size_t length );

virtual bool begin__capsule();

virtual bool end__capsule();

virtual bool begin__radius____float3();

virtual bool end__radius____float3();

virtual bool data__radius____float3( const float* data, size_t length );

virtual bool begin__instance_geometry( const COLLADASaxFWL14::instance_geometry__AttributeData& attributeData );

virtual bool end__instance_geometry();

virtual bool begin__rigid_constraint( const COLLADASaxFWL14::rigid_constraint__AttributeData& attributeData );

virtual bool end__rigid_constraint();

virtual bool begin__ref_attachment( const COLLADASaxFWL14::ref_attachment__AttributeData& attributeData );

virtual bool end__ref_attachment();

virtual bool begin__attachment( const COLLADASaxFWL14::attachment__AttributeData& attributeData );

virtual bool end__attachment();

virtual bool begin__translate( const COLLADASaxFWL14::translate__AttributeData& attributeData );

virtual bool end__translate();

virtual bool data__translate( const float* data, size_t length );

virtual bool begin__rotate( const COLLADASaxFWL14::rotate__AttributeData& attributeData );

virtual bool end__rotate();

virtual bool data__rotate( const float* data, size_t length );

virtual bool begin__rigid_constraint__technique_common();

virtual bool end__instance_rigid_body__technique_common();

virtual bool begin__enabled( const COLLADASaxFWL14::enabled__AttributeData& attributeData );

virtual bool end__enabled();

virtual bool data__enabled( const bool value );

virtual bool begin__interpenetrate( const COLLADASaxFWL14::interpenetrate__AttributeData& attributeData );

virtual bool end__interpenetrate();

virtual bool data__interpenetrate( const bool value );

virtual bool begin__limits();

virtual bool end__limits();

virtual bool begin__swing_cone_and_twist();

virtual bool end__swing_cone_and_twist();

virtual bool begin__min( const COLLADASaxFWL14::min__AttributeData& attributeData );

virtual bool end__min();

virtual bool data__min( const float* value, size_t length );

virtual bool begin__max( const COLLADASaxFWL14::max__AttributeData& attributeData );

virtual bool end__max();

virtual bool data__max( const float* value, size_t length );

virtual bool begin__spring();

virtual bool end__spring();

virtual bool begin__limits__linear();

virtual bool end__limits__linear();

virtual bool begin__angular();

virtual bool end__angular();

virtual bool begin__stiffness( const COLLADASaxFWL14::stiffness__AttributeData& attributeData );

virtual bool end__stiffness();

virtual bool data__stiffness( const float value );

virtual bool begin__damping( const COLLADASaxFWL14::damping__AttributeData& attributeData );

virtual bool end__damping();

virtual bool data__damping( const float value );

virtual bool begin__target_value( const COLLADASaxFWL14::target_value__AttributeData& attributeData );

virtual bool end__target_value();

virtual bool data__target_value( const float value );

virtual bool begin__spring__linear();

virtual bool end__spring__linear();

virtual bool begin__instance_physics_model( const COLLADASaxFWL14::instance_physics_model__AttributeData& attributeData );

virtual bool end__instance_physics_model();

virtual bool begin__instance_force_field( const COLLADASaxFWL14::instance_force_field__AttributeData& attributeData );

virtual bool end__instance_force_field();

virtual bool begin__instance_rigid_body( const COLLADASaxFWL14::instance_rigid_body__AttributeData& attributeData );

virtual bool end__instance_rigid_body();

virtual bool begin__instance_rigid_body__technique_common();

virtual bool end__instance_rigid_body__technique_common();

virtual bool begin__angular_velocity();

virtual bool end__angular_velocity();

virtual bool data__angular_velocity( const float* data, size_t length );

virtual bool begin__velocity();

virtual bool end__velocity();

virtual bool data__velocity( const float* data, size_t length );

virtual bool begin__instance_rigid_body__technique_common__dynamic( const COLLADASaxFWL14::instance_rigid_body__technique_common__dynamic__AttributeData& attributeData );

virtual bool end__instance_rigid_body__technique_common__dynamic();

virtual bool data__instance_rigid_body__technique_common__dynamic( const bool value );

virtual bool end__instance_rigid_body__technique_common__mass_frame();

virtual bool end__instance_rigid_body__technique_common__mass_frame();

virtual bool end__instance_rigid_body__technique_common__shape();

virtual bool end__instance_rigid_body__technique_common__shape();

virtual bool begin__instance_rigid_body__technique_common__shape__hollow( const COLLADASaxFWL14::instance_rigid_body__technique_common__shape__hollow__AttributeData& attributeData );

virtual bool end__instance_rigid_body__technique_common__shape__hollow();

virtual bool data__instance_rigid_body__technique_common__shape__hollow( const bool value );

virtual bool begin__instance_rigid_constraint( const COLLADASaxFWL14::instance_rigid_constraint__AttributeData& attributeData );

virtual bool end__rigid_constraint();


private:
/** Disable default copy ctor. */
PhysicsModelLoader14(const PhysicsModelLoader14&);
/** Disable default assignment operator. */
const PhysicsModelLoader14& operator=(const PhysicsModelLoader14&);
};
}
#endif // __COLLADASAXFWL_PHYSICSMODELLOADER14_H__
