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

#include "Math/COLLADABUMathMatrix4.h"


namespace COLLADAFW
{

    /** Holds the data of a skin controller, i.e. the weights per vertex per joint */
	class SkinControllerData : public ObjectTemplate<COLLADA_TYPE::SKIN_DATA>
	{
	private:

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

        /** The name of the skin controller.*/
        String mName;

		/** The number of joints this controller can use.*/
		size_t mJointsCount;

		/** Provides extra information about the position and orientation of the base mesh before binding.*/
		COLLADABU::Math::Matrix4 mBindShapeMatrix;

		/** Array of the inverse bind matrices. One for each joint.*/
		Matrix4Array mInverseBindMatrices;

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
		IntValuesArray mJointIndices;

	public:

        /** Constructor. */
		SkinControllerData( const UniqueId& uniqueId );

        /** Destructor. */
		virtual ~SkinControllerData();

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

		/** Provides extra information about the position and orientation of the base mesh before binding.*/
		const COLLADABU::Math::Matrix4& getBindShapeMatrix() const { return mBindShapeMatrix; }

		/** Provides extra information about the position and orientation of the base mesh before binding.*/
		void setBindShapeMatrix( const COLLADABU::Math::Matrix4& bindShapeMatrix) { mBindShapeMatrix = bindShapeMatrix; }

		/** Array of the inverse bind matrices. One for each joint.*/
		Matrix4Array& getInverseBindMatrices() { return mInverseBindMatrices; }

		/** Array of the inverse bind matrices. One for each joint.*/
		const Matrix4Array& getInverseBindMatrices() const { return mInverseBindMatrices; }

		/** Returns the number of joints this controller can use.*/
		size_t getJointsCount() const { return mJointsCount; }

		/** Sets the number of joints this controller can use.*/
		void setJointsCount(size_t jointsCount) { mJointsCount = jointsCount; }

		/** Returns the number of vertices of the mesh modified by this controller.*/
		size_t getVertexCount() const { return mJointsPerVertex.getCount(); }

		/** Returns the weights of the skin controller. */
		const FloatOrDoubleArray& getWeights() const { return mWeights; }
		FloatOrDoubleArray& getWeights() { return mWeights; }

		/** Returns the array defining how many joints are connected to a vertex. The length must be equal to mVertexCount.
		The i'th index corresponds to the i'th vertex of the source.*/
		const UIntValuesArray& getJointsPerVertex() const { return mJointsPerVertex; }
		UIntValuesArray& getJointsPerVertex() { return mJointsPerVertex; }

		/** Returns the indices of weights assigned to a joint/vertex pair. The number of pairs for the i'th vertex is 
		given by the i'th value in mJointsPerVertex.*/
		const UIntValuesArray& getWeightIndices() const { return mWeightIndices; }
		UIntValuesArray& getWeightIndices() { return mWeightIndices; }

		/** Returns the indices of joints assigned to a joint/vertex pair. The number of pairs for the i'th vertex is 
		given by the i'th value in mJointsPerVertex.*/
		const IntValuesArray& getJointIndices() const { return mJointIndices; }
		IntValuesArray& getJointIndices() { return mJointIndices; }

	private:

        /** Disable default copy ctor. */
		SkinControllerData( const SkinControllerData& pre );

        /** Disable default assignment operator. */
		const SkinControllerData& operator= ( const SkinControllerData& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SKINCONTROLLERDATA_H__
