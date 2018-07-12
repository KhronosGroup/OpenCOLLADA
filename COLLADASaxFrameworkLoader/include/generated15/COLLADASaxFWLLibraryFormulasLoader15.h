/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYFORMULASLOADER15_H__
#define __COLLADASAXFWL_LIBRARYFORMULASLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryFormulasLoader.h"
#include "COLLADASaxFWLFormulasLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryFormulasLoader15 : public FormulasLoader15
{
private:
LibraryFormulasLoader* mLoader;

public:
LibraryFormulasLoader15(LibraryFormulasLoader* loader)
 : FormulasLoader15(loader)
 , mLoader(loader)
{}


virtual bool end__library_formulas();


private:
/** Disable default copy ctor. */
LibraryFormulasLoader15(const LibraryFormulasLoader15&);
/** Disable default assignment operator. */
const LibraryFormulasLoader15& operator=(const LibraryFormulasLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYFORMULASLOADER15_H__
