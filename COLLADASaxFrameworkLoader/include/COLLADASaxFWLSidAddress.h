/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SIDADDRESS_H__
#define __COLLADASAXFWL_SIDADDRESS_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADABUURI.h"


namespace COLLADASaxFWL
{

    /** Represents the  address of an sid. */
	class SidAddress 	
	{
	public:
		typedef std::vector<String/*sid*/> SidList;
		
		enum MemberSelection
		{
			MEMBER_SELECTION_NONE,			//!< No member is selected, all values are targeted ("id/sid")
			MEMBER_SELECTION_NAME,			//!< A member is selected by name, evaluate mMemberSelection ("id/sid.name")
			MEMBER_SELECTION_ONE_INDEX,		//!< A member is selected by an index, evaluate mFirstIndex ("id/sid(0)")
			MEMBER_SELECTION_TWO_INDICES	//!< A member is selected by two indices, evaluate mFirstIndex and mSecondIndex ("id/sid(0)(3)")
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

		/** Constructor, invalid SidAddress. */
		SidAddress( );

		/** Constructor. */
		SidAddress( const String& sidAddress );

		/** Constructor. */
		SidAddress( const COLLADABU::URI& id, const String& sid);

		/** Constructor. */
		SidAddress( const COLLADABU::URI& id);

        /** Destructor. */
		virtual ~SidAddress();

		/** The id of the starting point. Empty, if address is relative.*/
		const String& getId() const { return mId; }

		/** List of all the sid in the address, starting with the first.*/
		const SidList& getSids() const { return mSids; }

		/** Appends @a sid to the list of sids.*/
		void appendSid( const String& sid) { mSids.push_back(sid); }

		/** Defines the method of member selection.*/
		MemberSelection getMemberSelection() const { return mMemberSelection; }

		/** Defines the method of member selection.*/
		void setMemberSelection( MemberSelection memberSelection ) { mMemberSelection = memberSelection; }

		/** The name of the member selection.*/
		const String& getMemberSelectionName() const { return mMemberSelectionName; }

		/** The name of the member selection.*/
		void setMemberSelectionName( const String& memberSelectionName) { mMemberSelectionName = memberSelectionName; }

		/** The first index of a matrix.*/
		size_t getFirstIndex() const { return mFirstIndex; }

		/** The first index of a matrix.*/
		void setFirstIndex( size_t firstIndex) { mFirstIndex = firstIndex; }

		/** The second index of a matrix.*/
		size_t getSecondIndex() const { return mSecondIndex; }

		/** The second index of a matrix.*/
		void setSecondIndex( size_t secondIndex) { mSecondIndex = secondIndex; }

		/** True, if the address is a valid sid address, false otherwise.*/
		bool isValid() const { return mIsValid; }

		/** Returns the sid address as a string.*/
		String getSidAddressString() const;


	private:

		void parseAddress( const String& sidAddress);

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_SIDADDRESS_H__
