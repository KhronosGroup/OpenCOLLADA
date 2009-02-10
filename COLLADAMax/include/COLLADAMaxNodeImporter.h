/*
Copyright (c) 2008 NetAllied Systems GmbH

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

#ifndef __COLLADAMAX_NODEIMPORTER_H__
#define __COLLADAMAX_NODEIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"

#include "COLLADAFWNode.h"
#include "Math/COLLADABUMathMatrix4.h"

namespace COLLADAFW
{
};

namespace COLLADAMax
{

	/** this class imports a visual scene into the max scene graph. */
	class NodeImporter : public ImporterBase
	{
	public:

		/** Constructor. */
		NodeImporter(DocumentImporter* documentImporter);

		/** Destructor. */
		virtual ~NodeImporter();

	public:
		/** Converts a COLLADAFW Matrix4 into a max Matrix3.*/
		static void Matrix4ToMaxMatrix3 ( Matrix3 & copy,  const COLLADABU::Math::Matrix4& original  );

	protected:
		void setNodeProperties( const COLLADAFW::Node* node, ImpNode* importNode);


		/** Recursively imports @a node.*/
		ImpNode* importNode( const COLLADAFW::Node* node, ImpNode* parentImportNode );

		/** Imports all nodes in  @a nodeArray and attaches them to @a parentImportNode.*/
		bool importNodes(const COLLADAFW::NodePointerArray& nodeArray, ImpNode* parentImportNode);

		/** Imports all the instance geometries in  @a instanceGeometryArray and attaches them to @a parentImportNode.*/
		bool importInstanceGeometries( const COLLADAFW::InstanceGeometryPointerArray& instanceGeometryArray, ImpNode* parentImportNode );

		/** Imports the first instance geometry in @a node. It is assumed that @a node has at least one
		instance geometry. A new INode is created, that references the instantiated geometry and has the
		properties of @a node (name, transformation). The new INode is attached to @a parentImportNode. 
		Use this member, if a node has exactly one instance geometry.*/
		ImpNode* importInstanceGeometrie( const COLLADAFW::Node* node, ImpNode* parentImportNode );

		/** Imports all the instance nodes in  @a instanceNodeArray and attaches them to @a parentImportNode.*/
		bool importInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodeArray, ImpNode* parentImportNode );

		/** Recursively clones @a nodeToClone and attaches the cloned graph to @a parentImportNode. The cloned
		nodes with reference the same object and transformation controller.*/
		bool recursivelyCloneINode( ImpNode* parentImportNode, INode* nodeToClone );

		/** Store the information about material bindings of @a instanceGeometry attached to max node @a node*/
		void storeMaterialBindings( INode* node, COLLADAFW::InstanceGeometry* instanceGeometry);

	private:

		/** Disable default copy ctor. */
		NodeImporter( const NodeImporter& pre );

		/** Disable default assignment operator. */
		const NodeImporter& operator= ( const NodeImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_NODEIMPORTER_H__
