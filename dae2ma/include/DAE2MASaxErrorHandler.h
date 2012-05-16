/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_SAXPARSERERRORHANDLER_H__
#define __DAE2MA_SAXPARSERERRORHANDLER_H__

#include "DAE2MAPrerequisites.h"

#include "COLLADASaxFWLIErrorHandler.h"
#include "COLLADASaxFWLSaxParserError.h"


namespace DAE2MA
{

    /** TODO Documentation */
    class SaxErrorHandler : public COLLADASaxFWL::IErrorHandler
    {
	private:
	
	public:

        /** Constructor. */
        SaxErrorHandler();

        /** Destructor. */
		virtual ~SaxErrorHandler();

        /** 
         * If this method returns true, the loader stops parsing immediately. 
         * If severity is not CRITICAL and this method returns true, the loader continues loading.
         */
        bool virtual handleError ( const COLLADASaxFWL::IError* error );

	private:

        /** Disable default copy ctor. */
		SaxErrorHandler( const SaxErrorHandler& pre );

        /** Disable default assignment operator. */
		const SaxErrorHandler& operator= ( const SaxErrorHandler& pre );

	};

} // namespace DAE2MA

#endif // __DAE2MA_SAXPARSERERRORHANDLER_H__
