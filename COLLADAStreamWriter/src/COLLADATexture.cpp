/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADATexture.h"

namespace COLLADA
{

    const String Texture::SAMPLER_SID_SUFFIX = "-sampler";
    const String Texture::SURFACE_SID_SUFFIX = "-surface";


    //---------------------------------------------------------------
    Texture::Texture ( const String& imageID, Texture::SurfaceType surfaceType, const String& sid )
        : BaseExtraTechnique()
        , mSid ( sid )
        , mImageID ( imageID )
        , mSurfaceType ( surfaceType )
        , mWrap_s ( Texture::WRAP_MODE_UNSPECIFIED )
        , mWrap_t ( Texture::WRAP_MODE_UNSPECIFIED )
        , mWrap_p ( Texture::WRAP_MODE_UNSPECIFIED )
        , mMinFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED )
        , mMagFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED )
        , mMipFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED )
    {}


    //---------------------------------------------------------------
    Texture::Texture()
        : mSurfaceType ( SURFACE_TYPE_UNSPECIFIED )
        , mSid ( "" )
        , mImageID ( "" )
        , mWrap_s ( Texture::WRAP_MODE_UNSPECIFIED )
        , mWrap_t ( Texture::WRAP_MODE_UNSPECIFIED )
        , mWrap_p ( Texture::WRAP_MODE_UNSPECIFIED )
        , mMinFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED )
        , mMagFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED )
        , mMipFilter ( Texture::SAMPLER_FILTER_UNSPECIFIED )
    {}


} //namespace COLLADA
