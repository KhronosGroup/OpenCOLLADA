/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_IERRORHANDLER_H__
#define __COLLADASAXFWL_IERRORHANDLER_H__

#include "COLLADASaxFWLPrerequisites.h"


namespace COLLADASaxFWL
{
	class IError;

    /** Interface to handle errors that occur while parsing a collada file*/
	class IErrorHandler 	
	{
	public:
	
	public:

        /** Constructor. */
		IErrorHandler();

        /** Destructor. */
		virtual ~IErrorHandler();

		/** If this method returns true, the loader stops parsing immediately. If severity is nor CRITICAL
		and this method returns false, the loader continues loading.*/
		bool virtual handleError(const IError* error) = 0;

	private:

        /** Disable default copy ctor. */
		IErrorHandler( const IErrorHandler& pre );

        /** Disable default assignment operator. */
		const IErrorHandler& operator= ( const IErrorHandler& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_IERRORHANDLER_H__
