/******************************************************************************
Copyright (c) 2007 netAllied GmbH, Tettnang

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

#ifndef __MATHML_SOLVER_ERROR_H__
#define __MATHML_SOLVER_ERROR_H__

#include "MathMLSolverPrerequisites.h"
#include "MathMLString.h"

namespace MathML
{

    /**
     * This class describes an error related to MathML.
     */
    class _MATHML_SOLVER_EXPORT Error
    {
    public:
        enum ErrorCode
        {
            ERR_INVALIDPARAMS,
            ERR_ITEM_NOT_FOUND,
            ERR_INTERNAL_ERROR,
        };

    private:
        /** Error code. */
        ErrorCode mErrorCode;
        /** Error message. */
        String mMsg;

    public:
        /** Constructor. */
        Error( ErrorCode errorCode, const String& errorMessage )
            : mErrorCode( errorCode )
            , mMsg( errorMessage )
        {}

        /** Destructor. */
        virtual ~Error(){}

        /** Returns the error code. */
        ErrorCode getErrorCode() const { return mErrorCode; }

        /** Returns the error message. */
        const String& getErrorMessage() const { return mMsg; }

    };

    /**
     * Handles errors. Users of the library may implement this to be notified when errors occur.
     */
    class _MATHML_SOLVER_EXPORT ErrorHandler
    {
    public:
        /** Constructor. */
        ErrorHandler(){}

        /** Destructor. */
        virtual ~ErrorHandler(){}

        /** This method is used to pass errors to implementors.
        @param error An error that occurred.
        @return true if caller should continue, false for cancel.
        */
        virtual bool handleError( const Error* error ) = 0;

    };

} // namespace MathML

#endif // __MATHML_SOLVER_ERROR_H__
