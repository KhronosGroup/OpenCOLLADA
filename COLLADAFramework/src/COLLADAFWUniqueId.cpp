/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWUniqueId.h"

namespace COLLADAFW
{
	
	const UniqueId UniqueId::INVALID = UniqueId();


	//-------------------------------
	UniqueId::~UniqueId()
	{
	}

    //-------------------------------
	bool UniqueId::operator<( const UniqueId& rhs ) const
	{
		if ( mClassId < rhs.mClassId )
			return true;
		if ( mClassId > rhs.mClassId )
			return false;

		if ( mObjectId < rhs.mObjectId )
			return true;
		if ( mObjectId > rhs.mObjectId )
			return false;

		return false;
	}

    //-------------------------------
    bool UniqueId::operator>( const UniqueId& rhs ) const
    {
        if ( mClassId > rhs.mClassId )
            return true;
        if ( mClassId < rhs.mClassId )
            return false;

        if ( mObjectId > rhs.mObjectId )
            return true;
        if ( mObjectId < rhs.mObjectId )
            return false;

        return false;
    }

    //-------------------------------
    bool UniqueId::operator== ( const UniqueId& uid ) const
    {
        if ( mClassId != uid.getClassId () ) return false;
        if ( mObjectId != uid.getObjectId () ) return false;
        return true;
    }

    //-------------------------------
    bool UniqueId::operator!= ( const UniqueId& uid ) const
    {
        if ( mClassId != uid.getClassId () ) return true;
        if ( mObjectId != uid.getObjectId () ) return true;
        return false;
    }

} // namespace COLLADAFW
