/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYIMAGESLOADER15_H__
#define __COLLADASAXFWL_LIBRARYIMAGESLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryImagesLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryImagesLoader15 : public IParserImpl15
{
private:
LibraryImagesLoader* mLoader;

public:
LibraryImagesLoader15(LibraryImagesLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_images();

virtual bool begin__image____image_type( const COLLADASaxFWL15::image____image_type__AttributeData& attributeData );

virtual bool end__image____image_type();

virtual bool begin__ref____anyURI();

virtual bool end__ref____anyURI();

virtual bool data__ref____anyURI( COLLADABU::URI value );

virtual bool begin__binary__hex( const COLLADASaxFWL15::binary__hex__AttributeData& attributeData );

virtual bool end__binary__hex();

virtual bool data__binary__hex( const uint8* data, size_t length );

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryImagesLoader15(const LibraryImagesLoader15&);
/** Disable default assignment operator. */
const LibraryImagesLoader15& operator=(const LibraryImagesLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYIMAGESLOADER15_H__
