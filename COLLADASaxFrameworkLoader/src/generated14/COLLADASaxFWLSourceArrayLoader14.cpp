/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSourceArrayLoader14.h"


namespace COLLADASaxFWL
{


bool SourceArrayLoader14::begin__float_array( const COLLADASaxFWL14::float_array__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__float_array(attributeData));
COLLADASaxFWL::float_array__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.digits = attributeData.digits;
attrData.magnitude = attributeData.magnitude;
if ( (attributeData.present_attributes & COLLADASaxFWL14::float_array__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::float_array__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::float_array__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__float_array(attrData);
}


bool SourceArrayLoader14::end__float_array()
{
SaxVirtualFunctionTest14(end__float_array());
return mLoader->end__float_array();
}


bool SourceArrayLoader14::data__float_array( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__float_array(data, length));
return mLoader->data__float_array(data, length);
}


bool SourceArrayLoader14::begin__animation__source__technique_common()
{
SaxVirtualFunctionTest14(begin__animation__source__technique_common());
return mLoader->begin__animation__source__technique_common();
}


bool SourceArrayLoader14::end__animation__source__technique_common()
{
SaxVirtualFunctionTest14(end__animation__source__technique_common());
return mLoader->end__animation__source__technique_common();
}


bool SourceArrayLoader14::begin__accessor( const COLLADASaxFWL14::accessor__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__accessor(attributeData));
COLLADASaxFWL::accessor__AttributeData attrData;
attrData.present_attributes = 0;
attrData.offset = attributeData.offset;
attrData.stride = attributeData.stride;
if ( (attributeData.present_attributes & COLLADASaxFWL14::accessor__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::accessor__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::accessor__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL14::accessor__AttributeData::ATTRIBUTE_SOURCE_PRESENT) == COLLADASaxFWL14::accessor__AttributeData::ATTRIBUTE_SOURCE_PRESENT ) {
    attrData.source = attributeData.source;
    attrData.present_attributes |= COLLADASaxFWL::accessor__AttributeData::ATTRIBUTE_SOURCE_PRESENT;
}
return mLoader->begin__accessor(attrData);
}


bool SourceArrayLoader14::end__accessor()
{
SaxVirtualFunctionTest14(end__accessor());
return mLoader->end__accessor();
}


bool SourceArrayLoader14::begin__param( const COLLADASaxFWL14::param__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__param(attributeData));
COLLADASaxFWL::param__AttributeData attrData;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
attrData.semantic = attributeData.semantic;
attrData.type = attributeData.type;
return mLoader->begin__param(attrData);
}


bool SourceArrayLoader14::end__param()
{
SaxVirtualFunctionTest14(end__param());
return mLoader->end__param();
}


bool SourceArrayLoader14::data__param( const ParserChar* value, size_t length )
{
SaxVirtualFunctionTest14(data__param(value, length));
return mLoader->data__param(value, length);
}


bool SourceArrayLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool SourceArrayLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
