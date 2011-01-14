/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_PHYSICSMATERIALLOADER14_H__
#define __COLLADASAXFWL_PHYSICSMATERIALLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLPhysicsMaterialLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class PhysicsMaterialLoader14 : public IParserImpl14
{
private:
PhysicsMaterialLoader* mLoader;

public:
PhysicsMaterialLoader14(PhysicsMaterialLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__physics_material( const COLLADASaxFWL14::physics_material__AttributeData& attributeData );

virtual bool end__physics_material();

virtual bool begin__physics_material__technique_common();

virtual bool end__physics_material__technique_common();

virtual bool begin__restitution( const COLLADASaxFWL14::restitution__AttributeData& attributeData );

virtual bool end__restitution();

virtual bool data__restitution( const float value );

virtual bool begin__dynamic_friction( const COLLADASaxFWL14::dynamic_friction__AttributeData& attributeData );

virtual bool end__dynamic_friction();

virtual bool data__dynamic_friction( const float value );

virtual bool begin__static_friction( const COLLADASaxFWL14::static_friction__AttributeData& attributeData );

virtual bool end__static_friction();

virtual bool data__static_friction( const float value );


private:
/** Disable default copy ctor. */
PhysicsMaterialLoader14(const PhysicsMaterialLoader14&);
/** Disable default assignment operator. */
const PhysicsMaterialLoader14& operator=(const PhysicsMaterialLoader14&);
};
}
#endif // __COLLADASAXFWL_PHYSICSMATERIALLOADER14_H__
