/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPhysicsSceneLoader14.h"


namespace COLLADASaxFWL
{


bool PhysicsSceneLoader14::end__physics_scene()
{
SaxVirtualFunctionTest14(end__physics_scene());
return mLoader->end__physics_scene();
}


bool PhysicsSceneLoader14::begin__instance_force_field( const COLLADASaxFWL14::instance_force_field__AttributeData& attributeData )
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


bool PhysicsSceneLoader14::end__instance_force_field()
{
SaxVirtualFunctionTest14(end__instance_force_field());
return mLoader->end__instance_force_field();
}


bool PhysicsSceneLoader14::begin__instance_physics_model( const COLLADASaxFWL14::instance_physics_model__AttributeData& attributeData )
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


bool PhysicsSceneLoader14::end__instance_physics_model()
{
SaxVirtualFunctionTest14(end__instance_physics_model());
return mLoader->end__instance_physics_model();
}


bool PhysicsSceneLoader14::begin__physics_scene__technique_common()
{
SaxVirtualFunctionTest14(begin__physics_scene__technique_common());
return mLoader->begin__physics_scene__technique_common();
}


bool PhysicsSceneLoader14::end__physics_scene__technique_common()
{
SaxVirtualFunctionTest14(end__physics_scene__technique_common());
return mLoader->end__physics_scene__technique_common();
}


bool PhysicsSceneLoader14::begin__gravity( const COLLADASaxFWL14::gravity__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__gravity(attributeData));
COLLADASaxFWL::gravity__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__gravity(attrData);
}


bool PhysicsSceneLoader14::end__gravity()
{
SaxVirtualFunctionTest14(end__gravity());
return mLoader->end__gravity();
}


bool PhysicsSceneLoader14::data__gravity( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__gravity(data, length));
return mLoader->data__gravity(data, length);
}


bool PhysicsSceneLoader14::begin__time_step( const COLLADASaxFWL14::time_step__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__time_step(attributeData));
COLLADASaxFWL::time_step__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__time_step(attrData);
}


bool PhysicsSceneLoader14::end__time_step()
{
SaxVirtualFunctionTest14(end__time_step());
return mLoader->end__time_step();
}


bool PhysicsSceneLoader14::data__time_step( const float value )
{
SaxVirtualFunctionTest14(data__time_step(value));
return mLoader->data__time_step(value);
}



}
