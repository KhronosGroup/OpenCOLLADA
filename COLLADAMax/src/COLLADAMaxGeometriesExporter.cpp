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


#include "COLLADAMaxStableHeaders.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWSource.h"
#include "COLLADASWBaseInputElement.h"
#include "COLLADASWPrimitves.h"

#include "COLLADAMaxGeometriesExporter.h"
#include "COLLADAMaxGeometryExporter.h"
#include "COLLADAMaxMaterialExporter.h"
#include "COLLADAMaxExportSceneGraph.h"



namespace COLLADAMax
{


    typedef std::vector<size_t> MaterialIDList;



    //---------------------------------------------------------------
    GeometriesExporter::GeometriesExporter ( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADASW::LibraryGeometries ( streamWriter ),
            mExportSceneGraph ( exportSceneGraph ),
            mDocumentExporter ( documentExporter )
    {}


    //---------------------------------------------------------------
    void GeometriesExporter::doExport()
    {
        doExport ( mExportSceneGraph->getRootExportNode() );

		const MorphControllerHelperGeometryList& morphControllerHelperGeometryList = mExportSceneGraph->getMorphControllerHelperGeometryList();

		for ( MorphControllerHelperGeometryList::const_iterator it = morphControllerHelperGeometryList.begin(); it != morphControllerHelperGeometryList.end(); ++it)
		{
			const MorphControllerHelperGeometry& morphControllerHelperGeometry = *it;
			GeometryExporter geometryExporter ( &morphControllerHelperGeometry, this, mDocumentExporter );

			geometryExporter.doExport();
		}

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
	COLLADASW::String GeometriesExporter::getGeometryId( const ExportNode& exportNode )
	{
		return COLLADASW::LibraryGeometries::GEOMETRY_ID_PRAEFIX + exportNode.getId() ;
	}



}
