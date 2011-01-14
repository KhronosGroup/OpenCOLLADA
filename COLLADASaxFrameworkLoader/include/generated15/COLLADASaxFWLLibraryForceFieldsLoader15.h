/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYFORCEFIELDSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYFORCEFIELDSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryForceFieldsLoader.h"
#include "COLLADASaxFWLForceFieldLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryForceFieldsLoader15 : public ForceFieldLoader15
{
private:
LibraryForceFieldsLoader* mLoader;

public:
LibraryForceFieldsLoader15(LibraryForceFieldsLoader* loader)
 : ForceFieldLoader15(loader)
 , mLoader(loader)
{}


virtual bool begin__force_field( const COLLADASaxFWL15::force_field__AttributeData& attributeData );

virtual bool end__force_field();

virtual bool end__library_force_fields();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryForceFieldsLoader15(const LibraryForceFieldsLoader15&);
/** Disable default assignment operator. */
const LibraryForceFieldsLoader15& operator=(const LibraryForceFieldsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYFORCEFIELDSLOADER15_H__
