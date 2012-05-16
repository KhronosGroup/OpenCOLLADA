/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryMaterials.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    const String LibraryMaterials::MATERIAL_ID_SUFFIX = "-material";


    //-------------------------------------
    LibraryMaterials::LibraryMaterials ( COLLADASW::StreamWriter* streamWriter )
            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_MATERIALS )
    {}

    //-------------------------------------
    void LibraryMaterials::addInstanceEffect( const URI &effectURL )
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_EFFECT );
        mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, effectURL );
        mSW->closeElement();
    }

    //-------------------------------------
    void LibraryMaterials::openMaterial( 
        const String& materialId /*= EMPTY_STRING */, 
        const String& materialName /*= EMPTY_STRING */ )
    {
        openLibrary();

        mMaterialCloser = mSW->openElement ( CSWC::CSW_ELEMENT_MATERIAL );

        if ( !materialId.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, materialId );

        if ( !materialName.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, materialName );
    }

    //-------------------------------------
    void LibraryMaterials::closeMaterial()
    {
        mMaterialCloser.close();
    }
} //namespace COLLADASW
