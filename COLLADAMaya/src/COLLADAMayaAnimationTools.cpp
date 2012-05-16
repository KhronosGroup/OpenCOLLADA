/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADAMayaAnimationTools.h"


namespace COLLADAMaya
{

    // ----------------------------------------------------------
    int AnimationClip::findPlug ( const MPlug& p )
    {
        uint count = plugs.length();

        for ( uint i = 0; i < count; ++i )
        {
            if ( p == plugs[i] )
            {
                if ( !p.isElement() || p.logicalIndex() == plugs[i].logicalIndex() )
                {
                    return i;
                }
            }
        }

        return -1;
    }

}