/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryForceFieldsLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryForceFieldsLoader14::begin__force_field( const COLLADASaxFWL14::force_field__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__force_field(attributeData));
COLLADASaxFWL::force_field__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__force_field(attrData);
}


bool LibraryForceFieldsLoader14::end__force_field()
{
SaxVirtualFunctionTest14(end__force_field());
return mLoader->end__force_field();
}


bool LibraryForceFieldsLoader14::end__library_force_fields()
{
SaxVirtualFunctionTest14(end__library_force_fields());
return mLoader->end__library_force_fields();
}


bool LibraryForceFieldsLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryForceFieldsLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
