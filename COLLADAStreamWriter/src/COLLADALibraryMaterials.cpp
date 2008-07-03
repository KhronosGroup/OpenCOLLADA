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
#include "COLLADALibraryMaterials.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    const String LibraryMaterials::MATERIAL_ID_SUFFIX = "-material";


    //---------------------------------------------------------------
    LibraryMaterials::LibraryMaterials ( COLLADA::StreamWriter * streamWriter )
            : Library ( streamWriter,CSWC::COLLADA_ELEMENT_LIBRARY_MATERIALS )
    {}


    //---------------------------------------------------------------
    void LibraryMaterials::addInstanceEffect ( const String & effectURL, const String & materialId, const String & materialName )
    {
        openLibrary();
        mSW->openElement ( CSWC::COLLADA_ELEMENT_MATERIAL );

        if ( !materialId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, materialId );

        if ( !materialName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, materialName );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_EFFECT );

        if ( !effectURL.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, effectURL );

        mSW->closeElement();

        mSW->closeElement();
    }


} //namespace COLLADA
