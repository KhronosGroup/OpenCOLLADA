/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASWStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWTexture.h"

namespace COLLADASW
{

    //------------------------------
    Texture::Texture ( const String& imageID, const String& sid )
        : BaseExtraTechnique()
        , mSid ( sid )
        , mImageID ( imageID )
    {}


    //------------------------------
    Texture::Texture()
        : mSid ( "" )
        , mImageID ( "" ) {}

    //------------------------------
    bool Texture::isValid() const
    {
        return ( !mImageID.empty() ) && ( mSurface.getSurfaceType() != Surface::SURFACE_TYPE_UNSPECIFIED );
    }

    //------------------------------
    void Texture::setTexcoord( const String texcoord )
    {
        mTexcoord = texcoord;
    }

    //------------------------------
    const String& Texture::getTexcoord() const
    {
        return mTexcoord;
    }

    //------------------------------
    const String& Texture::getImageID() const
    {
        return mImageID;
    }

    //------------------------------
    const String& Texture::getImageId() const
    {
        return mImageID;
    }

    //------------------------------
    const Surface& Texture::getSurface() const
    {
        return mSurface;
    }

    //------------------------------
    void Texture::setSurface( const Surface& surface )
    {
        mSurface = surface;
    }

    //------------------------------
    const Sampler& Texture::getSampler() const
    {
        return mSampler;
    }

    //------------------------------
    void Texture::setSampler( const Sampler& val )
    {
        mSampler = val;
    }

    //------------------------------
    COLLADASW::String Texture::getSamplerSid() const
    {
        return mImageID + Sampler::SAMPLER_SID_SUFFIX;
    }

    //------------------------------
    COLLADASW::String Texture::getSurfaceSid() const
    {
        return mSurface.getSurfaceSid();
    }

    //------------------------------
    void Texture::setImageId( String imageId )
    {
        mImageID = imageId;
    }

} //namespace COLLADASW
