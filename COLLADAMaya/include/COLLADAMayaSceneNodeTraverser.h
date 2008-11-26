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

#ifndef __COLLADA_MAYA_SCENE_NODE_TRAVERSER_H__
#define __COLLADA_MAYA_SCENE_NODE_TRAVERSER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentImporter.h"

#include "COLLADANodeTraverser.h"

namespace COLLADAMaya
{

    /** Declares the implementation of the node traverser for the node traverser listener. */
    class SceneNodeTraverser : public COLLADADH::NodeTraverser
    {

    private:

        /** Pointer to the current document importer. */
        DocumentImporter* mDocumentImporter;

    public:

        /** Constructor.
        @param nodeContainer. A element which contains nodes.
        */
        SceneNodeTraverser ( DocumentImporter* documentImporter, daeElement &nodeContainer );

        /** Destructor. */
        virtual ~SceneNodeTraverser () {}

        /** Returns a pointer to the current document importer. */
        DocumentImporter* getDocumentImporter () { return mDocumentImporter; }

        /** Returns a pointer to the current document importer. */
        const DocumentImporter* getDocumentImporter () const { return mDocumentImporter; }

    };
}

#endif // __COLLADA_MAYA_SCENE_NODE_TRAVERSER_H__