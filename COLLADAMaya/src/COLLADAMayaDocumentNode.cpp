/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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