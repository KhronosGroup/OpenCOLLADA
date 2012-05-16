/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_LIBRARYNODES_H__
#define __COLLADAFW_LIBRARYNODES_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWNode.h"


namespace COLLADAFW
{

    /** Provides a library in which to place \<node\> elements. */
    class LibraryNodes
	{
	private:
		/** The nodes contained in the library.*/
		NodePointerArray mNodes;
	
	public:

        /** Constructor. */
		LibraryNodes(){}

        /** Destructor. */
		virtual ~LibraryNodes(){}

		/** Returns the array containing all nodes of the library nodes.*/
		const NodePointerArray& getNodes() const { return mNodes; }

		/** Returns the array containing all nodes of the library nodes.*/
		NodePointerArray& getNodes() { return mNodes; }

	private:

        /** Disable default copy ctor. */
//		LibraryNodes( const LibraryNodes& pre );

        /** Disable default assignment operator. */
//		const LibraryNodes& operator= ( const LibraryNodes& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_LIBRARYNODES_H__
