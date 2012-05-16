/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MANodeImporter.h"


namespace DAE2MA
{

    //------------------------------
    NodeImporter::NodeImporter ( DocumentImporter* documentImporter ) 
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	NodeImporter::~NodeImporter()
	{
	}

    //------------------------------
    bool NodeImporter::importNodes ( const COLLADAFW::NodePointerArray& nodes )
    {
        for ( size_t i = 0, count = nodes.getCount(); i < count; ++i)
        {
            if ( !importNode( nodes[i] ) )
                return false;
        }
        return true;
    }

    //------------------------------
    bool NodeImporter::importNode ( const COLLADAFW::Node* node )
    {
        const COLLADAFW::UniqueId& nodeId = node->getUniqueId();
        addUniqueIdFWNode ( nodeId, node );

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

    //------------------------------
    const COLLADAFW::Node* NodeImporter::findNode ( const COLLADAFW::UniqueId& nodeId ) const
    {
        UniqueIdFWNodeMap::const_iterator it = mUniqueIdFWNodeMap.find ( nodeId );
        if ( it != mUniqueIdFWNodeMap.end () )
            return it->second;

        return 0;
    }

} // namespace DAE2MA
