/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADASWStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWEffectProfile.h"
#include "COLLADASWExtra.h"
#include "COLLADASWTechnique.h"
#include "COLLADASWParamTemplate.h"
#include <assert.h>
#include <algorithm>

namespace COLLADASW
{

    const String EffectProfile::DEFAULT_TECHNIQUE_SID = "common";


    //---------------------------------------------------------------
    EffectProfile::EffectProfile ( StreamWriter * streamWriter )
    : ElementWriter ( streamWriter )
    , BaseExtraTechnique()
    , mTechniqueSid ( DEFAULT_TECHNIQUE_SID )
    , mProfileType ( EffectProfile::COMMON )
    , mShaderType ( EffectProfile::UNSPECIFIED )
    , mReflectivity ( -1 )
    , mOpaque ( UNSPECIFIED_OPAQUE )
    , mTransparency ( -1 )
    , mIndexOfRefraction ( -1 )
    , mShininess ( -1 )
    , mTransparentSid (  )
    , mEmissionSid (  )
    , mAmbientSid (  )
    , mDiffuseSid (  )
    , mSpecularSid (  )
    , mReflectiveSid (  )
    , mShininessSid (  )
    , mReflectivitySid (  )
    , mTransparencySid (  )
    , mIndexOfRefractionSid (  )
    , mExtraTechniqueColorOrTextureSid (  )
    , mIncludeSid ( "" )
    {}

    //---------------------------------------------------------------
    void EffectProfile::addProfileElements ()
    {
        switch ( mProfileType )
        {
        case EffectProfile::COMMON:
            addProfileCommon ();
            break;
        case EffectProfile::CG:
            addProfileCG ();
            break;
        case EffectProfile::GLSL:
            addProfileGLSL ();
            break;
        case EffectProfile::GLES:
            addProfileGLES ();
            break;
        }
    }

    //---------------------------------------------------------------
    void EffectProfile::openProfile ()
    {
        mProfileCloser = mSW->openElement ( getProfileTypeName( mProfileType ) );
    }

    //---------------------------------------------------------------
    void EffectProfile::closeProfile ()
    {
        mProfileCloser.close();
    }

    //---------------------------------------------------------------
    void EffectProfile::addProfileCG ()
    {
        if ( !mCode.empty() )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_CODE );
            if ( !mCodeSid.empty() )
                mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, mCodeSid );
            mSW->appendText ( Utils::translateToXML ( mCode ) );
            mSW->closeElement();
        }

        if ( !mIncludeSid.empty() )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_INCLUDE );
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, mIncludeSid );
            mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, mIncludeURI.getURIString() );
        }
    }

    //--------------------------------------------------------------- 
    void EffectProfile::addProfileGLSL ()
    {
        if ( !mCode.empty() )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_CODE );
            if ( !mCodeSid.empty() )
                mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, mCodeSid );
            mSW->appendText ( Utils::translateToXML ( mCode ) );
            mSW->closeElement();
        }

        if ( !mIncludeSid.empty() )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_INCLUDE );
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, mIncludeSid );
            mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, mIncludeURI.getURIString() );
        }
    }

    //---------------------------------------------------------------
    void EffectProfile::addProfileGLES ()
    {

    }

    //---------------------------------------------------------------
    void EffectProfile::addProfileCommon ()
    {
        addSamplers();

        if ( !mTechniqueSid.empty() )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_TECHNIQUE );
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, mTechniqueSid );

            if ( mShaderType != EffectProfile::UNSPECIFIED )
            {
                TagCloser shaderTypeCloser = mSW->openElement ( getShaderTypeName ( mShaderType ) );

                addColorOrTexture ( CSWC::CSW_ELEMENT_EMISSION, mEmission, mEmissionSid );
                addColorOrTexture ( CSWC::CSW_ELEMENT_AMBIENT, mAmbient, mAmbientSid );
                addColorOrTexture ( CSWC::CSW_ELEMENT_DIFFUSE, mDiffuse, mDiffuseSid );
                addColorOrTexture ( CSWC::CSW_ELEMENT_SPECULAR, mSpecular, mSpecularSid );
                addFloat ( CSWC::CSW_ELEMENT_SHININESS, mShininess, mShininessSid );
                addColorOrTexture ( CSWC::CSW_ELEMENT_REFLECTIVE, mReflective, mReflectiveSid );
                addFloat ( CSWC::CSW_ELEMENT_REFLECTIVITY, mReflectivity, mReflectivitySid );
                addColorOrTexture ( CSWC::CSW_ELEMENT_TRANSPARENT, mTransparent, mTransparentSid, mOpaque );
                addFloat ( CSWC::CSW_ELEMENT_TRANSPARENCY, mTransparency, mTransparencySid );
                addFloat ( CSWC::CSW_ELEMENT_INDEX_OF_REFRACTION, mIndexOfRefraction, mIndexOfRefractionSid );

                addExtraTechniques( mSW );

                shaderTypeCloser.close();
            }

            addExtraTechniqueColorOrTexture( mExtraTechniqueColorOrTexture, mExtraTechniqueColorOrTextureSid );
        }
    }

    //---------------------------------------------------------------
    void EffectProfile::addExtraTechniqueColorOrTexture ( 
        const ColorOrTexture& colorOrTexture, 
        const String& elementSid ) const
    {
        if ( colorOrTexture.isTexture() )
        {
            const Texture& texture = colorOrTexture.getTexture();

            const String& profileName = texture.getProfileName();
            const String& childElement = texture.getChildElementName();

            // Open the extra tag
            COLLADASW::Extra colladaExtra ( mSW );
            colladaExtra.openExtra();

            // Open the technique tag
            COLLADASW::Technique colladaTechnique ( mSW );
            colladaTechnique.openTechnique( profileName );

            // Add the texture
            addColorOrTexture( childElement, colorOrTexture, elementSid );

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
    void EffectProfile::addSampler ( const ColorOrTexture& colorOrTexture ) 
    {
        // Don't implement double textures!
        if ( colorOrTexture.isTexture() )
        {
            // TODO: add COLLADASW 1.5 texture
            const Texture& texture = colorOrTexture.getTexture();

            // Have a look, if we have this surface already written.
            std::vector<String>::const_iterator iter;
            iter = find ( mSampledImages.begin(), mSampledImages.end(), texture.getImageId() );
            if ( iter == mSampledImages.end() )
            {
                // Push the id of the image in the list of sampled surface image ids
                mSampledImages.push_back( texture.getImageId() );

                // Add the surface <newparam>
                COLLADASW::NewParamSurface paramSurface ( mSW );
                paramSurface.openParam ( texture.getSurfaceSid() );
                texture.getSurface().add ( mSW );
                paramSurface.closeParam ();
                
                // Add the sampler <newparam>
                COLLADASW::NewParamSampler paramSampler ( mSW );
                paramSampler.openParam ( texture.getSamplerSid() );
                texture.getSampler().add ( mSW );
                paramSampler.closeParam ();
            }

        }
    }


    //---------------------------------------------------------------
    const String& EffectProfile::getShaderTypeName ( ShaderType shaderType )
    {
        switch ( shaderType )
        {
        case EffectProfile::CONSTANT:
            return CSWC::CSW_ELEMENT_CONSTANT;
        case EffectProfile::LAMBERT:
            return CSWC::CSW_ELEMENT_LAMBERT;
        case EffectProfile::PHONG:
            return CSWC::CSW_ELEMENT_PHONG;
        case EffectProfile::BLINN:
            return CSWC::CSW_ELEMENT_BLINN;
        default:
            return CSWC::EMPTY_STRING;
        }
    }

    //---------------------------------------------------------------
    const String& EffectProfile::getProfileTypeName ( ProfileType profileType )
    {
        switch ( profileType )
        {
        case EffectProfile::COMMON:
            return CSWC::CSW_ELEMENT_PROFILE_COMMON;
        case EffectProfile::CG:
            return CSWC::CSW_ELEMENT_PROFILE_CG;
        case EffectProfile::GLES:
            return CSWC::CSW_ELEMENT_PROFILE_GLES;
        case EffectProfile::GLSL:
            return CSWC::CSW_ELEMENT_PROFILE_GLSL;
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
            return CSWC::CSW_OPAQUE_TYPE_A_ONE;
        case RGB_ZERO:
            return CSWC::CSW_OPAQUE_TYPE_RGB_ZERO;
        case RGB_ONE:
            return CSWC::CSW_OPAQUE_TYPE_RGB_ONE;
        case A_ZERO:
            return CSWC::CSW_OPAQUE_TYPE_A_ZERO;
        default:
            return EMPTY_STRING;
        }
    }

    //---------------------------------------------------------------
    void EffectProfile::addColorOrTexture ( 
        const String& elementName,
        const ColorOrTexture& colorOrTexture,
        const String& elementSid,
        Opaque opaque
		) const
    {
        bool isColor = colorOrTexture.isColor();
        bool isTexture =  colorOrTexture.isTexture();
        if ( ! ( isColor || isTexture ) ) return;

        mSW->openElement ( elementName );

        if ( opaque != UNSPECIFIED_OPAQUE )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_OPAQUE, getOpaqueString ( opaque ) );

        if ( isTexture )
        {
            const Texture& texture = colorOrTexture.getTexture();

            mSW->openElement ( CSWC::CSW_ELEMENT_TEXTURE );
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_TEXTURE, texture.getSamplerSid() );
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_TEXCOORD, texture.getTexcoord() );
            
            texture.addExtraTechniques ( mSW );

            mSW->closeElement();
        }
        else if ( isColor )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_COLOR );
            if ( !elementSid.empty() )
                mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, elementSid );
            const Color& color = colorOrTexture.getColor();
            mSW->appendValues ( color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha() );
            mSW->closeElement();
        }

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void EffectProfile::addFloat ( 
        const String& elementName, 
        const double& number, 
        const String& elementSid ) const
    {
        if ( number >= 0 )
        {
            mSW->openElement ( elementName );
            mSW->openElement ( CSWC::CSW_ELEMENT_FLOAT );
            if ( !elementSid.empty() ) 
                mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_SID, elementSid );
            mSW->appendValues ( number );
            mSW->closeElement ();
            mSW->closeElement ();
        }
    }

    void EffectProfile::openTechnique( const String& techniqueSid )
    {
        mTechniqueCloser = mSW->openElement ( CSWC::CSW_ELEMENT_TECHNIQUE );
        mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, techniqueSid );
    }

    void EffectProfile::closeTechnique()
    {
        mTechniqueCloser.close ();
    }

    void EffectProfile::setTechniqueSid( const String& techniqueSid )
    {
        mTechniqueSid = techniqueSid;
    }

    const String& EffectProfile::getTechniqueSid() const
    {
        return mTechniqueSid;
    }

    void EffectProfile::setShaderType( ShaderType shaderType )
    {
        mShaderType = shaderType;
    }

    COLLADASW::EffectProfile::ShaderType EffectProfile::getShaderType() const
    {
        return mShaderType;
    }

    const String& EffectProfile::getCode() const
    {
        return mCode;
    }

    void EffectProfile::setInclude ( const URI &includeUri, const String &sid/*="" */ )
    {
        mIncludeURI = includeUri; mIncludeSid = sid;
    }

    void EffectProfile::setCode ( const String &code, const String &sid/*="" */ )
    {
        mCode = code; mCodeSid = sid;
    }

    void EffectProfile::setEmission ( const ColorOrTexture& emission, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mEmission = emission;
        if ( useDefaultSid ) mEmissionSid = CSWC::CSW_ELEMENT_EMISSION;
        else mEmissionSid = sid;
    }

    const String& EffectProfile::getEmissionDefaultSid()
    {
        return CSWC::CSW_ELEMENT_EMISSION;
    }

    ColorOrTexture& EffectProfile::getEmission()
    {
        return mEmission;
    }

    void EffectProfile::setAmbient( const ColorOrTexture& ambient, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mAmbient = ambient;
        if ( useDefaultSid ) mAmbientSid = CSWC::CSW_ELEMENT_AMBIENT;
        else mAmbientSid = sid;
    }

    const String& EffectProfile::getAmbientDefaultSid()
    {
        return CSWC::CSW_ELEMENT_AMBIENT;
    }

    ColorOrTexture& EffectProfile::getAmbient()
    {
        return mAmbient;
    }

    void EffectProfile::setDiffuse( const ColorOrTexture& diffuse, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mDiffuse = diffuse;
        if ( useDefaultSid ) mDiffuseSid = CSWC::CSW_ELEMENT_DIFFUSE;
        else mDiffuseSid = sid;
    }

    const String& EffectProfile::getDiffuseDefaultSid()
    {
        return CSWC::CSW_ELEMENT_DIFFUSE;
    }

    ColorOrTexture& EffectProfile::getDiffuse()
    {
        return mDiffuse;
    }

    void EffectProfile::setSpecular( const ColorOrTexture& specular, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mSpecular = specular;
        if ( useDefaultSid ) mSpecularSid = CSWC::CSW_ELEMENT_SPECULAR;
        else mSpecularSid = sid;
    }

    const String& EffectProfile::getSpecularDefaultSid()
    {
        return CSWC::CSW_ELEMENT_SPECULAR;
    }

    ColorOrTexture& EffectProfile::getSpecular()
    {
        return mSpecular;
    }

    void EffectProfile::setShininess( double shininess, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mShininess = shininess;
        if ( useDefaultSid ) mShininessSid = CSWC::CSW_ELEMENT_SHININESS;
        else mShininessSid = sid;
    }

    double EffectProfile::getShininess() const
    {
        return mShininess;
    }

    void EffectProfile::setReflective( const ColorOrTexture& reflective, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mReflective = reflective;
        if ( useDefaultSid ) mReflectiveSid = CSWC::CSW_ELEMENT_REFLECTIVE;
        else mReflectiveSid = sid;
    }

    const String& EffectProfile::getReflectiveDefaultSid()
    {
        return CSWC::CSW_ELEMENT_REFLECTIVE;
    }

    ColorOrTexture& EffectProfile::getReflective()
    {
        return mReflective;
    }

    void EffectProfile::setReflectivity( double reflectivity, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mReflectivity = reflectivity;
        if ( useDefaultSid ) mReflectivitySid = CSWC::CSW_ELEMENT_REFLECTIVITY;
        else mReflectivitySid = sid;
    }

    const String& EffectProfile::getReflectivityDefaultSid()
    {
        return CSWC::CSW_ELEMENT_REFLECTIVITY;
    }

    void EffectProfile::setTransparent( const ColorOrTexture& transparent, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mTransparent = transparent;
        if ( useDefaultSid ) mTransparentSid = CSWC::CSW_ELEMENT_TRANSPARENT;
        else mTransparentSid = sid;
    }

    const String& EffectProfile::getTransparentDefaultSid()
    {
        return CSWC::CSW_ELEMENT_TRANSPARENT;
    }

    ColorOrTexture& EffectProfile::getTransparent()
    {
        return mTransparent;
    }

    void EffectProfile::setOpaque( Opaque opaque )
    {
        mOpaque = opaque;
    }

    COLLADASW::EffectProfile::Opaque EffectProfile::getOpaque()
    {
        return mOpaque;
    }

    void EffectProfile::setTransparency( double transparency, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mTransparency = transparency;
        if ( useDefaultSid ) mTransparencySid = CSWC::CSW_ELEMENT_TRANSPARENCY;
        else mTransparencySid = sid;
    }

    void EffectProfile::setIndexOfRefraction( double indexOfRefrection, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mIndexOfRefraction = indexOfRefrection;
        if ( useDefaultSid ) mIndexOfRefractionSid = CSWC::CSW_ELEMENT_INDEX_OF_REFRACTION;
        else mIndexOfRefractionSid = sid;
    }

    const String& EffectProfile::getIndexOfRefractionSid()
    {
        return CSWC::CSW_ELEMENT_INDEX_OF_REFRACTION;
    }

    void EffectProfile::setExtraTechniqueColorOrTexture( const ColorOrTexture& colorOrTexture, const String& sid /*= "" */ )
    {
        mExtraTechniqueColorOrTexture = colorOrTexture;
        mExtraTechniqueColorOrTextureSid = sid;
    }
} //namespace COLLADASW
