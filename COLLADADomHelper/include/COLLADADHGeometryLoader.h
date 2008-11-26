/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_GEOMETRY_READER_H__
#define __COLLADA_GEOMETRY_READER_H__

#include "COLLADADHStableHeaders.h"
#include "COLLADADHBaseLoader.h"

#include "COLLADAFWGeometry.h"


namespace COLLADADH
{

    /** Reads the geometry of the dom and creates a COLLADAFW::Geometry object. */
    class GeometryLoader : BaseLoader
    {

    private:

    public:

        /** Constructor. */
        GeometryLoader ( daeDocument* daeDoc ) : BaseLoader ( daeDoc ) {}

        /** Destructor. */
        virtual ~GeometryLoader () {}

        /** Imports the data of the current geometry element. */
        COLLADAFW::Geometry* loadGeometry ( const domGeometryRef domGeoRef );

    };
}

#endif // __COLLADA_GEOMETRY_READER_H__