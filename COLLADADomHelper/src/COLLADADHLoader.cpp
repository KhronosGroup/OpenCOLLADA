/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADADomHelper.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADALoader.h"
#include "COLLADAVisualSceneLoader.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWIWriter.h"

namespace COLLADADH
{
	//--------------------------------------------------------------------
	Loader::Loader()
	{
	}

	//--------------------------------------------------------------------
	Loader::~Loader()
	{
	}

	bool Loader::loadDocument( const String& fileName, COLLADAFW::IWriter* writer )
	{
		if ( !writer )
			return false;

		mWriter = writer;

		mDomCollada = mDae.open ( fileName );

		if ( !mDomCollada )
			return false;

		daeDocument* daeDoc = mDomCollada->getDocument();

		if ( !loadVisualScenes() )
			return false;

		return true;
	}

	bool Loader::loadVisualScenes()
	{
		const domCOLLADA::domSceneRef colladaScene = mDomCollada->getScene();
		if ( !colladaScene )
			return true;

		const domInstanceWithExtraRef colladaInstanceVisualScene = colladaScene->getInstance_visual_scene();
		if ( !colladaInstanceVisualScene )
			return true;

		domVisual_sceneRef colladaVisualScene = daeSafeCast<domVisual_scene>(colladaInstanceVisualScene->getUrl().getElement());
		if ( !colladaVisualScene )
			return true;

		VisualSceneLoader visualSceneLoader(this, colladaVisualScene);
		COLLADAFW::VisualScene* visualScene = visualSceneLoader.load();
		if ( visualScene )
		{
			mWriter->writeVisualScene(visualScene);
			delete visualScene;
		}

		return true;
	}


} // namespace COLLADA
