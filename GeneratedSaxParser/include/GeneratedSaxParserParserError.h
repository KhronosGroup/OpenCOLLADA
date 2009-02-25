/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_PARSERERROR_H__
#define __GENERATEDSAXPARSER_PARSERERROR_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"



namespace GeneratedSaxParser
{
	class ParserError 	
	{
	public:
		enum Severity
		{
			SEVERITY_ERROR2,
			SEVERITY_CRITICAL,
		};

		enum ErrorType
		{
			ERROR_COULD_NOT_OPEN_FILE,
			ERROR_XML_PERSER_ERROR,
			ERROR_UNKNOWN_ELEMENT,
			ERROR_UNEXPECTED_ELEMENT,
			ERROR_ELEMENT_MUST_BE_ROOT,
			ERROR_ELEMENT_MUST_NOT_BE_ROOT,
			ERROR_TEXTDATA_PARSING_FAILED,
			ERROR_UNKNOWN_ATTRIBUTE,
			ERROR_ATTRIBUTE_PARSING_FAILED

		};
	private:
		/** The Severity of the error*/
		Severity mSeverity;

		/** The type of th error.*/
		ErrorType mErrorType;

		/** The hash of the element, the error occurred in.*/
		const char* mElementName;

		/** The hash of the attribute, that caused the error. Might be zero if no attribute 
		was involved.*/
		const char* mAttributeName;

		/** The line number the error occurred in. Might be zero if the location could not be
		determined.*/
		size_t mLineNumber;

		/** The column number the error occurred in. Might be zero if the location could not be
		determined.*/
		size_t mColumnNumber;

		/** Additional text information. Its meaning depends on the error type. Might be empty.*/
		String mAdditionalText;
	
	public:
		ParserError(Severity severity, 
					ErrorType errorType, 
					const char* elementName, 
					const char* attributeName, 
					size_t lineNumber, 
					size_t columnNumber,
					String additionalText = "");
		virtual ~ParserError();

		/** Returns the severity of the error.*/
		Severity getSeverity() const { return mSeverity; }

		/** Returns the error type.*/
		ErrorType getErrorType() const { return mErrorType; }

		/** Returns the name of the element, the error occurred in.*/
		const char* getElement() const { return mElementName; }

		/** Returns the name of the attribute, that caused the error. Might be zero if no attribute 
		was involved.*/
		const char* getAttribute() const { return mAttributeName; }

		/** Returns the line number the error occurred in. Might be zero if the location could not be
		determined.*/
		size_t getLineNumber() const { return mLineNumber; }

		/** Returns the column number the error occurred in. Might be zero if the location could not be
		determined.*/
		size_t getColumnNumber() const { return mColumnNumber; }

		/** Returns the Additional text information. Its meaning depends on the error type. Might be empty.*/
		const String& getAdditionalText() const { return mAdditionalText; }
	
		/** Returns a human readable error message, describing the error.*/
		String getErrorMessage() const;


	public:
	
	
	private:
		ParserError();
        /** Disable default copy ctor. */
		ParserError( const ParserError& pre );
        /** Disable default assignment operator. */
		const ParserError& operator= ( const ParserError& pre );

	};
} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_PARSERERROR_H__
