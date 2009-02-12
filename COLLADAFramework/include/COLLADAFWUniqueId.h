/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_UNIQUEID_H__
#define __COLLADAFW_UNIQUEID_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTypes.h"


namespace COLLADAFW
{
	/** Class that uniquely identifies each object in the model. It consists of a ClassId that uniquely identifies
	the class an object is instantiated from and of an ObjectId that uniquely identifies the object in the set
	of all objects of the same Type.*/
	class UniqueId 	
	{
	public:
		/** An invalid UniqueId.*/
		static const UniqueId INVALID;

	private:
		/** The class id of the class the object is instantiated from.*/
		ClassId mClassId;

		/** The object id that uniquely identifies the object in the set of all objects of the same Type.*/
		ObjectId mObjectId;


	public:
		/** Default constructor. Creates a UniqueId with ClassId COLALDA_TYPES::No_TYPE, which is an invalid ClassId.
		Therefore the UniqueId is considered to be invalid.*/
		UniqueId() : mClassId(COLLADA_TYPE::NO_TYPE), mObjectId(0){}

		/** Constructor. Creates UniqueId with ClassId @a classId an ObjectId @a objectId.*/
		UniqueId(ClassId classId, ObjectId objectId) : mClassId(classId), mObjectId(objectId){}
		virtual ~UniqueId();

		/** Returns the class id of the class the object is instantiated from.*/
		ClassId getClassId() const { return mClassId; }

		/** Returns the object id that uniquely identifies the object in the set of all objects of the same Type.*/
		ObjectId getObjectId() const { return mObjectId; }

		/** Returns true if the unique id is valid, false otherwise.*/
		bool isValid() const { return mClassId != COLLADA_TYPE::NO_TYPE; }

		bool operator<(const UniqueId& rhs) const;

        bool operator==(const UniqueId& uid) const;

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_UNIQUEID_H__
