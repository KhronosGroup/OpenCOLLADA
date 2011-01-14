/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_PHYSICSSCENELOADER15_H__
#define __COLLADASAXFWL_PHYSICSSCENELOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLPhysicsSceneLoader.h"
#include "COLLADASaxFWLPhysicsModelLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class PhysicsSceneLoader15 : public PhysicsModelLoader15
{
private:
PhysicsSceneLoader* mLoader;

public:
PhysicsSceneLoader15(PhysicsSceneLoader* loader)
 : PhysicsModelLoader15(loader)
 , mLoader(loader)
{}


virtual bool end__physics_scene();

virtual bool begin__instance_force_field( const COLLADASaxFWL15::instance_force_field__AttributeData& attributeData );

virtual bool end__instance_force_field();

virtual bool begin__instance_physics_model( const COLLADASaxFWL15::instance_physics_model__AttributeData& attributeData );

virtual bool end__instance_physics_model();

virtual bool begin__physics_scene_type____technique_common();

virtual bool end__physics_scene_type____technique_common();

virtual bool begin__gravity____targetable_float3_type( const COLLADASaxFWL15::gravity____targetable_float3_type__AttributeData& attributeData );

virtual bool end__gravity();

virtual bool data__gravity( const float* data, size_t length );

virtual bool begin__time_step____targetable_float3_type( const COLLADASaxFWL15::time_step____targetable_float3_type__AttributeData& attributeData );

virtual bool end__time_step();

virtual bool data__time_step( const float value );


private:
/** Disable default copy ctor. */
PhysicsSceneLoader15(const PhysicsSceneLoader15&);
/** Disable default assignment operator. */
const PhysicsSceneLoader15& operator=(const PhysicsSceneLoader15&);
};
}
#endif // __COLLADASAXFWL_PHYSICSSCENELOADER15_H__
