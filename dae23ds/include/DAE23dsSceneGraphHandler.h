/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_SCENEGRAPHHANDLER_H__
#define __DAE23DS_SCENEGRAPHHANDLER_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsSceneGraphBase.h"


namespace DAE23ds
{

	class SceneGraphHandler : public SceneGraphBase 
	{
	private:
		struct NodeInfo
		{
			NodeInfo( COLLADABU::Math::Matrix4 _worldTransformation)
				: worldTransformation(_worldTransformation){}
			COLLADABU::Math::Matrix4 worldTransformation;
		};

		typedef std::stack<NodeInfo> NodeInfoStack;

	private:
		NodeInfoStack mNodeInfoStack;
		Writer::UniqueIdNodeMap& mUniqueIdNodeMap;

		ChunkLength mSceneGraphLength;

	public:

		SceneGraphHandler( Writer* writer3ds, const COLLADAFW::VisualScene* visualScene, const Writer::LibraryNodesList& libraryNodesList );

		virtual ~SceneGraphHandler();

		bool handle();

		ChunkLength getScenegraphLength() const { return mSceneGraphLength; }


	private:

		/** Disable default copy ctor. */
		SceneGraphHandler( const SceneGraphHandler& pre );

		/** Disable default assignment operator. */
		const SceneGraphHandler& operator= ( const SceneGraphHandler& pre );

		bool handleNodes(  const COLLADAFW::NodePointerArray& nodesToWriter);

		bool handleNode(  const COLLADAFW::Node* nodeToWriter);

		void handleInstanceGeometries( const COLLADAFW::Node* node, const COLLADABU::Math::Matrix4& matrix );

		void handleInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodes);

		void addNodeLength( ChunkLength objectRefLength, ChunkLength factor , const COLLADABU::Math::Matrix4& matrix);
	};

} // namespace DAE23DS

#endif // __DAE23DS_SCENEGRAPHHANDLER_H__
