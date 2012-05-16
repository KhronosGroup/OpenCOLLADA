/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SAXPARSERERROR_H__
#define __COLLADASAXFWL_SAXPARSERERROR_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLIError.h"

namespace GeneratedSaxParser
{
	class ParserError;
}


namespace COLLADASaxFWL
{

    /** Error reported by the generated sax parser. These are mainly validation errors. */
	class SaxParserError : public IError 
	{
	private:
		const GeneratedSaxParser::ParserError& mError;
	
	public:

        /** Constructor. */
		SaxParserError( const GeneratedSaxParser::ParserError& error);

        /** Destructor. */
		virtual ~SaxParserError();

		/** Returns the type of the error.*/
		ErrorClass getErrorClass() const { return IError::ERROR_SAXPARSER; }

		/** Returns the severity of the error.*/
		Severity getSeverity() const;

        /** Returns the current error to get the error message. */
        const GeneratedSaxParser::ParserError& getError () { return mError; }

		/** The full error message describing the error, including all information.*/
		String getFullErrorMessage() const;

	private:

        /** Disable default copy ctor. */
		SaxParserError( const SaxParserError& pre );

        /** Disable default assignment operator. */
		const SaxParserError& operator= ( const SaxParserError& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_SAXPARSERERROR_H__
