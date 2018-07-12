/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYCONTROLLERSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYCONTROLLERSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryControllersLoader.h"
#include "COLLADASaxFWLSourceArrayLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryControllersLoader15 : public SourceArrayLoader15
{
private:
LibraryControllersLoader* mLoader;

public:
LibraryControllersLoader15(LibraryControllersLoader* loader)
 : SourceArrayLoader15(loader)
 , mLoader(loader)
{}


virtual bool end__library_controllers();

virtual bool begin__controller( const COLLADASaxFWL15::controller__AttributeData& attributeData );

virtual bool end__controller();

virtual bool begin__skin( const COLLADASaxFWL15::skin__AttributeData& attributeData );

virtual bool end__skin();

virtual bool begin__morph( const COLLADASaxFWL15::morph__AttributeData& attributeData );

virtual bool end__morph();

virtual bool begin__source( const COLLADASaxFWL15::source__AttributeData& attributeData );

virtual bool end__source();

virtual bool begin__joints();

virtual bool end__joints();

virtual bool begin__input____input_local_type( const COLLADASaxFWL15::input____input_local_type__AttributeData& attributeData );

virtual bool end__input____input_local_type();

virtual bool begin__input____input_local_offset_type( const COLLADASaxFWL15::input____input_local_offset_type__AttributeData& attributeData );

virtual bool end__input____input_local_offset_type();

virtual bool begin__vertex_weights( const COLLADASaxFWL15::vertex_weights__AttributeData& attributeData );

virtual bool end__vertex_weights();

virtual bool begin__vcount();

virtual bool end__vcount();

virtual bool data__vcount( const uint64* data, size_t length );

virtual bool begin__v();

virtual bool end__v();

virtual bool data__v( const sint64* data, size_t length );

virtual bool begin__Name_array( const COLLADASaxFWL15::Name_array__AttributeData& attributeData );

virtual bool end__Name_array();

virtual bool data__Name_array( const ParserString* data, size_t length );

virtual bool begin__IDREF_array( const COLLADASaxFWL15::IDREF_array__AttributeData& attributeData );

virtual bool end__IDREF_array();

virtual bool data__IDREF_array( const ParserString* data, size_t length );

virtual bool begin__bind_shape_matrix();

virtual bool end__bind_shape_matrix();

virtual bool data__bind_shape_matrix( const float* data, size_t length );

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryControllersLoader15(const LibraryControllersLoader15&);
/** Disable default assignment operator. */
const LibraryControllersLoader15& operator=(const LibraryControllersLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYCONTROLLERSLOADER15_H__
