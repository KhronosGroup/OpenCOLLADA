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
#include "COLLADAFWExtraData.h"


namespace COLLADAFW
{

	/** A morph controller.  */
	class MorphController : public Controller, public ExtraData
	{
	private:

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

        /** The name of the light.*/
        String mName;

		/** The unique ids of the morph targets (geometries).*/
		UniqueIdArray mMorphTargets;

		/** The morph weights.*/
		FloatOrDoubleArray mMorphWeights;

	public:

        /** Constructor. */
		MorphController( ObjectId objectId );

        /** Copy-Constructor. */
		MorphController( const MorphController& pre );

		/** Destructor. */
		virtual ~MorphController(){}

        /**
        * The original object id, if it in the original file format exist. 
        */
        const COLLADAFW::String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const COLLADAFW::String& val ) { mOriginalId = val; }

        /** Returns name of the controller.*/
        const COLLADAFW::String& getName() const { return mName; }

        /** Sets name of the controller.*/
        void setName(const COLLADAFW::String& name) { mName = name; }


		/** The unique ids of the morph targets (geometries).*/
		COLLADAFW::UniqueIdArray& getMorphTargets() { return mMorphTargets; }

		/** The unique ids of the morph targets (geometries).*/
		const COLLADAFW::UniqueIdArray& getMorphTargets() const { return mMorphTargets; }

		/** The morph weights.*/
		const COLLADAFW::FloatOrDoubleArray& getMorphWeights() const { return mMorphWeights; }

		/** The morph weights.*/
		COLLADAFW::FloatOrDoubleArray& getMorphWeights() { return mMorphWeights; }

	private:
        /** Disable default assignment operator. */
		const MorphController& operator= ( const MorphController& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MORPHCONTROLLER_H__
