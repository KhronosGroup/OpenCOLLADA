/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLRootParser15.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLIExtraDataCallbackHandler.h"

#include "COLLADASaxFWLAssetLoader15.h"
#include "COLLADASaxFWLSceneLoader15.h"
#include "COLLADASaxFWLVisualSceneLoader15.h"
#include "COLLADASaxFWLLibraryNodesLoader15.h"
#include "COLLADASaxFWLLibraryMaterialsLoader15.h"
#include "COLLADASaxFWLLibraryEffectsLoader15.h"
#include "COLLADASaxFWLLibraryCamerasLoader15.h"
#include "COLLADASaxFWLLibraryLightsLoader15.h"
#include "COLLADASaxFWLLibraryImagesLoader15.h"
#include "COLLADASaxFWLLibraryAnimationsLoader15.h"
#include "COLLADASaxFWLLibraryControllersLoader15.h"
#include "COLLADASaxFWLMeshLoader15.h"
#include "COLLADASaxFWLGeometryLoader15.h"
#include "COLLADASaxFWLLibraryFormulasLoader15.h"
#include "COLLADASaxFWLLibraryJointsLoader15.h"
#include "COLLADASaxFWLLibraryKinematicsModelsLoader15.h"
#include "COLLADASaxFWLLibraryArticulatedSystemsLoader15.h"
#include "COLLADASaxFWLLibraryKinematicsScenesLoader15.h"

namespace COLLADASaxFWL
{

	template<class Loader, class Loader15>
	Loader* RootParser15::beginCommon( )
	{
		mFileLoader->deleteFilePartLoader();
		Loader* loader = new Loader(mFileLoader);
		Loader15* loader15 = new Loader15(loader);
		loader->setParserImpl( loader15 );
		mFileLoader->setPartLoader(loader);
		mFileLoader->setParser(loader15);
		return loader;
	}

	template<class Loader, class Loader15>
	Loader* RootParser15::beginCommonWithId( const char * id)
	{
		mFileLoader->deleteFilePartLoader();
		Loader* loader = new Loader(mFileLoader);
		Loader15* loader15 = new Loader15(loader);
		loader->setParserImpl( loader15 );
		mFileLoader->setPartLoader(loader);
		mFileLoader->setParser(loader15);
		mFileLoader->addToSidTree( id, 0);
		return loader;
	}

	template<class Loader, class Loader15>
	Loader* RootParser15::beginCommonCTorWithId(  const char * id )
	{
		mFileLoader->deleteFilePartLoader();
		Loader* loader = new Loader(mFileLoader, id);
		Loader15* loader15 = new Loader15(loader);
		loader->setParserImpl( loader15 );
		mFileLoader->setPartLoader(loader);
		mFileLoader->setParser(loader15);
		mFileLoader->addToSidTree( id, 0);
		return loader;
	}


    //-----------------------------
    RootParser15::RootParser15( FileLoader* fileLoader )
        : mFileLoader ( fileLoader )
    {

    }

    //-----------------------------
    bool RootParser15::begin__asset()
    {
        SaxVirtualFunctionTest15(begin__asset());
		beginCommon<AssetLoader, AssetLoader15>();
        return true;
    }

    //------------------------------
    bool RootParser15::begin__scene()
    {
        SaxVirtualFunctionTest15(begin__scene()); 
		beginCommon<SceneLoader, SceneLoader15>();
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__visual_scene( const COLLADASaxFWL15::visual_scene__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__visual_scene(attributeData));
		beginCommonCTorWithId<VisualSceneLoader, VisualSceneLoader15>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__geometry( const COLLADASaxFWL15::geometry__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__geometry(attributeData));
		GeometryLoader* geometryLoader = beginCommonWithId<GeometryLoader, GeometryLoader15>(attributeData.id);
		if ( attributeData.name )
			geometryLoader->setGeometryName (attributeData.name);
		if ( attributeData.id )
			geometryLoader->setGeometryId (attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__library_nodes( const COLLADASaxFWL15::library_nodes__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__library_nodes(attributeData));
		beginCommonWithId<LibraryNodesLoader, LibraryNodesLoader15>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__library_materials( const COLLADASaxFWL15::library_materials__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__library_materials(attributeData));
		beginCommonWithId<LibraryMaterialsLoader, LibraryMaterialsLoader15>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__library_effects( const COLLADASaxFWL15::library_effects__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__library_effects(attributeData));
		beginCommonWithId<LibraryEffectsLoader, LibraryEffectsLoader15>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__library_cameras( const COLLADASaxFWL15::library_cameras__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__library_cameras(attributeData));
		beginCommonWithId<LibraryCamerasLoader, LibraryCamerasLoader15>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__library_lights( const COLLADASaxFWL15::library_lights__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__library_lights(attributeData));
		beginCommonWithId<LibraryLightsLoader, LibraryLightsLoader15>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__library_images( const COLLADASaxFWL15::library_images__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__library_images(attributeData));
		beginCommonWithId<LibraryImagesLoader, LibraryImagesLoader15>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__library_animations( const COLLADASaxFWL15::library_animations__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__library_animations(attributeData));
		beginCommonWithId<LibraryAnimationsLoader, LibraryAnimationsLoader15>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__library_controllers( const COLLADASaxFWL15::library_controllers__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__library_controllers(attributeData));
		beginCommonWithId<LibraryControllersLoader, LibraryControllersLoader15>(attributeData.id);
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__library_formulas( const COLLADASaxFWL15::library_formulas__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__library_formulas(attributeData));
        beginCommonWithId<LibraryFormulasLoader, LibraryFormulasLoader15>(attributeData.id);
        return true;
    }

	//-----------------------------
	bool RootParser15::begin__library_joints( const COLLADASaxFWL15::library_joints__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest15(begin__library_joints(attributeData));
		beginCommonWithId<LibraryJointsLoader, LibraryJointsLoader15>(attributeData.id);
		return true;
	}

	//-----------------------------
	bool RootParser15::begin__library_kinematics_models( const COLLADASaxFWL15::library_kinematics_models__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest15(begin__library_kinematics_models(attributeData));
		beginCommonWithId<LibraryKinematicsModelsLoader, LibraryKinematicsModelsLoader15>(attributeData.id);
		return true;
	}

	//-----------------------------
	bool RootParser15::begin__library_articulated_systems( const COLLADASaxFWL15::library_articulated_systems__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest15(begin__library_articulated_systems(attributeData));
		beginCommonWithId<LibraryArticulatedSystemsLoader, LibraryArticulatedSystemsLoader15>(attributeData.id);
		return true;
	}

	//-----------------------------
	bool RootParser15::begin__library_kinematics_scenes( const COLLADASaxFWL15::library_kinematics_scenes__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest15(begin__library_kinematics_scenes(attributeData));
		beginCommonWithId<LibraryKinematicsScenesLoader, LibraryKinematicsScenesLoader15>(attributeData.id);
		return true;
	}

	//-----------------------------
    bool RootParser15::end__COLLADA()
    {
        SaxVirtualFunctionTest15(end__COLLADA());
        return true;
    }

    //-----------------------------
    bool RootParser15::begin__technique____technique_type ( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
    {
        SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
        technique__AttributeData attr;
        attr.profile = attributeData.profile;
        return base__begin__technique ( attr, getUniqueId () );
    }

}
