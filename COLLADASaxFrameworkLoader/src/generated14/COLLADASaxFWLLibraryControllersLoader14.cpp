/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryControllersLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryControllersLoader14::end__library_controllers()
{
SaxVirtualFunctionTest14(end__library_controllers());
return mLoader->end__library_controllers();
}


bool LibraryControllersLoader14::begin__controller( const COLLADASaxFWL14::controller__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__controller(attributeData));
COLLADASaxFWL::controller__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__controller(attrData);
}


bool LibraryControllersLoader14::end__controller()
{
SaxVirtualFunctionTest14(end__controller());
return mLoader->end__controller();
}


bool LibraryControllersLoader14::begin__skin( const COLLADASaxFWL14::skin__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__skin(attributeData));
COLLADASaxFWL::skin__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL14::skin__AttributeData::ATTRIBUTE_SOURCE_PRESENT) == COLLADASaxFWL14::skin__AttributeData::ATTRIBUTE_SOURCE_PRESENT ) {
    attrData.source = attributeData.source;
    attrData.present_attributes |= COLLADASaxFWL::skin__AttributeData::ATTRIBUTE_SOURCE_PRESENT;
}
return mLoader->begin__skin(attrData);
}


bool LibraryControllersLoader14::end__skin()
{
SaxVirtualFunctionTest14(end__skin());
return mLoader->end__skin();
}


bool LibraryControllersLoader14::begin__morph( const COLLADASaxFWL14::morph__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__morph(attributeData));
COLLADASaxFWL::morph__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL14::morph__AttributeData::ATTRIBUTE_SOURCE_PRESENT) == COLLADASaxFWL14::morph__AttributeData::ATTRIBUTE_SOURCE_PRESENT ) {
    attrData.source = attributeData.source;
    attrData.present_attributes |= COLLADASaxFWL::morph__AttributeData::ATTRIBUTE_SOURCE_PRESENT;
}
switch (attributeData.method) {
case COLLADASaxFWL14::ENUM__MorphMethodType__NORMALIZED: attrData.method=COLLADASaxFWL::ENUM__MorphMethodType__NORMALIZED; break;
case COLLADASaxFWL14::ENUM__MorphMethodType__RELATIVE: attrData.method=COLLADASaxFWL::ENUM__MorphMethodType__RELATIVE; break;
case COLLADASaxFWL14::ENUM__MorphMethodType__COUNT: attrData.method=COLLADASaxFWL::ENUM__MorphMethodType__INVLAID; break;
case COLLADASaxFWL14::ENUM__MorphMethodType__NOT_PRESENT: attrData.method=COLLADASaxFWL::ENUM__MorphMethodType__NOT_PRESENT; break;
}
return mLoader->begin__morph(attrData);
}


bool LibraryControllersLoader14::end__morph()
{
SaxVirtualFunctionTest14(end__morph());
return mLoader->end__morph();
}


bool LibraryControllersLoader14::begin__source( const COLLADASaxFWL14::source__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__source(attributeData));
COLLADASaxFWL::source__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__source(attrData);
}


bool LibraryControllersLoader14::end__source()
{
SaxVirtualFunctionTest14(end__source());
return mLoader->end__source();
}


bool LibraryControllersLoader14::begin__joints()
{
SaxVirtualFunctionTest14(begin__joints());
return mLoader->begin__joints();
}


bool LibraryControllersLoader14::end__joints()
{
SaxVirtualFunctionTest14(end__joints());
return mLoader->end__joints();
}


bool LibraryControllersLoader14::begin__input____InputLocal( const COLLADASaxFWL14::input____InputLocal__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__input____InputLocal(attributeData));
COLLADASaxFWL::input____InputLocal__AttributeData attrData;
attrData.semantic = attributeData.semantic;
attrData.source = attributeData.source;
return mLoader->begin__input____InputLocal(attrData);
}


bool LibraryControllersLoader14::end__input____InputLocal()
{
SaxVirtualFunctionTest14(end__input____InputLocal());
return mLoader->end__input____InputLocal();
}


bool LibraryControllersLoader14::begin__input____InputLocalOffset( const COLLADASaxFWL14::input____InputLocalOffset__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__input____InputLocalOffset(attributeData));
COLLADASaxFWL::input____InputLocalOffset__AttributeData attrData;
attrData.present_attributes = 0;
attrData.semantic = attributeData.semantic;
attrData.source = attributeData.source;
if ( (attributeData.present_attributes & COLLADASaxFWL14::input____InputLocalOffset__AttributeData::ATTRIBUTE_OFFSET_PRESENT) == COLLADASaxFWL14::input____InputLocalOffset__AttributeData::ATTRIBUTE_OFFSET_PRESENT ) {
    attrData.offset = attributeData.offset;
    attrData.present_attributes |= COLLADASaxFWL::input____InputLocalOffset__AttributeData::ATTRIBUTE_OFFSET_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL14::input____InputLocalOffset__AttributeData::ATTRIBUTE_SET_PRESENT) == COLLADASaxFWL14::input____InputLocalOffset__AttributeData::ATTRIBUTE_SET_PRESENT ) {
    attrData.set = attributeData.set;
    attrData.present_attributes |= COLLADASaxFWL::input____InputLocalOffset__AttributeData::ATTRIBUTE_SET_PRESENT;
}
return mLoader->begin__input____InputLocalOffset(attrData);
}


bool LibraryControllersLoader14::end__input____InputLocalOffset()
{
SaxVirtualFunctionTest14(end__input____InputLocalOffset());
return mLoader->end__input____InputLocalOffset();
}


bool LibraryControllersLoader14::begin__vertex_weights( const COLLADASaxFWL14::vertex_weights__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__vertex_weights(attributeData));
COLLADASaxFWL::vertex_weights__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL14::vertex_weights__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::vertex_weights__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::vertex_weights__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__vertex_weights(attrData);
}


bool LibraryControllersLoader14::end__vertex_weights()
{
SaxVirtualFunctionTest14(end__vertex_weights());
return mLoader->end__vertex_weights();
}


bool LibraryControllersLoader14::begin__vcount()
{
SaxVirtualFunctionTest14(begin__vcount());
return mLoader->begin__vcount();
}


bool LibraryControllersLoader14::end__vcount()
{
SaxVirtualFunctionTest14(end__vcount());
return mLoader->end__vcount();
}


bool LibraryControllersLoader14::data__vcount( const uint64* data, size_t length )
{
SaxVirtualFunctionTest14(data__vcount(data, length));
return mLoader->data__vcount(data, length);
}


bool LibraryControllersLoader14::begin__v()
{
SaxVirtualFunctionTest14(begin__v());
return mLoader->begin__v();
}


bool LibraryControllersLoader14::end__v()
{
SaxVirtualFunctionTest14(end__v());
return mLoader->end__v();
}


bool LibraryControllersLoader14::data__v( const sint64* data, size_t length )
{
SaxVirtualFunctionTest14(data__v(data, length));
return mLoader->data__v(data, length);
}


bool LibraryControllersLoader14::begin__Name_array( const COLLADASaxFWL14::Name_array__AttributeData& attributeData )
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


bool LibraryControllersLoader14::end__Name_array()
{
SaxVirtualFunctionTest14(end__Name_array());
return mLoader->end__Name_array();
}


bool LibraryControllersLoader14::data__Name_array( const ParserString* data, size_t length )
{
SaxVirtualFunctionTest14(data__Name_array(data, length));
return mLoader->data__Name_array(data, length);
}


bool LibraryControllersLoader14::begin__IDREF_array( const COLLADASaxFWL14::IDREF_array__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__IDREF_array(attributeData));
COLLADASaxFWL::IDREF_array__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::IDREF_array__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::IDREF_array__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::IDREF_array__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__IDREF_array(attrData);
}


bool LibraryControllersLoader14::end__IDREF_array()
{
SaxVirtualFunctionTest14(end__IDREF_array());
return mLoader->end__IDREF_array();
}


bool LibraryControllersLoader14::data__IDREF_array( const ParserString* data, size_t length )
{
SaxVirtualFunctionTest14(data__IDREF_array(data, length));
return mLoader->data__IDREF_array(data, length);
}


bool LibraryControllersLoader14::begin__bind_shape_matrix()
{
SaxVirtualFunctionTest14(begin__bind_shape_matrix());
return mLoader->begin__bind_shape_matrix();
}


bool LibraryControllersLoader14::end__bind_shape_matrix()
{
SaxVirtualFunctionTest14(end__bind_shape_matrix());
return mLoader->end__bind_shape_matrix();
}


bool LibraryControllersLoader14::data__bind_shape_matrix( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__bind_shape_matrix(data, length));
return mLoader->data__bind_shape_matrix(data, length);
}


bool LibraryControllersLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryControllersLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
