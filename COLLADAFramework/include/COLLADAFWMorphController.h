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

		/** The morph weights.*/
		FloatOrDoubleArray mMorphWeights;

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

        /** The name of the light.*/
        String mName;

		/** The unique ids of the morph targets (geometries).*/
		UniqueIdArray mMorphTargets;


	public:

        /** Constructor. */
		MorphController( const UniqueId& uniqueId );

        /** Copy-Constructor. */
		MorphController( const MorphController& pre );

		/** Destructor. */
		virtual ~MorphController(){}

        /**
        * The original object id, if it in the original file format exist. 
        */
        const String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const String& val ) { mOriginalId = val; }

        /** Returns name of the controller.*/
        const String& getName() const { return mName; }

        /** Sets name of the controller.*/
        void setName(const String& name) { mName = name; }


		/** The unique ids of the morph targets (geometries).*/
		UniqueIdArray& getMorphTargets() { return mMorphTargets; }

		/** The unique ids of the morph targets (geometries).*/
		const UniqueIdArray& getMorphTargets() const { return mMorphTargets; }

		/** The morph weights.*/
		const FloatOrDoubleArray& getMorphWeights() const { return mMorphWeights; }

		/** The morph weights.*/
		FloatOrDoubleArray& getMorphWeights() { return mMorphWeights; }

	private:
        /** Disable default assignment operator. */
		const MorphController& operator= ( const MorphController& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MORPHCONTROLLER_H__
