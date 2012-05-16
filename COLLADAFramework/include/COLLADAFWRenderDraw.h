/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_RENDERDRAW_H__
#define __COLLADAFW_RENDERDRAW_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** 
    Instructs the FX Runtime what kind of geometry to submit.
    
    When executing multipass techniques, each pass may require different types of geometry to be submitted.
    One pass may require a model to be submitted, another pass may need a full screen quad to exercise a
    fragment shader over each pixel in an offscreen buffer, while another pass may need only front-facing
    polygons. <draw> declares a user-defined string that can be used as a semantic describing to the FX
    Runtime what geometry is expected for this pass.
    
    The <draw> element contains an xs:string. The following list includes common strings to use in
    <draw>, although you are not limited to only these strings:
    • GEOMETRY: The geometry associated with this <instance_geometry> or <instance_material>.
    • SCENE_GEOMETRY: Draw the entire scene’s geometry but with this effect, not the effects or
    materials already associated with the geometry. This is for techniques such as shadow-buffer
    generation, where you might be interested only in extracting the Z value from the light. This is
    without regard to ordering on the assumption that ZBuffer handles order.
    • SCENE_IMAGE: Draw the entire scene into my targets. Use the appropriate effects or materials for
    each object. This is for effects that need an accurate image of the scene to work on for effects such
    as postprocessing blurs. This is without regard to ordering on the assumption that ZBuffer handles
    order.
    • FULL_SCREEN_QUAD: Positions are 0,0 to 1,1 and the UVs match.
    • FULL_SCREEN_QUAD_PLUS_HALF_PIXEL: Positions are 0,0 to 1,1 and the UVs are off by plus ½
    of a pixel’s UV size.
    */
	class RenderDraw 	
    {
	private:
	
        /** A user-defined string that can be used as a semantic describing to the FX
        Runtime what geometry is expected for this pass. */
        String mExpectedGeometry;

	public:

        /** Constructor. */
		RenderDraw();

        /** Destructor. */
		virtual ~RenderDraw();

        /** A user-defined string that can be used as a semantic describing to the FX
        Runtime what geometry is expected for this pass. */
        const String getExpectedGeometry () const { return mExpectedGeometry; }

        /** A user-defined string that can be used as a semantic describing to the FX
        Runtime what geometry is expected for this pass. */
        void setExpectedGeometry ( const String& ExpectedGeometry ) { mExpectedGeometry = ExpectedGeometry; }

	private:

        /** Disable default copy ctor. */
		RenderDraw( const RenderDraw& pre );

        /** Disable default assignment operator. */
		const RenderDraw& operator= ( const RenderDraw& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_RENDERDRAW_H__
