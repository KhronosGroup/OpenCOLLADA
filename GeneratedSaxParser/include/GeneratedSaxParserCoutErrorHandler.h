/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_COUTERRORHANDLER_H__
#define __GENERATEDSAXPARSER_COUTERRORHANDLER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserIErrorHandler.h"



namespace GeneratedSaxParser
{

	class CoutErrorHandler 	: public IErrorHandler
	{
	private:
		bool mHasErrors;
		bool mHasCriticalError;

	public:
		CoutErrorHandler();
		virtual ~CoutErrorHandler();

		/** Notification of a parser error
		@param error The error object with specific information.
		@returns If true is returned, the parse stops parsing immediately, if false is returned and 
		the severity of the error is not ERROR_CRITICAL, the parser will continue.
		*/
		bool handleError( const ParserError& error );

		/** Notification sent before starting the problem detection process.
		Typically, this would tell a problem collector to clear previously recorded problems.
		*/
		void beginReporting(){};

		/** Notification sent after having completed problem detection process.
		Typically, this would tell a problem collector that no more problems should be expected in this
		iteration.
		*/
		void endReporting(){};

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
		CoutErrorHandler( const CoutErrorHandler& pre );
        /** Disable default assignment operator. */
		const CoutErrorHandler& operator= ( const CoutErrorHandler& pre );

	};
} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_COUTERRORHANDLER_H__
