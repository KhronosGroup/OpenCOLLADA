/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryEffects.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    //--------------------------
    LibraryEffects::LibraryEffects ( COLLADASW::StreamWriter * streamWriter )
            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_EFFECTS )
    {}


    //--------------------------
    void LibraryEffects::openEffect ( const String & id )
    {
        openLibrary();
        mCurrentEffectCloser = mSW->openElement ( CSWC::CSW_ELEMENT_EFFECT );

        if ( !id.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, id );
    }

    //--------------------------
    void LibraryEffects::closeEffect()
    {
        mCurrentEffectCloser.close();
    }

    //--------------------------
    void LibraryEffects::addEffectProfile( EffectProfile& effectProfile )
    {
        effectProfile.openProfile ();
        effectProfile.addProfileElements ();
        effectProfile.closeProfile ();
    }

} //namespace COLLADASW
