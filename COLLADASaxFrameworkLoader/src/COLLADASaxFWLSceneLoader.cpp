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

	//------------------------------
	bool SceneLoader::begin__instance_kinematics_scene( const instance_kinematics_scene__AttributeData& attributeData )
	{
		return true;
	}

	//------------------------------
	bool SceneLoader::end__instance_kinematics_scene()
	{
		if ( !mBoundNodes.empty() )
		{
			size_t boundNodesCount = mBoundNodes.size();
			COLLADAFW::InstanceKinematicsScene* instanceKinematicsScene = FW_NEW COLLADAFW::InstanceKinematicsScene(createUniqueId(COLLADAFW::InstanceKinematicsScene::ID()), COLLADAFW::UniqueId::INVALID);
			mCurrentScene->setInstanceKinematicsScene( instanceKinematicsScene );
			COLLADAFW::UniqueIdArray& boundNodes = instanceKinematicsScene->getBoundNodes();
			boundNodes.allocMemory(boundNodesCount);
			boundNodes.setCount(boundNodesCount);
			UniqueIdSet::const_iterator it = mBoundNodes.begin();
			for ( size_t i = 0; it != mBoundNodes.end(); ++it, ++i )
			{
				boundNodes[i] = *it;
			}
		}

		return true;
	}

	//------------------------------
	bool SceneLoader::begin__bind_joint_axis( const bind_joint_axis__AttributeData& attributeData )
	{
		const ParserChar* target = attributeData.target;
		if ( target )
		{
			//find first occurrence of a "/" in target
			const ParserChar* p = target;
			while ( (*p!=0) && (*p!='/') )
			{
				++p;
			}
			const COLLADAFW::UniqueId nodeUniqueId = createUniqueIdFromId(String(target, p-target).c_str());
			if ( nodeUniqueId.isValid() )
			{
				mBoundNodes.insert(nodeUniqueId);
			}
		}
		return true;
	}

} // namespace COLLADASaxFWL
