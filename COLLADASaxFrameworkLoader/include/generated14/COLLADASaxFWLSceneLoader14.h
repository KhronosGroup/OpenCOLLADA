/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_SCENELOADER14_H__
#define __COLLADASAXFWL_SCENELOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSceneLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class SceneLoader14 : public IParserImpl14
{
private:
SceneLoader* mLoader;

public:
SceneLoader14(SceneLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__instance_visual_scene( const COLLADASaxFWL14::instance_visual_scene__AttributeData& attributeData );

virtual bool end__instance_visual_scene();

virtual bool end__scene();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
SceneLoader14(const SceneLoader14&);
/** Disable default assignment operator. */
const SceneLoader14& operator=(const SceneLoader14&);
};
}
#endif // __COLLADASAXFWL_SCENELOADER14_H__
