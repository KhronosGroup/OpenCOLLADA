/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSidAddress.h"

#include <boost/regex.hpp>
#include <boost/regex/v4/match_flags.hpp>


namespace COLLADASaxFWL
{

	const char* sidSeparator = "/";

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
		/* An sid path looks as follows
			<id>/sid1/sid2/sid3<accessor>
			where,
			<id> is either a valid id or a "." for relative paths
			<accessor> is either "." followed by a name eg "ANGLE"
			              or a one dimensional array access of the form (<number>)
						  or a two dimensional array access of the form (<number>)(<number>)
						  or empty
			The number of sids is arbitrary an can be zero

		*/

		// Find the last sid separator "/"
		// we use this to split the address in to parts "<id>/sid1/sid2/"  and  "sid3<accessor>"
		size_t lastSidSeparator = sidAddress.find_last_of(sidSeparator);

		bool hasId = false;
		if ( lastSidSeparator != String::npos )
		{
			size_t nextTokenIndex = 0; 
			size_t startPos = 0;
			while (nextTokenIndex != lastSidSeparator)
			{
				nextTokenIndex = sidAddress.find_first_of(sidSeparator, startPos);
				if ( hasId )
				{
					mSids.push_back(String(sidAddress, startPos, nextTokenIndex- startPos));
				}
				else
				{
					if ( sidAddress[startPos] != '.' )
						mId.assign(sidAddress, startPos, nextTokenIndex- startPos);
					hasId = true;
				}
				startPos = nextTokenIndex + 1;
			}
		}

		const char * secondPart = sidAddress.c_str() + lastSidSeparator + 1;


		static boost::regex accessorNameRegex("(.+)\\.(.+)");
		boost::cmatch accessorNameRegexMatches; 

		static boost::regex accessorIndexRegex("(.+)(?:\\(([0-9]+)\\))?(?:\\(([0-9]+)\\))?");
		boost::cmatch accessorIndexRegexMatches; 

		if ( boost::regex_match(secondPart, accessorNameRegexMatches, accessorNameRegex) )
		{
			// first try the name accessor
			// this matches only, if the name accessor is present. Therefor there are exactly two matches 
			boost::cmatch::const_reference idOrSidMatch = accessorNameRegexMatches[1];
			assert(idOrSidMatch.matched);
			if ( idOrSidMatch.matched )
			{
				if ( hasId )
				{
					mSids.push_back(String(idOrSidMatch.first, idOrSidMatch.second - idOrSidMatch.first));
				}
				else
				{
					if ( *idOrSidMatch.first != '.' )
						mId.assign(idOrSidMatch.first, idOrSidMatch.second - idOrSidMatch.first);
					hasId = true;
				}
			}

			boost::cmatch::const_reference nameMatch = accessorNameRegexMatches[2];
			assert(nameMatch.matched);
			if ( nameMatch.matched )
			{
				mMemberSelectionName.assign(nameMatch.first, nameMatch.second - nameMatch.first);
			}

			mMemberSelection = MEMBER_SELECTION_NAME;

			mIsValid = true;
		}
		else if ( boost::regex_match(secondPart, accessorIndexRegexMatches, accessorIndexRegex, boost::regex_constants::match_any) )
		{
			size_t matchesCount = accessorIndexRegexMatches.size();
			//check all other cases
			// the first match is id or sid
			boost::cmatch::const_reference idOrSidMatch = accessorIndexRegexMatches[1];
			assert(idOrSidMatch.matched);
			if ( idOrSidMatch.matched )
			{
				if ( hasId )
				{
					mSids.push_back(String(idOrSidMatch.first, idOrSidMatch.second - idOrSidMatch.first));
				}
				else
				{
					if ( *idOrSidMatch.first != '.' )
						mId.assign(idOrSidMatch.first, idOrSidMatch.second - idOrSidMatch.first);
					hasId = true;
				}
			}
			mMemberSelection = MEMBER_SELECTION_NONE;

			// this one matches only if two indices are specified. In case of one index, only the next matches
			boost::cmatch::const_reference firstIndexMatch = accessorIndexRegexMatches[2];
			if ( firstIndexMatch.matched )
			{
				mMemberSelection = MEMBER_SELECTION_TWO_INDICES;
				bool failed = false;
				const char* bufferBegin = firstIndexMatch.first;
				mFirstIndex = (size_t)GeneratedSaxParser::Utils::toUint32(&bufferBegin, firstIndexMatch.second, failed);
				if ( failed )
				{
					mIsValid = false;
					return;
				}
			}

			// this one matches if two indices or only index are specified. 
			boost::cmatch::const_reference secondIndexMatch = accessorIndexRegexMatches[3];
			if ( secondIndexMatch.matched )
			{
				bool failed = false;
				const char* bufferBegin = secondIndexMatch.first;
				size_t index = (size_t)GeneratedSaxParser::Utils::toUint32(&bufferBegin, secondIndexMatch.second, failed);
				if ( mMemberSelection != MEMBER_SELECTION_TWO_INDICES )
				{
					mMemberSelection = MEMBER_SELECTION_ONE_INDEX;
					mFirstIndex = index;
				}
				else
				{
					mSecondIndex = index;
				}
				if ( failed )
				{
					mIsValid = false;
					return;
				}
			}

			mIsValid = true;
		}
		else
		{
			mIsValid = false;
		}

	}
} // namespace COLLADASaxFWL
