/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWInstanceKinematicsScene.h"


namespace COLLADAFW
{

	//------------------------------
	InstanceKinematicsScene::InstanceKinematicsScene( const UniqueId& uniqueId, const UniqueId& instanciatedObjectId ) 
		: InstanceBase<COLLADA_TYPE::INSTANCE_KINEMATICS_SCENE>(uniqueId, instanciatedObjectId)
		, mBoundNodes(UniqueIdArray::OWNER)
		, mNodeLinkBindings(NodeLinkBindingArray::OWNER)
	{

	}

	//------------------------------
	InstanceKinematicsScene::InstanceKinematicsScene( const InstanceKinematicsScene& pre )
		: InstanceBase<COLLADA_TYPE::INSTANCE_KINEMATICS_SCENE>(pre)
		, mFileId(pre.mFileId)
		, mBoundNodes(UniqueIdArray::OWNER)
		, mNodeLinkBindings(NodeLinkBindingArray::OWNER)
	{
		pre.mBoundNodes.cloneArray(mBoundNodes);
		pre.mNodeLinkBindings.cloneArray(mNodeLinkBindings);
	}


    //------------------------------
	InstanceKinematicsScene::~InstanceKinematicsScene()
	{
	}

	//------------------------------
	const InstanceKinematicsScene& InstanceKinematicsScene::operator=( const InstanceKinematicsScene& pre )
	{
		InstanceBase<COLLADA_TYPE::INSTANCE_KINEMATICS_SCENE>::operator =(pre);
		pre.mBoundNodes.cloneArray(mBoundNodes);
		pre.mNodeLinkBindings.cloneArray(mNodeLinkBindings);
		mFileId = pre.mFileId;
		return *this;
	}


	//------------------------------
	bool InstanceKinematicsScene::NodeLinkBinding::operator<( const NodeLinkBinding& rhs ) const
	{
		if ( nodeUniqueId < rhs.nodeUniqueId )
		{
			return true;
		}
		if ( nodeUniqueId > rhs.nodeUniqueId )
		{
			return false;
		}

		if ( kinematicsModel < rhs.kinematicsModel )
		{
			return true;
		}
		if ( kinematicsModel > rhs.kinematicsModel )
		{
			return false;
		}

		if ( linkNumber < rhs.linkNumber )
		{
			return true;
		}

		return false;
	}

} // namespace COLLADAFW
