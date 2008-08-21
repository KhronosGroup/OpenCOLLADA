/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_EFFECT_H__
#define __COLLADASTREAMWRITER_EFFECT_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADAColor.h"
#include "COLLADAColorOrTexture.h"
#include "COLLADASWC.h"
#include <vector>
#include <map>


namespace COLLADA
{

    /** A class to write a @a \<profile_COMMON\> element to the stream*/
    class EffectProfile : public ElementWriter, public BaseExtraTechnique
    {

    public:

        /** The list of the lighting models supported by the COMMON profile of COLLADA. */
        enum ShaderTypes
        {
            /** The constant lighting model.
            This lighting model uses the emissive color everywhere, without
            any complex lighting calculations. It also uses the translucency
            factor and the translucency color, by multiplying them together
            and applying them to your standard alpha channel according to the
            final lighting color.*/
            CONSTANT,

            /** The Lambert lighting model.
            This lighting model improves on the constant lighting model by
            using the dot-product between the normalized light vectors and the
            polygon normals to determine how much light should affect each polygon.
            This value is multiplied to the diffuse color and (1 + the ambient color). */
            LAMBERT,

            /** The Phong lighting model.
            This lighting model improves on the Lambert lighting model by
            calculating how much light is reflected by the polygons into the viewer's eye.
            For this calculation, the shininess, the specular color and the reflectivity is used. */
            PHONG,

            /** The Blinn lighting model.
            This lighting model improves on the Lambert lighting model by
            calculating how much light is reflected by the polygons into the viewer's eye.
            For this calculation, the shininess, the specular color and the reflectivity is used. */
            BLINN,

            /** Not a valid lighting model. */
            UNSPECIFIED
        };

        enum Opaque
        {
            UNSPECIFIED_OPAQUE,
            A_ONE,
            RGB_ZERO,
            A_ZERO,
            RGB_ONE
        };

    private:

        friend class LibraryEffects;

        /** The technique sid that is used, if no other is specified*/
        static const String DEFAULT_TECHNIQUE_SID;

        /** The sid of the technique element*/
        String mTechniqueSid;

        ShaderTypes mShaderType;

        /** The ColorOrTexture-values can be sampled. */
        ColorOrTexture mEmission;
        String mEmissionSid;

        ColorOrTexture mAmbient;
        String mAmbientSid; 

        ColorOrTexture mDiffuse;
        String mDiffuseSid; 

        ColorOrTexture mSpecular;
        String mSpecularSid;

        ColorOrTexture mTransparent;
        String mTransparentSid;

        ColorOrTexture mReflective;
        String mReflectiveSid;

        /** Just if we want to add an extra technique element to the current effect
            with the information of a texture. */
        ColorOrTexture mExtraTechniqueColorOrTexture;
        String mExtraTechniqueColorOrTextureSid;

        /** A list with all sampled image ids, which was already written.
        So you will not sample the same object a second time. */
        std::vector<String> mSampledImages;

        double mShininess;
        String mShininessSid;

        double mReflectivity;
        String mReflectivitySid;

        Opaque mOpaque;
        String mOpaqueSid;

        double mTransparency;
        String mTransparencySid;

        double mIndexOfRefraction;
        String mIndexOfRefractionSid;

    public:

        /** Constructor
        @param streamWriter The stream writer the @a \<profile_COMMON\> element should be written to
        */
        EffectProfile ( StreamWriter* streamWriter );
        virtual ~EffectProfile(){};

        /** Sets the sid of the @a \<technique\> element*/
        void setTechniqueSid ( const String& techniqueSid )
        {
            mTechniqueSid = techniqueSid;
        }

        /** Returns the sid of the @a \<technique\> element*/
        const String& getTechniqueSid () const 
        {
            return mTechniqueSid;
        }

        /** Sets the shader type to @a shaderType */
        void setShaderType( ShaderTypes shaderType )
        {
            mShaderType = shaderType;
        }

        /** Returns the shader type */
        ShaderTypes getShaderType() const
        {
            return mShaderType;
        }

        /** Sets the emission to @a emission */
        void setEmission( const ColorOrTexture& emission, const bool useDefaultSid = false, const String& sid = "" )
        {
            mEmission = emission;
            if ( useDefaultSid ) mEmissionSid = CSWC::COLLADA_ELEMENT_EMISSION;
            else mEmissionSid = sid;
        }

        /** Returns a reference to the emission*/
        ColorOrTexture& getEmission()
        {
            return mEmission;
        }

        /** Sets the ambient to @a ambient */
        void  setAmbient( const ColorOrTexture& ambient, const bool useDefaultSid = false, const String& sid = "" )
        {
            mAmbient = ambient;
            if ( useDefaultSid ) mAmbientSid = CSWC::COLLADA_ELEMENT_AMBIENT;
            else mAmbientSid = sid;
        }

        /** Returns a reference to ambient*/
        ColorOrTexture& getAmbient()
        {
            return mAmbient;
        }

        /** Sets the diffuse to @a diffuse */
        void  setDiffuse( const ColorOrTexture& diffuse, const bool useDefaultSid = false, const String& sid = "" )
        {
            mDiffuse = diffuse;
            if ( useDefaultSid ) mDiffuseSid = CSWC::COLLADA_ELEMENT_DIFFUSE;
            else mDiffuseSid = sid;
        }

        /** Returns a reference to diffuse*/
        ColorOrTexture& getDiffuse()
        {
            return mDiffuse;
        }

        /** Sets the specular to @a specular */
        void  setSpecular( const ColorOrTexture& specular, const bool useDefaultSid = false, const String& sid = "" )
        {
            mSpecular = specular;
            if ( useDefaultSid ) mSpecularSid = CSWC::COLLADA_ELEMENT_SPECULAR;
            else mSpecularSid = sid;
        }

        /** Returns a reference to specular*/
        ColorOrTexture& getSpecular()
        {
            return mSpecular;
        }

        /** Sets the shininess to @a shininess */
        void  setShininess( double shininess, const bool useDefaultSid = false, const String& sid = "" )
        {
            mShininess = shininess;
            if ( useDefaultSid ) mShininessSid = CSWC::COLLADA_ELEMENT_SHININESS;
            else mShininessSid = sid;
        }

        /** Returns the shininess*/
        double getShininess() const
        {
            return mShininess;
        }

        /** Sets the reflective to @a reflective */
        void  setReflective( const ColorOrTexture& reflective, const bool useDefaultSid = false, const String& sid = "" )
        {
            mReflective = reflective;
            if ( useDefaultSid ) mReflectiveSid = CSWC::COLLADA_ELEMENT_REFLECTIVE;
            else mReflectiveSid = sid;
        }

        /** Returns a reference to reflective*/
        ColorOrTexture& getReflective()
        {
            return mReflective;
        }

        /** Sets the reflectivity to @a reflectivity */
        void  setReflectivity( double reflectivity, const bool useDefaultSid = false, const String& sid = "" )
        {
            mReflectivity = reflectivity;
            if ( useDefaultSid ) mReflectivitySid = CSWC::COLLADA_ELEMENT_REFLECTIVITY;
            else mReflectivitySid = sid;
        }

        /** Sets the transparent to @a transparent */
        void setTransparent( const ColorOrTexture& transparent, const bool useDefaultSid = false, const String& sid = "" )
        {
            mTransparent = transparent;
            if ( useDefaultSid ) mTransparentSid = CSWC::COLLADA_ELEMENT_TRANSPARENT;
            else mTransparentSid = sid;
        }

        /** Returns a reference to transparent*/
        ColorOrTexture& getTransparent()
        {
            return mTransparent;
        }

        /** Sets the opaque attribute of transparent to @a opaque */
        void setOpacity( Opaque opaque, const bool useDefaultSid = false, const String& sid = "" )
        {
            mOpaque = opaque;
            if ( useDefaultSid ) mOpaqueSid = CSWC::COLLADA_ATTRIBUTE_OPAQUE;
            else mOpaqueSid = sid;
        }

        /** Sets the opaque attribute of transparent to @a opaque */
        Opaque getOpacity()
        {
            return mOpaque;
        }

        /** Sets the transparency to @a transparency */
        void  setTransparency( double transparency, const bool useDefaultSid = false, const String& sid = "" )
        {
            mTransparency = transparency;
            if ( useDefaultSid ) mTransparencySid = CSWC::COLLADA_ELEMENT_TRANSPARENCY;
            else mTransparencySid = sid;
        }

        /** Sets the indexOfRefrection to @a indexOfRefrection */
        void  setIndexOfRefraction( double indexOfRefrection, const bool useDefaultSid = false, const String& sid = "" )
        {
            mIndexOfRefraction = indexOfRefrection;
            if ( useDefaultSid ) mIndexOfRefractionSid = CSWC::COLLADA_ELEMENT_INDEX_OF_REFRACTION;
            else mIndexOfRefractionSid = sid;
        }

        /**
        * Adds extra technique tags to the current effect and writes 
        * the child element with the given colorOrTexture element in the tags.
        * You just can add one extra technique texture.
        * @param profileName Name of the technique.
        * @param childElement Name of the colorOrTexture child element.
        * @param colorOrTexture The colorOrTexture to set.
        */
        void setExtraTechniqueColorOrTexture ( const ColorOrTexture& colorOrTexture, const String& sid = "" )
        {
            mExtraTechniqueColorOrTexture = colorOrTexture;
            mExtraTechniqueColorOrTextureSid = sid;
        }

    private:

        /** Adds the EffectProfile to the stream*/
        void add( bool closeProfile = true );

        /** Add the samplers required by the textures to the stream*/
        void addSamplers();

        /** Add the sampler required by @a colorOrTexture to the stream*/
        void addSampler ( const ColorOrTexture &colorOrTexture );

        /** Returns the element name of the shader*/
        static const String& getShaderTypeName ( ShaderTypes shaderType );

        /** Returns a reference to the COLLADA name of the surface type*/
        static const String& getSurfaceTypeString ( Texture::SurfaceType surfaceType );

        /** Returns a reference to the COLLADA name of the SamplerFilter*/
        static const String& getSamplerFilterString ( Texture::SamplerFilter samplerFilter );

        /** Returns a reference to the COLLADA name of the wrap mode. */
        static const String& getWrapModeString ( Texture::WrapMode wrapMode );

        /** Returns a reference to the COLLADA name of the opaque type*/
        static const String& getOpaqueString ( Opaque opaque );

        /** Adds element @a elementName and adds @a colorOrTexture to it.*/
        void addColorOrTexture ( 
            const String &elementName, 
            const ColorOrTexture &colorOrTexture, 
            const String &elementSid, 
            Opaque opaque = UNSPECIFIED_OPAQUE, 
            const String &opaqueSid = "" ) const;

        /** Adds element @a elementName and adds @a number to it.*/
        void addFloat ( 
            const String &elementName, 
            const double &number, 
            const String &elementSid ) const;

        /**
        * Adds extra technique tags to the current effect and writes 
        * the child element with the given colorOrTexture element in the tags.
        * You just can add one extra technique texture.
        * @param profileName Name of the technique.
        * @param childElement Name of the colorOrTexture child element.
        * @param colorOrTexture The colorOrTexture to set.
        */
        void addExtraTechniqueColorOrTexture ( 
            const ColorOrTexture &colorOrTexture, 
            const String &elementSid );
    };


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_EFFECT_H__