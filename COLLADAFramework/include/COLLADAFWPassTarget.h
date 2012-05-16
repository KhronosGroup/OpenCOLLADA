/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_COLORTARGET_H__
#define __COLLADAFW_COLORTARGET_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWPassOutput.h"


namespace COLLADAFW
{

    /** 
    Specifies which <surface> will receive the color information from the output of this pass.
    
    Multiple Render Targets (MRTs) allow fragment shaders to output more than one value per pass, 
    or to redirect the standard depth and stencil units to read from and write to arbitrary 
    offscreen buffers. These elements tell the FX Runtime which previously defined surfaces to use.

    The <color_target> element has no attributes in GLES scope.
    */
    class PassTarget : public PassOutput
    {
    public:

        enum Face
        {
            POSITIVE_X, 
            NEGATIVE_X, 
            POSITIVE_Y, 
            NEGATIVE_Y,
            POSITIVE_Z,
            NEGATIVE_Z
        };

	private:
	
        /** Indexes a subimage inside a target <surface>, including a single MIP-map level, a 
        unique cube face, or a layer of a 3-D texture. The default is 0. Optional. */
        unsigned int mSlice;

        /** The default is 0. Optional. */
        unsigned int mMip;

        /** Valid values are 
        POSITIVE_X, NEGATIVE_X, POSITIVE_Y, NEGATIVE_Y, POSITIVE_Z, and NEGATIVE_Z. 
        The default is POSITIVE_X. Optional. */
        unsigned int mFace;

        /** The color target value. */
        String mTarget;

	public:

        /** Constructor. */
        PassTarget( PassOutput::OutputType outputType ) 
            : PassOutput ( outputType )
            , mFace ( POSITIVE_X ) 
        {}

        /** Destructor. */
        virtual ~PassTarget() {}

        /** Indexes a subimage inside a target <surface>, including a single MIP-map level, a 
        unique cube face, or a layer of a 3-D texture. The default is 0. Optional. */
        const unsigned int getSlice () const { return mSlice; }

        /** Indexes a subimage inside a target <surface>, including a single MIP-map level, a 
        unique cube face, or a layer of a 3-D texture. The default is 0. Optional. */
        void setSlice ( const unsigned int Slice ) { mSlice = Slice; }

        /** The default is 0. Optional. */
        const unsigned int getMip () const { return mMip; }

        /** The default is 0. Optional. */
        void setMip ( const unsigned int Mip ) { mMip = Mip; }

        /** Valid values are 
        POSITIVE_X, NEGATIVE_X, POSITIVE_Y, NEGATIVE_Y, POSITIVE_Z, and NEGATIVE_Z. 
        The default is POSITIVE_X. Optional. */
        const unsigned int getFace () const { return mFace; }

        /** Valid values are 
        POSITIVE_X, NEGATIVE_X, POSITIVE_Y, NEGATIVE_Y, POSITIVE_Z, and NEGATIVE_Z. 
        The default is POSITIVE_X. Optional. */
        void setFace ( const unsigned int Face ) { mFace = Face; }

        /** The color target value. */
        const String getTarget () const { return mTarget; }

        /** The color target value. */
        void setTarget ( const String Target ) { mTarget = Target; }

	private:

        /** Disable default copy ctor. */
		PassTarget( const PassTarget& pre );

        /** Disable default assignment operator. */
		const PassTarget& operator= ( const PassTarget& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_COLORTARGET_H__
