/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_PASSCLEAR_H__
#define __COLLADAFW_PASSCLEAR_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWColor.h"


namespace COLLADAFW
{

    /** 
    Specifies whether a render target surface is to be cleared, and which value to use.
    Before drawing, render target surfaces may need to be reset to a blank canvas or default. The
    <color_clear> declarations specify which value to use. If no clearing statement is included, 
    the target surface is unchanged as rendering begins.
    
    This element contains four float values representing the red, green, blue, and alpha channels.
    When this element exists inside a pass, it a cue to the runtime that a particular backbuffer or 
    render-target resource should be cleared. This means that all existing image data in the 
    resource should be replaced with the color provided. This element puts the resource into a fresh 
    and known state so that other operations that use this resource execute as expected.
    The index attribute identifies the resource that you want to clear. An index of 0 identifies the 
    primary resource. The primary resource may be the backbuffer or the override provided with an 
    appropriate <*_target> element (<color_target>, <depth_target>, or <stencil_target>).
    Current platforms have fairly restrictive rules for setting up multiple render targets (MRTs). 
    For example, MRTs can have only four color buffers, which must all be the same size and pixel 
    format, one depth buffer, and one stencil buffer active for all color buffers. The COLLADA FX 
    declaration is designed to be looser in its restrictions, so an FX runtime must validate that a 
    particular MRT declaration in a <pass> is possible before attempting to apply it, and flag it as 
    an error if it fails.
    */
    class PassColorClear : public PassOutput
    {
	private:
	
        /** The color value. */
        Color mColor;

	public:

        /** Constructor. */
        PassColorClear () 
            : PassOutput ( PassOutput::OUTPUT_TYPE_COLOR )
            , mColor ( 0.0f, 0.0f, 0.0f, 0.0f )
        {}

        /** Constructor. */
        PassColorClear ( float red, float green, float blue, float alpha ) 
            : PassOutput ( PassOutput::OUTPUT_TYPE_COLOR )
            , mColor ( red, green, blue, alpha )
        {}

        /** Destructor. */
		virtual ~PassColorClear();

        /** The color value. */
        const Color getColor () const { return mColor; }

        /** The color value. */
        void setColor ( const Color Color ) { mColor = Color; }

	private:

        /** Disable default copy ctor. */
		PassColorClear( const PassColorClear& pre );

        /** Disable default assignment operator. */
		const PassColorClear& operator= ( const PassColorClear& pre );

	};

    /** 
    Specifies whether a render target surface is to be cleared, and which value to use.

    Before drawing, render target surfaces may need resetting to a blank canvas or to a default. 
    These <depth_clear> declarations specify which value to use. If no clearing statement is 
    included, the target surface is unchanged as rendering begins.

    This element contains a single float value that is used to clear a resource.
    When this element exists inside a pass, it a cue to the runtime that a particular backbuffer or 
    render-target resource should be cleared. This means that all existing image data in the 
    resource should be replaced with the float value provided. This puts the resource into a fresh 
    and known state so that other operations with this resource execute as expected.
    The index attribute identifies the resource that you want to clear. An index of 0 identifies 
    the primary resource. The primary resource may be the backbuffer or the override provided with 
    an appropriate <*_target> element (<color_target>, <depth_target>, or <stencil_target>)
    Current platforms have fairly restrictive rules for setting up MRTs; for example, MRTs can have 
    only four color buffers, which must be all of the same size and pixel format, and only one depth 
    buffer and one stencil buffer active for all color buffers. The COLLADA FX declaration is 
    designed to be looser in its restrictions, so an FX runtime must validate that a particular MRT 
    declaration in a <pass> is possible before attempting to apply it, and flag it as an error if it 
    fails.
    */
    class PassDepthClear : public PassOutput
    {
    private:

        float mResource;

    public:

        /** Constructor. */
        PassDepthClear() 
            : PassOutput ( PassOutput::OUTPUT_TYPE_DEPTH )
            , mResource (0.0f) 
        {}

        /** Constructor. */
        PassDepthClear( float resource ) 
            : PassOutput ( PassOutput::OUTPUT_TYPE_DEPTH )
            , mResource ( resource ) 
        {}

        /** Destructor. */
        virtual ~PassDepthClear();

        const float getResource () const { return mResource; }
        void setResource ( const float Resource ) { mResource = Resource; }

    private:

        /** Disable default copy ctor. */
        PassDepthClear( const PassDepthClear& pre );

        /** Disable default assignment operator. */
        const PassDepthClear& operator= ( const PassDepthClear& pre );

    };

    /** 
    Specifies whether a render target surface is to be cleared, and which value to use.
    
    Before drawing, render target surfaces may need resetting to a blank canvas or default. These
    <stencil_clear> declarations specify which value to use. If no clearing statement is included, 
    the target surface will be unchanged as rendering begins.
    
    This element contains an xs:byte that is the value used to clear a resource.
    When this element exists inside a pass, it a cue to the runtime that a particular backbuffer or 
    render-target resource should be cleared. This means that all existing image data in the 
    resource should be replaced with the value provided. This puts the resource into a fresh and 
    known state so that other operations with this resource execute as expected.
    The index attribute identifies the resource that you want to clear. An index of 0 identifies the 
    primary resource. The primary resource may be the backbuffer or the override provided with an 
    appropriate <*_target> element (<color_target>, <depth_target>, or <stencil_target>).
    Current platforms have fairly restrictive rules for setting up MRTs; for example, only four 
    color buffers, which must be all of the same size and pixel format, and only one depth buffer 
    and one stencil buffer active for all color buffers. The COLLADA FX declaration is designed to 
    be looser in its restrictions, so an FX runtime must validate that a particular MRT declaration 
    in a <pass> is possible before attempting to apply it, and flag it as an error if it fails.
    */
    class PassStencilClear : public PassOutput
    {
    private:

        unsigned char mClearValue;

    public:

        /** Constructor. */
        PassStencilClear() 
            : PassOutput ( PassOutput::OUTPUT_TYPE_STENCIL )
            , mClearValue (0) 
        {}

        /** Constructor. */
        PassStencilClear( unsigned char clearValue ) 
            : PassOutput ( PassOutput::OUTPUT_TYPE_STENCIL )
            , mClearValue ( clearValue ) 
        {}

        /** Destructor. */
        virtual ~PassStencilClear();

        const unsigned char getClearValue () const { return mClearValue; }
        void setClearValue ( const unsigned char ClearValue ) { mClearValue = ClearValue; }

    private:

        /** Disable default copy ctor. */
        PassStencilClear( const PassStencilClear& pre );

        /** Disable default assignment operator. */
        const PassStencilClear& operator= ( const PassStencilClear& pre );

    };

} // namespace COLLADAFW

#endif // __COLLADAFW_PASSCLEAR_H__
