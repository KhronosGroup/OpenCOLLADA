/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryPhysicsScenesLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryPhysicsScenesLoader15::begin__physics_scene( const COLLADASaxFWL15::physics_scene__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__physics_scene(attributeData));
COLLADASaxFWL::physics_scene__AttributeData attrData;
//attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_scene(attrData);
}


bool LibraryPhysicsScenesLoader15::end__physics_scene()
{
SaxVirtualFunctionTest15(end__physics_scene());
return mLoader->end__physics_scene();
}


bool LibraryPhysicsScenesLoader15::end__library_physics_scenes()
{
SaxVirtualFunctionTest15(end__library_physics_scenes());
return mLoader->end__library_physics_scenes();
}


bool LibraryPhysicsScenesLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryPhysicsScenesLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
