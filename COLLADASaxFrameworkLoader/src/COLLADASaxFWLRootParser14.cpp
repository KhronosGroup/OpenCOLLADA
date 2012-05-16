/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLRootParser14.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLIExtraDataCallbackHandler.h"

#include "COLLADASaxFWLAssetLoader14.h"
#include "COLLADASaxFWLSceneLoader14.h"
#include "COLLADASaxFWLVisualSceneLoader14.h"
#include "COLLADASaxFWLLibraryNodesLoader14.h"
#include "COLLADASaxFWLLibraryMaterialsLoader14.h"
#include "COLLADASaxFWLLibraryEffectsLoader14.h"
#include "COLLADASaxFWLLibraryImagesLoader14.h"
#include "COLLADASaxFWLLibraryCamerasLoader14.h"
#include "COLLADASaxFWLLibraryLightsLoader14.h"
#include "COLLADASaxFWLLibraryAnimationsLoader14.h"
#include "COLLADASaxFWLLibraryControllersLoader14.h"
#include "COLLADASaxFWLMeshLoader14.h"
#include "COLLADASaxFWLGeometryLoader14.h"

namespace COLLADASaxFWL
{

	template<class Loader, class Loader14>
	Loader* RootParser14::beginCommon()
	{
		mFileLoader->deleteFilePartLoader();
		Loader* loader = new Loader(mFileLoader);
		Loader14* loader14 = new Loader14(loader);
		loader->setParserImpl( loader14 );
		mFileLoader->setPartLoader(loader);
		mFileLoader->setParser(loader14);
		return loader;
	}

	template<class Loader, class Loader14>
	Loader* RootParser14::beginCommonWithId( const char * id)
	{
		mFileLoader->deleteFilePartLoader();
		Loader* loader = new Loader(mFileLoader);
		Loader14* loader14 = new Loader14(loader);
		loader->setParserImpl( loader14 );
		mFileLoader->setPartLoader(loader);
		mFileLoader->setParser(loader14);
		mFileLoader->addToSidTree( id, 0);
		return loader;
	}


	template<class Loader, class Loader14>
	Loader* RootParser14::beginCommonCTorWithId(  const char * id )
	{
		mFileLoader->deleteFilePartLoader();
		Loader* loader = new Loader(mFileLoader, id);
		Loader14* loader14 = new Loader14(loader);
		loader->setParserImpl( loader14 );
		mFileLoader->setPartLoader(loader);
		mFileLoader->setParser(loader14);
		mFileLoader->addToSidTree( id, 0);
		return loader;
	}

    //-----------------------------
    RootParser14::RootParser14( FileLoader* fileLoader )
        : mFileLoader ( fileLoader )
    {
    }

    //-----------------------------
    bool RootParser14::begin__asset()
    {
        SaxVirtualFunctionTest14(begin__asset());
		beginCommon<AssetLoader, AssetLoader14>();
        return true;
    }

    //------------------------------
    bool RootParser14::begin__scene()
    {
        SaxVirtualFunctionTest14(begin__scene()); 
		beginCommon<SceneLoader, SceneLoader14>();
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__visual_scene( const COLLADASaxFWL14::visual_scene__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__visual_scene(attributeData));
		beginCommonCTorWithId<VisualSceneLoader, VisualSceneLoader14>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__geometry( const COLLADASaxFWL14::geometry__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__geometry(attributeData));
		GeometryLoader* geometryLoader = beginCommonWithId<GeometryLoader, GeometryLoader14>(attributeData.id);
        if ( attributeData.name )
            geometryLoader->setGeometryName (attributeData.name);
        if ( attributeData.id )
            geometryLoader->setGeometryId (attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__library_nodes( const COLLADASaxFWL14::library_nodes__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__library_nodes(attributeData));
		beginCommonWithId<LibraryNodesLoader, LibraryNodesLoader14>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__library_materials( const COLLADASaxFWL14::library_materials__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__library_materials(attributeData));
		beginCommonWithId<LibraryMaterialsLoader, LibraryMaterialsLoader14>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__library_effects( const COLLADASaxFWL14::library_effects__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__library_effects(attributeData));
		beginCommonWithId<LibraryEffectsLoader, LibraryEffectsLoader14>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__library_cameras( const COLLADASaxFWL14::library_cameras__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__library_cameras(attributeData));
		beginCommonWithId<LibraryCamerasLoader, LibraryCamerasLoader14>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__library_lights( const COLLADASaxFWL14::library_lights__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__library_lights(attributeData));
		beginCommonWithId<LibraryLightsLoader, LibraryLightsLoader14>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__library_images( const COLLADASaxFWL14::library_images__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__library_images(attributeData));
		beginCommonWithId<LibraryImagesLoader, LibraryImagesLoader14>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__library_animations( const COLLADASaxFWL14::library_animations__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__library_animations(attributeData));
		beginCommonWithId<LibraryAnimationsLoader, LibraryAnimationsLoader14>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__library_controllers( const COLLADASaxFWL14::library_controllers__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__library_controllers(attributeData));
		beginCommonWithId<LibraryControllersLoader, LibraryControllersLoader14>(attributeData.id);
		return true;
    }

    //-----------------------------
    bool RootParser14::end__COLLADA()
    {
        SaxVirtualFunctionTest14(end__COLLADA());
        return true;
    }

    //-----------------------------
    bool RootParser14::begin__technique ( const COLLADASaxFWL14::technique__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest14(begin__technique(attributeData));
        technique__AttributeData attr;
        attr.profile = attributeData.profile;
        return base__begin__technique ( attr, getUniqueId () );
    }

}
