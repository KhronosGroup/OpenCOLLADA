/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_ELEMENT_WRITER_H__
#define __COLLADASTREAMWRITER_ELEMENT_WRITER_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAStreamWriter.h"

namespace COLLADA
{
    /** The base class of all classes that write elements to the stream*/

    class ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter The stream writer that should be used to write to the stream*/
        ElementWriter ( StreamWriter * streamWriter ) : mSW ( streamWriter ) {}

        static const String EMPTY_STRING;

    protected:
        StreamWriter * mSW;


    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_ELEMENT_WRITER_H__
