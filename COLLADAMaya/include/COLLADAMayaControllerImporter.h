/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_CONTROLLERIMPORTER_H__
#define __COLLADAMAYA_CONTROLLERIMPORTER_H__

#include "COLLADAMayaPrerequisites.h"


namespace COLLADAMaya
{

    /** TODO Documentation */
	class ControllerImporter 	
    {
	private:
	
	public:

        /** Constructor. */
		ControllerImporter();

        /** Destructor. */
		virtual ~ControllerImporter();

	private:

        /** Disable default copy ctor. */
		ControllerImporter( const ControllerImporter& pre );

        /** Disable default assignment operator. */
		const ControllerImporter& operator= ( const ControllerImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_CONTROLLERIMPORTER_H__
