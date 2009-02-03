/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_IERROR_H__
#define __COLLADASAXFWL_IERROR_H__

#include "COLLADASaxFWLPrerequisites.h"


namespace COLLADASaxFWL
{

    /** Interface for error that can occur while loading a document. */
	class IError 	
	{
	public:
		enum Severity
		{
			SEVERITY_ERROR,
			SEVERITY_CRITICAL,
		};

		enum ErrorType
		{
			ERROR_SAXPARSER      // SaxParserError
		};
	public:
        /** Constructor. */
		IError(){}

        /** Destructor. */
		virtual ~IError();

		/** Returns the type of the error.*/
		ErrorType virtual getErrorType() const=0;

		/** Returns the severity of the error.*/
		Severity virtual getSeverity() const=0;

	private:

        /** Disable default copy ctor. */
		IError( const IError& pre );

        /** Disable default assignment operator. */
		const IError& operator= ( const IError& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_IERROR_H__
