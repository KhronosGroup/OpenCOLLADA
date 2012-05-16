/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_LOADERUTILS_H__
#define __COLLADAFW_LOADERUTILS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTypes.h"

#include <map>

namespace COLLADAFW
{
	/** This class provides utilities useful for most if the loaders.*/
	class LoaderUtils 	
	{
	private:
		typedef std::map<ClassId, ObjectId> ClassIdObjectIdMap;

		/** Maps each ClassId to the lowest ObjectId, not already used for this type.*/
		ClassIdObjectIdMap mLowestObjectIdMap;
	
	public:
		LoaderUtils();
		virtual ~LoaderUtils();

		/** Returns the lowest, not already used ObjectId for elements with ClassId @a classId and increases the.
		Use this method to create an ObjectId for objects you want to add to the model.*/
		ObjectId getLowestObjectIdFor(ClassId classId);

	private:
        /** Disable default copy ctor. */
		LoaderUtils( const LoaderUtils& pre );
        /** Disable default assignment operator. */
		const LoaderUtils& operator= ( const LoaderUtils& pre );

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_LOADERUTILS_H__
