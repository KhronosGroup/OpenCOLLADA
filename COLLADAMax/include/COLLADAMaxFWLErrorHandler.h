/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_FWLERRORHANDLER_H__
#define __COLLADAMAX_FWLERRORHANDLER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADASaxFWLIErrorHandler.h"


namespace COLLADAMax
{

    /** TODO Documentation */
	class FWLErrorHandler : public COLLADASaxFWL::IErrorHandler	
	{
	private:
	
	public:

        /** Constructor. */
		FWLErrorHandler();

        /** Destructor. */
		virtual ~FWLErrorHandler();

		/** If this method returns true, the loader stops parsing immediately. If severity is nor CRITICAL
		and this method returns true, the loader continues loading.*/
		bool virtual handleError(const COLLADASaxFWL::IError* error);


	private:

        /** Disable default copy ctor. */
		FWLErrorHandler( const FWLErrorHandler& pre );

        /** Disable default assignment operator. */
		const FWLErrorHandler& operator= ( const FWLErrorHandler& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_FWLERRORHANDLER_H__
