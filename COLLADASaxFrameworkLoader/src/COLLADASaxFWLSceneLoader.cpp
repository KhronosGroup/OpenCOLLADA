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
#include "COLLADASaxFWLFileLoader.h"


namespace COLLADASaxFWL
{

    //------------------------------
	SceneLoader::SceneLoader ( IFilePartLoader* callingFilePartLoader )
        : FilePartLoader(callingFilePartLoader)
        , mCurrentScene ( new COLLADAFW::Scene (createUniqueId(COLLADAFW::Scene::ID())) )
		, mCurrentInstanceKinematicsScene(0)
		, mCurrentBindJointAxis(0)
		, mCurrentCharacterData()
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
		mCurrentInstanceKinematicsScene = new KinematicsInstanceKinematicsScene();
		const COLLADABU::URI& fileUri = getFileLoader()->getFileUri();
		COLLADABU::URI url(fileUri, attributeData.url.getURIString());
		mCurrentInstanceKinematicsScene->setUrl( url);
		return true;
	}

	//------------------------------
	bool SceneLoader::end__instance_kinematics_scene()
	{
		getFileLoader()->addInstanceKinematicsScene( mCurrentInstanceKinematicsScene );
		mCurrentInstanceKinematicsScene = 0;
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
	bool SceneLoader::end__bind_kinematics_model()
	{
		mCurrentCharacterData.clear();
		return true;
	}

	//------------------------------
	bool SceneLoader::begin__bind_joint_axis( const bind_joint_axis__AttributeData& attributeData )
	{
		
		mCurrentBindJointAxis = new KinematicsBindJointAxis(String(attributeData.target));

		const ParserChar* target = attributeData.target;
		if ( target )
		{
			//find first occurrence of a "/" in target
			const ParserChar* p = target;
			while ( (*p!=0) && (*p!='/') )
			{
				++p;
			}
			const COLLADAFW::UniqueId nodeUniqueId = getUniqueIdById(String(target, p-target).c_str());
			if ( nodeUniqueId.isValid() )
			{
				mBoundNodes.insert(nodeUniqueId);
			}
		}
		return true;
	}

	//------------------------------
	bool SceneLoader::end__bind_joint_axis()
	{
		mCurrentInstanceKinematicsScene->addBindJointAxis( mCurrentBindJointAxis );
		mCurrentBindJointAxis = 0;
		return true;
	}

	//------------------------------
	bool SceneLoader::begin__axis____common_sidref_or_param_type()
	{
		return true;
	}

	//------------------------------
	bool SceneLoader::end__axis____common_sidref_or_param_type()
	{
		mCurrentBindJointAxis->getAxis().setParamValue(mCurrentCharacterData);
		mCurrentCharacterData.clear();
		return true;
	}

	//------------------------------
	bool SceneLoader::begin__value____common_float_or_param_type()
	{
		return true;
	}

	//------------------------------
	bool SceneLoader::end__value____common_float_or_param_type()
	{
		mCurrentBindJointAxis->getValue().setParamValue(mCurrentCharacterData);
		mCurrentCharacterData.clear();
		return true;
	}

	//------------------------------
	bool SceneLoader::begin__param____common_param_type()
	{
		return true;
	}

	//------------------------------
	bool SceneLoader::end__param____common_param_type()
	{
		return true;
	}

	//------------------------------
	bool SceneLoader::data__param____common_param_type( const ParserChar* value, size_t length )
	{
		mCurrentCharacterData.append( value, length );
		return true;
	}

} // namespace COLLADASaxFWL
