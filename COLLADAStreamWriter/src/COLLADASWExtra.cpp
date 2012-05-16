/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWExtra.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{
    //---------------------------------------------------------------
    void Extra::openExtra ( const String &extraId, const String &extraName, const String &extraType )
    {
        mExtraCloser = mSW->openElement ( CSWC::CSW_ELEMENT_EXTRA );

        if ( !extraId.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, extraId );

        if ( !extraName.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, extraName );

        if ( !extraType.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_TYPE, extraType );
    }

    //---------------------------------------------------------------
    void Extra::closeExtra()
    {
        mExtraCloser.close();
    }

} //namespace COLLADASW
