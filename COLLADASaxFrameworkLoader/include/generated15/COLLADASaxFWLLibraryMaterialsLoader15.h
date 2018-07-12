/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYMATERIALSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYMATERIALSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryMaterialsLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryMaterialsLoader15 : public IParserImpl15
{
private:
LibraryMaterialsLoader* mLoader;

public:
LibraryMaterialsLoader15(LibraryMaterialsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_materials();

virtual bool begin__material( const COLLADASaxFWL15::material__AttributeData& attributeData );

virtual bool end__material();

virtual bool begin__instance_effect( const COLLADASaxFWL15::instance_effect__AttributeData& attributeData );

virtual bool end__instance_effect();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryMaterialsLoader15(const LibraryMaterialsLoader15&);
/** Disable default assignment operator. */
const LibraryMaterialsLoader15& operator=(const LibraryMaterialsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYMATERIALSLOADER15_H__
