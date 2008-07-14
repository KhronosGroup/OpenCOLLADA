/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAStreamWriter.h"
#include "COLLADALibrary.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    Library::Library ( COLLADA::StreamWriter *streamWriter, const String &name )
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
