/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
        , mCurrentScene ( new COLLADAFW::Scene (createUniqueId(COLLADAFW::Scene::ID())) )
	{
	}
	
    //------------------------------
	SceneLoader::~SceneLoader ()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& SceneLoader::getUniqueId ()
    {
        if ( mCurrentScene )
            return mCurrentScene->getUniqueId ();
        return COLLADAFW::UniqueId::INVALID;
    }

    //------------------------------
    bool SceneLoader::begin__instance_visual_scene ( const instance_visual_scene__AttributeData& attributeData )
    {
        COLLADAFW::UniqueId visualSceneUniqueId = createUniqueIdFromUrl ( attributeData.url, COLLADAFW::VisualScene::ID() );
        COLLADAFW::UniqueId instanceVisualSceneUniqueId = createUniqueId ( COLLADAFW::InstanceVisualScene::ID() );
        mCurrentScene->setInstanceVisualScene ( FW_NEW COLLADAFW::InstanceVisualScene(instanceVisualSceneUniqueId, visualSceneUniqueId) );

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
