/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_H__
#define __GENERATEDSAXPARSER_H__


// This header includes all headers needed to use this library.
// note: you have to set one of these preprocessor flags:
// - GENERATEDSAXPARSER_XMLPARSER_LIBXML
// - GENERATEDSAXPARSER_XMLPARSER_EXPAT
#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserStackMemoryManager.h"
#include "GeneratedSaxParserTypes.h"
#include "GeneratedSaxParserUtils.h"
#include "GeneratedSaxParserIErrorHandler.h"
#include "GeneratedSaxParserCoutErrorHandler.h"
#include "GeneratedSaxParserIUnknownElementHandler.h"
#include "GeneratedSaxParserINamespaceHandler.h"
#include "GeneratedSaxParserNamespaceStack.h"
#include "GeneratedSaxParserParserError.h"
#include "GeneratedSaxParserParser.h"
#include "GeneratedSaxParserSaxParser.h"
#if defined(GENERATEDSAXPARSER_XMLPARSER_LIBXML)
#include "GeneratedSaxParserLibxmlSaxParser.h"
#elif defined(GENERATEDSAXPARSER_XMLPARSER_EXPAT)
#include "GeneratedSaxParserExpatSaxParser.h"
#endif
#include "GeneratedSaxParserParserTemplateBase.h"
#include "GeneratedSaxParserParserTemplate.h"

#endif // __GENERATEDSAXPARSER_H__
