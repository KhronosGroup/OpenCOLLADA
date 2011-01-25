/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryPhysicsScenesLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryPhysicsScenesLoader14::begin__physics_scene( const COLLADASaxFWL14::physics_scene__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__physics_scene(attributeData));
COLLADASaxFWL::physics_scene__AttributeData attrData;
//attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_scene(attrData);
}


bool LibraryPhysicsScenesLoader14::end__physics_scene()
{
SaxVirtualFunctionTest14(end__physics_scene());
return mLoader->end__physics_scene();
}


bool LibraryPhysicsScenesLoader14::end__library_physics_scenes()
{
SaxVirtualFunctionTest14(end__library_physics_scenes());
return mLoader->end__library_physics_scenes();
}


bool LibraryPhysicsScenesLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryPhysicsScenesLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
