/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include <cstring>
#include "GeneratedSaxParserStackMemoryManager.h"

namespace GeneratedSaxParser
{
	//--------------------------------------------------------------------
	StackMemoryManager::StackMemoryManager(size_t stackSize)
		: mActiveFrame(0)
    {
        mFrames = new StackFrame[ MAX_NUM_OF_FRAMES ];
		mFrames[ mActiveFrame ] = StackFrame(stackSize, new char[stackSize]);
	}
	
	//--------------------------------------------------------------------
	StackMemoryManager::~StackMemoryManager()
	{
        for (size_t i=mActiveFrame+1; i>0; --i)
			delete[] mFrames[ i-1 ].mMemoryBlob;
        delete[] mFrames;
	}

	//--------------------------------------------------------------------
	void* StackMemoryManager::newObject( size_t objectSize )
	{
		size_t newDataPos = mFrames[ mActiveFrame ].mCurrentPosition;

		size_t newDataSizePos = mFrames[ mActiveFrame ].mCurrentPosition + objectSize;

        size_t newCurrentPos = newDataSizePos + sizeof(objectSize);
		while ( newCurrentPos > mFrames[ mActiveFrame ].mMaxMemoryBlob )
		{
            if (!allocateMoreMemory())
                return 0;

            newDataPos = mFrames[ mActiveFrame ].mCurrentPosition;
            newDataSizePos = mFrames[ mActiveFrame ].mCurrentPosition + objectSize;
            newCurrentPos = newDataSizePos + sizeof(objectSize);
		}

        // objectSize will be written at newDataSizePos
        mFrames[ mActiveFrame ].mCurrentPosition = newCurrentPos;

        writeNewObjectSize(newDataSizePos, objectSize);

        return mFrames[ mActiveFrame ].mMemoryBlob + newDataPos;
	}

    //--------------------------------------------------------------------
	void StackMemoryManager::deleteObject()
	{
        mFrames[ mActiveFrame ].mCurrentPosition -= ( getTopObjectSize() + sizeof(mFrames[ mActiveFrame ].mCurrentPosition) );
        while ( mFrames[ mActiveFrame ].mCurrentPosition == 0 && mActiveFrame != 0 )
        {
            delete[] mFrames[ mActiveFrame ].mMemoryBlob;
            mFrames[ mActiveFrame-- ].mMemoryBlob = 0;
        }
	}

    //-----------------------------------------------------------------
    size_t StackMemoryManager::getTopObjectSize()
    {
        return *(size_t*)(mFrames[ mActiveFrame ].mMemoryBlob + mFrames[ mActiveFrame ].mCurrentPosition - sizeof(mFrames[ mActiveFrame ].mCurrentPosition));
    }

    //-----------------------------------------------------------------
    void StackMemoryManager::writeNewObjectSize( size_t position, size_t size )
    {
        *((size_t*)(mFrames[ mActiveFrame ].mMemoryBlob + position)) = size;
    }

    //-----------------------------------------------------------------
    void* StackMemoryManager::growObject( size_t amount )
    {
        size_t currentSize = getTopObjectSize();
        size_t newSize = currentSize + amount;
        size_t oldCurrentPos = mFrames[ mActiveFrame ].mCurrentPosition;
        size_t newDataSizePos = (mFrames[ mActiveFrame ].mCurrentPosition + amount) - sizeof(newSize);
        size_t newCurrentPos = newDataSizePos + sizeof(newSize);
        if ( newCurrentPos > mFrames[ mActiveFrame ].mMaxMemoryBlob )
        {
            size_t numOfAllocs = 0;
            while ( newCurrentPos > mFrames[ mActiveFrame ].mMaxMemoryBlob )
            {
                if (!allocateMoreMemory())
                    return 0;
                newDataSizePos = mFrames[ mActiveFrame ].mCurrentPosition + newSize;
                newCurrentPos = newDataSizePos + sizeof(newSize);
                numOfAllocs++;
            }
            void* source = mFrames[ mActiveFrame-numOfAllocs ].mMemoryBlob + oldCurrentPos - currentSize - sizeof(currentSize);
            memcpy(mFrames[ mActiveFrame ].mMemoryBlob, source, currentSize);
            // delete last object in last frame
            mFrames[ mActiveFrame-numOfAllocs ].mCurrentPosition -= ( currentSize + sizeof(mFrames[ mActiveFrame-numOfAllocs ].mCurrentPosition) );
        }
        mFrames[ mActiveFrame ].mCurrentPosition = newCurrentPos;
        writeNewObjectSize(newDataSizePos, newSize);
        return top();
    }

    //-----------------------------------------------------------------
    void* StackMemoryManager::top()
    {
        return mFrames[ mActiveFrame ].mCurrentPosition != 0 ? 
            (void*)(mFrames[ mActiveFrame ].mMemoryBlob + mFrames[ mActiveFrame ].mCurrentPosition - getTopObjectSize() - sizeof(mFrames[ mActiveFrame ].mCurrentPosition))
            : 0;
    }

    //-----------------------------------------------------------------
    bool StackMemoryManager::allocateMoreMemory()
    {
        if ( mActiveFrame == MAX_NUM_OF_FRAMES-1 )
            return false;
        size_t sizeOfNewBlob = mFrames[ mActiveFrame ].mMaxMemoryBlob * SIZE_OF_NEW_FRAME_FACTOR;
        char* newMem = new char[sizeOfNewBlob];
        if (!newMem)
            return false;
        mFrames[ ++mActiveFrame ] = StackFrame(sizeOfNewBlob, newMem);
        return true;
    }

} // namespace GeneratedSaxParser
