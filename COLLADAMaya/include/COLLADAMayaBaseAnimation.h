/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_BASEANIMATION_H__
#define __COLLADAMAYA_BASEANIMATION_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADAFWUniqueId.h"


namespace COLLADAMaya
{

    /** Base class to hold the animation data. */
	class BaseAnimation 	
    {
    private:
        COLLADAFW::UniqueId mAnimationListId;
        COLLADAFW::UniqueId mAnimationSourceId;

	public:

        /** Constructor. */
		BaseAnimation();

        /** Destructor. */
		virtual ~BaseAnimation();

        const COLLADAFW::UniqueId& getAnimationListId () const { return mAnimationListId; }
        void setAnimationListId ( const COLLADAFW::UniqueId& val ) { mAnimationListId = val; }

        const COLLADAFW::UniqueId& getAnimationSourceId () const { return mAnimationSourceId; }
        void setAnimationSourceId ( const COLLADAFW::UniqueId& val ) { mAnimationSourceId = val; }
	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_BASEANIMATION_H__
