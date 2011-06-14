/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_FILELOADER_H__
#define __COLLADASAXFWL_FILELOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLDocumentProcessor.h"

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
	class SidTreeNode;
	class SidAddress;
	class FilePartLoader;
    class VersionParser;

	/** Loader to a COLLADA document. Referenced documents are not loaded.*/
	class FileLoader : public DocumentProcessor
    {
	public:
		enum ParsingStatus
		{
			PARSING_NOT_STARTED,        //!< Parsing of the .dae file has not been started
			PARSING_PARSING,            //!< The .dae file is being parsed
			PARSING_FINISHED            //!< Parsing of the .dae file has been finished
		};

	private:
		/** The uri of the file that should be imported.*/
		COLLADABU::URI mFileURI;

		/** Parsing status of the FileLoader.*/
		ParsingStatus mParsingStatus;

        /** Error handler to be used. */
        SaxParserErrorHandler* mSaxParserErrorHandler;

        /** Generated private parser for COLLADA 1.4. */
        COLLADASaxFWL14::ColladaParserAutoGen14Private* mPrivateParser14;
        /** Generated private parser for COLLADA 1.5. */
        COLLADASaxFWL15::ColladaParserAutoGen15Private* mPrivateParser15;

        /** Parser object which knows line and column numbers in parsed file. */
        GeneratedSaxParser::SaxParser* mXmlSaxParser;

		/** The currently active version parser or 0 if none is activ.*/
		VersionParser* mVersionParser;

    public:

        /** Constructor.
		@param colladaLoader The collada loader this file loader is being used by. Used to retrieve document 
		global properties.
		@param fileURI The name of the file to be loaded.
		@param saxParserErrorHandler The error handler all sax parser errors should be passed to.
		@param objectFlags Flags (Loader::ObjectFlags) of objects that should be parsed. Set these 
		if you don't want to parse the entire file, but only those parts required to create the objects in 
		objectFlags.
		@param parsedObjectFlags Flags (Loader::ObjectFlags) of objects already parsed by @a colladaLoader. 
		Will be set to all objects parsed after a call of load().*/
		FileLoader ( Loader* colladaLoader, 
			         const COLLADABU::URI& fileURI, 
					 SaxParserErrorHandler* saxParserErrorHandler, 
					 int objectFlags,
					 int& /*[in,out]*/ parsedObjectFlags, 
                     const ExtraDataCallbackHandlerList& extraDataCallbackHandlerList );
 
        /** Destructor. */
        virtual ~FileLoader();

		/** Sets the parser to @a parserToBeSet.*/
        void setParser( COLLADASaxFWL14::ColladaParserAutoGen14* parserToBeSet );
        /** Sets the parser to @a parserToBeSet.*/
        void setParser( COLLADASaxFWL15::ColladaParserAutoGen15* parserToBeSet );

	        /** Loads the data into the frame work data model.*/
		bool load();
		bool load( const char* buffer, int length );

		/** Returns the parsing status of the file loader.*/
		ParsingStatus getParsingStatus() const { return mParsingStatus; }

		/** Returns the xml sax parser.*/
		const GeneratedSaxParser::SaxParser* getSaxParser() const { return mXmlSaxParser; }

		/** Returns the absolute uri of the currently parsed file*/
		const COLLADABU::URI& getFileUri();

		/** Returns a pointer to the file loader. */
		virtual FileLoader* getFileLoader() { return this; }

		/** Returns a pointer to the file loader. */
		virtual const FileLoader* getFileLoader() const { return this; }

		/** Returns the element of the element in level @a level, where the previous element is level 0. 
		If level is invalid or it is called, while no version parser is aktive, 0 is returned.*/
		StringHash getElementHash( size_t level = 0 ) const ;

	protected:
        void setSaxParser( GeneratedSaxParser::SaxParser* parserToBeSet ) { mXmlSaxParser = parserToBeSet; }
        /** Sets the private parser to @a parserToBeSet.*/
        void setPrivateParser( COLLADASaxFWL14::ColladaParserAutoGen14Private* parserToBeSet )
        {mPrivateParser14 = parserToBeSet;}
        /** Sets the private parser to @a parserToBeSet.*/
        void setPrivateParser( COLLADASaxFWL15::ColladaParserAutoGen15Private* parserToBeSet )
        {mPrivateParser15 = parserToBeSet;}


    private:
		friend class VersionParser;

        /** Disable default copy ctor. */
		FileLoader( const FileLoader& pre );

        /** Disable default assignment operator. */
		const FileLoader& operator= ( const FileLoader& pre );


	};
	
} // namespace COLLADASaxFWL

#endif // __COLLADASAXFWL_FILELOADER_H__
