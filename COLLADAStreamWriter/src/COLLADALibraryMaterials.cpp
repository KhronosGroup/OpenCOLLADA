/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
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
            mSW->appendURLAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, effectURL );

        mSW->closeElement();

        mSW->closeElement();
    }


} //namespace COLLADA
