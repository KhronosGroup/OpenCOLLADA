/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLVisualSceneLoader.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWIWriter.h"
#include "COLLADAFWExtraKeys.h"


namespace COLLADASaxFWL
{

	VisualSceneLoader::VisualSceneLoader( IFilePartLoader* callingFilePartLoader, const char* id )
		: FilePartLoader(callingFilePartLoader)
        , mVisualScene(new COLLADAFW::VisualScene(createUniqueIdFromId(id, COLLADAFW::VisualScene::ID())))
        , mInNode (false)
	{
		NodeLoader::setHandlingFilePartLoader(this);
	}

    //------------------------------
	VisualSceneLoader::~VisualSceneLoader()
	{
	}

    //------------------------------
    COLLADAFW::ExtraData* VisualSceneLoader::getExtraData ()
    {
        return mVisualScene;
    }

    //------------------------------
    const char* VisualSceneLoader::getSecondKey()
    {
        if ( !mInNode )
        {
            return COLLADAFW::ExtraKeys::VISUAL_SCENE;
        }
        else
        {
            if ( mParsingStatus & INSTANCE_CAMERA_BIT )
            {
                return COLLADAFW::ExtraKeys::INSTANCE_CAMERA;
            }
            else if ( mParsingStatus & INSTANCE_CONTROLLER_BIT )
            {
                if ( mParsingStatus & BIND_MATERIAL_BIT )
                {
                    if ( mParsingStatus & INSTANCE_MATERIAL_BIT )
                        return COLLADAFW::ExtraKeys::INSTANCE_MATERIAL_CONTROLLER;
                    else return COLLADAFW::ExtraKeys::BIND_MATERIAL_CONTROLLER;
                }
                else return COLLADAFW::ExtraKeys::INSTANCE_CONTROLLER;
            }
            else if ( mParsingStatus & INSTANCE_GEOMETRY_BIT )
            {
                if ( mParsingStatus & BIND_MATERIAL_BIT )
                {
                    if ( mParsingStatus & INSTANCE_MATERIAL_BIT )
                        return COLLADAFW::ExtraKeys::INSTANCE_MATERIAL_GEOMETRY;
                    else return COLLADAFW::ExtraKeys::BIND_MATERIAL_GEOMETRY;
                }
                else return COLLADAFW::ExtraKeys::INSTANCE_GEOMETRY;
            }
            else if ( mParsingStatus & INSTANCE_LIGHT_BIT )
            {
                return COLLADAFW::ExtraKeys::INSTANCE_LIGHT;
            }
            else if ( mParsingStatus & INSTANCE_NODE_BIT )
            {
                return COLLADAFW::ExtraKeys::INSTANCE_NODE;
            }
            else
            {
                return COLLADAFW::ExtraKeys::NODE;
            }
        }

        return 0;
    }

    //------------------------------
    const COLLADAFW::UniqueId& VisualSceneLoader::getUniqueId ()
    {
        return mVisualScene->getUniqueId ();
    }

	//------------------------------
	void VisualSceneLoader::handleRootNode( COLLADAFW::Node* rootNode )
	{
		mVisualScene->getRootNodes().append(rootNode);	
	}

	//------------------------------
	bool VisualSceneLoader::begin__visual_scene__node( const node__AttributeData& attributeData )
	{
        mInNode = true;
		return beginNode(attributeData);
	}

	//------------------------------
	bool VisualSceneLoader::end__visual_scene__node()
	{
        mInNode = false;
		return endNode();
	}

	//------------------------------
	bool VisualSceneLoader::end__visual_scene()
	{
		getFileLoader()->addVisualScene(mVisualScene);
		mVisualScene = 0;
		finish();
		moveUpInSidTree();
		return true;
	}

} // namespace COLLADASaxFWL
