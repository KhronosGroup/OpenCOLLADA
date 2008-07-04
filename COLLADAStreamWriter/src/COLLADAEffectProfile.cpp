/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/


#include "COLLADAEffectProfile.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    const String Texture::SAMPLER_SID_SUFFIX = "-sampler";
    const String Texture::SURFACE_SID_SUFFIX = "-surface";


    //---------------------------------------------------------------
    Texture::Texture ( const String & imageID, Texture::SurfaceType surfaceType )
            : BaseExtraTechnique(), mImageID ( imageID ),
            mSurfaceType ( surfaceType ),
            mWrap_s ( Texture::WRAP_MODE_UNSPECIFIED ),
            mWrap_t ( Texture::WRAP_MODE_UNSPECIFIED ),
            mWrap_p ( Texture::WRAP_MODE_UNSPECIFIED ),
            mMinFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED ),
            mMagFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED ),
            mMipFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED )
    {}


    //---------------------------------------------------------------
    Texture::Texture()
            : mSurfaceType ( SURFACE_TYPE_UNSPECIFIED ),
            mWrap_s ( Texture::WRAP_MODE_UNSPECIFIED ),
            mWrap_t ( Texture::WRAP_MODE_UNSPECIFIED ),
            mWrap_p ( Texture::WRAP_MODE_UNSPECIFIED ),
            mMinFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED ),
            mMagFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED ),
            mMipFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED )
    {}

    //---------------------------------------------------------------
    const Color Color::WHITE = Color ( 1.0, 1.0, 1.0, 1.0 );
    const Color Color::BLACK = Color ( 0.0, 0.0, 0.0, 1.0 );

    //---------------------------------------------------------------
    void Color::set ( double r, double g, double b, double a )
    {
        mR=r;
        mG=g;
        mB=b;
        mA=a;
    }

    //---------------------------------------------------------------
    bool Color::isValid() const
    {
        return ( mR >= 0 && mR <= 1 ) &&
               ( mG >= 0 && mG <= 1 ) &&
               ( mB >= 0 && mB <= 1 ) &&
               ( mA >= 0 && mA <= 1 );
    }


    const String EffectProfile::DEFAULT_TECHNIQUE_SID = "common";



    //---------------------------------------------------------------
    EffectProfile::EffectProfile ( StreamWriter * streamWriter )
            : ElementWriter ( streamWriter ),
            mTechniqueSid ( DEFAULT_TECHNIQUE_SID ),
            mShaderType ( UNSPECIFIED ),
            mReflectivity ( -1 ),
            mOpaque ( UNSPECIFIED_OPAQUE ),
            mTransparency ( -1 ),
            mIndexOfRefrection ( -1 )
    {}

    //---------------------------------------------------------------
    void EffectProfile::add() const
    {
        TagCloser profileCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_PROFILE_COMMON );

        addSamplers();

        mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mTechniqueSid );
        mSW->openElement ( getShaderTypeName ( mShaderType ) );

        addColorOrTexture ( CSWC::COLLADA_ELEMENT_EMISSION, mEmission );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_AMBIENT, mAmbient );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_DIFFUSE, mDiffuse );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_SPECULAR, mSpecular );
        addFloat ( CSWC::COLLADA_ELEMENT_SHININESS, mShininess );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_REFLECTIVE, mReflective );
        addFloat ( CSWC::COLLADA_ELEMENT_REFLECTIVITY, mReflectivity );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_TRANSPARENT, mTransparent, mOpaque );
        addFloat ( CSWC::COLLADA_ELEMENT_TRANSPARENCY, mTransparency );

        profileCloser.close();
    }



    //---------------------------------------------------------------
    void EffectProfile::addSamplers() const
    {
        addSampler ( mEmission );
        addSampler ( mAmbient );
        addSampler ( mDiffuse );
        addSampler ( mSpecular );
        addSampler ( mReflective );
        addSampler ( mTransparent );
    }


    //---------------------------------------------------------------
    void EffectProfile::addSampler ( const ColorOrTexture & colorOrTexture ) const
    {
        if ( colorOrTexture.isTexture() )
        {
            // TODO: add COLLADA 1.5 texture
            const Texture& texture = colorOrTexture.getTexture();

            // surface
            TagCloser surfaceNewParam = mSW->openElement ( CSWC::COLLADA_ELEMENT_NEWPARAM );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, texture.getSurfaceSid() );
            mSW->openElement ( CSWC::COLLADA_ELEMENT_SURFACE );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, getSurfaceTypeString ( texture.getSurfaceType() ) );
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_INIT_FROM, texture.getImageID() );
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_FORMAT, texture.getFormat() );
            surfaceNewParam.close();

            //sampler
            TagCloser samplerNewParam = mSW->openElement ( CSWC::COLLADA_ELEMENT_NEWPARAM );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, texture.getSamplerSid() );
            mSW->openElement ( CSWC::COLLADA_ELEMENT_SAMPLER2D );
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_SOURCE, texture.getSurfaceSid() );

            if ( texture.getWrapS() != Texture::WRAP_MODE_UNSPECIFIED )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_WRAP_S, getWrapModeString ( texture.getWrapS() ) );

            if ( texture.getWrapT() != Texture::WRAP_MODE_UNSPECIFIED )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_WRAP_T, getWrapModeString ( texture.getWrapT() ) );

            if ( texture.getWrapP() != Texture::WRAP_MODE_UNSPECIFIED )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_WRAP_P, getWrapModeString ( texture.getWrapP() ) );

            if ( texture.getMinFilter() != Texture::SAMPLER_FILTER_UNSPECIFIED )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_MINFILTER, getSamplerFilterString ( texture.getMinFilter() ) );

            if ( texture.getMagFilter() != Texture::SAMPLER_FILTER_UNSPECIFIED )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_MAGFILTER, getSamplerFilterString ( texture.getMagFilter() ) );

            if ( texture.getMipFilter() != Texture::SAMPLER_FILTER_UNSPECIFIED )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_MIPFILTER, getSamplerFilterString ( texture.getMipFilter() ) );

            samplerNewParam.close();
        }
    }


    //---------------------------------------------------------------
    const String& EffectProfile::getShaderTypeName ( ShaderTypes shaderType )
    {
        switch ( shaderType )
        {

        case EffectProfile::CONSTANT:
            return CSWC::COLLADA_ELEMENT_CONSTANT;

        case EffectProfile::LAMBERT:
            return CSWC::COLLADA_ELEMENT_LAMBERT;

        case EffectProfile::PHONG:
            return CSWC::COLLADA_ELEMENT_PHONG;

        case EffectProfile::BLINN:
            return CSWC::COLLADA_ELEMENT_BLINN;

        default:
            return CSWC::EMPTY_STRING;
        }
    }

    //---------------------------------------------------------------
    const String& EffectProfile::getSurfaceTypeString ( Texture::SurfaceType surfaceType )
    {
        switch ( surfaceType )
        {

        case Texture::SURFACE_TYPE_1D:
            return CSWC::COLLADA_SURFACE_TYPE_1D;

        case Texture::SURFACE_TYPE_2D:
            return CSWC::COLLADA_SURFACE_TYPE_2D;

        case Texture::SURFACE_TYPE_3D:
            return CSWC::COLLADA_SURFACE_TYPE_3D;

        case Texture::SURFACE_TYPE_CUBE:
            return CSWC::COLLADA_SURFACE_TYPE_CUBE;

        case Texture::SURFACE_TYPE_DEPTH:
            return CSWC::COLLADA_SURFACE_TYPE_DEPTH;

        case Texture::SURFACE_TYPE_RECT:
            return CSWC::COLLADA_SURFACE_TYPE_RECT;

        case Texture::SURFACE_TYPE_UNTYPED:
            return CSWC::COLLADA_SURFACE_TYPE_UNTYPED;

        default:
            return CSWC::EMPTY_STRING;
        }

    }


    //---------------------------------------------------------------
    const String& EffectProfile::getSamplerFilterString ( Texture::SamplerFilter samplerFilter )
    {
        switch ( samplerFilter )
        {

        case Texture::SAMPLER_FILTER_NONE:
            return CSWC::COLLADA_SAMPLER_FILTER_NONE;

        case Texture::SAMPLER_FILTER_LINEAR:
            return CSWC::COLLADA_SAMPLER_FILTER_LINEAR;

        case Texture::SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR:
            return CSWC::COLLADA_SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR;

        case Texture::SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST:
            return CSWC::COLLADA_SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST;

        case Texture::SAMPLER_FILTER_NEAREST:
            return CSWC::COLLADA_SAMPLER_FILTER_NEAREST;

        case Texture::SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR:
            return CSWC::COLLADA_SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR;

        case Texture::SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST:
            return CSWC::COLLADA_SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST;

        default:
            return CSWC::EMPTY_STRING;
        }
    }

    //---------------------------------------------------------------
    const String& EffectProfile::getWrapModeString ( Texture::WrapMode wrapMode )
    {
        switch ( wrapMode )
        {

        case Texture::WRAP_MODE_NONE:
            return CSWC::COLLADA_TEXTURE_WRAP_NONE;

        case Texture::WRAP_MODE_WRAP:
            return CSWC::COLLADA_TEXTURE_WRAP_WRAP;

        case Texture::WRAP_MODE_MIRROR:
            return CSWC::COLLADA_TEXTURE_WRAP_MIRROR;

        case Texture::WRAP_MODE_CLAMP:
            return CSWC::COLLADA_TEXTURE_WRAP_CLAMP;

        case Texture::WRAP_MODE_BORDER:
            return CSWC::COLLADA_TEXTURE_WRAP_BORDER;

        default:
            return CSWC::EMPTY_STRING;
        }
    }

    //---------------------------------------------------------------
    const String& EffectProfile::getOpaqueString ( Opaque opaque )
    {
        switch ( opaque )
        {

        case A_ONE:
            return CSWC::COLLADA_OPAQUE_TYPE_A_ONE;

        case RGB_ZERO:
            return CSWC::COLLADA_OPAQUE_TYPE_RGB_ZERO;

        case RGB_ONE:
            return CSWC::COLLADA_OPAQUE_TYPE_RGB_ONE;

        case A_ZERO:
            return CSWC::COLLADA_OPAQUE_TYPE_A_ZERO;

        default:
            return EMPTY_STRING;
        }
    }


    //---------------------------------------------------------------
    void EffectProfile::addColorOrTexture ( const String & elementName,
                                            const ColorOrTexture & colorOrTexture,
                                            Opaque opaque ) const
    {
        bool isColor = colorOrTexture.isColor();
        bool isTexture =  colorOrTexture.isTexture();

        if ( ! ( isColor || isTexture ) )
            return;

        mSW->openElement ( elementName );

        if ( opaque != UNSPECIFIED_OPAQUE )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_OPAQUE, getOpaqueString ( opaque ) );

        if ( isTexture )
        {
            const Texture& texture = colorOrTexture.getTexture();

            mSW->openElement ( CSWC::COLLADA_ELEMENT_TEXTURE );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TEXTURE, texture.getSamplerSid() );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TEXCOORD, texture.getTexcoord() );

            texture.addTextureExtraTechniques ( *mSW );

            mSW->closeElement();
        }

        else if ( isColor )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_COLOR );
            const Color& color = colorOrTexture.getColor();
            mSW->appendValues ( color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha() );
            mSW->closeElement();
        }

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void EffectProfile::addFloat ( const String & elementName, const double & number ) const
    {
        if ( number >= 0 )
        {
            mSW->openElement ( elementName );
            mSW->openElement ( CSWC::COLLADA_ELEMENT_FLOAT );
            mSW->appendValues ( number );
            mSW->closeElement();
            mSW->closeElement();
        }
    }



} //namespace COLLADA
