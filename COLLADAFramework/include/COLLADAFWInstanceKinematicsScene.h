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
#include "COLLADAFWPointerArray.h"

namespace COLLADAFW
{
	class KinematicsModel;

    /** TODO Documentation */
	class InstanceKinematicsScene : public InstanceBase<COLLADA_TYPE::INSTANCE_KINEMATICS_SCENE>
	{
	public:
		struct NodeLinkBinding
		{
			/** The uniqueId of the node within the visual scene, that is bound to a link.*/
			COLLADAFW::UniqueId nodeUniqueId;

			/** The index of the kinematics model the link the node is bound to belongs to.*/
			size_t kinematicsModelId;

			/** The number of the link within the kinematics model.*/
			size_t linkNumber;

			bool operator<(const NodeLinkBinding& rhs)const;
		};

		typedef Array<NodeLinkBinding> NodeLinkBindingArray;

	private:

		/** List of all nodes of the visual scene that are bound to the kinematics model.*/
		UniqueIdArray mBoundNodes;

		/** The node link bindings of the instance kinematics scene.*/
		NodeLinkBindingArray mNodeLinkBindings;

		/** The id of the COLLADA file the instance kinematics scene belongs to.*/
		FileId mFileId;
	
	public:

        /** Constructor. */
		InstanceKinematicsScene(const UniqueId& uniqueId, const UniqueId& instanciatedObjectId );


        /** Destructor. */
		virtual ~InstanceKinematicsScene();

		UniqueIdArray& getBoundNodes() { return mBoundNodes; }

		const UniqueIdArray& getBoundNodes() const { return mBoundNodes; }

		/** The node link bindings of the instance kinematics scene.*/
		const NodeLinkBindingArray& getNodeLinkBindings() const { return mNodeLinkBindings; }

		/** The node link bindings of the instance kinematics scene.*/
		NodeLinkBindingArray& getNodeLinkBindings() { return mNodeLinkBindings; }

		/** The id of the COLLADA file the instance kinematics scene belongs to.*/
		FileId getFileId() const { return mFileId; }

		/** The id of the COLLADA file the instance kinematics scene belongs to.*/
		void setFileId(FileId fileId) { mFileId = fileId; }

		/** Creates a clone of the InstanceKinematicsScene and returns a pointer to it.*/
		InstanceKinematicsScene* clone() const { return FW_NEW InstanceKinematicsScene(*this); }

	private:

        /** Disable default copy ctor. */
		InstanceKinematicsScene( const InstanceKinematicsScene& pre );

        /** Disable default assignment operator. */
		const InstanceKinematicsScene& operator= ( const InstanceKinematicsScene& pre );

	};

	typedef PointerArray<InstanceKinematicsScene> InstanceKinematicsSceneArray;


} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEKINEMATICSSCENE_H__
