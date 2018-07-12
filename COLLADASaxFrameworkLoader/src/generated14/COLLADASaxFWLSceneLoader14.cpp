/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSceneLoader14.h"


namespace COLLADASaxFWL
{


bool SceneLoader14::begin__instance_visual_scene( const COLLADASaxFWL14::instance_visual_scene__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__instance_visual_scene(attributeData));
COLLADASaxFWL::instance_visual_scene__AttributeData attrData;
attrData.present_attributes = 0;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL14::instance_visual_scene__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL14::instance_visual_scene__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_visual_scene__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_visual_scene(attrData);
}


bool SceneLoader14::end__instance_visual_scene()
{
SaxVirtualFunctionTest14(end__instance_visual_scene());
return mLoader->end__instance_visual_scene();
}


bool SceneLoader14::end__scene()
{
SaxVirtualFunctionTest14(end__scene());
return mLoader->end__scene();
}


bool SceneLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool SceneLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
