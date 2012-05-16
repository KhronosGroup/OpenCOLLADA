/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SHADER_H__
#define __COLLADAFW_SHADER_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class Shader 	{
	private:
	
	public:

        /** Constructor. */
		Shader();

        /** Destructor. */
		virtual ~Shader();

	private:

        /** Disable default copy ctor. */
		Shader( const Shader& pre );

        /** Disable default assignment operator. */
		const Shader& operator= ( const Shader& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SHADER_H__
