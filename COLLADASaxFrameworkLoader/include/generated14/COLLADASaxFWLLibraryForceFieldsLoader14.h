/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYFORCEFIELDSLOADER14_H__
#define __COLLADASAXFWL_LIBRARYFORCEFIELDSLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryForceFieldsLoader.h"
#include "COLLADASaxFWLForceFieldLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryForceFieldsLoader14 : public ForceFieldLoader14
{
private:
LibraryForceFieldsLoader* mLoader;

public:
LibraryForceFieldsLoader14(LibraryForceFieldsLoader* loader)
 : ForceFieldLoader14(loader)
 , mLoader(loader)
{}


virtual bool begin__force_field( const COLLADASaxFWL14::force_field__AttributeData& attributeData );

virtual bool end__force_field();

virtual bool end__library_force_fields();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryForceFieldsLoader14(const LibraryForceFieldsLoader14&);
/** Disable default assignment operator. */
const LibraryForceFieldsLoader14& operator=(const LibraryForceFieldsLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYFORCEFIELDSLOADER14_H__
