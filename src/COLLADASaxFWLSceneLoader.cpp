/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSceneLoader.h"
#include "COLLADASaxFWLLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWVisualScene.h"


namespace COLLADASaxFWL
{

    //------------------------------
	SceneLoader::SceneLoader ( IFilePartLoader* callingFilePartLoader )
        : FilePartLoader(callingFilePartLoader)
        , mCurrentScene ( new COLLADAFW::Scene () )
	{
	}
	
    //------------------------------
	SceneLoader::~SceneLoader ()
	{
	}

    //------------------------------
    bool SceneLoader::begin__instance_visual_scene ( const instance_visual_scene__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest(begin__instance_visual_scene(attributeData));

        COLLADAFW::UniqueId visualSceneUniqueId = getUniqueIdFromUrl( attributeData.url, COLLADAFW::VisualScene::ID() );
        mCurrentScene->setInstanceVisualScene ( FW_NEW COLLADAFW::InstanceVisualScene(visualSceneUniqueId) );

        return true;
    }

    //------------------------------
    bool SceneLoader::end__instance_visual_scene ()
    {
        return true;
    }

    //------------------------------
    bool SceneLoader::end__scene()
    {
        SaxVirtualFunctionTest(end__scene());
        bool success = true;
		if ( (getObjectFlags() & Loader::SCENE_FLAG) != 0 )
		{
			success = writer()->writeScene ( mCurrentScene );
		}
        delete mCurrentScene;
        finish();
        return success;
    }



} // namespace COLLADASaxFWL
