/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MORPHCONTROLLER_H__
#define __COLLADAFW_MORPHCONTROLLER_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWController.h"
#include "COLLADAFWFloatOrDoubleArray.h"


namespace COLLADAFW
{

	/** A morph controller.  */
	class MorphController : public Controller 
	{
	private:

		/** The unique ids of the morph targets (geometries).*/
		UniqueIdArray mMorphTargets;

		/** The morph weights.*/
		FloatOrDoubleArray mMorphWeights;

		/** The unique id of the source that gets modified by this controller. Must be a mesh. The vertex count of 
		the source must be equal to the vertex count of the skin controller.*/
		UniqueId mSource;
	
	public:

        /** Constructor. */
		MorphController( ObjectId objectId );

		MorphController( const MorphController& pre );

		/** Destructor. */
		virtual ~MorphController(){}

		/** The unique ids of the morph targets (geometries).*/
		COLLADAFW::UniqueIdArray& getMorphTargets() { return mMorphTargets; }

		/** The unique ids of the morph targets (geometries).*/
		const COLLADAFW::UniqueIdArray& getMorphTargets() const { return mMorphTargets; }

		/** The morph weights.*/
		const COLLADAFW::FloatOrDoubleArray& getMorphWeights() const { return mMorphWeights; }

		/** The morph weights.*/
		COLLADAFW::FloatOrDoubleArray& getMorphWeights() { return mMorphWeights; }

		/** Returns the unique id of the source that gets modified by this controller. Must be a mesh or a 
		controller. The vertex count of the source must be equal to the vertex count of the skin 
		controller.*/
		const COLLADAFW::UniqueId& getSource() const { return mSource; }

		/** Sets the unique id of the source that gets modified by this controller. Must be a mesh or a 
		controller. The vertex count of the source must be equal to the vertex count of the skin 
		controller.*/
		void setSource( const COLLADAFW::UniqueId& source) { mSource = source; }


	private:
        /** Disable default assignment operator. */
		const MorphController& operator= ( const MorphController& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MORPHCONTROLLER_H__
