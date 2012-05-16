/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_MESHACCESSOR_H__
#define __DAE23DS_MESHACCESSOR_H__

#include "DAE23dsPrerequisites.h"

#include "DAE23dsTriangle.h"

namespace COLLADAFW
{
	class Mesh;
}

namespace DAE23ds
{

	/** Helper to access triangles in a mesh.*/
	class MeshAccessor 	
	{
	public:
		typedef Triangle<unsigned int> TriangleType;
	private:
		/** The mesh.*/
		const COLLADAFW::Mesh* mMesh;

		/** Number of mesh primitives.*/
		size_t mMeshPrimitiveCount;

		/** Number of triangles per mesh primitive.*/
		size_t* mMeshPrimitiveTrianglesCount;

		/** Number of triangles of the mesh.*/
		size_t mTrianglesCount;

		/** The primitive that contains the current triangle.*/
		mutable size_t mCurrentPrimitiveIndex;

		/** The current strip or fan of the current triangle, 0 for triangles.*/
		mutable size_t mCurrentStripFanIndex;

		/** Index of the triangle within the current triangle, strip, or fan.*/
		mutable size_t mCurrentTriangleInTriStripFanIndex;

		/** Index of the current triangle.*/
		mutable size_t mCurrentTriangleIndex;

		/** Index in the positions array of the first vertex of the current strip or fan. Only Used by strips and fans*/
		mutable size_t mCurrentTrianglePositionsArrayIndex;

	public:

        /** Constructor. */
		MeshAccessor(const COLLADAFW::Mesh* mesh );

        /** Destructor. */
		virtual ~MeshAccessor();

		/** Returns the number of triangles of the mesh.*/
		size_t getTrianglesCount() const { return mTrianglesCount; }

		/** Returns the number of triangles of the @a index'th mesh primitive.*/
		size_t getMeshPrimitiveTriangleCount( size_t index ) const { assert(index < mMeshPrimitiveCount);  return mMeshPrimitiveTrianglesCount[index]; }

		/** Returns the @a n'th triangle.*/
		TriangleType getTriangle( size_t n) const;

		TriangleType getNextTriangle() const;

	private:

        /** Disable default copy ctor. */
		MeshAccessor( const MeshAccessor& pre );

        /** Disable default assignment operator. */
		const MeshAccessor& operator= ( const MeshAccessor& pre );

		size_t calculateTrianglesCount() const;

		size_t calculateMeshPrimitiveTriangleCount(const COLLADAFW::MeshPrimitive* meshPrimitive) const;
	};

} // namespace DAE23ds

#endif // __DAE23DS_MESHACCESSOR_H__
