/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_MATERIAL_IMPORTER_H__
#define __COLLADA_MAYA_MATERIAL_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"

namespace COLLADAMaya
{

    /** Declares the importer class for import materials. */
    class MaterialImporter : public BaseImporter
    {

    public:

        /** Constructor. */
        MaterialImporter ( DocumentImporter* documentImporter, daeDocument* daeDoc );

        /** Destructor. */
        virtual ~MaterialImporter () {}

        /** Imports all materials from the current collada document. */
        void importMaterials();

    private:

        /** Imports the current material into the maya scene. */
        void importMaterial ( domMaterial& material );

    };
}

#endif // __COLLADA_MAYA_MATERIAL_IMPORTER_H__