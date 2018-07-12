/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryAnimationsLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryAnimationsLoader14::end__library_animations()
{
SaxVirtualFunctionTest14(end__library_animations());
return mLoader->end__library_animations();
}


bool LibraryAnimationsLoader14::begin__source( const COLLADASaxFWL14::source__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__source(attributeData));
COLLADASaxFWL::source__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__source(attrData);
}


bool LibraryAnimationsLoader14::end__source()
{
SaxVirtualFunctionTest14(end__source());
return mLoader->end__source();
}


bool LibraryAnimationsLoader14::begin__animation( const COLLADASaxFWL14::animation__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__animation(attributeData));
COLLADASaxFWL::animation__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__animation(attrData);
}


bool LibraryAnimationsLoader14::end__animation()
{
SaxVirtualFunctionTest14(end__animation());
return mLoader->end__animation();
}


bool LibraryAnimationsLoader14::begin__sampler( const COLLADASaxFWL14::sampler__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__sampler(attributeData));
COLLADASaxFWL::sampler__AttributeData attrData;
attrData.id = attributeData.id;
attrData.pre_behavior = COLLADASaxFWL::ENUM__sampler_behavior__NOT_PRESENT;
attrData.post_behavior = COLLADASaxFWL::ENUM__sampler_behavior__NOT_PRESENT;
return mLoader->begin__sampler(attrData);
}


bool LibraryAnimationsLoader14::end__sampler()
{
SaxVirtualFunctionTest14(end__sampler());
return mLoader->end__sampler();
}


bool LibraryAnimationsLoader14::begin__channel( const COLLADASaxFWL14::channel__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__channel(attributeData));
COLLADASaxFWL::channel__AttributeData attrData;
attrData.source = attributeData.source;
attrData.target = attributeData.target;
return mLoader->begin__channel(attrData);
}


bool LibraryAnimationsLoader14::end__channel()
{
SaxVirtualFunctionTest14(end__channel());
return mLoader->end__channel();
}


bool LibraryAnimationsLoader14::begin__input____InputLocal( const COLLADASaxFWL14::input____InputLocal__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__input____InputLocal(attributeData));
COLLADASaxFWL::input____InputLocal__AttributeData attrData;
attrData.semantic = attributeData.semantic;
attrData.source = attributeData.source;
return mLoader->begin__input____InputLocal(attrData);
}


bool LibraryAnimationsLoader14::end__input____InputLocal()
{
SaxVirtualFunctionTest14(end__input____InputLocal());
return mLoader->end__input____InputLocal();
}


bool LibraryAnimationsLoader14::begin__Name_array( const COLLADASaxFWL14::Name_array__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__Name_array(attributeData));
COLLADASaxFWL::Name_array__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::Name_array__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::Name_array__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::Name_array__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__Name_array(attrData);
}


bool LibraryAnimationsLoader14::end__Name_array()
{
SaxVirtualFunctionTest14(end__Name_array());
return mLoader->end__Name_array();
}


bool LibraryAnimationsLoader14::data__Name_array( const ParserString* data, size_t length )
{
SaxVirtualFunctionTest14(data__Name_array(data, length));
return mLoader->data__Name_array(data, length);
}


bool LibraryAnimationsLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryAnimationsLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
