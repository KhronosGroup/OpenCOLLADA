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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentNode.h"
#include "COLLADAMayaDagHelper.h"

#include <maya/MFnCompoundAttribute.h>
#include <maya/MFnTypedAttribute.h>

namespace COLLADAMaya
{

    //
    // DaeDocNode
    //

    MTypeId DocumentNode::id ( 0x0005052B );
    MObject DocumentNode::rootAttribute;
    MObject DocumentNode::filenameAttribute;
    MObject DocumentNode::entityIdAttribute;
    MObject DocumentNode::entityLinkAttribute;

    // Plug-in interface
    void* DocumentNode::creator()
    {
        return new DocumentNode();
    }

    MStatus DocumentNode::initialize()
    {
        MStatus status;
        MFnCompoundAttribute complexFn;
        MFnTypedAttribute typedFn;

        // Create the leaf document filename attribute
        filenameAttribute = typedFn.create ( "filename", "fn", MFnData::kString );
        typedFn.setStorable ( true );

        // Create the leaf attribute for the entity ids and links
        entityIdAttribute = typedFn.create ( "entity", "e", MFnData::kString );
        typedFn.setStorable ( true );
        typedFn.setArray ( true );

        // entityLinkAttribute = typedFn.create("collada", "dae", MFnData::kString);
        // typedFn.setStorable(false);
        // typedFn.setArray(false);

        // Create the root attribute for the per-document information and links
        rootAttribute = complexFn.create ( "document", "doc" );
        complexFn.addChild ( filenameAttribute );
        complexFn.addChild ( entityIdAttribute );
        complexFn.setArray ( true );
        complexFn.setStorable ( true );

        // Add the plug tree to the node definition.
        status = addAttribute ( rootAttribute );

        if ( status != MStatus::kSuccess )
        {
            status.perror ( "DaeDocNode::initialize() - addAttribute(rootAttribute)" );
            return status;
        }

        // Create the global COLLADA documents information node.
        MObject colladaNodeObject = DagHelper::getNode ( "colladaDocuments" );

        if ( colladaNodeObject.isNull() )
        {
            MFnDependencyNode colladaNodeFn;
            colladaNodeFn.create ( DocumentNode::id, "colladaDocuments" );
        }

        return MStatus::kSuccess;
    }

    DocumentNode::DocumentNode()
    {
    }

    DocumentNode::~DocumentNode()
    {}
}