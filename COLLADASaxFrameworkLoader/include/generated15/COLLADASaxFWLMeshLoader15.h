/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_MESHLOADER15_H__
#define __COLLADASAXFWL_MESHLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLSourceArrayLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class MeshLoader15 : public SourceArrayLoader15
{
private:
MeshLoader* mLoader;

public:
MeshLoader15(MeshLoader* loader)
 : SourceArrayLoader15(loader)
 , mLoader(loader)
{}


virtual bool begin__source( const COLLADASaxFWL15::source__AttributeData& attributeData );

virtual bool end__source();

virtual bool end__mesh();

virtual bool begin__vertices( const COLLADASaxFWL15::vertices__AttributeData& attributeData );

virtual bool end__vertices();

virtual bool begin__input____input_local_type( const COLLADASaxFWL15::input____input_local_type__AttributeData& attributeData );

virtual bool end__input____input_local_type();

virtual bool begin__input____input_local_offset_type( const COLLADASaxFWL15::input____input_local_offset_type__AttributeData& attributeData );

virtual bool end__input____input_local_offset_type();

virtual bool begin__ph();

virtual bool end__ph();

virtual bool begin__p();

virtual bool end__p();

virtual bool data__p( const uint64* data, size_t length );

virtual bool begin__vcount();

virtual bool end__vcount();

virtual bool data__vcount( const uint64* data, size_t length );

virtual bool begin__h();

virtual bool end__h();

virtual bool data__h( const uint64* data, size_t length );

virtual bool begin__triangles( const COLLADASaxFWL15::triangles__AttributeData& attributeData );

virtual bool end__triangles();

virtual bool begin__tristrips( const COLLADASaxFWL15::tristrips__AttributeData& attributeData );

virtual bool end__tristrips();

virtual bool begin__trifans( const COLLADASaxFWL15::trifans__AttributeData& attributeData );

virtual bool end__trifans();

virtual bool begin__polygons( const COLLADASaxFWL15::polygons__AttributeData& attributeData );

virtual bool end__polygons();

virtual bool begin__polylist( const COLLADASaxFWL15::polylist__AttributeData& attributeData );

virtual bool end__polylist();

virtual bool begin__lines( const COLLADASaxFWL15::lines__AttributeData& attributeData );

virtual bool end__lines();

virtual bool begin__linestrips( const COLLADASaxFWL15::linestrips__AttributeData& attributeData );

virtual bool end__linestrips();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
MeshLoader15(const MeshLoader15&);
/** Disable default assignment operator. */
const MeshLoader15& operator=(const MeshLoader15&);
};
}
#endif // __COLLADASAXFWL_MESHLOADER15_H__
