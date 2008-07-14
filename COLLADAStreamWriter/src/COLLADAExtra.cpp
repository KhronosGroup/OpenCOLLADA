/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAExtra.h"
#include "COLLADASWC.h"

namespace COLLADA
{
    //---------------------------------------------------------------
    void Extra::openExtra ( const String &extraId, const String &extraName, const String &extraType )
    {
        mExtraCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_EXTRA );

        if ( !extraId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, extraId );

        if ( !extraName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, extraName );

        if ( !extraType.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, extraType );
    }

    //---------------------------------------------------------------
    void Extra::closeExtra()
    {
        mExtraCloser.close();
    }

} //namespace COLLADA
