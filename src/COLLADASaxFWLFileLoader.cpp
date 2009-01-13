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
#include "COLLADASaxFWLVisualSceneLoader.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLGeometryLoader.h"

#include "COLLADAFWObject.h"


namespace COLLADASaxFWL
{

    //-----------------------------
	FileLoader::FileLoader ( Loader* colladaLoader, const COLLADABU::URI& fileURI)
         : ColladaParserAutoGenPrivate(0),
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

		if ( attributeData.id )
			geometryLoader->setGeometryId((const char *) attributeData.id);

		if ( attributeData.name )
			geometryLoader->setGeometryName((const char *) attributeData.name);

		setPartLoader(geometryLoader);
		setParser(geometryLoader);
		return true;
	}


	const COLLADABU::URI& FileLoader::getFileUri()
	{
		return mFileURI;
	}

	void FileLoader::setParser( IFilePartLoader* parserToBeSet )
	{
		setCallbackObject(parserToBeSet);
	}
} // namespace COLLADASaxFWL
