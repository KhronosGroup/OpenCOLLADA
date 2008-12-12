/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADADH_FILELOADER_H__
#define __COLLADADH_FILELOADER_H__

#include "COLLADADHPrerequisites.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADABUURI.h"



namespace COLLADABU
{
	class URI;
}

namespace COLLADAFW
{
	class IWriter;
}


namespace COLLADADH
{
	class Loader;

	/** Loader to a COLLADA document. Referenced documents are not loaded.*/
	class FileLoader 	
    {
	private:
	
		/** The collada loader */
		Loader* mColladaLoader;

		/** The uri of the file that should be imported.*/
		COLLADABU::URI mFileURI;

		/** The parent (in the notion of the data model) of the currently parsed element.*/
		COLLADAFW::Object* mObject;

	public:

        /** Constructor.
		@param colladaLoader The collada loader this file loader is being used by. Used to retrieve document 
		global properties.
		@param fileName The name of the file to be loaded.*/
		FileLoader ( Loader* colladaLoader, const COLLADABU::URI& fileURI );

        /** Destructor. */
        virtual ~FileLoader();

	protected:
		/** Returns a pointer to the collada loader. */
		Loader* getColladaLoader () { return mColladaLoader; }

		/** Returns a const pointer to the collada document. */
		const Loader* getColladaLoader () const { return mColladaLoader; }

		/** Returns the writer the data will be written to.*/
		COLLADAFW::IWriter* writer();

		/** Returns the COLLADAFW::UniqueId of the element with uri @a uri. If the uri has been 
		passed to this method before, the same 	COLLADAFW::UniqueId will be returned, if not, a 
		new one is created.
		@param uri The uri of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& getUniqueId(const COLLADABU::URI& uri, COLLADAFW::ClassId classId);

		/** Performs the import.*/
		bool import();



    private:

        /** Disable default copy ctor. */
		FileLoader( const FileLoader& pre );

        /** Disable default assignment operator. */
		const FileLoader& operator= ( const FileLoader& pre );

	};
	
} // namespace COLLADADH

#endif // __COLLADADH_FILELOADER_H__
