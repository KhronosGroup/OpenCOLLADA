/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_EFFECT_H__
#define __COLLADASTREAMWRITER_EFFECT_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADAExtraTechnique.h"
#include <map>

namespace COLLADA
{

    class Texture : public BaseExtraTechnique
    {

    public:
        enum SurfaceType
        {
            SURFACE_TYPE_UNSPECIFIED,
            SURFACE_TYPE_NONE,
            /**< When a surface's type attribute is set to UNTYPED, its type is initially
            unknown and established later by the context in which it is used, such as by a
            texture sampler that references it. A surface of any other type may be changed
            into an UNTYPED surface at run-time, as if it were created by \<newparam\>, using
            \<setparam\>. If there is a type mismatch between a \<setparam\> operation and what
            the run-time decides the type should be, the result is profile- and
            platform-specific behavior. */
            SURFACE_TYPE_UNTYPED,
            SURFACE_TYPE_1D,
            SURFACE_TYPE_2D,
            SURFACE_TYPE_3D,
            SURFACE_TYPE_RECT,
            SURFACE_TYPE_CUBE,
            SURFACE_TYPE_DEPTH
        };

        /** Contains the texture filter functions.*/
        enum SamplerFilter
        {
            SAMPLER_FILTER_UNSPECIFIED,
            SAMPLER_FILTER_NONE,
            SAMPLER_FILTER_NEAREST,
            SAMPLER_FILTER_LINEAR,
            SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST,
            SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST,
            SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR,
            SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR
        };

        /** Contains the texture wrap modes.*/
        enum WrapMode
        {
            WRAP_MODE_UNSPECIFIED=0,
            WRAP_MODE_NONE,
            WRAP_MODE_WRAP,
            WRAP_MODE_MIRROR,
            WRAP_MODE_CLAMP,
            WRAP_MODE_BORDER
        };

        /**Constructor that sets all required attributes and the default values for optional attributes.*/
        Texture ( const String& imageID, SurfaceType surfaceType );

        /**Constructor that creates an invalid texture.*/
        Texture();

        /** Destructor */
        ~Texture() {};

        /** Chick, if the Texture is valid*/
        bool isValid() const
        {
            return ( !mImageID.empty() ) && ( mSurfaceType != SURFACE_TYPE_UNSPECIFIED );
        }

        /** Sets the texel format. */
        void setFormat ( const String format )
        {
            mFormat = format;
        }

        /** Returns the texel format*/
        const String & getFormat() const
        {
            return mFormat;
        }


        /** Sets the texcoord. */
        void setTexcoord ( const String texcoord )
        {
            mTexcoord = texcoord;
        }

        /** Returns the texcoord*/
        const String & getTexcoord() const
        {
            return mTexcoord;
        }


        /** Sets the min filter. */
        void setMinFilter ( SamplerFilter filter )
        {
            mMinFilter = filter;
        }

        /** Returns min filter*/
        SamplerFilter getMinFilter() const
        {
            return mMinFilter;
        }

        /** Sets the mag filter. */
        void setMagFilter ( SamplerFilter filter )
        {
            mMagFilter = filter;
        }

        /** Returns mag filter*/
        SamplerFilter getMagFilter() const
        {
            return mMagFilter;
        }

        /** Sets the mip filter. */
        void setMipFilter ( SamplerFilter filter )
        {
            mMipFilter = filter;
        }

        /** Returns mip filter*/
        SamplerFilter getMipFilter() const
        {
            return mMipFilter;
        }

        /** Retrieves the wrap mode (in dimension S, T or P) of the sampler.
        @return The wrap mode.*/
        WrapMode getWrapS() const
        {
            return ( WrapMode ) mWrap_s;
        }

        WrapMode getWrapT() const
        {
            return ( WrapMode ) mWrap_t;    /**< See above.*/
        }

        WrapMode getWrapP() const
        {
            return ( WrapMode ) mWrap_p;    /**< See above.*/
        }

        /** Sets the wrap mode (in dimension S, T or P) of the sampler.
        @param mode The wrap mode.*/
        void setWrapS ( WrapMode mode )
        {
            mWrap_s = mode;
        }

        void setWrapT ( WrapMode mode )
        {
            mWrap_t = mode;    /**< See above.*/
        }

        void setWrapP ( WrapMode mode )
        {
            mWrap_p = mode;    /**< See above.*/
        }

        /** Returns the image ID*/
        const String& getImageID() const
        {
            return mImageID;
        };

        const String& getImageId() const
        {
            return mImageID;
        };

        void setImageId ( String imageId )
        {
            mImageID = imageId;
        }

        /** Returns the surface type*/
        SurfaceType getSurfaceType() const
        {
            return mSurfaceType;
        }

        void setSurfaceType ( SurfaceType surfaceType )
        {
            mSurfaceType = surfaceType;
        }

        /** Returns the sid of the sampler used by this texture*/
        String getSamplerSid() const
        {
            return mImageID + SAMPLER_SID_SUFFIX;
        }

        /** Returns the sid of the surface used by this texture*/
        String getSurfaceSid() const
        {
            return mImageID + SURFACE_SID_SUFFIX;
        }

        /** comparison operator*/
        bool operator== ( const Texture& other ) const;

    private:
        static const String SAMPLER_SID_SUFFIX;
        static const String SURFACE_SID_SUFFIX;

        /** the ID of the image element assigned to the texture. Required*/
        String mImageID;

        /** surface Type. For possible values see domFx_surface_type_enum in domTypes.h. Required*/
        SurfaceType mSurfaceType;

        /** texel format. */
        String mFormat;

        /** texcoord.*/
        String mTexcoord;

        /** min filter. */
        SamplerFilter mMinFilter;

        /** mag filter. */
        SamplerFilter mMagFilter;

        /** mag filter. */
        SamplerFilter mMipFilter;

        /** Wrap modes */
        WrapMode mWrap_s;
        WrapMode mWrap_t;
        WrapMode mWrap_p;
    };



    class Color
    {

    public:
        Color ( double r, double g, double b, double a )
                : mR ( r ), mG ( g ), mB ( b ), mA ( a ) {}

        /** Creates a color with opacity 1.*/
        Color ( double r, double g, double b )
                : mR ( r ), mG ( g ), mB ( b ), mA ( 1 ) {}

        /** Creates an invalid color*/
        Color( )
                : mR ( -1 ), mG ( -1 ), mB ( -1 ), mA ( -1 ) {}

        /** Sets the values of color*/
        void set ( double r, double g, double b, double a );

        /** Return true if the color is valid, false otherwise*/
        bool isValid() const;

        /** Returns the red component*/
        double getRed() const
        {
            return mR;
        }

        /** Returns the green component*/
        double getGreen() const
        {
            return mG;
        }

        /** Returns the blue component*/
        double getBlue() const
        {
            return mB;
        }

        /** Returns the alpha component*/
        double getAlpha() const
        {
            return mA;
        }

        /** A white color object*/
        static const Color WHITE;

        /** A black color object*/
        static const Color BLACK;

    private:
        double mR;
        double mG;
        double mB;
        double mA;
    };

    /** Class that either represents a color or a texture*/

    class ColorOrTexture
    {

    public:
        /** Constructor to create a ColorOrTexture object that represents a color.
        @param color The color that should be represented.
        */
        ColorOrTexture ( Color color ) : mColor ( color ), mType ( COLOR ) {};

        /** Constructor to create a ColorOrTexture object that represents a color.
        @param texture The color that should be represented.
        */
        ColorOrTexture ( Texture texture ) : mTexture ( texture ), mType ( TEXTURE ) {};

        /** Creates an invalid CommonColorOrTextureType*/
        ColorOrTexture() : mType ( UNSPECIFIED ) {};

        /** Copy-Constructor */
        ColorOrTexture ( ColorOrTexture& cot )
        {
            mColor = cot.mColor;
            mTexture = cot.mTexture;
            mType = cot.mType;
        }

        /** Return true if the CommonColorOrTextureType is a valid color, false otherwise*/
        bool isColor() const
        {
            return ( mType == COLOR ) && ( mColor.isValid() );
        }

        /** Return true if the CommonColorOrTextureType is a valid Texture, false otherwise.*/
        bool isTexture() const
        {
            return ( mType == TEXTURE ) && ( mTexture.isValid() );
        }

        /** Return true if the CommonColorOrTextureType is a valid Texture, false otherwise.*/
        bool isValid() const
        {
            return ( mType != UNSPECIFIED ) && ( isTexture() || isColor() );
        }


        /** Returns the color */
        const Color& getColor() const
        {
            return mColor;
        }

        /** Returns the color */
        Color& getColor()
        {
            return mColor;
        }

        /** Returns the texture */
        const Texture& getTexture() const
        {
            return mTexture;
        }

        /** Returns the texture */
        Texture& getTexture()
        {
            return mTexture;
        }

    private:
        enum Type
        {
            UNSPECIFIED,
            COLOR,
            TEXTURE
        };
        Type mType;
        Color mColor;
        Texture mTexture;

    };

    /** A class to write a @a \<profile_COMMON\> element to the stream*/

    class EffectProfile : public ElementWriter
    {

    public:
        /** Constructor
        @param streamWriter The stream writer the @a \<profile_COMMON\> element should be written to
        */
        EffectProfile ( StreamWriter * streamWriter );

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

        /** Sets the sid of the @a \<technique\> element*/
        void setTechniqueSid ( const String & techniqueSid )
        {
            mTechniqueSid = techniqueSid;
        }

        /** Sets the shader type to @a shaderType */
        void  setShaderType ( ShaderTypes shaderType )
        {
            mShaderType = shaderType;
        }

        /** Returns the shader type */
        ShaderTypes  getShaderType() const
        {
            return mShaderType;
        }

        /** Sets the emission to @a emission */
        void  setEmission ( ColorOrTexture emission )
        {
            mEmission = emission;
        }

        /** Returns a reference to the emission*/
        ColorOrTexture & getEmission()
        {
            return mEmission;
        }

        /** Sets the ambient to @a ambient */
        void  setAmbient ( ColorOrTexture ambient )
        {
            mAmbient = ambient;
        }

        /** Returns a reference to ambient*/
        ColorOrTexture & getAmbient()
        {
            return mAmbient;
        }

        /** Sets the diffuse to @a diffuse */
        void  setDiffuse ( ColorOrTexture diffuse )
        {
            mDiffuse = diffuse;
        }

        /** Returns a reference to diffuse*/
        ColorOrTexture & getDiffuse()
        {
            return mDiffuse;
        }

        /** Sets the specular to @a specular */
        void  setSpecular ( ColorOrTexture specular )
        {
            mSpecular = specular;
        }

        /** Returns a reference to specular*/
        ColorOrTexture & getSpecular()
        {
            return mSpecular;
        }

        /** Sets the shininess to @a shininess */
        void  setShininess ( double shininess )
        {
            mShininess = shininess;
        }

        /** Returns the shininess*/
        double  getShininess() const
        {
            return mShininess;
        }

        /** Sets the reflective to @a reflective */
        void  setReflective ( ColorOrTexture reflective )
        {
            mReflective = reflective;
        }

        /** Returns a reference to reflective*/
        ColorOrTexture & getReflective()
        {
            return mReflective;
        }

        /** Sets the reflectivity to @a reflectivity */
        void  setReflectivity ( double reflectivity )
        {
            mReflectivity = reflectivity;
        }

        /** Sets the transparent to @a transparent */
        void  setTransparent ( ColorOrTexture transparent )
        {
            mTransparent = transparent;
        }

        /** Returns a reference to transparent*/
        ColorOrTexture & getTransparent()
        {
            return mTransparent;
        }

        /** Sets the opaque attribute of transparent to @a opaque */
        void  setOpacity ( Opaque opaque )
        {
            mOpaque = opaque;
        }

        /** Sets the opaque attribute of transparent to @a opaque */
        Opaque getOpacity()
        {
            return mOpaque;
        }

        /** Sets the transparency to @a transparency */
        void  setTransparency ( double transparency )
        {
            mTransparency = transparency;
        }

        /** Sets the indexOfRefrection to @a indexOfRefrection */
        void  setIndexOfRefrection ( double indexOfRefrection )
        {
            mIndexOfRefrection = indexOfRefrection;
        }


    private:

        friend class LibraryEffects;

        /** The technique sid that is used, if no other is specified*/
        static const String DEFAULT_TECHNIQUE_SID;

        /** The sid of the technique element*/
        String mTechniqueSid;

        ShaderTypes mShaderType;

        ColorOrTexture mEmission;
        ColorOrTexture mAmbient;
        ColorOrTexture mDiffuse;
        ColorOrTexture mSpecular;

        double mShininess;

        ColorOrTexture mReflective;

        double mReflectivity;

        ColorOrTexture mTransparent;

        Opaque mOpaque;

        double mTransparency;

        double mIndexOfRefrection;

        /** Adds the EffectProfile to the stream*/
        void add() const;

        /** Add the samplers required by the textures to the stream*/
        void addSamplers() const;

        /** Add the sampler required by @a colorOrTexture to the stream*/
        void addSampler ( const ColorOrTexture & colorOrTexture ) const;

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
        void addColorOrTexture ( const String &elementName, const ColorOrTexture &colorOrTexture, Opaque opaque = UNSPECIFIED_OPAQUE ) const;

        /** Adds element @a elementName and adds @a number to it.*/
        void addFloat ( const String & elementName, const double & number ) const;

    };


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_EFFECT_H__