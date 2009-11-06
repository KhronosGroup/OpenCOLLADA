/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

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

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_SAXPARSERERRORHANDLER_H__
