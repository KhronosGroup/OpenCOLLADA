/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYCONTROLLERSLOADER14_H__
#define __COLLADASAXFWL_LIBRARYCONTROLLERSLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryControllersLoader.h"
#include "COLLADASaxFWLSourceArrayLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryControllersLoader14 : public SourceArrayLoader14
{
private:
LibraryControllersLoader* mLoader;

public:
LibraryControllersLoader14(LibraryControllersLoader* loader)
 : SourceArrayLoader14(loader)
 , mLoader(loader)
{}


virtual bool end__library_controllers();

virtual bool begin__controller( const COLLADASaxFWL14::controller__AttributeData& attributeData );

virtual bool end__controller();

virtual bool begin__skin( const COLLADASaxFWL14::skin__AttributeData& attributeData );

virtual bool end__skin();

virtual bool begin__morph( const COLLADASaxFWL14::morph__AttributeData& attributeData );

virtual bool end__morph();

virtual bool begin__source( const COLLADASaxFWL14::source__AttributeData& attributeData );

virtual bool end__source();

virtual bool begin__joints();

virtual bool end__joints();

virtual bool begin__input____InputLocal( const COLLADASaxFWL14::input____InputLocal__AttributeData& attributeData );

virtual bool end__input____InputLocal();

virtual bool begin__input____InputLocalOffset( const COLLADASaxFWL14::input____InputLocalOffset__AttributeData& attributeData );

virtual bool end__input____InputLocalOffset();

virtual bool begin__vertex_weights( const COLLADASaxFWL14::vertex_weights__AttributeData& attributeData );

virtual bool end__vertex_weights();

virtual bool begin__vcount();

virtual bool end__vcount();

virtual bool data__vcount( const uint64* data, size_t length );

virtual bool begin__v();

virtual bool end__v();

virtual bool data__v( const sint64* data, size_t length );

virtual bool begin__Name_array( const COLLADASaxFWL14::Name_array__AttributeData& attributeData );

virtual bool end__Name_array();

virtual bool data__Name_array( const ParserString* data, size_t length );

virtual bool begin__IDREF_array( const COLLADASaxFWL14::IDREF_array__AttributeData& attributeData );

virtual bool end__IDREF_array();

virtual bool data__IDREF_array( const ParserString* data, size_t length );

virtual bool begin__bind_shape_matrix();

virtual bool end__bind_shape_matrix();

virtual bool data__bind_shape_matrix( const float* data, size_t length );

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryControllersLoader14(const LibraryControllersLoader14&);
/** Disable default assignment operator. */
const LibraryControllersLoader14& operator=(const LibraryControllersLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYCONTROLLERSLOADER14_H__
