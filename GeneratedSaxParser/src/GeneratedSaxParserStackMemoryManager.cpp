/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "GeneratedSaxParserStackMemoryManager.h"

namespace GeneratedSaxParser
{
	//--------------------------------------------------------------------
	StackMemoryManager::StackMemoryManager(size_t stackSize)
		: mCurrentPosition(0),
		mMaxMemoryBlob(stackSize)
		
	{
		mMemoryBlob = new char[stackSize];
	}
	
	//--------------------------------------------------------------------
	StackMemoryManager::~StackMemoryManager()
	{
			delete[] mMemoryBlob;
	}

	//--------------------------------------------------------------------
	void* StackMemoryManager::newObject( size_t objectSize )
	{
		size_t newDataPos = mCurrentPosition;

		size_t newDataSizePos = mCurrentPosition + objectSize;

        // objectSize will be written at newDataSizePos
		mCurrentPosition = newDataSizePos + sizeof(objectSize);

		if (mCurrentPosition >= mMaxMemoryBlob)
		{
//			assert(false);
			//realloc();
		}

        writeNewObjectSize(newDataSizePos, objectSize);

        return mMemoryBlob + newDataPos;
	}

    //--------------------------------------------------------------------
	void StackMemoryManager::deleteObject()
	{
		//mCurrentPosition -=  ( (*((size_t*)mMemoryBlob[mCurrentPosition - 1])) + sizeof(mCurrentPosition));
		//mCurrentPosition -=  ( (*((size_t*)(mMemoryBlob + mCurrentPosition - sizeof(mCurrentPosition)) )) + sizeof(mCurrentPosition));
        mCurrentPosition -= ( getTopObjectSize() + sizeof(mCurrentPosition) );
	}

    //-----------------------------------------------------------------
    size_t StackMemoryManager::getTopObjectSize()
    {
        return *(size_t*)(mMemoryBlob + mCurrentPosition - sizeof(mCurrentPosition));
    }

    //-----------------------------------------------------------------
    void StackMemoryManager::writeNewObjectSize( size_t position, size_t size )
    {
        *((size_t*)(mMemoryBlob + position)) = size;
    }

    //-----------------------------------------------------------------
    void StackMemoryManager::growObject( size_t amount )
    {
        size_t currentSize = getTopObjectSize();
        size_t newSize = currentSize + amount;
        size_t newDataSizePos = (mCurrentPosition + amount) - sizeof(newSize);
        mCurrentPosition = newDataSizePos + sizeof(newSize);
        // TODO check if new size exceeds allocated memory !!!
        writeNewObjectSize(newDataSizePos, newSize);
    }

    //-----------------------------------------------------------------
    void* StackMemoryManager::top()
    {
        return mCurrentPosition != 0 ? (void*)(mMemoryBlob + mCurrentPosition - getTopObjectSize() - sizeof(mCurrentPosition)) : 0;
    }

} // namespace GeneratedSaxParser
