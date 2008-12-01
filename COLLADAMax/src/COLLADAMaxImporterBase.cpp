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
#include "COLLADAMaxImporterBase.h"
#include "COLLADAMaxDocumentImporter.h"

#include "COLLADAFWUniqueId.h"


namespace COLLADAMax
{

	ImporterBase::ImporterBase( DocumentImporter* documentImporter)
		:	mDocumentImporter(documentImporter)
	{
	}

    //------------------------------
	ImporterBase::~ImporterBase()
	{
	}

	//------------------------------
	Interface* ImporterBase::getMaxInterface()
	{
		return mDocumentImporter->getMaxInterface();
	}

	//------------------------------
	ImpInterface* ImporterBase::getMaxImportInterface()
	{
		return mDocumentImporter->getMaxImportInterface();
	}

	void ImporterBase::addUniqueIdINodePair( const COLLADAFW::UniqueId& uniqueId, INode* node )
	{
		mDocumentImporter->getUniqueIdINodeMap().insert(std::pair<COLLADAFW::UniqueId, INode*>(uniqueId, node) );
	}

} // namespace COLLADAMax
