/*
	Copyright (c) 2010 yaoyansi<yaoyansi2@yahoo.com.cn>

	This file is part of dae23ds_lib3ds.

	Licensed under the MIT Open Source License, 
	for details please see LICENSE file or the website
	http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_SCENEGRAPHHANDLER_H__
#define __DAE23DS_SCENEGRAPHHANDLER_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsWriter.h"

namespace DAE23ds
{

	class SceneGraphHandler
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

		const COLLADAFW::VisualScene* mVisualScene;

	public:

		SceneGraphHandler( const COLLADAFW::VisualScene* visualScene);

		virtual ~SceneGraphHandler();

		bool handle();

	private:

		/** Disable default copy ctor. */
		SceneGraphHandler( const SceneGraphHandler& pre );

		/** Disable default assignment operator. */
		const SceneGraphHandler& operator= ( const SceneGraphHandler& pre );

		bool handleNodes(  const COLLADAFW::NodePointerArray& nodesToWriter);

		bool handleNode(  const COLLADAFW::Node* nodeToWriter);

		void handleInstanceGeometries( const COLLADAFW::Node* node, const COLLADABU::Math::Matrix4& matrix );
		
		void handleInstanceLights( const COLLADAFW::Node* node, const COLLADABU::Math::Matrix4& matrix );

		void handleInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodes);
		
		void addInstanceGeometryInstanceGeometryInfoPair(const COLLADAFW::UniqueId& geoId, const Writer::InstanceGeometryInfo& instanceGeoInfo);

	};

} // namespace DAE23DS

#endif // __DAE23DS_SCENEGRAPHHANDLER_H__
