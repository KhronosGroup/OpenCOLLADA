/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/


#include "DAE2OgreOgreWriter.h"
#include "DAE2OgreMeshWriter.h"
#include "DAE2OgreSceneGraphWriter.h"

#include "COLLADASaxFWLLoader.h"

#include "COLLADAFWRoot.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWVisualScene.h"
#include "COLLADAFWInstanceGeometry.h"


#include <iostream>


namespace DAE2Ogre
{


	//--------------------------------------------------------------------
	OgreWriter::OgreWriter( const COLLADABU::URI& inputFile, const COLLADABU::URI& outputFile )
		: mInputFile(inputFile)
		, mOutputFile(outputFile)
		, mCurrentRun(SCENEGRAPH_RUN)
	, mVisualScene(0)
	{
	}

	//--------------------------------------------------------------------
	OgreWriter::~OgreWriter()
	{
		delete mVisualScene;
	}

	//--------------------------------------------------------------------
	void OgreWriter::reportError( const String& method, const String& message, Severity severity )
	{
		switch ( severity )
		{
		case SEVERITY_INFORMATION:
			std::cout << "Information"; 
			break;
		case SEVERITY_WARNING:
			std::cout << "Warning"; 
			break;
		case _SEVERITY_ERROR:
			std::cout << "Error"; 
			break;
		}
		if ( !method.empty() )
			std::cout << " in " << method;
		std::cout << ": ";
		std::cout << message << std::endl;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::write()
	{
		COLLADASaxFWL::Loader loader;
		COLLADAFW::Root root(&loader, this);

		// Load scene graph 
		if ( !root.loadDocument(mInputFile.toNativePath()) )
			return false;

		// if there is no visual scene in the COLLADA file, nothing to export here
		if ( mVisualScene )
		{
			SceneGraphWriter sceneGraphWriter(this, *mVisualScene, mLibrayNodesList);
			sceneGraphWriter.write();
		}

		// load and write geometries
		mCurrentRun = GEOMETRY_RUN;
		if ( !root.loadDocument(mInputFile.toNativePath()) )
			return false;

		return true;
	}

	//--------------------------------------------------------------------
	void OgreWriter::cancel( const String& errorMessage )
	{
	}

	//--------------------------------------------------------------------
	void OgreWriter::start()
	{
	}

	//--------------------------------------------------------------------
	void OgreWriter::finish()
	{
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeGlobalAsset( const COLLADAFW::FileInfo* asset )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeVisualScene( const COLLADAFW::VisualScene* visualScene )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		// todo. handle multiple occurences of visual scene properly. This is just a quick fix
		if ( mVisualScene )
		{
			delete mVisualScene;
		}
		mVisualScene = new COLLADAFW::VisualScene(*visualScene);
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeScene( const COLLADAFW::Scene* scene )
	{
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		mLibrayNodesList.push_back(*libraryNodes);
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeGeometry( const COLLADAFW::Geometry* geometry )
	{
		if ( mCurrentRun != GEOMETRY_RUN )
			return true;
		if ( geometry->getType() != COLLADAFW::Geometry::GEO_TYPE_MESH )
			return true;
	
		MeshWriter meshWriter( this, (COLLADAFW::Mesh*)geometry );
		return meshWriter.write();
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeMaterial( const COLLADAFW::Material* material )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		mUniqueIdFWMaterialMap.insert(std::make_pair(material->getUniqueId(),*material ));
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeEffect( const COLLADAFW::Effect* effect )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		mUniqueIdFWEffectMap.insert(std::make_pair(effect->getUniqueId(),*effect ));
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeCamera( const COLLADAFW::Camera* camera )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeImage( const COLLADAFW::Image* image )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		mUniqueIdFWImageMap.insert(std::make_pair(image->getUniqueId(),*image ));
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeLight( const COLLADAFW::Light* light )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeAnimation( const COLLADAFW::Animation* animation )
	{
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeAnimationList( const COLLADAFW::AnimationList* animationList )
	{
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeSkinControllerData( const COLLADAFW::SkinControllerData* skinControllerData )
	{
		return true;
	}

	//--------------------------------------------------------------------
	bool OgreWriter::writeController( const COLLADAFW::Controller* Controller )
	{
		return true;
	}

} // namespace DAE2Ogre
