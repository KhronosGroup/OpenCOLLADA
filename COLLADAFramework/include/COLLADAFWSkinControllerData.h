/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SKINCONTROLLERDATA_H__
#define __COLLADAFW_SKINCONTROLLERDATA_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWTypes.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWFloatOrDoubleArray.h"

namespace COLLADAFW
{

    /** Holds the data of a skin controller, i.e. the weights per vertex per joint */
	class SkinControllerData : public ObjectTemplate<COLLADA_TYPE::SKIN_DATA>	
	{
	private:
		/** The number of joints this controller can use.*/
		size_t mJointsCount;

		/** The unique id of the source that gets modified by this controller. Must be a mesh or a 
		controller. The vertex count of the source must be equal to the vertex count of the skin 
		controller.*/
		UniqueId mSource;

		/** The weights of the skin controller. */
		FloatOrDoubleArray mWeights;

		/** Defines how many joints are connected to a vertex. The length must be equal to mVertexCount.
		The i'th index corresponds to the i'th vertex of the source.*/
		UIntValuesArray mJointsPerVertex;

		/** Indices of weights assigned to a joint/vertex pair. The number of pairs for the i'th vertex is 
		given by the i'th value in mJointsPerVertex.*/
		UIntValuesArray mWeightIndices;

		/** Indices of joints assigned to a joint/vertex pair. The number of pairs for the i'th vertex is 
		given by the i'th value in mJointsPerVertex.*/
		UIntValuesArray mJointIndices;

	public:

        /** Constructor. */
		SkinControllerData( ObjectId objectId );

        /** Destructor. */
		virtual ~SkinControllerData();

		/** Returns the number of joints this controller can use.*/
		size_t getJointsCount() const { return mJointsCount; }

		/** Sets the number of joints this controller can use.*/
		void setJointsCount(size_t jointsCount) { mJointsCount = jointsCount; }

		/** Returns the number of vertices of the mesh modified by this controller.*/
		size_t getVertexCount() const { return mJointsPerVertex.getCount(); }

		/** Returns the unique id of the source that gets modified by this controller. Must be a mesh or a 
		controller. The vertex count of the source must be equal to the vertex count of the skin 
		controller.*/
		const COLLADAFW::UniqueId& getSource() const { return mSource; }

		/** Sets the unique id of the source that gets modified by this controller. Must be a mesh or a 
		controller. The vertex count of the source must be equal to the vertex count of the skin 
		controller.*/
		void setSource( const COLLADAFW::UniqueId& source) { mSource = source; }


		/** Returns the weights of the skin controller. */
		const COLLADAFW::FloatOrDoubleArray& getWeights() const { return mWeights; }
		COLLADAFW::FloatOrDoubleArray& getWeights() { return mWeights; }

		/** Returns the array defining how many joints are connected to a vertex. The length must be equal to mVertexCount.
		The i'th index corresponds to the i'th vertex of the source.*/
		const COLLADAFW::UIntValuesArray& getJointsPerVertex() const { return mJointsPerVertex; }
		COLLADAFW::UIntValuesArray& getJointsPerVertex() { return mJointsPerVertex; }

		/** Returns the indices of weights assigned to a joint/vertex pair. The number of pairs for the i'th vertex is 
		given by the i'th value in mJointsPerVertex.*/
		const COLLADAFW::UIntValuesArray& getWeightIndices() const { return mWeightIndices; }
		COLLADAFW::UIntValuesArray& getWeightIndices() { return mWeightIndices; }

		/** Returns the indices of joints assigned to a joint/vertex pair. The number of pairs for the i'th vertex is 
		given by the i'th value in mJointsPerVertex.*/
		const COLLADAFW::UIntValuesArray& getJointIndices() const { return mJointIndices; }
		COLLADAFW::UIntValuesArray& getJointIndices() { return mJointIndices; }

	private:

        /** Disable default copy ctor. */
		SkinControllerData( const SkinControllerData& pre );

        /** Disable default assignment operator. */
		const SkinControllerData& operator= ( const SkinControllerData& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SKINCONTROLLERDATA_H__
