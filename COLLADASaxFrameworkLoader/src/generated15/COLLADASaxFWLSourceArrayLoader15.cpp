/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSourceArrayLoader15.h"


namespace COLLADASaxFWL
{


bool SourceArrayLoader15::begin__float_array( const COLLADASaxFWL15::float_array__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__float_array(attributeData));
COLLADASaxFWL::float_array__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.digits = attributeData.digits;
attrData.magnitude = attributeData.magnitude;
if ( (attributeData.present_attributes & COLLADASaxFWL15::float_array__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::float_array__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::float_array__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__float_array(attrData);
}


bool SourceArrayLoader15::end__float_array()
{
SaxVirtualFunctionTest15(end__float_array());
return mLoader->end__float_array();
}


bool SourceArrayLoader15::data__float_array( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__float_array(data, length));
return mLoader->data__float_array(data, length);
}


bool SourceArrayLoader15::begin__source_type____technique_common()
{
SaxVirtualFunctionTest15(begin__source_type____technique_common());
return mLoader->begin__animation__source__technique_common();
}


bool SourceArrayLoader15::end__source_type____technique_common()
{
SaxVirtualFunctionTest15(end__source_type____technique_common());
return mLoader->end__animation__source__technique_common();
}


bool SourceArrayLoader15::begin__accessor( const COLLADASaxFWL15::accessor__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__accessor(attributeData));
COLLADASaxFWL::accessor__AttributeData attrData;
attrData.present_attributes = 0;
attrData.offset = attributeData.offset;
attrData.stride = attributeData.stride;
if ( (attributeData.present_attributes & COLLADASaxFWL15::accessor__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::accessor__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::accessor__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::accessor__AttributeData::ATTRIBUTE_SOURCE_PRESENT) == COLLADASaxFWL15::accessor__AttributeData::ATTRIBUTE_SOURCE_PRESENT ) {
    attrData.source = attributeData.source;
    attrData.present_attributes |= COLLADASaxFWL::accessor__AttributeData::ATTRIBUTE_SOURCE_PRESENT;
}
return mLoader->begin__accessor(attrData);
}


bool SourceArrayLoader15::end__accessor()
{
SaxVirtualFunctionTest15(end__accessor());
return mLoader->end__accessor();
}


bool SourceArrayLoader15::begin__param____param_type( const COLLADASaxFWL15::param____param_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__param____param_type(attributeData));
COLLADASaxFWL::param__AttributeData attrData;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
attrData.semantic = attributeData.semantic;
attrData.type = attributeData.type;
return mLoader->begin__param(attrData);
}


bool SourceArrayLoader15::end__param____param_type()
{
SaxVirtualFunctionTest15(end__param____param_type());
return mLoader->end__param();
}


bool SourceArrayLoader15::data__param____param_type( const ParserChar* value, size_t length )
{
SaxVirtualFunctionTest15(data__param____param_type(value, length));
return mLoader->data__param(value, length);
}


bool SourceArrayLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool SourceArrayLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
