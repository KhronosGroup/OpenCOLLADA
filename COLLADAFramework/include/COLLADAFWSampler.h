/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SAMPLER_H__
#define __COLLADAFW_SAMPLER_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWColor.h"
#include "COLLADAFWPointerArray.h"

namespace COLLADAFW
{

	/** 
     * Declares the storage for the graphical representation of an object. 
     * The samplerId is the array index position in the samplers array.
     */
	class Sampler : public ObjectTemplate<COLLADA_TYPE::SAMPLER>
	{
	public:
		/** The different sampler types. */
		enum SamplerType
		{
			SAMPLER_TYPE_UNSPECIFIED, 
			SAMPLER_TYPE_1D, 
			SAMPLER_TYPE_2D, 
			SAMPLER_TYPE_3D, 
			SAMPLER_TYPE_CUBE, 
			SAMPLER_TYPE_RECT,
			SAMPLER_TYPE_DEPTH,
			SAMPLER_TYPE_STATE
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

		/** 
		Contains the texture wrap modes.
		Wrap modes that affect the interpretation of s, t, and p texture 
		coordinates in <sampler_*> elements. The wrap mode enums map to the 
		following OpenGL symbols.*/
		enum WrapMode
		{
			WRAP_MODE_UNSPECIFIED=0,
			// NONE == GL_CLAMP_TO BORDER The defined behavior for NONE is 
			// consistent with decal texturing where the border is black. 
			// Mapping this calculation to GL_CLAMP_TO_BORDER is the best 
			// approximation of this.
			WRAP_MODE_NONE,
			// WRAP == GL_REPEAT Ignores the integer part of texture coordinates, 
			// using only the fractional part.
			WRAP_MODE_WRAP, 
			// MIRROR == GL_MIRRORED_REPEAT First mirrors the texture coordinate. 
			// The mirrored coordinate is then clamped as described for CLAMP_TO_EDGE.
			WRAP_MODE_MIRROR,
			// CLAMP == GL_CLAMP_TO_EDGE Clamps texture coordinates at all 
			// mipmap levels such that the texture filter never samples a 
			// border texel. Note: GL_CLAMP takes any texels beyond the
			// sampling border and substitutes those texels with the border 
			// color. So CLAMP_TO_EDGE is more appropriate. This also works 
			// much better with OpenGL ES where the GL_CLAMP symbol was removed 
			// from the OpenGL ES specification.
			WRAP_MODE_CLAMP,
			// BORDER GL_CLAMP_TO_BORDER Clamps texture coordinates at all 
			// MIPmaps such that the texture filter always samples border 
			// texels for fragments whose corresponding texture coordinate
			// is sufficiently far outside the range [0, 1].
			WRAP_MODE_BORDER
		};
	
	private:

		/** The type of the current sampler. */
		SamplerType mSamplerType;

		/** The unique id of the image used as source for this sampler */
		UniqueId mSourceImageUniqueId;

		/** Texture minimization. Enumerated type fx_sampler_filter_common. 
		Applying a texture to a primitive implies a mapping from texture image 
		space to framebuffer image space. In general, this mapping involves
		a reconstruction of the sampled texture image, followed by a 
		homogeneous warping implied by the mapping to framebuffer space, then a 
		filtering, followed finally by a resampling of the filtered, warped, 
		reconstructed image before applying it to a fragment. */
		SamplerFilter mMinFilter;

		/** Texture magnification. Enumerated type fx_sampler_filter_common. 
		When gamma indicates magnification, this value determines how the 
		texture value is obtained. */
		SamplerFilter mMagFilter;

		/** MIPmap filter. Enumerated type fx_sampler_filter_common. */
		SamplerFilter mMipFilter;

		/** Wrap modes */
		WrapMode mWrapS;
		WrapMode mWrapT;
		WrapMode mWrapP;

		/** When reading past the edge of the texture address space based on 
		the wrap modes involving clamps, this color takes over. Type 
		fx_color_common (four floating-point numbers in RGBA order). */
		Color mBorderColor;

		/** An xs:unsignedByte, which is the maximum number of progressive 
		levels that the sampler will evaluate. */
		unsigned char mMipmapMaxlevel;

		/** An xs:float, which biases the gamma (level of detail parameter) 
		that is used by the sampler to evaluate the MIPmap chain. */
		float mMipmapBias;

	public:

        /** Constructor. */
		Sampler ( const UniqueId& uniqueId );

        /** Destructor. */
		virtual ~Sampler();

		/** Returns the sampler type. */
		SamplerType getSamplerType ( ) { return mSamplerType; }

		/** Set the sampler type. */
		void setSamplerType ( SamplerType samplerType ) { mSamplerType = samplerType; }

		/** Returns the unique id of the image used as source for this sampler */
		const UniqueId& getSourceImage () const { return mSourceImageUniqueId; }

		/** Returns the unique id of the image used as source for this sampler */
		void setSource ( const UniqueId& sourceImageUniqueId ) { mSourceImageUniqueId = sourceImageUniqueId; }

		/** Returns min filter*/
		SamplerFilter getMinFilter() const { return mMinFilter; } 

		/** Sets the min filter. */
		void setMinFilter ( SamplerFilter minFilter ) { mMinFilter = minFilter; }

		/** Returns mag filter*/
		SamplerFilter getMagFilter() const { return mMagFilter; } 

		/** Sets the mag filter. */
		void setMagFilter ( SamplerFilter magFilter ) { mMagFilter = magFilter; }

		/** Returns mip filter*/
		SamplerFilter getMipFilter() const { return mMipFilter; } 

		/** Sets the mip filter. */
		void setMipFilter ( SamplerFilter mipFilter ) { mMipFilter = mipFilter; }

		/** Returns the wrap mode in dimension S.*/
		WrapMode getWrapS() const { return mWrapS; }

		/** Sets the wrap mode in dimension S.*/
		void setWrapS ( WrapMode wrapS ) { mWrapS = wrapS; }

		/** Returns the wrap mode in dimension T.*/
		WrapMode getWrapT() const { return mWrapT; }

		/** Sets the wrap mode in dimension T.*/
		void setWrapT ( WrapMode wrapT ) { mWrapT = wrapT; }

		/** Returns the wrap mode in dimension P*/
		WrapMode getWrapP() const { return mWrapP; }

		/** Sets the wrap mode in dimension P.*/
		void setWrapP ( WrapMode wrapP ) { mWrapP = wrapP; }

		/** Returns the border color. */
		const Color& getBorderColor () const { return mBorderColor; }

		/** Sets the border color. */
		void setBorderColor ( const Color& borderColor ) { mBorderColor = borderColor; }

		/** Returns the maximum number of progressive levels that the sampler will evaluate. */
		unsigned char getMipmapMaxlevel () const { return mMipmapMaxlevel; }

		/** Sets the maximum number of progressive levels that the sampler will evaluate. */
		void setMipmapMaxlevel ( unsigned char mipmapMaxlevel ) { mMipmapMaxlevel = mipmapMaxlevel; }

		/** Returns the mipmap Bias.*/
		float getMipmapBias () const { return mMipmapBias; }

		/** Returns the mipmap Bias.*/
		void setMipmapBias ( float mipmapBias ) { mMipmapBias = mipmapBias; }

		Sampler* clone() { return FW_NEW Sampler(*this); }

	};

    /** 
    * The samplerId is the array index position in the samplers array.
    */
	typedef PointerArray<Sampler> SamplerPointerArray;


} // namespace COLLADAFW

#endif // __COLLADAFW_SAMPLER_H__
