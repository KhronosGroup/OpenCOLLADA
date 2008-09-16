/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAStreamWriter.h"
#include "COLLADALight.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    // ---------------------------------------------------
    Light::Light ( 
        StreamWriter* streamWriter, 
        const String& lightId, 
        const LightType& lightType, 
        const float intensity, 
        const String& lightName )
    : ElementWriter ( streamWriter )
    , BaseExtraTechnique ( )
    , mLightId ( lightId )
    , mLightType ( lightType )
    , mColorSid ( "" )
    , mLightName ( lightName )
    , mIntensity ( intensity )
    , mIntensitySid ( "" )
    , mConstantAttenuation ( 1.0f )
    , mConstantAttenuationSid ( "" )
    , mLinearAttenuation ( 0.0f )
    , mLinearAttenuationSid ( "" )
    , mQuadraticAttenuation ( 0.0f )
    , mQuadraticAttenuationSid ( "" )
    , mFallOffAngle ( 180.0f )
    , mFallOffAngleSid ( "" )
    , mFallOffExponent ( 0.0f )
    , mFallOffExponentSid ( "" )
    {}

    // ---------------------------------------------------
    void Light::add () const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_LIGHT );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, getLightId() );
        if ( !getLightName().empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, getLightName() );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE_COMMON );
        this->addTypeSpecificInfos ();
        mSW->closeElement(); // COLLADA_ELEMENT_TECHNIQUE_COMMON
        addExtraTechniques ( mSW );

        mSW->closeElement(); // COLLADA_ELEMENT_LIGHT

    }

    // --------------------------------------------
    void Light::setColor( const Color& val, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mColor = val; 
        if ( useDefaultSid ) mColorSid = CSWC::COLLADA_ELEMENT_COLOR;
        else mColorSid = sid;
    }

    // --------------------------------------------
    void Light::setIntensity( float intensity, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mIntensity = intensity; 
        if ( useDefaultSid ) mIntensitySid = CSWC::COLLADA_ELEMENT_FALLOFF_EXPONENT;
        else mIntensitySid = sid;
    }

    // --------------------------------------------
    void Light::setConstantAttenuation( const float val, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mConstantAttenuation = val; 
        if ( useDefaultSid ) mConstantAttenuationSid = CSWC::COLLADA_ELEMENT_CONSTANT_ATTENUATION;
        else mConstantAttenuationSid = sid;
    }

    // --------------------------------------------
    void Light::setLinearAttenuation( const float val, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mLinearAttenuation = val; 
        if ( useDefaultSid ) mLinearAttenuationSid = CSWC::COLLADA_ELEMENT_LINEAR_ATTENUATION;
        else mLinearAttenuationSid = sid;
    }

    // --------------------------------------------
    void Light::setQuadraticAttenuation( const float val, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mQuadraticAttenuation = val; 
        if ( useDefaultSid ) mQuadraticAttenuationSid = CSWC::COLLADA_ELEMENT_QUADRATIC_ATTENUATION;
        else mQuadraticAttenuationSid = sid;
    }

    // --------------------------------------------
    void Light::setFallOffAngle( const float val, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mFallOffAngle = val; 
        if ( useDefaultSid ) mFallOffAngleSid = CSWC::COLLADA_ELEMENT_FALLOFF_ANGLE;
        else mFallOffAngleSid = sid;
    }

    // --------------------------------------------
    void Light::setFallOffExponent( const float val, const bool useDefaultSid /*= false*/, const String& sid /*= "" */ )
    {
        mFallOffExponent = val; 
        if ( useDefaultSid ) mFallOffExponentSid = CSWC::COLLADA_ELEMENT_FALLOFF_EXPONENT;
        else mFallOffExponentSid = sid;
    }

    // --------------------------------------------
    void AmbientLight::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_AMBIENT );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_COLOR );
        mSW->appendValues ( mColor.getRed(), mColor.getGreen(), mColor.getBlue() );
        mSW->closeElement(); // COLLADA_ELEMENT_COLOR

        mSW->closeElement(); // COLLADA_ELEMENT_AMBIENT
    }

    // --------------------------------------------
    void DirectionalLight::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_DIRECTIONAL );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_COLOR );
        if ( !mColorSid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mColorSid );
        mSW->appendValues ( mColor.getRed(), mColor.getGreen(), mColor.getBlue() );
        mSW->closeElement(); // COLLADA_ELEMENT_COLOR

        mSW->closeElement(); // COLLADA_ELEMENT_DIRECTIONAL
    }

    // --------------------------------------------
    void PointLight::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_POINT );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_COLOR );
        if ( !mColorSid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mColorSid );
        mSW->appendValues ( mColor.getRed(), mColor.getGreen(), mColor.getBlue() );
        mSW->closeElement(); // COLLADA_ELEMENT_COLOR

        mSW->openElement ( CSWC::COLLADA_ELEMENT_CONSTANT_ATTENUATION );
        if ( !mConstantAttenuationSid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mConstantAttenuationSid );
        mSW->appendValues ( mConstantAttenuation );
        mSW->closeElement();

        mSW->openElement ( CSWC::COLLADA_ELEMENT_LINEAR_ATTENUATION );
        if ( !mLinearAttenuationSid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mLinearAttenuationSid );
        mSW->appendValues ( mLinearAttenuation );
        mSW->closeElement();

        mSW->openElement ( CSWC::COLLADA_ELEMENT_QUADRATIC_ATTENUATION );
        if ( !mQuadraticAttenuationSid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mQuadraticAttenuationSid );
        mSW->appendValues ( mQuadraticAttenuation );
        mSW->closeElement();

        mSW->closeElement(); // COLLADA_ELEMENT_POINT
    }

    // --------------------------------------------
    void SpotLight::addTypeSpecificInfos() const
    { 
        mSW->openElement ( CSWC::COLLADA_ELEMENT_SPOT );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_COLOR );
        if ( !mColorSid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mColorSid );
        mSW->appendValues ( mColor.getRed(), mColor.getGreen(), mColor.getBlue() );
        mSW->closeElement(); // COLLADA_ELEMENT_COLOR

        mSW->openElement ( CSWC::COLLADA_ELEMENT_CONSTANT_ATTENUATION );
        if ( !mConstantAttenuationSid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mConstantAttenuationSid );
        mSW->appendValues ( mConstantAttenuation );
        mSW->closeElement();

        mSW->openElement ( CSWC::COLLADA_ELEMENT_LINEAR_ATTENUATION );
        if ( !mLinearAttenuationSid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mLinearAttenuationSid );
        mSW->appendValues ( mLinearAttenuation );
        mSW->closeElement();

        mSW->openElement ( CSWC::COLLADA_ELEMENT_QUADRATIC_ATTENUATION );
        if ( !mQuadraticAttenuationSid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mQuadraticAttenuationSid );
        mSW->appendValues ( mQuadraticAttenuation );
        mSW->closeElement();

        if ( !COLLADA::MathUtils::equals ( mFallOffAngle, 180.0f ) )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_FALLOFF_ANGLE );
            if ( !mFallOffAngleSid.empty() )
                mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mFallOffAngleSid );
            mSW->appendValues ( mFallOffAngle );
            mSW->closeElement();
        }

        if ( !COLLADA::MathUtils::equals ( mFallOffExponent, 0.0f ) )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_FALLOFF_EXPONENT );
            if ( !mFallOffExponentSid.empty() )
                mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, mFallOffExponentSid );
            mSW->appendValues ( mFallOffExponent );
            mSW->closeElement();
        }

        mSW->closeElement(); // COLLADA_ELEMENT_SPOT
    }


} //namespace COLLADA
