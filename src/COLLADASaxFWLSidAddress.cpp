/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSidAddress.h"


namespace COLLADASaxFWL
{

	const char* separators = "/().";

    //------------------------------
	SidAddress::SidAddress( const String& sidAddress )
		: mMemberSelection(MEMBER_SELECTION_NONE)
		, mFirstIndex(0)
		, mSecondIndex(0)
		, mIsValid(false)
	{
		parseAddress( sidAddress );
	}

	SidAddress::SidAddress( const COLLADABU::URI& id, const String& sid )
		: mId(id.getFragment())
		, mMemberSelection(MEMBER_SELECTION_NONE)
		, mFirstIndex(0)
		, mSecondIndex(0)
		, mIsValid( !id.getFragment().empty() && !sid.empty() )
	{
		mSids.push_back( sid );
	}

    //------------------------------
	SidAddress::~SidAddress()
	{
	}

	//------------------------------
	void SidAddress::parseAddress( const String& sidAddress )
	{
		enum States
		{
			STATE_BEGIN,					//!< Nothing has been parsed yet
			STATE_ID,						//!< The id has been parsed and set
			STATE_SID,						//!< One or more sids have been parsed
			STATE_MEMBER_SELECTION_DOT,     //!< A dot for member selection has been found, next is member name
			STATE_MEMBER_SELECTION_NAME

		};

		size_t startPos = 0;

		States state = STATE_BEGIN;
		if ( sidAddress[0] == '.' )
		{
			// the address is relative
			mId = "";
			state = STATE_ID;
			startPos++;
		}

		while ( startPos != String::npos )
		{
			char separator;
			String token = nextToken( separator, startPos, sidAddress);
			if ( token.empty() )
				continue;
			switch ( separator )
			{
			case '/':
				{
					if ( state == STATE_BEGIN )
					{
						mId = token;
						state = STATE_ID;
					}
					else if ( state == STATE_ID || state == STATE_SID )
					{
						mSids.push_back(token);
						state = STATE_SID;
					}
					else
					{
						//todo error handling
						return;
					}
					break;
				}
			case '\0':
				{
					if ( state == STATE_ID || state == STATE_SID )
					{
						mSids.push_back(token);
						state = STATE_SID;
					}
					else if ( state == STATE_MEMBER_SELECTION_DOT )
					{
						mMemberSelectionName = token;
						mMemberSelection = MEMBER_SELECTION_NAME;
					}
					else
					{
						// todo error handling
						return;
					}
					break;
				}
			case '.':
				{
					if ( state == STATE_SID || state == STATE_ID)
					{
						mSids.push_back(token);
						state = STATE_MEMBER_SELECTION_DOT;
					}
					else
					{
						// todo error handling
						return;
					}
					break;
				}
			}
		}

		mIsValid = true;
	}

	//------------------------------
	String SidAddress::nextToken(  /*out*/ char& separator,  /*in out*/ size_t& startPos, const String& string )
	{
		size_t nextTokenIndex = string.find_first_of(separators, startPos);
		
		if ( nextTokenIndex == String::npos)
		{
			// no separator has been found. The rest of the string is the last token
			separator = '\0';
			String returnString(string, startPos);
			startPos = String::npos;
			return returnString;
		}
		else
		{
			separator = string[nextTokenIndex];
			String returnString(string, startPos, nextTokenIndex - startPos);
			startPos = nextTokenIndex + 1;
			return returnString;
		}
	}


} // namespace COLLADASaxFWL
