/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_H__
#define __COLLADASTREAMWRITER_LIBRARY_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"

namespace COLLADASW
{

    /** Base class for all libraries*/
    class Library : public ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter the stream writer the library should be written to
        */
        Library ( StreamWriter* streamWriter, const String& name );

        /** Destructor*/
        virtual ~Library() {}

        /** Closes the @a \<library_geometry\> tag.
        This function should be called after the last geometry has been added*/
        void closeLibrary();

        /** Opens the library.
        This function must be called before the first geometry is added*/
        void openLibrary();

    private:
        TagCloser mLibraryCloser;    ///< Used to close the library  tag
        bool mLibraryOpen;      ///< true, if a library has been open and not closed. false otherwise.
        const String& mName;


    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_H__
