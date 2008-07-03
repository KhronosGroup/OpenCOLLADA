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

#ifndef __COLLADASTREAMWRITER_EXTRA_H__
#define __COLLADASTREAMWRITER_EXTRA_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include <map>

namespace COLLADA
{

    /** A class to add an Asset to the stream.*/

    class Extra : public ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter The stream the asset should be written to.*/
        Extra ( StreamWriter* streamWriter ) : ElementWriter ( streamWriter ) {}

        /** Destructor*/
        virtual ~Extra() {}

        /** Opens the extra tag. */
        void openExtra ( const String &extraId="", const String &extraName="", const String &extraType="" );

        /** Closes the extra tag */
        void closeExtra();

    private:

        /** Used to close the current extra. */
        TagCloser mExtraCloser;
    };

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_EXTRA_H__
