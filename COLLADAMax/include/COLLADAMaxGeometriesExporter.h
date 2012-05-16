/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_GEOMETRIESEXPORTER_H__
#define __COLLADAMAX_GEOMETRIESEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryGeometries.h"

#include "COLLADAMaxDocumentExporter.h"

namespace COLLADAMax
{

    class ExportSceneGraph;

    class ExportNode;

    /** Class to exports all nodes in an export scene graph.*/

    class GeometriesExporter : public COLLADASW::LibraryGeometries
    {

	public:
		/** List of material ids.*/
		typedef std::vector<size_t> MaterialIDList;

		/** Maps Objects to material lists.*/
		typedef std::map<Object*, MaterialIDList> ObjectMaterialIDListMap;

    private:
        /** The export scene graph to export.*/
        ExportSceneGraph * mExportSceneGraph;

        /** The document exporter used to export the document.*/
        DocumentExporter * mDocumentExporter;

        /** Prefix of the symbol names.*/
        static const String SYMBOL_NAME_PREFIX;

		/** Maps exported geometry objects to their list of material ids.*/
		GeometriesExporter::ObjectMaterialIDListMap mExportedObjectMaterialIDListMap;

    public:
        /** Constructor
        @param streamWriter The stream the animation should be written to
        @param exportSceneGraph The scene graph to export
        @param documentExporter The document exporter this exporter belongs to
        */
        GeometriesExporter ( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter );

        /** Exports all geometries in the export scene graph.*/
        void doExport();

		/** Creates an id for the geometry, derived from the node id*/
		static String getGeometryId(const ExportNode& exportNode);

    private:
        GeometriesExporter ( const GeometriesExporter & geometriesExporter );
        GeometriesExporter &operator= ( const GeometriesExporter & geometriesExporter );

        friend class GeometryExporter;

        /** Exports all the geometries in @a node and all its child nodes.*/
        void doExport ( ExportNode* exportNode );

		/** Returns the map of exported geometry objects to their list of material ids.*/
		ObjectMaterialIDListMap& getExportedObjectMaterialIDListMap(){return mExportedObjectMaterialIDListMap;}


    };

}

#endif //__COLLADAMAX_GEOMETRIESEXPORTER_H__




