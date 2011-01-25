/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_PHYSICSMODELLOADER_H__
#define __COLLADASAXFWL_PHYSICSMODELLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLHelperLoaderBase.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLXmlTypes.h"
#include "COLLADASaxFWLFilePartLoader.h"


namespace COLLADAFW
{ 
	class PhysicsModel;
	class RigidBody;
}

namespace COLLADASaxFWL
{

    /** Imports the entire Physics Model and sends it to the writer. */
	class PhysicsModelLoader : public HelperLoaderBase
	{
		/** Stack of rigid bodies.*/
		typedef std::stack<COLLADAFW::RigidBody*> RigidbodyStack;
		
			
	protected:
		/** Pointer to the Physics Model this loader creates.*/
		COLLADAFW::PhysicsModel* mPhysicsModel;

		/** Stack of rigid Bodies to traverse back in the model hierarchy. Array and contents will be delete in destructor.*/
		RigidbodyStack mRigidbodyStack;
        

	public:

        /** Constructor. */
		PhysicsModelLoader( );

        /** Destructor. */
		virtual ~PhysicsModelLoader( );

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();
        
		bool beginPhysicsModel ( const physics_model__AttributeData& attributeData );

		bool endPhysicsModel () ; 
        /** Sax callback function for the ending of a Physics Model.*/
		virtual bool end__physics_model();

		/** Sax callback function for the ending of a Physics Model.*/
		virtual bool begin__physics_model(const physics_model__AttributeData& attributeData );

		virtual bool begin__rigid_body( const rigid_body__AttributeData& attributeData );

		virtual bool end__rigid_body();

		virtual bool begin__rigid_body__technique_common() { return true; }

		virtual bool end__rigid_body__technique_common() { return true; }

		virtual bool begin__rigid_body__technique_common__dynamic( const rigid_body__technique_common__dynamic__AttributeData& attributeData );

		virtual bool end__rigid_body__technique_common__dynamic();

		virtual bool data__rigid_body__technique_common__dynamic( const bool value );

		virtual bool begin__mass( const mass__AttributeData& attributeData );

		virtual bool end__mass();

		virtual bool data__mass( const float value );
		
		virtual bool begin__mass_frame(){ return true; }

		virtual bool end__mass_frame() { return true; }

virtual bool begin__inertia( const COLLADASaxFWL14::inertia__AttributeData& attributeData ){return true; }

virtual bool end__inertia(){return true; }

virtual bool data__inertia( const float* value, size_t length ){return true; }

virtual bool begin__instance_physics_material( const COLLADASaxFWL14::instance_physics_material__AttributeData& attributeData ){return true; }

virtual bool end__instance_physics_material(){return true; }

virtual bool begin__shape(){return true; }

virtual bool end__shape(){return true; }

virtual bool begin__shape__hollow( const COLLADASaxFWL14::rigid_body__technique_common__shape__hollow__AttributeData& attributeData ){return true; }

virtual bool end__shape__hollow(){return true; }

virtual bool data__shape__hollow( const bool value ){return true; }

virtual bool begin__density( const COLLADASaxFWL14::density__AttributeData& attributeData ){return true; }

virtual bool end__density(){return true; }

virtual bool data__density( const float value ){return true; }

virtual bool begin__plane(){return true; }

virtual bool end__plane(){return true; }

virtual bool begin__equation(){return true; }

virtual bool end__equation(){return true; }

virtual bool data__equation( const float* data, size_t length ){return true; }

virtual bool begin__box(){return true; }

virtual bool end__box(){return true; }

virtual bool begin__half_extents(){return true; }

virtual bool end__half_extents(){return true; }

virtual bool data__half_extents( const float* data, size_t length ){return true; }

virtual bool begin__sphere(){return true; }

virtual bool end__sphere(){return true; }

virtual bool begin__radius____float(){return true; }

virtual bool end__radius____float(){return true; }

virtual bool data__radius____float( const float value ){return true; }

virtual bool begin__cylinder(){return true; }

virtual bool end__cylinder(){return true; }

virtual bool begin__height(){return true; }

virtual bool end__height(){return true; }

virtual bool data__height( const float value ){return true; }

virtual bool begin__radius____float2(){return true; }

virtual bool end__radius____float2(){return true; }

virtual bool data__radius____float2( const float* data, size_t length ){return true; }

virtual bool begin__capsule(){return true; }

virtual bool end__capsule(){return true; }

virtual bool begin__radius____float3(){return true; }

virtual bool end__radius____float3(){return true; }

virtual bool data__radius____float3( const float* data, size_t length ){return true; }

virtual bool begin__instance_geometry( const COLLADASaxFWL14::instance_geometry__AttributeData& attributeData ){return true; }

virtual bool end__instance_geometry(){return true; }

virtual bool begin__rigid_constraint( const COLLADASaxFWL14::rigid_constraint__AttributeData& attributeData ){return true; }

virtual bool end__rigid_constraint(){return true; }

virtual bool begin__ref_attachment( const COLLADASaxFWL14::ref_attachment__AttributeData& attributeData ){return true; }

virtual bool end__ref_attachment(){return true; }

virtual bool begin__attachment( const COLLADASaxFWL14::attachment__AttributeData& attributeData ){return true; }

virtual bool end__attachment(){return true; }

virtual bool begin__translate( const COLLADASaxFWL14::translate__AttributeData& attributeData ){return true; }

virtual bool end__translate(){return true; }

virtual bool data__translate( const float* data, size_t length ){return true; }

virtual bool begin__rotate( const COLLADASaxFWL14::rotate__AttributeData& attributeData ){return true; }

virtual bool end__rotate(){return true; }

virtual bool data__rotate( const float* data, size_t length ){return true; }

virtual bool begin__rigid_constraint__technique_common(){return true; }

virtual bool end__rigid_constraint__technique_common(){return true; }

virtual bool begin__enabled( const COLLADASaxFWL14::enabled__AttributeData& attributeData ){return true; }

virtual bool end__enabled(){return true; }

virtual bool data__enabled( const bool value ){return true; }

virtual bool begin__interpenetrate( const COLLADASaxFWL14::interpenetrate__AttributeData& attributeData ){return true; }

virtual bool end__interpenetrate(){return true; }

virtual bool data__interpenetrate( const bool value ){return true; }

virtual bool begin__limits(){return true; }

virtual bool end__limits(){return true; }

virtual bool begin__swing_cone_and_twist(){return true; }

virtual bool end__swing_cone_and_twist(){return true; }

virtual bool begin__min( const COLLADASaxFWL14::min__AttributeData& attributeData ){return true; }

virtual bool end__min(){return true; }

virtual bool data__min( const float* value, size_t length ){return true; }

virtual bool begin__max( const COLLADASaxFWL14::max__AttributeData& attributeData ){return true; }

virtual bool end__max(){return true; }

virtual bool data__max( const float* value, size_t length ){return true; }

virtual bool begin__spring(){return true; }

virtual bool end__spring(){return true; }

virtual bool begin__limits__linear(){return true; }

virtual bool end__limits__linear(){return true; }

virtual bool begin__angular(){return true; }

virtual bool end__angular(){return true; }

virtual bool begin__stiffness( const COLLADASaxFWL14::stiffness__AttributeData& attributeData ){return true; }

virtual bool end__stiffness(){return true; }

virtual bool data__stiffness( const float value ){return true; }

virtual bool begin__damping( const COLLADASaxFWL14::damping__AttributeData& attributeData ){return true; }

virtual bool end__damping(){return true; }

virtual bool data__damping( const float value ){return true; }

virtual bool begin__target_value( const COLLADASaxFWL14::target_value__AttributeData& attributeData ){return true; }

virtual bool end__target_value(){return true; }

virtual bool data__target_value( const float value ){return true; }

virtual bool begin__spring__linear(){return true; }

virtual bool end__spring__linear(){return true; }

virtual bool begin__instance_physics_model( const COLLADASaxFWL14::instance_physics_model__AttributeData& attributeData ){return true; }

virtual bool end__instance_physics_model(){return true; }

virtual bool begin__instance_force_field( const COLLADASaxFWL14::instance_force_field__AttributeData& attributeData ){return true; }

virtual bool end__instance_force_field(){return true; }

virtual bool begin__instance_rigid_body( const COLLADASaxFWL14::instance_rigid_body__AttributeData& attributeData ){return true; }

virtual bool end__instance_rigid_body(){return true; }

virtual bool begin__angular_velocity(){return true; }

virtual bool end__angular_velocity(){return true; }

virtual bool data__angular_velocity( const float* data, size_t length ){return true; }

virtual bool begin__velocity(){return true; }

virtual bool end__velocity(){return true; }

virtual bool data__velocity( const float* data, size_t length ){return true; }

virtual bool begin__instance_rigid_body__technique_common__dynamic( const COLLADASaxFWL14::instance_rigid_body__technique_common__dynamic__AttributeData& attributeData ){return true; }

virtual bool end__instance_rigid_body__technique_common__dynamic(){return true; }

virtual bool data__instance_rigid_body__technique_common__dynamic( const bool value ){return true; }

virtual bool begin__instance_rigid_body__technique_common(){return true; }

virtual bool end__instance_rigid_body__technique_common(){return true; }

virtual bool begin__instance_rigid_body__technique_common__mass_frame(){return true; }

virtual bool end__instance_rigid_body__technique_common__mass_frame(){return true; }

virtual bool begin__instance_rigid_body__technique_common__shape(){return true; }

virtual bool end__instance_rigid_body__technique_common__shape(){return true; }

virtual bool begin__instance_rigid_body__technique_common__shape__hollow( const COLLADASaxFWL14::instance_rigid_body__technique_common__shape__hollow__AttributeData& attributeData ){return true; }

virtual bool end__instance_rigid_body__technique_common__shape__hollow(){return true; }

virtual bool data__instance_rigid_body__technique_common__shape__hollow( const bool value ){return true; }

virtual bool begin__instance_rigid_constraint( const COLLADASaxFWL14::instance_rigid_constraint__AttributeData& attributeData ){return true; }

virtual bool end__instance_rigid_constraint( ){return true; }

		
    private:

		/** Store a parent rigidbody, i.e. a rigid body that does not has a rigid body as parent.*/
		virtual void handleParentBody( COLLADAFW::RigidBody* parentBody );

        /** Disable default copy ctor. */
        PhysicsModelLoader( const PhysicsModelLoader& pre );

        /** Disable default assignment operator. */
        const PhysicsModelLoader& operator= ( const PhysicsModelLoader& pre );

    };

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_PhysicsModelLOADER_H__
