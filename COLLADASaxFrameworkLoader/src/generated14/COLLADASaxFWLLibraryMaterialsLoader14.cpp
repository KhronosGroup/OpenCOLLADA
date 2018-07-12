/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryMaterialsLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryMaterialsLoader14::end__library_materials()
{
SaxVirtualFunctionTest14(end__library_materials());
return mLoader->end__library_materials();
}


bool LibraryMaterialsLoader14::begin__material( const COLLADASaxFWL14::material__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__material(attributeData));
COLLADASaxFWL::material__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__material(attrData);
}


bool LibraryMaterialsLoader14::end__material()
{
SaxVirtualFunctionTest14(end__material());
return mLoader->end__material();
}


bool LibraryMaterialsLoader14::begin__instance_effect( const COLLADASaxFWL14::instance_effect__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_effect(attributeData));
COLLADASaxFWL::instance_effect__AttributeData attrData;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_effect__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_effect__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_effect__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_effect(attrData);
}


bool LibraryMaterialsLoader14::end__instance_effect()
{
SaxVirtualFunctionTest14(end__instance_effect());
return mLoader->end__instance_effect();
}


bool LibraryMaterialsLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryMaterialsLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
