/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_SAXPARSERERRORHANDLER_H__
#define __COLLADAMAYA_SAXPARSERERRORHANDLER_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADASaxFWLIErrorHandler.h"
#include "COLLADASaxFWLSaxParserError.h"


namespace COLLADAMaya
{

    /** TODO Documentation */
    class SaxParserErrorHandler : public COLLADASaxFWL::IErrorHandler
    {
	private:
	
	public:

        /** Constructor. */
        SaxParserErrorHandler();

        /** Destructor. */
		virtual ~SaxParserErrorHandler();

        /** 
         * If this method returns true, the loader stops parsing immediately. 
         * If severity is not CRITICAL and this method returns true, the loader continues loading.
         */
        bool virtual handleError ( const COLLADASaxFWL::IError* error );

	private:

        /** Disable default copy ctor. */
		SaxParserErrorHandler( const SaxParserErrorHandler& pre );

        /** Disable default assignment operator. */
		const SaxParserErrorHandler& operator= ( const SaxParserErrorHandler& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_SAXPARSERERRORHANDLER_H__
