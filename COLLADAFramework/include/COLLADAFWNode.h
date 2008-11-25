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
#include "COLLADAFWTransformation.h"
#include "COLLADAFWInstanceGeometry.h"

namespace COLLADAFW
{

	class Node;

	typedef Array<Node*> NodeArray;

	class Node 	
	{
	private:
	
		/**
		* The name attribute is the text string name of this element. 
		* Optional attribute.
		*/
		String mName;

		/** A text string containing the unique identifier of the element. This value must be
		unique within the instance document. Optional.
		*/
		String mId;

		/** A text string containing the unique identifier of the element. This value must be
		unique within the instance document. Optional.
		*/
		String mSid;

		/** List of all transformations of the node.*/
		TransformationArray mTransformations;

		/** List of all instance geometries of this node.*/
		InstanceGeometryArray mInstanceGeometries;

		/** List of all child nodes.*/
		NodeArray mChildNodes;

	public:
		Node();
		virtual ~Node();

		/** Returns the name of the node*/
		const String& getName() const { return mName; }

		/** Sets the name of the node*/
		void getName(const String& name) { mName = name; }

		/** Returns the id of the node*/
		const String& getId() const { return mId; }

		/** Sets the id of the node*/
		void getId(const String& id) { mId = id; }

		/** Returns the sid of the node*/
		const String& getSid() const { return mSid; }

		/** Sets the id of the node*/
		void getSid(const String& sid) { mSid = sid; }

		/** Get list of all transformations of the node.*/
		TransformationArray& getTransformations() { return mTransformations; }

		/** Get list of all transformations of the node.*/
		const TransformationArray& getTransformations() const { return mTransformations; }

		/** List of all instance geometries of this node.*/
		InstanceGeometryArray& getInstanceGeometries() { return mInstanceGeometries; }

		/** List of all instance geometries of this node.*/
		const InstanceGeometryArray& getInstanceGeometries() const { return mInstanceGeometries; }

		/** Get list of all child nodes.*/
		NodeArray& getChildNodes() { return mChildNodes; }

		/** Get list of all child nodes.*/
		const NodeArray& getChildNodes() const { return mChildNodes; }

	private:
        /** Disable default copy ctor. */
		Node( const Node& pre );
        /** Disable default assignment operator. */
		const Node& operator= ( const Node& pre );

	};


} // namespace COLLADAFW

#endif // __COLLADAFW_NODE_H__
