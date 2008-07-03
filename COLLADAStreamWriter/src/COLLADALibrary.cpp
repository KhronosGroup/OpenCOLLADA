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

#include "COLLADAStreamWriter.h"
#include "COLLADALibrary.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    Library::Library ( COLLADA::StreamWriter * streamWriter, const String & name )
            : ElementWriter ( streamWriter ),
            mLibraryOpen ( false ),
            mName ( name )
    {}


    //---------------------------------------------------------------
    void Library::openLibrary()
    {
        if ( !mLibraryOpen )
        {
            mLibraryCloser = mSW->openElement ( mName );
            mLibraryOpen = true;
        }
    }


    //---------------------------------------------------------------
    void Library::closeLibrary()
    {
        if ( mLibraryOpen )
            mLibraryCloser.close();

        mLibraryOpen = false;
    }


} //namespace COLLADA
