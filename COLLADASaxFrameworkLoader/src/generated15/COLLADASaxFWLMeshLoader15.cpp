/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLMeshLoader15.h"


namespace COLLADASaxFWL
{


bool MeshLoader15::begin__source( const COLLADASaxFWL15::source__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__source(attributeData));
COLLADASaxFWL::source__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__source(attrData);
}


bool MeshLoader15::end__source()
{
SaxVirtualFunctionTest15(end__source());
return mLoader->end__source();
}


bool MeshLoader15::end__mesh()
{
SaxVirtualFunctionTest15(end__mesh());
return mLoader->end__mesh();
}


bool MeshLoader15::begin__vertices( const COLLADASaxFWL15::vertices__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__vertices(attributeData));
COLLADASaxFWL::vertices__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__vertices(attrData);
}


bool MeshLoader15::end__vertices()
{
SaxVirtualFunctionTest15(end__vertices());
return mLoader->end__vertices();
}


bool MeshLoader15::begin__input____input_local_type( const COLLADASaxFWL15::input____input_local_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__input____input_local_type(attributeData));
COLLADASaxFWL::input____InputLocal__AttributeData attrData;
attrData.semantic = attributeData.semantic;
attrData.source = attributeData.source;
return mLoader->begin__input____InputLocal(attrData);
}


bool MeshLoader15::end__input____input_local_type()
{
SaxVirtualFunctionTest15(end__input____input_local_type());
return mLoader->end__input____InputLocal();
}


bool MeshLoader15::begin__input____input_local_offset_type( const COLLADASaxFWL15::input____input_local_offset_type__AttributeData& attributeData )
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


bool MeshLoader15::end__input____input_local_offset_type()
{
SaxVirtualFunctionTest15(end__input____input_local_offset_type());
return mLoader->end__input____InputLocalOffset();
}


bool MeshLoader15::begin__ph()
{
SaxVirtualFunctionTest15(begin__ph());
return mLoader->begin__ph();
}


bool MeshLoader15::end__ph()
{
SaxVirtualFunctionTest15(end__ph());
return mLoader->end__ph();
}


bool MeshLoader15::begin__p()
{
SaxVirtualFunctionTest15(begin__p());
return mLoader->begin__p();
}


bool MeshLoader15::end__p()
{
SaxVirtualFunctionTest15(end__p());
return mLoader->end__p();
}


bool MeshLoader15::data__p( const uint64* data, size_t length )
{
SaxVirtualFunctionTest15(data__p(data, length));
return mLoader->data__p(data, length);
}


bool MeshLoader15::begin__vcount()
{
SaxVirtualFunctionTest15(begin__vcount());
return mLoader->begin__vcount();
}


bool MeshLoader15::end__vcount()
{
SaxVirtualFunctionTest15(end__vcount());
return mLoader->end__vcount();
}


bool MeshLoader15::data__vcount( const uint64* data, size_t length )
{
SaxVirtualFunctionTest15(data__vcount(data, length));
return mLoader->data__vcount(data, length);
}


bool MeshLoader15::begin__h()
{
SaxVirtualFunctionTest15(begin__h());
return mLoader->begin__h();
}


bool MeshLoader15::end__h()
{
SaxVirtualFunctionTest15(end__h());
return mLoader->end__h();
}


bool MeshLoader15::data__h( const uint64* data, size_t length )
{
SaxVirtualFunctionTest15(data__h(data, length));
return mLoader->data__h(data, length);
}


bool MeshLoader15::begin__triangles( const COLLADASaxFWL15::triangles__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__triangles(attributeData));
COLLADASaxFWL::triangles__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL15::triangles__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::triangles__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::triangles__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__triangles(attrData);
}


bool MeshLoader15::end__triangles()
{
SaxVirtualFunctionTest15(end__triangles());
return mLoader->end__triangles();
}


bool MeshLoader15::begin__tristrips( const COLLADASaxFWL15::tristrips__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__tristrips(attributeData));
COLLADASaxFWL::tristrips__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL15::tristrips__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::tristrips__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::tristrips__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__tristrips(attrData);
}


bool MeshLoader15::end__tristrips()
{
SaxVirtualFunctionTest15(end__tristrips());
return mLoader->end__tristrips();
}


bool MeshLoader15::begin__trifans( const COLLADASaxFWL15::trifans__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__trifans(attributeData));
COLLADASaxFWL::trifans__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL15::trifans__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::trifans__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::trifans__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__trifans(attrData);
}


bool MeshLoader15::end__trifans()
{
SaxVirtualFunctionTest15(end__trifans());
return mLoader->end__trifans();
}


bool MeshLoader15::begin__polygons( const COLLADASaxFWL15::polygons__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__polygons(attributeData));
COLLADASaxFWL::polygons__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL15::polygons__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::polygons__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::polygons__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__polygons(attrData);
}


bool MeshLoader15::end__polygons()
{
SaxVirtualFunctionTest15(end__polygons());
return mLoader->end__polygons();
}


bool MeshLoader15::begin__polylist( const COLLADASaxFWL15::polylist__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__polylist(attributeData));
COLLADASaxFWL::polylist__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL15::polylist__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::polylist__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::polylist__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__polylist(attrData);
}


bool MeshLoader15::end__polylist()
{
SaxVirtualFunctionTest15(end__polylist());
return mLoader->end__polylist();
}


bool MeshLoader15::begin__lines( const COLLADASaxFWL15::lines__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__lines(attributeData));
COLLADASaxFWL::lines__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL15::lines__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::lines__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::lines__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__lines(attrData);
}


bool MeshLoader15::end__lines()
{
SaxVirtualFunctionTest15(end__lines());
return mLoader->end__lines();
}


bool MeshLoader15::begin__linestrips( const COLLADASaxFWL15::linestrips__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__linestrips(attributeData));
COLLADASaxFWL::linestrips__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL15::linestrips__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL15::linestrips__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::linestrips__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__linestrips(attrData);
}


bool MeshLoader15::end__linestrips()
{
SaxVirtualFunctionTest15(end__linestrips());
return mLoader->end__linestrips();
}


bool MeshLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool MeshLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
