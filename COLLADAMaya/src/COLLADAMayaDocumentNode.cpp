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