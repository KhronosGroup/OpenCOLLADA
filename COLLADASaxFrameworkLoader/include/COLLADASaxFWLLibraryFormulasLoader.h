/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYFORMULASLOADER_H__
#define __COLLADASAXFWL_LIBRARYFORMULASLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLFormulasLoader.h"
#include "COLLADASaxFWLXmlTypes.h"


namespace COLLADASaxFWL
{

	/** Loads formulas in a library formulas. */
	class LibraryFormulasLoader : public FilePartLoader, public FormulasLoader
	{
    public:

        /** Constructor. */
		LibraryFormulasLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryFormulasLoader();

		/** Finishes loading a library formulas.*/
		virtual bool end__library_formulas();

    private:

        /** Disable default copy ctor. */
		LibraryFormulasLoader( const LibraryFormulasLoader& pre );

        /** Disable default assignment operator. */
		const LibraryFormulasLoader& operator= ( const LibraryFormulasLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYFORMULASLOADER_H__
