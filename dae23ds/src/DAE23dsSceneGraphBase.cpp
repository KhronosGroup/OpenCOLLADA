/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "dae23dsStableHeaders.h"
#include "DAE23dsSceneGraphBase.h"


namespace DAE23ds
{

    //------------------------------
	SceneGraphBase::SceneGraphBase( Writer* writer3ds, const COLLADAFW::VisualScene* visualScene, const Writer::LibraryNodesList& libraryNodesList )
		: BaseWriter( writer3ds )
		, mVisualScene(visualScene)
		, mLibraryNodesList(libraryNodesList)
	{

	}

    //------------------------------
	SceneGraphBase::~SceneGraphBase()
	{
	}

	//------------------------------
	size_t SceneGraphBase::getNextInstanceNumber( const COLLADAFW::InstanceGeometry* instance )
	{
		if ( !getApplyTransformationsToMeshes() )
		{
			return 0;
		}
		InstanceGeometryNextInstanceNumberMap::iterator it = mInstanceGeometryNextInstanceNumberMap.find(instance);
		if ( it == mInstanceGeometryNextInstanceNumberMap.end() )
		{
			mInstanceGeometryNextInstanceNumberMap.insert(std::make_pair(instance,1));
			return 0;
		}
		else
		{
			return it->second++;
		}
	}
} // namespace DAE23ds
