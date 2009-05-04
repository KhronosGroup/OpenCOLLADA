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
		size_t mCurrentPosition;
		size_t mMaxMemoryBlob;
		char* mMemoryBlob;

	public:
		StackMemoryManager(size_t stackSize);

		~StackMemoryManager();

		void* newObject(size_t objectSize);

		void deleteObject();

        void growObject(size_t amount);

        /** Returns ptr to top object on stack or 0 when stack is empty. Object will not be removed. */
        void* top();

    protected:
        inline size_t getTopObjectSize();

        inline void writeNewObjectSize(size_t position, size_t size);

    private:
		/** Disable default copy ctor. */
		StackMemoryManager( const StackMemoryManager& pre );
		/** Disable default assignment operator. */
		const StackMemoryManager& operator= ( const StackMemoryManager& pre );

	};
} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_STACKMEMORYMANAGER_H__
