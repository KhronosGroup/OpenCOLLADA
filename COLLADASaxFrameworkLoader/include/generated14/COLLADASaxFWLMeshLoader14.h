/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_MESHLOADER14_H__
#define __COLLADASAXFWL_MESHLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLSourceArrayLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class MeshLoader14 : public SourceArrayLoader14
{
private:
MeshLoader* mLoader;

public:
MeshLoader14(MeshLoader* loader)
 : SourceArrayLoader14(loader)
 , mLoader(loader)
{}


virtual bool begin__source( const COLLADASaxFWL14::source__AttributeData& attributeData );

virtual bool end__source();

virtual bool end__mesh();

virtual bool begin__vertices( const COLLADASaxFWL14::vertices__AttributeData& attributeData );

virtual bool end__vertices();

virtual bool begin__input____InputLocal( const COLLADASaxFWL14::input____InputLocal__AttributeData& attributeData );

virtual bool end__input____InputLocal();

virtual bool begin__input____InputLocalOffset( const COLLADASaxFWL14::input____InputLocalOffset__AttributeData& attributeData );

virtual bool end__input____InputLocalOffset();

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

virtual bool begin__triangles( const COLLADASaxFWL14::triangles__AttributeData& attributeData );

virtual bool end__triangles();

virtual bool begin__tristrips( const COLLADASaxFWL14::tristrips__AttributeData& attributeData );

virtual bool end__tristrips();

virtual bool begin__trifans( const COLLADASaxFWL14::trifans__AttributeData& attributeData );

virtual bool end__trifans();

virtual bool begin__polygons( const COLLADASaxFWL14::polygons__AttributeData& attributeData );

virtual bool end__polygons();

virtual bool begin__polylist( const COLLADASaxFWL14::polylist__AttributeData& attributeData );

virtual bool end__polylist();

virtual bool begin__lines( const COLLADASaxFWL14::lines__AttributeData& attributeData );

virtual bool end__lines();

virtual bool begin__linestrips( const COLLADASaxFWL14::linestrips__AttributeData& attributeData );

virtual bool end__linestrips();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
MeshLoader14(const MeshLoader14&);
/** Disable default assignment operator. */
const MeshLoader14& operator=(const MeshLoader14&);
};
}
#endif // __COLLADASAXFWL_MESHLOADER14_H__
