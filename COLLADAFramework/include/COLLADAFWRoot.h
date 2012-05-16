/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ROOT_H__
#define __COLLADAFW_ROOT_H__

#include "COLLADAFWPrerequisites.h"



namespace COLLADAFW
{
	class Object;
	class IWriter;
	class ILoader;
	class UniqueId;

	/** The root class of the framework.*/
	class Root 	
	{
	private:
		/** The loader used to load the model.*/
		ILoader* mLoader;

		/** The writer that writes the data.*/
		IWriter* mWriter;
	
	public:
		Root(ILoader* loader, IWriter* writer) : mLoader(loader), mWriter(writer){}
		virtual ~Root();

		/** Loads @a fileName in to the model.
		@returns True, if loading succeeded, false otherwise.*/
		bool loadDocument(const String& fileName);

		/** Loads @a buffer in to the model.
         @returns True, if loading succeeded, false otherwise.*/
		bool loadDocument(const String& uri, const char* buffer, int length);
        
		/** Returns the object with unique id @a uniqueId.
		Only available if we have a pool.*/
		Object* getObject(const UniqueId& uniqueId);


	private:
        /** Disable default copy ctor. */
		Root( const Root& pre );
        /** Disable default assignment operator. */
		const Root& operator= ( const Root& pre );

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_ROOT_H__
