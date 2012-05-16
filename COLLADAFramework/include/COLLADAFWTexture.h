/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TEXTURE_H__
#define __COLLADAFW_TEXTURE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWTypes.h"


namespace COLLADAFW
{

    /** A Texture. It only specifies the sampler that should be used for the texture and the texture map.
	The samplers are contained in an array of the parent EffectCommon.*/
    class Texture : public ObjectTemplate<COLLADA_TYPE::TEXTURE>
	{
	private:

		/** The index of the sampler used by the texture, i.e. the index of the sampler in the array of 
		samplers in the parent EffectCommon. */
		SamplerID mSamplerId;

		/** The id of the texture map, that should be used by this texture. It must be binded to a set of 
		texture coordinates, when the material is binded to the geometry. See also TextureCoordinateBinding 
		in InstanceGeometry*/
		TextureMapId mTextureMapId;

	public:

        /** Constructor. */
        Texture ( const UniqueId& uniqueId );

        /** Destructor. */
		virtual ~Texture();

        /** Sets the unique id of the object.*/
        void setUniqueId ( const UniqueId& uniqueId );

		/** 
         * Returns the id of the sampler. 
         * The sampler id is the array index position in the samplers array 
         * (see EffectCommon::mSamplers from type SamplerPointerArray).
         */
		SamplerID getSamplerId() const { return mSamplerId; }

		/** Sets the id of the sampler.*/
		void setSamplerId(SamplerID samplerId);

		/** Returns the id of the texture map, that should be used by this texture. It must be binded to a set of 
		texture coordinates, when the material is binded to the geometry. See also TextureCoordinateBinding 
		in InstanceGeometry*/
		TextureMapId getTextureMapId() const { return mTextureMapId; }

		/** Returns the id of the texture map, that should be used by this texture. It must be binded to a set of 
		texture coordinates, when the material is binded to the geometry. See also TextureCoordinateBinding 
		in InstanceGeometry*/
		void setTextureMapId( TextureMapId textureMapId );


		bool isValid() const { return true; }
	};

} // namespace COLLADAFW

#endif // __COLLADAFW_TEXTURE_H__
