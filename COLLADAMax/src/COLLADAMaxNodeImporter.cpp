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
#include "COLLADAMaxNodeImporter.h"


namespace COLLADAMax
{

	NodeImporter::NodeImporter( DocumentImporter* documentImporter )
		:	ImporterBase(documentImporter)
	{}

	//------------------------------
	NodeImporter::~NodeImporter()
	{
	}


	//------------------------------
	bool NodeImporter::importNodes( const COLLADAFW::NodePointerArray& nodes )
	{
		for ( size_t i = 0, count = nodes.getCount(); i < count; ++i)
		{
			if ( !importNode( nodes[i] ) )
				return false;
		}
		return true;
	}

	//------------------------------
	bool NodeImporter::importNode( const COLLADAFW::Node* node )
	{
		const COLLADAFW::UniqueId& nodeUniqueId = node->getUniqueId();
		addUniqueIdFWNodePair( nodeUniqueId, node );
		const COLLADAFW::NodePointerArray& childNodes = node->getChildNodes();
		for ( size_t i = 0, count = childNodes.getCount(); i < count; ++i)
		{
			if ( !importNode( childNodes[i] ) )
			{
				return false;
			}
		}
		return true;
	}

} // namespace COLLADAMax
