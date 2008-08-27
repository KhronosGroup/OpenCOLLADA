/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITEREXCEPTION_H__
#define __COLLADASTREAMWRITEREXCEPTION_H__

#include "COLLADAPrerequisites.h"

namespace COLLADA
{

    /** Class that is throw by the stream writer classes if something goes wrong*/
    class StreamWriterException
    {

	public:
		enum Type
		{
			ERROR_FILE_OPEN,
			ERROR_SET_BUFFER
		};

	private:
		Type mExceptionType;
		String mMessage;

    public:
        /** Creates an exception of type @a type*/
		StreamWriterException ( Type exceptionType, const String& message ) : mExceptionType(exceptionType), mMessage(message){}

		/** Returns the type of the exception*/
		Type getType()const {return mExceptionType;}

		/** Returns the text, describing the exception.*/
		String getMessage()const {return mMessage;};
		

	};

} //namespace COLLADA


#endif //__COLLADASTREAMWRITEREXCEPTION_H__
