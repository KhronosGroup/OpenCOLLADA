/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPhysicsSceneLoader15.h"


namespace COLLADASaxFWL
{


bool PhysicsSceneLoader15::end__physics_scene()
{
SaxVirtualFunctionTest15(end__physics_scene());
return mLoader->end__physics_scene();
}


//bool PhysicsSceneLoader15::begin__instance_force_field( const COLLADASaxFWL15::instance_force_field__AttributeData& attributeData )
//{
//SaxVirtualFunctionTest15(begin__instance_force_field(attributeData));
//COLLADASaxFWL::instance_force_field__AttributeData attrData;
//attrData.present_attributes = 0;
//attrData.sid = attributeData.sid;
//attrData.name = attributeData.name;
//if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_force_field__AttributeData::ATTRIBUTE_URI_PRESENT) == COLLADASaxFWL15::instance_force_field__AttributeData::ATTRIBUTE_URI_PRESENT ) {
//    attrData.url = attributeData.url;
//    attrData.present_attributes |= COLLADASaxFWL::instance_force_field__AttributeData::ATTRIBUTE_URI_PRESENT;
//}
//return mLoader->begin__instance_force_field(attrData);
//}


//bool PhysicsSceneLoader15::end__instance_force_field()
//{
//SaxVirtualFunctionTest15(end__instance_force_field());
//return mLoader->end__instance_force_field();
//}


//bool PhysicsSceneLoader15::begin__instance_physics_model( const COLLADASaxFWL15::instance_physics_model__AttributeData& attributeData )
//{
//SaxVirtualFunctionTest15(begin__instance_physics_model(attributeData));
//COLLADASaxFWL::instance_physics_model__AttributeData attrData;
//attrData.present_attributes = 0;
//attrData.sid = attributeData.sid;
//attrData.name = attributeData.name;
//if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_physics_model__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_physics_model__AttributeData::ATTRIBUTE_URL_PRESENT ) {
//    attrData.url = attributeData.url;
//    attrData.present_attributes |= COLLADASaxFWL::instance_physics_model__AttributeData::ATTRIBUTE_URL_PRESENT;
//}
//if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_physics_model__AttributeData::ATTRIBUTE_PARENT_PRESENT) == COLLADASaxFWL15::instance_physics_model__AttributeData::ATTRIBUTE_PARENT_PRESENT ) {
//    attrData.url = attributeData.url;
//    attrData.present_attributes |= COLLADASaxFWL::instance_physics_model__AttributeData::ATTRIBUTE_PARENT_PRESENT;
//}
//return mLoader->begin__instance_physics_model(attrData);
//}
//
//
//bool PhysicsSceneLoader15::end__instance_physics_model()
//{
//SaxVirtualFunctionTest15(end__instance_physics_model());
//return mLoader->end__instance_physics_model();
//}


bool PhysicsSceneLoader15::begin__physics_scene_type____technique_common()
{
SaxVirtualFunctionTest15(begin__physics_scene_type____technique_common());
return mLoader->begin__physics_scene__technique_common();
}


bool PhysicsSceneLoader15::end__physics_scene_type____technique_common()
{
SaxVirtualFunctionTest15(end__physics_scene_type____technique_common());
return mLoader->end__physics_scene__technique_common();
}


bool PhysicsSceneLoader15::begin__gravity( const COLLADASaxFWL15::gravity__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__gravity(attributeData));
COLLADASaxFWL::gravity__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__gravity(attrData);
}


bool PhysicsSceneLoader15::end__gravity()
{
SaxVirtualFunctionTest15(end__gravity());
return mLoader->end__gravity();
}


bool PhysicsSceneLoader15::data__gravity( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__gravity(data, length));
return mLoader->data__gravity(data, length);
}


bool PhysicsSceneLoader15::begin__time_step( const COLLADASaxFWL15::time_step__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__time_step(attributeData));
COLLADASaxFWL::time_step__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__time_step(attrData);
}


bool PhysicsSceneLoader15::end__time_step()
{
SaxVirtualFunctionTest15(end__time_step());
return mLoader->end__time_step();
}


bool PhysicsSceneLoader15::data__time_step( const float value )
{
SaxVirtualFunctionTest15(data__time_step(value));
return mLoader->data__time_step(value);
}



}
