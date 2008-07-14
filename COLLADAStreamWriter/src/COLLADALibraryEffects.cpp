/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryEffects.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    LibraryEffects::LibraryEffects ( COLLADA::StreamWriter * streamWriter )
            : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_EFFECTS )
    {}


    //---------------------------------------------------------------
    void LibraryEffects::openEffect ( const String & id )
    {
        openLibrary();
        mCurrentEffectCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_EFFECT );

        if ( !id.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, id );
    }




    //---------------------------------------------------------------
    void LibraryEffects::closeEffect()
    {
        mCurrentEffectCloser.close();
    }

} //namespace COLLADA
