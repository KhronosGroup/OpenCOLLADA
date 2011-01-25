/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_PHYSICSMODELLOADER15_H__
#define __COLLADASAXFWL_PHYSICSMODELLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLPhysicsModelLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class PhysicsModelLoader15 : public IParserImpl15
{
private:
PhysicsModelLoader* mLoader;

public:
PhysicsModelLoader15(PhysicsModelLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__physics_model( const COLLADASaxFWL15::physics_model__AttributeData& attributeData );

virtual bool end__physics_model();

virtual bool begin__rigid_body( const COLLADASaxFWL15::rigid_body__AttributeData& attributeData );

virtual bool end__rigid_body();

virtual bool begin__rigid_body_type____technique_common();

virtual bool end__rigid_body_type____technique_common();

virtual bool begin__rigid_body__technique_common__dynamic( const COLLADASaxFWL15::rigid_body__technique_common__dynamic__AttributeData& attributeData );

virtual bool end__rigid_body__technique_common__dynamic();

virtual bool data__rigid_body__technique_common__dynamic( bool value );

virtual bool begin__mass( const COLLADASaxFWL15::mass__AttributeData& attributeData );

virtual bool end__mass();

virtual bool data__mass( float value );

//virtual bool begin__rigid_body__technique_common__mass_frame();
//
//virtual bool end__rigid_body__technique_common__mass_frame();
//
//virtual bool begin__inertia( const COLLADASaxFWL15::inertia__AttributeData& attributeData );
//
//virtual bool end__inertia();
//
//virtual bool data__inertia( const float* value, size_t length );
//
//virtual bool begin__instance_physics_material( const COLLADASaxFWL15::instance_physics_material__AttributeData& attributeData );
//
//virtual bool end__instance_physics_material();
//
//virtual bool begin__rigid_body__technique_common__shape();
//
//virtual bool end__rigid_body__technique_common__shape();
//
//virtual bool begin__rigid_body__technique_common__shape__hollow( const COLLADASaxFWL15::rigid_body__technique_common__shape__hollow__AttributeData& attributeData );
//
//virtual bool end__rigid_body__technique_common__shape__hollow();
//
//virtual bool data__rigid_body__technique_common__shape__hollow( const bool value );
//
//virtual bool begin__density( const COLLADASaxFWL15::density__AttributeData& attributeData );
//
//virtual bool end__density();
//
//virtual bool data__density( const float value );
//
//virtual bool begin__plane();
//
//virtual bool end__plane();
//
//virtual bool begin__equation();
//
//virtual bool end__equation();
//
//virtual bool data__equation( const float* data, size_t length );
//
//virtual bool begin__box();
//
//virtual bool end__box();
//
//virtual bool begin__half_extents();
//
//virtual bool end__half_extents();
//
//virtual bool data__half_extents( const float* data, size_t length );
//
//virtual bool begin__sphere();
//
//virtual bool end__sphere();
//
//virtual bool begin__radius____float_type();
//
//virtual bool end__radius____float_type();
//
//virtual bool data__radius____float_type( const float value );
//
//virtual bool begin__cylinder____cylinder_type();
//
//virtual bool end__cylinder____cylinder_type();
//
//virtual bool begin__height();
//
//virtual bool end__height();
//
//virtual bool data__height( const float value );
//
//virtual bool begin__radius____float2_type();
//
//virtual bool end__radius____float2_type();
//
//virtual bool data__radius____float2_type( const float* data, size_t length );
//
//virtual bool begin__capsule();
//
//virtual bool end__capsule();
//
//virtual bool begin__radius____float3_type();
//
//virtual bool end__radius____float3_type();
//
//virtual bool data__radius____float3_type( const float* data, size_t length );
//
//virtual bool begin__instance_geometry( const COLLADASaxFWL15::instance_geometry__AttributeData& attributeData );
//
//virtual bool end__instance_geometry();
//
//virtual bool begin__rigid_constraint( const COLLADASaxFWL15::rigid_constraint__AttributeData& attributeData );
//
//virtual bool end__rigid_constraint();
//
//virtual bool begin__ref_attachment( const COLLADASaxFWL15::ref_attachment__AttributeData& attributeData );
//
//virtual bool end__ref_attachment();
//
//virtual bool begin__attachment( const COLLADASaxFWL15::attachment__AttributeData& attributeData );
//
//virtual bool end__attachment();
//
//virtual bool begin__translate( const COLLADASaxFWL15::translate__AttributeData& attributeData );
//
//virtual bool end__translate();
//
//virtual bool data__translate( const float* data, size_t length );
//
//virtual bool begin__rotate( const COLLADASaxFWL15::rotate__AttributeData& attributeData );
//
//virtual bool end__rotate();
//
//virtual bool data__rotate( const float* data, size_t length );
//
//virtual bool begin__rigid_constraint____technique_common();
//
//virtual bool end__rigid_constraint____technique_common();
//
//virtual bool begin__enabled( const COLLADASaxFWL15::enabled__AttributeData& attributeData );
//
//virtual bool end__enabled();
//
//virtual bool data__enabled( const bool value );
//
//virtual bool begin__interpenetrate( const COLLADASaxFWL15::interpenetrate__AttributeData& attributeData );
//
//virtual bool end__interpenetrate();
//
//virtual bool data__interpenetrate( const bool value );
//
//virtual bool begin__rigid_constraint__technique_common__limits();
//
//virtual bool end__rigid_constraint__technique_common__limits();
//
//virtual bool begin__swing_cone_and_twist();
//
//virtual bool end__swing_cone_and_twist();
//
//virtual bool begin__min____targetable_float3_type( const COLLADASaxFWL15::min____targetable_float3_type__AttributeData& attributeData );
//
//virtual bool end__min____targetable_float3_type();
//
//virtual bool data__min____targetable_float3_type( const float* value, size_t length );
//
//virtual bool begin__max____targetable_float3_type( const COLLADASaxFWL15::max____targetable_float3_type__AttributeData& attributeData );
//
//virtual bool end__max____targetable_float3_type();
//
//virtual bool data__max____targetable_float3_type( const float* value, size_t length );
//
//virtual bool begin__spring();
//
//virtual bool end__spring();
//
//virtual bool begin__rigid_constraint__technique_common__limits__linear();
//
//virtual bool end__rigid_constraint__technique_common__limits__linear();
//
//virtual bool begin__angular();
//
//virtual bool end__angular();
//
//virtual bool begin__stiffness____targetable_float3_type( const COLLADASaxFWL15::stiffness__AttributeData& attributeData );
//
//virtual bool end__stiffness();
//
//virtual bool data__stiffness( const float value );
//
//virtual bool begin__damping____targetable_float3_type( const COLLADASaxFWL15::damping__AttributeData& attributeData );
//
//virtual bool end__damping();
//
//virtual bool data__damping( const float value );
//
//virtual bool begin__target_value____targetable_float3_type( const COLLADASaxFWL15::target_value__AttributeData& attributeData );
//
//virtual bool end__target_value();
//
//virtual bool data__target_value( const float value );
//
//virtual bool begin__spring__linear();
//
//virtual bool end__spring__linear();
//
//virtual bool begin__instance_physics_model( const COLLADASaxFWL15::instance_physics_model__AttributeData& attributeData );
//
//virtual bool end__instance_physics_model();
//
//virtual bool begin__instance_force_field( const COLLADASaxFWL15::instance_force_field__AttributeData& attributeData );
//
//virtual bool end__instance_force_field();
//
//virtual bool begin__instance_rigid_body( const COLLADASaxFWL15::instance_rigid_body__AttributeData& attributeData );
//
//virtual bool end__instance_rigid_body();
//
//virtual bool begin__instance_rigid_body_type____technique_common();
//
//virtual bool end__instance_rigid_body_type____technique_common();
//
//virtual bool begin__angular_velocity();
//
//virtual bool end__angular_velocity();
//
//virtual bool data__angular_velocity( const float* data, size_t length );
//
//virtual bool begin__velocity();
//
//virtual bool end__velocity();
//
//virtual bool data__velocity( const float* data, size_t length );
//
//virtual bool begin__instance_rigid_body__technique_common__dynamic( const COLLADASaxFWL15::instance_rigid_body__technique_common__dynamic__AttributeData& attributeData );
//
//virtual bool end__instance_rigid_body__technique_common__dynamic();
//
//virtual bool data__instance_rigid_body__technique_common__dynamic( const bool value );
//
//virtual bool begin__instance_rigid_body__technique_common__mass_frame();
//
//virtual bool end__instance_rigid_body__technique_common__mass_frame();
//
//virtual bool begin__instance_rigid_body__technique_common__shape();
//
//virtual bool end__instance_rigid_body__technique_common__shape();
//
//virtual bool begin__instance_rigid_body__technique_common__shape__hollow( const COLLADASaxFWL15::instance_rigid_body__technique_common__shape__hollow__AttributeData& attributeData );
//
//virtual bool end__instance_rigid_body__technique_common__shape__hollow();
//
//virtual bool data__instance_rigid_body__technique_common__shape__hollow( const bool value );
//
//virtual bool begin__instance_rigid_constraint( const COLLADASaxFWL15::instance_rigid_constraint__AttributeData& attributeData );
//
//virtual bool end__rigid_constraint();


private:
/** Disable default copy ctor. */
PhysicsModelLoader15(const PhysicsModelLoader15&);
/** Disable default assignment operator. */
const PhysicsModelLoader15& operator=(const PhysicsModelLoader15&);
};
}
#endif // __COLLADASAXFWL_PHYSICSMODELLOADER15_H__
