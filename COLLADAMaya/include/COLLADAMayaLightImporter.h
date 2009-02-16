/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_LIGHTIMPORTER_H__
#define __COLLADAMAYA_LIGHTIMPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaBaseImporter.h"


namespace COLLADAMaya
{

    /** TODO Documentation */
    class LightImporter : BaseImporter
    {
	private:
	
	public:

        /** Constructor. */
		LightImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~LightImporter ();

        /**
        * Imports the data of the current light.
        */
        void importLight ( const COLLADAFW::Light* camera );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_LIGHTIMPORTER_H__
