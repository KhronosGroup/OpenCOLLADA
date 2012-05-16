/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIGHT_H__
#define __COLLADASTREAMWRITER_LIGHT_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWColor.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    /** A class that hold all information about a @a \<light\> element.*/
    class Light : public ElementWriter, public BaseExtraTechnique
    {
    public:
        
        /** Light types */ 
        enum LightType
        {
            AMBIENT, 
            DIRECTIONAL, 
            POINT, 
            SPOT
        };

    private:

        friend class LibraryLights;

        /** The id of the light.*/
        String mLightId;

        /** The name of the light.*/
        String mLightName;

        /** The light type. */
        LightType mLightType;

    protected:

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        float mConstantAttenuation;
        String mConstantAttenuationSid;

        float mLinearAttenuation;
        String mLinearAttenuationSid;

        float mQuadraticAttenuation;
        String mQuadraticAttenuationSid;

        /**
        * The <falloff_angle> and <falloff_exponent> are used to specify the 
        * amount of attenuation based on the direction of the light.
        */
        float mFallOffAngle;
        String mFallOffAngleSid;

        float mFallOffExponent;
        String mFallOffExponentSid;

        /** The color attribute. */
        Color mColor;
        String mColorSid;

        /** The color intensity. To calculate the light color,
        multiply the base color with the intensity. */
        float mIntensity;
        String mIntensitySid;

//         float mDropOff;
//         String mDropOffSid;

    protected:

        /** Adds the light information. */
        void add() const;

        /** Adds the light type specific information. */
        virtual void addTypeSpecificInfos () const = 0;

    public:
 
        /** 
         * Constructor
         * @param lightId The id of the light.
         * @param lightName The name of the light.
         */
        Light ( 
            StreamWriter* streamWriter, 
            const String& lightId,
            const LightType& lightType,
            const String& lightName = ElementWriter::EMPTY_STRING, 
            const float intensity = 1.0f );

        /** Destructor */
        virtual ~Light() {}

        /** Returns a reference to the light id */
        const String& getLightId() const { return mLightId; }

        /** Returns the light type. */
        const LightType& getLightType () const { return mLightType; }

        /** Returns a reference to the light name */
        const String& getLightName() const { return mLightName; }

        /** The name of the light.*/
        void setLightName ( const String& val ) { mLightName = val; }

        /** The color attribute. */
        const Color& getColor() const { return mColor; }

        /** The color attribute. */
        void setColor ( const Color& val, const bool useDefaultSid = false, const String& sid = "" );
		/** Returns the default sid used for the color element*/ 
		static const String& getColorDefaultSid() { return CSWC::CSW_ELEMENT_COLOR; }

        /** Retrieves the intensity of the light. To calculate the light color,
        multiply the base color with the intensity.
        @return The intensity of the light. */
        const float getIntensity() const { return mIntensity; }
 
        /** Sets the intensity of the light. To calculate the light color,
        multiply the base color with the intensity.
        @param intensity The intensity of the light. */
        void setIntensity ( float intensity, const bool useDefaultSid = false, const String& sid = "" );

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        const float getConstantAttenuation() const { return mConstantAttenuation; }

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        void setConstantAttenuation ( const float val, const bool useDefaultSid = false, const String& sid = "" );
		/** Returns the default sid used for the ConstantAttenuation element*/ 
		static const String& getConstantAttenuationDefaultSid() { return CSWC::CSW_ELEMENT_CONSTANT_ATTENUATION; }

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        const float getLinearAttenuation() const { return mLinearAttenuation; }

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        void setLinearAttenuation ( const float val, const bool useDefaultSid = false, const String& sid = "" );
		/** Returns the default sid used for the LinearAttenuation element*/ 
		static const String& getLinearAttenuationDefaultSid() { return CSWC::CSW_ELEMENT_LINEAR_ATTENUATION; }

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        const float getQuadraticAttenuation() const { return mQuadraticAttenuation; }

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        void setQuadraticAttenuation ( const float val, const bool useDefaultSid = false, const String& sid = "" );
		/** Returns the default sid used for the QuadraticAttenuation element*/ 
		static const String& getQuadraticAttenuationDefaultSid() { return CSWC::CSW_ELEMENT_QUADRATIC_ATTENUATION; }

        /**
        * The <falloff_angle> and <falloff_exponent> are used to specify the 
        * amount of attenuation based on the direction of the light.
        */
        const float getFallOffAngle() const { return mFallOffAngle; }
		/** Returns the default sid used for the FallOffAngle element*/ 
		static const String& getFallOffAngleDefaultSid() { return CSWC::CSW_ELEMENT_FALLOFF_ANGLE; }

        /**
        * The <falloff_angle> and <falloff_exponent> are used to specify the 
        * amount of attenuation based on the direction of the light.
        */
        void setFallOffAngle ( const float val, const bool useDefaultSid = false, const String& sid = "" );

        /**
        * The <falloff_angle> and <falloff_exponent> are used to specify the 
        * amount of attenuation based on the direction of the light.
        */
        const float getFallOffExponent() const { return mFallOffExponent; }

        /**
        * The <falloff_angle> and <falloff_exponent> are used to specify the 
        * amount of attenuation based on the direction of the light.
        */
        void setFallOffExponent ( const float val, const bool useDefaultSid = false, const String& sid = "" );
		/** Returns the default sid used for the FallOffExponent element*/ 
		static const String& getFallOffExponentDefaultSid() { return CSWC::CSW_ELEMENT_FALLOFF_EXPONENT; }

    };


    /** Light class for ambient light. */
    class AmbientLight : public Light
    {
    public:

        /** 
        * Constructor
        * @param lightId The id of the light.
        * @param lightName The name of the light.
        */
        AmbientLight ( 
            StreamWriter* streamWriter, 
            const String& lightId,
            const String& lightName = ElementWriter::EMPTY_STRING,
            const float intensity = 1.0f )
        : Light ( streamWriter, lightId, AMBIENT, lightName, intensity )
        {}

        virtual ~AmbientLight() {}

    protected:

        /** Adds the light type specific information. */
        void addTypeSpecificInfos () const;

    };

    /** Light class for directional light. */
    class DirectionalLight : public Light
    {
    public:

        /** 
        * Constructor
        * @param lightId The id of the light.
        * @param lightName The name of the light.
        */
        DirectionalLight ( 
            StreamWriter* streamWriter, 
            const String& lightId,
            const String& lightName = ElementWriter::EMPTY_STRING,
            const float intensity = 1.0f )
        : Light ( streamWriter, lightId, DIRECTIONAL, lightName, intensity ) 
        {}

        virtual ~DirectionalLight() {}

    protected:

        /** Adds the light type specific information. */
        void addTypeSpecificInfos () const;

    };

    /** Light class for point light. */
    class PointLight : public Light
    {
    public:

        /** 
        * Constructor
        * @param lightId The id of the light.
        * @param lightName The name of the light.
        */
        PointLight ( 
            StreamWriter* streamWriter, 
            const String& lightId,
            const String& lightName = ElementWriter::EMPTY_STRING,
            const float intensity = 1.0f )
        : Light ( streamWriter, lightId, POINT, lightName, intensity )
        {}

        virtual ~PointLight() {}

    protected:

        /** Adds the light type specific information. */
        void addTypeSpecificInfos () const;

    };

    /** Light class for spot light. */
    class SpotLight : public Light
    {
    public:

        /** 
        * Constructor
        * @param lightId The id of the light.
        * @param lightName The name of the light.
        */
        SpotLight ( 
            StreamWriter* streamWriter, 
            const String& lightId,
            const String& lightName = ElementWriter::EMPTY_STRING,
            const float intensity = 1.0f )
        : Light ( streamWriter, lightId, POINT, lightName, intensity )
        {}


        virtual ~SpotLight() {}

    protected:

        /** Adds the light type specific information. */
        void addTypeSpecificInfos () const;

    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIGHT_H__
