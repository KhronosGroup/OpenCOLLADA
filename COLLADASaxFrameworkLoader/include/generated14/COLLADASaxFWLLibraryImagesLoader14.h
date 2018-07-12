/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYIMAGESLOADER14_H__
#define __COLLADASAXFWL_LIBRARYIMAGESLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryImagesLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryImagesLoader14 : public IParserImpl14
{
private:
LibraryImagesLoader* mLoader;

public:
LibraryImagesLoader14(LibraryImagesLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_images();

virtual bool begin__image( const COLLADASaxFWL14::image__AttributeData& attributeData );

virtual bool end__image();

virtual bool begin__init_from____anyURI();

virtual bool end__init_from____anyURI();

virtual bool data__init_from____anyURI( COLLADABU::URI value );

virtual bool begin__data();

virtual bool end__data();

virtual bool data__data( const uint8* data, size_t length );

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryImagesLoader14(const LibraryImagesLoader14&);
/** Disable default assignment operator. */
const LibraryImagesLoader14& operator=(const LibraryImagesLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYIMAGESLOADER14_H__
