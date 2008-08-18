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


#ifndef __COLLADAMAX_CONTROLLEREXPORTER_H__
#define __COLLADAMAX_CONTROLLEREXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADALibraryControllers.h"


namespace COLLADAMax
{
	class ExportSceneGraph;
	class ExportNode;
	class DocumentExporter;
	class Controller;
	class SkinController;
	class ControllerList;

    /** Base class to export extra tags in max.*/

    class ControllerExporter : public COLLADA::LibraryControllers
    {

    public:

    private:
		ExportSceneGraph* mExportSceneGraph;
		DocumentExporter* mDocumentExporter;

    public:
        /** Constructor
         @param streamWriter the stream the extra tags should be written to.*/
        ControllerExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter  );

        /** Destructor*/
        virtual ~ControllerExporter()
        {}

		/** Exports all the controllers in the export scene graph.*/
		void doExport();

		/** Creates an id for the controller, derived from the node id of @a exportNode and the number @a number*/
		static String getControllerId(const ExportNode& exportNode, size_t number);


    private:

		/** Exports all the controllers in @a node and all its child nodes.*/
		void doExport ( ExportNode* exportNode );

		/** Exports all the controllers in @a controllerList.*/
		void exportControllers(  ExportNode* exportNode );

		/** Exports @a controller.*/
		void exportController( ExportNode* exportNode, Controller* controller, const String& controllerId, const String& controllerSource );

		/** Exports @a skinController.*/
		void exportSkinController( ExportNode* exportNode, SkinController* skinController, const String& controllerId, const String& skinSource);

	
	};


}


#endif //__COLLADAMAX_CONTROLLEREXPORTER_H__

