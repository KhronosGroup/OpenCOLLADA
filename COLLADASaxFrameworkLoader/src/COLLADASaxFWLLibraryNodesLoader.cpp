/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryNodesLoader.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWLibraryNodes.h"


namespace COLLADASaxFWL
{

    //------------------------------
	LibraryNodesLoader::LibraryNodesLoader(IFilePartLoader* callingFilePartLoader)
		: FilePartLoader(callingFilePartLoader),
		mLibraryNodes(new COLLADAFW::LibraryNodes())
	{
		NodeLoader::setHandlingFilePartLoader(this);
	}
	
    //------------------------------
	LibraryNodesLoader::~LibraryNodesLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& LibraryNodesLoader::getUniqueId ()
    {
        if ( !mNodeStack.empty() )
            return mNodeStack.top()->getUniqueId();
        return COLLADAFW::UniqueId::INVALID;
    }

    //------------------------------
	void LibraryNodesLoader::handleRootNode( COLLADAFW::Node* rootNode )
	{
		mLibraryNodes->getNodes().append(rootNode);
	}

	//------------------------------
	bool LibraryNodesLoader::begin__node( const node__AttributeData& attributeData )
	{
		return beginNode(attributeData);
	}

	//------------------------------
	bool LibraryNodesLoader::end__node()
	{
		return endNode();
	}

	//------------------------------
	bool LibraryNodesLoader::end__library_nodes()
	{
		moveUpInSidTree();
		getFileLoader()->addLibraryNodes(mLibraryNodes);
		finish();
		return true;
	}

} // namespace COLLADASaxFWL
