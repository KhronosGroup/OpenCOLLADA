/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_PASS_H__
#define __COLLADASTREAMWRITER_PASS_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWSurfaceInitOption.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    /** 
    Provides a static declaration of all the render states, shaders, and 
    settings for one rendering pipeline. 
    <pass> describes all the render states and shaders for a rendering 
    pipeline, and is the element that the FX Runtime is asked to "apply" to the 
    current graphics state before the program can submit geometry.
    A static declaration is one that requires no evaluation by a scripting 
    engine or runtime system in order to be applied to the graphics state. At 
    the time that a <pass> is applied, all render state settings and uniform
    parameters are precalculated and known.
    */
    class Pass : public ElementWriter
    {

    private:

        TagCloser mPassCloser;

    public:

        /** Constructor. */
        Pass ( StreamWriter* sw );

        /** Destructor. */
        ~Pass () {}

        /** 
        Provides a static declaration of all the render states, shaders, and 
        settings for one rendering pipeline. 
        @param sid The optional label for this pass, allowing passes to be 
                    specified by name and, if desired, reordered by the 
                    application as the technique is evaluated. Optional.
        */
        void openPass ( const String &sid = "" );

        /** Close the current pass element. */
        void closePass ( );

        /** Specifies which <surface> will receive the color information from the output of this pass. */
        void addColorTarget ( 
            const String& val, 
            const int index=-1, 
            const int slice=-1, 
            const int mip=-1, 
            SurfaceInitOption::Face face = SurfaceInitOption::POSITIVE_X );

        /** Specifies which <surface> will receive the depth information from the output of this pass. */
        void addDepthTarget ( 
            const String& val, 
            const int index=-1, 
            const int slice=-1, 
            const int mip=-1, 
            SurfaceInitOption::Face face = SurfaceInitOption::POSITIVE_X );

        /** Specifies which <surface> will receive the stencil information from the output of this pass. */
        void addStencilTarget ( 
            const String& val, 
            const int index=-1, 
            const int slice=-1, 
            const int mip=-1, 
            SurfaceInitOption::Face face = SurfaceInitOption::POSITIVE_X );

        /** Specifies whether a render target surface is to be cleared, and which value to use. 
        @param index Which of the multiple render targets (MRTs) is being set. 
                        The default is 0. Optional. */
        void addColorClear ( const Color& val, unsigned int index=0 );

        /** Specifies which <surface> will receive the depth information from the output of this pass. 
        This element contains a single float value that is used to clear a resource. */
        void addDepthClear ( const float val, unsigned int index=0 );

        /** Specifies whether a render target surface is to be cleared, and which value to use. */
        void addStencilClear ( const unsigned char val, unsigned int index=0 );

        /** Instructs the FX Runtime what kind of geometry to submit. 
        The <draw> element contains an xs:string. The following list includes common strings to use in
        <draw>, although you are not limited to only these strings:
        � GEOMETRY: The geometry associated with this <instance_geometry> or
        <instance_material>.
        � SCENE_GEOMETRY: Draw the entire scene�s geometry but with this effect, not the effects or
        materials already associated with the geometry. This is for techniques such as shadow-buffer
        generation, where you might be interested only in extracting the Z value from the light. This is
        without regard to ordering on the assumption that ZBuffer handles order.
        � SCENE_IMAGE: Draw the entire scene into my targets. Use the appropriate effects or materials for
        each object. This is for effects that need an accurate image of the scene to work on for effects such
        as postprocessing blurs. This is without regard to ordering on the assumption that ZBuffer handles
        order.
        � FULL_SCREEN_QUAD: Positions are 0,0 to 1,1 and the UVs match.
        � FULL_SCREEN_QUAD_PLUS_HALF_PIXEL: Positions are 0,0 to 1,1 and the UVs are off by plus �
        of a pixel�s UV size. */
        void addDraw ( const String& draw );

    };
}

#endif // __COLLADASTREAMWRITER_PASS_H__
