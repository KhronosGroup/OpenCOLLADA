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

#ifndef __COLLADAMAX_VISUALSCENEIMPORTER_H__
#define __COLLADAMAX_VISUALSCENEIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"
#include "COLLADAFWNode.h"

#include "dummy.h"

namespace COLLADAFW
{
	class VisualScene;
};

class Object;

namespace COLLADAMax
{

    /** this class imports a visual scene into the max scene graph. */
	class VisualSceneImporter : public ImporterBase
	{
	private:
		/** The visual scene that should be imported.*/
		const COLLADAFW::VisualScene* mVisualScene;
	
		Object* mDummyGeoObject;

		DummyObject* mDummyObject;

	public:

        /** Constructor. */
		VisualSceneImporter(DocumentImporter* documentImporter, const COLLADAFW::VisualScene* visualScene);

		/** Performs the import of the scene graph.
		@return True on success, false otherwise.*/
		bool import();

        /** Destructor. */
		virtual ~VisualSceneImporter();

	public:
		/** Converts a COLLADAFW Matrix4 into a max Matrix3.*/
		static void Matrix4ToMaxMatrix3 ( Matrix3 & copy,  const COLLADABU::Math::Matrix4& original  );

	private:

        /** Disable default copy ctor. */
		VisualSceneImporter( const VisualSceneImporter& pre );

        /** Disable default assignment operator. */
		const VisualSceneImporter& operator= ( const VisualSceneImporter& pre );

		/** Recursively imports @a node.*/
		ImpNode* importNode(COLLADAFW::Node* node);

		/** Imports all nodes in  @a nodeArray and attaches them to @a parentImportNode.*/
		bool importNodes(const COLLADAFW::NodeArray& nodeArray, ImpNode* parentImportNode);

		/** Imports all the instance geometries in  @a instanceGeometryArray and attaches them to @a parentImportNode.*/
		bool importInstanceGeometries( const COLLADAFW::InstanceGeometryArray& instanceGeometryArray, ImpNode* parentImportNode );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_VISUALSCENEIMPORTER_H__
