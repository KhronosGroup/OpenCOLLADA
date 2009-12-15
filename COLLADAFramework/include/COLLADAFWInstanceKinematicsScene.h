/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCEKINEMATICSSCENE_H__
#define __COLLADAFW_INSTANCEKINEMATICSSCENE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWInstanceBase.h"
#include "COLLADAFWUniqueId.h"

namespace COLLADAFW
{

    /** TODO Documentation */
	class InstanceKinematicsScene : public InstanceBase<COLLADA_TYPE::INSTANCE_KINEMATICS_SCENE>
	{
	private:

		/** List of all nodes of the visual scene that are bound to the kinematics model.*/
		UniqueIdArray mBoundNodes;
	
	public:

        /** Constructor. */
		InstanceKinematicsScene(const UniqueId& uniqueId, const UniqueId& instanciatedObjectId )
			: InstanceBase<COLLADA_TYPE::INSTANCE_KINEMATICS_SCENE>(uniqueId, instanciatedObjectId)
			, mBoundNodes(UniqueIdArray::OWNER){}


        /** Destructor. */
		virtual ~InstanceKinematicsScene(){}

		UniqueIdArray& getBoundNodes() { return mBoundNodes; }

		const UniqueIdArray& getBoundNodes() const { return mBoundNodes; }

	private:

        /** Disable default copy ctor. */
		InstanceKinematicsScene( const InstanceKinematicsScene& pre );

        /** Disable default assignment operator. */
		const InstanceKinematicsScene& operator= ( const InstanceKinematicsScene& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEKINEMATICSSCENE_H__
