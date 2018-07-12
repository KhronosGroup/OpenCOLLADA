/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYANIMATIONSLOADER14_H__
#define __COLLADASAXFWL_LIBRARYANIMATIONSLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryAnimationsLoader.h"
#include "COLLADASaxFWLSourceArrayLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryAnimationsLoader14 : public SourceArrayLoader14
{
private:
LibraryAnimationsLoader* mLoader;

public:
LibraryAnimationsLoader14(LibraryAnimationsLoader* loader)
 : SourceArrayLoader14(loader)
 , mLoader(loader)
{}


virtual bool end__library_animations();

virtual bool begin__source( const COLLADASaxFWL14::source__AttributeData& attributeData );

virtual bool end__source();

virtual bool begin__animation( const COLLADASaxFWL14::animation__AttributeData& attributeData );

virtual bool end__animation();

virtual bool begin__sampler( const COLLADASaxFWL14::sampler__AttributeData& attributeData );

virtual bool end__sampler();

virtual bool begin__channel( const COLLADASaxFWL14::channel__AttributeData& attributeData );

virtual bool end__channel();

virtual bool begin__input____InputLocal( const COLLADASaxFWL14::input____InputLocal__AttributeData& attributeData );

virtual bool end__input____InputLocal();

virtual bool begin__Name_array( const COLLADASaxFWL14::Name_array__AttributeData& attributeData );

virtual bool end__Name_array();

virtual bool data__Name_array( const ParserString* data, size_t length );

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryAnimationsLoader14(const LibraryAnimationsLoader14&);
/** Disable default assignment operator. */
const LibraryAnimationsLoader14& operator=(const LibraryAnimationsLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYANIMATIONSLOADER14_H__
