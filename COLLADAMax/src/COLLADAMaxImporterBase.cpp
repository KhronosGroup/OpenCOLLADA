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

	//------------------------------
	void ImporterBase::addUniqueIdObjectINodePair( const COLLADAFW::UniqueId& uniqueId, INode* node )
	{
		mDocumentImporter->getUniqueIdObjectINodeMap().insert(std::pair<COLLADAFW::UniqueId, INode*>(uniqueId, node) );
	}

	//------------------------------
	void ImporterBase::addUniqueIdReferencingINodePair( const COLLADAFW::UniqueId& uniqueId, INode* node )
	{
		mDocumentImporter->getUniqueIdReferencingINodeMap().insert(std::pair<COLLADAFW::UniqueId, INode*>(uniqueId, node) );
	}

	//------------------------------
	void ImporterBase::getObjectINodesByUniqueId( const COLLADAFW::UniqueId& uniqueId, COLLADAMax::INodeList& nodelist )
	{
		const DocumentImporter::UniqueIdINodeMultiMap& uniqueIdINodeMap = mDocumentImporter->getUniqueIdObjectINodeMap();

		DocumentImporter::UniqueIdINodeMultiMap::const_iterator rangeBegin = uniqueIdINodeMap.lower_bound(uniqueId);
		DocumentImporter::UniqueIdINodeMultiMap::const_iterator rangeEnd = uniqueIdINodeMap.upper_bound(uniqueId);

		for (DocumentImporter::UniqueIdINodeMultiMap::const_iterator it = rangeBegin; it != rangeEnd; ++it)
			nodelist.push_back(it->second);
	}


	//------------------------------
	void ImporterBase::getReferencingINodesByUniqueId( const COLLADAFW::UniqueId& uniqueId, COLLADAMax::INodeList& nodelist )
	{
		const DocumentImporter::UniqueIdINodeMultiMap& uniqueIdINodeMap = mDocumentImporter->getUniqueIdReferencingINodeMap();

		DocumentImporter::UniqueIdINodeMultiMap::const_iterator rangeBegin = uniqueIdINodeMap.lower_bound(uniqueId);
		DocumentImporter::UniqueIdINodeMultiMap::const_iterator rangeEnd = uniqueIdINodeMap.upper_bound(uniqueId);

		for (DocumentImporter::UniqueIdINodeMultiMap::const_iterator it = rangeBegin; it != rangeEnd; ++it)
			nodelist.push_back(it->second);
	}

	//------------------------------
	void ImporterBase::addUniqueIdObjectPair( const COLLADAFW::UniqueId& uniqueId, Object* object )
	{
		mDocumentImporter->getUniqueIdObjectMap()[uniqueId] = object;
	}


	//------------------------------
	void ImporterBase::addUniqueIdINodePair( const COLLADAFW::UniqueId& uniqueId, INode* iNode )
	{
		mDocumentImporter->getUniqueIdINodeMap()[uniqueId] = iNode;
	}

	//------------------------------
	void ImporterBase::addObjectINodeUniqueIdPair( INode* iNode, const COLLADAFW::UniqueId& uniqueId )
	{
		mDocumentImporter->getObjectINodeUniqueIdMap()[iNode] = uniqueId;
	}

	//------------------------------
	Object* ImporterBase::getObjectByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdObjectMap& uniqueIdObjectMap = mDocumentImporter->getUniqueIdObjectMap();
		DocumentImporter::UniqueIdObjectMap::const_iterator it = uniqueIdObjectMap.find(uniqueId);
		if ( it == uniqueIdObjectMap.end() )
			return 0;
		else
			return it->second;
	}

	//------------------------------
	INode* ImporterBase::getINodeByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdINodeMap& uniqueIdINodeMap = mDocumentImporter->getUniqueIdINodeMap();
		DocumentImporter::UniqueIdINodeMap::const_iterator it = uniqueIdINodeMap.find(uniqueId);
		if ( it == uniqueIdINodeMap.end() )
			return 0;
		else
			return it->second;
	}

	//------------------------------
	const COLLADAFW::UniqueId& ImporterBase::getUniqueIdByObjectINode( INode* iNode )
	{
		const DocumentImporter::ObjectINodeUniqueIdMap& objectINodeUniqueIdMap = mDocumentImporter->getObjectINodeUniqueIdMap();
		DocumentImporter::ObjectINodeUniqueIdMap::const_iterator it = objectINodeUniqueIdMap.find(iNode);
		if ( it == objectINodeUniqueIdMap.end() )
			return COLLADAFW::UniqueId::INVALID;
		else
			return it->second;
	}


} // namespace COLLADAMax
