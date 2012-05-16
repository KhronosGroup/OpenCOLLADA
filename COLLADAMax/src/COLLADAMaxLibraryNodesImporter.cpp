/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADAMaxLibraryNodesImporter.h"

#include "COLLADAFWNode.h"
#include "COLLADAFWLibraryNodes.h"


namespace COLLADAMax
{


	//------------------------------
	LibraryNodesImporter::LibraryNodesImporter( DocumentImporter* documentImporter, const COLLADAFW::LibraryNodes* libraryNodes )
		:	NodeImporter(documentImporter)
		, mLibraryNodes( new COLLADAFW::LibraryNodes( *libraryNodes) )
	{
		addLibraryNodes( mLibraryNodes );
	}

	//------------------------------
	LibraryNodesImporter::~LibraryNodesImporter()
	{
	}

	//------------------------------
	bool LibraryNodesImporter::import()
	{
		const COLLADAFW::NodePointerArray& libraryRootNodes = mLibraryNodes->getNodes();
		return importNodes( libraryRootNodes );
	}

} // namespace COLLADAMax
