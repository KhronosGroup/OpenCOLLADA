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

#ifndef __COLLADASTREAMWRITER_LIBRARY_H__
#define __COLLADASTREAMWRITER_LIBRARY_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"

namespace COLLADA
{

    /** Base class for all libraries*/

    class Library : public ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter the stream writer the library should be written to
        */
        Library ( StreamWriter * streamWriter, const String & name );

        /** Destructor*/
        virtual ~Library() {}


    protected:
        /** Closes the @a \<library_geometry\> tag.
        This function should be called after the last geometry has been added*/
        void closeLibrary();

        /** Opens the library.
        This function must be called before the first geometry is added*/
        void openLibrary();

    private:
        TagCloser mLibraryCloser;    ///< Used to close the library  tag
        bool mLibraryOpen;      ///< true, if a library has been open and not closed. false otherwise.
        const String & mName;


    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_H__
