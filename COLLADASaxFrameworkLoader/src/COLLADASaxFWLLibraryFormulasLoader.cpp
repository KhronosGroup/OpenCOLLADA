/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryFormulasLoader.h"


namespace COLLADASaxFWL
{

    //-----------------------------------------------------------------
    LibraryFormulasLoader::LibraryFormulasLoader( IFilePartLoader* callingFilePartLoader )
        : FilePartLoader( callingFilePartLoader )
		, FormulasLoader( )
    {
		FormulasLoader::setHandlingFilePartLoader(this);
    }

    //-----------------------------------------------------------------
    LibraryFormulasLoader::~LibraryFormulasLoader()
    {
    }

    //-----------------------------------------------------------------
    bool LibraryFormulasLoader::end__library_formulas()
    {
        finish();
        return true;
    }


} // namespace COLLADASaxFWL
