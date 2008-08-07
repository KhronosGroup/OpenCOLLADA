/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_LIGHTS_H__
#define __COLLADASTREAMWRITER_LIBRARY_LIGHTS_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADALibrary.h"
#include "COLLADALight.h"

namespace COLLADA
{

    /** Class to simply the creation of @a \<library_lights\> and @a \<lights\>'s*/
    class LibraryLights : public Library, public BaseExtraTechnique
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_lights\> and @a \<lights\>'s
        should be written to.
        */
        LibraryLights ( StreamWriter* streamWriter );

        /** Destructor*/
        virtual ~LibraryLights() {}

    protected:
        /** Adds @a \<light\> element. If not already opened, it opens @a \<library_lights\>*/
        void addLight ( const Light& light );

    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_LIGHTS_H__