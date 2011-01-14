/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryForceFieldsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryForceFieldsLoader15::begin__force_field( const COLLADASaxFWL15::force_field__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__force_field(attributeData));
COLLADASaxFWL::force_field__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__force_field(attrData);
}


bool LibraryForceFieldsLoader15::end__force_field()
{
SaxVirtualFunctionTest15(end__force_field());
return mLoader->end__force_field();
}


bool LibraryForceFieldsLoader15::end__library_force_fields()
{
SaxVirtualFunctionTest15(end__library_force_fields());
return mLoader->end__library_force_fields();
}


bool LibraryForceFieldsLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryForceFieldsLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
