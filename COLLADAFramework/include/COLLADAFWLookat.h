/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_LOOKAT_H__
#define __COLLADAFW_LOOKAT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTransformation.h"


namespace COLLADAFW
{

    /**
    * The <lookat> element contains a float3x3, which is three 
    * mathematical vectors.
    * Positioning and orienting a camera or object in the scene is often 
    * complicated when using a matrix. A lookat transform is an intuitive 
    * way to specify an eye position, interest point, and orientation.
    * eyePosition The position of the object.
    * interestPosition The position of the interest point.
    * upPosition The direction that points up.
    */
	class Lookat : public Transformation
    {
	private:
	
        /** The position of the viewer. Defines the translation. */
        COLLADABU::Math::Vector3 mEyePosition; 

        /** The target of the viewer. Defines the pitch and the yaw of the transform. */
        COLLADABU::Math::Vector3 mInterestPointPosition; 

        /** The up-axis of the viewer. Defines the roll of the transform. */
        COLLADABU::Math::Vector3 mUpAxisDirection; 

	public:

        /** Constructor. */
        Lookat() 
            : Transformation ( Transformation::LOOKAT ) 
        {}

        /** Destructor. */
        virtual ~Lookat() {}

        /** The position of the viewer. Defines the translation. */
        COLLADABU::Math::Vector3& getEyePosition () { return mEyePosition; }
		const COLLADABU::Math::Vector3& getEyePosition () const { return mEyePosition; }
        void setEyePosition ( COLLADABU::Math::Vector3& val ) { mEyePosition = val; }

        /** The target of the viewer. Defines the pitch and the yaw of the transform. */
		COLLADABU::Math::Vector3& getInterestPointPosition () { return mInterestPointPosition; }
		const COLLADABU::Math::Vector3& getInterestPointPosition () const { return mInterestPointPosition; }
        void setInterestPointPosition ( COLLADABU::Math::Vector3& val ) { mInterestPointPosition = val; }

        /** The up-axis of the viewer. Defines the roll of the transform. */
        COLLADABU::Math::Vector3& getUpAxisDirection () { return mUpAxisDirection; }
		const COLLADABU::Math::Vector3& getUpAxisDirection () const { return mUpAxisDirection; }
        void setUpAxisDirection ( COLLADABU::Math::Vector3& val ) { mUpAxisDirection = val; }

		/** Clones the lookat.*/
		virtual Lookat* clone() const { return new Lookat(*this); }


	private:

        /** Disable default copy ctor. */
//		Lookat( const Lookat& pre );

        /** Disable default assignment operator. */
		const Lookat& operator= ( const Lookat& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_LOOKAT_H__
