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
#include "COLLADAMayaStableheaders.h"
#include "COLLADAMayaNode.h"

#include "COLLADABUUtils.h"


namespace COLLADAMaya
{

    // ------------------------------------
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
