/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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

