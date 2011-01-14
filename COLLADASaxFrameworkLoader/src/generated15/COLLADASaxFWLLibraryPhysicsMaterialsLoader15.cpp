/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryPhysicsMaterialsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryPhysicsMaterialsLoader15::begin__physics_material( const COLLADASaxFWL15::physics_material__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__physics_material(attributeData));
COLLADASaxFWL::physics_material__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_material(attrData);
}


bool LibraryPhysicsMaterialsLoader15::end__physics_material()
{
SaxVirtualFunctionTest15(end__physics_material());
return mLoader->end__physics_material();
}


bool LibraryPhysicsMaterialsLoader15::end__library_physics_materials()
{
SaxVirtualFunctionTest15(end__library_physics_materials());
return mLoader->end__library_physics_materials();
}


bool LibraryPhysicsMaterialsLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryPhysicsMaterialsLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
