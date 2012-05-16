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


#ifndef __COLLADAMAX_XREFEXPORTER_H__
#define __COLLADAMAX_XREFEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"



namespace COLLADAMax
{
	class ExportSceneGraph;
	class ExportNode;
	class DocumentExporter;

    /** Base class to export extra tags in max.*/

    class XRefExporter : public COLLADASW::LibraryControllers
    {

    public:

    private:
		ExportSceneGraph* mExportSceneGraph;
		DocumentExporter* mDocumentExporter;

    public:
        /** Constructor
         @param streamWriter the stream the extra tags should be written to.*/
        XRefExporter ( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter  );

        /** Destructor*/
        virtual ~XRefExporter()
        {}

		/** Exports all the controllers in the export scene graph.*/
		void doExport();


    private:

		/** Exports all the controllers in @a node and all its child nodes.*/
		void doExport ( ExportNode* exportNode );
	};


}


#endif //__COLLADAMAX_XREFEXPORTER_H__

