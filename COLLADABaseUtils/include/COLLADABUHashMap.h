/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_HASHMAP_H__
#define __COLLADABU_HASHMAP_H__

#include "COLLADABUPrerequisites.h"

#include <map>

namespace COLLADABU
{
	template<class KeyType, class ValueType, class HashType, HashType (*calculateHash)(const KeyType& key)>
	class HashMap 	
	{
	private:
		struct HashValuePair
		{
			HashValuePair(const HashType& _hash, const KeyType& _key ) : hash(_hash), key(_key){}
			HashType hash;
			KeyType key;
		
			bool operator<( const HashValuePair& rhs)const
			{
				if ( hash < rhs.hash )
					return true;

				if ( rhs.hash < hash  )
					return false;

				if ( key < rhs.key )
					return true;

				if ( rhs.key < key )
					return false;
				return false;
			}
		};


	private:

		typedef std::map<HashValuePair, ValueType> Map;

		Map mMap;


	public:
		class const_iterator;
		class iterator
		{
		private:
			typename Map::iterator mIt;
			friend class const_iterator;
		public:
			iterator(typename Map::iterator it):mIt(it){}
			KeyType& first() { return mIt->first.key; }
			ValueType& second() { return mIt->second; }

			bool operator==(iterator other)const { return mIt == other.mIt; }
			bool operator==(const_iterator other)const { return mIt == other.mIt; }
		};
	
	//	typedef const iterator const_iterator;

		class const_iterator
		{
		private:
			typename Map::const_iterator mIt;
			friend class iterator;
		public:
			const_iterator(typename  Map::const_iterator it):mIt(it){}
			const KeyType& first() const { return mIt->first.key; }
			const ValueType& second() const { return mIt->second; }
			bool operator==(const_iterator other)const { return mIt == other.mIt; }
			bool operator==(iterator other)const { return mIt == other.mIt; }
		};
	private:
	//	HashMap(){}
	//	virtual ~HashMap(){}
	public:

		ValueType& operator[](const KeyType& key);

		const ValueType& operator[](const KeyType& key)const;

		iterator find(const KeyType& key) {return iterator(mMap.find(HashValuePair(calculateHash(key), key)) ); }

		const_iterator find(const KeyType& key) const{return iterator(mMap.find(HashValuePair(calculateHash(key), key)) ); }

		const_iterator end()const { return const_iterator(mMap.end()); }

	};

	template<class KeyType, class ValueType, class HashType, HashType (*calculateHash)(const KeyType& key)>
	ValueType& HashMap<KeyType, ValueType, HashType, calculateHash>::operator[]( const KeyType& key )
	{
		return mMap[HashValuePair(calculateHash(key), key)];
	}


	template<class KeyType, class ValueType, class HashType, HashType (*calculateHash)(const KeyType& key)>
	const ValueType& COLLADABU::HashMap<KeyType, ValueType, HashType, calculateHash>::operator[]( const KeyType& key ) const
	{
		return mMap[HashValuePair(calculateHash(key), key)];
	}



} // namespace COLLADABU

#endif // __COLLADABU_HASHMAP_H__
