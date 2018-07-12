/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_SCENELOADER15_H__
#define __COLLADASAXFWL_SCENELOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSceneLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class SceneLoader15 : public IParserImpl15
{
private:
SceneLoader* mLoader;

public:
SceneLoader15(SceneLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__instance_visual_scene( const COLLADASaxFWL15::instance_visual_scene__AttributeData& attributeData );

virtual bool end__instance_visual_scene();

virtual bool begin__instance_kinematics_scene( const COLLADASaxFWL15::instance_kinematics_scene__AttributeData& attributeData );

virtual bool end__instance_kinematics_scene();

virtual bool begin__bind_kinematics_model( const COLLADASaxFWL15::bind_kinematics_model__AttributeData& attributeData );

virtual bool end__bind_kinematics_model();

virtual bool begin__bind_joint_axis( const COLLADASaxFWL15::bind_joint_axis__AttributeData& attributeData );

virtual bool end__bind_joint_axis();

virtual bool begin__axis____common_sidref_or_param_type();

virtual bool end__axis____common_sidref_or_param_type();

virtual bool begin__value____common_float_or_param_type();

virtual bool end__value____common_float_or_param_type();

virtual bool begin__param____common_param_type();

virtual bool end__param____common_param_type();

virtual bool data__param____common_param_type( const ParserChar* value, size_t length );

virtual bool end__scene();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
SceneLoader15(const SceneLoader15&);
/** Disable default assignment operator. */
const SceneLoader15& operator=(const SceneLoader15&);
};
}
#endif // __COLLADASAXFWL_SCENELOADER15_H__
