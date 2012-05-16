/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SETPARAM_H__
#define __COLLADAFW_SETPARAM_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class SetParam 	{
	private:
	
	public:

        /** Constructor. */
		SetParam();

        /** Destructor. */
		virtual ~SetParam();

	private:

        /** Disable default copy ctor. */
		SetParam( const SetParam& pre );

        /** Disable default assignment operator. */
		const SetParam& operator= ( const SetParam& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SETPARAM_H__
