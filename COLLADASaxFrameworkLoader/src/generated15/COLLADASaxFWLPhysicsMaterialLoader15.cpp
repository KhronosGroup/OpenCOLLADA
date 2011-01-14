/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPhysicsMaterialLoader15.h"


namespace COLLADASaxFWL
{


bool PhysicsMaterialLoader15::begin__physics_material( const COLLADASaxFWL15::physics_material__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__physics_material(attributeData));
COLLADASaxFWL::physics_material__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_material(attrData);
}


bool PhysicsMaterialLoader15::end__physics_material()
{
SaxVirtualFunctionTest15(end__physics_material());
return mLoader->end__physics_material();
}


bool PhysicsMaterialLoader15::begin__physics_material_type____technique_common()
{
SaxVirtualFunctionTest15(begin__physics_material_type____technique_common());
return mLoader->begin__physics_material__technique_common();
}


bool PhysicsMaterialLoader15::end__physics_material_type____technique_common()
{
SaxVirtualFunctionTest15(end__physics_material_type____technique_common());
return mLoader->end__physics_material__technique_common();
}


bool PhysicsMaterialLoader15::begin__restitution____targetable_float3_type( const COLLADASaxFWL15::restitution____targetable_float3_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__restitution____targetable_float3_type(attributeData));
COLLADASaxFWL::restitution__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__restitution(attrData);
}


bool PhysicsMaterialLoader15::end__restitution()
{
SaxVirtualFunctionTest15(end__restitution());
return mLoader->end__restitution();
}


bool PhysicsMaterialLoader15::data__restitution( const float value )
{
SaxVirtualFunctionTest15(data__restitution(value));
return mLoader->data__restitution(value);
}


bool PhysicsMaterialLoader15::begin__dynamic_friction____targetable_float3_type( const COLLADASaxFWL15::dynamic_friction____targetable_float3_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__dynamic_friction____targetable_float3_type(attributeData));
COLLADASaxFWL::dynamic_friction__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__dynamic_friction(attrData);
}


bool PhysicsMaterialLoader15::end__dynamic_friction()
{
SaxVirtualFunctionTest15(end__dynamic_friction());
return mLoader->end__dynamic_friction();
}


bool PhysicsMaterialLoader15::data__dynamic_friction( const float value )
{
SaxVirtualFunctionTest15(data__dynamic_friction(value));
return mLoader->data__dynamic_friction(value);
}


bool PhysicsMaterialLoader15::begin__static_friction____targetable_float3_type( const COLLADASaxFWL15::static_friction____targetable_float3_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__static_friction____targetable_float3_type(attributeData));
COLLADASaxFWL::static_friction__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__static_friction(attrData);
}


bool PhysicsMaterialLoader15::end__static_friction()
{
SaxVirtualFunctionTest15(end__static_friction());
return mLoader->end__static_friction();
}


bool PhysicsMaterialLoader15::data__static_friction( const float value )
{
SaxVirtualFunctionTest15(data__static_friction(value));
return mLoader->data__static_friction(value);
}



}
