/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_EXTRADATA_H__
#define __COLLADAFW_EXTRADATA_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWPointerArray.h"


namespace COLLADAFW
{


	/** Key value pair used to store extra data.*/
	class  ExtraDataPair
	{
	private:
		/** The key, used to identify the extra data.*/
		String mKey;
		/** The value of the extra data.*/
		String mValue;

	public:
		/** Ctor.*/
		ExtraDataPair( const String& mKey, const String& mValue);

		/** Returns the key of the extra data.*/
		const String& getKey() const { return mKey; }

		/** Sets the key of the extra data.*/
		void setKey( const String& key) { mKey = key; }

		/** Returns the value of the extra data.*/
		const String& getValue() const { return mValue; }

		/** Sets the value of the extra data.*/
		void setValue( const String& value) { mValue = value; }

		ExtraDataPair* clone() { return FW_NEW ExtraDataPair( *this ); }
	};

	typedef PointerArray<ExtraDataPair> ExtraDataArray;


    /** Base class for all framework classes that can contain extra data. */
	class ExtraData 	
	{
	private:
		/** List of the extra data key value pairs.*/
		ExtraDataArray mExtraDataArray; 

	public:

        /** Constructor. */
		ExtraData();

        /** Destructor. */
		virtual ~ExtraData();

		/** Returns the list of the extra data key value pairs.*/
		const ExtraDataArray& getExtraDataArray() const { return mExtraDataArray; }

		/** Returns the list of the extra data key value pairs.*/
		ExtraDataArray& getExtraDataArray() { return mExtraDataArray; }

		/** Appends all the extra data pairs in @a extraDataArray to the extra data array.*/
		void appendExtraData(const ExtraDataArray& extraDataArray);

		/** Appends all the extra data pairs in @a extraData to the extra data array.*/
		void appendExtraData(const ExtraData& extraData);


	};

} // namespace COLLADAFW

#endif // __COLLADAFW_EXTRADATA_H__
