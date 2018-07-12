/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryMaterialsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryMaterialsLoader15::end__library_materials()
{
SaxVirtualFunctionTest15(end__library_materials());
return mLoader->end__library_materials();
}


bool LibraryMaterialsLoader15::begin__material( const COLLADASaxFWL15::material__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__material(attributeData));
COLLADASaxFWL::material__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__material(attrData);
}


bool LibraryMaterialsLoader15::end__material()
{
SaxVirtualFunctionTest15(end__material());
return mLoader->end__material();
}


bool LibraryMaterialsLoader15::begin__instance_effect( const COLLADASaxFWL15::instance_effect__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_effect(attributeData));
COLLADASaxFWL::instance_effect__AttributeData attrData;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_effect__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_effect__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_effect__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_effect(attrData);
}


bool LibraryMaterialsLoader15::end__instance_effect()
{
SaxVirtualFunctionTest15(end__instance_effect());
return mLoader->end__instance_effect();
}


bool LibraryMaterialsLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryMaterialsLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
