/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADADH_BASELOADER_H__
#define __COLLADADH_BASELOADER_H__

#include "COLLADADHPrerequisites.h"


namespace COLLADADH
{

    /** Base loader class, which holds a pointer to the dae document. */
	class BaseLoader 	
    {
	private:
	
        /** The collada document. */
        daeDocument* mDaeDocument;

	public:

        /** Constructor. */
        BaseLoader ( daeDocument* daeDoc );

        /** Destructor. */
        virtual ~BaseLoader();

        /** Returns a pointer to the collada document. */
        daeDocument* getDaeDocument ();

        /** Returns a const pointer to the collada document. */
        const daeDocument* getDaeDocument () const;

    private:

        /** Disable default copy ctor. */
		BaseLoader( const BaseLoader& pre );

        /** Disable default assignment operator. */
		const BaseLoader& operator= ( const BaseLoader& pre );

	};
	
} // namespace COLLADADH

#endif // __COLLADADH_BASELOADER_H__
