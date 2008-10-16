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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentImporter.h"
#include "COLLADAMayaReferenceManager.h"

#include "COLLADAURI.h"

namespace COLLADAMaya
{
    
    //---------------------------------------------------------------
    DocumentImporter::DocumentImporter ( const String& fileName )
        : mFileName ( fileName )
        , mGeometryImporter ( NULL )
        , mVisualSceneImporter ( NULL )
        , mSceneId ( "MayaScene" )
    {
    }

    //---------------------------------------------------------------
    DocumentImporter::~DocumentImporter()
    {
        releaseLibraries(); 
    }

    //---------------------------------------------------------------
    void DocumentImporter::createLibraries()
    {
        releaseLibraries();

        // Get the sceneID (assign a name to the scene)
        MString sceneName;
        MGlobal::executeCommand ( MString ( "file -q -ns" ), sceneName );
        if ( sceneName.length() != 0 ) mSceneId = sceneName.asChar();

        // Initialize the reference manager
        ReferenceManager::getInstance()->initialize ();

        // Create the basic elements
        mGeometryImporter = new GeometryImporter ();
        mVisualSceneImporter = new VisualSceneImporter ();
    }

    //---------------------------------------------------------------
    void DocumentImporter::releaseLibraries()
    {
        delete mGeometryImporter;
        delete mVisualSceneImporter;
    }

    //-----------------------------
    void DocumentImporter::importCurrentScene()
    {
        // Create the import/export library helpers.
        createLibraries();

        DAE dae;
        String fileUriString = COLLADA::URI::nativePathToUri( getFilename() );
        domCOLLADA* colladaDocument = dae.open ( fileUriString );

        domLibrary_visual_scenes_Array visualScenesArray = colladaDocument->getLibrary_visual_scenes_array();

        size_t numOfScenes = visualScenesArray.getCount();
        for ( size_t scenePos=0; scenePos<numOfScenes; ++scenePos )
        {
            domLibrary_visual_scenesRef vsRef = visualScenesArray.get ( scenePos );
            const domVisual_scene_Array vs = vsRef->getVisual_scene_array();
            for ( size_t j=0; j<vs.getCount(); ++j )
            {
            }
        }

    }

    //---------------------------------
    const String& DocumentImporter::getFilename() const
    {
        return mFileName;
    }

    //---------------------------------
    GeometryImporter* DocumentImporter::getGeometryImporter()
    {
        return mGeometryImporter;
    }

    //---------------------------------
    VisualSceneImporter* DocumentImporter::getVisualSceneImporter()
    {
        return mVisualSceneImporter;
    }


}