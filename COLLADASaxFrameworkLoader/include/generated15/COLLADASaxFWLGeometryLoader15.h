/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_GEOMETRYLOADER15_H__
#define __COLLADASAXFWL_GEOMETRYLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLGeometryLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class GeometryLoader15 : public IParserImpl15
{
private:
GeometryLoader* mLoader;

public:
GeometryLoader15(GeometryLoader* loader)
 : mLoader(loader)
{}


virtual bool begin__mesh();

virtual bool end__geometry();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
GeometryLoader15(const GeometryLoader15&);
/** Disable default assignment operator. */
const GeometryLoader15& operator=(const GeometryLoader15&);
};
}
#endif // __COLLADASAXFWL_GEOMETRYLOADER15_H__
