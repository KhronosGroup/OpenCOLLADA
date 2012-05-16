/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_SCENEGRAPHWRITER_H__
#define __DAE23DS_SCENEGRAPHWRITER_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsSceneGraphBase.h"

namespace DAE23ds
{

	class SceneGraphWriter : public SceneGraphBase 
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
		Common::Buffer& mBuffer;

		NodeInfoStack mNodeInfoStack;
		Writer::UniqueIdNodeMap& mUniqueIdNodeMap;

		/** The 3ds node id that will be used by the next frame work node.*/
		short mNext3dsNodeId;

	public:

		SceneGraphWriter( Writer* writer3ds, const COLLADAFW::VisualScene* visualScene, const Writer::LibraryNodesList& libraryNodesList );

		virtual ~SceneGraphWriter();

		bool write( ChunkLength scenegraphLength );


	private:

		/** Disable default copy ctor. */
		SceneGraphWriter( const SceneGraphWriter& pre );

		/** Disable default assignment operator. */
		const SceneGraphWriter& operator= ( const SceneGraphWriter& pre );

		bool writeNodes(  const COLLADAFW::NodePointerArray& nodesToWriter, short parent3dsNodeId);

		bool writeNode(const char* objectRefName, ChunkLength objectRefLength, short nodeId, short parent3dsNodeId, const COLLADABU::Math::Matrix4& matrix );

		bool writeNode(  const COLLADAFW::Node* nodeToWriter, short parent3dsNodeId);

		void writeInstanceGeometries( const COLLADAFW::InstanceGeometryPointerArray& instanceGeometries, short parent3dsNodeId );

		void writeInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodes, short parent3dsNodeIde);

	};

} // namespace DAE23ds

#endif // __DAE23DS_SCENEGRAPHWRITER_H__
