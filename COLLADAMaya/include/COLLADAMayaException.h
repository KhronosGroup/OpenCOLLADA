/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

#include "COLLADABUException.h"


namespace COLLADAMaya
{

    /** Class that is throw by the stream writer classes if something goes wrong*/
    class ColladaMayaException : public COLLADABU::Exception
    {

	public:

        /** Constructor. Creates an exception of unknown type with the given message. */
        ColladaMayaException ( const String& message ) 
            : COLLADABU::Exception ( message )
        {}

        /** Constructor. Creates an exception of type @a type with the given message. */
        ColladaMayaException ( Type exceptionType, const String& message ) 
            : COLLADABU::Exception ( exceptionType, message )
        {}

        /** Constructor. */
        ColladaMayaException ( Type exceptionType, const String file, const long line, const String message )
            : COLLADABU::Exception ( exceptionType, file, line, message )
        {}

        /** Constructor. */
        ColladaMayaException ( const String file, const long line, const String message )
            : COLLADABU::Exception ( file, line, message )
        {}

        /** Destructor. */
        virtual ~ColladaMayaException () {}

        /** Print the massage in the standard error output. */
        void printMessage ()
        {
            std::cerr << "ColladaMayaException: " << mMessage << std::endl;
        }

	};

} //namespace COLLADA


#endif //__COLLADAMAYAEXCEPTION_H__
