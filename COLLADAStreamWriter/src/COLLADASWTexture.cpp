/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

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
        return ( !mImageID.empty() ) && ( mSampler.getSamplerType() != Sampler::SAMPLER_TYPE_UNSPECIFIED );
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
#if 0
	const Surface& Texture::getSurface() const
    {
        return mSurface;
    }

    //------------------------------
    void Texture::setSurface( const Surface& surface )
    {
        mSurface = surface;
    }
#endif
    //------------------------------
    const Sampler& Texture::getSampler() const
    {
        return mSampler;
    }

    //------------------------------
    void Texture::setSampler ( const Sampler& val )
    {
        mSampler = val;
    }

    //------------------------------
    COLLADASW::String Texture::getSamplerSid() const
    {
        if ( COLLADABU::Utils::equals ( mSampler.getSamplerSid (), COLLADABU::Utils::EMPTY_STRING ) )
            return mImageID + Sampler::SAMPLER_SID_SUFFIX;

        return mSampler.getSamplerSid ();
    }

    //------------------------------
    COLLADASW::String Texture::getSurfaceSid() const
    {
        if ( COLLADABU::Utils::equals ( mSampler.getSurfaceSid (), COLLADABU::Utils::EMPTY_STRING ) )
            return mImageID + Sampler::SURFACE_SID_SUFFIX;

        return mSampler.getSurfaceSid ();
    }

    //------------------------------
    void Texture::setImageId( String imageId )
    {
        mImageID = imageId;
    }

} //namespace COLLADASW
