/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_PHYSICSSCENELOADER14_H__
#define __COLLADASAXFWL_PHYSICSSCENELOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLPhysicsSceneLoader.h"
#include "COLLADASaxFWLPhysicsModelLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class PhysicsSceneLoader14 : public PhysicsModelLoader14
{
private:
PhysicsSceneLoader* mLoader;

public:
PhysicsSceneLoader14(PhysicsSceneLoader* loader)
 : PhysicsModelLoader14(loader)
 , mLoader(loader)
{}


virtual bool end__physics_scene();

virtual bool begin__instance_force_field( const COLLADASaxFWL14::instance_force_field__AttributeData& attributeData );

virtual bool end__instance_force_field();

virtual bool begin__instance_physics_model( const COLLADASaxFWL14::instance_physics_model__AttributeData& attributeData );

virtual bool end__instance_physics_model();

virtual bool begin__physics_scene__technique_common();

virtual bool end__physics_scene__technique_common();

virtual bool begin__gravity( const COLLADASaxFWL14::gravity__AttributeData& attributeData );

virtual bool end__gravity();

virtual bool data__gravity( const float* data, size_t length );

virtual bool begin__time_step( const COLLADASaxFWL14::time_step__AttributeData& attributeData );

virtual bool end__time_step();

virtual bool data__time_step( const float value );


private:
/** Disable default copy ctor. */
PhysicsSceneLoader14(const PhysicsSceneLoader14&);
/** Disable default assignment operator. */
const PhysicsSceneLoader14& operator=(const PhysicsSceneLoader14&);
};
}
#endif // __COLLADASAXFWL_PHYSICSSCENELOADER14_H__
