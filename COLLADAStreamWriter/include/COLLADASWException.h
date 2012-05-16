/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITEREXCEPTION_H__
#define __COLLADASTREAMWRITEREXCEPTION_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADABUException.h"


namespace COLLADASW
{

    /** Class that is throw by the stream writer classes if something goes wrong*/
    class StreamWriterException : public COLLADABU::Exception
    {

    public:

        /** Constructor. Creates an exception of unknown type with the given message. */
        StreamWriterException ( const String& message ) 
            : COLLADABU::Exception ( message )
        {}

        /** Constructor. Creates an exception of type @a type with the given message. */
        StreamWriterException ( Type exceptionType, const String& message ) 
            : COLLADABU::Exception ( exceptionType, message )
        {}

        /** Constructor. */
        StreamWriterException ( Type exceptionType, const String file, const long line, const String message )
            : COLLADABU::Exception ( exceptionType, file, line, message )
        {}

        /** Constructor. */
        StreamWriterException ( const String file, const long line, const String message )
            : COLLADABU::Exception ( file, line, message )
        {}

        /** Destructor. */
        virtual ~StreamWriterException () {}

        /** Print the massage in the standard error output. */
        void printMessage ()
        {
            std::cerr << "StreamWriterException: " << mMessage << std::endl;
        }

	};

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITEREXCEPTION_H__
