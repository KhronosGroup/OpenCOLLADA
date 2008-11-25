/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TRANSLATE_H__
#define __COLLADAFW_TRANSLATE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTransformation.h"

namespace COLLADAFW
{
	class Translate : public Transformation 
		{
	private:
	
	public:
		Translate();
		virtual ~Translate();

	private:
        /** Disable default copy ctor. */
		Translate( const Translate& pre );
        /** Disable default assignment operator. */
		const Translate& operator= ( const Translate& pre );

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_TRANSLATE_H__
