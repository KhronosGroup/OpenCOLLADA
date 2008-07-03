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
#include "COLLADALibraryVisualScenes.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    LibraryVisualScenes::LibraryVisualScenes ( COLLADA::StreamWriter * streamWriter )
            : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_VISUAL_SCENES )
    {}


    //---------------------------------------------------------------
    void LibraryVisualScenes::openVisualScene ( const String & id )
    {
        openLibrary();
        mCurrentVisualSceneCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_VISUAL_SCENE );

        if ( !id.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, id );
    }


    //---------------------------------------------------------------
    void LibraryVisualScenes::closeVisualScene()
    {
        mCurrentVisualSceneCloser.close();
    }

} //namespace COLLADA
