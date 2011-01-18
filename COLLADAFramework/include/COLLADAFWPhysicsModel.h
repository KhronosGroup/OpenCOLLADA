/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_PHYSICSMODEL_H__
#define __COLLADAFW_PHYSICSMODEL_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTransformation.h"
#include "COLLADAFWBody.h"//
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

    /** A Physics model. It describes a Physics model, using the rigidBodies contained in mrigidBodies. The hierarchy 
	of the model is defines by a list of LinkBodyConnection that connect the bodies to a link. Since links do 
	not have any properties, they are simply described by numbers, starting from 0.  */
	class PhysicsModel : public ObjectTemplate<COLLADA_TYPE::PHYSICS_MODEL>
	{
	public:
		/** Defines the connection of a body to a link.*/
		class LinkBodyConnection
		{
		private:
			/** The number of the link. This number is used to uniquely identify one link within a specific 
			Physics model. The base link has always number 0. */
			size_t mLinkNumber;

			/** The index of the body in mBodies of PhysicsModel.*/
			size_t mBodyIndex;

			/** The transformation defining the position and orientation of the body, relative to the link.*/
			TransformationPointerArray mTransformations;

		public:
			LinkBodyConnection( size_t linkNumber, size_t bodyIndex)
				: mLinkNumber(linkNumber)
				, mBodyIndex(bodyIndex)
			{}

			/** Returns the number of the link. This number is used to uniquely identify one link within a specific 
			Physics model. */
			size_t getLinkNumber() const { return mLinkNumber; }

			/** Returns the index of the body in mbodies of PhysicsModel.*/
			size_t getBodyIndex() const { return mBodyIndex; }

			/** Returns the transformation defining the position and orientation of the body, relative to the link.*/
			const TransformationPointerArray& getTransformations() const { return mTransformations; }

			/** Returns the transformation defining the position and orientation of the body, relative to the link.*/
			TransformationPointerArray& getTransformations(){ return mTransformations; }

			/** Creates a clone of the LinkbodyConnection and returns a pointer to it.*/
			LinkBodyConnection* clone() const { return FW_NEW LinkBodyConnection(*this); }

		};

		typedef PointerArray<LinkBodyConnection> LinkBodyConnections;

	private:

		/** The bodies used in the Physics model.*/
		BodyPointerArray mBodies;

		/** List of LinkBodyConnection that define the connection between the links and the bodies. This 
		defines the hierarchy of the Physics model.*/
		LinkBodyConnections mLinkBodyConnections;

		/** Indices of the Physics models base links.*/
		SizeTValuesArray mBaseLinks;
	
	public:

        /** Constructor. */
		PhysicsModel(const UniqueId& uniqueId);

        /** Destructor. */
		virtual ~PhysicsModel();

		/** Returns the bodies used in the Physics model.*/
		const BodyPointerArray& getBodies() const { return mBodies; }

		/** Returns the bodies used in the Physics model.*/
		BodyPointerArray& getBodies() { return mBodies; }

		/** Returns the List of LinkBodyConnection that define the connection between the links and the bodies. This 
		defines the hierarchy of the Physics model.*/
		const LinkBodyConnections& getLinkBodyConnections() const { return mLinkBodyConnections; }

		/** Returns the List of LinkBodyConnection that define the connection between the links and the Bodies. This 
		defines the hierarchy of the Physics model.*/
		LinkBodyConnections& getLinkBodyConnections() { return mLinkBodyConnections; }

		/** Returns the indices of the Physics models base links.*/
		const SizeTValuesArray& getBaseLinks() const { return mBaseLinks; }

		/** Returns the indices of the Physics models base links.*/
		SizeTValuesArray& getBaseLinks(){ return mBaseLinks; }

		/** Creates a clone of the PhysicsModel and returns a pointer to it.*/
		PhysicsModel* clone() const { return FW_NEW PhysicsModel(*this); }

	private:

        /** Disable default copy ctor. */
		PhysicsModel( const PhysicsModel& pre );

        /** Disable default assignment operator. */
		const PhysicsModel& operator= ( const PhysicsModel& pre );

	};

	typedef PointerArray<PhysicsModel> PhysicsModelArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_PHYSICSMODEL_H__
