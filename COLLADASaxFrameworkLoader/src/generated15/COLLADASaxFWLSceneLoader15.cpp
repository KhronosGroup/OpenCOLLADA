/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSceneLoader15.h"


namespace COLLADASaxFWL
{


bool SceneLoader15::begin__instance_visual_scene( const COLLADASaxFWL15::instance_visual_scene__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_visual_scene(attributeData));
COLLADASaxFWL::instance_visual_scene__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_visual_scene__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_visual_scene__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_visual_scene__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_visual_scene(attrData);
}


bool SceneLoader15::end__instance_visual_scene()
{
SaxVirtualFunctionTest15(end__instance_visual_scene());
return mLoader->end__instance_visual_scene();
}


bool SceneLoader15::begin__instance_kinematics_scene( const COLLADASaxFWL15::instance_kinematics_scene__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_kinematics_scene(attributeData));
COLLADASaxFWL::instance_kinematics_scene__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_kinematics_scene__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_kinematics_scene__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_kinematics_scene__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_kinematics_scene(attrData);
}


bool SceneLoader15::end__instance_kinematics_scene()
{
SaxVirtualFunctionTest15(end__instance_kinematics_scene());
return mLoader->end__instance_kinematics_scene();
}


bool SceneLoader15::begin__bind_kinematics_model( const COLLADASaxFWL15::bind_kinematics_model__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__bind_kinematics_model(attributeData));
COLLADASaxFWL::bind_kinematics_model__AttributeData attrData;
attrData.node = attributeData.node;
return mLoader->begin__bind_kinematics_model(attrData);
}


bool SceneLoader15::end__bind_kinematics_model()
{
SaxVirtualFunctionTest15(end__bind_kinematics_model());
return mLoader->end__bind_kinematics_model();
}


bool SceneLoader15::begin__bind_joint_axis( const COLLADASaxFWL15::bind_joint_axis__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__bind_joint_axis(attributeData));
COLLADASaxFWL::bind_joint_axis__AttributeData attrData;
attrData.target = attributeData.target;
return mLoader->begin__bind_joint_axis(attrData);
}


bool SceneLoader15::end__bind_joint_axis()
{
SaxVirtualFunctionTest15(end__bind_joint_axis());
return mLoader->end__bind_joint_axis();
}


bool SceneLoader15::begin__axis____common_sidref_or_param_type()
{
SaxVirtualFunctionTest15(begin__axis____common_sidref_or_param_type());
return mLoader->begin__axis____common_sidref_or_param_type();
}


bool SceneLoader15::end__axis____common_sidref_or_param_type()
{
SaxVirtualFunctionTest15(end__axis____common_sidref_or_param_type());
return mLoader->end__axis____common_sidref_or_param_type();
}


bool SceneLoader15::begin__value____common_float_or_param_type()
{
SaxVirtualFunctionTest15(begin__value____common_float_or_param_type());
return mLoader->begin__value____common_float_or_param_type();
}


bool SceneLoader15::end__value____common_float_or_param_type()
{
SaxVirtualFunctionTest15(end__value____common_float_or_param_type());
return mLoader->end__value____common_float_or_param_type();
}


bool SceneLoader15::begin__param____common_param_type()
{
SaxVirtualFunctionTest15(begin__param____common_param_type());
return mLoader->begin__param____common_param_type();
}


bool SceneLoader15::end__param____common_param_type()
{
SaxVirtualFunctionTest15(end__param____common_param_type());
return mLoader->end__param____common_param_type();
}


bool SceneLoader15::data__param____common_param_type( const ParserChar* value, size_t length )
{
SaxVirtualFunctionTest15(data__param____common_param_type(value, length));
return mLoader->data__param____common_param_type(value, length);
}


bool SceneLoader15::end__scene()
{
SaxVirtualFunctionTest15(end__scene());
return mLoader->end__scene();
}


bool SceneLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool SceneLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
