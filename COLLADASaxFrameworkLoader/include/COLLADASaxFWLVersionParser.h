/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_VERSIONPARSER_H__
#define __COLLADASAXFWL_VERSIONPARSER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLTypes.h"
#include "COLLADASaxFWLColladaParserAutoGen14FunctionMapFactory.h"
#include "COLLADASaxFWLColladaParserAutoGen15FunctionMapFactory.h"

#include "GeneratedSaxParserParser.h"

namespace COLLADASaxFWL14
{
    class ColladaParserAutoGen14Private;
}
namespace COLLADASaxFWL15
{
    class ColladaParserAutoGen15Private;
}

namespace COLLADASaxFWL
{
    class FileLoader;

    /**
     * Starts parsing a file to find out which COLLADA version it uses.
     * Creates appropriate parser and continues with that.
     */
    class VersionParser : public GeneratedSaxParser::Parser
    {
    private:
        /** The function map we use to parse the COLLADA file. It contains only those elements that are required 
        to parse all the objects listed in given flags.*/
        COLLADASaxFWL14::ColladaParserAutoGen14Private::ElementFunctionMap mFunctionMap14;
        COLLADASaxFWL15::ColladaParserAutoGen15Private::ElementFunctionMap mFunctionMap15;

        /** Private Parser for COLLADA 1.4 */
        COLLADASaxFWL14::ColladaParserAutoGen14Private* mPrivateParser14;
        /** Private Parser for COLLADA 1.5 */
        COLLADASaxFWL15::ColladaParserAutoGen15Private* mPrivateParser15;

        /** File loader to use. */
        FileLoader* mFileLoader;
        /** Indicates which parts of the file shall be parsed. */
        int mFlags;
        /** Indicates which parts of the file have already been parsed. */
        int& mParsedFlags;

    public:
        VersionParser(GeneratedSaxParser::IErrorHandler* errorHandler, 
            FileLoader* fileLoader,
            int flags,
            int& parsedFlags);
        virtual ~VersionParser();

        virtual bool elementBegin(const ParserChar* elementName, const ParserAttributes& attributes );

        virtual bool elementEnd(const ParserChar* elementName );

        virtual bool textData(const ParserChar* text, size_t textLength);

		/** Returns the element of the element in level @a level, where the previous element is level 0. 
		If level is invalid, 0 is returned.*/
		StringHash getElementHash( size_t level = 0 )const;

        /**
        * Creates generated parser objects and starts parsing the input file. 
        * Will determine COLLADA version of input file and use appropriate parser.
        */
        bool createAndLaunchParser();
        bool createAndLaunchParser(const char* buffer, int length);

    protected:
        void createFunctionMap14();
        void createFunctionMap15();
        bool parse14( const ParserChar* elementName, const ParserAttributes& attributes );
        bool parse15( const ParserChar* elementName, const ParserAttributes& attributes );
    };
}

#endif // __COLLADASAXFWL_VERSIONPARSER_H__
