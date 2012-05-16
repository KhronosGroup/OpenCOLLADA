/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsBitSet.h"


namespace DAE23ds
{

    //------------------------------
	BitSet::BitSet( size_t bitCount ) 
		: mBuffer( new char[(bitCount - 1) / sizeof(char) + 1] )
		, mBitCount( bitCount )
	{

	}

	//------------------------------
	BitSet::BitSet( size_t bitCount, bool defaultValue ) 
		: mBuffer( new char[(bitCount - 1) / sizeof(char) + 1] )
		, mBitCount( bitCount )
	{
		if ( defaultValue )
		{
			memset( mBuffer, 0xFF, (bitCount - 1) / sizeof(char) + 1);
		}
		else
		{
			memset( mBuffer, 0x00, (bitCount - 1) / sizeof(char) + 1);
		}
	}

	//------------------------------
	BitSet::~BitSet()
	{
		delete[] mBuffer;
	}

	//------------------------------
	void BitSet::setBit( size_t n, bool value )
	{
		assert( n < mBitCount );
		char& c = mBuffer[ n / sizeof(char) ];
		char bitInByte = (char)(n % sizeof(char));
		char bitMask = 1 << bitInByte;
		if ( value )
		{
			c |= bitMask;
		}
		else
		{
			c &= ~bitMask;
		}
	}

	//------------------------------
	bool BitSet::setBit( size_t n )
	{
		assert( n < mBitCount );
		char& c = mBuffer[ n / sizeof(char) ];
		char bitInByte = (char)(n % sizeof(char));
		char bitMask = 1 << bitInByte;
		return (c & bitMask) == bitMask;
	}

} // namespace DAE23ds
