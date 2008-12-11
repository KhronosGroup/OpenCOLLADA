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

//#include "COLLADADHLoader.h"


namespace COLLADAMaya
{

    /** Declares the base import functionality. 
    This is the base class for all importers. */
    class BaseImporter
    {

    private:

        /** Pointer to the current document importer. */
        DocumentImporter* mDocumentImporter;

    public:

        /** Constructor. */
        BaseImporter ( DocumentImporter* documentImporter )
        : mDocumentImporter ( documentImporter )
        {}

        /** Destructor. */
        virtual ~BaseImporter () {}

    protected:

        /** Returns a pointer to the current document importer. */
        DocumentImporter* getDocumentImporter () { return mDocumentImporter; }

        /** Returns a pointer to the current document importer. */
        const DocumentImporter* getDocumentImporter () const { return mDocumentImporter; }

//         /** Pointer to the current dae document. */
//         daeDocument* getDaeDocument () 
//         { 
//             return mDocumentImporter->getDocumentLoader ().getDaeDocument (); 
//         }
// 
//         /** Pointer to the current dae document. */
//         const daeDocument* getDaeDocument () const 
//         { 
//             return mDocumentImporter->getDocumentLoader ().getDaeDocument (); 
//         }
// 
//         /** Returns the current document loader. */
//         COLLADADH::Loader& getDocumentLoader ()
//         {
//             return mDocumentImporter->getDocumentLoader ();
//         }
// 
//         /** Returns the current document loader. */
//         const COLLADADH::Loader& getDocumentLoader () const
//         {
//             return mDocumentImporter->getDocumentLoader ();
//         }

    };
}

#endif // __COLLADA_MAYA_BASE_IMPORTER_H__