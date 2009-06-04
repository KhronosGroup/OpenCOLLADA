/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaGeometryBinding.h"


namespace COLLADAMaya
{

    //------------------------------
    bool GeometryBinding::operator< ( const GeometryBinding& rhs ) const
    {
        if ( mSourceId < rhs.mSourceId )
            return true;
        if ( mSourceId > rhs.mSourceId )
            return false;

        if ( mTransformId < rhs.mTransformId )
            return true;
        if ( mTransformId > rhs.mTransformId )
            return false;

        return false;
    }

    //------------------------------
    bool GeometryBinding::operator== ( const GeometryBinding& uid ) const
    {
        if ( mSourceId != uid.mSourceId ) return false;
        if ( mTransformId != uid.mTransformId ) return false;
        return true;
    }

} // namespace COLLADAMaya
