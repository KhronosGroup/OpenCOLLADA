/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SAXFWLERROR_H__
#define __COLLADASAXFWL_SAXFWLERROR_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLIError.h"


namespace COLLADASaxFWL
{

    /** Describes errors that can occur  */
	class SaxFWLError : public IError 
	{
	public:
		enum ErrorType
		{
			ERROR_UNRESOLVED_REFERENCE,             // An element that is referenced, could not be resolved.
			ERROR_UNRESOLVED_FORMULA,               // A formula referenced in a formula, could not be resolved.
			ERROR_UNRESOLVED_PARAMETER,             // A parameter referenced in a formula, could not be resolved.
			ERROR_UNEXPECTED_ELEMENT,               // An element could be resolved but does not have the expected type
			ERROR_PARAMETER_COUNT_DOESNOT_MATCH,    // A parameter referenced in a formula, could not be resolved.
			ERROR_SOURCE_NOT_FOUND,					// A source referenced an an input element could not be resolved
			ERROR_DATA_NOT_VALID,                   // Data not valid.
            ERROR_DATA_NOT_SUPPORTED                // Data not supported.
		};
	private:
		/** The type of the error.*/
		ErrorType mErrorType;

		/** The severity of th error. */
		IError::Severity mSeverity;

		/** The error message describing the error.*/
		String mErrorMessage;

		/** The line number the error occurred in. Might be zero if the location could not be
		determined.*/
		size_t mLineNumber;

		/** The column number the error occurred in. Might be zero if the location could not be
		determined.*/
		size_t mColumnNumber;
	
	public:

        /** Constructor. */
		SaxFWLError(ErrorType errorType, String errorMessage, IError::Severity severity = IError::SEVERITY_ERROR_NONCRITICAL);

        /** Destructor. */
		virtual ~SaxFWLError();

		/** Returns the type of the error.*/
		IError::ErrorClass getErrorClass() const { return IError::ERROR_SAXFWL; }

		/** Returns the severity of the error.*/
		IError::Severity getSeverity() const { return mSeverity; }

		/** Returns the type of the error.*/
		ErrorType getErrorType() const { return mErrorType; }

		/** The error message describing the error.*/
		const String& getErrorMessage() const { return mErrorMessage; }

		/** The full error message describing the error, including all information.*/
		String getFullErrorMessage() const;

		/** The line number the error occurred in. Might be zero if the location could not be
		determined.*/
		size_t getLineNumber() const { return mLineNumber; }

		/** The line number the error occurred in. Might be zero if the location could not be
		determined.*/
		void setLineNumber(size_t lineNumber) { mLineNumber = lineNumber; }

		/** The column number the error occurred in. Might be zero if the location could not be
		determined.*/
		size_t getColumnNumber() const { return mColumnNumber; }

		/** The column number the error occurred in. Might be zero if the location could not be
		determined.*/
		void setColumnNumber(size_t columnNumber) { mColumnNumber = columnNumber; }

	private:

        /** Disable default copy ctor. */
		SaxFWLError( const SaxFWLError& pre );

        /** Disable default assignment operator. */
		const SaxFWLError& operator= ( const SaxFWLError& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_SAXFWLERROR_H__
