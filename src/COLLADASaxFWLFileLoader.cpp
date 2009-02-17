/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLAssetLoader.h"
#include "COLLADASaxFWLVisualSceneLoader.h"
#include "COLLADASaxFWLLibraryNodesLoader.h"
#include "COLLADASaxFWLLibraryMaterialsLoader.h"
#include "COLLADASaxFWLLibraryEffectsLoader.h"
#include "COLLADASaxFWLLibraryCamerasLoader.h"
#include "COLLADASaxFWLLibraryLightsLoader.h"
#include "COLLADASaxFWLLibraryImagesLoader.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLGeometryLoader.h"
#include "COLLADASaxFWLSaxParserErrorHandler.h"

#include "COLLADAFWObject.h"

#pragma warning(disable:4355)


namespace COLLADASaxFWL
{

    //-----------------------------
	FileLoader::FileLoader ( Loader* colladaLoader, const COLLADABU::URI& fileURI, SaxParserErrorHandler* saxParserErrorHandler)
         : ColladaParserAutoGenPrivate(0, saxParserErrorHandler),
		 mColladaLoader(colladaLoader),
		 mFileURI(fileURI),
		 mLibxmlSaxParse(this)
	{
		setCallbackObject(this);
	}
	
	//-----------------------------
	FileLoader::~FileLoader()
	{
		deleteFilePartLoader();
	}

	//-----------------------------
	bool FileLoader::load()
	{
		bool success = mLibxmlSaxParse.parseFile(mFileURI.toNativePath().c_str()); 
		return success;
	}

    //-----------------------------
    bool FileLoader::begin__COLLADA__asset ()
    {
		deleteFilePartLoader();
        AssetLoader* assetLoader = new AssetLoader(this);
        setPartLoader(assetLoader);
        setParser(assetLoader);
        return true;
    }

    //-----------------------------
	bool FileLoader::begin__visual_scene( const visual_scene__AttributeData& attributeData )
	{
		deleteFilePartLoader();
		VisualSceneLoader* visualSceneLoader = new VisualSceneLoader(this);
		setPartLoader(visualSceneLoader);
		setParser(visualSceneLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__geometry( const geometry__AttributeData& attributeData )
	{
		deleteFilePartLoader();
		GeometryLoader* geometryLoader = new GeometryLoader(this);

		if ( attributeData.name )
			geometryLoader->setGeometryName ((const char *) attributeData.name);
        if ( attributeData.id )
            geometryLoader->setGeometryId ((const char *) attributeData.id);

		setPartLoader(geometryLoader);
		setParser(geometryLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_nodes( const library_nodes__AttributeData& attributeData )
	{
		deleteFilePartLoader();
		LibraryNodesLoader* libraryNodesLoader = new LibraryNodesLoader(this);

		setPartLoader(libraryNodesLoader);
		setParser(libraryNodesLoader);
		return true;
	}

	//-----------------------------
	const COLLADABU::URI& FileLoader::getFileUri()
	{
		return mFileURI;
	}

	//-----------------------------
	void FileLoader::setParser( IFilePartLoader* parserToBeSet )
	{
		setCallbackObject(parserToBeSet);
	}

	//-----------------------------
	bool FileLoader::begin__library_materials( const library_materials__AttributeData& attributeData )
	{
		deleteFilePartLoader();
		LibraryMaterialsLoader* libraryMaterialsLoader = new LibraryMaterialsLoader(this);

		setPartLoader(libraryMaterialsLoader);
		setParser(libraryMaterialsLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_effects( const library_effects__AttributeData& attributeData )
	{
		deleteFilePartLoader();
		LibraryEffectsLoader* libraryEffectsLoader = new LibraryEffectsLoader(this);

		setPartLoader(libraryEffectsLoader);
		setParser(libraryEffectsLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_cameras( const library_cameras__AttributeData& attributeData )
	{
		deleteFilePartLoader();
		LibraryCamerasLoader* libraryCamerasLoader = new LibraryCamerasLoader(this);

		setPartLoader(libraryCamerasLoader);
		setParser(libraryCamerasLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_lights( const library_lights__AttributeData& attributeData )
	{
		deleteFilePartLoader();
		LibraryLightsLoader* libraryLightsLoader = new LibraryLightsLoader(this);

		setPartLoader(libraryLightsLoader);
		setParser(libraryLightsLoader);
		return true;
	}

	//-----------------------------
	bool FileLoader::begin__library_images( const library_images__AttributeData& attributeData )
	{
		deleteFilePartLoader();
		LibraryImagesLoader* libraryImagesLoader = new LibraryImagesLoader(this);

		setPartLoader(libraryImagesLoader);
		setParser(libraryImagesLoader);
		return true;
	}


	//-----------------------------
    bool FileLoader::end__COLLADA ()
    {
        writer ()->finish ();
        return true;
    }

} // namespace COLLADASaxFWL
