/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYNODESLOADER_H__
#define __COLLADASAXFWL_LIBRARYNODESLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLNodeLoader.h"
#include "COLLADASaxFWLFilePartLoader.h"

namespace COLLADAFW
{
	class LibraryNodes;
}

namespace COLLADASaxFWL
{

	/** Imports the entire library nodes and sends it to the writer. */
	class LibraryNodesLoader : public FilePartLoader, public NodeLoader 
	{
	private:
		/** Pointer to the visual scene this loader creates.*/
		COLLADAFW::LibraryNodes* mLibraryNodes;

	public:

		/** Constructor. */
		LibraryNodesLoader(IFilePartLoader* callingFilePartLoader);

		/** Destructor. */
		virtual ~LibraryNodesLoader();

	private:

		/** Disable default copy ctor. */
		LibraryNodesLoader( const LibraryNodesLoader& pre );

		/** Disable default assignment operator. */
		const LibraryNodesLoader& operator= ( const LibraryNodesLoader& pre );

		/** Appends the root node to the array of root nodes of the visual scene,*/
		void handleRootNode( COLLADAFW::Node* rootNode );

    public:

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();


		/** Sax callback function for the beginning of nodes, as child of a library nodes.*/
		virtual bool begin__node( const node__AttributeData& attributeData );

		/** Sax callback function for the ending of nodes, as child of a library nodes.*/
		virtual bool end__node();

		/** Sax callback function for the ending of a library nodes.*/
		virtual bool end__library_nodes();

	};


} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYNODESLOADER_H__
