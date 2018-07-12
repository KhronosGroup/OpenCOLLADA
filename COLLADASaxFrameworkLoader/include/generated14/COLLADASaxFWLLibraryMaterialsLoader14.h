/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYMATERIALSLOADER14_H__
#define __COLLADASAXFWL_LIBRARYMATERIALSLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryMaterialsLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryMaterialsLoader14 : public IParserImpl14
{
private:
LibraryMaterialsLoader* mLoader;

public:
LibraryMaterialsLoader14(LibraryMaterialsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_materials();

virtual bool begin__material( const COLLADASaxFWL14::material__AttributeData& attributeData );

virtual bool end__material();

virtual bool begin__instance_effect( const COLLADASaxFWL14::instance_effect__AttributeData& attributeData );

virtual bool end__instance_effect();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryMaterialsLoader14(const LibraryMaterialsLoader14&);
/** Disable default assignment operator. */
const LibraryMaterialsLoader14& operator=(const LibraryMaterialsLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYMATERIALSLOADER14_H__
