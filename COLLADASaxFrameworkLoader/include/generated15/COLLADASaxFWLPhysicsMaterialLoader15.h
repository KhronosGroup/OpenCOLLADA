/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_PHYSICSMATERIALLOADER15_H__
#define __COLLADASAXFWL_PHYSICSMATERIALLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLPhysicsMaterialLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class PhysicsMaterialLoader15 : public IParserImpl15
{
private:
PhysicsMaterialLoader* mLoader;

public:
PhysicsMaterialLoader15(PhysicsMaterialLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__physics_material( const COLLADASaxFWL15::physics_material__AttributeData& attributeData );

virtual bool end__physics_material();

virtual bool begin__physics_material_type____technique_common();

virtual bool end__physics_material_type____technique_common();

virtual bool begin__restitution____targetable_float3_type( const COLLADASaxFWL15::restitution____targetable_float3_type__AttributeData& attributeData );

virtual bool end__restitution();

virtual bool data__restitution( const float value );

virtual bool begin__dynamic_friction____targetable_float3_type( const COLLADASaxFWL15::dynamic_friction____targetable_float3_type__AttributeData& attributeData );

virtual bool end__dynamic_friction();

virtual bool data__dynamic_friction( const float value );

virtual bool begin__static_friction____targetable_float3_type( const COLLADASaxFWL15::static_friction____targetable_float3_type__AttributeData& attributeData );

virtual bool end__static_friction();

virtual bool data__static_friction( const float value );


private:
/** Disable default copy ctor. */
PhysicsMaterialLoader15(const PhysicsMaterialLoader15&);
/** Disable default assignment operator. */
const PhysicsMaterialLoader15& operator=(const PhysicsMaterialLoader15&);
};
}
#endif // __COLLADASAXFWL_PHYSICSMATERIALLOADER15_H__
