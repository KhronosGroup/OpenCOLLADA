/*
Copyright (c) 2008 NetAllied Systems GmbH

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
	template<ClassId classId>
	class Object 	
	{
	private:
		/** The unique id of the object.*/
		UniqueId mUniqueId;

	public:
		Object(ObjectId objectId) : mUniqueId(classId, objectId){};
		virtual ~Object(){};

		/** Returns the unique id of the object.*/
		const UniqueId& getUniqueId() const { return mUniqueId; }

		/** Returns the class id of the object.*/
		static ClassId getClassId() { return classId; }

		/** Returns the object id of the object.*/
		ObjectId getObjectId() const { return mUniqueId.getObjectId(); }

	private:
        /** Disable default copy ctor. */
		Object( const Object& pre );
        /** Disable default assignment operator. */
		const Object& operator= ( const Object& pre );

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_OBJECT_H__
