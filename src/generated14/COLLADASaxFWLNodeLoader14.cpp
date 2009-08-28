/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLNodeLoader14.h"


namespace COLLADASaxFWL
{


bool NodeLoader14::begin__node( const COLLADASaxFWL14::node__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__node(attributeData));
COLLADASaxFWL::node__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
switch (attributeData.type) {
case COLLADASaxFWL14::ENUM__NodeType__JOINT: attrData.type=COLLADASaxFWL::ENUM__NodeType__JOINT; break;
case COLLADASaxFWL14::ENUM__NodeType__NODE: attrData.type=COLLADASaxFWL::ENUM__NodeType__NODE; break;
case COLLADASaxFWL14::ENUM__NodeType__COUNT: attrData.type=COLLADASaxFWL::ENUM__NodeType__INVALID; break;
case COLLADASaxFWL14::ENUM__NodeType__NOT_PRESENT: attrData.type=COLLADASaxFWL::ENUM__NodeType__NOT_PRESENT; break;
}
if ( (attributeData.present_attributes & COLLADASaxFWL14::node__AttributeData::ATTRIBUTE_LAYER_PRESENT) == COLLADASaxFWL14::node__AttributeData::ATTRIBUTE_LAYER_PRESENT ) {
    attrData.layer = attributeData.layer;
    attrData.present_attributes |= COLLADASaxFWL::node__AttributeData::ATTRIBUTE_LAYER_PRESENT;
}
return mLoader->begin__node(attrData);
}


bool NodeLoader14::end__node()
{
SaxVirtualFunctionTest14(end__node());
return mLoader->end__node();
}


bool NodeLoader14::begin__translate( const COLLADASaxFWL14::translate__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__translate(attributeData));
COLLADASaxFWL::translate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__translate(attrData);
}


bool NodeLoader14::end__translate()
{
SaxVirtualFunctionTest14(end__translate());
return mLoader->end__translate();
}


bool NodeLoader14::data__translate( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__translate(data, length));
return mLoader->data__translate(data, length);
}


bool NodeLoader14::begin__rotate( const COLLADASaxFWL14::rotate__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__rotate(attributeData));
COLLADASaxFWL::rotate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__rotate(attrData);
}


bool NodeLoader14::end__rotate()
{
SaxVirtualFunctionTest14(end__rotate());
return mLoader->end__rotate();
}


bool NodeLoader14::data__rotate( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__rotate(data, length));
return mLoader->data__rotate(data, length);
}


bool NodeLoader14::begin__matrix( const COLLADASaxFWL14::matrix__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__matrix(attributeData));
COLLADASaxFWL::matrix__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__matrix(attrData);
}


bool NodeLoader14::end__matrix()
{
SaxVirtualFunctionTest14(end__matrix());
return mLoader->end__matrix();
}


bool NodeLoader14::data__matrix( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__matrix(data, length));
return mLoader->data__matrix(data, length);
}


bool NodeLoader14::begin__scale( const COLLADASaxFWL14::scale__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__scale(attributeData));
COLLADASaxFWL::scale__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__scale(attrData);
}


bool NodeLoader14::end__scale()
{
SaxVirtualFunctionTest14(end__scale());
return mLoader->end__scale();
}


bool NodeLoader14::data__scale( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__scale(data, length));
return mLoader->data__scale(data, length);
}


bool NodeLoader14::begin__skew( const COLLADASaxFWL14::skew__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__skew(attributeData));
COLLADASaxFWL::skew__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__skew(attrData);
}


bool NodeLoader14::end__skew()
{
SaxVirtualFunctionTest14(end__skew());
return mLoader->end__skew();
}


bool NodeLoader14::data__skew( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__skew(data, length));
return mLoader->data__skew(data, length);
}


bool NodeLoader14::begin__lookat( const COLLADASaxFWL14::lookat__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__lookat(attributeData));
COLLADASaxFWL::lookat__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__lookat(attrData);
}


bool NodeLoader14::end__lookat()
{
SaxVirtualFunctionTest14(end__lookat());
return mLoader->end__lookat();
}


bool NodeLoader14::data__lookat( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__lookat(data, length));
return mLoader->data__lookat(data, length);
}


bool NodeLoader14::begin__instance_geometry( const COLLADASaxFWL14::instance_geometry__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_geometry(attributeData));
COLLADASaxFWL::instance_geometry__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_geometry(attrData);
}


bool NodeLoader14::end__instance_geometry()
{
SaxVirtualFunctionTest14(end__instance_geometry());
return mLoader->end__instance_geometry();
}


bool NodeLoader14::begin__bind_material()
{
SaxVirtualFunctionTest14(begin__bind_material());
return mLoader->begin__bind_material();
}


bool NodeLoader14::end__bind_material()
{
SaxVirtualFunctionTest14(end__bind_material());
return mLoader->end__bind_material();
}


bool NodeLoader14::begin__bind_material__technique_common()
{
SaxVirtualFunctionTest14(begin__bind_material__technique_common());
return mLoader->begin__bind_material__technique_common();
}


bool NodeLoader14::end__bind_material__technique_common()
{
SaxVirtualFunctionTest14(end__bind_material__technique_common());
return mLoader->end__bind_material__technique_common();
}


bool NodeLoader14::begin__instance_material( const COLLADASaxFWL14::instance_material__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_material(attributeData));
COLLADASaxFWL::instance_material__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.symbol = attributeData.symbol;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_material__AttributeData::ATTRIBUTE_TARGET_PRESENT) == COLLADASaxFWL14::instance_material__AttributeData::ATTRIBUTE_TARGET_PRESENT ) {
    attrData.target = attributeData.target;
    attrData.present_attributes |= COLLADASaxFWL::instance_material__AttributeData::ATTRIBUTE_TARGET_PRESENT;
}
return mLoader->begin__instance_material(attrData);
}


bool NodeLoader14::end__instance_material()
{
SaxVirtualFunctionTest14(end__instance_material());
return mLoader->end__instance_material();
}


bool NodeLoader14::begin__bind_vertex_input( const COLLADASaxFWL14::bind_vertex_input__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__bind_vertex_input(attributeData));
COLLADASaxFWL::bind_vertex_input__AttributeData attrData;
attrData.present_attributes = 0;
attrData.semantic = attributeData.semantic;
attrData.input_semantic = attributeData.input_semantic;
if ( (attributeData.present_attributes & COLLADASaxFWL14::bind_vertex_input__AttributeData::ATTRIBUTE_INPUT_SET_PRESENT) == COLLADASaxFWL14::bind_vertex_input__AttributeData::ATTRIBUTE_INPUT_SET_PRESENT ) {
    attrData.input_set = attributeData.input_set;
    attrData.present_attributes |= COLLADASaxFWL::bind_vertex_input__AttributeData::ATTRIBUTE_INPUT_SET_PRESENT;
}
return mLoader->begin__bind_vertex_input(attrData);
}


bool NodeLoader14::end__bind_vertex_input()
{
SaxVirtualFunctionTest14(end__bind_vertex_input());
return mLoader->end__bind_vertex_input();
}


bool NodeLoader14::begin__instance_node( const COLLADASaxFWL14::instance_node__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_node(attributeData));
COLLADASaxFWL::instance_node__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_node__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_node__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_node__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_node(attrData);
}


bool NodeLoader14::end__instance_node()
{
SaxVirtualFunctionTest14(end__instance_node());
return mLoader->end__instance_node();
}


bool NodeLoader14::begin__instance_camera( const COLLADASaxFWL14::instance_camera__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_camera(attributeData));
COLLADASaxFWL::instance_camera__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_camera__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_camera__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_camera__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_camera(attrData);
}


bool NodeLoader14::end__instance_camera()
{
SaxVirtualFunctionTest14(end__instance_camera());
return mLoader->end__instance_camera();
}


bool NodeLoader14::begin__instance_light( const COLLADASaxFWL14::instance_light__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_light(attributeData));
COLLADASaxFWL::instance_light__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_light__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_light__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_light__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_light(attrData);
}


bool NodeLoader14::end__instance_light()
{
SaxVirtualFunctionTest14(end__instance_light());
return mLoader->end__instance_light();
}


bool NodeLoader14::begin__instance_controller( const COLLADASaxFWL14::instance_controller__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_controller(attributeData));
COLLADASaxFWL::instance_controller__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_controller__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_controller__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_controller__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_controller(attrData);
}


bool NodeLoader14::end__instance_controller()
{
SaxVirtualFunctionTest14(end__instance_controller());
return mLoader->end__instance_controller();
}


bool NodeLoader14::begin__skeleton()
{
SaxVirtualFunctionTest14(begin__skeleton());
return mLoader->begin__skeleton();
}


bool NodeLoader14::end__skeleton()
{
SaxVirtualFunctionTest14(end__skeleton());
return mLoader->end__skeleton();
}


bool NodeLoader14::data__skeleton( COLLADABU::URI value )
{
SaxVirtualFunctionTest14(data__skeleton(value));
return mLoader->data__skeleton(value);
}



}
