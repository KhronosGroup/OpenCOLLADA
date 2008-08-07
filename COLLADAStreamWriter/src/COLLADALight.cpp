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

    // --------------------------------------------
    const String Light::CONSTANT_ATTENUATION    = "constant_attenuation";
    const String Light::LINEAR_ATTENUATION      = "linear_attenuation";
    const String Light::QUADRATIC_ATTENUATION   = "quadratic_attenuation";
    const String Light::ZFAR                    = "zfar";

    const String Light::FALLOFF_ANGLE           = "falloff_angle";
    const String Light::FALLOFF_EXPONENT        = "falloff_exponent";

    // ---------------------------------------------------
    Light::Light ( 
        StreamWriter* streamWriter, 
        const String& lightId, 
        const LightType& lightType, 
        const Color& color, 
        const float intensity, 
        const String& lightName )
    : ElementWriter ( streamWriter )
    , BaseExtraTechnique ( )
    , mLightId ( lightId )
    , mLightType ( lightType )
    , mColor ( color )
    , mLightName ( lightName )
    , mIntensity ( intensity )
    , mConstantAttenuation ( 1.0f )
    , mLinearAttenuation ( 0.0f )
    , mQuadraticAttenuation ( 0.0f )
    , mFallOffAngle ( 180.0f )
    , mFallOffExponent ( 0.0f )
    , mZFar ( 0.0f )
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

        addTextureExtraTechniques ( *mSW );

        mSW->closeElement(); // COLLADA_ELEMENT_TECHNIQUE_COMMON
        mSW->closeElement(); // COLLADA_ELEMENT_LIGHT

    }

    // --------------------------------------------
    void AmbientLight::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_LIGHT_AMBIENT );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_COLOR );
        mSW->appendValues ( mColor.getRed(), mColor.getGreen(), mColor.getBlue() );
        mSW->closeElement(); // COLLADA_ELEMENT_COLOR

        mSW->closeElement(); // COLLADA_ELEMENT_LIGHT_AMBIENT
    }

    // --------------------------------------------
    void DirectionalLight::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_LIGHT_DIRECTIONAL );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_COLOR );
        mSW->appendValues ( mColor.getRed(), mColor.getGreen(), mColor.getBlue() );
        mSW->closeElement(); // COLLADA_ELEMENT_COLOR

        mSW->closeElement(); // COLLADA_ELEMENT_LIGHT_DIRECTIONAL
    }

    // --------------------------------------------
    void PointLight::addTypeSpecificInfos() const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_LIGHT_POINT );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_COLOR );
        mSW->appendValues ( mColor.getRed(), mColor.getGreen(), mColor.getBlue() );
        mSW->closeElement(); // COLLADA_ELEMENT_COLOR

        mSW->openElement ( Light::CONSTANT_ATTENUATION );
        mSW->appendValues ( mConstantAttenuation );
        mSW->closeElement();

        mSW->openElement ( Light::LINEAR_ATTENUATION );
        mSW->appendValues ( mLinearAttenuation );
        mSW->closeElement();

        mSW->openElement ( Light::QUADRATIC_ATTENUATION );
        mSW->appendValues ( mQuadraticAttenuation );
        mSW->closeElement();

        if ( !COLLADA::MathUtils::equals ( mZFar, 0.0f ) )
        {
            mSW->openElement ( Light::ZFAR );
            mSW->appendValues ( mZFar );
            mSW->closeElement();
        }

        mSW->closeElement(); // COLLADA_ELEMENT_LIGHT_POINT
    }

    // --------------------------------------------
    void SpotLight::addTypeSpecificInfos() const
    { 
        mSW->openElement ( CSWC::COLLADA_ELEMENT_LIGHT_SPOT );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_COLOR );
        mSW->appendValues ( mColor.getRed(), mColor.getGreen(), mColor.getBlue() );
        mSW->closeElement(); // COLLADA_ELEMENT_COLOR

        mSW->openElement ( Light::CONSTANT_ATTENUATION );
        mSW->appendValues ( mConstantAttenuation );
        mSW->closeElement();

        mSW->openElement ( Light::LINEAR_ATTENUATION );
        mSW->appendValues ( mLinearAttenuation );
        mSW->closeElement();

        mSW->openElement ( Light::QUADRATIC_ATTENUATION );
        mSW->appendValues ( mQuadraticAttenuation );
        mSW->closeElement();

        if ( !COLLADA::MathUtils::equals ( mFallOffAngle, 180.0f ) )
        {
            mSW->openElement ( Light::FALLOFF_ANGLE );
            mSW->appendValues ( mFallOffAngle );
            mSW->closeElement();
        }

        if ( !COLLADA::MathUtils::equals ( mFallOffExponent, 0.0f ) )
        {
            mSW->openElement ( Light::FALLOFF_EXPONENT );
            mSW->appendValues ( mFallOffExponent );
            mSW->closeElement();
        }

        mSW->closeElement(); // COLLADA_ELEMENT_LIGHT_SPOT
    }


} //namespace COLLADA
