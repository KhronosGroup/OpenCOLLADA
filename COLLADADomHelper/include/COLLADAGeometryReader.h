/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_GEOMETRY_READER_H__
#define __COLLADA_GEOMETRY_READER_H__

#include "HelperPrerequisites.h"
#include "COLLADAReader.h"


namespace COLLADADomHelper
{

    /** Reads the geometry of the dom and creates a COLLADAFW::Geometry object. */
    class GeometryReader : Reader
    {

    private:

        /** A pointer to the current geometry instance to import. */
        domGeometryRef mGeometryRef;

    public:

        /** Constructor. */
        GeometryReader ( daeDocument* daeDoc ) : Reader ( *daeDoc ) {}

        /** Destructor. */
        virtual ~GeometryReader () {}

        /** Imports the data of the current geometry element. */
        void importGeometry ( domInstance_geometryRef instanceGeometryRef );

    };
}

#endif // __COLLADA_GEOMETRY_READER_H__