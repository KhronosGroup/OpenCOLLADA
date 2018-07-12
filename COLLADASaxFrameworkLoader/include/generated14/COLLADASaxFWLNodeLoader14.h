/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_NODELOADER14_H__
#define __COLLADASAXFWL_NODELOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLNodeLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class NodeLoader14 : public IParserImpl14
{
private:
NodeLoader* mLoader;

public:
NodeLoader14(NodeLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__node( const COLLADASaxFWL14::node__AttributeData& attributeData );

virtual bool end__node();

virtual bool begin__translate( const COLLADASaxFWL14::translate__AttributeData& attributeData );

virtual bool end__translate();

virtual bool data__translate( const float* data, size_t length );

virtual bool begin__rotate( const COLLADASaxFWL14::rotate__AttributeData& attributeData );

virtual bool end__rotate();

virtual bool data__rotate( const float* data, size_t length );

virtual bool begin__matrix( const COLLADASaxFWL14::matrix__AttributeData& attributeData );

virtual bool end__matrix();

virtual bool data__matrix( const float* data, size_t length );

virtual bool begin__scale( const COLLADASaxFWL14::scale__AttributeData& attributeData );

virtual bool end__scale();

virtual bool data__scale( const float* data, size_t length );

virtual bool begin__skew( const COLLADASaxFWL14::skew__AttributeData& attributeData );

virtual bool end__skew();

virtual bool data__skew( const float* data, size_t length );

virtual bool begin__lookat( const COLLADASaxFWL14::lookat__AttributeData& attributeData );

virtual bool end__lookat();

virtual bool data__lookat( const float* data, size_t length );

virtual bool begin__instance_geometry( const COLLADASaxFWL14::instance_geometry__AttributeData& attributeData );

virtual bool end__instance_geometry();

virtual bool begin__bind_material();

virtual bool end__bind_material();

virtual bool begin__bind_material__technique_common();

virtual bool end__bind_material__technique_common();

virtual bool begin__instance_material( const COLLADASaxFWL14::instance_material__AttributeData& attributeData );

virtual bool end__instance_material();

virtual bool begin__bind_vertex_input( const COLLADASaxFWL14::bind_vertex_input__AttributeData& attributeData );

virtual bool end__bind_vertex_input();

virtual bool begin__instance_node( const COLLADASaxFWL14::instance_node__AttributeData& attributeData );

virtual bool end__instance_node();

virtual bool begin__instance_camera( const COLLADASaxFWL14::instance_camera__AttributeData& attributeData );

virtual bool end__instance_camera();

virtual bool begin__instance_light( const COLLADASaxFWL14::instance_light__AttributeData& attributeData );

virtual bool end__instance_light();

virtual bool begin__instance_controller( const COLLADASaxFWL14::instance_controller__AttributeData& attributeData );

virtual bool end__instance_controller();

virtual bool begin__skeleton();

virtual bool end__skeleton();

virtual bool data__skeleton( COLLADABU::URI value );


private:
/** Disable default copy ctor. */
NodeLoader14(const NodeLoader14&);
/** Disable default assignment operator. */
const NodeLoader14& operator=(const NodeLoader14&);
};
}
#endif // __COLLADASAXFWL_NODELOADER14_H__
