/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLSaxParserErrorHandler.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADASaxFWLVersionParser.h"
#include "COLLADASaxFWLKinematicsSceneCreator.h"
#include "COLLADASaxFWLFormulasLinker.h"

#include "COLLADAFWConstants.h"
#include "COLLADAFWVisualScene.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWSkinController.h"
#include "COLLADAFWMorphController.h"
#include "COLLADAFWIWriter.h"
#include "COLLADAFWKinematicsScene.h"
#include "COLLADAFWFormulas.h"

#include "COLLADAFWObject.h"

#if defined(GENERATEDSAXPARSER_XMLPARSER_LIBXML)
#	include "GeneratedSaxParserLibxmlSaxParser.h"
#elif defined(GENERATEDSAXPARSER_XMLPARSER_EXPAT)
#	include "GeneratedSaxParserExpatSaxParser.h"
#else
#	error "No prepocesser flag set to chose the xml parser to use"
#endif

#if defined(COLLADABU_OS_WIN)
#pragma warning(disable:4355)
#endif

using namespace COLLADASaxFWL14;

namespace COLLADASaxFWL
{

    //-----------------------------
	FileLoader::FileLoader ( Loader* colladaLoader, 
							 const COLLADABU::URI& fileURI, 
							 SaxParserErrorHandler* saxParserErrorHandler, 
							 int objectFlags,
							 int& parsedObjectFlags, 
                             const ExtraDataCallbackHandlerList& extraDataCallbackHandlerList )
         : DocumentProcessor( colladaLoader, saxParserErrorHandler, objectFlags, parsedObjectFlags )
		 , mFileURI( fileURI )
         , mParsingStatus( PARSING_NOT_STARTED )
		 , mSaxParserErrorHandler(saxParserErrorHandler)
         , mPrivateParser14( 0 )
         , mPrivateParser15( 0 )
         , mXmlSaxParser( 0 )
		 , mVersionParser(0)
	{
        getExtraDataElementHandler ().setExtraDataCallbackHandlerList ( extraDataCallbackHandlerList );
	}

	//-----------------------------
	FileLoader::~FileLoader()
	{
	}

	//-----------------------------
	bool FileLoader::load()
	{
        VersionParser parser( mSaxParserErrorHandler, this, mObjectFlags, mParsedObjectFlags );
		mVersionParser = &parser;
        mParsingStatus = PARSING_PARSING;
        bool success = parser.createAndLaunchParser();
        mParsingStatus = PARSING_FINISHED;
		mVersionParser = 0;
        return success;
	}

	//-----------------------------
	bool FileLoader::load( const char* buffer, int length )
	{
        VersionParser parser( mSaxParserErrorHandler, this, mObjectFlags, mParsedObjectFlags );
		mVersionParser = &parser;
        mParsingStatus = PARSING_PARSING;
        bool success = parser.createAndLaunchParser( buffer, length );
        mParsingStatus = PARSING_FINISHED;
		mVersionParser = 0;
        return success;
	}    

	//-----------------------------
	const COLLADABU::URI& FileLoader::getFileUri()
	{
		return mFileURI;
	}

	//-----------------------------
    void FileLoader::setParser( COLLADASaxFWL14::ColladaParserAutoGen14* parserToBeSet )
	{
		COLLADABU_ASSERT(mPrivateParser14);
        mPrivateParser14->setCallbackObject(parserToBeSet);
	}

    //-----------------------------
    void FileLoader::setParser( COLLADASaxFWL15::ColladaParserAutoGen15* parserToBeSet )
    {
		COLLADABU_ASSERT(mPrivateParser15);
        mPrivateParser15->setCallbackObject(parserToBeSet);
    }

	//-----------------------------
	COLLADASaxFWL14::StringHash FileLoader::getElementHash( size_t level /*= 0 */ ) const 
	{
		if ( mVersionParser )
		{
			return mVersionParser->getElementHash(level);
		}
		return 0;
	}
} // namespace COLLADASaxFWL
