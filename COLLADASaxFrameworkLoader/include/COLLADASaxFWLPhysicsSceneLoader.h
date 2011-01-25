/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_PHYSICSSCENELOADER_H__
#define __COLLADASAXFWL_PHYSICSSCENELOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLHelperLoaderBase.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLXmlTypes.h"


namespace COLLADAFW
{ 
	class PhysicsScene;
}

namespace COLLADASaxFWL
{

    /** Imports the entire Physics scene and sends it to the writer. */
	class PhysicsSceneLoader : public HelperLoaderBase
	{
	private:

		
		/** The current scene has gravity.*/
		bool mCurrentSceneHasGravity;
	
		/** The current scene has timeStep.*/
		bool mCurrentSceneHasTimeStep;
	
	protected:
		/** Pointer to the Physics scene this loader creates.*/
		COLLADAFW::PhysicsScene* mPhysicsScene;
        

	public:

        /** Constructor. */
		PhysicsSceneLoader();

        /** Destructor. */
		virtual ~PhysicsSceneLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();
        
		bool beginPhysicsScene ( const physics_scene__AttributeData& attributeData );

		bool endPhysicsScene () ; 
        /** Sax callback function for the ending of a Physics scene.*/
		virtual bool end__physics_scene();

		/** Sax callback function for the ending of a Physics scene.*/
		virtual bool begin__physics_scene(const physics_scene__AttributeData& attributeData );


		virtual bool begin__instance_force_field( const COLLADASaxFWL14::instance_force_field__AttributeData& attributeData ){return true; }

		virtual bool end__instance_force_field(){return true; }

		virtual bool begin__instance_physics_model( const COLLADASaxFWL14::instance_physics_model__AttributeData& attributeData ){return true; }

		virtual bool end__instance_physics_model(){return true; }

		virtual bool begin__instance_rigid_body( const COLLADASaxFWL14::instance_rigid_body__AttributeData& attributeData ){return true;}
		
		virtual bool end__instance_rigid_body(){return true;}

		virtual bool begin__instance_rigid_body__technique_common() { return true; }

		virtual bool end__instance_rigid_body__technique_common(){ return true; }

		virtual bool begin__physics_scene__technique_common() { return true; }

		virtual bool end__physics_scene__technique_common(){ return true; }

		/** Add animatable float to sid tree*/
		virtual bool begin__gravity( const gravity__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__gravity();

		/** Stores the gravity of the current scene.*/
		virtual bool data__gravity( const float* value, size_t length );

		/** Add animatable float to sid tree*/
		virtual bool begin__time_step( const time_step__AttributeData& attributeData );

		/** Move up in sid tree.*/
		virtual bool end__time_step();

		/** Stores the time step of the current scene.*/
		virtual bool data__time_step( float value );

    private:

        /** Disable default copy ctor. */
        PhysicsSceneLoader( const PhysicsSceneLoader& pre );

        /** Disable default assignment operator. */
        const PhysicsSceneLoader& operator= ( const PhysicsSceneLoader& pre );

    };

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_PhysicsSCENELOADER_H__
