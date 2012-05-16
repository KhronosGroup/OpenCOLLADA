/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_EXCEPTION_H__
#define __COLLADAFW_EXCEPTION_H__

#include "COLLADAFWPrerequisites.h"

#include "COLLADABUException.h"


namespace COLLADAFW
{

    /** Class that is throw by the stream writer classes if something goes wrong*/
    class FrameworkException : public COLLADABU::Exception
    {

	public:

        /** Constructor. Creates an exception of unknown type with the given message. */
        FrameworkException ( const String& message ) 
            : COLLADABU::Exception ( message )
        {}

        /** Constructor. Creates an exception of type @a type with the given message. */
        FrameworkException ( Type exceptionType, const String& message ) 
            : COLLADABU::Exception ( exceptionType, message )
        {}

        /** Constructor. */
        FrameworkException ( Type exceptionType, const String file, const long line, const String message )
            : COLLADABU::Exception ( exceptionType, file, line, message )
        {}

        /** Constructor. */
        FrameworkException ( const String file, const long line, const String message )
            : COLLADABU::Exception ( file, line, message )
        {}

        /** Destructor. */
        virtual ~FrameworkException () {}

        /** Print the massage in the standard error output. */
        void printMessage ()
        {
            std::cerr << "FrameworkException: " << mMessage << std::endl;
        }

	};

} //namespace COLLADAFW


#endif //__COLLADAFW_EXCEPTION_H__
