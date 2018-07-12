/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADAFWAnimatableFloat.h"


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
		AnimatableFloat mConstantAttenuation;

		/** The linear coefficient in the attenuation formula.
		Used by point and spot lights.*/
		AnimatableFloat mLinearAttenuation;

		/** The quadratic coefficient in the attenuation formula.
		Used by point and spot lights.*/
		AnimatableFloat mQuadraticAttenuation;

		/** The fall off angle.
		Used by spot and  lights.*/
		AnimatableFloat mFallOffAngle;

		/** The fall off exponent.
		Used by spot and  lights.*/
		AnimatableFloat mFallOffExponent;

	public:

		/** @param objectId The object id of the camera.*/
		Light( const UniqueId& uniqueId );

        /** Destructor. */
		virtual ~Light();

        /**
        * The original object id, if it in the original file format exist. 
        */
        const String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const String& val ) { mOriginalId = val; }

		/** Returns name of the light.*/
		const String& getName() const { return mName; }

		/** Sets name of the light.*/
		void setName(const String& name) { mName = name; }

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
		const AnimatableFloat& getConstantAttenuation() const { return mConstantAttenuation; }

		/** Returns the constant coefficient in the attenuation formula.
		Used by point and spot lights.*/
		AnimatableFloat& getConstantAttenuation() { return mConstantAttenuation; }

		/** Sets the constant coefficient in the attenuation formula.
		Used by point and spot lights.*/
		void setConstantAttenuation(double constantAttenuation) { mConstantAttenuation = constantAttenuation; }

		/** Returns the linear coefficient in the attenuation formula.
		Used by point and spot lights.*/
		const AnimatableFloat&  getLinearAttenuation() const { return mLinearAttenuation; }

		/** Returns the linear coefficient in the attenuation formula.
		Used by point and spot lights.*/
		AnimatableFloat&  getLinearAttenuation() { return mLinearAttenuation; }

		/** Sets the linear coefficient in the attenuation formula.
		Used by point and spot lights.*/
		void setLinearAttenuation(double linearAttenuation) { mLinearAttenuation = linearAttenuation; }

		/** Returns the quadratic coefficient in the attenuation formula.
		Used by point and spot lights.*/
		const AnimatableFloat& getQuadraticAttenuation() const { return mQuadraticAttenuation; }

		/** Returns the quadratic coefficient in the attenuation formula.
		Used by point and spot lights.*/
		AnimatableFloat& getQuadraticAttenuation() { return mQuadraticAttenuation; }

		/** Sets the quadratic coefficient in the attenuation formula.
		Used by point and spot lights.*/
		void setQuadraticAttenuation(double quadraticAttenuation) { mQuadraticAttenuation = quadraticAttenuation; }

		/** Returns fall off angle.
		Used by spot and  lights.*/
		const AnimatableFloat&  getFallOffAngle() const { return mFallOffAngle; }

		/** Returns fall off angle.
		Used by spot and  lights.*/
		AnimatableFloat&  getFallOffAngle() { return mFallOffAngle; }

		/** Sets fall off angle.
		Used by spot and  lights.*/
		void setFallOffAngle(double fallOffAngl) { mFallOffAngle = fallOffAngl; }

		/** Returns fall off exponent.
		Used by spot and  lights.*/
		const AnimatableFloat&  getFallOffExponent() const { return mFallOffExponent; }

		/** Returns fall off exponent.
		Used by spot and  lights.*/
		AnimatableFloat&  getFallOffExponent() { return mFallOffExponent; }

		/** Sets fall off exponent.
		Used by spot and  lights.*/
		void setFallOffExponent(double fallOffAngl) { mFallOffExponent = fallOffAngl; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_LIGHT_H__
