/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_IERRORHANDLER_H__
#define __GENERATEDSAXPARSER_IERRORHANDLER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserParserError.h"


namespace GeneratedSaxParser
{
	class ParserError;

	class IErrorHandler 	
	{
	public:
		IErrorHandler(){};
		virtual ~IErrorHandler(){};

		/** Notification of a parser error
		@param error The error object with specific information.
		@returns If true is returned, the parse stops parsing immediately, if false is returned and 
		the severity of the error is not ERROR_CRITICAL, the parser will continue.
		*/
		virtual bool handleError( const ParserError& error ) = 0;

		/** Notification sent before starting the problem detection process.
		Typically, this would tell a problem collector to clear previously recorded problems.
		*/
		virtual void beginReporting() = 0;

		/** Notification sent after having completed problem detection process.
		Typically, this would tell a problem collector that no more problems should be expected in this
		iteration.
		*/
		virtual void endReporting() = 0;

		/** Predicate allowing the error handler to signal whether or not it is currently
		interested by problem reports. When answering <code>false</code>, problem will
		not be discovered any more until the next iteration.
		@par 
		This  predicate will be invoked once prior to each error detection iteration.

		@return boolean - indicates whether the requestor is currently interested in problems.
		*/
	//	virtual bool isActive() const = 0;

		/** Signals that one or more errors have been accepted.
		@return boolean - <code>true</code> if errors have been accepted, otherwise <code>false</code>
		*/
		virtual bool hasErrors() const = 0;

		/** Signals that a has been accepted.
		@return boolean - <code>true</code> if a critical error has been accepted, otherwise <code>false</code>
		*/
		virtual bool hasCriticalError() const = 0;


	private:
        /** Disable default copy ctor. */
		IErrorHandler( const IErrorHandler& pre );
        /** Disable default assignment operator. */
		const IErrorHandler& operator= ( const IErrorHandler& pre );

	};

} // namespace COLLADASAXPARSER

#endif // __GENERATEDSAXPARSER_IERRORHANDLER_H__
