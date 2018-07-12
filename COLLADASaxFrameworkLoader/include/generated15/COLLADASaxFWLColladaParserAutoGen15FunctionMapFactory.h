/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL15_FUNCTIONMAPFACTORY_H__
#define __COLLADASAXFWL15_FUNCTIONMAPFACTORY_H__

#include "COLLADASaxFWLColladaParserAutoGen15Private.h"

namespace COLLADASaxFWL15
{

class FunctionMapFactory {
public:

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__COLLADA__1level();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__asset__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__scene__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_animation_clips__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_animations__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_cameras__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_controllers__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_effects__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_force_fields__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_geometries__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_images__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_lights__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_materials__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_nodes__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_physics_materials__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_physics_models__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_physics_scenes__allChildren();

static const ColladaParserAutoGen15Private::ElementFunctionMap& createFunctionMap__library_visual_scenes__allChildren();

private:
/** Disable default copy ctor. */
FunctionMapFactory( const FunctionMapFactory& pre );
/** Disable default assignment operator. */
const FunctionMapFactory& operator= ( const FunctionMapFactory& pre );
};
} // namespace
#endif
