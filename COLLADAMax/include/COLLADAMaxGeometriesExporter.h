/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_GEOMETRIESEXPORTER_H__
#define __COLLADAMAX_GEOMETRIESEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryGeometries.h"

#include "COLLADAMaxDocumentExporter.h"

namespace COLLADAMax
{

    class ExportSceneGraph;

    class ExportNode;

    /** Class to exports all nodes in an export scene graph.*/

    class GeometriesExporter : public COLLADA::LibraryGeometries
    {

    private:
        /** The export scene graph to export.*/
        ExportSceneGraph * mExportSceneGraph;

        /** The document exporter used to export the document.*/
        DocumentExporter * mDocumentExporter;

        /** Prefix of the symbol names.*/
        static const String SYMBOL_NAME_PREFIX;

    public:
        /** Constructor
        @param streamWriter The stream the animation should be written to
        @param exportSceneGraph The scene graph to export
        @param documentExporter The document exporter this exporter belongs to
        */
        GeometriesExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter );

        /** Exports all geometries in the export scene graph.*/
        void doExport();


    private:
        GeometriesExporter ( const GeometriesExporter & geometriesExporter );
        GeometriesExporter &operator= ( const GeometriesExporter & geometriesExporter );

        friend class GeometryExporter;

        /** Exports all the geometries in @a node and all its child nodes.*/
        void doExport ( ExportNode* exportNode );

    };

}

#endif //__COLLADAMAX_GEOMETRIESEXPORTER_H__




