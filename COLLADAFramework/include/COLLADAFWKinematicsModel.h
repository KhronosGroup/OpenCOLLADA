/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_KINEMATICSMODEL_H__
#define __COLLADAFW_KINEMATICSMODEL_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTransformation.h"
#include "COLLADAFWJoint.h"
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

    /** A kinematics model. It describes a kinematics model, using the joints contained in mJoints. The hierarchy 
	of the model is defines by a list of LinkJointConnection that connect the joints to a link. Since links do 
	not have any properties, they are simply described by numbers, starting from 0.  */
	class KinematicsModel : public ObjectTemplate<COLLADA_TYPE::KINEMATICS_MODEL>
	{
	public:
		/** Defines the connection of a joint to a link.*/
		class LinkJointConnection
		{
		private:
			/** The number of the link. This number is used to uniquely identify one link within a specific 
			kinematics model. The base link has always number 0. */
			size_t mLinkNumber;

			/** The index of the joint in mJoints of KinematicsModel.*/
			size_t mJointIndex;

			/** The transformation defining the position and orientation of the joint, relative to the link.*/
			TransformationPointerArray mTransformations;

		public:
			LinkJointConnection( size_t linkNumber, size_t jointIndex)
				: mLinkNumber(linkNumber)
				, mJointIndex(jointIndex)
			{}

			/** Returns the number of the link. This number is used to uniquely identify one link within a specific 
			kinematics model. */
			size_t getLinkNumber() const { return mLinkNumber; }

			/** Returns the index of the joint in mJoints of KinematicsModel.*/
			size_t getJointIndex() const { return mJointIndex; }

			/** Returns the transformation defining the position and orientation of the joint, relative to the link.*/
			const TransformationPointerArray& getTransformations() const { return mTransformations; }

			/** Returns the transformation defining the position and orientation of the joint, relative to the link.*/
			TransformationPointerArray& getTransformations(){ return mTransformations; }

			/** Creates a clone of the LinkJointConnection and returns a pointer to it.*/
			LinkJointConnection* clone() const { return FW_NEW LinkJointConnection(*this); }

		};

		typedef PointerArray<LinkJointConnection> LinkJointConnections;

	private:

		/** The joints used in the kinematics model.*/
		JointPointerArray mJoints;

		/** List of LinkJointConnection that define the connection between the links and the joints. This 
		defines the hierarchy of the kinematics model.*/
		LinkJointConnections mLinkJointConnections;

		/** Indices of the kinematics models base links.*/
		SizeTValuesArray mBaseLinks;
	
	public:

        /** Constructor. */
		KinematicsModel(const UniqueId& uniqueId);

        /** Destructor. */
		virtual ~KinematicsModel();

		/** Returns the joints used in the kinematics model.*/
		const JointPointerArray& getJoints() const { return mJoints; }

		/** Returns the joints used in the kinematics model.*/
		JointPointerArray& getJoints() { return mJoints; }

		/** Returns the List of LinkJointConnection that define the connection between the links and the joints. This 
		defines the hierarchy of the kinematics model.*/
		const LinkJointConnections& getLinkJointConnections() const { return mLinkJointConnections; }

		/** Returns the List of LinkJointConnection that define the connection between the links and the joints. This 
		defines the hierarchy of the kinematics model.*/
		LinkJointConnections& getLinkJointConnections() { return mLinkJointConnections; }

		/** Returns the indices of the kinematics models base links.*/
		const SizeTValuesArray& getBaseLinks() const { return mBaseLinks; }

		/** Returns the indices of the kinematics models base links.*/
		SizeTValuesArray& getBaseLinks(){ return mBaseLinks; }

		/** Creates a clone of the KinematicsModel and returns a pointer to it.*/
		KinematicsModel* clone() const { return FW_NEW KinematicsModel(*this); }

	private:

        /** Disable default copy ctor. */
		KinematicsModel( const KinematicsModel& pre );

        /** Disable default assignment operator. */
		const KinematicsModel& operator= ( const KinematicsModel& pre );

	};

	typedef PointerArray<KinematicsModel> KinematicsModelArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_KINEMATICSMODEL_H__
