/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_NODE_H__
#define __DAE2MA_NODE_H__

#include "DAE2MAPrerequisites.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWNode.h"

#include "COLLADABUIDList.h"

#include <vector>


namespace DAE2MA
{
    /**
     * This class exist to have the node path for a node.
     */
	class MayaNode 	
    {
	private:
	
        /** The unique id of the object.*/
        COLLADAFW::UniqueId mUniqueId;

        /**
        * The name attribute is the text string name of the node.
        * The name has to be unique in maya.
        */
        String mName;

        /**
         * The parent node.
         */
        MayaNode* mParentNode;

        /**
         * The list of unique ids of all child nodes (every node types) under the current node.
         */
        COLLADABU::IDList mChildNodeIds;

        /** 
        * The type of the <node> element. Valid values are JOINT or NODE. The default is 
        * NODE. Optional. 
        */
        COLLADAFW::Node::NodeType mType;

        /**
         * If the current maya node is a transform node, you can set the transform matrix.
         * Will be used if we import a skin controller element to calculate the transform matrix
         * with the initial transformation and the skin controller's bind shape matrix.
         */
        COLLADABU::Math::Matrix4 mTransformationMatrix;

	public:

        MayaNode ();

        /**
         * Constructor.
         * Copy the uniqueId!
         */
        MayaNode ( 
            const COLLADAFW::UniqueId& uniqueId, 
            const String name, 
            MayaNode* parent = NULL, 
            const COLLADAFW::Node::NodeType nodeType = COLLADAFW::Node::NODE );

        virtual ~MayaNode() {}

        /** 
         * Returns the unique id of the object.
         */
        const COLLADAFW::UniqueId& getUniqueId() const { return mUniqueId; }

        /** 
        * The type of the <node> element. Valid values are JOINT or NODE. The default is NODE. Optional. 
        */
        const COLLADAFW::Node::NodeType getType () const { return mType; }

        /**
        * The parent node.
        */
        MayaNode* getParent () { return mParentNode; }
        const MayaNode* getParent () const { return mParentNode; }
        void setParent ( MayaNode* val );

        /**
        * The list of unique ids of all child nodes (every node types) under the current node.
        */
        String addChildNodeId ( 
            const String& newId, 
            bool returnConverted = true, 
            bool alwaysAddNumberSuffix = false );

        /**
         * Returns true, if the given id is already in the list of child node ids.
         */
        bool containsChildNodeId ( const String& id );

        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        const String getName () const { return mName; }

        /**
         * Get's the node path of the current maya node.
         */
        const String getNodePath ();

        /**
        * If the current maya node is a transform node, you can set the transform matrix.
        * Will be used if we import a skin controller element to calculate the transform matrix
        * with the initial transformation and the skin controller's bind shape matrix.
        */
        const COLLADABU::Math::Matrix4& getTransformationMatrix () const { return mTransformationMatrix; }
        void setTransformationMatrix ( const COLLADABU::Math::Matrix4& val ) { mTransformationMatrix = val; }

	};
} // namespace DAE2MA

#endif // __DAE2MA_NODE_H__
