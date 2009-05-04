/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_SAMPLER_H__
#define __COLLADASTREAMWRITER_SAMPLER_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWConstants.h"
#include "COLLADASWColor.h"

namespace COLLADASW
{

    /** Declares the storage for the graphical representation of an object. */
    class Sampler : public BaseExtraTechnique
    {

    public:

        static const String SAMPLER_SID_SUFFIX;

    public:

        /** The different sampler types. */
        enum SamplerType
        {
            SAMPLER_TYPE_UNSPECIFIED, 
            SAMPLER_TYPE_1D, 
            SAMPLER_TYPE_2D, 
            SAMPLER_TYPE_3D, 
            SAMPLER_TYPE_CUBE, 
            SAMPLER_TYPE_RECT,
            SAMPLER_TYPE_DEPTH,
            SAMPLER_TYPE_STATE
        };

        /** Contains the texture filter functions.*/
        enum SamplerFilter
        {
            SAMPLER_FILTER_UNSPECIFIED,
            SAMPLER_FILTER_NONE,
            SAMPLER_FILTER_NEAREST,
            SAMPLER_FILTER_LINEAR,
            SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST,
            SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST,
            SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR,
            SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR
        };

        /** 
        Contains the texture wrap modes.
        Wrap modes that affect the interpretation of s, t, and p texture 
        coordinates in <sampler_*> elements. The wrap mode enums map to the 
        following OpenGL symbols.*/
        enum WrapMode
        {
            WRAP_MODE_UNSPECIFIED=0,
            // NONE == GL_CLAMP_TO BORDER The defined behavior for NONE is 
            // consistent with decal texturing where the border is black. 
            // Mapping this calculation to GL_CLAMP_TO_BORDER is the best 
            // approximation of this.
            WRAP_MODE_NONE,
            // WRAP == GL_REPEAT Ignores the integer part of texture coordinates, 
            // using only the fractional part.
            WRAP_MODE_WRAP, 
            // MIRROR == GL_MIRRORED_REPEAT First mirrors the texture coordinate. 
            // The mirrored coordinate is then clamped as described for CLAMP_TO_EDGE.
            WRAP_MODE_MIRROR,
            // CLAMP == GL_CLAMP_TO_EDGE Clamps texture coordinates at all 
            // mipmap levels such that the texture filter never samples a 
            // border texel. Note: GL_CLAMP takes any texels beyond the
            // sampling border and substitutes those texels with the border 
            // color. So CLAMP_TO_EDGE is more appropriate. This also works 
            // much better with OpenGL ES where the GL_CLAMP symbol was removed 
            // from the OpenGL ES specification.
            WRAP_MODE_CLAMP,
            // BORDER GL_CLAMP_TO_BORDER Clamps texture coordinates at all 
            // MIPmaps such that the texture filter always samples border 
            // texels for fragments whose corresponding texture coordinate
            // is sufficiently far outside the range [0, 1].
            WRAP_MODE_BORDER
        };

    private:

        /** The type of the current sampler. */
        SamplerType mSamplerType;

        /** An xs:NCName, which is the sid of a <surface>. A <sampler*> is a 
        definition of how a shader will resolve a color out of a <surface>. 
        <source> identifies the <surface> to read. */
        String mSource;

        /** Texture minimization. Enumerated type fx_sampler_filter_common. 
        Applying a texture to a primitive implies a mapping from texture image 
        space to framebuffer image space. In general, this mapping involves
        a reconstruction of the sampled texture image, followed by a 
        homogeneous warping implied by the mapping to framebuffer space, then a 
        filtering, followed finally by a resampling of the filtered, warped, 
        reconstructed image before applying it to a fragment. */
        SamplerFilter mMinFilter;

        /** Texture magnification. Enumerated type fx_sampler_filter_common. 
        When gamma indicates magnification, this value determines how the 
        texture value is obtained. */
        SamplerFilter mMagFilter;

        /** MIPmap filter. Enumerated type fx_sampler_filter_common. */
        SamplerFilter mMipFilter;

        /** Wrap modes */
        WrapMode mWrap_s;
        WrapMode mWrap_t;
        WrapMode mWrap_p;

        /** When reading past the edge of the texture address space based on 
        the wrap modes involving clamps, this color takes over. Type 
        fx_color_common (four floating-point numbers in RGBA order). */
        Color mBorderColor;
        bool mUseBorderColor;

        /** An xs:unsignedByte, which is the maximum number of progressive 
        levels that the sampler will evaluate. */
        unsigned char mMipmapMaxlevel;

        /** An xs:float, which biases the gamma (level of detail parameter) 
        that is used by the sampler to evaluate the MIPmap chain. */
        float mMipmapBias;

    public:

        /** Constructor. */
        Sampler ( const SamplerType &samplerType, const String &source = "" );

        /**Constructor that creates an invalid surface.*/
        Sampler();

        /** Initialize the members in depend on the sampler type. */
        void initializeMembers();

        /** Destructor. */
        ~Sampler () {}

        /** Set the samplers type. */
        void setSamplerType ( const COLLADASW::Sampler::SamplerType& val ) { mSamplerType = val; }

        /** An xs:NCName, which is the sid of a <surface>. A <sampler*> is a 
        definition of how a shader will resolve a color out of a <surface>. 
        <source> identifies the <surface> to read. */
        const String& getSource () const;
        void setSource ( const String& val );

        /** Sets the min filter. */
        void setMinFilter ( const SamplerFilter& filter );

        /** Returns min filter*/
        const SamplerFilter& getMinFilter() const;

        /** Sets the mag filter. */
        void setMagFilter ( const SamplerFilter& filter );

        /** Returns mag filter*/
        const SamplerFilter& getMagFilter() const;

        /** Sets the mip filter. */
        void setMipFilter ( const SamplerFilter& filter );

        /** Returns mip filter*/
        const SamplerFilter& getMipFilter() const;

        /** Retrieves the wrap mode (in dimension S, T or P) of the sampler.
        @return The wrap mode.*/
        const WrapMode& getWrapS() const;

        /** Retrieves the wrap mode (in dimension S, T or P) of the sampler.
        @return The wrap mode.*/
        const WrapMode& getWrapT() const;

        /** Retrieves the wrap mode (in dimension S, T or P) of the sampler.
        @return The wrap mode.*/
        const WrapMode& getWrapP() const;

        /** Sets the wrap mode (in dimension S, T or P) of the sampler.
        @param mode The wrap mode.*/
        void setWrapS ( const WrapMode& mode );

        /** Sets the wrap mode (in dimension S, T or P) of the sampler.
        @param mode The wrap mode.*/
        void setWrapT ( const WrapMode& mode );

        /** Sets the wrap mode (in dimension S, T or P) of the sampler.
        @param mode The wrap mode.*/
        void setWrapP ( const WrapMode& mode );

        /** When reading past the edge of the texture address space based on 
        the wrap modes involving clamps, this color takes over. Type 
        fx_color_common (four floating-point numbers in RGBA order). */
        const Color& getBorderColor () const;
        void setBorderColor ( const Color& val );

        /** An xs:unsignedByte, which is the maximum number of progressive 
        levels that the sampler will evaluate. */
        const unsigned char getMipmapMaxlevel () const;
        void setMipmapMaxlevel ( const unsigned char val );

        /** An xs:float, which biases the gamma (level of detail parameter) 
        that is used by the sampler to evaluate the MIPmap chain. */
        const float getMipmapBias () const;
        void setMipmapBias ( const float val );

        /** Returns the COLLADASW string for the given sampler type. */
        static const String& getSamplerTypeString ( const SamplerType &samplerType );

        /** Returns a reference to the COLLADASW name of the SamplerFilter. */
        static const String& getSamplerFilterString ( const SamplerFilter &samplerFilter );

        /** Returns a reference to the COLLADASW name of the wrap mode. */
        static const String& getWrapModeString ( const WrapMode &wrapMode );

        /** Declares the storage for the graphical representation of an object. */
        void add ( StreamWriter *sw ) const;
    };
}

#endif // __COLLADASTREAMWRITER_SAMPLER_H__