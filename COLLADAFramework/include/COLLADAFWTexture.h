/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TEXTURE_H__
#define __COLLADAFW_TEXTURE_H__

#include "COLLADAFWPrerequisites.h"

#include "COLLADAFWTypes.h"

namespace COLLADAFW
{

    /** TODO Documentation */
	class Texture 	
	{
	private:
		/** The id of the sampler used by the texture.*/
		SamplerID mSamplerId;

	public:

        /** Constructor. */
		Texture();

        /** Destructor. */
		virtual ~Texture();

		/** Returns the id of the sampler.*/
		SamplerID getSamplerId() const { return mSamplerId; }

		/** Sets the id of the sampler.*/
		void setSamplerId(SamplerID samplerId) { mSamplerId = samplerId; }

		bool isValid() const { return true; }
	};

} // namespace COLLADAFW

#endif // __COLLADAFW_TEXTURE_H__
