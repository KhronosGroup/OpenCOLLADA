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
    const COLLADAFW::UniqueId& VisualSceneLoader::getUniqueId()
    {
        if ( mCurrentInstanceController )
		{
			return mCurrentInstanceController->getUniqueId();
		}
        else if ( mCurrentInstanceGeometry )
		{
			return mCurrentInstanceGeometry->getUniqueId();
		}

		if ( !mNodeStack.empty() )
		{
			COLLADAFW::Node* currentNode = mNodeStack.top();
			return currentNode->getUniqueId();
		}

        if ( mVisualScene )
		{
			return mVisualScene->getUniqueId();
		}

        return COLLADAFW::UniqueId::INVALID;
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
