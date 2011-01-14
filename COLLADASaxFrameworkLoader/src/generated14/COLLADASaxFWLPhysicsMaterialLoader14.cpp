/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPhysicsMaterialLoader14.h"


namespace COLLADASaxFWL
{


bool PhysicsMaterialLoader14::begin__physics_material( const COLLADASaxFWL14::physics_material__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__physics_material(attributeData));
COLLADASaxFWL::physics_material__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_material(attrData);
}


bool PhysicsMaterialLoader14::end__physics_material()
{
SaxVirtualFunctionTest14(end__physics_material());
return mLoader->end__physics_material();
}


bool PhysicsMaterialLoader14::begin__physics_material__technique_common()
{
SaxVirtualFunctionTest14(begin__physics_material__technique_common());
return mLoader->begin__physics_material__technique_common();
}


bool PhysicsMaterialLoader14::end__physics_material__technique_common()
{
SaxVirtualFunctionTest14(end__physics_material__technique_common());
return mLoader->end__physics_material__technique_common();
}


bool PhysicsMaterialLoader14::begin__restitution( const COLLADASaxFWL14::restitution__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__restitution(attributeData));
COLLADASaxFWL::restitution__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__restitution(attrData);
}


bool PhysicsMaterialLoader14::end__restitution()
{
SaxVirtualFunctionTest14(end__restitution());
return mLoader->end__restitution();
}


bool PhysicsMaterialLoader14::data__restitution( const float value )
{
SaxVirtualFunctionTest14(data__restitution(value));
return mLoader->data__restitution(value);
}


bool PhysicsMaterialLoader14::begin__dynamic_friction( const COLLADASaxFWL14::dynamic_friction__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__dynamic_friction(attributeData));
COLLADASaxFWL::dynamic_friction__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__dynamic_friction(attrData);
}


bool PhysicsMaterialLoader14::end__dynamic_friction()
{
SaxVirtualFunctionTest14(end__dynamic_friction());
return mLoader->end__dynamic_friction();
}


bool PhysicsMaterialLoader14::data__dynamic_friction( const float value )
{
SaxVirtualFunctionTest14(data__dynamic_friction(value));
return mLoader->data__dynamic_friction(value);
}


bool PhysicsMaterialLoader14::begin__static_friction( const COLLADASaxFWL14::static_friction__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__static_friction(attributeData));
COLLADASaxFWL::static_friction__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__static_friction(attrData);
}


bool PhysicsMaterialLoader14::end__static_friction()
{
SaxVirtualFunctionTest14(end__static_friction());
return mLoader->end__static_friction();
}


bool PhysicsMaterialLoader14::data__static_friction( const float value )
{
SaxVirtualFunctionTest14(data__static_friction(value));
return mLoader->data__static_friction(value);
}



}
