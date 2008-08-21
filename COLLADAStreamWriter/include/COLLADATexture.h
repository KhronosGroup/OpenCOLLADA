/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_TEXTURE_H__
#define __COLLADASTREAMWRITER_TEXTURE_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADAColor.h"
#include <vector>
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

    private:

        static const String SAMPLER_SID_SUFFIX;
        static const String SURFACE_SID_SUFFIX;

        String mSid;

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

        /** The name of the profile, if we want to add the texture as an extra technique tag. */
        String mProfileName;

        /** The name of the child element, if we have set a profile name and we want 
        to add the texture as an extra technique tag under a child element.*/
        String mChildElementName;

    public:

        /**Constructor that sets all required attributes and the default values for optional attributes.*/
        Texture ( const String &imageID, SurfaceType surfaceType, const String &sid="" );

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

        /** Returns the image ID*/
        const String& getImageId() const
        {
            return mImageID;
        };

        /** Returns the image ID*/
        String getImageId()
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

        /**
        * Set the name of the profile, if we want to add the texture as an extra technique tag.
        * @param profileName Name of the extra technique profile.
        */
        void setProfileName(const String& profileName)  { mProfileName = profileName; }
        /**
        * Get the name of the profile, if we want to add the texture as an extra technique tag.
        * @return mProfileName Name of the extra technique profile.
        */
        const String& getProfileName() const { return mProfileName; } 

        /**
        * Set the name of the child element, if we have set a profile name and we want 
        * to add the texture as an extra technique tag under a child element.
        * @param childElementName Name of the child element.
        */
        void setChildElementName(const String& childElementName)  { mChildElementName = childElementName; }
        /**
        * Get the name of the child element, if we have set a profile name and we want 
        * to add the texture as an extra technique tag under a child element.
        * @return childElementName Name of the child element.
        */
        const String& getChildElementName() const { return mChildElementName; } 

    };

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_TEXTURE_H__