/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INCLUDE_H__
#define __COLLADASTREAMWRITER_INCLUDE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{
    
    /** Imports source code or precompiled binary shaders into the FX Runtime 
    by referencing an external resource.
    Parent elements:
    technique (FX) (in profile_CG, profile_GLSL), generator, profile_CG,
    profile_GLSL
    */
    class Include 
    {

    public:
        
        /** Constructor. */
        Include () {}

        /** Destructor. */
        virtual ~Include () {}

        /** Imports source code or precompiled binary shaders into the FX 
         Runtime by referencing an external resource.
         @param sidNC Identifier for this source code block or binary shader. Required.
         @param uri Location where the resource can be found. Required.
         */
        void addInclude ( StreamWriter *sw, const String &sidNC, const URI &uri ) const
        {
            sw->openElement ( CSWC::CSW_ELEMENT_INCLUDE );
            sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sidNC );
            sw->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, uri );
            sw->closeElement();
        }

    };

}

#endif // __COLLADASTREAMWRITER_INCLUDE_H__
