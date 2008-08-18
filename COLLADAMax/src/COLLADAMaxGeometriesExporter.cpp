/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAStreamWriter.h"
#include "COLLADASource.h"
#include "COLLADABaseInputElement.h"
#include "COLLADAPrimitves.h"
#include "COLLADAUtils.h"

#include "COLLADAMaxGeometriesExporter.h"
#include "COLLADAMaxGeometryExporter.h"
#include "COLLADAMaxMaterialExporter.h"
#include "COLLADAMaxExportSceneGraph.h"



namespace COLLADAMax
{


    typedef std::vector<size_t> MaterialIDList;



    //---------------------------------------------------------------
    GeometriesExporter::GeometriesExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADA::LibraryGeometries ( streamWriter ),
            mExportSceneGraph ( exportSceneGraph ),
            mDocumentExporter ( documentExporter )
    {}


    //---------------------------------------------------------------
    void GeometriesExporter::doExport()
    {
        doExport ( mExportSceneGraph->getRootExportNode() );
        closeLibrary();
    }



    //---------------------------------------------------------------
    void GeometriesExporter::doExport ( ExportNode* exportNode )
    {
        GeometryExporter geometryExporter ( exportNode, this, mDocumentExporter );

        geometryExporter.doExport();


        //export the geometries of the child nodes
        size_t numberOfChildren = exportNode->getNumberOfChildren();

        for ( size_t i = 0; i < numberOfChildren; ++i )
            doExport ( exportNode->getChild ( i ) );

    }


	//---------------------------------------------------------------
	COLLADA::String GeometriesExporter::getGeometryId( const ExportNode& exportNode )
	{
		return COLLADA::LibraryGeometries::GEOMETRY_ID_PRAEFIX + exportNode.getId() ;
	}



}
