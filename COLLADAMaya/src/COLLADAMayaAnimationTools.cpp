/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
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