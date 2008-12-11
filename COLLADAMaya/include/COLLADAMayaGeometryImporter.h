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

#include "COLLADAFWMesh.h"


namespace COLLADAMaya
{

    /** Declares the importer implementation to import the geometries. */
    class GeometryImporter : public BaseImporter
    {

    private:

        /** The current transform object, for which the geometries should be created. */
        MObject mTransformObject;

        /** Pointer to the current framework geometry object. */
        const COLLADAFW::Geometry* mGeometry;

    public:

        /** Constructor. */
        GeometryImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~GeometryImporter () {}

        /** Imports the geometry element. */
        bool importGeometry ( const COLLADAFW::Geometry* geometry );

    private:

        /** Imports the data of the current mesh element. */
        bool importMesh ( const COLLADAFW::Mesh* mesh );

        void writeHeader(FILE* file)
        {
            fprintf_s(file,"//Maya ASCII 2008 scene\n");
            fprintf_s(file,"//Name: inMeshTest.ma\n");
            fprintf_s(file,"//Last modified: Mon, Dec 01, 2008 02:02:39 PM\n");
            fprintf_s(file,"//Codeset: 1252\n");
            fprintf_s(file,"requires maya \"2008\";\n");
            fprintf_s(file,"currentUnit -l centimeter -a degree -t film;\n");
            fprintf_s(file,"fileInfo \"application\" \"maya\";\n");
            fprintf_s(file,"fileInfo \"product\" \"Maya Unlimited 2008\";\n");
            fprintf_s(file,"fileInfo \"version\" \"2008\";\n");
            fprintf_s(file,"fileInfo \"cutIdentifier\" \"200708022245-704165\";\n");
            fprintf_s(file,"fileInfo \"osv\" \"Microsoft Windows XP Service Pack 3 (Build 2600)\\n\";\n");
        }


    };

}

#endif // __COLLADA_MAYA_GEOMETRY_IMPORTER_H__