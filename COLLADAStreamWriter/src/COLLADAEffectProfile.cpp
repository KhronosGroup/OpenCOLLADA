/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAEffectProfile.h"
#include "COLLADASWC.h"
#include "COLLADAExtra.h"
#include "COLLADATechnique.h"
#include <assert.h>
#include <algorithm>

namespace COLLADA
{

    const String EffectProfile::DEFAULT_TECHNIQUE_SID = "common";


    //---------------------------------------------------------------
    EffectProfile::EffectProfile ( StreamWriter * streamWriter )
            : ElementWriter ( streamWriter ),
            BaseExtraTechnique(),
            mTechniqueSid ( DEFAULT_TECHNIQUE_SID ),
            mShaderType ( UNSPECIFIED ),
            mReflectivity ( -1 ),
            mOpaque ( UNSPECIFIED_OPAQUE ),
            mTransparency ( -1 ),
            mIndexOfRefrection ( -1 ),
            mShininess ( -1 )
    {}

    //---------------------------------------------------------------
    void EffectProfile::add(bool closeProfile) 
    {
        TagCloser profileCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_PROFILE_COMMON );

        addSamplers();

        mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mTechniqueSid );

        TagCloser shaderTypeCloser = mSW->openElement ( getShaderTypeName ( mShaderType ) );

        addColorOrTexture ( CSWC::COLLADA_ELEMENT_EMISSION, mEmission );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_AMBIENT, mAmbient );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_DIFFUSE, mDiffuse );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_SPECULAR, mSpecular );
        addFloat ( CSWC::COLLADA_ELEMENT_SHININESS, mShininess );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_REFLECTIVE, mReflective );
        addFloat ( CSWC::COLLADA_ELEMENT_REFLECTIVITY, mReflectivity );
        addColorOrTexture ( CSWC::COLLADA_ELEMENT_TRANSPARENT, mTransparent, mOpaque );
        addFloat ( CSWC::COLLADA_ELEMENT_TRANSPARENCY, mTransparency );

        addTextureExtraTechniques( *mSW );

        shaderTypeCloser.close();

        addExtraTechniqueColorOrTexture(mExtraTechniqueColorOrTexture);

        profileCloser.close();
    }

    //---------------------------------------------------------------
    void EffectProfile::addExtraTechniqueColorOrTexture ( 
        const ColorOrTexture& colorOrTexture)
    {
        if ( colorOrTexture.isTexture() )
        {
            const Texture& texture = colorOrTexture.getTexture();

            const String& profileName = texture.getProfileName();
            const String& childElement = texture.getChildElementName();

            // Open the extra tag
            COLLADA::Extra colladaExtra ( mSW );
            colladaExtra.openExtra();

            // Open the technique tag
            COLLADA::Technique colladaTechnique ( mSW );
            colladaTechnique.openTechnique(profileName);

            // Add the texture
            addColorOrTexture(childElement, colorOrTexture);

            // Close the technique and extra tags
            colladaTechnique.closeTechnique();
            colladaExtra.closeExtra();
        }
    }

    //---------------------------------------------------------------
    void EffectProfile::addSamplers() 
    {
        addSampler ( mEmission );
        addSampler ( mAmbient );
        addSampler ( mDiffuse );
        addSampler ( mSpecular );
        addSampler ( mReflective );
        addSampler ( mTransparent );
    }


    //---------------------------------------------------------------
    void EffectProfile::addSampler ( const ColorOrTexture & colorOrTexture ) 
    {
        // Don't implement double textures!
        if ( colorOrTexture.isTexture() )
        {
            // TODO: add COLLADA 1.5 texture
            const Texture& texture = colorOrTexture.getTexture();

            // Have a look, if we have this surface already written.
            std::vector<String>::const_iterator iter;
            iter = find(mSampledImages.begin(), mSampledImages.end(), texture.getImageId());
            if (iter == mSampledImages.end())
            {
                // Push the id of the image in the list of sampled surface image ids
                mSampledImages.push_back(texture.getImageId());

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
