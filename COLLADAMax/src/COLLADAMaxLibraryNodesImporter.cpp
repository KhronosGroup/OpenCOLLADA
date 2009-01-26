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
		for ( size_t i = 0, count = libraryRootNodes.getCount(); i < count; ++i)
		{
			if ( !importLibraryNode( libraryRootNodes[i] ) )
				return false;
		}

		return true;
	}

	//------------------------------
	bool LibraryNodesImporter::importLibraryNode( const COLLADAFW::Node* node )
	{
		const COLLADAFW::UniqueId& nodeUniqueId = node->getUniqueId();
		ImpNode* referencingImpNode = getReferencingImpNodesByUniqueId(nodeUniqueId);
		if ( !referencingImpNode )
		{
			addUniqueIdFWNodePair( nodeUniqueId, node );
			const COLLADAFW::NodePointerArray& childNodes = node->getChildNodes();
			for ( size_t i = 0, count = childNodes.getCount(); i < count; ++i)
				if ( !importLibraryNode( childNodes[i] ) )
					return false;
		}
		else
		{
			while ( referencingImpNode  )
			{
				removeUniqueIdReferencingImpNodePair( nodeUniqueId, referencingImpNode);
				if ( !importNode( node, referencingImpNode ) )
					return false;
				referencingImpNode = getReferencingImpNodesByUniqueId(nodeUniqueId);
			}
		}
		
		return true;
	}

} // namespace COLLADAMax
