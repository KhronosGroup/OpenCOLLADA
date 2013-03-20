/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_GEOMETRYLOADER14_H__
#define __COLLADASAXFWL_GEOMETRYLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLGeometryLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class GeometryLoader14 : public IParserImpl14
{
private:
GeometryLoader* mLoader;

public:
GeometryLoader14(GeometryLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__mesh();

virtual bool begin__spline( const COLLADASaxFWL14::spline__AttributeData& attributeData );

virtual bool end__geometry();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
GeometryLoader14(const GeometryLoader14&);
/** Disable default assignment operator. */
const GeometryLoader14& operator=(const GeometryLoader14&);
};
}
#endif // __COLLADASAXFWL_GEOMETRYLOADER14_H__
