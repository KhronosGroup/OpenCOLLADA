/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLNodeLoader15.h"


namespace COLLADASaxFWL
{


bool NodeLoader15::begin__node( const COLLADASaxFWL15::node__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__node(attributeData));
COLLADASaxFWL::node__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
switch (attributeData.type) {
case COLLADASaxFWL15::ENUM__node_enum__JOINT: attrData.type=COLLADASaxFWL::ENUM__NodeType__JOINT; break;
case COLLADASaxFWL15::ENUM__node_enum__NODE: attrData.type=COLLADASaxFWL::ENUM__NodeType__NODE; break;
case COLLADASaxFWL15::ENUM__node_enum__COUNT: attrData.type=COLLADASaxFWL::ENUM__NodeType__INVALID; break;
case COLLADASaxFWL15::ENUM__node_enum__NOT_PRESENT: attrData.type=COLLADASaxFWL::ENUM__NodeType__NOT_PRESENT; break;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::node__AttributeData::ATTRIBUTE_LAYER_PRESENT) == COLLADASaxFWL15::node__AttributeData::ATTRIBUTE_LAYER_PRESENT ) {
    attrData.layer = attributeData.layer;
    attrData.present_attributes |= COLLADASaxFWL::node__AttributeData::ATTRIBUTE_LAYER_PRESENT;
}
return mLoader->begin__node(attrData);
}


bool NodeLoader15::end__node()
{
SaxVirtualFunctionTest15(end__node());
return mLoader->end__node();
}


bool NodeLoader15::begin__translate( const COLLADASaxFWL15::translate__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__translate(attributeData));
COLLADASaxFWL::translate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__translate(attrData);
}


bool NodeLoader15::end__translate()
{
SaxVirtualFunctionTest15(end__translate());
return mLoader->end__translate();
}


bool NodeLoader15::data__translate( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__translate(data, length));
return mLoader->data__translate(data, length);
}


bool NodeLoader15::begin__rotate( const COLLADASaxFWL15::rotate__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__rotate(attributeData));
COLLADASaxFWL::rotate__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__rotate(attrData);
}


bool NodeLoader15::end__rotate()
{
SaxVirtualFunctionTest15(end__rotate());
return mLoader->end__rotate();
}


bool NodeLoader15::data__rotate( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__rotate(data, length));
return mLoader->data__rotate(data, length);
}


bool NodeLoader15::begin__matrix____matrix_type( const COLLADASaxFWL15::matrix____matrix_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__matrix____matrix_type(attributeData));
COLLADASaxFWL::matrix__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__matrix(attrData);
}


bool NodeLoader15::end__matrix____matrix_type()
{
SaxVirtualFunctionTest15(end__matrix____matrix_type());
return mLoader->end__matrix();
}


bool NodeLoader15::data__matrix____matrix_type( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__matrix____matrix_type(data, length));
return mLoader->data__matrix(data, length);
}


bool NodeLoader15::begin__scale( const COLLADASaxFWL15::scale__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__scale(attributeData));
COLLADASaxFWL::scale__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__scale(attrData);
}


bool NodeLoader15::end__scale()
{
SaxVirtualFunctionTest15(end__scale());
return mLoader->end__scale();
}


bool NodeLoader15::data__scale( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__scale(data, length));
return mLoader->data__scale(data, length);
}


bool NodeLoader15::begin__skew( const COLLADASaxFWL15::skew__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__skew(attributeData));
COLLADASaxFWL::skew__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__skew(attrData);
}


bool NodeLoader15::end__skew()
{
SaxVirtualFunctionTest15(end__skew());
return mLoader->end__skew();
}


bool NodeLoader15::data__skew( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__skew(data, length));
return mLoader->data__skew(data, length);
}


bool NodeLoader15::begin__lookat( const COLLADASaxFWL15::lookat__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__lookat(attributeData));
COLLADASaxFWL::lookat__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__lookat(attrData);
}


bool NodeLoader15::end__lookat()
{
SaxVirtualFunctionTest15(end__lookat());
return mLoader->end__lookat();
}


bool NodeLoader15::data__lookat( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__lookat(data, length));
return mLoader->data__lookat(data, length);
}


bool NodeLoader15::begin__instance_geometry( const COLLADASaxFWL15::instance_geometry__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_geometry(attributeData));
COLLADASaxFWL::instance_geometry__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_geometry__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_geometry(attrData);
}


bool NodeLoader15::end__instance_geometry()
{
SaxVirtualFunctionTest15(end__instance_geometry());
return mLoader->end__instance_geometry();
}


bool NodeLoader15::begin__bind_material()
{
SaxVirtualFunctionTest15(begin__bind_material());
return mLoader->begin__bind_material();
}


bool NodeLoader15::end__bind_material()
{
SaxVirtualFunctionTest15(end__bind_material());
return mLoader->end__bind_material();
}


bool NodeLoader15::begin__bind_material_type____technique_common()
{
SaxVirtualFunctionTest15(begin__bind_material_type____technique_common());
return mLoader->begin__bind_material__technique_common();
}


bool NodeLoader15::end__bind_material_type____technique_common()
{
SaxVirtualFunctionTest15(end__bind_material_type____technique_common());
return mLoader->end__bind_material__technique_common();
}


bool NodeLoader15::begin__instance_material____instance_material_type( const COLLADASaxFWL15::instance_material____instance_material_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_material____instance_material_type(attributeData));
COLLADASaxFWL::instance_material__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.symbol = attributeData.symbol;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_material____instance_material_type__AttributeData::ATTRIBUTE_TARGET_PRESENT) == COLLADASaxFWL15::instance_material____instance_material_type__AttributeData::ATTRIBUTE_TARGET_PRESENT ) {
    attrData.target = attributeData.target;
    attrData.present_attributes |= COLLADASaxFWL::instance_material__AttributeData::ATTRIBUTE_TARGET_PRESENT;
}
return mLoader->begin__instance_material(attrData);
}


bool NodeLoader15::end__instance_material____instance_material_type()
{
SaxVirtualFunctionTest15(end__instance_material____instance_material_type());
return mLoader->end__instance_material();
}


bool NodeLoader15::begin__bind_vertex_input( const COLLADASaxFWL15::bind_vertex_input__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__bind_vertex_input(attributeData));
COLLADASaxFWL::bind_vertex_input__AttributeData attrData;
attrData.present_attributes = 0;
attrData.semantic = attributeData.semantic;
attrData.input_semantic = attributeData.input_semantic;
if ( (attributeData.present_attributes & COLLADASaxFWL15::bind_vertex_input__AttributeData::ATTRIBUTE_INPUT_SET_PRESENT) == COLLADASaxFWL15::bind_vertex_input__AttributeData::ATTRIBUTE_INPUT_SET_PRESENT ) {
    attrData.input_set = attributeData.input_set;
    attrData.present_attributes |= COLLADASaxFWL::bind_vertex_input__AttributeData::ATTRIBUTE_INPUT_SET_PRESENT;
}
return mLoader->begin__bind_vertex_input(attrData);
}


bool NodeLoader15::end__bind_vertex_input()
{
SaxVirtualFunctionTest15(end__bind_vertex_input());
return mLoader->end__bind_vertex_input();
}


bool NodeLoader15::begin__instance_node( const COLLADASaxFWL15::instance_node__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_node(attributeData));
COLLADASaxFWL::instance_node__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_node__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_node__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_node__AttributeData::ATTRIBUTE_URL_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_node__AttributeData::ATTRIBUTE_PROXY_PRESENT) == COLLADASaxFWL15::instance_node__AttributeData::ATTRIBUTE_PROXY_PRESENT ) {
    attrData.proxy = attributeData.proxy;
    attrData.present_attributes |= COLLADASaxFWL::instance_node__AttributeData::ATTRIBUTE_PROXY_PRESENT;
}
return mLoader->begin__instance_node(attrData);
}


bool NodeLoader15::end__instance_node()
{
SaxVirtualFunctionTest15(end__instance_node());
return mLoader->end__instance_node();
}


bool NodeLoader15::begin__instance_camera( const COLLADASaxFWL15::instance_camera__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_camera(attributeData));
COLLADASaxFWL::instance_camera__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_camera__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_camera__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_camera__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_camera(attrData);
}


bool NodeLoader15::end__instance_camera()
{
SaxVirtualFunctionTest15(end__instance_camera());
return mLoader->end__instance_camera();
}


bool NodeLoader15::begin__instance_light( const COLLADASaxFWL15::instance_light__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_light(attributeData));
COLLADASaxFWL::instance_light__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_light__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_light__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_light__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_light(attrData);
}


bool NodeLoader15::end__instance_light()
{
SaxVirtualFunctionTest15(end__instance_light());
return mLoader->end__instance_light();
}


bool NodeLoader15::begin__instance_controller( const COLLADASaxFWL15::instance_controller__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_controller(attributeData));
COLLADASaxFWL::instance_controller__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_controller__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_controller__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_controller__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_controller(attrData);
}


bool NodeLoader15::end__instance_controller()
{
SaxVirtualFunctionTest15(end__instance_controller());
return mLoader->end__instance_controller();
}


bool NodeLoader15::begin__skeleton()
{
SaxVirtualFunctionTest15(begin__skeleton());
return mLoader->begin__skeleton();
}


bool NodeLoader15::end__skeleton()
{
SaxVirtualFunctionTest15(end__skeleton());
return mLoader->end__skeleton();
}


bool NodeLoader15::data__skeleton( COLLADABU::URI value )
{
SaxVirtualFunctionTest15(data__skeleton(value));
return mLoader->data__skeleton(value);
}



}
