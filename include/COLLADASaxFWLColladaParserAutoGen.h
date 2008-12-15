/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADASaxFrameworkLoader.

Licensed under the MIT Open Source License,
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL_COLLADAPARSERAUTOGEN_H__
#define __COLLADASAXFWL_COLLADAPARSERAUTOGEN_H__


#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"
#include "COLLADASaxFWLColladaParserAutoGenData.h"


namespace COLLADASaxFWL
{


typedef GeneratedSaxParser::StringHash StringHash;
typedef GeneratedSaxParser::ParserChar ParserChar;
typedef GeneratedSaxParser::ParserAttributes ParserAttributes;
typedef GeneratedSaxParser::ParserError ParserError;


class ColladaParserAutoGen 
{
public:

ColladaParserAutoGen( );
virtual ~ColladaParserAutoGen();

public:
	virtual bool begin__node__translate( const node__translate__AttributeData& attributeData ){return true;}
	virtual bool end__node__translate(){return true;}
	virtual bool data__node__translate( const double*, size_t length ){return true;}





private:
/** Disable default copy ctor. */
ColladaParserAutoGen( const ColladaParserAutoGen& pre );
/** Disable default assignment operator. */
const ColladaParserAutoGen& operator= ( const ColladaParserAutoGen& pre );

void initFunctionMap();
void initNameMap();

};

}
#endif
