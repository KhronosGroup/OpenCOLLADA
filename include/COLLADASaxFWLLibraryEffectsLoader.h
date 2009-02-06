/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYEFFECTSSLOADER_H__
#define __COLLADASAXFWL_LIBRARYEFFECTSSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADAFWEffectCommon.h"

namespace COLLADAFW
{
	class Effect;
}



namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class LibraryEffectsLoader : public FilePartLoader 
	{
	private:
		enum Profile
		{
			PROFILE_BRIDGE,
			PROFILE_CG,
			PROFILE_GLES,
			PROFILE_GLES2,
			PROFILE_GLSL,
			PROFILE_COMMON,
			PROFILE_UNKNOWN
		};

		enum ShaderParameterTypes
		{
			SHADER_PARAMETER_EMISSION,
			SHADER_PARAMETER_AMBIENT,
			SHADER_PARAMETER_DIFFUSE,
			SHADER_PARAMETER_SPECULAR,
			SHADER_PARAMETER_SHININESS,
			SHADER_PARAMETER_REFLECTIVE,
			SHADER_PARAMETER_REFLECTIVITY,
			SHADER_PARAMETER_TRANSPARANT,
			SHADER_PARAMETER_TRANSPARANCY,
			SHADER_PARAMETER_INDEX_OF_REFRECTION,
			UNKNOWN_SHADER_TYPE
		};

	private:
		/** The effect currently being imported.*/
		COLLADAFW::Effect* mCurrentEffect;

		/** The current profile.*/
		Profile mCurrentProfile;

		/** The type of the current shader parameter.*/
		ShaderParameterTypes mCurrentShaderParameterType;

		/** The index of the next color component to read.*/
		size_t mCurrentColorValueIndex;
	
	public:

        /** Constructor. */
		LibraryEffectsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryEffectsLoader();


		/** Creates a new current effect.*/
		virtual bool begin__effect( const effect__AttributeData& attributeData );

		/** Sends current material to the writer an deletes it afterwards.*/
		virtual bool end__effect();


		/** Set the current profile to PROFILE_COMMON. Create and append common effect to current 
		effect.*/
		virtual bool begin__profile_COMMON( const profile_COMMON__AttributeData& attributeData );

		/** Set the current profile to unknown.*/
		virtual bool end__profile_COMMON();

		
		/** Set the shader type of the current profile.*/
		virtual bool begin__technique__constant();

		/** We don't need to do anything here.*/
		virtual bool end__technique__constant(){return true;}


		/** Set the shader type of the current profile.*/
		virtual bool begin__lambert();

		/** We don't need to do anything here.*/
		virtual bool end__lambert(){return true;}


		/** Set the shader type of the current profile.*/
		virtual bool begin__phong();

		/** We don't need to do anything here.*/
		virtual bool end__phong(){return true;}

		/** Set the color or texture kind.*/
		virtual bool begin__phong__emission(){ return true;}
		virtual bool end__phong__emission() {return true;}
		virtual bool begin__phong__ambient(){return true;}
		virtual bool end__phong__ambient(){return true;}
		virtual bool begin__phong__diffuse(){return true;}
		virtual bool end__phong__diffuse(){return true;}
		virtual bool begin__phong__specular(){return true;}
		virtual bool end__phong__specular(){return true;}
		virtual bool begin__phong__shininess(){return true;}
		virtual bool end__phong__shininess(){return true;}
		virtual bool begin__phong__reflective(){return true;}
		virtual bool end__phong__reflective(){return true;}
		virtual bool begin__phong__reflectivity(){return true;}
		virtual bool end__phong__reflectivity(){return true;}
		virtual bool begin__phong__transparent( const transparent__AttributeData& attributeData ){return true;}
		virtual bool end__phong__transparent(){return true;}
		virtual bool begin__phong__transparency(){return true;}
		virtual bool end__phong__transparency(){return true;}
		virtual bool begin__phong__index_of_refraction(){return true;}
		virtual bool end__phong__index_of_refraction(){return true;}


		/** Set the shader type of the current profile.*/
		virtual bool begin__blinn();

		/** We don't need to do anything here.*/
		virtual bool end__blinn(){return true;}


		/** Sets the shader parameter type.*/
		virtual bool begin__emission__color( const emission__color__AttributeData& attributeData );
		/** Resets the shader parameter type.*/
		virtual bool end__emission__color();
		/** Stores color data into the correct color object.*/
		virtual bool data__emission__color( const double* value, size_t length );

		/** Sets the shader parameter type.*/
		virtual bool begin__ambient__color( const ambient__color__AttributeData& attributeData );
		/** Resets the shader parameter type.*/
		virtual bool end__ambient__color();
		/** Stores color data into the correct color object.*/
		virtual bool data__ambient__color( const double* value, size_t length );


		/** Sets the shader parameter type.*/
		virtual bool begin__diffuse__color( const diffuse__color__AttributeData& attributeData );
		/** Resets the shader parameter type.*/
		virtual bool end__diffuse__color();
		/** Stores color data into the correct color object.*/
		virtual bool data__diffuse__color( const double* value, size_t length );


		/** Sets the shader parameter type.*/
		virtual bool begin__specular__color( const specular__color__AttributeData& attributeData );
		/** Resets the shader parameter type.*/
		virtual bool end__specular__color();
		/** Stores color data into the correct color object.*/
		virtual bool data__specular__color( const double* value, size_t length );

		/** Sets the shader parameter type.*/
		virtual bool begin__reflective__color( const reflective__color__AttributeData& attributeData );
		/** Resets the shader parameter type.*/
		virtual bool end__reflective__color();
		/** Stores color data into the correct color object.*/
		virtual bool data__reflective__color( const double* value, size_t length );

		/** Sets the shader parameter type.*/
		virtual bool begin__transparent__color( const transparent__color__AttributeData& attributeData );
		/** Resets the shader parameter type.*/
		virtual bool end__transparent__color();
		/** Stores color data into the correct color object.*/
		virtual bool data__transparent__color( const double* value, size_t length );

		/** We don't need to do anything here.*/
		virtual bool begin__shininess__float( const shininess__float__AttributeData& attributeData ){return true;}
		/** We don't need to do anything here.*/
		virtual bool end__shininess__float(){return true;}
		/** Set the value in the effect.*/
		virtual bool data__shininess__float( double value );

		/** We don't need to do anything here.*/
		virtual bool begin__reflectivity__float( const reflectivity__float__AttributeData& attributeData ){return true;}
		/** We don't need to do anything here.*/
		virtual bool end__reflectivity__float(){return true;}
		/** Set the value in the effect.*/
		virtual bool data__reflectivity__float( double value );

		/** We don't need to do anything here.*/
		virtual bool begin__transparency__float( const transparency__float__AttributeData& attributeData ){return true;}
		/** We don't need to do anything here.*/
		virtual bool end__transparency__float(){return true;}
		/** Set the value in the effect.*/
		virtual bool data__transparency__float( double value );

		/** We don't need to do anything here.*/
		virtual bool begin__index_of_refraction__float( const index_of_refraction__float__AttributeData& attributeData ){return true;}
		/** We don't need to do anything here.*/
		virtual bool end__index_of_refraction__float(){return true;}
		/** Set the value in the effect.*/
		virtual bool data__index_of_refraction__float( double value );

		/** Finishes loading a library effects.*/
		virtual bool end__library_effects();

	private:
		/** Set the shader type of the current profile.*/
		bool setCommonEffectShaderType( COLLADAFW::EffectCommon::ShaderType shaderType); 

		/** Stores color data into the correct color object.*/
		bool handleColorData( const double* value, size_t length );

		/** Stores color data into the  @a color object.*/
		bool handleColorData( const double* value, size_t length, COLLADAFW::Color& color );

	private:

        /** Disable default copy ctor. */
		LibraryEffectsLoader( const LibraryEffectsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryEffectsLoader& operator= ( const LibraryEffectsLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYEFFECTSSLOADER_H__
