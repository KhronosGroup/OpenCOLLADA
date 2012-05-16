/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_BITSET_H__
#define __DAE23DS_BITSET_H__

#include "DAE23dsPrerequisites.h"


namespace DAE23ds
{

	/** Fixed size bit set.*/
	class BitSet 	
	{
	private:

		/** The buffer that contains the bits.*/
		char* mBuffer;

		/** The number of bits.*/
		size_t mBitCount;
	
	public:

        /** Constructor. 
		@param bitCount number of bits*/
		BitSet( size_t bitCount );

		/** Constructor. 
		@param bitCount number of bits
		@param defaultValue the value the bits should be set on construction*/
		BitSet( size_t bitCount, bool defaultValue );


		/** Destructor. */
		virtual ~BitSet();

		/** Sets the n'th bit. No check is performed if n is in [0...bitCount]*/
		void setBit( size_t n, bool value);

		/** Returns the n'th bit. No check is performed if n is in [0...bitCount]*/
		bool setBit( size_t n);

	private:

        /** Disable default copy ctor. */
		BitSet( const BitSet& pre );

        /** Disable default assignment operator. */
		const BitSet& operator= ( const BitSet& pre );

	};

} // namespace DAE23ds

#endif // __DAE23DS_BITSET_H__
