/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLMeshLoader14.h"


namespace COLLADASaxFWL
{


bool MeshLoader14::begin__source( const COLLADASaxFWL14::source__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__source(attributeData));
COLLADASaxFWL::source__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__source(attrData);
}


bool MeshLoader14::end__source()
{
SaxVirtualFunctionTest14(end__source());
return mLoader->end__source();
}


bool MeshLoader14::end__mesh()
{
SaxVirtualFunctionTest14(end__mesh());
return mLoader->end__mesh();
}


bool MeshLoader14::begin__vertices( const COLLADASaxFWL14::vertices__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__vertices(attributeData));
COLLADASaxFWL::vertices__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__vertices(attrData);
}


bool MeshLoader14::end__vertices()
{
SaxVirtualFunctionTest14(end__vertices());
return mLoader->end__vertices();
}


bool MeshLoader14::begin__input____InputLocal( const COLLADASaxFWL14::input____InputLocal__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__input____InputLocal(attributeData));
COLLADASaxFWL::input____InputLocal__AttributeData attrData;
attrData.semantic = attributeData.semantic;
attrData.source = attributeData.source;
return mLoader->begin__input____InputLocal(attrData);
}


bool MeshLoader14::end__input____InputLocal()
{
SaxVirtualFunctionTest14(end__input____InputLocal());
return mLoader->end__input____InputLocal();
}


bool MeshLoader14::begin__input____InputLocalOffset( const COLLADASaxFWL14::input____InputLocalOffset__AttributeData& attributeData )
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


bool MeshLoader14::end__input____InputLocalOffset()
{
SaxVirtualFunctionTest14(end__input____InputLocalOffset());
return mLoader->end__input____InputLocalOffset();
}


bool MeshLoader14::begin__ph()
{
SaxVirtualFunctionTest14(begin__ph());
return mLoader->begin__ph();
}


bool MeshLoader14::end__ph()
{
SaxVirtualFunctionTest14(end__ph());
return mLoader->end__ph();
}


bool MeshLoader14::begin__p()
{
SaxVirtualFunctionTest14(begin__p());
return mLoader->begin__p();
}


bool MeshLoader14::end__p()
{
SaxVirtualFunctionTest14(end__p());
return mLoader->end__p();
}


bool MeshLoader14::data__p( const uint64* data, size_t length )
{
SaxVirtualFunctionTest14(data__p(data, length));
return mLoader->data__p(data, length);
}


bool MeshLoader14::begin__vcount()
{
SaxVirtualFunctionTest14(begin__vcount());
return mLoader->begin__vcount();
}


bool MeshLoader14::end__vcount()
{
SaxVirtualFunctionTest14(end__vcount());
return mLoader->end__vcount();
}


bool MeshLoader14::data__vcount( const uint64* data, size_t length )
{
SaxVirtualFunctionTest14(data__vcount(data, length));
return mLoader->data__vcount(data, length);
}


bool MeshLoader14::begin__h()
{
SaxVirtualFunctionTest14(begin__h());
return mLoader->begin__h();
}


bool MeshLoader14::end__h()
{
SaxVirtualFunctionTest14(end__h());
return mLoader->end__h();
}


bool MeshLoader14::data__h( const uint64* data, size_t length )
{
SaxVirtualFunctionTest14(data__h(data, length));
return mLoader->data__h(data, length);
}


bool MeshLoader14::begin__triangles( const COLLADASaxFWL14::triangles__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__triangles(attributeData));
COLLADASaxFWL::triangles__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL14::triangles__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::triangles__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::triangles__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__triangles(attrData);
}


bool MeshLoader14::end__triangles()
{
SaxVirtualFunctionTest14(end__triangles());
return mLoader->end__triangles();
}


bool MeshLoader14::begin__tristrips( const COLLADASaxFWL14::tristrips__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__tristrips(attributeData));
COLLADASaxFWL::tristrips__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL14::tristrips__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::tristrips__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::tristrips__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__tristrips(attrData);
}


bool MeshLoader14::end__tristrips()
{
SaxVirtualFunctionTest14(end__tristrips());
return mLoader->end__tristrips();
}


bool MeshLoader14::begin__trifans( const COLLADASaxFWL14::trifans__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__trifans(attributeData));
COLLADASaxFWL::trifans__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL14::trifans__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::trifans__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::trifans__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__trifans(attrData);
}


bool MeshLoader14::end__trifans()
{
SaxVirtualFunctionTest14(end__trifans());
return mLoader->end__trifans();
}


bool MeshLoader14::begin__polygons( const COLLADASaxFWL14::polygons__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__polygons(attributeData));
COLLADASaxFWL::polygons__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL14::polygons__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::polygons__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::polygons__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__polygons(attrData);
}


bool MeshLoader14::end__polygons()
{
SaxVirtualFunctionTest14(end__polygons());
return mLoader->end__polygons();
}


bool MeshLoader14::begin__polylist( const COLLADASaxFWL14::polylist__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__polylist(attributeData));
COLLADASaxFWL::polylist__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL14::polylist__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::polylist__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::polylist__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__polylist(attrData);
}


bool MeshLoader14::end__polylist()
{
SaxVirtualFunctionTest14(end__polylist());
return mLoader->end__polylist();
}


bool MeshLoader14::begin__lines( const COLLADASaxFWL14::lines__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__lines(attributeData));
COLLADASaxFWL::lines__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL14::lines__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::lines__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::lines__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__lines(attrData);
}


bool MeshLoader14::end__lines()
{
SaxVirtualFunctionTest14(end__lines());
return mLoader->end__lines();
}


bool MeshLoader14::begin__linestrips( const COLLADASaxFWL14::linestrips__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__linestrips(attributeData));
COLLADASaxFWL::linestrips__AttributeData attrData;
attrData.present_attributes = 0;
attrData.name = attributeData.name;
attrData.material = attributeData.material;
if ( (attributeData.present_attributes & COLLADASaxFWL14::linestrips__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::linestrips__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
    attrData.count = attributeData.count;
    attrData.present_attributes |= COLLADASaxFWL::linestrips__AttributeData::ATTRIBUTE_COUNT_PRESENT;
}
return mLoader->begin__linestrips(attrData);
}


bool MeshLoader14::end__linestrips()
{
SaxVirtualFunctionTest14(end__linestrips());
return mLoader->end__linestrips();
}


bool MeshLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool MeshLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
