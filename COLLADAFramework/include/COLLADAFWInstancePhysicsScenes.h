/* * Contributor(s): Prabhath Jayathilake.*/

#ifndef __COLLADAFW_INSTANCEPHYSICSSCENE_H__
#define __COLLADAFW_INSTANCEPHYSICSSCENE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWInstanceBase.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWPointerArray.h"

namespace COLLADAFW
{
	class PhysicsModel;

    /** TODO Documentation */
	class InstancePhysicsScene : public InstanceBase<COLLADA_TYPE::INSTANCE_PHYSICS_SCENE>
	{
	public:
		struct NodeModelBinding
		{
			/** The uniqueId of the node within the visual scene, that is bound to a model.*/
			COLLADAFW::UniqueId nodeUniqueId;

			/** The index of the Physics model the node is bound to .*/
			size_t PhysicsModelId;

			bool operator<(const NodeModelBinding& rhs)const;
		};

		typedef Array<NodeModelBinding> NodeModelBindingArray;

	private:

		/** List of all nodes of the visual scene that are bound to the Physics model.*/
		UniqueIdArray mBoundNodes;

		/** The node Model bindings of the instance Physics scene.*/
		NodeModelBindingArray mNodeModelBindings;

		/** The id of the COLLADA file the instance Physics scene belongs to.*/
		FileId mFileId;
	
	public:

        /** Constructor. */
		InstancePhysicsScene(const UniqueId& uniqueId, const UniqueId& instanciatedObjectId );


        /** Destructor. */
		virtual ~InstancePhysicsScene();

		UniqueIdArray& getBoundNodes() { return mBoundNodes; }

		const UniqueIdArray& getBoundNodes() const { return mBoundNodes; }

		/** The node Model bindings of the instance Physics scene.*/
		const NodeModelBindingArray& getNodeModelBindings() const { return mNodeModelBindings; }

		/** The node Model bindings of the instance Physics scene.*/
		NodeModelBindingArray& getNodeModelBindings() { return mNodeModelBindings; }

		/** The id of the COLLADA file the instance Physics scene belongs to.*/
		FileId getFileId() const { return mFileId; }

		/** The id of the COLLADA file the instance Physics scene belongs to.*/
		void setFileId(FileId fileId) { mFileId = fileId; }

		/** Creates a clone of the InstancePhysicsScene and returns a pointer to it.*/
		InstancePhysicsScene* clone() const { return FW_NEW InstancePhysicsScene(*this); }

	private:

        /** Disable default copy ctor. */
		InstancePhysicsScene( const InstancePhysicsScene& pre );

        /** Disable default assignment operator. */
		const InstancePhysicsScene& operator= ( const InstancePhysicsScene& pre );

	};

	typedef PointerArray<InstancePhysicsScene> InstancePhysicsSceneArray;


} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEPHYSICSSCENE_H__
