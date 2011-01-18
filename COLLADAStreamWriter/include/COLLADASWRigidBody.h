/* * Contributor(s): Prabhath Jayathilake.*/

#ifndef __COLLADASTREAMWRITER_RIGID_BODY_H__
#define __COLLADASTREAMWRITER_RIGID_BODY_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    /** A class that hold all information about an @a \<rigid_body\> element.*/
    class RigidBody : public ElementWriter, public BaseExtraTechnique
    {

    private:

        // LibraryPhysicsModel should be able to call the add() method.
        friend class LibraryPhysicsModel;

        /** The id of the rigid body.*/
        String mRigidBodyId;

        /** The name of the rigid body.*/
        String mRigidBodyName;

		/** the sid of the RigidBody. used in Instance Rigid Body*/
		String mRigidBodySid;


		/** Closer to close the rigid body*/
        TagCloser mRigidBodyCloser;

		/**Whether the Rigid Body is Dynamic or not*/
		bool dynamic;

		/**The mass of the Rigid Body*/
		float mass;


    public:

		/**
        * Constructor
        * @param rigidBodyId The id of the body.
        * @param rigidBodyName The name of the body.
        */
        RigidBody (StreamWriter* streamWriter,const String& bodyId,const String& bodyName = ElementWriter::EMPTY_STRING,const String& bodySid = ElementWriter::EMPTY_STRING)
			: ElementWriter( streamWriter )
		    ,mRigidBodySid(bodySid)
			,mRigidBodyId(bodyId)
			,mRigidBodyName(bodyName) {}

        /** Destructor */
        virtual ~RigidBody()
        { }

        /** Returns a reference to the rigid body id */
        const String& getBodyId() const { return mRigidBodyId; }

		/** Returns a reference to the rigid body sid */
        const String& getBodySid() const { return mRigidBodySid; }

        /** Returns a reference to the rigid body name */
        const String& getBodyName() const { return mRigidBodyName; }
        
        /** Returns whether the Rigid Body is dynamic */
        const bool isDynamic() const { return dynamic; }

		/** Returns the mass of rigid body id */
        const float getBodyMass() const { return mass; }

		/**Set Boolean of dynamic*/
		void setDynamic(const bool Bool) { dynamic = Bool; }

		/**Set mass of Rigid Body*/
		void setMass(const float val ) { mass = val; }


		/** Opens the model tag
        It should be closed using close()*/
        void add();

    
    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_RIGID_BODY_H__
