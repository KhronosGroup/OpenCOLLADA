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
#include "COLLADAMaxFWLErrorHandler.h"

#include "COLLADAFWFileInfo.h"

#include "COLLADAFWLibraryNodes.h"


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

		return createAndAssignMaterials();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::createAndAssignMaterials()
	{
		MaterialCreator materialCreator(this);
		return materialCreator.create();
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

} // namespace COLLADAMax
