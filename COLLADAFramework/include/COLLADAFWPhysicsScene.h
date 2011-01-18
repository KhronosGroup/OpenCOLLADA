/* * Contributor(s): Prabhath Jayathilake.*/

#ifndef __COLLADAFW_PHYSICSSCENE_H__
#define __COLLADAFW_PHYSICSSCENE_H__

#include "COLLADAFWPrerequisites.h"
//#include "COLLADAFWPhysicsModel.h"//
//#include "COLLADAFWPhysicsController.h"//
#include "COLLADAFWInstancePhysicsScenes.h"//
#include "COLLADAFWAnimatableFloat.h"
#include "COLLADAFWGravity.h"



namespace COLLADAFW
{

    /** Contains the entire Physics information of a COLLADA file. */
	class PhysicsScene : public ObjectTemplate<COLLADA_TYPE::PHYSICS_SCENE> 	
	{
	private:
		///** All Physics models.*/
		//PhysicsModelArray mPhysicsModels;

		/** All Physics controllers.*/
		//PhysicsControllerArray mPhysicsControllerArray;

		/** All the instance Physics scenes in the model.*/
		InstancePhysicsSceneArray mInstancePhysicsScenes;

		/**The Gravity of the scene*/
		Gravity mGravity;

		/**The time step of the scene*/
		AnimatableFloat time_step;

		/**
		* The name attribute is the text string name of this element. 
		* Optional attribute.
		*/
		String mName;



	public:

        /** Constructor. */
		PhysicsScene(const UniqueId& uniqueId):
		  ObjectTemplate < COLLADA_TYPE::PHYSICS_SCENE > ( uniqueId ),
          mGravity(0,0,0)
		  {}

        /** Destructor. */
		virtual ~PhysicsScene();
        
		//-------TODO-----------
		///** Returns all Physics models.*/
		//const PhysicsModelArray& getPhysicsModels() const { return mPhysicsModels; }

		///** Returns all Physics models.*/
		//PhysicsModelArray& getPhysicsModels() { return mPhysicsModels; }

		///** Returns all Physics models.*/
		//const PhysicsControllerArray& getPhysicsControllers() const { return mPhysicsControllerArray; }

		/** Returns all Physics models.*/
		//PhysicsControllerArray& getPhysicsControllers() { return mPhysicsControllerArray; }

		/** All the instance Physics scenes in the model.*/
		InstancePhysicsSceneArray InstancePhysicsScenes;

		/** Returns all Physics models.*/
		const InstancePhysicsSceneArray& getInstancePhysicsScenes() const { return mInstancePhysicsScenes; }

		/** Returns all Physics models.*/
		InstancePhysicsSceneArray& getInstancePhysicsScenes() { return mInstancePhysicsScenes; }

		/** Sets the name of the scene.*/
		void setName(const String& name) { mName = name; }

        /** Returns the gravity of the scene.*/
		Gravity& getGravity() { return mGravity; }
   
		/** Returns the gravity of the scene.*/
        const Gravity& getGravity() const { return mGravity; }
   
		/** Returns the gravity of the scene.*/
		AnimatableFloat& getTimestep() { return time_step; }
   
		/** Returns the gravity of the scene.*/
  		const AnimatableFloat& getTimestep() const { return time_step; }
   
		void setGravity( Gravity gravity) { mGravity = gravity;	} 	
		
		void setTimeStep(float tstep) { time_step = tstep ; }
	private:

//         /** Disable default copy ctor. */
// 		PhysicsScene( const PhysicsScene& pre );
// 
//         /** Disable default assignment operator. */
// 		const PhysicsScene& operator= ( const PhysicsScene& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_PHYSICSSCENE_H__
