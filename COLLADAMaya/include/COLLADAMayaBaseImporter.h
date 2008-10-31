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

#ifndef __COLLADA_MAYA_BASE_IMPORTER_H__
#define __COLLADA_MAYA_BASE_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentImporter.h"

namespace COLLADAMaya
{

    /** Declares the base import functionality. 
    This is the base class for all importers. */
    class BaseImporter
    {

    private:

        /** Pointer to the current document importer. */
        DocumentImporter* mDocumentImporter;

        /** Pointer to the current dae document. */
        daeDocument* mDaeDoc;

    public:

        /** Constructor. */
        BaseImporter ( DocumentImporter* documentImporter, daeDocument* daeDoc )
        : mDocumentImporter ( documentImporter )
        , mDaeDoc ( daeDoc )
        {}

        /** Destructor. */
        virtual ~BaseImporter () {}

    protected:

        /** Returns a pointer to the current document importer. */
        DocumentImporter* getDocumentImporter () { return mDocumentImporter; }

        /** Pointer to the current dae document. */
        daeDocument* getDaeDocument () { return mDaeDoc; }
        const daeDocument* getDaeDocument () const { return mDaeDoc; }

        /** Returns a pointer to the current document importer. */
        const DocumentImporter* getDocumentImporter () const { return mDocumentImporter; }


    };
}

#endif // __COLLADA_MAYA_BASE_IMPORTER_H__