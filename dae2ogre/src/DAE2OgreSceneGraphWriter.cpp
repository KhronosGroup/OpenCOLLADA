/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2OgreStableHeaders.h"
#include "DAE2OgreSceneGraphWriter.h"


namespace DAE2Ogre
{

    //------------------------------
	SceneGraphWriter::SceneGraphWriter( OgreWriter* ogreWriter, const COLLADAFW::VisualScene& visualScene, const OgreWriter::LibraryNodesList& libraryNodesList )
		: BaseWriter( ogreWriter )
	    , mVisualScene(visualScene)
		, mLibraryNodesList(libraryNodesList)
	{
	}

    //------------------------------
	SceneGraphWriter::~SceneGraphWriter()
	{
	}

	//------------------------------
	bool SceneGraphWriter::write(  )
	{
		createUniqueIdNodeMap();

		NodeInfo nodeInfo( COLLADABU::Math::Matrix4::IDENTITY );
		mNodeInfoStack.push( nodeInfo );

		writeNodes( mVisualScene.getRootNodes());
		return true;
	}

	//------------------------------
	bool SceneGraphWriter::writeNodes( const COLLADAFW::NodePointerArray& nodesToWriter )
	{
		for ( size_t i = 0, count = nodesToWriter.getCount(); i < count; ++i)
		{
			writeNode(nodesToWriter[i]);
		}
		return true;
	}

	//------------------------------
	bool SceneGraphWriter::writeNode(const COLLADAFW::Node* nodeToWriter )
	{
		
		const NodeInfo& parentNodeInfo = mNodeInfoStack.top();
		const COLLADABU::Math::Matrix4& parentWorldMatrix = parentNodeInfo.worldTransformation;
		COLLADABU::Math::Matrix4 worldMatrix = parentWorldMatrix * nodeToWriter->getTransformationMatrix();
		NodeInfo nodeInfo( worldMatrix );
		mNodeInfoStack.push(nodeInfo);

		writeNodes(nodeToWriter->getChildNodes());

		storeInstanceGeometries( nodeToWriter->getInstanceGeometries(), worldMatrix);

		writeInstanceNodes( nodeToWriter->getInstanceNodes() );

		mNodeInfoStack.pop();

		return true;
	}


	//------------------------------
	void SceneGraphWriter::storeInstanceGeometries( const COLLADAFW::InstanceGeometryPointerArray& instanceGeometries, 
													const COLLADABU::Math::Matrix4& worldMatrix  )
	{
		for ( size_t i = 0, count = instanceGeometries.getCount(); i < count; ++i)
		{
			COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometries[i];
			OgreWriter::InstanceGeometryInfo instanceGeometryInfo( instanceGeometry, worldMatrix );
			addGeometryUniqueIdInstanceGeometryInfoPair(instanceGeometry->getInstanciatedObjectId(), instanceGeometryInfo);
		}
	}

	//------------------------------
	void SceneGraphWriter::writeInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodes)
	{
		for ( size_t i = 0, count = instanceNodes.getCount(); i < count; ++i)
		{
			const COLLADAFW::InstanceNode* instanceNode = instanceNodes[i];
			const COLLADAFW::UniqueId& referencedNodeUniqueId = instanceNode->getInstanciatedObjectId();
			UniqueIdNodeMap::const_iterator it = mUniqueIdNodeMap.find( referencedNodeUniqueId );
			if ( it != mUniqueIdNodeMap.end() )
			{
				const COLLADAFW::Node* referencedNode = it->second;
				writeNode( referencedNode );
			}
		}
	}

	//------------------------------
	void SceneGraphWriter::createUniqueIdNodeMap( COLLADAFW::Node* node )
	{
		mUniqueIdNodeMap[node->getUniqueId()] = node;
		createUniqueIdNodeMap( node->getChildNodes() );
	}

	//------------------------------
	void SceneGraphWriter::createUniqueIdNodeMap( const COLLADAFW::NodePointerArray& nodes )
	{
		for ( size_t i = 0, cout = nodes.getCount(); i < cout; ++i)
		{
			COLLADAFW::Node* node = nodes[i];
			createUniqueIdNodeMap( node );
		}
	}

	//------------------------------
	void SceneGraphWriter::createUniqueIdNodeMap()
	{
		createUniqueIdNodeMap( mVisualScene.getRootNodes() );
		OgreWriter::LibraryNodesList::const_iterator it = mLibraryNodesList.begin();
		for ( ; it != mLibraryNodesList.end(); ++it )
		{
			const COLLADAFW::LibraryNodes& libraryNodes = *it;
			createUniqueIdNodeMap( libraryNodes.getNodes() );
		}
	}

} // namespace DAE2Ogre
