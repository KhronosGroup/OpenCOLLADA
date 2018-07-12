/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryControllersLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryControllersLoader15::end__library_controllers()
{
SaxVirtualFunctionTest15(end__library_controllers());
return mLoader->end__library_controllers();
}


bool LibraryControllersLoader15::begin__controller( const COLLADASaxFWL15::controller__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__controller(attributeData));
COLLADASaxFWL::controller__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__controller(attrData);
}


bool LibraryControllersLoader15::end__controller()
{
SaxVirtualFunctionTest15(end__controller());
return mLoader->end__controller();
}


bool LibraryControllersLoader15::begin__skin( const COLLADASaxFWL15::skin__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__skin(attributeData));
COLLADASaxFWL::skin__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::skin__AttributeData::ATTRIBUTE_SOURCE_PRESENT) == COLLADASaxFWL15::skin__AttributeData::ATTRIBUTE_SOURCE_PRESENT ) {
    attrData.source = attributeData.source;
    attrData.present_attributes |= COLLADASaxFWL::skin__AttributeData::ATTRIBUTE_SOURCE_PRESENT;
}
return mLoader->begin__skin(attrData);
}


bool LibraryControllersLoader15::end__skin()
{
SaxVirtualFunctionTest15(end__skin());
return mLoader->end__skin();
}


bool LibraryControllersLoader15::begin__morph( const COLLADASaxFWL15::morph__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__morph(attributeData));
COLLADASaxFWL::morph__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::morph__AttributeData::ATTRIBUTE_SOURCE_PRESENT) == COLLADASaxFWL15::morph__AttributeData::ATTRIBUTE_SOURCE_PRESENT ) {
    attrData.source = attributeData.source;
    attrData.present_attributes |= COLLADASaxFWL::morph__AttributeData::ATTRIBUTE_SOURCE_PRESENT;
}
switch (attributeData.method) {
case COLLADASaxFWL15::ENUM__morph_method_enum__NORMALIZED: attrData.method=COLLADASaxFWL::ENUM__MorphMethodType__NORMALIZED; break;
case COLLADASaxFWL15::ENUM__morph_method_enum__RELATIVE: attrData.method=COLLADASaxFWL::ENUM__MorphMethodType__RELATIVE; break;
case COLLADASaxFWL15::ENUM__morph_method_enum__COUNT: attrData.method=COLLADASaxFWL::ENUM__MorphMethodType__INVLAID; break;
case COLLADASaxFWL15::ENUM__morph_method_enum__NOT_PRESENT: attrData.method=COLLADASaxFWL::ENUM__MorphMethodType__NOT_PRESENT; break;
}
return mLoader->begin__morph(attrData);
}


bool LibraryControllersLoader15::end__morph()
{
SaxVirtualFunctionTest15(end__morph());
return mLoader->end__morph();
}


bool LibraryControllersLoader15::begin__source( const COLLADASaxFWL15::source__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__source(attributeData));
COLLADASaxFWL::source__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__source(attrData);
}


bool LibraryControllersLoader15::end__source()
{
SaxVirtualFunctionTest15(end__source());
return mLoader->end__source();
}


bool LibraryControllersLoader15::begin__joints()
{
SaxVirtualFunctionTest15(begin__joints());
return mLoader->begin__joints();
}


bool LibraryControllersLoader15::end__joints()
{
SaxVirtualFunctionTest15(end__joints());
return mLoader->end__joints();
}


bool LibraryControllersLoader15::begin__input____input_local_type( const COLLADASaxFWL15::input____input_local_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__input____input_local_type(attributeData));
COLLADASaxFWL::input____InputLocal__AttributeData attrData;
attrData.semantic = attributeData.semantic;
attrData.source = attributeData.source;
return mLoader->begin__input____InputLocal(attrData);
}


bool LibraryControllersLoader15::end__input____input_local_type()
{
SaxVirtualFunctionTest15(end__input____input_local_type());
return mLoader->end__input____InputLocal();
}


bool LibraryControllersLoader15::begin__input____input_local_offset_type( const COLLADASaxFWL15::input____input_local_offset_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__input____input_local_offset_type(attributeData));
COLLADASaxFWL::input____InputLocalOffset__AttributeData attrData;
attrData.present_attributes = 0;
attrData.semantic = attributeData.semantic;
attrData.source = attributeData.source;
if ( (attributeData.present_attributes & COLLADASaxFWL15::input____input_local_offset_type__AttributeData::ATTRIBUTE_OFFSET_PRESENT) == COLLADASaxFWL15::input____input_local_offset_type__AttributeData::ATTRIBUTE_OFFSET_PRESENT ) {
    attrData.offset = attributeData.offset;
    attrData.present_attributes |= COLLADASaxFWL::input____InputLocalOffset__AttributeData::ATTRIBUTE_OFFSET_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::input____input_local_offset_type__AttributeData::ATTRIBUTE_SET_PRESENT) == COLLADASaxFWL15::input____input_local_offset_type__AttributeData::ATTRIBUTE_SET_PRESENT ) {
    attrData.set = attributeData.set;
    attrData.present_attributes |= COLLADASaxFWL::input____InputLocalOffset__AttributeData::ATTRIBUTE_SET_PRESENT;
}
return mLoader->begin__input____InputLocalOffset(attrData);
}


bool LibraryControllersLoader15::end__input____input_local_offset_type()
{
SaxVirtualFunctionTest15(end__input____input_local_offset_type());
return mLoader->end__input____InputLocalOffset();
}


bool LibraryControllersLoader15::begin__vertex_weights( const COLLADASaxFWL15::vertex_weights__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__vertex_weights(attributeData));
COLLADASaxFWL::vertex_weights__AttributeData attrData;
attrData.present_attributes = 0;
if ( (attributeData.present_attributes & COLLADASaxFWL15::vertex_weights__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::vertex_weights__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::vertex_weights__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__vertex_weights(attrData);
}


bool LibraryControllersLoader15::end__vertex_weights()
{
SaxVirtualFunctionTest15(end__vertex_weights());
return mLoader->end__vertex_weights();
}


bool LibraryControllersLoader15::begin__vcount()
{
SaxVirtualFunctionTest15(begin__vcount());
return mLoader->begin__vcount();
}


bool LibraryControllersLoader15::end__vcount()
{
SaxVirtualFunctionTest15(end__vcount());
return mLoader->end__vcount();
}


bool LibraryControllersLoader15::data__vcount( const uint64* data, size_t length )
{
SaxVirtualFunctionTest15(data__vcount(data, length));
return mLoader->data__vcount(data, length);
}


bool LibraryControllersLoader15::begin__v()
{
SaxVirtualFunctionTest15(begin__v());
return mLoader->begin__v();
}


bool LibraryControllersLoader15::end__v()
{
SaxVirtualFunctionTest15(end__v());
return mLoader->end__v();
}


bool LibraryControllersLoader15::data__v( const sint64* data, size_t length )
{
SaxVirtualFunctionTest15(data__v(data, length));
return mLoader->data__v(data, length);
}


bool LibraryControllersLoader15::begin__Name_array( const COLLADASaxFWL15::Name_array__AttributeData& attributeData )
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


bool LibraryControllersLoader15::end__Name_array()
{
SaxVirtualFunctionTest15(end__Name_array());
return mLoader->end__Name_array();
}


bool LibraryControllersLoader15::data__Name_array( const ParserString* data, size_t length )
{
SaxVirtualFunctionTest15(data__Name_array(data, length));
return mLoader->data__Name_array(data, length);
}


bool LibraryControllersLoader15::begin__IDREF_array( const COLLADASaxFWL15::IDREF_array__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__IDREF_array(attributeData));
COLLADASaxFWL::IDREF_array__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::IDREF_array__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::IDREF_array__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::IDREF_array__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__IDREF_array(attrData);
}


bool LibraryControllersLoader15::end__IDREF_array()
{
SaxVirtualFunctionTest15(end__IDREF_array());
return mLoader->end__IDREF_array();
}


bool LibraryControllersLoader15::data__IDREF_array( const ParserString* data, size_t length )
{
SaxVirtualFunctionTest15(data__IDREF_array(data, length));
return mLoader->data__IDREF_array(data, length);
}


bool LibraryControllersLoader15::begin__bind_shape_matrix()
{
SaxVirtualFunctionTest15(begin__bind_shape_matrix());
return mLoader->begin__bind_shape_matrix();
}


bool LibraryControllersLoader15::end__bind_shape_matrix()
{
SaxVirtualFunctionTest15(end__bind_shape_matrix());
return mLoader->end__bind_shape_matrix();
}


bool LibraryControllersLoader15::data__bind_shape_matrix( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__bind_shape_matrix(data, length));
return mLoader->data__bind_shape_matrix(data, length);
}


bool LibraryControllersLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryControllersLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
