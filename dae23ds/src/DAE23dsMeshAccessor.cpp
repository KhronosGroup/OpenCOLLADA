/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsMeshAccessor.h"


namespace DAE23ds
{

    //------------------------------
	MeshAccessor::MeshAccessor( const COLLADAFW::Mesh* mesh )
		: mMesh( mesh )
		, mMeshPrimitiveCount( mesh->getMeshPrimitives().getCount() )
		, mMeshPrimitiveTrianglesCount( new size_t[mMeshPrimitiveCount] )
		, mTrianglesCount( calculateTrianglesCount() )
		, mCurrentPrimitiveIndex(0)
		, mCurrentStripFanIndex(0)
		, mCurrentTriangleInTriStripFanIndex(0)
	{

	}

    //------------------------------
	MeshAccessor::~MeshAccessor()
	{
		delete[] mMeshPrimitiveTrianglesCount;
	}

	//------------------------------
	size_t MeshAccessor::calculateTrianglesCount() const
	{
		size_t trianglesCount = 0;
		const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mMesh->getMeshPrimitives();
		size_t meshPrimitivesCount = meshPrimitives.getCount();

		for ( size_t i = 0; i < meshPrimitivesCount; ++i)
		{
			const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives[i];
			size_t primitiveTrianglesCount = calculateMeshPrimitiveTriangleCount(meshPrimitive);
			trianglesCount += primitiveTrianglesCount;
			mMeshPrimitiveTrianglesCount[i] = primitiveTrianglesCount;
		}
		return trianglesCount;
	}

	//------------------------------
	size_t MeshAccessor::calculateMeshPrimitiveTriangleCount(const COLLADAFW::MeshPrimitive* meshPrimitive) const
	{
		size_t trianglesCount = 0;

		switch ( meshPrimitive->getPrimitiveType() )
		{
		case COLLADAFW::MeshPrimitive::TRIANGLES:
			{
				const COLLADAFW::UIntValuesArray& positionsIndices = meshPrimitive->getPositionIndices();
				size_t positionsIndicesCount = positionsIndices.getCount();
				trianglesCount = positionsIndicesCount/3;
				break;
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
			{
				const COLLADAFW::Tristrips* tristrips = (const COLLADAFW::Tristrips*)meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();

				for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
				{
					trianglesCount += (faceVertexCountArray[k] - 2);
				}
				break;
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
			{
				const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*)meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();

				for ( size_t k = 0, count = faceVertexCountArray.getCount(); k < count; ++k)
				{
					trianglesCount += (faceVertexCountArray[k] - 2);
				}
				break;
			}
		}
		return trianglesCount;
	}

	//------------------------------
	MeshAccessor::TriangleType MeshAccessor::getTriangle( size_t n ) const
	{
		assert( n < mTrianglesCount );

		mCurrentTriangleIndex = n;
		//find the correct mesh primitive
		size_t triangleIndex = mMeshPrimitiveTrianglesCount[0] ;
		size_t meshPrimitiveIndex = 0;
		while ( triangleIndex < n + 1 )
		{
			triangleIndex += mMeshPrimitiveTrianglesCount[++meshPrimitiveIndex];
		}
		triangleIndex -= mMeshPrimitiveTrianglesCount[meshPrimitiveIndex];

		size_t indexInPrimitive = n - triangleIndex;
		const COLLADAFW::MeshPrimitive* meshPrimitive = mMesh->getMeshPrimitives()[meshPrimitiveIndex];

		COLLADAFW::MaterialId materialId = meshPrimitive->getMaterialId();

		mCurrentPrimitiveIndex = meshPrimitiveIndex;

		const COLLADAFW::UIntValuesArray& positionsIndices = meshPrimitive->getPositionIndices();

		switch ( meshPrimitive->getPrimitiveType() )
		{
		case COLLADAFW::MeshPrimitive::TRIANGLES:
			{
				size_t firstIndex = indexInPrimitive * 3;
				TriangleType triangle(positionsIndices[firstIndex], positionsIndices[firstIndex+1],positionsIndices[firstIndex+2], materialId);
				mCurrentStripFanIndex = 0;
				mCurrentTriangleInTriStripFanIndex = indexInPrimitive;
				return triangle;
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
			{
				const COLLADAFW::Tristrips* tristrips = (const COLLADAFW::Tristrips*)meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();

				//find the correct tristrip
				size_t triangleIndex = faceVertexCountArray[0] - 2 ;
				size_t tristripIndex = 0;
				while ( triangleIndex < indexInPrimitive + 1 )
				{
					triangleIndex += faceVertexCountArray[++tristripIndex] - 2;
				}
				triangleIndex -= (faceVertexCountArray[tristripIndex] - 2);
				size_t firstIndex = indexInPrimitive  + 2*tristripIndex;
				mCurrentStripFanIndex = tristripIndex;
				mCurrentTriangleInTriStripFanIndex = indexInPrimitive - triangleIndex;
				mCurrentTrianglePositionsArrayIndex = triangleIndex + 2*tristripIndex;
				if ( mCurrentTriangleInTriStripFanIndex % 2 == 0 )
				{
					return TriangleType(positionsIndices[firstIndex], positionsIndices[firstIndex+1],positionsIndices[firstIndex+2], materialId);
				}
				else
				{
					return TriangleType(positionsIndices[firstIndex], positionsIndices[firstIndex+2],positionsIndices[firstIndex+1], materialId);
				}
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
			{
				const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*)meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();

				//find the correct trifan
				size_t triangleIndex = faceVertexCountArray[0] - 2 ;
				size_t trisfanIndex = 0;
				while ( triangleIndex < indexInPrimitive + 1 )
				{
					triangleIndex += faceVertexCountArray[++trisfanIndex] - 2;
				}
				triangleIndex -= (faceVertexCountArray[trisfanIndex] - 2);
				size_t firstIndex = indexInPrimitive + 2*trisfanIndex;
				TriangleType triangle(positionsIndices[triangleIndex + 2*trisfanIndex ], positionsIndices[firstIndex+1],positionsIndices[firstIndex+2], materialId);
				mCurrentStripFanIndex = trisfanIndex;
				mCurrentTriangleInTriStripFanIndex = indexInPrimitive - triangleIndex;
				return triangle;
			}
		default:
			assert(false);
			return TriangleType(0, 0, 0, 0);
		}
	}

	//------------------------------
	MeshAccessor::TriangleType MeshAccessor::getNextTriangle() const
	{
		mCurrentTriangleIndex++;
		const COLLADAFW::MeshPrimitive* meshPrimitive = mMesh->getMeshPrimitives()[mCurrentPrimitiveIndex];
		const COLLADAFW::UIntValuesArray& positionsIndices = meshPrimitive->getPositionIndices();

		COLLADAFW::MaterialId materialId = meshPrimitive->getMaterialId();

		switch ( meshPrimitive->getPrimitiveType() )
		{
		case COLLADAFW::MeshPrimitive::TRIANGLES:
			{
				size_t triangleCount = positionsIndices.getCount()/3;
				if ( (mCurrentTriangleInTriStripFanIndex + 1) < triangleCount )
				{
					// use next in same triangle

					mCurrentTriangleInTriStripFanIndex++;
					size_t firstIndex = mCurrentTriangleInTriStripFanIndex * 3;
					TriangleType triangle(positionsIndices[firstIndex], positionsIndices[firstIndex+1],positionsIndices[firstIndex+2], materialId);
					return triangle;
				}
				else
				{
					return getTriangle( mCurrentTriangleIndex );
				}
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
			{
				const COLLADAFW::Tristrips* tristrips = (const COLLADAFW::Tristrips*)meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = tristrips->getGroupedVerticesVertexCountArray();

				size_t triangleCount = faceVertexCountArray[mCurrentStripFanIndex] - 2;

				if ( (mCurrentTriangleInTriStripFanIndex + 1) < triangleCount )
				{
					// use next in same triangle

					mCurrentTriangleInTriStripFanIndex++;
					size_t firstIndex = mCurrentTrianglePositionsArrayIndex + mCurrentTriangleInTriStripFanIndex;
					if ( mCurrentTriangleInTriStripFanIndex % 2 == 0 )
					{
						return TriangleType(positionsIndices[firstIndex], positionsIndices[firstIndex+1],positionsIndices[firstIndex+2], materialId);
					}
					else
					{
						return TriangleType(positionsIndices[firstIndex], positionsIndices[firstIndex+2],positionsIndices[firstIndex+1], materialId);
					}
				}
				else
				{
					if ( (mCurrentStripFanIndex + 1) < faceVertexCountArray.getCount() )
					{
						// take the next strip
						mCurrentTrianglePositionsArrayIndex += faceVertexCountArray[mCurrentStripFanIndex];
						mCurrentStripFanIndex++;
						mCurrentTriangleInTriStripFanIndex = 0;
						size_t firstIndex = mCurrentTrianglePositionsArrayIndex;
						return TriangleType (positionsIndices[firstIndex], positionsIndices[firstIndex+1],positionsIndices[firstIndex+2], materialId);
					}
					else
					{
						return getTriangle( mCurrentTriangleIndex );
					}
				}
			}
		case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
			{
				const COLLADAFW::Trifans* trifans = (const COLLADAFW::Trifans*)meshPrimitive;
				const COLLADAFW::UIntValuesArray& faceVertexCountArray = trifans->getGroupedVerticesVertexCountArray();


				size_t triangleCount = faceVertexCountArray[mCurrentStripFanIndex] - 2;

				if ( (mCurrentTriangleInTriStripFanIndex + 1) < triangleCount )
				{
					// use next in same triangle

					mCurrentTriangleInTriStripFanIndex++;
					size_t firstIndex = mCurrentTrianglePositionsArrayIndex + mCurrentTriangleInTriStripFanIndex;
					TriangleType triangle(positionsIndices[mCurrentTrianglePositionsArrayIndex], positionsIndices[firstIndex+1],positionsIndices[firstIndex+2], materialId);
					return triangle;
				}
				else
				{
					if ( (mCurrentStripFanIndex + 1) < faceVertexCountArray.getCount() )
					{
						// take the next strip
						mCurrentTrianglePositionsArrayIndex += faceVertexCountArray[mCurrentStripFanIndex];
						mCurrentStripFanIndex++;
						mCurrentTriangleInTriStripFanIndex = 0;
						size_t firstIndex = mCurrentTrianglePositionsArrayIndex;
						TriangleType triangle(positionsIndices[mCurrentTrianglePositionsArrayIndex], positionsIndices[firstIndex+1],positionsIndices[firstIndex+2], materialId);
						return triangle;
					}
					else
					{
						return getTriangle( mCurrentTriangleIndex );
					}
				}
			}
		default:
			assert(false);
			return TriangleType(0, 0, 0, 0);
		}


	}


} // namespace DAE23ds
