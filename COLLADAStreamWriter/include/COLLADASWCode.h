/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_CODE_H__
#define __COLLADASTREAMWRITER_CODE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWStreamWriter.h"

namespace COLLADASW
{
    
    /** Provides an inline block of source code.
    Source code can be inlined into the <effect> declaration to be used 
    to compile shaders.
    Parent elements:
    technique (FX) (in profile_CG, profile_GLSL), generator, profile_CG,
    profile_GLSL
    */
    class Code
    {

    public:
        
        /** Constructor. */
        Code () {}

        /** Destructor. */
        virtual ~Code () {}

        /** Provides an inline block of source code.
         Source code can be inlined into the <effect> declaration to be used 
         to compile shaders.
         @code The code block to show.
         @param sidNC A text string value containing the subidentifier of this 
                    element. This value must be unique within the scope of the 
                    parent element. An identifier for the source code to allow 
                    the block to be locally referenced by other elements. Optional.
         */
        void addCode ( StreamWriter *sw, const String& code, const String &sidNC = "" ) const
        {
            sw->openElement ( CSWC::CSW_ELEMENT_INCLUDE );

            if ( !sidNC.empty() )
                sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sidNC );

            sw->appendValues ( code );

            sw->closeElement();
        }

    };

}

#endif // __COLLADASTREAMWRITER_CODE_H__
