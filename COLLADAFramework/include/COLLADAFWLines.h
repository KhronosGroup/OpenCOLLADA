/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_LINES_H__
#define __COLLADAFW_LINES_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshPrimitive.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class Lines : public MeshPrimitive 
		{
	private:
	
	public:

        /** Constructor. */
		Lines( const UniqueId& uniqueId ) 
            : MeshPrimitive( uniqueId, LINES )
        {}

        /** Destructor. */
        virtual ~Lines() {}

	private:

        /** Disable default copy ctor. */
		Lines( const Lines& pre );

        /** Disable default assignment operator. */
		const Lines& operator= ( const Lines& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_LINES_H__
