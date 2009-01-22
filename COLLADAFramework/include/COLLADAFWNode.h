/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_NODE_H__
#define __COLLADAFW_NODE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWTransformation.h"
#include "COLLADAFWInstanceGeometry.h"
#include "COLLADAFWInstanceNode.h"
#include "COLLADAFWArrayPrimitiveType.h"


namespace COLLADABU
{
    namespace Math
    {
        class Matrix4;
    }
}


namespace COLLADAFW
{

	class Node;

	typedef ArrayPrimitiveType<Node*> NodeArray;

	class Node : public ObjectTemplate<COLLADA_TYPE::NODE>
	{
    public:
        
        enum NodeType
        {
            NODE,
            JOINT
        };

	private:
	
		/**
		* The name attribute is the text string name of this element. 
		* Optional attribute.
		*/
		String mName;

		/** A text string containing the unique identifier of the element. This value must be
		unique within the instance document. Optional.
		*/
		String mSid;

        /** The type of the <node> element. Valid values are JOINT or NODE. The default is
        NODE. Optional. */
        NodeType mType;

		/** List of all transformations of the node. Array and contents will be delete in destructor.*/
		TransformationArray mTransformations;

		/** List of all instance geometries of this node. Array and contents will be delete in destructor.*/
		InstanceGeometryArray mInstanceGeometries;

		/** List of all instance nodes of this node. Array and contents will be delete in destructor.*/
		InstanceNodeArray mInstanceNodes;

		/** List of all child nodes. Array and contents will be delete in destructor.*/
		NodeArray mChildNodes;

	public:
		/** Creates a node with object id @a objectId.*/
		Node(ObjectId objectId);

		virtual ~Node();

		/** Returns the name of the node*/
		const String& getName() const { return mName; }

		/** Sets the name of the node*/
		void setName(const String& name) { mName = name; }

		/** Returns the sid of the node*/
		const String& getSid() const { return mSid; }

		/** Sets the id of the node*/
		void setSid(const String& sid) { mSid = sid; }

        /** The type of the <node> element. Valid values are JOINT or NODE. The default is
        NODE. Optional. */
        const COLLADAFW::Node::NodeType getType () const { return mType; }

        /** The type of the <node> element. Valid values are JOINT or NODE. The default is
        NODE. Optional. */
        void setType ( const COLLADAFW::Node::NodeType Type ) { mType = Type; }

		/** Get list of all transformations of the node.*/
		TransformationArray& getTransformations() { return mTransformations; }

		/** Get list of all transformations of the node.*/
		const TransformationArray& getTransformations() const { return mTransformations; }

		/** List of all instance geometries of this node.*/
		InstanceGeometryArray& getInstanceGeometries() { return mInstanceGeometries; }

		/** List of all instance geometries of this node.*/
		const InstanceGeometryArray& getInstanceGeometries() const { return mInstanceGeometries; }

		/** List of all instance nodes of this node.*/
		InstanceNodeArray& getInstanceNodes() { return mInstanceNodes; }

		/** List of all instance nodes of this node.*/
		const InstanceNodeArray& getInstanceNodes() const { return mInstanceNodes; }

		/** Get list of all child nodes.*/
		NodeArray& getChildNodes() { return mChildNodes; }

		/** Get list of all child nodes.*/
		const NodeArray& getChildNodes() const { return mChildNodes; }

		/** Calculates a baked matrix, representing all the transformations of the node.
		@param transformationMatrix Will be set to the calculated transformation matrix.*/
		void getTransformationMatrix(COLLADABU::Math::Matrix4& transformationMatrix) const;

		/** Returns a baked matrix, representing all the transformations of the node.
		@return The transformation matrix*/
		COLLADABU::Math::Matrix4 getTransformationMatrix() const;

	private:
        /** Disable default copy ctor. */
		Node( const Node& pre );
        /** Disable default assignment operator. */
		const Node& operator= ( const Node& pre );


	};


} // namespace COLLADAFW

#endif // __COLLADAFW_NODE_H__
