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

#ifndef __COLLADAMAX_LIBRARYNODESIMPORTER_H__
#define __COLLADAMAX_LIBRARYNODESIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxNodeImporter.h"

namespace COLLADAFW
{
	class LibraryNodes;
}

namespace COLLADAMax
{

	/** Imports a library into the max scene.
	Only nodes that are referenced by already imported nodes, will be added to the max scene.
	All other nodes will be stored and integrated into the max scene by the VisualSceneLoader as soon
	as the nodes get referenced a node.*/
	class LibraryNodesImporter : public NodeImporter 
		{
	private:
		
		/** The LibraryNodes that should be imported.*/
		const COLLADAFW::LibraryNodes* mLibraryNodes;

	public:

        /** Constructor. */
		LibraryNodesImporter(DocumentImporter* documentImporter, const COLLADAFW::LibraryNodes* libraryNodes );

        /** Destructor. */
		virtual ~LibraryNodesImporter();

		/** Performs the import of the geometry.
		@return True on success, false otherwise.*/
		bool import();

	private:

        /** Disable default copy ctor. */
		LibraryNodesImporter( const LibraryNodesImporter& pre );

        /** Disable default assignment operator. */
		const LibraryNodesImporter& operator= ( const LibraryNodesImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_LIBRARYNODESIMPORTER_H__
