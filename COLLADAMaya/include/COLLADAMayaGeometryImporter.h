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

#ifndef __COLLADA_MAYA_GEOMETRY_IMPORTER_H__
#define __COLLADA_MAYA_GEOMETRY_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"

namespace COLLADAMaya
{

    /** Declares xy */
    class GeometryImporter
    {

    public:

        /** Constructor. */
        GeometryImporter () {}

        /** Destructor. */
        virtual ~GeometryImporter () {}

    };
}

#endif // __COLLADA_MAYA_GEOMETRY_IMPORTER_H__