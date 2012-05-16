/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2OGRE_SCENEGRAPHWRITER_H__
#define __DAE2OGRE_SCENEGRAPHWRITER_H__

#include "DAE2OgrePrerequisites.h"
#include "DAE2OgreBaseWriter.h"

#include "DAE2OgreOgreWriter.h"

#include "Math/COLLADABUMathMatrix4.h"


namespace COLLADAFW
{
	class VisualScene;
}

namespace DAE2Ogre
{

	class SceneGraphWriter : public BaseWriter 
	{
	private:
		struct NodeInfo
		{
			NodeInfo( COLLADABU::Math::Matrix4 _worldTransformation)
				: worldTransformation(_worldTransformation){}
			COLLADABU::Math::Matrix4 worldTransformation;
		};

		typedef std::stack<NodeInfo> NodeInfoStack;

		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Node*> UniqueIdNodeMap;

	private:
		const COLLADAFW::VisualScene& mVisualScene;
		const OgreWriter::LibraryNodesList& mLibraryNodesList;
		NodeInfoStack mNodeInfoStack;
		UniqueIdNodeMap mUniqueIdNodeMap;
	
	public:

		SceneGraphWriter( OgreWriter* ogreWriter, const COLLADAFW::VisualScene& visualScene, const OgreWriter::LibraryNodesList& libraryNodesList );

		virtual ~SceneGraphWriter();

		bool write();


	private:

        /** Disable default copy ctor. */
		SceneGraphWriter( const SceneGraphWriter& pre );

        /** Disable default assignment operator. */
		const SceneGraphWriter& operator= ( const SceneGraphWriter& pre );

		void createUniqueIdNodeMap( COLLADAFW::Node* node );

		void createUniqueIdNodeMap( const COLLADAFW::NodePointerArray& nodes );

		void createUniqueIdNodeMap();

		bool writeNodes(  const COLLADAFW::NodePointerArray& nodesToWriter);

		bool writeNode(  const COLLADAFW::Node* nodeToWriter);

		void storeInstanceGeometries( const COLLADAFW::InstanceGeometryPointerArray& instanceGeometries, 
			const COLLADABU::Math::Matrix4& worldMatrix );
	
		void writeInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodes);


	};

} // namespace DAE2Ogre

#endif // __DAE2OGRE_SCENEGRAPHWRITER_H__
