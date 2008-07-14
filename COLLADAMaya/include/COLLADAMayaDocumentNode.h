/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_DOCUMENT_NODE_H__
#define __COLLADA_MAYA_DOCUMENT_NODE_H__

#include <maya/MPxNode.h>

namespace COLLADAMaya
{
    /**
     * Class to represent the dae node for register on plugin.
     */

    class DocumentNode : public MPxNode
    {

    public:
        // DG attributes
        static MObject rootAttribute;
        static MObject filenameAttribute;
        static MObject entityIdAttribute;
        static MObject entityLinkAttribute;

    public:
        /** Constructor */
        DocumentNode();
        virtual ~DocumentNode();

        // Plug-in interface
        static void* creator();
        static MStatus initialize();
        static MTypeId id;

        // MPxNode interface.
        virtual Type type() const
        {
            return MPxNode::kDependNode;
        }

        /*
        // TODO
        // Document Management
        inline size_t GetDocumentCount() { return documents.size(); }
        inline DaeDoc* GetDocument(size_t index) { FUAssert(index < documents.size(), return NULL); return documents.at(index); }
        DaeDoc* FindDocument(uint logicalIndex);
        DaeDoc* FindDocument(const MString& filename);
        DaeDoc* FindDocument(FCDocument* colladaDocument);
        void ReleaseDocument(DaeDoc* document);
        void ReleaseAllEntityNodes();
        uint Synchronize();

        // Entites
        void LinkEntity(DaeDoc* document, DaeEntity* entity, MObject& node);
        DaeEntity* FindEntity(const MObject& node, DaeDoc** document=NULL);
        */
    };

}

#endif // __COLLADA_MAYA_DOCUMENT_NODE_H__

