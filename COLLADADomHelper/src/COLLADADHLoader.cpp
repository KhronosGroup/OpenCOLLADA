/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADADomHelper.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADADHStableHeaders.h"
#include "COLLADADHLoader.h"
#include "COLLADADHVisualSceneLoader.h"
#include "COLLADADHGeometryLoader.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWIWriter.h"

namespace COLLADADH
{
	//---------------------------------
	Loader::Loader()
	{
	}

    //---------------------------------
	Loader::~Loader()
	{
	}

    //---------------------------------
	bool Loader::loadDocument( const String& fileName, COLLADAFW::IWriter* writer )
	{
		if ( !writer )
			return false;

		mWriter = writer;

		mDomCollada = mDae.open ( fileName );

		if ( !mDomCollada )
			return false;

		daeDocument* daeDoc = mDomCollada->getDocument();

		if ( !loadVisualScenes() )
			return false;

        if ( !loadGeometries() )
            return false;

		return true;
	}

    //---------------------------------
	bool Loader::loadVisualScenes()
	{
		const domCOLLADA::domSceneRef colladaScene = mDomCollada->getScene();
		if ( !colladaScene )
			return true;

		const domInstanceWithExtraRef colladaInstanceVisualScene = colladaScene->getInstance_visual_scene();
		if ( !colladaInstanceVisualScene )
			return true;

		domVisual_sceneRef colladaVisualScene = daeSafeCast<domVisual_scene>(colladaInstanceVisualScene->getUrl().getElement());
		if ( !colladaVisualScene )
			return true;

		VisualSceneLoader visualSceneLoader(this, colladaVisualScene);
		COLLADAFW::VisualScene* visualScene = visualSceneLoader.load();
		if ( visualScene )
		{
			mWriter->writeVisualScene(visualScene);
			delete visualScene;
		}

		return true;
	}

    //---------------------------------
    bool Loader::loadGeometries ()
    {
        // Get all elements <library_geometries>
        domLibrary_geometries_Array domLibGeosArray = mDomCollada->getLibrary_geometries_array ();
        size_t numLibGeos = domLibGeosArray.getCount ();
        for ( size_t j=0; j<numLibGeos; ++j )
        {
            domLibrary_geometriesRef domLibGeosRef = domLibGeosArray.get ( j );

            // Get all elements <geometry>
            domGeometry_Array domGeoArray = domLibGeosRef->getGeometry_array ();
            size_t numGeos = domGeoArray.getCount ();
            for ( size_t k=0; k<numGeos; ++k )
            {
                domGeometryRef domGeoRef = domGeoArray.get ( k );

                // Load the geometry into the COLLADAFramework geometry object.
                GeometryLoader geometryLoader ( mDomCollada->getDocument () );
                COLLADAFW::Geometry* geometry = geometryLoader.loadGeometry ( domGeoRef );

                // If we have found a geometry, write it into the destination file.
                if ( geometry )
                {
                    mWriter->writeGeometry ( geometry );
                    delete geometry;
                }
            }
        }

        return true;
    }

} // namespace COLLADA
