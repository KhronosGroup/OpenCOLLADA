/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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
