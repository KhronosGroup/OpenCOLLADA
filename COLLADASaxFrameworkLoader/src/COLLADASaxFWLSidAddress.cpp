/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADASaxFrameworkLoader.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADABUPcreCompiledPattern.h"

#include "pcre.h"


namespace COLLADASaxFWL
{

	const int regExpMatchesVectorLength = 30;    /* should be a multiple of 3 */
	const char* sidSeparator = "/";

	//------------------------------
	SidAddress::SidAddress( )
		: mMemberSelection(MEMBER_SELECTION_NONE)
		, mFirstIndex(0)
		, mSecondIndex(0)
		, mIsValid(false)
	{
	}

	//------------------------------
	SidAddress::SidAddress( const String& sidAddress )
		: mMemberSelection(MEMBER_SELECTION_NONE)
		, mFirstIndex(0)
		, mSecondIndex(0)
		, mIsValid(false)
	{
		parseAddress( sidAddress );
	}

	//------------------------------
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
	SidAddress::SidAddress( const COLLADABU::URI& id )
		: mId(id.getFragment())
		, mMemberSelection(MEMBER_SELECTION_NONE)
		, mFirstIndex(0)
		, mSecondIndex(0)
		, mIsValid( !id.getFragment().empty() )
	{
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
		int secondPartLength = (int)sidAddress.length() - (int)lastSidSeparator - 1;


		// regular expression: "(.+)\.(.+)"
		static const COLLADABU::PcreCompiledPattern accessorNameRegexCompiledPattern("(.+)\\.(.+)");
		pcre* accessorNameRegex = accessorNameRegexCompiledPattern.getCompiledPattern();

		int accessorNameMatches[regExpMatchesVectorLength];


		int  accessorNameResult = pcre_exec(
											accessorNameRegex,			/* the compiled pattern */
											0,							/* no extra data - we didn't study the pattern */
											secondPart,					/* the subject string */
											secondPartLength,			/* the length of the subject */
											0,							/* start at offset 0 in the subject */
											0,							/* default options */
											accessorNameMatches,		/* output vector for substring information */
											regExpMatchesVectorLength);	/* number of elements in the output vector */


		if ( accessorNameResult >= 0 )
		{
			// first try the name accessor
			// this matches only, if the name accessor is present. Therefor there are exactly two matches 
			int idOrSidStart = accessorNameMatches[2*1];
			int idOrSidEnd = accessorNameMatches[2*1+1];
			COLLADABU_ASSERT( idOrSidStart >= 0 );
			if ( idOrSidStart >= 0 )
			{
				if ( hasId )
				{
					mSids.push_back(String( secondPart + idOrSidStart, idOrSidEnd - idOrSidStart));
				}
				else
				{
					if ( secondPart[idOrSidStart] != '.' )
						mId.assign(secondPart + idOrSidStart, idOrSidEnd - idOrSidStart);
					hasId = true;
				}
			}

			int& nameStart = accessorNameMatches[2*2];
			int& nameEnd = accessorNameMatches[2*2+1];
			COLLADABU_ASSERT(nameStart>=0);
			if ( nameStart>=0 )
			{
				mMemberSelectionName.assign(secondPart + nameStart, nameEnd - nameStart);
			}

			mMemberSelection = MEMBER_SELECTION_NAME;

			mIsValid = true;
		}
		else 
		{
			// regular expression: "([^(]+)(?:\(([0-9]+)\))?(?:\(([0-9]+)\))?"
			static const COLLADABU::PcreCompiledPattern accessorIndexRegexCompiledPattern("([^(]+)(?:\\(([0-9]+)\\))?(?:\\(([0-9]+)\\))?");
			pcre* accessorIndexRegex = accessorIndexRegexCompiledPattern.getCompiledPattern();

			int accessorIndexMatches[regExpMatchesVectorLength];

			int  accessorIndexResult = pcre_exec(
				accessorIndexRegex,			/* the compiled pattern */
				0,							/* no extra data - we didn't study the pattern */
				secondPart,					/* the subject string */
				secondPartLength,			/* the length of the subject */
				0,							/* start at offset 0 in the subject */
				0,							/* default options */
				accessorIndexMatches,		/* output vector for substring information */
				regExpMatchesVectorLength);

			if ( accessorIndexResult >= 0 )
			{
				//check all other cases
				// the first match is id or sid
				int& idOrSidStart = accessorIndexMatches[2*1];
				int& idOrSidEnd = accessorIndexMatches[2*1+1];
				COLLADABU_ASSERT( idOrSidStart >= 0 );

				if ( idOrSidStart >= 0 )
				{
					if ( hasId )
					{
						mSids.push_back(String( secondPart + idOrSidStart, idOrSidEnd - idOrSidStart));
					}
					else
					{
						if ( secondPart[idOrSidStart] != '.' )
							mId.assign(secondPart + idOrSidStart, idOrSidEnd - idOrSidStart);
						hasId = true;
					}
				}
				mMemberSelection = MEMBER_SELECTION_NONE;

				// this one matches only if two indices are specified. In case of one index, only the next matches
				int& firstIndexStart = accessorIndexMatches[2*2];
				int& firstIndexEnd = accessorIndexMatches[2*2+1];
				if ( firstIndexStart >= 0)
				{
					mMemberSelection = MEMBER_SELECTION_ONE_INDEX;
					bool failed = false;
					const char* bufferBegin = secondPart + firstIndexStart;
					mFirstIndex = (size_t)GeneratedSaxParser::Utils::toUint32(&bufferBegin, secondPart + firstIndexEnd, failed);
					if ( failed )
					{
						mIsValid = false;
						return;
					}
				}

				// this one matches if two indices or only index are specified. 
				int& secondIndexStart = accessorIndexMatches[2*3];
				int& secondIndexEnd = accessorIndexMatches[2*3+1];
				if ( secondIndexStart >= 0)
				{
					bool failed = false;
					const char* bufferBegin = secondPart + secondIndexStart;
					size_t index = (size_t)GeneratedSaxParser::Utils::toUint32(&bufferBegin, secondPart + secondIndexEnd, failed);
					
					mMemberSelection = MEMBER_SELECTION_TWO_INDICES;
					mSecondIndex = index;
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

	}

	//------------------------------
	String SidAddress::getSidAddressString() const
	{
		if ( !mIsValid )
			return String();

		std::ostringstream stream;
		stream << mId;
		SidList::const_iterator it = mSids.begin();
		for ( ; it != mSids.end(); ++it )
		{
			stream << "/" << *it;
		}
		switch ( mMemberSelection )
		{
		case MEMBER_SELECTION_NAME:
			stream << "." << mMemberSelectionName;
			break;
		case MEMBER_SELECTION_ONE_INDEX:
			stream << "(" << mFirstIndex << ")";
			break;
		case MEMBER_SELECTION_TWO_INDICES:
			stream << "(" << mFirstIndex << ")";
			stream << "(" << mSecondIndex<< ")";
			break;
		default:
			break;
		}

		return stream.str();
	}
} // namespace COLLADASaxFWL
