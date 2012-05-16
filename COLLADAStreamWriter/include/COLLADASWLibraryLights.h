/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_LIGHTS_H__
#define __COLLADASTREAMWRITER_LIBRARY_LIGHTS_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWLight.h"

namespace COLLADASW
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

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_LIGHTS_H__
