/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MAShadingBinding.h"


namespace DAE2MA
{

    //------------------------------
    ShadingBinding::ShadingBinding()
	{
	}

    //------------------------------
    ShadingBinding::ShadingBinding ( 
        const COLLADAFW::UniqueId& geometryId, 
        const COLLADAFW::UniqueId& transformId, 
        const COLLADAFW::MaterialId& shadingEngineId,
        const COLLADAFW::UniqueId& controllerId /*= COLLADAFW::UniqueId ()*/ ) 
        : mGeometryId (geometryId)
        , mTransformId (transformId)
        , mShadingEngineId (shadingEngineId)
        , mControllerId (controllerId)
    {

    }

    //------------------------------
	ShadingBinding::~ShadingBinding()
	{
	}

    //------------------------------
    bool ShadingBinding::operator< ( const ShadingBinding& rhs ) const
    {
        if ( mGeometryId < rhs.mGeometryId )
            return true;
        if ( mGeometryId > rhs.mGeometryId )
            return false;

        if ( mTransformId < rhs.mTransformId )
            return true;
        if ( mTransformId > rhs.mTransformId )
            return false;

        if ( mShadingEngineId < rhs.mShadingEngineId )
            return true;
        if ( mShadingEngineId > rhs.mShadingEngineId )
            return false;

        return false;
    }

    //------------------------------
    bool ShadingBinding::operator== ( const ShadingBinding& uid ) const
    {
        if ( mGeometryId != uid.mGeometryId ) return false;
        if ( mTransformId != uid.mTransformId ) return false;
        if ( mShadingEngineId != uid.mShadingEngineId ) return false;
        return true;
    }

} // namespace DAE2MA
