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
	DummyObject* ImporterBase::getDummyObject()
	{
		return mDocumentImporter->getDummyObject();
	}

	//------------------------------
	void ImporterBase::addUniqueIdObjectINodePair( const COLLADAFW::UniqueId& uniqueId, INode* node )
	{
		mDocumentImporter->getUniqueIdObjectINodeMap().insert(std::pair<COLLADAFW::UniqueId, INode*>(uniqueId, node) );
	}

	//------------------------------
	void ImporterBase::addUniqueIdReferencingImpNodePair( const COLLADAFW::UniqueId& uniqueId, ImpNode* node )
	{
		mDocumentImporter->getUniqueIdReferencingImpNodeMap().insert(std::pair<COLLADAFW::UniqueId, ImpNode*>(uniqueId, node) );
	}

	//------------------------------
	void ImporterBase::removeUniqueIdReferencingImpNodePair( const COLLADAFW::UniqueId& uniqueId, ImpNode* node )
	{
		DocumentImporter::UniqueIdImpNodeMultiMap& uniqueIdReferencingImpNodeMap = mDocumentImporter->getUniqueIdReferencingImpNodeMap();

		DocumentImporter::UniqueIdImpNodeMultiMap::iterator rangeBegin = uniqueIdReferencingImpNodeMap.lower_bound(uniqueId);
		DocumentImporter::UniqueIdImpNodeMultiMap::iterator rangeEnd = uniqueIdReferencingImpNodeMap.upper_bound(uniqueId);

		for (DocumentImporter::UniqueIdImpNodeMultiMap::iterator it = rangeBegin; it != rangeEnd; ++it)
		{
			if ( it->second == node )
			{
				uniqueIdReferencingImpNodeMap.erase(it);
				break;
			}
		}
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
	ImpNode* ImporterBase::getReferencingImpNodesByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdImpNodeMultiMap& uniqueIdReferencingImpNodeMap = mDocumentImporter->getUniqueIdReferencingImpNodeMap();

		DocumentImporter::UniqueIdImpNodeMultiMap::const_iterator it = uniqueIdReferencingImpNodeMap.find(uniqueId);
		if ( it == uniqueIdReferencingImpNodeMap.end() )
			return 0;
		else
			return it->second;
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
	void ImporterBase::addUniqueIdFWNodePair( const COLLADAFW::UniqueId& uniqueId, const COLLADAFW::Node* node )
	{
		mDocumentImporter->getUniqueIdFWNodeMap()[uniqueId] = node;
	}

	//------------------------------
	void ImporterBase::addLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes )
	{
		mDocumentImporter->getLibraryNodesList().push_back(libraryNodes);
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


	//------------------------------
	const COLLADAFW::Node* ImporterBase::getFWNodeByUniqueId( const COLLADAFW::UniqueId& uniqueId )
	{
		const DocumentImporter::UniqueIdFWNodeMap& uniqueIdFWNodeMap = mDocumentImporter->getUniqueIdFWNodeMap();
		DocumentImporter::UniqueIdFWNodeMap::const_iterator it = uniqueIdFWNodeMap.find(uniqueId);
		if ( it == uniqueIdFWNodeMap.end() )
			return 0;
		else
			return it->second;
	}


} // namespace COLLADAMax
