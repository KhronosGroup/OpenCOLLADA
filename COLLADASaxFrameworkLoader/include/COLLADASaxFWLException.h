/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_EXCEPTION_H__
#define __COLLADASAXFWL_EXCEPTION_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADABUException.h"


namespace COLLADASaxFWL
{

    /** Class that is throw by the stream writer classes if something goes wrong*/
    class ColladaSaxFrameworkLoaderException : public COLLADABU::Exception
    {

	public:

        /** Constructor. Creates an exception of unknown type with the given message. */
        ColladaSaxFrameworkLoaderException ( const String& message ) 
            : COLLADABU::Exception ( message )
        {}

        /** Constructor. Creates an exception of type @a type with the given message. */
        ColladaSaxFrameworkLoaderException ( Type exceptionType, const String& message ) 
            : COLLADABU::Exception ( exceptionType, message )
        {}

        /** Constructor. */
        ColladaSaxFrameworkLoaderException ( Type exceptionType, const String file, const long line, const String message )
            : COLLADABU::Exception ( exceptionType, file, line, message )
        {}

        /** Constructor. */
        ColladaSaxFrameworkLoaderException ( const String file, const long line, const String message )
            : COLLADABU::Exception ( file, line, message )
        {}

        /** Destructor. */
        virtual ~ColladaSaxFrameworkLoaderException () {}

        /** Print the massage in the standard error output. */
        void printMessage ()
        {
            std::cerr << "ColladaSaxFrameworkLoaderException: " << mMessage << std::endl;
        }

	};

} //namespace COLLADASaxFWL


#endif //__COLLADASAXFWL_EXCEPTION_H__
