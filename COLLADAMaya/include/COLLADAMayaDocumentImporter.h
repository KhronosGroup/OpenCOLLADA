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

#include <DAE.h>
#include <dom/domCOLLADA.h>
#include <dom/domElements.h>

#include "COLLADADHLoader.h"


namespace COLLADAMaya
{

    class MaterialImporter;
    class GeometryImporter;
    class CameraImporter;
    class VisualSceneImporter;


    /** The main importer class. This class imports all data of the scene. */
    class DocumentImporter
    {

    private:

        /** The name of the collada file. */
        String mFileName;

        /** The id of the current scene. */
        String mSceneId;

        /** The DAE class is the core interface via which you interact with the DOM. */
        DAE mDae;

        /** The currently parsed collada document. */
        domCOLLADA* mColladaDoc;

        /** Imports the material. */
        MaterialImporter* mMaterialImporter;

        /** Imports the visual scene. */
        VisualSceneImporter* mVisualSceneImporter;

        /** Imports the geometry. */
        GeometryImporter* mGeometryImporter;

        /** Imports the camera. */
        CameraImporter* mCameraImporter;

        COLLADADH::Loader mLoader;

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

        /** The currently parsed collada document. */
        const domCOLLADA* getColladaDocument () const { return mColladaDoc; }
        domCOLLADA* getColladaDocument () { return mColladaDoc; }

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

        /** Imports the asset. */
        void importAsset();

        /** Imports the current scene. */
        void exportScene();

        /** Parse the current collada file and creates the parsing libraries: 
        we want access to the libraries during import/export time. */
        void createLibraries();

        /** Releases the import/export libraries */
        void releaseLibraries();


    };
}

#endif // __COLLADA_MAYA_DOCUMENT_IMPORTER_H__