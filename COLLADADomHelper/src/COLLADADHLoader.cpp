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

		DAE dae;
		mDomCollada = dae.open ( fileName );

		if ( !mDomCollada )
			return false;

		daeDocument* daeDoc = mDomCollada->getDocument();

		if ( !loadVisualScenes() )
			return false;

  //      if ( !loadGeometries() )
  //          return false;

		dae.close(fileName);

		return true;
	}

    //---------------------------------
	bool Loader::loadVisualScenes()
	{

		VisualSceneLoader visualSceneLoader(this, mDomCollada);
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
                GeometryLoader geometryLoader ( this, mDomCollada );
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

	const COLLADAFW::UniqueId& Loader::getUniqueId( daeElement* element, COLLADAFW::ClassId classId )
	{
		DEAElementUniqueIdMap::const_iterator it = mDEAElementUniqueIdMap.find(element);
		if ( it == mDEAElementUniqueIdMap.end() )
		{
			return mDEAElementUniqueIdMap[element] = COLLADAFW::UniqueId(classId, mLoaderUtil.getLowestObjectIdFor(classId));
		}
		else
		{
			return it->second;
		}
	}

} // namespace COLLADA
