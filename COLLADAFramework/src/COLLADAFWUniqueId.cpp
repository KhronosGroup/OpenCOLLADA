/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWUniqueId.h"

namespace COLLADAFW
{
	static const String UNIQUEID = "UniqueID";
	
	const UniqueId UniqueId::INVALID = UniqueId();



	//-------------------------------
	UniqueId::UniqueId( const String& ascii )
	{
		fromAscii(ascii);
	}

	//-------------------------------
	UniqueId::~UniqueId()
	{
	}

	//-------------------------------
	COLLADAFW::String UniqueId::toAscii() const
	{
		// sample: UniqueId(1,4)
		std::stringstream stream;
		stream << UNIQUEID << '(' << mClassId << ',' << mObjectId << ')';
		return stream.str();
	}

	//-------------------------------
	bool UniqueId::fromAscii( const String& ascii )
	{
		if ( !fromAscii_intern(ascii) )
		{
			*this = INVALID;
			return false;
		}
		return true;
	}

	//-------------------------------
	bool UniqueId::fromAscii_intern( const String& ascii )
	{
		static const size_t UNIQUEID_LENGTH = UNIQUEID.length();
		static const char digits[] = "0123456789";

		// sample: UniqueId(1,4)
		if ( ascii.length() < UNIQUEID_LENGTH )
		{
			return false;
		}

		if ( ascii.compare(0, UNIQUEID_LENGTH, UNIQUEID ) != 0 )
		{
			return false;
		}

		size_t classIdFirstNonDigit = ascii.find_last_not_of( digits, UNIQUEID_LENGTH+1 );
		if ( (classIdFirstNonDigit == ascii.npos) || (classIdFirstNonDigit == UNIQUEID_LENGTH+1))
		{
			// no digit follows the opening bracket 
			return false;
		}
		if ( ascii[classIdFirstNonDigit] == ',' )
		{
			// missing comma after first number
			return false;
		}
		//parse
		mClassId = atoi( &ascii[UNIQUEID_LENGTH+1]);

		size_t objectIdFirstNonDigit = ascii.find_last_not_of( digits, classIdFirstNonDigit + 1);
		if ( (objectIdFirstNonDigit == ascii.npos) || (objectIdFirstNonDigit == classIdFirstNonDigit + 1) )
		{
			// no digit follows the opening bracket 
			return false;
		}

		mObjectId = atoi( &ascii[classIdFirstNonDigit+1]);

		return true;
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

		if ( mFileId < rhs.mFileId )
			return true;
		if ( mFileId > rhs.mFileId )
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

		if ( mFileId > rhs.mFileId )
			return true;
		if ( mFileId < rhs.mFileId )
			return false;

        return false;
    }

    //-------------------------------
    bool UniqueId::operator== ( const UniqueId& uid ) const
    {
		return (mClassId == uid.mClassId) && (mObjectId == uid.mObjectId) && (mFileId == uid.mFileId);
    }

    //-------------------------------
    bool UniqueId::operator!= ( const UniqueId& uid ) const
    {
		return (mClassId != uid.mClassId) || (mObjectId != uid.mObjectId) || (mFileId != uid.mFileId);
    }

	//------------------------------
	UniqueId::operator size_t() const
	{
		size_t retVal = 2166136261U;
		const char* p = (const char*)this;
		for ( size_t i = 0; i < sizeof(UniqueId); ++i)
		{
			retVal = 16777619U * retVal ^ (size_t)(*p++);
		}
		return retVal;
	}

} // namespace COLLADAFW
