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

#ifndef __COLLADA_MAYA_DOCUMENT_IMPORTER_H__
#define __COLLADA_MAYA_DOCUMENT_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaGeometryImporter.h"
#include "COLLADAMayaVisualSceneImporter.h"

#include <DAE.h>
#include <dom/domCOLLADA.h>
#include <dom/domElements.h>



namespace COLLADAMaya
{

    class GeometryImporter;
    class VisualSceneImporter;


    /** The main importer class. This class imports all data of the scene. */
    class DocumentImporter
    {

    private:

        /** Imports the geometry. */
        GeometryImporter* mGeometryImporter;

        /** Imports the visual scene. */
        VisualSceneImporter* mVisualSceneImporter;

        /** The name of the collada file. */
        String mFileName;

        /** The id of the current scene. */
        String mSceneId;

    public:

        /** Constructor. */
        DocumentImporter ( const String& fileName );

        /** Destructor. */
        virtual ~DocumentImporter ();

        /** Imports the current scene. */
        void importCurrentScene();

        /**
        * Returns the name of the current collada file to export.
        * @return const String& Name of the current collada file
        */
        const String& getFilename() const;

        /**
        * Returns a pointer to the geometry exporter.
        * @return GeometryImporter* Pointer to the geometry exporter
        */
        GeometryImporter* getGeometryImporter();

        /**
        * Returns a pointer to the visual scene exporter.
        * @return MaterialImporter* Pointer to the visual scene exporter
        */
        VisualSceneImporter* getVisualSceneImporter();

    private:

        /** Exports the asset. */
        void exportAsset();

        /** Exports the current scene. */
        void exportScene();

        /** Create the parsing libraries: we want access to the libraries during import/export time. */
        void createLibraries();

        /** Releases the import/export libraries */
        void releaseLibraries();


    };
}

#endif // __COLLADA_MAYA_DOCUMENT_IMPORTER_H__