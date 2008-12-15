/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_IFILEPARTLOADER_H__
#define __COLLADASAXFWL_IFILEPARTLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLColladaParserAutoGen.h"
#include "COLLADAFWUniqueId.h"



namespace COLLADAFW
{
	class IWriter;
}

namespace COLLADABU
{
	class URI;
}

namespace COLLADASaxFWL
{
	class Loader;

    /** Base class for all loaders that load parts of fiels or entire files */
	class IFilePartLoader : protected ColladaParserAutoGen
	{
	public:
	
		/** Returns a pointer to the collada loader. */
		virtual Loader* getColladaLoader () =0;

		/** Returns a const pointer to the collada document. */
		virtual const Loader* getColladaLoader ()const =0;

		/** Returns the writer the data will be written to.*/
		COLLADAFW::IWriter* writer();

		/** Returns the COLLADAFW::UniqueId of the element with uri @a uri. If the uri has been 
		passed to this method before, the same 	COLLADAFW::UniqueId will be returned, if not, a 
		new one is created.
		@param uri The uri of the element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& getUniqueId(const COLLADABU::URI& uri, COLLADAFW::ClassId classId);

		/** After this functions, the next sax callback should be caught by this the file part loader.*/
		virtual void setMeAsParser()=0;


	public:

        /** Constructor. */
		IFilePartLoader();

        /** Destructor. */
		virtual ~IFilePartLoader();

	private:

        /** Disable default copy ctor. */
		IFilePartLoader( const IFilePartLoader& pre );

        /** Disable default assignment operator. */
		const IFilePartLoader& operator= ( const IFilePartLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_IFILEPARTLOADER_H__
