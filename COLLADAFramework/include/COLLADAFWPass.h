/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_PASS_H__
#define __COLLADAFW_PASS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWPassTarget.h"
#include "COLLADAFWPassClear.h"
#include "COLLADAFWRenderDraw.h"
#include "COLLADAFWRenderState.h"
#include "COLLADAFWShader.h"


namespace COLLADAFW
{

    /** 
    Provides a static declaration of all the render states, shaders, and settings for one 
    rendering pipeline.
    <pass> describes all the render states and shaders for a rendering pipeline, and is the element 
    that the FX Runtime is asked to "apply" to the current graphics state before the program can 
    submit geometry.
    A static declaration is one that requires no evaluation by a scripting engine or runtime 
    system in order to be applied to the graphics state. At the time that a <pass> is applied, 
    all render state settings and uniform parameters are precalculated and known.
    */
	class Pass 	
    {
	private:
	
        /** The optional label for this pass, allowing passes to be specified by name and, if
        desired, reordered by the application as the technique is evaluated. Optional. */
        String mSid;

        /** Adds a strongly typed annotation remark to the parent object. No or one occurance. */
        Annotate mAnnotate;

        /** Specifies which <surface> will receive the color information from the output of this 
        pass. No or one occurance. */
        PassTarget mColorTarget;

        /** Specifies which <surface> will receive the depth information from the output of this 
        pass. No or one occurence. */
        PassTarget mDepthTarget;

        /** Specifies which <surface> will receive the stencil information from the output of this 
        pass. No or one occurence. */
        PassTarget mStencilTarget;

        /** Specifies whether a render target surface is to be cleared, and which value to use. 
        No or one occurence. */
        PassColorClear mColorClear;

        /** Specifies whether a render target surface is to be cleared, and which value to use. 
        No or one occurence. */
        PassDepthClear mDepthClear;

        /** Specifies whether a render target surface is to be cleared, and which value to use. 
        No or one occurence. */
        PassStencilClear mStencilClear;

        /** Instructs the FX Runtime what kind of geometry to submit. No or one occurence. */
        RenderDraw mDraw;

        /** Different FX profiles have different sets of render states available for use within 
        the <pass> element. */
        RenderState mRenderStates;

        /** Declares and prepares a shader for execution in the rendering pipeline of a <pass>. */
        Array<Shader> mShaderArray;

        /** Provides arbitrary additional information about or related to its parent element. */
//        Array<Extra> mExtraArray;

	public:

        /** Constructor. */
        Pass() 
            : mColorTarget ( PassOutput::OUTPUT_TYPE_COLOR )
            , mDepthTarget ( PassOutput::OUTPUT_TYPE_DEPTH )
            , mStencilTarget ( PassOutput::OUTPUT_TYPE_STENCIL )
        {}

        /** Destructor. */
		virtual ~Pass();

	private:

        /** Disable default copy ctor. */
		Pass( const Pass& pre );

        /** Disable default assignment operator. */
		const Pass& operator= ( const Pass& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_PASS_H__
