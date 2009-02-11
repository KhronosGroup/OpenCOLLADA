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
#include "COLLADAMaxFWLErrorHandler.h"

#include "COLLADAFWLibraryNodes.h"

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

		return createAndAssignMaterials();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::createAndAssignMaterials()
	{
		MaterialCreator materialCreator(this);
		return materialCreator.create();
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
		return true;
	}

} // namespace COLLADAMax
