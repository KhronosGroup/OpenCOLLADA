/* * Contributor(s): Prabhath Jayathilake.*/

#ifndef __COLLADAFW_RIGIDBODY_H__
#define __COLLADAFW_RIGIDBODY_H__

#include "COLLADAFWPrerequisites.h"
//#include "COLLADAFWPhysicsModel.h"//
//#include "COLLADAFWPhysicsController.h"//
#include "COLLADAFWInstancePhysicsScenes.h"//
#include "COLLADAFWAnimatableFloat.h"
#include "COLLADAFWAnimatableBool.h"




namespace COLLADAFW
{
    typedef PointerArray<RigidBody> BodyPointerArray;
    /** Contains the entire Physics information of a COLLADA file. */
	class RigidBody : public ObjectTemplate<COLLADA_TYPE::RIGID_BODY> 	
	{
	private:
		
		/**The mass of the Rigid Body*/
		AnimatableFloat mMass;

		/**The dynamicity of the Rigid Body*/
		AnimatableBool mDynamic;

		/**
		* The name attribute is the text string name of this element. 
		* Optional attribute.
		*/
		String mName;

		 /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

		 /** List of all child rigidbodies. Array and contents will be delete in destructor.*/
		BodyPointerArray mChildBodies;

		String mNodeName;

	public:

        /** Constructor. */
		RigidBody(const UniqueId& uniqueId):
		  ObjectTemplate < COLLADA_TYPE::RIGID_BODY> ( uniqueId )
          {}
				 	
        /** Destructor. */
	    virtual ~RigidBody() {};
        
		
		/** Sets the name of the scene.*/
		void setName(const String& name) { mName = name; }

		 /**
        * The original object id, if it in the original file format exist. 
        */
         void setOriginalId ( const String& val ) { mOriginalId = val; }

		 const String& getOriginalId ( ) const { return mOriginalId; }

        /** Returns the dynamicity of the rigid body.*/
		AnimatableBool& isDynamic() { return mDynamic; }
   
		/** Returns the dynamicity of the rigid body.*/
	    const AnimatableBool& isDynamic() const { return mDynamic; }
   
		/** Returns the mass of the body.*/
		AnimatableFloat& getMass() { return mMass; }
   
		/** Returns the mass of the body.*/
  		const AnimatableFloat& getMass() const { return mMass; }
   
		void setDynamicity( bool dynamic) { mDynamic = dynamic;	} 	
		
		void setMass(float mass) { mMass = mass ; }

		/** Get list of all child bodie.*/
		BodyPointerArray& getChildBodies() { return mChildBodies; }

		/** Get list of all child nodes.*/
		const BodyPointerArray& getChildBodies() const { return mChildBodies; }
	
		 /** Creates a clone of the rigidbody and returns a pointer to it.*/
		 RigidBody* clone() const { return FW_NEW RigidBody(*this); }
	private:

//         /** Disable default copy ctor. */
// 		PhysicsScene( const PhysicsScene& pre );
// 
//         /** Disable default assignment operator. */
// 		const PhysicsScene& operator= ( const PhysicsScene& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_RIGIDBODY_H__
