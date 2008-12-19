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
#include "COLLADAMaxGeometryImporter.h"

#include "COLLADASaxFWLLoader.h"
#include "COLLADAFWRoot.h"

namespace COLLADAMax
{
	//--------------------------------------------------------------------
	DocumentImporter::DocumentImporter(Interface * maxInterface, ImpInterface* maxImportInterface, const NativeString &filepath)
		: mMaxInterface(maxInterface),
		mMaxImportInterface(maxImportInterface),
		mImportFilePath(filepath)
	{
	}
	
	//--------------------------------------------------------------------
	DocumentImporter::~DocumentImporter()
	{
	}


	//---------------------------------------------------------------
	bool DocumentImporter::import()
	{
		COLLADASaxFWL::Loader loader;
		COLLADAFW::Root root(&loader, this);

		return root.loadDocument(mImportFilePath);
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeVisualScene( const COLLADAFW::VisualScene* visualScene )
	{
		VisualSceneImporter visualSceneImporter(this, visualScene);
		return visualSceneImporter.import();
	}

	//---------------------------------------------------------------
	bool DocumentImporter::writeGeometry( const COLLADAFW::Geometry* geometry )
	{
		GeometryImporter geometryImporter(this, geometry);
		return geometryImporter.importMesh();
		return true;
	}

} // namespace COLLADAMax
