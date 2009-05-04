/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_TRANSFORMANIMATION_H__
#define __COLLADAMAYA_TRANSFORMANIMATION_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADAFWTransformation.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAMaya
{

    /** Stores the transform node id, the mayaTransform node and the transformation type. */
	class TransformAnimation 	
    {
	private:
	
        COLLADAFW::UniqueId mAnimationListId;
        COLLADAFW::UniqueId mTransformNodeId;
        COLLADAFW::Transformation* mTransformation;

    public:

        /** Constructor. */
		TransformAnimation();

        /** Destructor. */
		virtual ~TransformAnimation();

        const COLLADAFW::UniqueId& getAnimationListId () const { return mAnimationListId; }
        void setAnimationListId ( const COLLADAFW::UniqueId& val ) { mAnimationListId = val; }

        const COLLADAFW::UniqueId& getTransformNodeId () const { return mTransformNodeId; }
        void setTransformNodeId ( const COLLADAFW::UniqueId& val ) { mTransformNodeId = val; }

        const COLLADAFW::Transformation* getTransformation () const { return mTransformation; }
        void setTransformation ( const COLLADAFW::Transformation* val );
        const COLLADAFW::Transformation::TransformationType getTransformType () const { return mTransformation->getTransformationType (); }

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_TRANSFORMANIMATION_H__
