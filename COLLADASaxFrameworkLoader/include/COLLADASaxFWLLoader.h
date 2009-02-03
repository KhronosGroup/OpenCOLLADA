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
#include "COLLADASaxFWLGeometryMaterialIdInfo.h"

#include "COLLADAFWILoader.h"
#include "COLLADAFWLoaderUtils.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWTypes.h"

#include "COLLADABUHashMap.h"
#include "COLLADABUHashFunctions.h"
#include "COLLADABUURI.h"


namespace COLLADAFW
{
	class IWriter;
}

namespace COLLADASaxFWL
{

	class IErrorHandler;


	/** Loader to a COLLADA document and all the documents that are referenced it.*/
	class Loader : public COLLADAFW::ILoader 
	{
	public:
		/** Maps the unique id of each geometry to the corresponding ColladaSymbolMaterialIdMap.*/
		typedef std::map<COLLADAFW::UniqueId, GeometryMaterialIdInfo> UniqueIdMeshMaterialIdInfoMap;

	private:
		typedef COLLADABU::HashMap<COLLADABU::URI, COLLADAFW::UniqueId, unsigned long, COLLADABU::calculateHash> URIUniqueIdMap;

	private:
		/** Loader utils that will help us to fill the model.*/
		COLLADAFW::LoaderUtils mLoaderUtil;

		/** The writer that will be fed by this loader.*/
		COLLADAFW::IWriter* mWriter;

		/** Maps each already processed dae element to its COLLADAFW::UniqueId. */
		URIUniqueIdMap mURIUniqueIdMap;

		/** Maps the unique id of each geometry to the corresponding GeometryMaterialIdInfo.*/
		UniqueIdMeshMaterialIdInfoMap mGeometryMeshMaterialIdInfoMapMap;

		/** The error handler to pass the errors to.*/
		IErrorHandler* mErrorHandler;
	
	public:

        /** Constructor. */
		Loader(IErrorHandler* errorHandler = 0);

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

		/** Returns the GeometryMaterialIdInfo object of the geometry with @a uniqueId. If this method has 
		not been called before with the same uniqueId, an empty GeometryMaterialIdInfo is created, added to
		the map and returned.*/
		GeometryMaterialIdInfo& getMeshMaterialIdInfo( const COLLADAFW::UniqueId& uniqueId);

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
