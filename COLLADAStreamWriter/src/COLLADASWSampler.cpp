/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWSampler.h"
#include "COLLADASWParamTemplate.h"

namespace COLLADASW
{

    const String Sampler::SAMPLER_SID_SUFFIX = "-sampler";
	const String Sampler::SURFACE_SID_SUFFIX = "-surface";

    //-------------------------------
    Sampler::Sampler ( 
        const SamplerType& samplerType,
        const String& samplerSid, 
        const String& surfaceSid/* = ""*/ )
        : BaseExtraTechnique()
        , mSamplerType ( samplerType )
        , mSamplerSid ( samplerSid )
        , mSurfaceSid ( surfaceSid )
        , mMinFilter ( Sampler::SAMPLER_FILTER_NONE )
        , mMagFilter ( Sampler::SAMPLER_FILTER_NONE )
        , mMipFilter ( Sampler::SAMPLER_FILTER_NONE )
        , mWrap_s ( Sampler::WRAP_MODE_UNSPECIFIED )
        , mWrap_t ( Sampler::WRAP_MODE_UNSPECIFIED )
        , mWrap_p ( Sampler::WRAP_MODE_UNSPECIFIED )
        , mUseBorderColor ( false )
        , mMipmapMaxlevel ( 0 )
        , mMipmapBias ( 0.0f )
    {
        initializeMembers();
    }

    //-------------------------------
    Sampler::Sampler()
        : BaseExtraTechnique()
        , mSamplerType ( Sampler::SAMPLER_TYPE_UNSPECIFIED )
        , mSamplerSid ( COLLADABU::Utils::EMPTY_STRING )
        , mSurfaceSid ( COLLADABU::Utils::EMPTY_STRING )
        , mMinFilter ( Sampler::SAMPLER_FILTER_NONE )
        , mMagFilter ( Sampler::SAMPLER_FILTER_NONE )
        , mMipFilter ( Sampler::SAMPLER_FILTER_NONE )
        , mWrap_s ( Sampler::WRAP_MODE_UNSPECIFIED )
        , mWrap_t ( Sampler::WRAP_MODE_UNSPECIFIED )
        , mWrap_p ( Sampler::WRAP_MODE_UNSPECIFIED )
        , mUseBorderColor ( false )
        , mMipmapMaxlevel ( 0 )
        , mMipmapBias ( 0.0f )
    {}

    //-------------------------------
    void Sampler::initializeMembers()
    {
        switch ( mSamplerType )
        {
        case Sampler::SAMPLER_TYPE_1D:
            mWrap_s = Sampler::WRAP_MODE_WRAP;
            break;
        case Sampler::SAMPLER_TYPE_2D:
        case Sampler::SAMPLER_TYPE_STATE:
            mWrap_s = Sampler::WRAP_MODE_WRAP;
            mWrap_t = Sampler::WRAP_MODE_WRAP;
            mMipmapMaxlevel = 255;
            break;
        case Sampler::SAMPLER_TYPE_3D:
        case Sampler::SAMPLER_TYPE_CUBE:
        case Sampler::SAMPLER_TYPE_RECT:
            mWrap_s = Sampler::WRAP_MODE_WRAP;
            mWrap_t = Sampler::WRAP_MODE_WRAP;
            mWrap_p = Sampler::WRAP_MODE_WRAP;
            mMipmapMaxlevel = 255;
            break;
        case Sampler::SAMPLER_TYPE_DEPTH:
            mWrap_s = Sampler::WRAP_MODE_WRAP;
            mWrap_t = Sampler::WRAP_MODE_WRAP;
            break;
        case Sampler::SAMPLER_TYPE_UNSPECIFIED:
        default: break;
        }
    }

    //-------------------------------
    void Sampler::setMinFilter( const SamplerFilter& filter )
    {
        mMinFilter = filter;
    }

    //-------------------------------
    const Sampler::SamplerFilter& Sampler::getMinFilter() const
    {
        return mMinFilter;
    }

    //-------------------------------
    void Sampler::setMagFilter( const SamplerFilter& filter )
    {
        mMagFilter = filter;
    }

    //-------------------------------
    const Sampler::SamplerFilter& Sampler::getMagFilter() const
    {
        return mMagFilter;
    }

    //-------------------------------
    void Sampler::setMipFilter( const SamplerFilter& filter )
    {
        mMipFilter = filter;
    }

    //-------------------------------
    const Sampler::SamplerFilter& Sampler::getMipFilter() const
    {
        return mMipFilter;
    }

    //-------------------------------
    const Sampler::WrapMode& Sampler::getWrapS() const
    {
        return mWrap_s;
    }

    //-------------------------------
    const Sampler::WrapMode& Sampler::getWrapT() const
    {
        return mWrap_t;    /**< See above.*/
    }

    //-------------------------------
    const Sampler::WrapMode& Sampler::getWrapP() const
    {
        return mWrap_p;    /**< See above.*/
    }

    //-------------------------------
    void Sampler::setWrapS( const WrapMode& mode )
    {
        mWrap_s = mode;
    }

    //-------------------------------
    void Sampler::setWrapT( const WrapMode& mode )
    {
        mWrap_t = mode;    /**< See above.*/
    }

    //-------------------------------
    void Sampler::setWrapP( const WrapMode& mode )
    {
        mWrap_p = mode;    /**< See above.*/
    }

    //-------------------------------
    const Color& Sampler::getBorderColor() const
    {
        return mBorderColor;
    }

    //-------------------------------
    void Sampler::setBorderColor( const Color& val )
    {
        mBorderColor = val;
        mUseBorderColor = true;
    }

    //-------------------------------
    const unsigned char Sampler::getMipmapMaxlevel() const
    {
        return mMipmapMaxlevel;
    }

    //-------------------------------
    void Sampler::setMipmapMaxlevel( const unsigned char val )
    {
        mMipmapMaxlevel = val;
    }

    //-------------------------------
    const float Sampler::getMipmapBias() const
    {
        return mMipmapBias;
    }

    //-------------------------------
    void Sampler::setMipmapBias( const float val )
    {
        mMipmapBias = val;
    }

#if 0
	//-------------------------------
    const String& Sampler::getSource() const
    {
        return mSource;
    }

    //-------------------------------
    void Sampler::setSource( const String& val )
    {
        mSource = val;
    }
#endif

    //-------------------------------
    const String& Sampler::getSamplerTypeString( const SamplerType& samplerType )
    {
        switch ( samplerType )
        {
        case Sampler::SAMPLER_TYPE_1D: return CSWC::CSW_VALUE_TYPE_SAMPLER_1D;
        case Sampler::SAMPLER_TYPE_2D: return CSWC::CSW_VALUE_TYPE_SAMPLER_2D;
        case Sampler::SAMPLER_TYPE_3D: return CSWC::CSW_VALUE_TYPE_SAMPLER_3D;
        case Sampler::SAMPLER_TYPE_CUBE: return CSWC::CSW_VALUE_TYPE_SAMPLER_CUBE;
        case Sampler::SAMPLER_TYPE_DEPTH: return CSWC::CSW_VALUE_TYPE_SAMPLER_DEPTH;
        case Sampler::SAMPLER_TYPE_RECT: return CSWC::CSW_VALUE_TYPE_SAMPLER_RECT;
        case Sampler::SAMPLER_TYPE_STATE: return CSWC::CSW_VALUE_TYPE_SAMPLER_STATE;
        case Sampler::SAMPLER_TYPE_UNSPECIFIED:
        default: return CSWC::EMPTY_STRING;
        }
    }

	//---------------------------------------------------------------
	const String& Sampler::getSurfaceTypeString ( SamplerType surfaceType ) const
	{
		switch ( surfaceType )
		{
		case Sampler::SAMPLER_TYPE_1D:
			return CSWC::CSW_SURFACE_TYPE_1D;
		case Sampler::SAMPLER_TYPE_2D:
			return CSWC::CSW_SURFACE_TYPE_2D;
		case Sampler::SAMPLER_TYPE_3D:
			return CSWC::CSW_SURFACE_TYPE_3D;
		case Sampler::SAMPLER_TYPE_CUBE:
			return CSWC::CSW_SURFACE_TYPE_CUBE;
		case Sampler::SAMPLER_TYPE_DEPTH:
			return CSWC::CSW_SURFACE_TYPE_DEPTH;
		case Sampler::SAMPLER_TYPE_RECT:
			return CSWC::CSW_SURFACE_TYPE_RECT;
		case Sampler::SAMPLER_TYPE_UNSPECIFIED:
			return CSWC::CSW_SURFACE_TYPE_UNTYPED;
		default:
			return CSWC::EMPTY_STRING;
		}
	}


    //-------------------------------
    const String& Sampler::getSamplerFilterString ( const Sampler::SamplerFilter& samplerFilter )
    {
        switch ( samplerFilter )
        {
        case Sampler::SAMPLER_FILTER_NONE:
            return CSWC::CSW_SAMPLER_FILTER_NONE;
        case Sampler::SAMPLER_FILTER_LINEAR:
            return CSWC::CSW_SAMPLER_FILTER_LINEAR;
        case Sampler::SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR:
            return CSWC::CSW_SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR;
        case Sampler::SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST:
            return CSWC::CSW_SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST;
        case Sampler::SAMPLER_FILTER_NEAREST:
            return CSWC::CSW_SAMPLER_FILTER_NEAREST;
        case Sampler::SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR:
            return CSWC::CSW_SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR;
        case Sampler::SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST:
            return CSWC::CSW_SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST;
        default:
            return CSWC::EMPTY_STRING;
        }
    }

    //-------------------------------
    const String& Sampler::getWrapModeString ( const Sampler::WrapMode& wrapMode )
    {
        switch ( wrapMode )
        {
        case Sampler::WRAP_MODE_NONE:
            return CSWC::CSW_TEXTURE_WRAP_NONE;
        case Sampler::WRAP_MODE_WRAP:
            return CSWC::CSW_TEXTURE_WRAP_WRAP;
        case Sampler::WRAP_MODE_MIRROR:
            return CSWC::CSW_TEXTURE_WRAP_MIRROR;
        case Sampler::WRAP_MODE_CLAMP:
            return CSWC::CSW_TEXTURE_WRAP_CLAMP;
        case Sampler::WRAP_MODE_BORDER:
            return CSWC::CSW_TEXTURE_WRAP_BORDER;
        default:
            return CSWC::EMPTY_STRING;
        }
    }

    //-------------------------------
    void Sampler::add_1_4_1 ( StreamWriter* sw, const String& source ) const
    {
        sw->openElement ( getSamplerTypeString ( mSamplerType ) );

        if ( mSamplerType != Sampler::SAMPLER_TYPE_STATE )
            sw->appendTextElement ( CSWC::CSW_ELEMENT_SOURCE, source );

		addCommon( sw );

        sw->closeElement (); // mSamplerType
    }


	//-------------------------------
	void Sampler::add_1_5_0 ( StreamWriter* sw ) const
	{
		sw->openElement ( getSamplerTypeString ( mSamplerType ) );

		if ( !mImageId.empty() )
		{
			sw->openElement( CSWC::CSW_ELEMENT_INSTANCE_IMAGE );
			sw->appendAttribute( CSWC::CSW_ATTRIBUTE_URL, "#" + mImageId );
			sw->closeElement (); // CSW_ELEMENT_INSTANCE_IMAGE
		}

		addCommon( sw );
		
		sw->closeElement (); // mSamplerType
	}


	//-------------------------------
	void Sampler::addCommon ( StreamWriter* sw ) const
	{
		if ( mWrap_s != Sampler::WRAP_MODE_WRAP && mWrap_s != Sampler::WRAP_MODE_UNSPECIFIED )
			sw->appendTextElement ( CSWC::CSW_ELEMENT_WRAP_S, getWrapModeString ( mWrap_s ) );

		if ( mWrap_t != Sampler::WRAP_MODE_WRAP && mWrap_t != Sampler::WRAP_MODE_UNSPECIFIED )
			sw->appendTextElement ( CSWC::CSW_ELEMENT_WRAP_T, getWrapModeString ( mWrap_t ) );

		if ( mWrap_p != Sampler::WRAP_MODE_WRAP && mWrap_p != Sampler::WRAP_MODE_UNSPECIFIED )
			sw->appendTextElement ( CSWC::CSW_ELEMENT_WRAP_P, getWrapModeString ( mWrap_p ) );

		if ( mMinFilter != Sampler::SAMPLER_FILTER_NONE )
			sw->appendTextElement ( CSWC::CSW_ELEMENT_MINFILTER, getSamplerFilterString ( mMinFilter ) );

		if ( mMagFilter != Sampler::SAMPLER_FILTER_NONE )
			sw->appendTextElement ( CSWC::CSW_ELEMENT_MAGFILTER, getSamplerFilterString ( mMagFilter ) );

		if ( mMipFilter != Sampler::SAMPLER_FILTER_NONE )
			sw->appendTextElement ( CSWC::CSW_ELEMENT_MIPFILTER, getSamplerFilterString ( mMipFilter ) );

		if ( mUseBorderColor )
		{
			sw->openElement ( CSWC::CSW_ELEMENT_BORDER_COLOR );
			sw->appendValues ( mBorderColor.getRed(), mBorderColor.getGreen(), mBorderColor.getBlue(), mBorderColor.getAlpha() );
			sw->closeElement ();
		}

		bool writeMipMapLevel = false;
		if ( mMipmapMaxlevel != 0 &&
			( mSamplerType == SAMPLER_TYPE_1D || mSamplerType == SAMPLER_TYPE_DEPTH ) )
			writeMipMapLevel = true;
		if ( mMipmapMaxlevel != 255 &&
			( mSamplerType != SAMPLER_TYPE_1D || mSamplerType != SAMPLER_TYPE_DEPTH || mSamplerType != SAMPLER_TYPE_UNSPECIFIED ) )
			writeMipMapLevel = true;
		if ( writeMipMapLevel )
		{
			sw->openElement ( CSWC::CSW_ELEMENT_MIPMAP_MAXLEVEL );
			sw->appendValues ( mMipmapMaxlevel );
			sw->closeElement ();
		}

		if ( mMipmapBias != 0.0f )
		{
			sw->openElement ( CSWC::CSW_ELEMENT_MIPMAP_BIAS );
			sw->appendValues ( mMipmapBias );
			sw->closeElement ();
		}

		addExtraTechniques ( sw );
	}

	//-------------------------------
	template<class ParamSurfaceType, class ParamSamplerType> 
	void Sampler::addInParam ( 
        StreamWriter* sw, 
        std::vector<COLLADASW::Annotation>* surfaceAnnotations /*= 0*/, 
        std::vector<COLLADASW::Annotation>* samplerAnnotations /*= 0*/,
		bool AddSurfaceParam) const
	{
		if ( sw->getCOLLADAVersion() == StreamWriter::COLLADA_1_4_1 )
		{
			if (AddSurfaceParam)
			{
				// Add the surface <newparam>
				ParamSurfaceType paramSurface(sw);
				paramSurface.openParam(mSurfaceSid);
				if (surfaceAnnotations) paramSurface.addAnnotations(*surfaceAnnotations);
				addSurface(sw);
				paramSurface.closeParam();
			}

			// Add the sampler <newparam>
			ParamSamplerType paramSampler ( sw );
			paramSampler.openParam ( mSamplerSid );
            if ( samplerAnnotations ) paramSampler.addAnnotations ( *samplerAnnotations );
			add_1_4_1 ( sw, mSurfaceSid );
			paramSampler.closeParam ();
		}
		else if ( sw->getCOLLADAVersion() == StreamWriter::COLLADA_1_5_0 )
		{
			// Add the sampler <newparam>
			ParamSamplerType paramSampler ( sw );
			paramSampler.openParam ( mSamplerSid );
            if ( surfaceAnnotations ) paramSampler.addAnnotations ( *surfaceAnnotations );
            if ( samplerAnnotations ) paramSampler.addAnnotations ( *samplerAnnotations );
			add_1_5_0( sw );
			paramSampler.closeParam ();
		}
	}

	// ----------------------------------------
	void Sampler::addInSetParam( 
        StreamWriter* sw, 
        std::vector<COLLADASW::Annotation>* surfaceAnnotations /*= 0*/, 
        std::vector<COLLADASW::Annotation>* samplerAnnotations /*= 0*/,
		bool AddSurfaceParam) const
	{
		addInParam<SetParamSurface, SetParamSampler>(sw, surfaceAnnotations, samplerAnnotations, AddSurfaceParam);
	}

	// ----------------------------------------
	void Sampler::addInNewParam( 
        StreamWriter* sw, 
        std::vector<COLLADASW::Annotation>* surfaceAnnotations /*= 0*/, 
        std::vector<COLLADASW::Annotation>* samplerAnnotations /*= 0*/,
		bool AddSurfaceParam) const
	{
		addInParam<NewParamSurface, NewParamSampler>(sw, surfaceAnnotations, samplerAnnotations, AddSurfaceParam);
	}

	// ----------------------------------------
	void Sampler::addSurface ( StreamWriter* sw ) const
	{
		sw->openElement ( CSWC::CSW_ELEMENT_SURFACE );
		sw->appendAttribute( CSWC::CSW_ATTRIBUTE_TYPE, getSurfaceTypeString ( mSamplerType ) );

		sw->openElement( CSWC::CSW_ELEMENT_INIT_FROM );

		if ( !mImageId.empty() )
			sw->appendValues( mImageId );

		sw->closeElement(); //CSW_ELEMENT_INIT_FROM

		addExtraTechniques ( sw );

		sw->closeElement(); // COLLADASW_ELEMENT_SURFACE
	}


}
