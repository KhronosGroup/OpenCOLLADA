/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryPhysicsModelsLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryPhysicsModelsLoader14::begin__physics_model( const COLLADASaxFWL14::physics_model__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__physics_model(attributeData));
COLLADASaxFWL::physics_model__AttributeData attrData;
//attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__physics_model(attrData);
}


bool LibraryPhysicsModelsLoader14::end__physics_model()
{
SaxVirtualFunctionTest14(end__physics_model());
return mLoader->end__physics_model();
}


bool LibraryPhysicsModelsLoader14::end__library_physics_models()
{
SaxVirtualFunctionTest14(end__library_physics_models());
return mLoader->end__library_physics_models();
}


bool LibraryPhysicsModelsLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryPhysicsModelsLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
