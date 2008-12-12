/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_FILEPARTLOADER_H__
#define __COLLADASAXFWL_FILEPARTLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLIFilePartLoader.h"



namespace COLLADASaxFWL
{

    /** Base class for all loader that import only a part of the file */
	class FilePartLoader : public IFilePartLoader
	{
	private:
		IFilePartLoader* mCallingFilePartLoader;
	
	public:

        /** Constructor. */
		FilePartLoader(IFilePartLoader* callingFilePartLoader);

        /** Destructor. */
		virtual ~FilePartLoader();

	public:
		/** Returns a pointer to the collada loader. */
		Loader* getColladaLoader () { return mCallingFilePartLoader->getColladaLoader(); }

		/** Returns a const pointer to the collada document. */
		const Loader* getColladaLoader () const { return mCallingFilePartLoader->getColladaLoader(); }

		/** After this functions, the next sax callback should be caught by this the file part loader.*/
		void changeParserToMe(){assert(false);}

		/** Should be called by a FilePartLoader to indicate that it has finish loading
		the part of the model and cannot handle the next sax callback .*/
		void finish();


	private:

        /** Disable default copy ctor. */
		FilePartLoader( const FilePartLoader& pre );

        /** Disable default assignment operator. */
		const FilePartLoader& operator= ( const FilePartLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_FILEPARTLOADER_H__
