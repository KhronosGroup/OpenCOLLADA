/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
		Loader* getColladaLoader();

		/** Returns a const pointer to the collada document. */
		const Loader* getColladaLoader() const;

		/** Returns a pointer to the file loader. */
		FileLoader* getFileLoader();

		/** Returns a pointer to the file loader. */
		const FileLoader* getFileLoader() const;

		/** A combination of ObjectFlags, indicating which objects should be parsed during the 
		parse process.*/
		int getObjectFlags() const;


        /** Sets the parser to @a parserToBeSet.*/
        virtual void setParser( COLLADASaxFWL14::ColladaParserAutoGen14* parserToBeSet );
        /** Sets the parser to @a parserToBeSet.*/
        virtual void setParser( COLLADASaxFWL15::ColladaParserAutoGen15* parserToBeSet );



		/** Should be called by a FilePartLoader to indicate that it has finish loading
		the part of the model and cannot handle the next sax callback .*/
		void finish();

		/** Returns the absolute uri of the currently parsed file*/
		const COLLADABU::URI& getFileUri();



	private:

        /** Disable default copy ctor. */
		FilePartLoader( const FilePartLoader& pre );

        /** Disable default assignment operator. */
		const FilePartLoader& operator= ( const FilePartLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_FILEPARTLOADER_H__
