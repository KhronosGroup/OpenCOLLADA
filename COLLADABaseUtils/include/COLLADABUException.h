/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADABaseUtils.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_EXCEPTION_H__
#define __COLLADABU_EXCEPTION_H__

#include "COLLADABUPrerequisites.h"


namespace COLLADABU
{

    /** Class that is throw by the stream writer classes if something goes wrong*/
    class BaseUtilsException
    {

	public:
		enum Type
		{
			ERROR_FILE_OPEN,
			ERROR_SET_BUFFER,
			ERROR_UTF8_2_WIDE,
			ERROR_WIDE_2_UTF8,
			ERROR_NATIVE_2_WIDE,
			ERROR_WIDE_2_NATIVE
		};

	private:
		Type mExceptionType;
		String mMessage;

    public:
        /** Creates an exception of type @a type*/
		BaseUtilsException ( Type exceptionType, const String& message ) 
        : mExceptionType(exceptionType)
        , mMessage(message)
        {}

		/** Returns the type of the exception*/
		Type getType()const {return mExceptionType;}

		/** Returns the text, describing the exception.*/
		String getMessage()const {return mMessage;};
		

	};

} //namespace COLLADABU


#endif //__COLLADABU_EXCEPTION_H__
