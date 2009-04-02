/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxDocumentImporter.h"
#include "COLLADAMaxVisualSceneImporter.h"
#include "COLLADAMaxLibraryNodesImporter.h"
#include "COLLADAMaxGeometryImporter.h"
#include "COLLADAMaxMaterialImporter.h"
#include "COLLADAMaxMaterialCreator.h"
#include "COLLADAMaxEffectImporter.h"
#include "COLLADAMaxCameraImporter.h"
#include "COLLADAMaxLightImporter.h"
#include "COLLADAMaxImageImporter.h"
#include "COLLADAMaxAnimationImporter.h"
#include "COLLADAMaxAnimationListImporter.h"
#include "COLLADAMaxAnimationAssigner.h"
#include "COLLADAMaxSceneGraphCreator.h"
#include "COLLADAMaxFWLErrorHandler.h"

#include "COLLADAFWFileInfo.h"

#include "COLLADAFWLibraryNodes.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWVisualScene.h"


#include "COLLADASaxFWLLoader.h"
#include "COLLADAFWRoot.h"

namespace COLLADAMax
{
	//--------------------------------------------------------------------
	DocumentImporter::DocumentImporter(Interface * maxInterface, ImpInterface* maxImportInterface, const NativeString &filepath)
		: mMaxInterface(maxInterface)
		, mMaxImportInterface(maxImportInterface)
		, mImportFilePath(filepath)
		, mNumberOfAmbientColors(0)
		, mDummyObject((DummyObject*) getMaxImportInterface()->Create(HELPER_CLASS_ID, Class_ID(DUMMY_CLASS_ID, 0)))
	{
	}
	
	//--------------------------------------------------------------------
	DocumentImporter::~DocumentImporter()
	{
		// Delete all the stored library nodes
		for ( LibraryNodesList::const_iterator it = mLibraryNodesList.begin(); it != mLibraryNodesList.end(); ++it)
			delete *it;

		// Delete all the stored library nodes
		for ( UniqueIdVisualSceneMap::const_iterator it = mUniqueIdVisualSceneMap.begin(); it != mUniqueIdVisualSceneMap.end(); ++it)
			delete it->second;

		// Delete all the animation lists
		for ( UniqueIdAnimationListMap::const_iterator it = mUniqueIdAnimationListMap.begin(); it != mUniqueIdAnimationListMap.end(); ++it)
			delete it->second;
	}


	//---------------------------------------------------------------
	bool DocumentImporter::import()
	{
		FWLErrorHandler errorHandler;
		COLLADASaxFWL::Loader loader(&errorHandler);
		COLLADAFW::Root root(&loader, this);

//		return root.loadDocument("dsfsdf.dae");
		if ( !root.loadDocument(mImportFilePath) )
			return false;

		if ( (mNumberOfAmbientColors > 0) && mAmbientColor.isValid() )
		{
			mMaxImportInterface->SetAmbient(0, Point3(mAmbientColor.getRed(), mAmbientColor.getGreen(), mAmbientColor.getBlue() ));
		}

		if ( !createSceneGraph() )
			return false;

		if ( !createAndAssignMaterials() )
			return false;

		if ( !assignControllers() )
			return false;

		return true;
	}

	//---------------------------------------------------------------
	void* DocumentImporter::createMaxObject(SClass_ID superClassId, Class_ID classId)
	{
		void* c = mMaxImportInterface->Create(superClassId, classId);

		if ( !c )
		{
			// This can be caused if the object referred to is in a deffered plugin.
			DllDir* dllDir = GetCOREInterface()->GetDllDirectory();
			ClassDirectory& classDir = dllDir->ClassDir();
			ClassEntry* classEntry = classDir.FindClassEntry(superClassId, classId);

			if ( !classEntry )
				return 0;

			// This will force the loading of the specified plugin
			classEntry->FullCD();

			if ( !classEntry->IsLoaded() )
				return 0;

			c = mMaxImportInterface->Create(superClassId, classId);
		}
		return c;
	}

	//---------------------------------------------------------------
	bool DocumentImporter::createAndAssignMaterials()
	{
		MaterialCreator materialCreator(this);
		return materialCreator.create();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::assignControllers()
	{
		AnimationAssigner animationAssigner(this);
		return animationAssigner.assign();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::createSceneGraph()
	{
		UniqueIdVisualSceneMap::const_iterator it = mUniqueIdVisualSceneMap.begin();
		if ( it != mUniqueIdVisualSceneMap.end() )
		{
			SceneGraphCreator sceneGraphCreator(this, it->second);
			return sceneGraphCreator.create();
		}
		return true;
	}

	//---------------------------------------------------------------
	void DocumentImporter::addAmbientColor( const COLLADAFW::Color& ambientColor )
	{
		if ( mAmbientColor.isValid())
		{
			mAmbientColor.setRed( (mAmbientColor.getRed() * mNumberOfAmbientColors + ambientColor.getRed())/(mNumberOfAmbientColors+1) );
			mAmbientColor.setGreen( (mAmbientColor.getGreen() * mNumberOfAmbientColors + ambientColor.getGreen())/(mNumberOfAmbientColors+1) );
			mAmbientColor.setBlue( (mAmbientColor.getBlue() * mNumberOfAmbientColors + ambientColor.getBlue())/(mNumberOfAmbientColors+1) );
			mNumberOfAmbientColors++;
		}
		else
		{
			mAmbientColor = ambientColor;
			mNumberOfAmbientColors = 1;
		}

	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeGlobalAsset( const COLLADAFW::FileInfo* asset )
	{
		mFileInfo.absoluteFileUri = asset->getAbsoluteFileUri();

		float systemUnitScale = 1.0f;

		// Retrieve the system unit information
		int systemUnitType = UNITS_CENTIMETERS;
		GetMasterUnitInfo(&systemUnitType, &systemUnitScale);

		switch (systemUnitType)
		{
		case UNITS_INCHES: 
			systemUnitScale *= 0.0254f; 
			break;
		case UNITS_FEET: 
			systemUnitScale *= 0.3048f; 
			break;
		case UNITS_MILES: 
			systemUnitScale *= 1609.344f; 
			break;
		case UNITS_MILLIMETERS: 
			systemUnitScale *= 0.001f; 
			break;
		case UNITS_CENTIMETERS: 
			systemUnitScale *= 0.01f; 
			break;
		case UNITS_METERS: 
			break;
		case UNITS_KILOMETERS: 
			systemUnitScale *= 1000.0f; 
			break;
		default: break;
		}
		mFileInfo.unitScale = (float)asset->getUnit().getLinearUnitMeter() / systemUnitScale;
		return true;
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeVisualScene( const COLLADAFW::VisualScene* visualScene )
	{
		VisualSceneImporter visualSceneImporter(this, visualScene);
		return visualSceneImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes )
	{
		LibraryNodesImporter libraryNodesImporter(this, libraryNodes);
		return libraryNodesImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeGeometry( const COLLADAFW::Geometry* geometry )
	{
		GeometryImporter geometryImporter(this, geometry);
		return geometryImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeMaterial( const COLLADAFW::Material* material )
	{
		MaterialImporter materialImporter(this, material);
		return materialImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeEffect( const COLLADAFW::Effect* effect )
	{
		EffectImporter effectImporter(this, effect);
		return effectImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeCamera( const COLLADAFW::Camera* camera )
	{
		CameraImporter cameraImporter(this, camera);
		return cameraImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeImage( const COLLADAFW::Image* image )
	{
		ImageImporter imageImporter(this, image);
		return imageImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeLight( const COLLADAFW::Light* light )
	{
		LightImporter lightImporter(this, light);
		return lightImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeAnimation( const COLLADAFW::Animation* animation )
	{
		AnimationImporter animationImporter(this, animation);
		return animationImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeAnimationList( const COLLADAFW::AnimationList* animationList )
	{
		AnimationListImporter animationListImporter(this, animationList);
		return animationListImporter.import();
	}

	//---------------------------------------------------------------
	float DocumentImporter::convertSpaceUnit( float originalValue )
	{
		return originalValue * mFileInfo.unitScale;
	}

} // namespace COLLADAMax
