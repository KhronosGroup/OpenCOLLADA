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
	private:
//		Object* mParent;
	public:
		virtual ~Object(){};

		/** Returns the class id of the object.*/
		virtual ClassId getClassId() const =0;

//		Object* getParent() { return mParent; }

	protected:
		Object(Object* parent) /*: mParent(parent)*/{}

//		void setParent(Object* parent) { mParent = parent; }


	private:
		/** Disable default copy ctor. */
//		Object( const Object& pre );
		/** Disable default assignment operator. */
//		const Object& operator= ( const Object& pre );

	};


	/** Base class of all classes that can be referenced in the model.*/
	template<ClassId classId>
	class ObjectTemplate : public Object
	{
	private:
		/** The unique id of the object.*/
		UniqueId mUniqueId;

	public:
		ObjectTemplate(ObjectId objectId, Object* parent = 0) : Object(parent), mUniqueId(classId, objectId){};
		virtual ~ObjectTemplate(){};

		/** Returns the unique id of the object.*/
		const UniqueId& getUniqueId() const { return mUniqueId; }

		/** Returns the class id of the object.*/
		static ClassId ID() { return classId; }

		/** Returns the class id of the object.*/
		ClassId getClassId() const { return ID(); }

		/** Returns the object id of the object.*/
		ObjectId getObjectId() const { return mUniqueId.getObjectId(); }

	private:
        /** Disable default copy ctor. */
	//	ObjectTemplate( const ObjectTemplate& pre );
        /** Disable default assignment operator. */
	//	const ObjectTemplate& operator= ( const ObjectTemplate& pre );

	};


	template<class ObjectType>
	ObjectType* objectSafeCast(Object* object)
	{
		if ( object->getClassId() == ObjectType::ID() )
			return (ObjectType*)object;
		else
			return 0;
	}


} // namespace COLLADAFW

#endif // __COLLADAFW_OBJECT_H__
