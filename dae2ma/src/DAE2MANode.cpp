/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#include "DAE2MAStableHeaders.h"
#include "DAE2MANode.h"

#include "COLLADABUUtils.h"


namespace DAE2MA
{

    // -----------------------------
    MayaNode::MayaNode () 
        : mName (EMPTY_STRING)
        , mType ( COLLADAFW::Node::NODE )
        , mParentNode (0)
        , mTransformationMatrix ( COLLADABU::Math::Matrix4::IDENTITY )
    {

    }

    // -----------------------------
    MayaNode::MayaNode ( 
        const COLLADAFW::UniqueId& uniqueId, 
        const String name, 
        MayaNode* parent /*= NULL*/, 
        const COLLADAFW::Node::NodeType nodeType /*= COLLADAFW::Node::NODE*/ ) 
        : mUniqueId ( uniqueId )
        , mName ( name )
        , mType ( nodeType )
        , mParentNode ( parent ) 
        , mTransformationMatrix ( COLLADABU::Math::Matrix4::IDENTITY )
    {

    }

    // -----------------------------
    void MayaNode::setParent ( MayaNode* val )
    {
        mParentNode = val; 
    }

    // -----------------------------
    const String MayaNode::getNodePath () 
    {
        // Recursive call
        String path;
        if ( mParentNode != NULL )
        {
            path = mParentNode->getNodePath () + path;
        }
        if ( !mName.empty () )
            path += "|" + mName;

        return path;
    }

//     // -----------------------------
//     const char* MayaNode::getNodePath () 
//     {
//         static char* buffer = 0;
//         if ( !buffer )
//         {
//             buffer = new char[1000];
//         }
// 
//         // Recursive call
//         if ( mParentNode != NULL )
//         {
//             memcpy 
//             path = mParentNode->getNodePath () + path;
//         }
//         if ( !mName.empty () )
//             path += "|" + mName;
// 
//         return path;
//     }

    // -----------------------------
    String MayaNode::addChildNodeId ( 
        const String& newId, 
        bool returnConverted /*= true*/, 
        bool alwaysAddNumberSuffix /*= false */ )
    {
        return mChildNodeIds.addId ( newId, returnConverted, alwaysAddNumberSuffix );
    }

    // -----------------------------
    bool MayaNode::containsChildNodeId ( const String& id )
    {
        return mChildNodeIds.containsId ( id );
    }

} // namespace DAE2MA
