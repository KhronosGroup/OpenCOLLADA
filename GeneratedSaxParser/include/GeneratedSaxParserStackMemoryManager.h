/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_STACKMEMORYMANAGER_H__
#define __GENERATEDSAXPARSER_STACKMEMORYMANAGER_H__

#include "GeneratedSaxParserPrerequisites.h"



namespace GeneratedSaxParser
{
	/** Memory manager that implements a stack.
		Memory fragmentation:
         ______________ _ ______________ _ ______________ _ 
		|              | |              | |              | |
		 -------------- - -------------- - -------------- - 
		     data0    size0   data1    size1   data2    size2
	*/
	class StackMemoryManager 
	{
	private:
        static const size_t MAX_NUM_OF_FRAMES = 12;
        static const size_t SIZE_OF_NEW_FRAME_FACTOR = 2;

        struct StackFrame
        {
            StackFrame() : mCurrentPosition(0), mMaxMemoryBlob(0), mMemoryBlob(0)
            {}
            StackFrame(size_t size, char* memoryBlob) :
                mCurrentPosition(0),
                mMaxMemoryBlob(size),
                mMemoryBlob(memoryBlob)
            {}
            /** 
             * Points at beginning of free space inside mMemoryBlob.
             * Or in other words: points after size of top object.
             */
		    size_t mCurrentPosition;
            /** Size of mMemoryBlob. */
		    size_t mMaxMemoryBlob;
            /** Pointer to allocated memory. */
		    char* mMemoryBlob;
        };
        size_t mActiveFrame;
        StackFrame* mFrames;

	public:
		StackMemoryManager(size_t stackSize);

		~StackMemoryManager();

		void* newObject(size_t objectSize);

		void deleteObject();

        void* growObject(size_t amount);

        /** Returns ptr to top object on stack or 0 when stack is empty. Object will not be removed. */
        void* top();

    protected:
        inline size_t getTopObjectSize();

        inline void writeNewObjectSize(size_t position, size_t size);

        bool allocateMoreMemory();

    private:
		/** Disable default copy ctor. */
		StackMemoryManager( const StackMemoryManager& pre );
		/** Disable default assignment operator. */
		const StackMemoryManager& operator= ( const StackMemoryManager& pre );

	};
} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_STACKMEMORYMANAGER_H__
