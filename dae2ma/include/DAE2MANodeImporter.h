/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_NODEIMPORTER_H__
#define __DAE2MA_NODEIMPORTER_H__

#include "DAE2MAPrerequisites.h"
#include "DAE2MABaseImporter.h"


namespace DAE2MA
{

    /** This class imports a visual scene into the scene graph. */
	class NodeImporter : public BaseImporter
    {
	private:
	
        /** 
        * Maps unique ids of nodes to the frame word node itself. 
        */
        UniqueIdFWNodeMap mUniqueIdFWNodeMap;

	public:

        /** Constructor. */
		NodeImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~NodeImporter();

        /** Maps unique ids of nodes to the frame word node itself. */
        bool importNodes ( const COLLADAFW::NodePointerArray& nodes );

        /** Maps unique ids of nodes to the frame word node itself. */
        bool importNode ( const COLLADAFW::Node* node );

        /** Get the framework node to the current unique node id. */
        const COLLADAFW::Node* findNode ( const COLLADAFW::UniqueId& nodeId ) const;

    private:

        /** Adds UniqueId frame work node pair to the UniqueIdFWNodeMap. */
        void addUniqueIdFWNode ( 
            const COLLADAFW::UniqueId& nodeId, 
            const COLLADAFW::Node* node )
        {
            mUniqueIdFWNodeMap [nodeId] = node;
        }


        /** Disable default copy ctor. */
		NodeImporter( const NodeImporter& pre );

        /** Disable default assignment operator. */
		const NodeImporter& operator= ( const NodeImporter& pre );

	};

} // namespace DAE2MA

#endif // __DAE2MA_NODEIMPORTER_H__
