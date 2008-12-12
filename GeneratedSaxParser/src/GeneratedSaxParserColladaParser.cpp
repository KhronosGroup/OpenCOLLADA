/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "GeneratedSaxParserColladaParser.h"


#include <iostream>


namespace GeneratedSaxParser
{

	ColladaParser::ColladaParser(IErrorHandler* errorHandler)
		: ColladaParserAutoGen(errorHandler),
		  mCount(0)
	{
	}

	ColladaParser::~ColladaParser()
	{
	}

	bool ColladaParser::endTranslate()
	{
		return true;
	}


	bool ColladaParser::endNode()
	{
		return true;
	}

	bool ColladaParser::endCOLLADA()
	{
		std::cout << mCount << std::endl;
		return true;
	}

	bool ColladaParser::endLibraryNodes()
	{
		return true;
	}

	bool ColladaParser::beginTranslate( const TranslateAttributeData& attributeData )
	{
		return true;
	}

	bool ColladaParser::beginNode( const NodeAttributeData& attributeData )
	{
		return true;
	}

	bool ColladaParser::beginCOLLADA( const COLLADAAttributeData& attributeData )
	{
		std::cout << attributeData.version << "\n";
		std::cout << attributeData.xmlns << "\n";
		std::cout << attributeData.number << "\n";
		return true;
	}

	bool ColladaParser::beginLibraryNodes( const LibraryNodesAttributeData& attributeData )
	{
		return true;
	}

	bool ColladaParser::dataTranslate( const int* data, size_t length )
	{
//		for ( size_t i = 0; i<length; ++i)
//			std::cout << data[i] << "\n";

		mCount += length;
		return true;
	}

} // namespace GeneratedSaxParser
