/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ILOADER_H__
#define __COLLADAFW_ILOADER_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{
	class IWriter;

	class ILoader 	
	{
	private:
	
	public:

        ILoader() {};
        virtual ~ILoader() {};

		/** Starts loading the model and feeds the writer with data.
		@param fileName The name of the file that should be loaded.
		@param writer The writer that should be fed with data.
		@return True, if loading succeeded, false otherwise.*/
		virtual bool loadDocument(const String& fileName, IWriter* writer)=0;

		/** Starts loading the model and feeds the writer with data.
         @param uri The URI associated with the buffer.
         @param buffer A pointer to a document buffer that should be loaded.
         @param length The length of the buffer in bytes.
         @param writer The writer that should be fed with data.
         @return True, if loading succeeded, false otherwise.*/
		virtual bool loadDocument(const String& uri, const char* buffer, int length, IWriter* writer)=0;
        
	private:

        /** Disable default copy ctor. */
		ILoader( const ILoader& pre );

        /** Disable default assignment operator. */
		const ILoader& operator= ( const ILoader& pre );

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_LOADER_H__
