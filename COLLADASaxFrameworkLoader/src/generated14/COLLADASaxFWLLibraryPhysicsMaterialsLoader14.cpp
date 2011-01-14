/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryPhysicsMaterialsLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryPhysicsMaterialsLoader14::begin__physics_material( const COLLADASaxFWL14::physics_material__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__physics_material(attributeData));
COLLADASaxFWL::physics_material__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_material(attrData);
}


bool LibraryPhysicsMaterialsLoader14::end__physics_material()
{
SaxVirtualFunctionTest14(end__physics_material());
return mLoader->end__physics_material();
}


bool LibraryPhysicsMaterialsLoader14::end__library_physics_materials()
{
SaxVirtualFunctionTest14(end__library_physics_materials());
return mLoader->end__library_physics_materials();
}


bool LibraryPhysicsMaterialsLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryPhysicsMaterialsLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
