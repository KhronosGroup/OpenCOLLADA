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
         : mColladaLoader(colladaLoader),
		 mFileURI(fileURI),
		 mLibxmlSaxParse(0),
		 mPartLoader(0)
	{
		mLibxmlSaxParse.changeParser(this);
	}
	
	//-----------------------------
	FileLoader::~FileLoader()
	{
	}

	//-----------------------------
	bool FileLoader::load()
	{
		//GeneratedSaxParser::LibxmlSaxParser libxmlSaxParse(this);
		bool success = mLibxmlSaxParse.parseFile(mFileURI.toNativePath().c_str()); 
		return success;
	}



	//-----------------------------
	bool FileLoader::begin__visual_scene( const visual_scene__AttributeData& attributeData )
	{
		VisualSceneLoader* visualSceneLoader = new VisualSceneLoader(this);
		mPartLoader = visualSceneLoader;
		//mLibxmlSaxParse.changeParser(visualSceneLoader);
		return true;
	}

	//-----------------------------
	void FileLoader::changeParserToMe()
	{
		delete mPartLoader;
		mLibxmlSaxParse.changeParser(this);
	}

} // namespace COLLADASaxFWL
