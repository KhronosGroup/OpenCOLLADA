/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYANIMATIONSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYANIMATIONSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryAnimationsLoader.h"
#include "COLLADASaxFWLSourceArrayLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryAnimationsLoader15 : public SourceArrayLoader15
{
private:
LibraryAnimationsLoader* mLoader;

public:
LibraryAnimationsLoader15(LibraryAnimationsLoader* loader)
 : SourceArrayLoader15(loader)
 , mLoader(loader)
{}


virtual bool end__library_animations();

virtual bool begin__source( const COLLADASaxFWL15::source__AttributeData& attributeData );

virtual bool end__source();

virtual bool begin__animation( const COLLADASaxFWL15::animation__AttributeData& attributeData );

virtual bool end__animation();

virtual bool begin__sampler( const COLLADASaxFWL15::sampler__AttributeData& attributeData );

virtual bool end__sampler();

virtual bool begin__channel( const COLLADASaxFWL15::channel__AttributeData& attributeData );

virtual bool end__channel();

virtual bool begin__input____input_local_type( const COLLADASaxFWL15::input____input_local_type__AttributeData& attributeData );

virtual bool end__input____input_local_type();

virtual bool begin__Name_array( const COLLADASaxFWL15::Name_array__AttributeData& attributeData );

virtual bool end__Name_array();

virtual bool data__Name_array( const ParserString* data, size_t length );

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryAnimationsLoader15(const LibraryAnimationsLoader15&);
/** Disable default assignment operator. */
const LibraryAnimationsLoader15& operator=(const LibraryAnimationsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYANIMATIONSLOADER15_H__
