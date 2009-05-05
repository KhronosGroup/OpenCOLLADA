/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADAFWInstanceCamera.h"
#include "COLLADAFWInstanceLight.h"
#include "COLLADAFWInstanceController.h"
#include "COLLADAFWArrayPrimitiveType.h"
#include "COLLADAFWPointerArray.h"

#include "Math/COLLADABUMathVector3.h"


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
	typedef PointerArray<Node> NodePointerArray;

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
         * The parent node.
         */
		Node* mParentNode;

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

		/**
		* The name attribute is the text string name of this element. 
		* Optional attribute.
		*/
		String mName;

        /** 
         * The type of the <node> element. Valid values are JOINT or NODE. The default is 
         * NODE. Optional. 
         */
        NodeType mType;

		/** List of all transformations of the node. Array and contents will be delete in destructor.*/
		TransformationPointerArray mTransformations;

		/** List of all instance geometries of this node. Array and contents will be delete in destructor.*/
		InstanceGeometryPointerArray mInstanceGeometries;

		/** List of all instance nodes of this node. Array and contents will be delete in destructor.*/
		InstanceNodePointerArray mInstanceNodes;

		/** List of all instance cameras of this node. Array and contents will be delete in destructor.*/
		InstanceCameraPointerArray mInstanceCameras;

		/** List of all instance lights of this node. Array and contents will be delete in destructor.*/
		InstanceLightPointerArray mInstanceLights;

        /** List of all instance controller of this node. Array and contents will be delete in destructor.*/
        InstanceControllerPointerArray mInstanceControllers;

        /** List of all child nodes. Array and contents will be delete in destructor.*/
		NodePointerArray mChildNodes;

	public:

		/** Creates a node with object id @a objectId.*/
		Node(ObjectId objectId);

		virtual ~Node();

        /**
        * The original object id, if it in the original file format exist. 
        */
        const COLLADAFW::String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const COLLADAFW::String& val ) { mOriginalId = val; }

		/** Returns the name of the node*/
		const String& getName() const { return mName; }

		/** Sets the name of the node*/
		void setName(const String& name) { mName = name; }

        /** The type of the <node> element. Valid values are JOINT or NODE. The default is
        NODE. Optional. */
        const COLLADAFW::Node::NodeType getType () const { return mType; }

        /** The type of the <node> element. Valid values are JOINT or NODE. The default is
        NODE. Optional. */
        void setType ( const COLLADAFW::Node::NodeType Type ) { mType = Type; }

		/** Get list of all transformations of the node.*/
		TransformationPointerArray& getTransformations() { return mTransformations; }

		/** Get list of all transformations of the node.*/
		const TransformationPointerArray& getTransformations() const { return mTransformations; }

		/** List of all instance geometries of this node.*/
		InstanceGeometryPointerArray& getInstanceGeometries() { return mInstanceGeometries; }

		/** List of all instance geometries of this node.*/
		const InstanceGeometryPointerArray& getInstanceGeometries() const { return mInstanceGeometries; }

		/** List of all instance nodes of this node.*/
		InstanceNodePointerArray& getInstanceNodes() { return mInstanceNodes; }

		/** List of all instance nodes of this node.*/
		const InstanceNodePointerArray& getInstanceNodes() const { return mInstanceNodes; }

		/** List of all instance cameras of this camera.*/
		InstanceCameraPointerArray& getInstanceCameras() { return mInstanceCameras; }

		/** List of all instance cameras of this camera.*/
		const InstanceCameraPointerArray& getInstanceCameras() const { return mInstanceCameras; }

		/** List of all instance cameras of this camera.*/
		InstanceLightPointerArray& getInstanceLights() { return mInstanceLights; }

		/** List of all instance cameras of this camera.*/
		const InstanceLightPointerArray& getInstanceLights() const { return mInstanceLights; }

        /** List of all instance controller of this node. Array and contents will be delete in destructor.*/
        InstanceControllerPointerArray& getInstanceControllers () { return mInstanceControllers; }

        /** List of all instance controller of this node. Array and contents will be delete in destructor.*/
        const InstanceControllerPointerArray& getInstanceControllers () const { return mInstanceControllers; }

        /** 
        * The parent node.
        */
        const Node* getParentNode () const { return mParentNode; }

        /** 
        * The parent node.
        */
        void setParentNode ( Node* val ) { mParentNode = val; }

		/** Get list of all child nodes.*/
		NodePointerArray& getChildNodes() { return mChildNodes; }

		/** Get list of all child nodes.*/
		const NodePointerArray& getChildNodes() const { return mChildNodes; }

        /** 
        * Calculates a baked matrix, representing all the transformations of the joint.
        * matrix = [SP-1 * S * SH * SP * ST] * [RP-1 * RA * R * JO * RP * RT] * T
        *          [        scale          ] * [          rotation          ] * translation
        * (where '*' denotes matrix multiplication and '-1' denotes matrix inversion')
        * [SP] scale pivot translate (inverse)
        * [S]  scale
        * [SH] shear
        * [ST] scale pivot translate
        * [RP] rotate pivot (inverse)
        * [RA] rotation axis
        * [R]  rotation
        * [RP] rotate pivot
        * [RT] rotate pivot translate
        * [T]  translate
        * [JO] joint orientation
        * @param transformationMatrix Will be set to the calculated node transformation matrix.
        */
        void getNodeTransformationMatrix(COLLADABU::Math::Matrix4& transformationMatrix) const;

        /** 
        * Calculates a baked matrix, representing all the transformations of the joint.
        * matrix = [SP-1 * S * SH * SP * ST] * [RP-1 * RA * R * JO * RP * RT] * T
        *          [        scale          ] * [          rotation          ] * translation
        * (where '*' denotes matrix multiplication and '-1' denotes matrix inversion')
        * [SP] scale pivot translate (inverse)
        * [S]  scale
        * [SH] shear
        * [ST] scale pivot translate
        * [RP] rotate pivot (inverse)
        * [RA] rotation axis
        * [R]  rotation
        * [RP] rotate pivot
        * [RT] rotate pivot translate
        * [T]  translate
        * [JO] joint orientation
        * @return The calculated node transformation matrix.
        */
        COLLADABU::Math::Matrix4 getNodeTransformationMatrix() const;

        /** 
         * Returns a baked matrix, representing all the transformations of the node.
         * The transformation matrix for a joint node:
         * matrix = S * RO * R * JO * S-1 * T
         * (where '*' denotes matrix multiplication and '-1' denotes matrix inversion')
         * [S]:  scale
         * [RO]: rotate orient (attribute name is rotateAxis)
         * [R]:  rotation
         * [JO]: joint orient
         * [S]:  parent scale (inverse)
         * [T]:  translate
         * @param parentScale 
         * @return The calculated joint transformation matrix.
         */
        COLLADABU::Math::Matrix4 getJointTransformationMatrix() const;

		/** Creates a clone of the node and returns a pointer to it.*/
		Node* clone() const { return FW_NEW Node(*this); }
	};


} // namespace COLLADAFW

#endif // __COLLADAFW_NODE_H__
