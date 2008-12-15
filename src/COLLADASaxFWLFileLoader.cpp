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

#include "COLLADAFWObject.h"


namespace COLLADASaxFWL
{

    //-----------------------------
	FileLoader::FileLoader ( Loader* colladaLoader, const COLLADABU::URI& fileURI)
         : ColladaParserAutoGenPrivate(this),
		 mColladaLoader(colladaLoader),
		 mFileURI(fileURI),
		 mLibxmlSaxParse(this),
		 mPartLoader(0),
		 mDeletePartLoader(false)
	{
	}
	
	//-----------------------------
	FileLoader::~FileLoader()
	{
		deletePartLoader();
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
		deletePartLoader();
		VisualSceneLoader* visualSceneLoader = new VisualSceneLoader(this);
		mPartLoader = visualSceneLoader;
		setCallbackObject(visualSceneLoader);
		return true;
	}

	//-----------------------------
	void FileLoader::setMeAsParser()
	{
		mDeletePartLoader = true;
		setCallbackObject(this);
	}

	void FileLoader::deletePartLoader()
	{
		if ( mDeletePartLoader )
		{
			delete mPartLoader;
			mPartLoader = 0;
			mDeletePartLoader = false;
		}
	}
} // namespace COLLADASaxFWL
