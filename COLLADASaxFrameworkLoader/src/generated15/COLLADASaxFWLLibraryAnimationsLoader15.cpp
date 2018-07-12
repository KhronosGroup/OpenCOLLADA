/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryAnimationsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryAnimationsLoader15::end__library_animations()
{
SaxVirtualFunctionTest15(end__library_animations());
return mLoader->end__library_animations();
}


bool LibraryAnimationsLoader15::begin__source( const COLLADASaxFWL15::source__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__source(attributeData));
COLLADASaxFWL::source__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__source(attrData);
}


bool LibraryAnimationsLoader15::end__source()
{
SaxVirtualFunctionTest15(end__source());
return mLoader->end__source();
}


bool LibraryAnimationsLoader15::begin__animation( const COLLADASaxFWL15::animation__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__animation(attributeData));
COLLADASaxFWL::animation__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__animation(attrData);
}


bool LibraryAnimationsLoader15::end__animation()
{
SaxVirtualFunctionTest15(end__animation());
return mLoader->end__animation();
}


bool LibraryAnimationsLoader15::begin__sampler( const COLLADASaxFWL15::sampler__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__sampler(attributeData));
COLLADASaxFWL::sampler__AttributeData attrData;
attrData.id = attributeData.id;
switch (attributeData.pre_behavior) {
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__CONSTANT: attrData.pre_behavior=COLLADASaxFWL::ENUM__sampler_behavior__CONSTANT; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__CYCLE: attrData.pre_behavior=COLLADASaxFWL::ENUM__sampler_behavior__CYCLE; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__CYCLE_RELATIVE: attrData.pre_behavior=COLLADASaxFWL::ENUM__sampler_behavior__CYCLE_RELATIVE; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__GRADIENT: attrData.pre_behavior=COLLADASaxFWL::ENUM__sampler_behavior__GRADIENT; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__OSCILLATE: attrData.pre_behavior=COLLADASaxFWL::ENUM__sampler_behavior__OSCILLATE; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__UNDEFINED: attrData.pre_behavior=COLLADASaxFWL::ENUM__sampler_behavior__UNDEFINED; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__COUNT: attrData.pre_behavior=COLLADASaxFWL::ENUM__sampler_behavior__INVALID; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__NOT_PRESENT: attrData.pre_behavior=COLLADASaxFWL::ENUM__sampler_behavior__NOT_PRESENT; break;
}
switch (attributeData.post_behavior) {
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__CONSTANT: attrData.post_behavior=COLLADASaxFWL::ENUM__sampler_behavior__CONSTANT; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__CYCLE: attrData.post_behavior=COLLADASaxFWL::ENUM__sampler_behavior__CYCLE; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__CYCLE_RELATIVE: attrData.post_behavior=COLLADASaxFWL::ENUM__sampler_behavior__CYCLE_RELATIVE; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__GRADIENT: attrData.post_behavior=COLLADASaxFWL::ENUM__sampler_behavior__GRADIENT; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__OSCILLATE: attrData.post_behavior=COLLADASaxFWL::ENUM__sampler_behavior__OSCILLATE; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__UNDEFINED: attrData.post_behavior=COLLADASaxFWL::ENUM__sampler_behavior__UNDEFINED; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__COUNT: attrData.post_behavior=COLLADASaxFWL::ENUM__sampler_behavior__INVALID; break;
case COLLADASaxFWL15::ENUM__sampler_behavior_enum__NOT_PRESENT: attrData.post_behavior=COLLADASaxFWL::ENUM__sampler_behavior__NOT_PRESENT; break;
}
return mLoader->begin__sampler(attrData);
}


bool LibraryAnimationsLoader15::end__sampler()
{
SaxVirtualFunctionTest15(end__sampler());
return mLoader->end__sampler();
}


bool LibraryAnimationsLoader15::begin__channel( const COLLADASaxFWL15::channel__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__channel(attributeData));
COLLADASaxFWL::channel__AttributeData attrData;
attrData.source = attributeData.source;
attrData.target = attributeData.target;
return mLoader->begin__channel(attrData);
}


bool LibraryAnimationsLoader15::end__channel()
{
SaxVirtualFunctionTest15(end__channel());
return mLoader->end__channel();
}


bool LibraryAnimationsLoader15::begin__input____input_local_type( const COLLADASaxFWL15::input____input_local_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__input____input_local_type(attributeData));
COLLADASaxFWL::input____InputLocal__AttributeData attrData;
attrData.semantic = attributeData.semantic;
attrData.source = attributeData.source;
return mLoader->begin__input____InputLocal(attrData);
}


bool LibraryAnimationsLoader15::end__input____input_local_type()
{
SaxVirtualFunctionTest15(end__input____input_local_type());
return mLoader->end__input____InputLocal();
}


bool LibraryAnimationsLoader15::begin__Name_array( const COLLADASaxFWL15::Name_array__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__Name_array(attributeData));
COLLADASaxFWL::Name_array__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::Name_array__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::Name_array__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::Name_array__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__Name_array(attrData);
}


bool LibraryAnimationsLoader15::end__Name_array()
{
SaxVirtualFunctionTest15(end__Name_array());
return mLoader->end__Name_array();
}


bool LibraryAnimationsLoader15::data__Name_array( const ParserString* data, size_t length )
{
SaxVirtualFunctionTest15(data__Name_array(data, length));
return mLoader->data__Name_array(data, length);
}


bool LibraryAnimationsLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryAnimationsLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
