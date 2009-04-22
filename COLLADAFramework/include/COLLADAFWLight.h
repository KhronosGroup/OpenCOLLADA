/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_LIGHT_H__
#define __COLLADAFW_LIGHT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWColor.h"


namespace COLLADAFW
{

	/** A light of one of the types: ambient, directional, point, spot.
	Formula for attenuation:
	A = constant_attenuation + ( D * linear_attenuation ) + ( D^2 * quadratic_attenuation )*/
	class Light : public ObjectTemplate < COLLADA_TYPE::LIGHT >
	{
	public:

		/** All possible types of light*/
		enum LightType
		{	
			UNDEFINED,
			AMBIENT_LIGHT,
		    DIRECTIONAL_LIGHT,
			POINT_LIGHT,
			SPOT_LIGHT
		};

	private:

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

		/** The name of the light.*/
		String mName;

		/** The type of the light.*/
		LightType mLightType;

		/** The color of the light. Has only rgb values, no alpha. 
		Used by all light types.*/
		Color mColor;

		/** The constant coefficient in the attenuation formula.
		Used by point and spot lights.*/
		double mConstantAttenuation;

		/** The linear coefficient in the attenuation formula.
		Used by point and spot lights.*/
		double mLinearAttenuation;

		/** The quadratic coefficient in the attenuation formula.
		Used by point and spot lights.*/
		double mQuadraticAttenuation;

		/** The fall off angle.
		Used by spot and  lights.*/
		double mFallOffAngle;

		/** The fall off exponent.
		Used by spot and  lights.*/
		double mFallOffExponent;

	public:

		/** @param objectId The object id of the camera.*/
		Light( ObjectId objectId );

        /** Destructor. */
		virtual ~Light();

        /**
        * The original object id, if it in the original file format exist. 
        */
        const COLLADAFW::String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const COLLADAFW::String& val ) { mOriginalId = val; }

		/** Returns name of the light.*/
		const COLLADAFW::String& getName() const { return mName; }

		/** Sets name of the light.*/
		void setName(const COLLADAFW::String& name) { mName = name; }

		/** Returns the type of the light.*/
		LightType getLightType() const { return mLightType; }

		/** Sets the type of the light.*/
		void setLightType(LightType lightType) { mLightType = lightType; }

		/** Returns the color of the light. Has only rgb values, no alpha. 
		Used by all light types.*/
		const Color& getColor() const { return mColor; }

		/** Returns the color of the light. Has only rgb values, no alpha. 
		Used by all light types.*/
		Color& getColor() { return mColor; }

		/** Sets the color of the light. Has only rgb values, no alpha. 
		Used by all light types.*/
		void setColor(const Color& color) { mColor = color; }

		/** Returns the constant coefficient in the attenuation formula.
		Used by point and spot lights.*/
		double getConstantAttenuation() const { return mConstantAttenuation; }

		/** Sets the constant coefficient in the attenuation formula.
		Used by point and spot lights.*/
		void setConstantAttenuation(double constantAttenuation) { mConstantAttenuation = constantAttenuation; }

		/** Returns the linear coefficient in the attenuation formula.
		Used by point and spot lights.*/
		double getLinearAttenuation() const { return mLinearAttenuation; }

		/** Sets the linear coefficient in the attenuation formula.
		Used by point and spot lights.*/
		void setLinearAttenuation(double linearAttenuation) { mLinearAttenuation = linearAttenuation; }

		/** Returns the quadratic coefficient in the attenuation formula.
		Used by point and spot lights.*/
		double getQuadraticAttenuation() const { return mQuadraticAttenuation; }

		/** Sets the quadratic coefficient in the attenuation formula.
		Used by point and spot lights.*/
		void setQuadraticAttenuation(double quadraticAttenuation) { mQuadraticAttenuation = quadraticAttenuation; }

		/** Returns fall off angle.
		Used by spot and  lights.*/
		double getFallOffAngle() const { return mFallOffAngle; }

		/** Sets fall off angle.
		Used by spot and  lights.*/
		void setFallOffAngle(double fallOffAngl) { mFallOffAngle = fallOffAngl; }

		/** Returns fall off exponent.
		Used by spot and  lights.*/
		double getFallOffExponent() const { return mFallOffExponent; }

		/** Sets fall off exponent.
		Used by spot and  lights.*/
		void setFallOffExponent(double fallOffAngl) { mFallOffExponent = fallOffAngl; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_LIGHT_H__
