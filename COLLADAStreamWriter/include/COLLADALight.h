/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIGHT_H__
#define __COLLADASTREAMWRITER_LIGHT_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAStreamWriter.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADAColor.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    /** A class that hold all information about an @a \<light\> element.*/
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
        float mLinearAttenuation;
        float mQuadraticAttenuation;

        /** 
        * Contains a floating-point number that describes the distance 
        * to the far clipping plane.
        */
        float mZFar;

        /**
        * The <falloff_angle> and <falloff_exponent> are used to specify the 
        * amount of attenuation based on the direction of the light.
        */
        float mFallOffAngle;
        float mFallOffExponent;

        /** The color attribute. */
        Color mColor;

        /** The color intensity. To calculate the light color,
        multiply the base color with the intensity. */
        float mIntensity;

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
            const Color& color, 
            const float intensity = 1.0f,
            const String& lightName = ElementWriter::EMPTY_STRING );

        /** Destructor */
        virtual ~Light() {}

        /** Returns a reference to the light id */
        const String& getLightId() const { return mLightId; }

        /** Returns the light type. */
        const LightType& getLightType () const { return mLightType; }

        /** Returns a reference to the light name */
        const String& getLightName() const { return mLightName; }

        /** The color attribute. */
        const Color getColor() const { return mColor; }
        void setColor ( const Color val ) { mColor = val; }

        /** Retrieves the intensity of the light. To calculate the light color,
        multiply the base color with the intensity.
        @return The intensity of the light. */
        const float getIntensity() const { return mIntensity; }
 
        /** Sets the intensity of the light. To calculate the light color,
        multiply the base color with the intensity.
        @param intensity The intensity of the light. */
        void setIntensity ( float intensity ) { mIntensity = intensity; }

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        const float getConstantAttenuation() const { return mConstantAttenuation; }
        void setConstantAttenuation ( const float val ) { mConstantAttenuation = val; }

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        const float getLinearAttenuation() const { return mLinearAttenuation; }
        void setLinearAttenuation ( const float val ) { mLinearAttenuation = val; }

        /** 
        * The <constant_attenuation>, <linear_attenuation>, and 
        * <quadratic_attenuation> are used to calculate the total attenuation 
        * of this light given a distance. The equation used is
        * A = constant_attenuation +
        *     ( Dist * linear_attenuation ) +
        *     (( Dist^2 ) * quadratic_attenuation ). 
        */ 
        const float getQuadraticAttenuation() const { return mQuadraticAttenuation; }
        void setQuadraticAttenuation ( const float val ) { mQuadraticAttenuation = val; }

        /** 
        * Contains a floating-point number that describes the distance 
        * to the far clipping plane.
        */
        const float getZFar() const { return mZFar; }
        void setZFar ( const float val ) { mZFar = val; }

        /**
        * The <falloff_angle> and <falloff_exponent> are used to specify the 
        * amount of attenuation based on the direction of the light.
        */
        const float getFallOffAngle() const { return mFallOffAngle; }
        void setFallOffAngle ( const float val ) { mFallOffAngle = val; }

        /**
        * The <falloff_angle> and <falloff_exponent> are used to specify the 
        * amount of attenuation based on the direction of the light.
        */
        const float getFallOffExponent() const { return mFallOffExponent; }
        void setFallOffExponent ( const float val ) { mFallOffExponent = val; }

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
            const Color& color, 
            const float intensity = 1.0f,
            const String& lightName = ElementWriter::EMPTY_STRING )
        : Light ( streamWriter, lightId, AMBIENT, color, intensity, lightName )
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
            const Color& color, 
            const float intensity = 1.0f,
            const String& lightName = ElementWriter::EMPTY_STRING )
        : Light ( streamWriter, lightId, DIRECTIONAL, color, intensity, lightName ) 
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
            const Color& color, 
            const float intensity = 1.0f,
            const String& lightName = ElementWriter::EMPTY_STRING )
        : Light ( streamWriter, lightId, POINT, color, intensity, lightName )
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
            const Color& color, 
            const float intensity = 1.0f,
            const String& lightName = ElementWriter::EMPTY_STRING )
        : Light ( streamWriter, lightId, POINT, color, intensity, lightName )
        {}


        virtual ~SpotLight() {}

    protected:

        /** Adds the light type specific information. */
        void addTypeSpecificInfos () const;

    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIGHT_H__