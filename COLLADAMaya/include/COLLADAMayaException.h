/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYAEXCEPTION_H__
#define __COLLADAMAYAEXCEPTION_H__

#include "COLLADAMayaPrerequisites.h"

namespace COLLADAMaya
{

    /** Class that is throw by the stream writer classes if something goes wrong*/
    class ColladaMayaException
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
		ColladaMayaException ( Type exceptionType, const String& message ) 
        : mExceptionType(exceptionType)
        , mMessage(message)
        {}

		/** Returns the type of the exception*/
		Type getType()const {return mExceptionType;}

		/** Returns the text, describing the exception.*/
		String getMessage()const {return mMessage;};
		

	};

} //namespace COLLADA


#endif //__COLLADAMAYAEXCEPTION_H__
