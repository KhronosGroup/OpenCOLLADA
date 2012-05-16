/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_HELPERLOADERBASE_H__
#define __COLLADASAXFWL_HELPERLOADERBASE_H__

#include "COLLADASaxFWLPrerequisites.h"


namespace COLLADASaxFWL
{
	class FilePartLoader;

    /** This is the base class for all loader the load parts, that can appear in different libraries. */
	class HelperLoaderBase 	
	{
	private:
		/** The file part loader that handles the storage events. Usually the object itself.*/
		FilePartLoader* mHandlingFilePartLoader;

	public:
		HelperLoaderBase(): mHandlingFilePartLoader( 0 ){}
		virtual ~HelperLoaderBase(){}

		/** Sets the handling FilePartLoader. You must set the handling FilePartLoader before the first sax callback
		is called*/
		void setHandlingFilePartLoader( FilePartLoader* handlingFilePartLoader ) { mHandlingFilePartLoader = handlingFilePartLoader; }
	
		/** Returns the handling FilePartLoader. You must set the handling FilePartLoader before the first sax callback
		is called*/
		FilePartLoader* getHandlingFilePartLoader() { COLLADABU_ASSERT(mHandlingFilePartLoader); return mHandlingFilePartLoader; }

	private:

        /** Disable default copy ctor. */
		HelperLoaderBase( const HelperLoaderBase& pre );

        /** Disable default assignment operator. */
		const HelperLoaderBase& operator= ( const HelperLoaderBase& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_HELPERLOADERBASE_H__
