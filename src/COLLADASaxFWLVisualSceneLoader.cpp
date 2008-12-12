/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLVisualSceneLoader.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWIWriter.h"


namespace COLLADASaxFWL
{

	VisualSceneLoader::VisualSceneLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
	{
		mVisualScene = new COLLADAFW::VisualScene();
	}

    //------------------------------
	VisualSceneLoader::~VisualSceneLoader()
	{
	}

	//------------------------------
	bool VisualSceneLoader::beginNode( const char* nodeName )
	{
		COLLADAFW::Node* newNode = new COLLADAFW::Node();

		if ( nodeName )
			newNode->setName(nodeName);

		if ( mNodeStack.empty() )
		{
			// we are a direct child of the visual scene
			mVisualScene->getRootNodes().append(newNode);
		}
		else
		{
			//we are a child of another node
			COLLADAFW::Node* parentNode = mNodeStack.top();
			parentNode->getChildNodes().append(newNode);
		}
		mNodeStack.push(newNode);
		return true;
	}

	//------------------------------
	bool VisualSceneLoader::endNode()
	{
		mNodeStack.pop();
		return true;
	}


	//------------------------------
	bool VisualSceneLoader::begin__visual_scene__node( const visual_scene__node__AttributeData& attributeData )
	{
		return beginNode((const char *)attributeData.name);
	}

	//------------------------------
	bool VisualSceneLoader::end__visual_scene__node()
	{
		return endNode();
	}

	bool VisualSceneLoader::end__visual_scene()
	{
		bool success = writer()->writeVisualScene(mVisualScene);
		delete mVisualScene;
		finish();
		return success;
	}

} // namespace COLLADASaxFWL
