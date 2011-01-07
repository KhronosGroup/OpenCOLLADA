/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_EFFECT_H__
#define __COLLADASTREAMWRITER_EFFECT_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWColor.h"
#include "COLLADASWColorOrTexture.h"
#include "COLLADASWConstants.h"
#include "COLLADABUURI.h"
#include <vector>
#include <map>


namespace COLLADASW
{

    /** A class to write a @a \<profile_COMMON\> element to the stream*/
    class EffectProfile : public ElementWriter, public BaseExtraTechnique
    {

    public:

        /** The possible profile types. */
        enum ProfileType
        {
            COMMON, 
            CG,
            GLES,
            GLSL
        };

        /** The list of the lighting models supported by the COMMON profile of COLLADASW. */
        enum ShaderType
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

		typedef std::list< std::pair<String, String> > StringPairList;

    private:

        friend class LibraryEffects;

		struct ExtraColorOrTextureEntry
		{
			ColorOrTexture colorOrTexture;
			String elementSid;
			StringPairList attributes;
		};

		typedef std::map<String, std::vector<ExtraColorOrTextureEntry> > ExtraColorOrTextureEntryByProfileName;

        /**
         * A text string containing the unique identifier of the element. 
         * This value must be unique within the instance document. Optional.
         */
        String mEffectProfileId;

        /** The include sid and uri for the cg profile. */
        String mIncludeSid;
        URI mIncludeURI;

        /** For writing code directly into code tags. */
        String mCodeSid;
        String mCode;

        /** The technique sid that is used, if no other is specified*/
        static const String DEFAULT_TECHNIQUE_SID;

        /** The sid of the technique element*/
        String mTechniqueSid;

        TagCloser mTechniqueCloser;

        /** The current profile type. */
        ProfileType mProfileType;

        TagCloser mProfileCloser;

        /** The current shader type. */
        ShaderType mShaderType;

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
		ExtraColorOrTextureEntryByProfileName mExtraTechniqueColorOrTextureEntries;

        /** A list with all sampled image ids, which was already written.
        So you will not sample the same object a second time. */
        std::vector<String> mSampledImages;

        double mShininess;
        String mShininessSid;

        double mReflectivity;
        String mReflectivitySid;

        Opaque mOpaque;

        double mTransparency;
        String mTransparencySid;

        double mIndexOfRefraction;
        String mIndexOfRefractionSid;

        /** The extra tag elements under the effect profile. */
        BaseExtraTechnique mProfileExtra;

        /** The extra tag elements under the effect profile's technique element. */
        BaseExtraTechnique mProfileTechniqueExtra;

        /** The extra tag elements under the effect profile's technique element. */
        BaseExtraTechnique mProfileTechniqueTextureExtra;

    public:

        /** Constructor
        @param streamWriter The stream writer the @a \<profile_COMMON\> element should be written to
        */
        EffectProfile ( StreamWriter* streamWriter, const String& effectProfileId = "" );
        virtual ~EffectProfile(){};

        /** The extra tag elements under the effect profile. */
        BaseExtraTechnique& getProfileExtra () { return mProfileExtra; }

        /** The extra tag elements under the effect profile's technique element. */
        BaseExtraTechnique& getProfileTechniqueExtra () { return mProfileTechniqueExtra; }

        /**
        * A text string containing the unique identifier of the element. 
        * This value must be unique within the instance document. Optional.
        */
        const COLLADASW::String& getEffectProfileId () const { return mEffectProfileId; }
        void setEffectProfileId ( const COLLADASW::String& val ) { mEffectProfileId = val; }

        /** The current profile type. */
        const EffectProfile::ProfileType& getProfileType () const { return mProfileType; }

        /** The current profile type. */
        void setProfileType ( const EffectProfile::ProfileType& val ) { mProfileType = val; }

        /** Opens the current profile. */
        void openProfile ();

        /** Close the current profile. */
        void closeProfile ();

        /** Adds the EffectProfile to the stream*/
        void addProfileElements ();

        /** Opens a technique element with the given sid.  */
        void openTechnique ( const String& techniqueSid );

        /** Close the current technique element. */
        void closeTechnique ();

        /** Sets the sid of the @a \<technique\> element*/
        void setTechniqueSid ( const String& techniqueSid );

        /** Returns the sid of the @a \<technique\> element*/
        const String& getTechniqueSid () const;

        /** Sets the shader type to @a shaderType */
        void setShaderType( ShaderType shaderType );

        /** Returns the shader type */
        ShaderType getShaderType() const;

        /** Reference to the included file. */
        void setInclude ( const URI &includeUri, const String &sid="" );

        const URI & getIncludeURI() { return mIncludeURI; }

        /** For writing code directly into code tags. */
        const String& getCode () const;
        void setCode ( const String &code, const String &sid="" );

        /** Sets the emission to @a emission */
        void setEmission( 
            const ColorOrTexture& emission, 
            const bool useDefaultSid = false, 
            const String& sid = "" );

		/** Returns the default sid used for the emission element*/ 
		static const String& getEmissionDefaultSid();

        /** Returns a reference to the emission*/
        ColorOrTexture& getEmission();

        /** Sets the ambient to @a ambient */
        void  setAmbient( 
            const ColorOrTexture& ambient, 
            const bool useDefaultSid = false, 
            const String& sid = "" );

		/** Returns the default sid used for the ambient element*/ 
		static const String& getAmbientDefaultSid();

        /** Returns a reference to ambient*/
        ColorOrTexture& getAmbient();

        /** Sets the diffuse to @a diffuse */
        void  setDiffuse( 
            const ColorOrTexture& diffuse, 
            const bool useDefaultSid = false, 
            const String& sid = "" );

		/** Returns the default sid used for the diffuse element*/ 
		static const String& getDiffuseDefaultSid();

        /** Returns a reference to diffuse*/
        ColorOrTexture& getDiffuse();

        /** Sets the specular to @a specular */
        void  setSpecular( 
            const ColorOrTexture& specular, 
            const bool useDefaultSid = false, 
            const String& sid = "" );

		/** Returns the default sid used for the specular element*/ 
		static const String& getSpecularDefaultSid();

        /** Returns a reference to specular*/
        ColorOrTexture& getSpecular();

        /** Sets the shininess to @a shininess */
        void  setShininess( double shininess, const bool useDefaultSid = false, const String& sid = "" );

		/** Returns the default sid used for the shininess element*/ 
		static const String& getShininessDefaultSid() { return CSWC::CSW_ELEMENT_SHININESS; }

        /** Returns the shininess*/
        double getShininess() const;

        /** Sets the reflective to @a reflective */
        void  setReflective( 
            const ColorOrTexture& reflective, 
            const bool useDefaultSid = false, 
            const String& sid = "" );

		/** Returns the default sid used for the reflective element*/ 
		static const String& getReflectiveDefaultSid();

        /** Returns a reference to reflective*/
        ColorOrTexture& getReflective();

        /** Sets the reflectivity to @a reflectivity */
        void  setReflectivity( double reflectivity, const bool useDefaultSid = false, const String& sid = "" );

		/** Returns the default sid used for the reflectivity element*/ 
		static const String& getReflectivityDefaultSid();

        /** Sets the transparent to @a transparent */
        void setTransparent( 
            const ColorOrTexture& transparent, 
            const bool useDefaultSid = false, 
            const String& sid = "" );

		/** Returns the default sid used for the transparent element*/ 
		static const String& getTransparentDefaultSid();

        /** Returns a reference to transparent*/
        ColorOrTexture& getTransparent();

        /** Sets the opaque attribute of transparent to @a opaque */
        void setOpaque( Opaque opaque);

        /** Sets the opaque attribute of transparent to @a opaque */
        Opaque getOpaque();

        /** Sets the transparency to @a transparency */
        void  setTransparency( double transparency, const bool useDefaultSid = false, const String& sid = "" );

		/** Returns the default sid used for the transparency element*/ 
		static const String& getTransparencyDefaultSid() { return CSWC::CSW_ELEMENT_TRANSPARENCY; }

        /** Sets the indexOfRefrection to @a indexOfRefrection */
        void  setIndexOfRefraction( 
            double indexOfRefrection, 
            const bool useDefaultSid = false, 
            const String& sid = "" );

		/** Returns the default sid used for the indexOfRefrection element*/ 
		static const String& getIndexOfRefractionSid();

        /**
        * Adds extra technique tags to the current effect and writes 
        * the child element with the given colorOrTexture element in the tags.
        * @param profileName Name of the technique.
        * @param childElement Name of the colorOrTexture child element.
        * @param colorOrTexture The colorOrTexture to set.
        */
        void addExtraTechniqueColorOrTexture ( const ColorOrTexture& colorOrTexture, const StringPairList& attributes = StringPairList(), const String& sid = "" );

        /** Add the sampler required by @a colorOrTexture to the stream*/
        void addSampler ( const ColorOrTexture &colorOrTexture );

    private:

        /** Adds the EffectProfile to the stream*/
        void addProfileCommon ();

        /** Adds the EffectProfile to the stream*/
        void addProfileCG ();
        void addProfileGLSL ();
        void addProfileGLES ();

        /** Add the samplers required by the textures to the stream*/
        void addSamplers();

        /** Returns the element name of the profile type. */
        static const String& getProfileTypeName ( ProfileType profileType );

        /** Returns the element name of the shader. */
        static const String& getShaderTypeName ( ShaderType shaderType );

        /** Returns a reference to the COLLADASW name of the opaque type*/
        static const String& getOpaqueString ( Opaque opaque );

        /** Adds element @a elementName and adds @a colorOrTexture to it.*/
        void addColorOrTexture ( 
            const String &elementName, 
            const ColorOrTexture &colorOrTexture, 
            const String &elementSid, 
			StringPairList attributes = StringPairList(),
            Opaque opaque = UNSPECIFIED_OPAQUE ) const;

        /** Adds element @a elementName and adds @a number to it.*/
        void addFloat ( 
            const String &elementName, 
            const double &number, 
            const String &elementSid ) const;

        /**
        * Adds extra technique tags to the current effect and writes 
        * the child element with the given colorOrTexture element in the tags.
        * @param profileName Name of the technique.
        * @param childElement Name of the colorOrTexture child element.
        * @param colorOrTexture The colorOrTexture to set.
        */
        void addExtraTechniqueColorOrTextures ( 
			const ExtraColorOrTextureEntryByProfileName &entriesByProfileName ) const;
    };


} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_EFFECT_H__
