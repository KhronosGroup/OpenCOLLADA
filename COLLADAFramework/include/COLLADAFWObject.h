/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License,
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_OBJECT_H__
#define __COLLADAFW_OBJECT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAFW
{


	/** Base class of all classes that can be referenced in the model.*/
	class Object
	{
	public:
		virtual ~Object(){};

		/** Returns the class id of the object.*/
		virtual ClassId getClassId() const =0;

		/** Returns the unique id of the object.*/
		virtual const UniqueId& getUniqueId() const = 0;

	};


	/** Base class of all classes that can be referenced in the model.*/
	template<ClassId classId>
	class ObjectTemplate : public Object
	{
	private:
		/** The unique id of the object.*/
		UniqueId mUniqueId;

	public:
		ObjectTemplate(ObjectId objectId, FileId fileId) : mUniqueId(classId, objectId, fileId) {}

		ObjectTemplate(const UniqueId& uniqueId) : mUniqueId(uniqueId) {}

		virtual ~ObjectTemplate() {}

		/** Returns the unique id of the object.*/
		const UniqueId& getUniqueId() const { return mUniqueId; }

		/** Returns the class id of the object.*/
		static ClassId ID() { return classId; }

		/** Returns the class id of the object.*/
		ClassId getClassId() const { return ID(); }

		/** Returns the object id of the object.*/
		ObjectId getObjectId() const { return mUniqueId.getObjectId(); }

		/** Returns the file id of the object.*/
		FileId getFileId() const { return mUniqueId.getFileId(); }

	protected:

        /** Sets the unique id of the object.*/
		void setUniqueId ( const UniqueId& uniqueId )
		{ 
			COLLADABU_ASSERT( uniqueId.getClassId() == classId ); 
			mUniqueId = uniqueId; 
		}


	};


	template<class ObjectType>
	ObjectType* objectSafeCast(Object* object)
	{
		if ( !object)
			return 0;

		if ( object->getClassId() == ObjectType::ID() )
			return (ObjectType*)object;
		else
			return 0;
	}

	template<class ObjectType>
	const ObjectType* objectSafeCast(const Object* object)
	{
		if ( !object)
			return 0;

		if ( object->getClassId() == ObjectType::ID() )
			return (ObjectType*)object;
		else
			return 0;
	}


} // namespace COLLADAFW

#endif // __COLLADAFW_OBJECT_H__
