/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLIParserImpl.h"

#include <cassert>


namespace COLLADASaxFWL
{

	FilePartLoader::FilePartLoader( IFilePartLoader* callingFilePartLoader )
		: mCallingFilePartLoader(callingFilePartLoader)
	{
		COLLADABU_ASSERT(callingFilePartLoader);
	}

    //------------------------------
	FilePartLoader::~FilePartLoader()
	{
	}

	//------------------------------
	void FilePartLoader::finish()
	{
		mCallingFilePartLoader->setMeAsParser();
	}

	//------------------------------
	const COLLADABU::URI& FilePartLoader::getFileUri()
	{
		return mCallingFilePartLoader->getFileUri();
	}


    //------------------------------
    void FilePartLoader::setParser( COLLADASaxFWL14::ColladaParserAutoGen14* parserToBeSet )
    {
        mCallingFilePartLoader->setParser(parserToBeSet);
    }

    //------------------------------
    void FilePartLoader::setParser( COLLADASaxFWL15::ColladaParserAutoGen15* parserToBeSet )
    {
        mCallingFilePartLoader->setParser(parserToBeSet);
    }

	//------------------------------
	int FilePartLoader::getObjectFlags() const
	{
		return getFileLoader()->getObjectFlags();
	}

	//------------------------------
	Loader* FilePartLoader::getColladaLoader()
	{
		return mCallingFilePartLoader->getColladaLoader();
	}

	//------------------------------
	const Loader* FilePartLoader::getColladaLoader() const
	{
		return mCallingFilePartLoader->getColladaLoader();
	}

	//------------------------------
	FileLoader* FilePartLoader::getFileLoader()
	{
		return mCallingFilePartLoader->getFileLoader();
	}

	//------------------------------
	const FileLoader* FilePartLoader::getFileLoader() const
	{
		return mCallingFilePartLoader->getFileLoader();
	}

} // namespace COLLADASaxFWL
