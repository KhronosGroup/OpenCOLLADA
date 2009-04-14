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
#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaNode.h"

#include "COLLADABUUtils.h"


namespace COLLADAMaya
{

    // -----------------------------
    MayaNode::MayaNode () 
        : mParent (0)
        , mName ("")
        , mPath ("")
        , mIsCorrectPositioned (true)
    {

    }

    // -----------------------------
    MayaNode::MayaNode ( 
        const COLLADAFW::UniqueId& uniqueId, 
        const String name, 
        MayaNode* parent /*= NULL*/, 
        const bool isCorrectPositioned/*=true */ ) 
        : mUniqueId ( uniqueId )
        , mName ( name )
        , mParent ( parent ) 
        , mPath ("")
        , mIsCorrectPositioned (isCorrectPositioned)
    {

    }

    // -----------------------------
    void MayaNode::setParent ( MayaNode* val )
    {
        mParent = val; 
        mPath = "";
    }

    // -----------------------------
    void MayaNode::setName ( COLLADAMaya::String val )
    {
        mName = val; 
        mPath = "";
    }

    // -----------------------------
    const COLLADAMaya::String MayaNode::getNodePath () 
    {
        if ( COLLADABU::Utils::equals ( mPath, "") ) 
        {
            if ( mParent != NULL )
            {
                mPath = mParent->getNodePath () + mPath;
            }
            mPath += "|" + mName;
        }

        return mPath;
    }

} // namespace COLLADAMaya
