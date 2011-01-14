/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryPhysicsModelsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryPhysicsModelsLoader15::begin__physics_model( const COLLADASaxFWL15::physics_model__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__physics_model(attributeData));
COLLADASaxFWL::physics_model__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_model(attrData);
}


bool LibraryPhysicsModelsLoader15::end__physics_model()
{
SaxVirtualFunctionTest15(end__physics_model());
return mLoader->end__physics_model();
}


bool LibraryPhysicsModelsLoader15::end__library_physics_models()
{
SaxVirtualFunctionTest15(end__library_physics_models());
return mLoader->end__library_physics_models();
}


bool LibraryPhysicsModelsLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryPhysicsModelsLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
