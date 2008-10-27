#ifndef __COLLADA_EFFECT_UTIL_H__
#define __COLLADA_EFFECT_UTIL_H__

#include <dom/domProfile_COMMON.h>
#include <vector>

namespace COLLADA
{
	/** A vector of domImage pointers. */
	typedef std::vector<domImage*> TextureImageList;

	/** Utility class with static mehtods to access effect data. */
	class EffectUtil
	{
	public:
		enum ShaderType
		{
			CONSTANT,
			PHONG,
			LAMBERT,
			BLINN,
			UNKNOWN
		};

		enum ColorType
		{
			ALL_COLORS,
			DIFFUSE, 
			SPECULAR,
			AMBIENT, 
			EMISSIVE,
			REFLECTIVE,
		};

	public:
		/** @return The fall back color: white.
		*/
		static const domFx_color_common& getFallbackColor();
		
		/** @return The default specular color: black.
		*/
		static const domFx_color_common& getDefaultSpecularColor();
		
		/** @return The default emissive color: black.
		*/
		static const domFx_color_common& getDefaultEmissiveColor();

		/** @return The default emissive color: black.
		*/
		static const domFx_color_common& getDefaultAmbientColor();

		/** @return The default emissive color: black.
		*/
		static const domFx_color_common& getDefaultReflectiveColor();

		/** Retrieves the shader type of the given effect.
			@param effect The Effect to retrieve the shader type from.
			@return the shader type.
		*/
		static const ShaderType getShaderType(const domEffectRef& effect);

		/** Retrieves the ambient color from the given effect. If the 
			effect doesn't declare an ambient color, the fall back 
			color white will be returned.
			@param effect The effect to retrieve the ambient color from.
			@param shaderType The shader type.
			@return The ambient color of the given effect.
		*/
		static const domFx_color_common& getAmbientColor(const domEffectRef& effect, const ShaderType shaderType = UNKNOWN);
		
		/** Retrieves the diffuse color from the given effect. If the 
		effect doesn't declare an diffuse color, the fall back 
		color white will be returned.
		@param effect The effect to retrieve the diffuse color from.
		@param shaderType The shader type.
		@return The diffuse color of the given effect.
		*/
		static const domFx_color_common& getDiffuseColor(const domEffectRef& effect, const ShaderType shaderType = UNKNOWN);		
		
		/** Retrieves the specular color from the given effect. If the 
		effect doesn't declare an specular color, the default 
		color black will be returned.
		@param effect The effect to retrieve the specular color from.
		@param shaderType The shader type.
		@return The specular color of the given effect.
		*/
		static const domFx_color_common& getSpecularColor(const domEffectRef& effect, const ShaderType shaderType = UNKNOWN);
		
		/** Retrieves the emissive color from the given effect. If the 
		effect doesn't declare an emissive color, the default
		color black will be returned.
		@param effect The effect to retrieve the emissive color from.
		@param shaderType The shader type.
		@return The emissive color of the given effect.
		*/
		static const domFx_color_common& getEmissiveColor(const domEffectRef& effect, const ShaderType shaderType = UNKNOWN);

		/** Retrieves the reflective color from the given effect. If the 
		effect doesn't declare an reflective color, the default
		color black will be returned.
		@param effect The effect to retrieve the reflective color from.
		@param shaderType The shader type.
		@return The reflective color of the given effect.
		*/
		static const domFx_color_common& getReflectiveColor(const domEffectRef& effect, const ShaderType shaderType = UNKNOWN);
		
		/** Retrieves the specularity or roughness of the specular 
			reflection lobe. If the effect doesn't declare shininess,
			the default value 0 will be returned.
			@param effect The effect to retrieve the shininess from. 
			@param shaderType The shader type.
			@return The shininess of the given effect.
		*/
		static float getShininess(const domEffectRef& effect, const ShaderType shaderType = UNKNOWN);
		
		/** Returns the amount of perfectly refracted light added to the 
			reflected color as a scalar value between 0.0 and 1.0. If the 
			given effect doesn't declare transparency the default value 1.0
			(not transparent) will be returned.
			@param effect The effect to retrieve the transparency value from.
			@param shaderType The shader type.
			@return The transparency declared in the given effect.
		*/
		static float getTransparency(const domEffectRef& effect, const ShaderType shaderType = UNKNOWN);
		
        static domCommon_transparent_typeRef getTransparent(const domEffectRef& effect, const ShaderType shaderType = UNKNOWN);

        /** Retrieves a list of domImages which are used by the given effect.
			@param effect The effect to retrieve the list of domImages.
			@param shaderType The shader type.
			@param list The list where the pointers to the used domImages are stored.
		*/
		static void getTextureImages(const domEffectRef& effect, TextureImageList& list, const ColorType colorType = ALL_COLORS, const ShaderType shaderType = UNKNOWN);

	private:
		/** Retrieves the common profile element from the given effect.
			@param effect The effect to retrieve the common profile element.
			@return The common profile for the given effect. The returned shared pointer can be null.
		*/
		static domProfile_COMMONRef getCommonProfile(const domEffectRef& effect);

		/** Retrieves the common phong element from the given effect.
		@param effect The effect to retrieve the common phong element.
		@return The common phong for the given effect. The returned shared pointer can be null.
		*/
		static domProfile_COMMON::domTechnique::domPhongRef getPhong(const domEffectRef& effect);		

		/** Retrieves the common lambert element from the given effect.
		@param effect The effect to retrieve the common lambert element.
		@return The common lambert for the given effect. The returned shared pointer can be null.
		*/
		static domProfile_COMMON::domTechnique::domLambertRef getLambert(const domEffectRef& effect);		

		/** Retrieves the common blinn element from the given effect.
		@param effect The effect to retrieve the common blinn element.
		@return The common blinn for the given effect. The returned shared pointer can be null.
		*/
		static domProfile_COMMON::domTechnique::domBlinnRef getBlinn(const domEffectRef& effect);		

		/** Retrieves the common constant element from the given effect.
		@param effect The effect to retrieve the common constant element.
		@return The common constant for the given effect. The returned shared pointer can be null.
		*/
		static domProfile_COMMON::domTechnique::domConstantRef getConstant(const domEffectRef& effect);		
	};
}

#endif // __COLLADA_EFFECT_UTIL_H__