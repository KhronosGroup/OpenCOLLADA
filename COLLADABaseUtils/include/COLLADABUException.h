/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADABaseUtils.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_EXCEPTION_H__
#define __COLLADABU_EXCEPTION_H__

#include "COLLADABUPrerequisites.h"
#include "COLLADABUStableHeaders.h"

#include <iostream>


namespace COLLADABU
{

    /** Class that is thrown by the base utils classes if something goes wrong. */
    class Exception
    {

	public:

		enum Type
		{
            ERROR_TYPE_UNKNOWN, 
			ERROR_FILE_OPEN,
			ERROR_SET_BUFFER,
			ERROR_UTF8_2_WIDE,
			ERROR_WIDE_2_UTF8,
			ERROR_NATIVE_2_WIDE,
			ERROR_WIDE_2_NATIVE
		};

	protected:

        /** The type of the exception. */
		Type mExceptionType;

        /** The error message for output. */
        String mMessage;

    public:

        /** Constructor. Creates an exception of unknown type with the given message. */
        Exception ( const String& message ) 
            : mExceptionType ( ERROR_TYPE_UNKNOWN )
            , mMessage ( message )
        {}

        /** Constructor. Creates an exception of type @a type with the given message. */
		Exception ( Type exceptionType, const String& message ) 
        : mExceptionType ( exceptionType )
        , mMessage ( message )
        {}

        /** Constructor. */
        Exception ( Type exceptionType, const String file, const long line, const String message )
            : mExceptionType ( exceptionType )
        {
            std::ostringstream stream;
            stream << file << ":" << line << ": " << message;
            mMessage = stream.str ().c_str ();
        }

        /** Constructor. */
        Exception ( const String file, const long line, const String message )
            : mExceptionType ( ERROR_TYPE_UNKNOWN )
        {
            std::ostringstream stream;
            stream << file << ":" << line << ": " << message;
            mMessage = stream.str ().c_str ();
        }

        /** Destructor. */
        virtual ~Exception () {}

		/** Returns the type of the exception*/
		Type getType()const {return mExceptionType;}

		/** Returns the text, describing the exception.*/
		String getMessage()const {return mMessage;};
		
        /** Print the massage in the standard error output. */
        void printMessage ()
        {
            if ( mExceptionType == ERROR_TYPE_UNKNOWN )
                std::cerr << "MainException: " << mMessage << std::endl;
            else
                std::cerr << "MainException: " << mMessage << ", Error type " << mExceptionType << std::endl;
        }

        
	};

} //namespace COLLADABU


#endif //__COLLADABU_EXCEPTION_H__
