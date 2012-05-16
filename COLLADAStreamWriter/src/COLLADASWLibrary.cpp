/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    Library::Library ( COLLADASW::StreamWriter *streamWriter, const String &name )
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


} //namespace COLLADASW
