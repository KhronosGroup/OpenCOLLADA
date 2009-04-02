/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SIDADDRESS_H__
#define __COLLADASAXFWL_SIDADDRESS_H__

#include "COLLADASaxFWLPrerequisites.h"


namespace COLLADASaxFWL
{

    /** Represents the  address of an sid. */
	class SidAddress 	
	{
	public:
		typedef std::vector<String/*sid*/> SidList;
		
		enum MemberSelection
		{
			MEMBER_SELECTION_NONE,			//!< No member is selected, all values are targeted
			MEMBER_SELECTION_NAME,			//!< A member is selected by name, evaluate mMemberSelection
			MEMBER_SELECTION_ONE_INDEX,		//!< A member is selected by an index, evaluate mFirstIndex
			MEMBER_SELECTION_TWO_INDICES	//!< A member is selected by two indices, evaluate mFirstIndex and mSecondIndex
		};
	private:
		/** The id of the starting point. Empty, if address is relative.*/
		String mId;

		/** List of all the sid in the address, starting with the first.*/
		SidList mSids;

		/** Defines the method of member selection.*/
		MemberSelection mMemberSelection;

		/** The name of the member selection.*/
		String mMemberSelectionName;

		/** The first index of a matrix.*/
		size_t mFirstIndex;

		/** The second index of a matrix.*/
		size_t mSecondIndex;

		/** True, if the address is a valid sid address, false otherwise.*/
		bool mIsValid;
	
	public:

        /** Constructor. */
		SidAddress( const String& sidAddress );

        /** Destructor. */
		virtual ~SidAddress();

		/** The id of the starting point. Empty, if address is relative.*/
		const String& getId() const { return mId; }

		/** List of all the sid in the address, starting with the first.*/
		const SidList& getSids() const { return mSids; }

		/** Defines the method of member selection.*/
		MemberSelection getMemberSelection() const { return mMemberSelection; }

		/** The name of the member selection.*/
		const String& getMemberSelectionName() const { return mMemberSelectionName; }
		
		/** The first index of a matrix.*/
		size_t getFirstIndex() const { return mFirstIndex; }

		/** The second index of a matrix.*/
		size_t getSecondIndex() const { return mSecondIndex; }

		/** True, if the address is a valid sid address, false otherwise.*/
		bool isValid() const { return mIsValid; }


	private:

		void parseAddress( const String& sidAddress);

		static String nextToken(  /*out*/ char& separator,  /*in out*/ size_t& startPos, const String& string);

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_SIDADDRESS_H__
