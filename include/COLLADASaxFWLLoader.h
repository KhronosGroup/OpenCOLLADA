/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_LOADER_H__
#define __COLLADA_LOADER_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADAFWILoader.h"
#include "COLLADAFWLoaderUtils.h"
#include "COLLADAFWUniqueId.h"

#include "COLLADABUHashMap.h"
#include "COLLADABUHashFunctions.h"

#include "COLLADABUURI.h"


namespace COLLADAFW
{
	class IWriter;
}

namespace COLLADASaxFWL
{
	/** Loader to a COLLADA document and all the documents that are referenced it.*/
	class Loader : public COLLADAFW::ILoader 
	{
	private:
		typedef COLLADABU::HashMap<COLLADABU::URI, COLLADAFW::UniqueId, unsigned long, COLLADABU::calculateHash> URIUniqueIdMap;

	private:
		/** Loader utils that will help us to fill the model.*/
		COLLADAFW::LoaderUtils mLoaderUtil;

		/** The writer that will be fed by this loader.*/
		COLLADAFW::IWriter* mWriter;

		/** Maps each already processed dae element to its COLLADAFW::UniqueId. */
		URIUniqueIdMap mURIUniqueIdMap;
	
	public:

        /** Constructor. */
		Loader();

        /** Destructor. */
		virtual ~Loader();


        /** Starts loading the model and feeds the writer with data.
		@param fileName The name of the fills that should be loaded.
		@param writer The writer that should be fed with data.
		@return True, if loading succeeded, false otherwise.*/
		virtual bool loadDocument(const String& fileName, COLLADAFW::IWriter* writer);

		/** Returns the COLLADAFW::UniqueId of the element with uri @a uri. If the uri has been 
		passed to this method before, the same 	COLLADAFW::UniqueId will be returned, if not, a 
		new one is created.
		@param uri The uri of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& getUniqueId(const COLLADABU::URI& uri, COLLADAFW::ClassId classId);

		/** Returns the COLLADAFW::UniqueId of an element with no uri.  At each call a new 
		COLLADAFW::UniqueId will be created and returned. Use this member for collada elements that
		do not have an id.
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		COLLADAFW::UniqueId getUniqueId(COLLADAFW::ClassId classId);

		/** Returns the writer the data will be written to.*/
		COLLADAFW::IWriter* writer(){ return mWriter; }



	private:

        /** Disable default copy ctor. */
		Loader( const Loader& pre );

        /** Disable default assignment operator. */
		const Loader& operator= ( const Loader& pre );


	};

} // namespace COLLADA

#endif // __COLLADA_LOADER_H__
