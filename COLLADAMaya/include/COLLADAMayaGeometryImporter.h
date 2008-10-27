/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_GEOMETRY_IMPORTER_H__
#define __COLLADA_MAYA_GEOMETRY_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"


namespace COLLADAMaya
{

    /** Declares the importer implementation to import the geometries. */
    class GeometryImporter : public BaseImporter
    {

    public:

        /** Constructor. */
        GeometryImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~GeometryImporter () {}

        /** Imports all geometries of the current dae element. */
        void importGeometries ( MObject& transformObject, domNode& node );

    private:

        /** Imports the data of the current geometry element. */
        void importGeometry ( domInstance_geometryRef instanceGeometryRef );

        /** Imports the data of the current mesh element. */
        bool importMesh ( domMeshRef& meshRef );
    };
}

#endif // __COLLADA_MAYA_GEOMETRY_IMPORTER_H__