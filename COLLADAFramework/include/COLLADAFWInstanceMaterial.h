/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCEMATERIAL_H__
#define __COLLADAFW_INSTANCEMATERIAL_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class InstanceMaterial 	
    {
	private:
	
	public:

        /** Constructor. */
		InstanceMaterial();

        /** Destructor. */
		virtual ~InstanceMaterial();

	private:

        /** Disable default copy ctor. */
		InstanceMaterial( const InstanceMaterial& pre );

        /** Disable default assignment operator. */
		const InstanceMaterial& operator= ( const InstanceMaterial& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEMATERIAL_H__
