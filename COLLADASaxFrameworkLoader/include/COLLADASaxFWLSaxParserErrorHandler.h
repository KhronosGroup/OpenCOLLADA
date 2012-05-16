/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADASaxFrameworkLoader.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SAXPARSERERRORHANDLER_H__
#define __COLLADASAXFWL_SAXPARSERERRORHANDLER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "GeneratedSaxParserIErrorHandler.h"


namespace GeneratedSaxParser
{
	class ParserError;
}

namespace COLLADASaxFWL
{
	class IErrorHandler;

	/** TODO Documentation */
	class SaxParserErrorHandler : public GeneratedSaxParser::IErrorHandler
	{
	private:


	private:
		/** The error handler to pass the errors to.*/
		COLLADASaxFWL::IErrorHandler* mErrorHandler;
		bool mHasErrors;
		bool mHasCriticalError;

	public:
		/** Constructor. */
		SaxParserErrorHandler(COLLADASaxFWL::IErrorHandler* mErrorHandler);

		/** Destructor. */
		virtual ~SaxParserErrorHandler();

		/** Notification of a parser error
		@param error The error object with specific information.
		@returns If true is returned, the parse stops parsing immediately, if false is returned and 
		the severity of the error is not ERROR_CRITICAL, the parser will continue.
		*/
		bool handleError( const GeneratedSaxParser::ParserError& error );

		/** Notification sent before starting the problem detection process.
		Typically, this would tell a problem collector to clear previously recorded problems.
		*/
		void beginReporting(){}

		/** Notification sent after having completed problem detection process.
		Typically, this would tell a problem collector that no more problems should be expected in this
		iteration.
		*/
		void endReporting(){}

		/** Signals that one or more errors have been accepted.
		@return boolean - <code>true</code> if errors have been accepted, otherwise <code>false</code>
		*/
		bool hasErrors() const { return mHasErrors; };

		/** Signals that a has been accepted.
		@return boolean - <code>true</code> if a critical error has been accepted, otherwise <code>false</code>
		*/
		bool hasCriticalError() const { return mHasCriticalError; };



	private:

		/** Disable default copy ctor. */
		SaxParserErrorHandler( const SaxParserErrorHandler& pre );

		/** Disable default assignment operator. */
		const SaxParserErrorHandler& operator= ( const SaxParserErrorHandler& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_SAXPARSERERRORHANDLER_H__
